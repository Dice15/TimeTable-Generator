#pragma once

#include "./../core/Course.h"
#include "WeightGraph.h"

#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


class TimeTabGenerator
{
public:
	using Bits = long long;
	using TimeTab = Bits;
	enum GetTimeTabResult { CannotLoadPrev, CannotLoadNext, EssentialConflict, CannotCreateTimeTab, LoadSuccessfully };



private:
	bool mExistEssentialConflict;			// 필수과목 사이에서의 충돌 확인

	int mKValue;							// 한 페이지 당 보여주는 시간표 개수
	int mTargetCredit;						// 목표학점
	int mNumberOfEssentialCourse;			// 필수과목 수
	int mNumberOfNormalCourse;				// 일반과목 수
	vector<Course> mEssentialCourseList;	// 필수과목의 과목 정보
	vector<Course> mNormalCourseList;		// 일반과목의 과목 정보
	vector<int> mNormalCourseLank;			// 일반과목의 우선순위

	WeightedGraph mKspGraph;				// 가중치 그래프
	Bits mCommonConflict;					// 필수과목과 충돌되는 과목
	vector<Bits> mCourseConflict;			// i-th과목과 충돌되는 과목

	vector<TimeTab> mTimeTabList;			// 생성된 시간표 리스트	



public:
	TimeTabGenerator() {}
	TimeTabGenerator(int kValue, int targetCredit, vector<Course>& essnCourseList, vector<Course>& normCourseList, vector<int>& nomCourseLank)
		: mExistEssentialConflict(false)

		, mKValue(kValue)
		, mTargetCredit(targetCredit)
		, mNumberOfEssentialCourse((int)essnCourseList.size() - 1)
		, mNumberOfNormalCourse((int)normCourseList.size() - 1)
		, mEssentialCourseList(essnCourseList)
		, mNormalCourseList(normCourseList)
		, mNormalCourseLank(nomCourseLank)

