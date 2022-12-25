
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

// 공과대학
void CreateCSV_Major_CSE();           // 공과대학-컴퓨터공학전공
void CreateCSV_Major_MME();           // 공과대학-멀티미디어공학과



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

	// 공과대학
	cout << "\n- 공과대학\n";
	CreateCSV_Major_CSE();
	CreateCSV_Major_MME();


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
			for (auto& lectureTime : util::Split(fileLine[5], util::Contain, regex(R"([^,"]{1,})"))) {
				auto day = util::Split(lectureTime, util::Except, regex(R"(\d{1,}.\d{1,}-\d{1,}.\d{1,}/\d{1,}:\d{1,}-\d{1,}:\d{1,})"));
				auto time = util::Split(lectureTime, util::Contain, regex(R"(\d{1,})"));

				newLine.push_back(day[0]);
				newLine.push_back(to_string(stoi(time[4]) * 60 + stoi(time[5])));
				newLine.push_back(to_string(stoi(time[6]) * 60 + stoi(time[7])));
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



// 공과대학
void CreateCSV_Major_CSE() {   // 공과대학-컴퓨터공학전공
	if (CSV_Format_Type1("./documents/origin/mdrims/전공/공과대학/컴퓨터공학전공.csv", "./documents/mdrims/전공/공과대학/컴퓨터공학전공.csv"))
		cout << "\"컴퓨터공학전공.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"컴퓨터공학전공.CSV\"\n";
}

void CreateCSV_Major_MME() {  // 공과대학-멀티미디어공학과
	if (CSV_Format_Type1("./documents/origin/mdrims/전공/공과대학/멀티미디어공학과.csv", "./documents/mdrims/전공/공과대학/멀티미디어공학과.csv"))
		cout << "\"멀티미디어공학과.CSV\" Created Successfully!!!\n";
	else cout << "Failed to created \"멀티미디어공학과.CSV\"\n";
}

