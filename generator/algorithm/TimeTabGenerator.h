#pragma once

#include "./../../core/Course.h"
#include "./WeightGraph.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;


class TimeTabGenerator
{
public:
	using Bits = long long;
	using TimeTab = Bits;
	enum GetTimeTabResult { InvalidInput, CannotLoadPrev, CannotLoadNext, LoadSuccessfully };



private:
	bool mValidInput;                                // 제대로된 input인지 확인

	int mKValue;                                     // 한 페이지 당 보여주는 시간표 개수
	int mTargetCredit;                               // 목표학점
	int mNumberOfCourse;                             // 과목 수
	int mNumberOfEssentialCourse;                    // 필수과목 수 
	int mNumberOfNormalCourse;                       // 일반과목 수
	vector<pair<Course, int>> mCourseInfoList;       // { 과목, 선호도 }
	

	int mSource;
	int mSubSource;
	int mSink;
	WeightedGraph mKspGraph;                         // 가중치 그래프
	vector<Bits> mCourseConflict;                    // i-th과목과 충돌되는 과목

	vector<TimeTab> mTimeTabList;                    // 생성된 시간표 리스트	



public:
	TimeTabGenerator() {}
	TimeTabGenerator(int kValue, int targetCredit, int numberOfEssentialCourse, int numberOfNoramlCourse, vector<pair<Course, int>>& courseInfoList)
		: mValidInput(true)

		, mKValue(kValue)
		, mTargetCredit(targetCredit)
		, mNumberOfCourse(courseInfoList.size())
		, mNumberOfEssentialCourse(numberOfEssentialCourse)
		, mNumberOfNormalCourse(numberOfNoramlCourse)
		, mCourseInfoList(courseInfoList)

		, mSource(0)
		, mSubSource(mNumberOfEssentialCourse + 1)
		, mSink(mNumberOfEssentialCourse + 1)
		, mKspGraph(WeightedGraph())
		, mCourseConflict(vector<Bits>((int)courseInfoList.size()))

