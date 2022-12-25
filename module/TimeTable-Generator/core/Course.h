
#pragma once
#include "./C++Header_STL.h"
#include "./Utility.h"



class Course
{
public:
	struct CourseID {
		string base, div;
		string ToString() { return base + "-" + div; }
	};

	struct LectureTime {
		string day; int start, end;
		string ToString() {
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

	bool operator<(const Course& other) const { return id.base == other.id.base ? id.div < other.id.div : id.base < other.id.base; }

	bool operator==(const Course& other) const { return id.base == other.id.base && id.div == other.id.div; }
};



class CourseManager
{
public:
	static bool IsEmptyBlock(string& block) { return block == "*"; }

	static bool IsSubString(string& text, string& pattern) {
		string t = "";
		string p = "";
		
		for (auto& e : text) t += toupper(e);
		for (auto& e : pattern) p += toupper(e);

		return t.find(p) != string::npos;
	}

	static vector<Course> Load_CourseList(string& path, tuple<string, string>& filter)
	{
		vector<Course> courseList;
		ifstream ifs("./documents/mdrims/" + path);
		//ofstream ofs("./log.txt");
	
		if (ifs.is_open())
		{
			string buffer;

			while (!ifs.eof())
			{
				getline(ifs, buffer);
				if (buffer.empty()) continue;
				//ofs << buffer << '\n';

				auto fileLine = util::Split(buffer, util::SplitType::Contain, regex(R"("[^"]{1,}"|[^,]{1,})"));
				auto newCourse = Course();

				// 교과과정 추가
				newCourse.curriculum = fileLine[0];

				// 학수번호 추가 (학수번호를 앞자리, 뒷자리로 분리하여 추가)
				newCourse.id = { fileLine[1], fileLine[2] };

				// 교과목명 추가
				newCourse.name = util::Split(fileLine[3], util::Contain, regex(R"([^"]{1,})"))[0];   // "a,b,c" 형태의 교과목명이 존재하므로 큰따옴표 제거 처리 필요

				// 학점 추가
				if (IsEmptyBlock(fileLine[4])) 	newCourse.credit = 0;
				else newCourse.credit = stoi(fileLine[4]);

				// 교원명 추가
				if (IsEmptyBlock(fileLine[5])) newCourse.professor = "";
				else newCourse.professor = fileLine[5];

				// 강의 시간 추가 List<요일, 시작 시간, 종료 시간>
				if (IsEmptyBlock(fileLine[6])) newCourse.times = vector<Course::LectureTime>();
				else {
					newCourse.times = vector<Course::LectureTime>();
					for (int i = 6; i < fileLine.size(); i += 3)
						newCourse.times.push_back({ fileLine[i], stoi(fileLine[i + 1]), stoi(fileLine[i + 2]) });
				}

				// filter 체크
				bool pass = true;
				auto& [courseName, professor] = filter;

				if (!courseName.empty() && !IsSubString(newCourse.name, courseName))pass = false;
				if (!professor.empty() && !IsSubString(newCourse.professor, professor))pass = false;

				//if (!courseName.empty() && newCourse.name.find(courseName) == string::npos) pass = false;
				//if (!professor.empty() && newCourse.professor.find(professor) == string::npos) pass = false;

				// 생성된 과목 추가
				if (pass) courseList.push_back(newCourse);

			}
			ifs.close();
		}

		return courseList;
	}
};