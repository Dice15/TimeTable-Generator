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
	bool mValidInput;                                // ����ε� input���� Ȯ��

	int mKValue;                                     // �� ������ �� �����ִ� �ð�ǥ ����
	int mTargetCredit;                               // ��ǥ����
	int mNumberOfCourse;                             // ���� ��
	int mNumberOfEssentialCourse;                    // �ʼ����� �� 
	int mNumberOfNormalCourse;                       // �Ϲݰ��� ��
	vector<pair<Course, int>> mCourseInfoList;       // { ����, ��ȣ�� }
	

	int mSource;
	int mSubSource;
	int mSink;
	WeightedGraph mKspGraph;                         // ����ġ �׷���
	vector<Bits> mCourseConflict;                    // i-th����� �浹�Ǵ� ����

	vector<TimeTab> mTimeTabList;                    // ������ �ð�ǥ ����Ʈ	



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



private:   // ������ �浹 ���θ� üũ
	bool Check_CourseConflict(Course& fstCourse, Course& sndCourse)
	{
		if (fstCourse.id.base == sndCourse.id.base) return true;   // �м���ȣ ���ڸ��� ���� �� (���� ����)
		for (auto& fstTime : fstCourse.times)                      // ���� �ð��� ��ĥ ��
			for (auto& sndTime : sndCourse.times)
				if (fstTime.day == sndTime.day && (fstTime.start < sndTime.end && fstTime.end > sndTime.start)) return true;
		return false;
	}



private:   // ������ ����ġ�� ���
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



private:   // �� ���񸶴� �浹�Ǵ� ������ ������ ������ �ִ� �迭 ����
	void Construct_CourseConflict()
	{
		for (int i = 1; i < mNumberOfCourse; i++)
			for (int j = i + 1; j < mNumberOfCourse; j++)
				if (Check_CourseConflict(mCourseInfoList[i].first, mCourseInfoList[j].first)) {
					mCourseConflict[i] |= (Bits)1 << (Bits)j;
					mCourseConflict[j] |= (Bits)1 << (Bits)i;
				}
	}



private:   // KspGraph�� �ʼ����� �߰�
	void Add_EssentialCourse()
	{
		mKspGraph.Assign(mSink + 1, 2e18, 1e18, 0);   // TODO: long long -> int�� �ٲٴ� �۾��� �ʿ���

	
		// classify �۾�
		unordered_map<string, vector<int>> classify;   // ���� �м���ȣ ���ڸ��� ���� ���񳢸� ���� (���� ���� �з� �۾�)

		for (int i = 1; i <= mNumberOfEssentialCourse; i++)
			classify[mCourseInfoList[i].first.id.base].push_back(i);


		// Source -> �ʼ�����
		vector<int> prevIdxList = { mSource };

		for (auto& [id_base, idxList] : classify) {   // Source, �ʼ����� �׷��� ����
			for (auto& u : prevIdxList)
				for (auto& v : idxList)
					if (!(mCourseConflict[u] & (Bits)1 << (Bits)v)) mKspGraph.Add_Directed_Edge(u, v, Get_CourseWeight(v));

			prevIdxList = idxList;
			mTargetCredit -= mCourseInfoList[idxList[0]].first.credit;
		}


		// ��ǥ������ ���� ���� ó��
		if (mTargetCredit == 0) {   // �ʼ��������� ��ǥ������ �޼��ϴ� ���
			for (auto& u : prevIdxList)   // �ʼ������ Sink �׷��� ����
				mKspGraph.Add_Directed_Edge(u, mSink, 0);
		}
		else if (mTargetCredit < 0) {   // ��ǥ������ �ʰ��ϴ� ���
			mValidInput = false;
		}
		else {
			mSink = mSubSource + (mNumberOfNormalCourse * mTargetCredit) + 1;
			mKspGraph.Resize(mSink + 1);   // TODO: long long -> int�� �ٲٴ� �۾��� �ʿ���
			for (auto& u : prevIdxList)   // �ʼ������ SubSource �׷��� ����
				mKspGraph.Add_Directed_Edge(u, mSubSource, 0);
		}
	}