		, mTimeTabList(vector<TimeTab>()) {
		Construct_CourseConflict();
		Construct_KspGraph();
	}



private:   // 과목간의 충돌 여부를 체크
	bool Check_CourseConflict(Course& fstCourse, Course& sndCourse)
	{
		if (fstCourse.id.base == sndCourse.id.base) return true;   // 학수번호 앞자리가 같을 때 (같은 과목)
		for (auto& fstTime : fstCourse.times)                      // 강의 시간이 겹칠 때
			for (auto& sndTime : sndCourse.times)
				if (fstTime.day == sndTime.day && (fstTime.start < sndTime.end && fstTime.end > sndTime.start)) return true;
		return false;
	}



private:   // 과목의 가중치를 계산
	int Get_CourseWeight(int normCourseIdx)
	{
		auto& [course, lank] = mCourseInfoList[normCourseIdx];
		switch (lank) {
		case 0: return 0;
		case 1: return course.credit;
		case 2: return course.credit * 25;
		case 3: return course.credit * 625;
		case 4: return course.credit * 15625;
		case 5: return course.credit * 390625;
		default: break;
		}
		return -1;
	}



private:   // 각 과목마다 충돌되는 과목을 정보를 가지고 있는 배열 구성
	void Construct_CourseConflict()
	{
		for (int i = 1; i < mNumberOfCourse; i++)
			for (int j = i + 1; j < mNumberOfCourse; j++)
				if (Check_CourseConflict(mCourseInfoList[i].first, mCourseInfoList[j].first)) {
					mCourseConflict[i] |= (Bits)1 << (Bits)j;
					mCourseConflict[j] |= (Bits)1 << (Bits)i;
				}
	}



private:   // KspGraph에 필수과목 추가
	void Add_EssentialCourse()
	{
		mKspGraph.Assign(mSink + 1, 2e18, 1e18, 0);   // TODO: long long -> int로 바꾸는 작업이 필요함

	
		// classify 작업
		unordered_map<string, vector<int>> classify;   // 같은 학수번호 앞자리를 가진 과목끼리 묶음 (동일 과목 분류 작업)

		for (int i = 1; i <= mNumberOfEssentialCourse; i++)
			classify[mCourseInfoList[i].first.id.base].push_back(i);


		// Source -> 필수과목
		vector<int> prevIdxList = { mSource };

		for (auto& [id_base, idxList] : classify) {   // Source, 필수과목 그래프 연결
			for (auto& u : prevIdxList)
				for (auto& v : idxList)
					if (!(mCourseConflict[u] & (Bits)1 << (Bits)v)) mKspGraph.Add_Directed_Edge(u, v, Get_CourseWeight(v));

			prevIdxList = idxList;
			mTargetCredit -= mCourseInfoList[idxList[0]].first.credit;
		}


		// 목표학점에 따른 예외 처리
		if (mTargetCredit == 0) {   // 필수과목으로 목표학점을 달성하는 경우
			for (auto& u : prevIdxList)   // 필수과목과 Sink 그래프 연결
				mKspGraph.Add_Directed_Edge(u, mSink, 0);
		}
		else if (mTargetCredit < 0) {   // 목표학점을 초과하는 경우
			mValidInput = false;
		}
		else {
			mSink = mSubSource + (mNumberOfNormalCourse * mTargetCredit) + 1;
			mKspGraph.Resize(mSink + 1);   // TODO: long long -> int로 바꾸는 작업이 필요함
			for (auto& u : prevIdxList)   // 필수과목과 SubSource 그래프 연결
				mKspGraph.Add_Directed_Edge(u, mSubSource, 0);
		}
	}



private:   // KspGraph에 일반과목 추가
	void Add_NormalCourse()
	{
		if (mTargetCredit <= 0) return;

		int level = mTargetCredit;
		auto convVertexNum = [&](int idx, int lev) { return idx + 1 + ((lev - 1) * mNumberOfNormalCourse); };   // idx + 1 = SubSource + (idx - NumberOfEssential)


		// SubSource와 일반과목 연결
		for (int v = mNumberOfEssentialCourse + 1; v < mNumberOfCourse; v++) {   // TODO: Source로부터의 간선 최적화 필요 
			if (mCourseInfoList[v].first.credit > level) continue;
			mKspGraph.Add_Directed_Edge(mSubSource, convVertexNum(v, mCourseInfoList[v].first.credit), Get_CourseWeight(v));
		}


		// Sink와 일반과목 연결
		for (int u = mNumberOfEssentialCourse + 1; u < mNumberOfCourse; u++)   // TODO: Sink로의 간선 최적화 필요 
			mKspGraph.Add_Directed_Edge(convVertexNum(u, level), mSink, 0);


		// 일반 과목끼리 연결
		for (int lev = 1; lev < level; lev++) {   // TODO: 간선 최적화 필요
			for (int u = mNumberOfEssentialCourse + 1; u < mNumberOfCourse; u++) {
				for (int v = u + 1; v < mNumberOfCourse; v++) {
					if (mCourseConflict[u] & (Bits)1 << (Bits)v) continue;
					if (lev + mCourseInfoList[v].first.credit > level) continue;
					mKspGraph.Add_Directed_Edge(convVertexNum(u, lev), convVertexNum(v, lev + mCourseInfoList[v].first.credit), Get_CourseWeight(v));
				}
			}
		}
	}



private:   // KspGraph 구성
	void Construct_KspGraph()
	{
		Add_EssentialCourse();   // 필수과목 추가, 예외처리 필수과목으로 1) 목표학점을 달성하는 경우, 2) 목표학점을 초과하는 경우, 3) 그 외
		Add_NormalCourse();      // 일반과목 추가

		if (mValidInput) {
			function<int(int)> GetCourseNum = [&](int idx) {
				if (idx == mSource || idx == mSubSource || idx == mSink) return 0;
				if (idx <= mNumberOfEssentialCourse) return idx;
				return (idx - 1 - mSubSource) % mNumberOfNormalCourse + mSubSource;
			};

			mTimeTabList = mKspGraph.Construct_Ksp(mSource, mSink, mKValue, mCourseConflict, GetCourseNum);
		}
	}





public:   // Ksp를 추가로 실행하여 시간표를 생성하고 반환
	tuple<vector<vector<Course>>, vector<vector<int>>, GetTimeTabResult> Get_TimeTable(int page)
	{
		if (!mValidInput) return { vector<vector<Course>>(), vector<vector<int>>(), GetTimeTabResult::InvalidInput };
		if (page <= 0) return { vector<vector<Course>>(), vector<vector<int>>(), GetTimeTabResult::CannotLoadPrev };


		// 현재 페이지에 시간표가 없다면 추가로 시간표를 생성
		if ((int)mTimeTabList.size() <= mKValue * (page - 1)) {
			function<int(int)> GetCourseNum = [&](int idx) {
				if (idx == mSource || idx == mSubSource || idx == mSink) return 0;
				if (idx <= mNumberOfEssentialCourse) return idx;
				return (idx - 1 - mSubSource) % mNumberOfNormalCourse + mSubSource;
			};

			for (auto& timeTab : mKspGraph.Additional_Ksp(mKValue, mCourseConflict, GetCourseNum)) mTimeTabList.push_back(timeTab);

			// 추가로 생성된 시간표가 없다면 생성할 수 있는 시간표가 없다고 간주 (첫 호출이였다면 input자체가 잘못됨)
			if ((int)mTimeTabList.size() <= mKValue * (page - 1)) return { vector<vector<Course>>(), vector<vector<int>>(), page == 1 ? GetTimeTabResult::InvalidInput : GetTimeTabResult::CannotLoadNext };
		}


		// 시간표에 포함된 과목 정보를 인접리스트 형태로 반환
		int begin = mKValue * (page - 1), end = min((int)mTimeTabList.size(), mKValue * page);
		vector<vector<Course>> courseAdjList;   // 포함된 과목 (시간표별)
		vector<vector<int>> lankCount;          // 우선순위 카운팅 (시간표별)


		for (int i = begin; i < end; i++) {
			courseAdjList.push_back(vector<Course>());
			lankCount.push_back(vector<int>(6, 0));

			auto& courseList = courseAdjList.back();
			auto& courseLank = lankCount.back();

			for (int j = 1; j < mNumberOfCourse; j++)
				if (mTimeTabList[i] & (Bits)1 << (Bits)j) {
					courseList.push_back(mCourseInfoList[j].first);
					courseLank[mCourseInfoList[j].second]++;
				}
		}

		return { courseAdjList, lankCount, GetTimeTabResult::LoadSuccessfully };
	}
};