		, mKspGraph(WeightedGraph())
		, mCommonConflict((Bits)0)
		, mCourseConflict(vector<Bits>(normCourseList.size())) {
		Construct_CourseConflict();
		Construct_KspGraph();
	}



private:	// 과목간의 충돌 여부를 체크
	bool Check_CourseConflict(Course& fstCourse, Course& sndCourse)
	{
		if (fstCourse.id.base == sndCourse.id.base) return true;	// 학수번호 앞자리가 같을 때 (같은 과목)
		for (auto& fstTime : fstCourse.times)						// 강의 시간이 겹칠 때
			for (auto& sndTime : sndCourse.times)
				if (fstTime.day == sndTime.day && (fstTime.start < sndTime.end && fstTime.end > sndTime.start)) return true;
		return false;
	}



private:	// 과목의 가중치를 계산
	int Get_CourseWeight(int normCourseIdx)
	{
		switch (mNormalCourseLank[normCourseIdx]) {
		case 1: return mNormalCourseList[normCourseIdx].credit;
		case 2: return mNormalCourseList[normCourseIdx].credit * 25;
		case 3: return mNormalCourseList[normCourseIdx].credit * 625;
		case 4: return mNormalCourseList[normCourseIdx].credit * 15625;
		case 5: return mNormalCourseList[normCourseIdx].credit * 390625;
		default: break;
		}
		return -1;
	}



private:	// 각 과목마다 충돌되는 과목을 정보를 가지고 있는 배열 구성
	void Construct_CourseConflict()
	{
		// 필수 과목의 출돌
		for (int i = 1; i <= mNumberOfEssentialCourse; i++) {
			for (int j = i + 1; j <= mNumberOfEssentialCourse; j++)	// 필수 과목끼리 충돌이 있다면 false리턴
				if (Check_CourseConflict(mEssentialCourseList[i], mEssentialCourseList[j])) mExistEssentialConflict = true;

			for (int j = 1; j <= mNumberOfNormalCourse; j++)	// 필수 과목과 일반 과목 사이의 충돌 확인
				if (Check_CourseConflict(mEssentialCourseList[i], mNormalCourseList[j])) mCommonConflict |= (Bits)1 << (Bits)j;
		}

		// 일반 과목의 충돌
		for (int i = 1; i <= mNumberOfNormalCourse; i++) {
			mCourseConflict[i] = mCommonConflict;		// commonConflict(모든 필수과목의 충돌되는 일반 과목들)
			for (int j = i + 1; j <= mNumberOfNormalCourse; j++)		// 일반 과목 사이의 충돌 확인
				if (Check_CourseConflict(mNormalCourseList[i], mNormalCourseList[j])) mCourseConflict[i] |= (Bits)1 << (Bits)j;
		}
	}



private:	// KspGraph 구성
	void Construct_KspGraph()
	{
		if (mExistEssentialConflict) return;
		if (mTargetCredit == 0) { mTimeTabList = vector<Bits>{ 0 }; return; }

		int source = 0, sink = (mNumberOfNormalCourse * mTargetCredit) + 1, level = mTargetCredit;
		auto convVertexNum = [&](int vNum, int lev) { return vNum + ((lev - 1) * mNumberOfNormalCourse); };
		function<int(int)> GetCourseNum = [&](int idx) { return idx == source ? 0 : idx == sink ? mNumberOfNormalCourse + 1 : ((idx - 1) % mNumberOfNormalCourse) + 1; };



		// TODO: long long -> int로 바꾸는 작업이 필요함

		mKspGraph.Assign(sink + 1, 2e18, 1e18, 0);	// TODO: Graph의 가중치를 int형으로 바꿨다면 수정해야 함

		// Source와 일반 과목 연결
		for (int v = 1; v <= mNumberOfNormalCourse; v++) {	// TODO: Source로부터의 간선 최적화 필요 
			if (mNormalCourseList[v].credit > level) continue;
			if (!(mCommonConflict & (Bits)1 << (Bits)v)) mKspGraph.Add_Directed_Edge(source, convVertexNum(v, mNormalCourseList[v].credit), Get_CourseWeight(v));
		}

		// Sink와 일반 과목 연결
		for (int u = 1; u <= mNumberOfNormalCourse; u++)	// TODO: Sink로의 간선 최적화 필요 
			if (!(mCommonConflict & (Bits)1 << (Bits)u)) mKspGraph.Add_Directed_Edge(convVertexNum(u, level), sink, 0);

		// 일반 과목끼리 연결
		for (int lev = 1; lev < level; lev++) {	// TODO: 간선 최적화 필요
			for (int u = 1; u <= mNumberOfNormalCourse; u++) {
				if (mCommonConflict & (Bits)1 << (Bits)u) continue;
				for (int v = u + 1; v <= mNumberOfNormalCourse; v++) {
					if (mCommonConflict & (Bits)1 << (Bits)v) continue;
					if (mCourseConflict[u] & (Bits)1 << (Bits)v) continue;
					if (lev + mNormalCourseList[v].credit > level) continue;
					mKspGraph.Add_Directed_Edge(convVertexNum(u, lev), convVertexNum(v, lev + mNormalCourseList[v].credit), Get_CourseWeight(v));
				}
			}
		}

		mTimeTabList = mKspGraph.Construct_Ksp(source, sink, mKValue, mCourseConflict, GetCourseNum);
	}





public:		// Ksp를 추가로 실행하여 시간표를 생성하고 반환
	tuple<vector<Course>, vector<vector<Course>>, vector<vector<int>>, GetTimeTabResult> Get_TimeTable(int page)
	{
		if (page <= 0) return { vector<Course>(), vector<vector<Course>>(), vector<vector<int>>(), GetTimeTabResult::CannotLoadPrev };
		if (mExistEssentialConflict) return { vector<Course>(), vector<vector<Course>>(), vector<vector<int>>(), GetTimeTabResult::EssentialConflict };


		// 현재 페이지에 시간표가 없다면 추가로 시간표를 생성
		if ((int)mTimeTabList.size() <= mKValue * (page - 1)) {
			int source = 0, sink = (mNumberOfNormalCourse * mTargetCredit) + 1;
			function<int(int)> GetCourseNum = [&](int idx) { return idx == source ? 0 : idx == sink ? mNumberOfNormalCourse + 1 : ((idx - 1) % mNumberOfNormalCourse) + 1; };
			for (auto& timeTab : mKspGraph.Additional_Ksp(mKValue, mCourseConflict, GetCourseNum)) mTimeTabList.push_back(timeTab);

			// 추가로 생성된 시간표가 없다면 생성할 수 있는 시간표가 없다고 간주 (첫 호출이였다면 input자체가 잘못됨)
			if ((int)mTimeTabList.size() <= mKValue * (page - 1)) return { vector<Course>(), vector<vector<Course>>(), vector<vector<int>>(), page == 1 ? GetTimeTabResult::CannotCreateTimeTab : GetTimeTabResult::CannotLoadNext };
		}


		// 시간표에 포함된 과목 정보를 인접리스트 형태로 반환
		int begin = mKValue * (page - 1), end = min((int)mTimeTabList.size(), mKValue * page);
		vector<Course> essentialCourseList;				// 필수과목 (공통)
		vector<vector<Course>> normalCourseAdjList;		// 일반과목 (시간표별)
		vector<vector<int>> timeTbCourseLankCount;		// 우선순위 카운팅 (시간표별)


		for (int i = 1; i <= mNumberOfEssentialCourse; i++)
			essentialCourseList.push_back(mEssentialCourseList[i]);

		for (int i = begin; i < end; i++) {
			normalCourseAdjList.push_back(vector<Course>());
			timeTbCourseLankCount.push_back(vector<int>(6, 0));

			auto& courseList = normalCourseAdjList.back();
			auto& courseLank = timeTbCourseLankCount.back();

			courseLank[0] = essentialCourseList.size();
			for (int j = 1; j <= mNumberOfNormalCourse; j++)
				if (mTimeTabList[i] & (Bits)1 << (Bits)j) {
					courseList.push_back(mNormalCourseList[j]);
					courseLank[mNormalCourseLank[j]]++;
				}
		}

		return { essentialCourseList, normalCourseAdjList, timeTbCourseLankCount, GetTimeTabResult::LoadSuccessfully };
	}
};