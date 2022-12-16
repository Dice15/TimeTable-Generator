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
	bool mExistEssentialConflict;			// �ʼ����� ���̿����� �浹 Ȯ��

	int mKValue;							// �� ������ �� �����ִ� �ð�ǥ ����
	int mTargetCredit;						// ��ǥ����
	int mNumberOfEssentialCourse;			// �ʼ����� ��
	int mNumberOfNormalCourse;				// �Ϲݰ��� ��
	vector<Course> mEssentialCourseList;	// �ʼ������� ���� ����
	vector<Course> mNormalCourseList;		// �Ϲݰ����� ���� ����
	vector<int> mNormalCourseLank;			// �Ϲݰ����� �켱����

	WeightedGraph mKspGraph;				// ����ġ �׷���
	Bits mCommonConflict;					// �ʼ������ �浹�Ǵ� ����
	vector<Bits> mCourseConflict;			// i-th����� �浹�Ǵ� ����

	vector<TimeTab> mTimeTabList;			// ������ �ð�ǥ ����Ʈ	



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



private:	// ������ �浹 ���θ� üũ
	bool Check_CourseConflict(Course& fstCourse, Course& sndCourse)
	{
		if (fstCourse.id.base == sndCourse.id.base) return true;	// �м���ȣ ���ڸ��� ���� �� (���� ����)
		for (auto& fstTime : fstCourse.times)						// ���� �ð��� ��ĥ ��
			for (auto& sndTime : sndCourse.times)
				if (fstTime.day == sndTime.day && (fstTime.start < sndTime.end && fstTime.end > sndTime.start)) return true;
		return false;
	}



private:	// ������ ����ġ�� ���
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



private:	// �� ���񸶴� �浹�Ǵ� ������ ������ ������ �ִ� �迭 ����
	void Construct_CourseConflict()
	{
		// �ʼ� ������ �⵹
		for (int i = 1; i <= mNumberOfEssentialCourse; i++) {
			for (int j = i + 1; j <= mNumberOfEssentialCourse; j++)	// �ʼ� ���񳢸� �浹�� �ִٸ� false����
				if (Check_CourseConflict(mEssentialCourseList[i], mEssentialCourseList[j])) mExistEssentialConflict = true;

			for (int j = 1; j <= mNumberOfNormalCourse; j++)	// �ʼ� ����� �Ϲ� ���� ������ �浹 Ȯ��
				if (Check_CourseConflict(mEssentialCourseList[i], mNormalCourseList[j])) mCommonConflict |= (Bits)1 << (Bits)j;
		}

		// �Ϲ� ������ �浹
		for (int i = 1; i <= mNumberOfNormalCourse; i++) {
			mCourseConflict[i] = mCommonConflict;		// commonConflict(��� �ʼ������� �浹�Ǵ� �Ϲ� �����)
			for (int j = i + 1; j <= mNumberOfNormalCourse; j++)		// �Ϲ� ���� ������ �浹 Ȯ��
				if (Check_CourseConflict(mNormalCourseList[i], mNormalCourseList[j])) mCourseConflict[i] |= (Bits)1 << (Bits)j;
		}
	}



private:	// KspGraph ����
	void Construct_KspGraph()
	{
		if (mExistEssentialConflict) return;
		if (mTargetCredit == 0) { mTimeTabList = vector<Bits>{ 0 }; return; }

		int source = 0, sink = (mNumberOfNormalCourse * mTargetCredit) + 1, level = mTargetCredit;
		auto convVertexNum = [&](int vNum, int lev) { return vNum + ((lev - 1) * mNumberOfNormalCourse); };
		function<int(int)> GetCourseNum = [&](int idx) { return idx == source ? 0 : idx == sink ? mNumberOfNormalCourse + 1 : ((idx - 1) % mNumberOfNormalCourse) + 1; };



		// TODO: long long -> int�� �ٲٴ� �۾��� �ʿ���

		mKspGraph.Assign(sink + 1, 2e18, 1e18, 0);	// TODO: Graph�� ����ġ�� int������ �ٲ�ٸ� �����ؾ� ��

		// Source�� �Ϲ� ���� ����
		for (int v = 1; v <= mNumberOfNormalCourse; v++) {	// TODO: Source�κ����� ���� ����ȭ �ʿ� 
			if (mNormalCourseList[v].credit > level) continue;
			if (!(mCommonConflict & (Bits)1 << (Bits)v)) mKspGraph.Add_Directed_Edge(source, convVertexNum(v, mNormalCourseList[v].credit), Get_CourseWeight(v));
		}

		// Sink�� �Ϲ� ���� ����
		for (int u = 1; u <= mNumberOfNormalCourse; u++)	// TODO: Sink���� ���� ����ȭ �ʿ� 
			if (!(mCommonConflict & (Bits)1 << (Bits)u)) mKspGraph.Add_Directed_Edge(convVertexNum(u, level), sink, 0);

		// �Ϲ� ���񳢸� ����
		for (int lev = 1; lev < level; lev++) {	// TODO: ���� ����ȭ �ʿ�
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





public:		// Ksp�� �߰��� �����Ͽ� �ð�ǥ�� �����ϰ� ��ȯ
	tuple<vector<Course>, vector<vector<Course>>, vector<vector<int>>, GetTimeTabResult> Get_TimeTable(int page)
	{
		if (page <= 0) return { vector<Course>(), vector<vector<Course>>(), vector<vector<int>>(), GetTimeTabResult::CannotLoadPrev };
		if (mExistEssentialConflict) return { vector<Course>(), vector<vector<Course>>(), vector<vector<int>>(), GetTimeTabResult::EssentialConflict };


		// ���� �������� �ð�ǥ�� ���ٸ� �߰��� �ð�ǥ�� ����
		if ((int)mTimeTabList.size() <= mKValue * (page - 1)) {
			int source = 0, sink = (mNumberOfNormalCourse * mTargetCredit) + 1;
			function<int(int)> GetCourseNum = [&](int idx) { return idx == source ? 0 : idx == sink ? mNumberOfNormalCourse + 1 : ((idx - 1) % mNumberOfNormalCourse) + 1; };
			for (auto& timeTab : mKspGraph.Additional_Ksp(mKValue, mCourseConflict, GetCourseNum)) mTimeTabList.push_back(timeTab);

			// �߰��� ������ �ð�ǥ�� ���ٸ� ������ �� �ִ� �ð�ǥ�� ���ٰ� ���� (ù ȣ���̿��ٸ� input��ü�� �߸���)
			if ((int)mTimeTabList.size() <= mKValue * (page - 1)) return { vector<Course>(), vector<vector<Course>>(), vector<vector<int>>(), page == 1 ? GetTimeTabResult::CannotCreateTimeTab : GetTimeTabResult::CannotLoadNext };
		}


		// �ð�ǥ�� ���Ե� ���� ������ ��������Ʈ ���·� ��ȯ
		int begin = mKValue * (page - 1), end = min((int)mTimeTabList.size(), mKValue * page);
		vector<Course> essentialCourseList;				// �ʼ����� (����)
		vector<vector<Course>> normalCourseAdjList;		// �Ϲݰ��� (�ð�ǥ��)
		vector<vector<int>> timeTbCourseLankCount;		// �켱���� ī���� (�ð�ǥ��)


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