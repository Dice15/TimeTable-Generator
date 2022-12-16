#pragma once

#include "./Utility.h"

#include <fstream>
#include <vector>
#include <string>
using namespace std;



class Course
{
public:
	struct CourseID {
		string base, div;
		string format() { return base + "-" + div; }
	};
	struct LectureTime {
		string day; int start, end;
		string format() {
			auto format = [&](string& s) { if (s.size() == 1) s.insert(s.begin(), '0'); return s; };
			return day + ", " + format(to_string(start / 60)) + ":" + format(to_string(start % 60)) + "~" + format(to_string(end / 60)) + ":" + format(to_string(end % 60));
		}
	};

	string curriculum;              // 교과과정
	CourseID id;                    // 학수번호
	string name;                    // 교과목명
	int credit;                     // 학점
	string professor;               // 담당교수
	vector<LectureTime> times;      // 강의시간

	Course() {}
	Course(string _curriculum, CourseID _id, string _name, int _credit, string _professor) :curriculum(_curriculum), id(_id), name(_name), credit(_credit), professor(_professor), times(vector<LectureTime>()) {}
};



class CourseManager
{
public:
	static vector<Course> Load_CourseList()
	{
		vector<Course> courseList;

		ifstream ifs("./documents/mdrims/all.csv");
		string buffer;

		if (ifs.is_open()) 
		{	
			while (!ifs.eof()) 
			{
				getline(ifs, buffer);
				auto line = util::Split(buffer, util::SplitType::Except, regex(R"(,)"));

				if (line.size() < 6) continue;
				courseList.push_back({ line[0], { line[1], line[2] }, line[3], stoi(line[4]), line[5] });
				for (int i = 6; i < line.size(); i += 3) courseList.back().times.push_back({ line[i], stoi(line[i + 1]), stoi(line[i + 2]) });
			}
			ifs.close();
		}

		return courseList;
	}


	static void Save_UserSetting(int targetCredit, vector<Course>& essnCourseList, vector<Course>& normCourseList, vector<int>& nomCourseLank)
	{
		ofstream ofs("./documents/results/wish.csv");

		if (ofs.is_open())
		{
			auto index = 0;
			auto label = vector<string>{ "필수", "1순위", "2순위", "3순위", "4순위","5순위" };

			ofs << "목표 학점" << "," << to_string(targetCredit) << '\n';
			for (auto& course : essnCourseList) {
				ofs << label[0] << "," << course.curriculum << "," << course.id.base << "," << course.id.div << "," << course.name << "," << course.credit << "," << course.professor;
				for (auto& lecTime : course.times) ofs << "," << lecTime.day << "," << lecTime.start << "," << lecTime.end;
				ofs << '\n';
			}
			for (auto& course : normCourseList) {
				ofs << label[nomCourseLank[index++]] << "," << course.curriculum << "," << course.id.base << "," << course.id.div << "," << course.name << "," << course.credit << "," << course.professor;
				for (auto& lecTime : course.times) ofs << "," << lecTime.day << "," << lecTime.start << "," << lecTime.end;
				ofs << '\n';
			}

			ofs.close();
		}
	}
};