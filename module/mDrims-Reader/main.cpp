
#include "./core/C++Header.h"
#include "./core/FileManager.h"



// 입출력 형식
bool IsEmptyBlock(string& block);
bool CSV_Format_Type1(string inputPath, string outputPath);   // CSV 파일 형식 type1

// 일반과목
void CreateCSV_CommonLiberalArts();       // 공통교양
void CreateCSV_CoreLiberalArts();         // 핵심교양
void CreateCSV_AcademicBasics();          // 학문기초
void CreateCSV_GeneralLiberalArts();      // 일반교양
void CreateCSV_UniversityMajorBasics();   // 대학전공기초
void CreateCSV_TeachingProfession();      // 교직
void CreateCSV_MilitaryScience();         // 군사학
void CreateCSV_LifelongEducation();       // 평생교육
void CreateCSV_FreeChoice();              // 자유선택
void CreateCSV_NanoDegree();              // 나노디그리

// AI융합대학
void CreateCSV_Major_ASW();           // AI융합대학-AI소프트웨어융합학부
void CreateCSV_Major_CSE();           // AI융합대학-컴퓨터공학전공
void CreateCSV_Major_MME();           // AI융합대학-멀티미디어소프트웨어공학전공
void CreateCSV_Major_AIC();           // AI융합대학-인공지능전공
void CreateCSV_Major_AID();           // AI융합대학-데이터사이언스전공
void CreateCSV_Major_AIE();           // AI융합대학-엔터테인먼트테크놀로지전공
void CreateCSV_Major_AIB();           // AI융합대학-AI융합대


int main()
{
	// 일반 과목
	cout << "\n- 일반과목\n";
	CreateCSV_CommonLiberalArts();
	CreateCSV_CoreLiberalArts();
	CreateCSV_AcademicBasics();
	CreateCSV_GeneralLiberalArts();
	CreateCSV_UniversityMajorBasics();
	CreateCSV_TeachingProfession();
	CreateCSV_MilitaryScience();
	CreateCSV_LifelongEducation();
	CreateCSV_FreeChoice();
	CreateCSV_NanoDegree();

	// AI융합대학
	cout << "\n- AI융합대학\n";
	CreateCSV_Major_ASW();
	CreateCSV_Major_CSE();
	CreateCSV_Major_MME();
	CreateCSV_Major_AIC();
	CreateCSV_Major_AID();
	CreateCSV_Major_AIE();
	CreateCSV_Major_AIB();


	cout << "\n\nfinish...\n\n";

	system("pause");
	return 0;
}



// 입출력 형식
bool IsEmptyBlock(string& block) { return block == "*"; }