private:   // KspGraph�� �Ϲݰ��� �߰�
	void Add_NormalCourse()
	{
		if (mTargetCredit <= 0) return;

		int level = mTargetCredit;
		auto convVertexNum = [&](int idx, int lev) { return idx + 1 + ((lev - 1) * mNumberOfNormalCourse); };   // idx + 1 = SubSource + (idx - NumberOfEssential)


		// SubSource�� �Ϲݰ��� ����
		for (int v = mNumberOfEssentialCourse + 1; v < mNumberOfCourse; v++) {   // TODO: Source�κ����� ���� ����ȭ �ʿ� 
			if (mCourseInfoList[v].first.credit > level) continue;
			mKspGraph.Add_Directed_Edge(mSubSource, convVertexNum(v, mCourseInfoList[v].first.credit), Get_CourseWeight(v));
		}


		// Sink�� �Ϲݰ��� ����
		for (int u = mNumberOfEssentialCourse + 1; u < mNumberOfCourse; u++)   // TODO: Sink���� ���� ����ȭ �ʿ� 
			mKspGraph.Add_Directed_Edge(convVertexNum(u, level), mSink, 0);


		// �Ϲ� ���񳢸� ����
		for (int lev = 1; lev < level; lev++) {   // TODO: ���� ����ȭ �ʿ�
			for (int u = mNumberOfEssentialCourse + 1; u < mNumberOfCourse; u++) {
				for (int v = u + 1; v < mNumberOfCourse; v++) {
					if (mCourseConflict[u] & (Bits)1 << (Bits)v) continue;
					if (lev + mCourseInfoList[v].first.credit > level) continue;
					mKspGraph.Add_Directed_Edge(convVertexNum(u, lev), convVertexNum(v, lev + mCourseInfoList[v].first.credit), Get_CourseWeight(v));
				}
			}
		}
	}



private:   // KspGraph ����
	void Construct_KspGraph()
	{
		Add_EssentialCourse();   // �ʼ����� �߰�, ����ó�� �ʼ��������� 1) ��ǥ������ �޼��ϴ� ���, 2) ��ǥ������ �ʰ��ϴ� ���, 3) �� ��
		Add_NormalCourse();      // �Ϲݰ��� �߰�

		if (mValidInput) {
			function<int(int)> GetCourseNum = [&](int idx) {
				if (idx == mSource || idx == mSubSource || idx == mSink) return 0;
				if (idx <= mNumberOfEssentialCourse) return idx;
				return (idx - 1 - mSubSource) % mNumberOfNormalCourse + mSubSource;
			};

			mTimeTabList = mKspGraph.Construct_Ksp(mSource, mSink, mKValue, mCourseConflict, GetCourseNum);
		}
	}





public:   // Ksp�� �߰��� �����Ͽ� �ð�ǥ�� �����ϰ� ��ȯ
	tuple<vector<vector<Course>>, vector<vector<int>>, GetTimeTabResult> Get_TimeTable(int page)
	{
		if (!mValidInput) return { vector<vector<Course>>(), vector<vector<int>>(), GetTimeTabResult::InvalidInput };
		if (page <= 0) return { vector<vector<Course>>(), vector<vector<int>>(), GetTimeTabResult::CannotLoadPrev };


		// ���� �������� �ð�ǥ�� ���ٸ� �߰��� �ð�ǥ�� ����
		if ((int)mTimeTabList.size() <= mKValue * (page - 1)) {
			function<int(int)> GetCourseNum = [&](int idx) {
				if (idx == mSource || idx == mSubSource || idx == mSink) return 0;
				if (idx <= mNumberOfEssentialCourse) return idx;
				return (idx - 1 - mSubSource) % mNumberOfNormalCourse + mSubSource;
			};

			for (auto& timeTab : mKspGraph.Additional_Ksp(mKValue, mCourseConflict, GetCourseNum)) mTimeTabList.push_back(timeTab);

			// �߰��� ������ �ð�ǥ�� ���ٸ� ������ �� �ִ� �ð�ǥ�� ���ٰ� ���� (ù ȣ���̿��ٸ� input��ü�� �߸���)
			if ((int)mTimeTabList.size() <= mKValue * (page - 1)) return { vector<vector<Course>>(), vector<vector<int>>(), page == 1 ? GetTimeTabResult::InvalidInput : GetTimeTabResult::CannotLoadNext };
		}


		// �ð�ǥ�� ���Ե� ���� ������ ��������Ʈ ���·� ��ȯ
		int begin = mKValue * (page - 1), end = min((int)mTimeTabList.size(), mKValue * page);
		vector<vector<Course>> courseAdjList;   // ���Ե� ���� (�ð�ǥ��)
		vector<vector<int>> lankCount;          // �켱���� ī���� (�ð�ǥ��)


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