bool CSV_Format_Type1(string inputPath, string outputPath)   // CSV 파일 형식 type1
{
	auto fileData = FileManager::Read_CSV(inputPath, util::SplitType::Contain, regex(R"("[^"]{1,}"|[^,]{1,})"));
	auto newFileData = vector<vector<string>>((int)fileData.size(), vector<string>());

	for (int i = 0; i < (int)fileData.size(); i++)
	{
		auto& fileLine = fileData[i];
		auto& newLine = newFileData[i];

		// 교과과정 추가
		newLine.push_back(fileLine[0]);

		// 학수번호 추가 (학수번호를 앞자리, 뒷자리로 분리하여 추가)
		for (auto& courseID : util::Split(fileLine[1], util::SplitType::Except, regex(R"(-)")))
			newLine.push_back(courseID);

		// 교과목명 추가
		newLine.push_back(fileLine[2]);

		// 학점 추가
		newLine.push_back(fileLine[3]);

		// 교원명 추가
		newLine.push_back(fileLine[4]);

		// 강의 시간 추가 List<요일, 시작 시간, 종료 시간>
		if (IsEmptyBlock(fileLine[5])) newLine.push_back(fileLine[5]);
		else {
			auto prevLecture = tuple(string(), string(), string());

			for (auto& lectureTime : util::Split(fileLine[5], util::Contain, regex(R"([^,"]{1,})"))) {
				auto day = util::Split(lectureTime, util::Except, regex(R"(\d{1,}.\d{1,}-\d{1,}.\d{1,}/\d{1,}:\d{1,}-\d{1,}:\d{1,})"));
				auto time = util::Split(lectureTime, util::Contain, regex(R"(\d{1,})"));
				auto currLecture = tuple(day[0], to_string(stoi(time[4]) * 60 + stoi(time[5])), to_string(stoi(time[6]) * 60 + stoi(time[7])));

				// 연속 강의면 합침
				if (get<0>(prevLecture) == get<0>(currLecture) && get<2>(prevLecture) == get<1>(currLecture)) {
					(* (--newLine.end())) = get<2>(currLecture);
				}
				else {
					newLine.push_back(get<0>(currLecture));
					newLine.push_back(get<1>(currLecture));
					newLine.push_back(get<2>(currLecture));
				}

				prevLecture = currLecture;
			}
		}
	}

	return FileManager::Write_CSV(outputPath, newFileData);
}



// 일반과목
void CreateCSV_CommonLiberalArts() {   // 공통교양
	if (CSV_Format_Type1("./documents/origin/mdrims/공통교양/공통교양.csv", "./documents/mdrims/공통교양/공통교양.csv"))
		cout << "\"공통교양.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"공통교양.CSV\"\n";
}

void CreateCSV_CoreLiberalArts() {   // 핵심교양
	if (CSV_Format_Type1("./documents/origin/mdrims/핵심교양/핵심교양.csv", "./documents/mdrims/핵심교양/핵심교양.csv"))
		cout << "\"핵심교양.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"핵심교양.CSV\"\n";
}

void CreateCSV_AcademicBasics() {   // 학문기초
	if (CSV_Format_Type1("./documents/origin/mdrims/학문기초/학문기초.csv", "./documents/mdrims/학문기초/학문기초.csv"))
		cout << "\"학문기초.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"학문기초.CSV\"\n";
}

void CreateCSV_GeneralLiberalArts() {  // 일반교양
	if (CSV_Format_Type1("./documents/origin/mdrims/일반교양/일반교양.csv", "./documents/mdrims/일반교양/일반교양.csv"))
		cout << "\"일반교양.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"일반교양.CSV\"\n";
}

void CreateCSV_UniversityMajorBasics() {  // 대학전공기초
	if (CSV_Format_Type1("./documents/origin/mdrims/대학전공기초/대학전공기초.csv", "./documents/mdrims/대학전공기초/대학전공기초.csv"))
		cout << "\"대학전공기초.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"대학전공기초.CSV\"\n";
}

void CreateCSV_TeachingProfession() {  // 교직
	if (CSV_Format_Type1("./documents/origin/mdrims/교직/교직.csv", "./documents/mdrims/교직/교직.csv"))
		cout << "\"교직.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"교직.CSV\"\n";
}

void CreateCSV_MilitaryScience() {  // 군사학
	if (CSV_Format_Type1("./documents/origin/mdrims/군사학/군사학.csv", "./documents/mdrims/군사학/군사학.csv"))
		cout << "\"군사학.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"군사학.CSV\"\n";
}

void CreateCSV_LifelongEducation() {  // 평생교육
	if (CSV_Format_Type1("./documents/origin/mdrims/평생교육/평생교육.csv", "./documents/mdrims/평생교육/평생교육.csv"))
		cout << "\"평생교육.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"평생교육.CSV\"\n";
}

void CreateCSV_FreeChoice() {  // 자유선택
	if (CSV_Format_Type1("./documents/origin/mdrims/자유선택/자유선택.csv", "./documents/mdrims/자유선택/자유선택.csv"))
		cout << "\"자유선택.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"자유선택.CSV\"\n";
}

void CreateCSV_NanoDegree() {  // 나노디그리
	if (CSV_Format_Type1("./documents/origin/mdrims/나노디그리/나노디그리.csv", "./documents/mdrims/나노디그리/나노디그리.csv"))
		cout << "\"나노디그리.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"나노디그리.CSV\"\n";
}



// AI융합대학
void CreateCSV_Major_ASW() {   // AI융합대학-AI소프트웨어융합학부
	if (CSV_Format_Type1("./documents/origin/mdrims/전공/AI융합대학/AI소프트웨어융합학부.csv", "./documents/mdrims/전공/AI융합대학/AI소프트웨어융합학부.csv"))
		cout << "\"AI소프트웨어융합학부.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"AI소프트웨어융합학부.CSV\"\n";
}

void CreateCSV_Major_CSE() {   // AI융합대학-컴퓨터공학전공
	if (CSV_Format_Type1("./documents/origin/mdrims/전공/AI융합대학/컴퓨터공학전공.csv", "./documents/mdrims/전공/AI융합대학/컴퓨터공학전공.csv"))
		cout << "\"컴퓨터공학전공.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"컴퓨터공학전공.CSV\"\n";
}

void CreateCSV_Major_MME() {  // AI융합대학-멀티미디어소프트웨어공학전공
	if (CSV_Format_Type1("./documents/origin/mdrims/전공/AI융합대학/멀티미디어소프트웨어공학전공.csv", "./documents/mdrims/전공/AI융합대학/멀티미디어소프트웨어공학전공.csv"))
		cout << "\"멀티미디어소프트웨어공학전공.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"멀티미디어소프트웨어공학전공.CSV\"\n";
}

void CreateCSV_Major_AIC() {   // AI융합대학-인공지능전공
	if (CSV_Format_Type1("./documents/origin/mdrims/전공/AI융합대학/인공지능전공.csv", "./documents/mdrims/전공/AI융합대학/인공지능전공.csv"))
		cout << "\"인공지능전공.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"인공지능전공.CSV\"\n";
}

void CreateCSV_Major_AID() {   // AI융합대학-데이터사이언스전공
	if (CSV_Format_Type1("./documents/origin/mdrims/전공/AI융합대학/데이터사이언스전공.csv", "./documents/mdrims/전공/AI융합대학/데이터사이언스전공.csv"))
		cout << "\"데이터사이언스전공.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"데이터사이언스전공.CSV\"\n";
}

void CreateCSV_Major_AIE() {   // AI융합대학-엔터테인먼트테크놀로지전공
	if (CSV_Format_Type1("./documents/origin/mdrims/전공/AI융합대학/엔터테인먼트테크놀로지전공.csv", "./documents/mdrims/전공/AI융합대학/엔터테인먼트테크놀로지전공.csv"))
		cout << "\"엔터테인먼트테크놀로지전공.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"엔터테인먼트테크놀로지전공.CSV\"\n";
}

void CreateCSV_Major_AIB() {   // AI융합대학-AI융합대
	if (CSV_Format_Type1("./documents/origin/mdrims/전공/AI융합대학/AI융합대.csv", "./documents/mdrims/전공/AI융합대학/AI융합대.csv"))
		cout << "\"AI융합대.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"AI융합대.CSV\"\n";
}