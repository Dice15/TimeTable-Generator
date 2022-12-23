
#pragma once
#include "./core/C++Header_STL.h"
#include "./core/Course.h"
#include "./generator//ui/TimeTabForm.h"



namespace TimeTableGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	/// <summary>
	/// 메인 Form: 개설된 과목 리스트에서 원하는 과목을 선택하고 선호도를 부여
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void) {
			mProcessCheck_Initializing = true;
			InitializeComponent();
			InitialzerMembers();
			mProcessCheck_Initializing = false;
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btCallGenerator;
	protected:

	private: System::Windows::Forms::DataGridView^ gvCourseList;
	private: System::Windows::Forms::DataGridView^ gvSelectCourse;

	private: System::Windows::Forms::ComboBox^ cbTargetCredit;
	private: System::Windows::Forms::Label^ lbTargetCredit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column0;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;




	private: System::Windows::Forms::Label^ lbIdxSelect;
	private: System::Windows::Forms::Label^ lbIDSelect;


	private: System::Windows::Forms::TextBox^ tbIdxSelect;
	private: System::Windows::Forms::Button^ btIdxSelect;
	private: System::Windows::Forms::TextBox^ tbIDSelect;
	private: System::Windows::Forms::Button^ btIDSelect;
	private: System::Windows::Forms::Label^ lbRestDay;
	private: System::Windows::Forms::CheckBox^ cbRestDay0;
	private: System::Windows::Forms::CheckBox^ cbRestDay1;
	private: System::Windows::Forms::CheckBox^ cbRestDay2;
	private: System::Windows::Forms::CheckBox^ cbRestDay3;
	private: System::Windows::Forms::CheckBox^ cbRestDay4;














	private: System::Windows::Forms::CheckBox^ cbSetRangeCredit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SelectList_Column0;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SelectList_Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SelectList_Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SelectList_Column3;
	private: System::Windows::Forms::CheckBox^ cbRestDay5;
	private: System::Windows::Forms::Label^ lbRestTime;
	private: System::Windows::Forms::ComboBox^ cbRestTimeDay;
	private: System::Windows::Forms::ComboBox^ cbRestTimeStart;
	private: System::Windows::Forms::ComboBox^ cbRestTimeEnd;
	private: System::Windows::Forms::Button^ btRestTimeAdd;








	private: System::Windows::Forms::Label^ lbRestTimeStoE;
	private: System::Windows::Forms::DataGridView^ gvRestTimeList;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;









































	protected:

	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드
		/// </summary>
		void InitializeComponent(void)
		{
			this->btCallGenerator = (gcnew System::Windows::Forms::Button());
			this->gvCourseList = (gcnew System::Windows::Forms::DataGridView());
			this->Column0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->gvSelectCourse = (gcnew System::Windows::Forms::DataGridView());
			this->SelectList_Column0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SelectList_Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SelectList_Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SelectList_Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cbTargetCredit = (gcnew System::Windows::Forms::ComboBox());
			this->lbTargetCredit = (gcnew System::Windows::Forms::Label());
			this->lbIdxSelect = (gcnew System::Windows::Forms::Label());
			this->lbIDSelect = (gcnew System::Windows::Forms::Label());
			this->tbIdxSelect = (gcnew System::Windows::Forms::TextBox());
			this->btIdxSelect = (gcnew System::Windows::Forms::Button());
			this->tbIDSelect = (gcnew System::Windows::Forms::TextBox());
			this->btIDSelect = (gcnew System::Windows::Forms::Button());
			this->lbRestDay = (gcnew System::Windows::Forms::Label());
			this->cbRestDay0 = (gcnew System::Windows::Forms::CheckBox());
			this->cbRestDay1 = (gcnew System::Windows::Forms::CheckBox());
			this->cbRestDay2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbRestDay3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbRestDay4 = (gcnew System::Windows::Forms::CheckBox());
			this->cbSetRangeCredit = (gcnew System::Windows::Forms::CheckBox());
			this->cbRestDay5 = (gcnew System::Windows::Forms::CheckBox());
			this->lbRestTime = (gcnew System::Windows::Forms::Label());
			this->cbRestTimeDay = (gcnew System::Windows::Forms::ComboBox());
			this->cbRestTimeStart = (gcnew System::Windows::Forms::ComboBox());
			this->cbRestTimeEnd = (gcnew System::Windows::Forms::ComboBox());
			this->btRestTimeAdd = (gcnew System::Windows::Forms::Button());
			this->lbRestTimeStoE = (gcnew System::Windows::Forms::Label());
			this->gvRestTimeList = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvCourseList))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvSelectCourse))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvRestTimeList))->BeginInit();
			this->SuspendLayout();
			// 
			// btCallGenerator
			// 
			this->btCallGenerator->Font = (gcnew System::Drawing::Font(L"굴림", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->btCallGenerator->Location = System::Drawing::Point(920, 12);
			this->btCallGenerator->Name = L"btCallGenerator";
			this->btCallGenerator->Size = System::Drawing::Size(453, 51);
			this->btCallGenerator->TabIndex = 1;
			this->btCallGenerator->Text = L"시간표 생성";
			this->btCallGenerator->UseVisualStyleBackColor = true;
			this->btCallGenerator->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::btCallGenerator_MouseClick);
			// 
			// gvCourseList
			// 
			this->gvCourseList->AllowUserToAddRows = false;
			this->gvCourseList->AllowUserToDeleteRows = false;
			this->gvCourseList->AllowUserToResizeRows = false;
			this->gvCourseList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->gvCourseList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Column0,
					this->Column1, this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8
			});
			this->gvCourseList->Location = System::Drawing::Point(10, 68);
			this->gvCourseList->MultiSelect = false;
			this->gvCourseList->Name = L"gvCourseList";
			this->gvCourseList->ReadOnly = true;
			this->gvCourseList->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->gvCourseList->RowTemplate->Height = 23;
			this->gvCourseList->Size = System::Drawing::Size(895, 821);
			this->gvCourseList->TabIndex = 2;
			this->gvCourseList->RowHeaderMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainForm::gridView_courseList_RowHeaderMouseDoubleClick);
			// 
			// Column0
			// 
			this->Column0->HeaderText = L"Idx";
			this->Column0->Name = L"Column0";
			this->Column0->ReadOnly = true;
			this->Column0->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column0->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column0->Width = 35;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"교과과정";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"학수번호";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"교과목명";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"학점";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"담당교수";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"강의시간1";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"강의시간2";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"강의시간3";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// gvSelectCourse
			// 
			this->gvSelectCourse->AllowUserToAddRows = false;
			this->gvSelectCourse->AllowUserToDeleteRows = false;
			this->gvSelectCourse->AllowUserToResizeRows = false;
			this->gvSelectCourse->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->gvSelectCourse->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->SelectList_Column0,
					this->SelectList_Column1, this->SelectList_Column2, this->SelectList_Column3
			});
			this->gvSelectCourse->Location = System::Drawing::Point(920, 350);
			this->gvSelectCourse->MultiSelect = false;
			this->gvSelectCourse->Name = L"gvSelectCourse";
			this->gvSelectCourse->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->gvSelectCourse->RowTemplate->Height = 23;
			this->gvSelectCourse->Size = System::Drawing::Size(454, 539);
			this->gvSelectCourse->TabIndex = 3;
			this->gvSelectCourse->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::gvSelectCourse_CellValueChanged);
			this->gvSelectCourse->RowHeaderMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainForm::gvSelectCourse_RowHeaderMouseDoubleClick);
			this->gvSelectCourse->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &MainForm::gvSelectCourse_RowsAdded);
			this->gvSelectCourse->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &MainForm::gvSelectCourse_RowsRemoved);
			// 
			// SelectList_Column0
			// 
			this->SelectList_Column0->HeaderText = L"num";
			this->SelectList_Column0->Name = L"SelectList_Column0";
			this->SelectList_Column0->Width = 35;
			// 
			// SelectList_Column1
			// 
			this->SelectList_Column1->HeaderText = L"학수번호";
			this->SelectList_Column1->Name = L"SelectList_Column1";
			this->SelectList_Column1->ReadOnly = true;
			this->SelectList_Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// SelectList_Column2
			// 
			this->SelectList_Column2->HeaderText = L"교과목명";
			this->SelectList_Column2->Name = L"SelectList_Column2";
			this->SelectList_Column2->ReadOnly = true;
			this->SelectList_Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// SelectList_Column3
			// 
			this->SelectList_Column3->HeaderText = L"담당교수";
			this->SelectList_Column3->Name = L"SelectList_Column3";
			this->SelectList_Column3->ReadOnly = true;
			this->SelectList_Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// cbTargetCredit
			// 
			this->cbTargetCredit->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbTargetCredit->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->cbTargetCredit->FormattingEnabled = true;
			this->cbTargetCredit->Items->AddRange(gcnew cli::array< System::Object^  >(25) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24"
			});
			this->cbTargetCredit->Location = System::Drawing::Point(1014, 74);
			this->cbTargetCredit->Name = L"cbTargetCredit";
			this->cbTargetCredit->Size = System::Drawing::Size(257, 24);
			this->cbTargetCredit->TabIndex = 4;
			// 
			// lbTargetCredit
			// 
			this->lbTargetCredit->AutoSize = true;
			this->lbTargetCredit->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbTargetCredit->Location = System::Drawing::Point(932, 80);
			this->lbTargetCredit->Name = L"lbTargetCredit";
			this->lbTargetCredit->Size = System::Drawing::Size(76, 16);
			this->lbTargetCredit->TabIndex = 5;
			this->lbTargetCredit->Text = L"목표 학점";
			// 
			// lbIdxSelect
			// 
			this->lbIdxSelect->AutoSize = true;
			this->lbIdxSelect->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbIdxSelect->Location = System::Drawing::Point(53, 28);
			this->lbIdxSelect->Name = L"lbIdxSelect";
			this->lbIdxSelect->Size = System::Drawing::Size(118, 16);
			this->lbIdxSelect->TabIndex = 6;
			this->lbIdxSelect->Text = L"Idx로 과목 선택";
			// 
			// lbIDSelect
			// 
			this->lbIDSelect->AutoSize = true;
			this->lbIDSelect->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbIDSelect->Location = System::Drawing::Point(450, 28);
			this->lbIDSelect->Name = L"lbIDSelect";
			this->lbIDSelect->Size = System::Drawing::Size(161, 16);
			this->lbIDSelect->TabIndex = 7;
			this->lbIDSelect->Text = L"학수번호로 과목 선택";
			// 
			// tbIdxSelect
			// 
			this->tbIdxSelect->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbIdxSelect->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbIdxSelect->Location = System::Drawing::Point(177, 23);
			this->tbIdxSelect->Name = L"tbIdxSelect";
			this->tbIdxSelect->Size = System::Drawing::Size(145, 26);
			this->tbIdxSelect->TabIndex = 8;
			this->tbIdxSelect->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::tbIdxSelect_KeyPress);
			// 
			// btIdxSelect
			// 
			this->btIdxSelect->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->btIdxSelect->Location = System::Drawing::Point(328, 21);
			this->btIdxSelect->Name = L"btIdxSelect";
			this->btIdxSelect->Size = System::Drawing::Size(80, 30);
			this->btIdxSelect->TabIndex = 9;
			this->btIdxSelect->Text = L"추가";
			this->btIdxSelect->UseVisualStyleBackColor = true;
			this->btIdxSelect->Click += gcnew System::EventHandler(this, &MainForm::btIdxSelect_Click);
			// 
			// tbIDSelect
			// 
			this->tbIDSelect->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbIDSelect->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbIDSelect->Enabled = false;
			this->tbIDSelect->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbIDSelect->Location = System::Drawing::Point(617, 23);
			this->tbIDSelect->Name = L"tbIDSelect";
			this->tbIDSelect->ReadOnly = true;
			this->tbIDSelect->Size = System::Drawing::Size(145, 26);
			this->tbIDSelect->TabIndex = 10;
			this->tbIDSelect->Text = L"미구현";
			// 
			// btIDSelect
			// 
			this->btIDSelect->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->btIDSelect->Location = System::Drawing::Point(768, 21);
			this->btIDSelect->Name = L"btIDSelect";
			this->btIDSelect->Size = System::Drawing::Size(80, 30);
			this->btIDSelect->TabIndex = 11;
			this->btIDSelect->Text = L"추가";
			this->btIDSelect->UseVisualStyleBackColor = true;
			// 
			// lbRestDay
			// 
			this->lbRestDay->AutoSize = true;
			this->lbRestDay->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbRestDay->Location = System::Drawing::Point(932, 115);
			this->lbRestDay->Name = L"lbRestDay";
			this->lbRestDay->Size = System::Drawing::Size(76, 16);
			this->lbRestDay->TabIndex = 12;
			this->lbRestDay->Text = L"요일 공강";
			// 
			// cbRestDay0
			// 
			this->cbRestDay0->AutoSize = true;
			this->cbRestDay0->Location = System::Drawing::Point(1018, 115);
			this->cbRestDay0->Name = L"cbRestDay0";
			this->cbRestDay0->Size = System::Drawing::Size(36, 16);
			this->cbRestDay0->TabIndex = 13;
			this->cbRestDay0->Text = L"월";
			this->cbRestDay0->UseVisualStyleBackColor = true;
			this->cbRestDay0->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbRestDay0_CheckedChanged);
			// 
			// cbRestDay1
			// 
			this->cbRestDay1->AutoSize = true;
			this->cbRestDay1->Location = System::Drawing::Point(1070, 115);
			this->cbRestDay1->Name = L"cbRestDay1";
			this->cbRestDay1->Size = System::Drawing::Size(36, 16);
			this->cbRestDay1->TabIndex = 14;
			this->cbRestDay1->Text = L"화";
			this->cbRestDay1->UseVisualStyleBackColor = true;
			this->cbRestDay1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbRestDay1_CheckedChanged);
			// 
			// cbRestDay2
			// 
			this->cbRestDay2->AutoSize = true;
			this->cbRestDay2->Location = System::Drawing::Point(1122, 115);
			this->cbRestDay2->Name = L"cbRestDay2";
			this->cbRestDay2->Size = System::Drawing::Size(36, 16);
			this->cbRestDay2->TabIndex = 15;
			this->cbRestDay2->Text = L"수";
			this->cbRestDay2->UseVisualStyleBackColor = true;
			this->cbRestDay2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbRestDay2_CheckedChanged);
			// 
			// cbRestDay3
			// 
			this->cbRestDay3->AutoSize = true;
			this->cbRestDay3->Location = System::Drawing::Point(1174, 115);
			this->cbRestDay3->Name = L"cbRestDay3";
			this->cbRestDay3->Size = System::Drawing::Size(36, 16);
			this->cbRestDay3->TabIndex = 16;
			this->cbRestDay3->Text = L"목";
			this->cbRestDay3->UseVisualStyleBackColor = true;
			this->cbRestDay3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbRestDay3_CheckedChanged);
			// 
			// cbRestDay4
			// 
			this->cbRestDay4->AutoSize = true;
			this->cbRestDay4->Location = System::Drawing::Point(1226, 115);
			this->cbRestDay4->Name = L"cbRestDay4";
			this->cbRestDay4->Size = System::Drawing::Size(36, 16);
			this->cbRestDay4->TabIndex = 17;
			this->cbRestDay4->Text = L"금";
			this->cbRestDay4->UseVisualStyleBackColor = true;
			this->cbRestDay4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbRestDay4_CheckedChanged);
			// 
			// cbSetRangeCredit
			// 
			this->cbSetRangeCredit->AutoSize = true;
			this->cbSetRangeCredit->Enabled = false;
			this->cbSetRangeCredit->Location = System::Drawing::Point(1280, 80);
			this->cbSetRangeCredit->Name = L"cbSetRangeCredit";
			this->cbSetRangeCredit->Size = System::Drawing::Size(98, 16);
			this->cbSetRangeCredit->TabIndex = 18;
			this->cbSetRangeCredit->Text = L"범위 (미구현)";
			this->cbSetRangeCredit->UseVisualStyleBackColor = true;
			// 
			// cbRestDay5
			// 
			this->cbRestDay5->AutoSize = true;
			this->cbRestDay5->Enabled = false;
			this->cbRestDay5->Location = System::Drawing::Point(1278, 115);
			this->cbRestDay5->Name = L"cbRestDay5";
			this->cbRestDay5->Size = System::Drawing::Size(86, 16);
			this->cbRestDay5->TabIndex = 19;
			this->cbRestDay5->Text = L"토 (미구현)";
			this->cbRestDay5->UseVisualStyleBackColor = true;
			this->cbRestDay5->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbRestDay5_CheckedChanged);
			// 
			// lbRestTime
			// 
			this->lbRestTime->AutoSize = true;
			this->lbRestTime->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbRestTime->Location = System::Drawing::Point(932, 151);
			this->lbRestTime->Name = L"lbRestTime";
			this->lbRestTime->Size = System::Drawing::Size(76, 16);
			this->lbRestTime->TabIndex = 20;
			this->lbRestTime->Text = L"시간 공강";
			// 
			// cbRestTimeDay
			// 
			this->cbRestTimeDay->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbRestTimeDay->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->cbRestTimeDay->FormattingEnabled = true;
			this->cbRestTimeDay->Location = System::Drawing::Point(1014, 145);
			this->cbRestTimeDay->Name = L"cbRestTimeDay";
			this->cbRestTimeDay->Size = System::Drawing::Size(50, 24);
			this->cbRestTimeDay->TabIndex = 21;
			// 
			// cbRestTimeStart
			// 
			this->cbRestTimeStart->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbRestTimeStart->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->cbRestTimeStart->FormattingEnabled = true;
			this->cbRestTimeStart->Location = System::Drawing::Point(1070, 145);
			this->cbRestTimeStart->Name = L"cbRestTimeStart";
			this->cbRestTimeStart->Size = System::Drawing::Size(100, 24);
			this->cbRestTimeStart->TabIndex = 22;
			// 
			// cbRestTimeEnd
			// 
			this->cbRestTimeEnd->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbRestTimeEnd->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->cbRestTimeEnd->FormattingEnabled = true;
			this->cbRestTimeEnd->Location = System::Drawing::Point(1195, 145);
			this->cbRestTimeEnd->Name = L"cbRestTimeEnd";
			this->cbRestTimeEnd->Size = System::Drawing::Size(100, 24);
			this->cbRestTimeEnd->TabIndex = 23;
			// 
			// btRestTimeAdd
			// 
			this->btRestTimeAdd->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->btRestTimeAdd->Location = System::Drawing::Point(1301, 145);
			this->btRestTimeAdd->Name = L"btRestTimeAdd";
			this->btRestTimeAdd->Size = System::Drawing::Size(55, 24);
			this->btRestTimeAdd->TabIndex = 24;
			this->btRestTimeAdd->Text = L"추가";
			this->btRestTimeAdd->UseVisualStyleBackColor = true;
			this->btRestTimeAdd->Click += gcnew System::EventHandler(this, &MainForm::btRestTimeAdd_Click);
			// 
			// lbRestTimeStoE
			// 
			this->lbRestTimeStoE->AutoSize = true;
			this->lbRestTimeStoE->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbRestTimeStoE->Location = System::Drawing::Point(1173, 149);
			this->lbRestTimeStoE->Name = L"lbRestTimeStoE";
			this->lbRestTimeStoE->Size = System::Drawing::Size(19, 16);
			this->lbRestTimeStoE->TabIndex = 25;
			this->lbRestTimeStoE->Text = L"~";
			// 
			// gvRestTimeList
			// 
			this->gvRestTimeList->AllowUserToAddRows = false;
			this->gvRestTimeList->AllowUserToDeleteRows = false;
			this->gvRestTimeList->AllowUserToResizeRows = false;
			this->gvRestTimeList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->gvRestTimeList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->gvRestTimeList->Location = System::Drawing::Point(919, 179);
			this->gvRestTimeList->MultiSelect = false;
			this->gvRestTimeList->Name = L"gvRestTimeList";
			this->gvRestTimeList->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->gvRestTimeList->RowTemplate->Height = 23;
			this->gvRestTimeList->Size = System::Drawing::Size(454, 156);
			this->gvRestTimeList->TabIndex = 26;
			this->gvRestTimeList->RowHeaderMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainForm::gvRestTimeList_RowHeaderMouseDoubleClick);
			this->gvRestTimeList->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &MainForm::gvRestTimeList_RowsAdded);
			this->gvRestTimeList->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &MainForm::gvRestTimeList_RowsRemoved);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"num";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 35;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"공강 시간";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn2->Width = 375;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1384, 901);
			this->Controls->Add(this->gvRestTimeList);
			this->Controls->Add(this->lbRestTimeStoE);
			this->Controls->Add(this->btRestTimeAdd);
			this->Controls->Add(this->cbRestTimeEnd);
			this->Controls->Add(this->cbRestTimeStart);
			this->Controls->Add(this->cbRestTimeDay);
			this->Controls->Add(this->lbRestTime);
			this->Controls->Add(this->cbRestDay5);
			this->Controls->Add(this->cbSetRangeCredit);
			this->Controls->Add(this->cbRestDay4);
			this->Controls->Add(this->cbRestDay3);
			this->Controls->Add(this->cbRestDay2);
			this->Controls->Add(this->cbRestDay1);
			this->Controls->Add(this->cbRestDay0);
			this->Controls->Add(this->lbRestDay);
			this->Controls->Add(this->btIDSelect);
			this->Controls->Add(this->tbIDSelect);
			this->Controls->Add(this->btIdxSelect);
			this->Controls->Add(this->tbIdxSelect);
			this->Controls->Add(this->lbIDSelect);
			this->Controls->Add(this->lbIdxSelect);
			this->Controls->Add(this->lbTargetCredit);
			this->Controls->Add(this->cbTargetCredit);
			this->Controls->Add(this->gvSelectCourse);
			this->Controls->Add(this->gvCourseList);
			this->Controls->Add(this->btCallGenerator);
			this->Name = L"MainForm";
			this->Text = L"시간표 생성기";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvCourseList))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvSelectCourse))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvRestTimeList))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		String^ ToGcString(string& _std_string) { return gcnew String(_std_string.data()); }
		String^ ToGcString(int& _int_value) { return gcnew String(to_string(_int_value).data()); }
		string ToStdString(String^ _gc_string) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(_gc_string)).ToPointer();
			string _std_string = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			return _std_string;
		}


	private:
		const int mMaxSelectCount = 60;
		const int mNumberOfLank = 6;

		bool mProcessCheck_Initializing = false;
		bool mProcessCheck_SelectCourse = false;
		bool mProcessCheck_UnSelectCourse = false;
		bool mProcessCheck_ModifySelectedCourseLank = false;

		vector<Course>* mCourseList;
		vector<pair<int, Course>>* mSelectedCourseInfoList;

		unordered_set<string>* mRestDaySet;
		vector<Course::LectureTime>* mRestTimeList;




	private:   // 멤버 초기화
		System::Void InitialzerMembers() {
			Init_CourseList();
			Init_SelectedCourse();
			Init_TargetCredit();
			Init_Rest();
		}

		System::Void Init_CourseList() {
			mCourseList = new vector<Course>();
			LoadCourse();
		}

		System::Void Init_SelectedCourse() {
			mSelectedCourseInfoList = new vector<pair<int, Course>>();
			DataGridViewComboBoxColumn^ cbColumn = gcnew DataGridViewComboBoxColumn();

			cbColumn->Width = 75;
			cbColumn->HeaderText = "선호도";
			cbColumn->DisplayStyle = DataGridViewComboBoxDisplayStyle::ComboBox;
			cbColumn->Items->Add("0) 필수");
			cbColumn->Items->Add("1) *****");
			cbColumn->Items->Add("2) ****");
			cbColumn->Items->Add("3) ***");
			cbColumn->Items->Add("4) **");
			cbColumn->Items->Add("5) *");
			gvSelectCourse->Columns->Add(cbColumn);
		}

		System::Void Init_TargetCredit() {
			cbTargetCredit->SelectedIndex = 0;
		}

		System::Void Init_Rest() {
			mRestDaySet = new unordered_set<string>();
			mRestTimeList = new vector<Course::LectureTime>();

			cbRestTimeDay->Items->Add("월");
			cbRestTimeDay->Items->Add("화");
			cbRestTimeDay->Items->Add("수");
			cbRestTimeDay->Items->Add("목");
			cbRestTimeDay->Items->Add("금");
			cbRestTimeDay->Items->Add("토");
			cbRestTimeDay->SelectedIndex = 0;

			for (int h = 8; h < 24; h++) {
				for (int m = 0; m < 60; m += 30) {
					cbRestTimeStart->Items->Add((h < 10 ? "0" : "") + h.ToString() + ":" + (m < 10 ? "0" : "") + m.ToString());
					cbRestTimeEnd->Items->Add((h < 10 ? "0" : "") + h.ToString() + ":" + (m < 10 ? "0" : "") + m.ToString());
				}
			}
			cbRestTimeStart->Items->RemoveAt(cbRestTimeStart->Items->Count - 1);
			cbRestTimeEnd->Items->RemoveAt(0);
			cbRestTimeStart->SelectedIndex = 0;
			cbRestTimeEnd->SelectedIndex = 0;
		}



	private:   // 원하는 카테코리(특정 학과 전공, 일반 교양, 공통 교양 등,,,)에 해당하는 과목 리스트를 불러온다.
		System::Void LoadCourse(/*string todo_implement*/) {   // TODO: 앱 개발 시 과목 카테고리 기능 추가 필요

			*mCourseList = CourseManager::Load_CourseList();   // 불러온 과목 리스트를 mCourseList에 저장

			for (auto& course : *mCourseList) {   // 불러온 과목 리스트를 gvCourseList에 추가하여 사용자에게 보여줌
				gvCourseList->Rows->Add(
					gvCourseList->Rows->Count.ToString(),
					ToGcString(course.curriculum),
					ToGcString(course.id.ToString()),
					ToGcString(course.name),
					ToGcString(course.credit),
					ToGcString(course.professor),
					course.times.size() > 0 ? ToGcString(course.times[0].ToString()) : ToGcString(string()),
					course.times.size() > 1 ? ToGcString(course.times[1].ToString()) : ToGcString(string()),
					course.times.size() > 2 ? ToGcString(course.times[2].ToString()) : ToGcString(string())
				);
			}
		}



	private: // gvCourseList에서 과목을 선택하는 이벤트
		System::Boolean IsAlreadySelectedCourse(Course& newCourse) {
			for (auto& selectedCourseInfo : *mSelectedCourseInfoList)
				if (selectedCourseInfo.second == newCourse) return true;
			return false;
		}

		System::Boolean IsFullSelectedCourse() {
			return (int)mSelectedCourseInfoList->size() < mMaxSelectCount ? false : true;
		}

		System::Void SelectCourse(Course& newCourse) {	// gvCourseList에서 선택한 과목을 gvSelectedCourse에 추가
			if (IsAlreadySelectedCourse(newCourse)) { MessageBox::Show("이미 선택한 과목입니다"); return; }   // 이미 선택한 과목이면 추가하는 과정을 진행하지 않음
			if (IsFullSelectedCourse()) { MessageBox::Show("최대 " + mMaxSelectCount + "개의 과목을 선택할 수 있습니다(TimeTable - Beta)"); return; }   // 최대로 선택할 수 있는 과목 확인

			// mSelectedCourseInfoList에 선택한 과목 추가
			mSelectedCourseInfoList->push_back({ mNumberOfLank - 1, newCourse });
			sort(mSelectedCourseInfoList->begin(), mSelectedCourseInfoList->end());

			// gvSelectedCourse의 데이터 갱신
			gvSelectCourse->Rows->Clear();
			for (auto& [lank, course] : *mSelectedCourseInfoList) {
				int idx = gvSelectCourse->Rows->Add(gvSelectCourse->Rows->Count, ToGcString(course.id.ToString()), ToGcString(course.name), ToGcString(course.professor));
				auto comb = (DataGridViewComboBoxCell^)(gvSelectCourse->Rows[idx]->Cells[4]);
				comb->Value = comb->Items[lank];
			}
		}

		System::Void gridView_courseList_RowHeaderMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {	// 직접 클릭
			mProcessCheck_SelectCourse = true;
			SelectCourse((*mCourseList)[e->RowIndex]);
			mProcessCheck_SelectCourse = false;
		}

		System::Void btIdxSelect_Click(System::Object^ sender, System::EventArgs^ e) {	// Idx 입력 후 버튼
			mProcessCheck_SelectCourse = true;

			int idx = -1;
			if (int::TryParse(tbIdxSelect->Text, idx)) {
				if (0 <= idx && idx < (int)(*mCourseList).size()) SelectCourse((*mCourseList)[idx]);
				else MessageBox::Show("Idx 최대값은 " + ((int)(*mCourseList).size() - 1) + "입니다");
			}
			else MessageBox::Show("\"" + tbIdxSelect->Text + "\"는(은) " + "자연수로 변환할 수 없습니다");
			tbIdxSelect->Text = "";

			mProcessCheck_SelectCourse = false;
		}

		System::Void tbIdxSelect_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {	// Idx 입력 후 enter키
			mProcessCheck_SelectCourse = true;

			if (e->KeyChar == (char)Keys::Enter) {
				int idx = -1;
				if (int::TryParse(tbIdxSelect->Text, idx)) {
					if (0 <= idx && idx < (int)(*mCourseList).size()) SelectCourse((*mCourseList)[idx]);
					else MessageBox::Show("Idx 최대값은 " + ((int)(*mCourseList).size() - 1) + "입니다");
				}
				else MessageBox::Show("\"" + tbIdxSelect->Text + "\"는(은) " + "자연수로 변환할 수 없습니다");
				tbIdxSelect->Text = "";
			}

			mProcessCheck_SelectCourse = false;
		}



	private: // gvSelectCourse에서 선택한 과목을 삭제하는 이벤트
		System::Void gvSelectCourse_RowHeaderMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
			mProcessCheck_UnSelectCourse = true;

			int idx = e->RowIndex;

			// mSelectedCourseInfoList의 idx번째 과목 삭제	
			mSelectedCourseInfoList->erase(mSelectedCourseInfoList->begin() + idx);

			// gvSelectedCourse의 idx번째 과목 삭제하고 넘버링을 다시 한다
			gvSelectCourse->Rows->RemoveAt(idx);
			for (int i = 0; i < gvSelectCourse->Rows->Count; i++)
				gvSelectCourse->Rows[i]->Cells[0]->Value = i;

			mProcessCheck_UnSelectCourse = false;
		}



	private: // gvSelectCourse에서 scroll의 유무에 따라 3번 column의 너비를 변경해야 한다
		System::Void gvSelectCourse_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
			if (gvSelectCourse->Rows->Count > 22)
				gvSelectCourse->Columns[3]->Width = 82;
		}

		System::Void gvSelectCourse_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e) {
			if (gvSelectCourse->Rows->Count < 23)
				gvSelectCourse->Columns[3]->Width = 100;
		}



	private: // gvSelectCourse에서 과목의 우선순위를 변경했을 때, 발생하는 정렬 이벤트
		System::Void gvSelectCourse_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (mProcessCheck_Initializing || mProcessCheck_SelectCourse || mProcessCheck_UnSelectCourse || mProcessCheck_ModifySelectedCourseLank) return;
			mProcessCheck_ModifySelectedCourseLank = true;

			int eColumnIdx = e->ColumnIndex;
			int eRowIdx = e->RowIndex;

			if (eColumnIdx == 4) {
				// mSelectedCourseInfoList의 eRowIdx번째 과목의 Lank변경
				(*mSelectedCourseInfoList)[eRowIdx].first = ToStdString(gvSelectCourse->Rows[eRowIdx]->Cells[4]->Value->ToString())[0] - 48;
				sort(mSelectedCourseInfoList->begin(), mSelectedCourseInfoList->end());

				// gvSelectedCourse의 데이터 갱신
				gvSelectCourse->Rows->Clear();
				for (auto& [lank, course] : *mSelectedCourseInfoList) {
					int idx = gvSelectCourse->Rows->Add(gvSelectCourse->Rows->Count, ToGcString(course.id.ToString()), ToGcString(course.name), ToGcString(course.professor));
					auto comb = (DataGridViewComboBoxCell^)(gvSelectCourse->Rows[idx]->Cells[4]);
					comb->Value = comb->Items[lank];

					if (lank == 0) gvSelectCourse->Rows[idx]->DefaultCellStyle->BackColor = Color::FromArgb(240, 134, 118);   // 필수과목은 색상처리
				}
			}

			mProcessCheck_ModifySelectedCourseLank = false;
		}



	private:   // 요일 공강 버튼에 대한 이벤트 처리
		System::Void SelectRestDay(string day) {
			if (mRestDaySet->find(day) == mRestDaySet->end()) mRestDaySet->insert(day);
		}

		System::Void UnSelectRestDay(string day) {
			if (mRestDaySet->find(day) != mRestDaySet->end()) mRestDaySet->erase(day);
		}

		System::Void cbRestDay0_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { ((CheckBox^)sender)->Checked ? SelectRestDay("월") : UnSelectRestDay("월"); }
		System::Void cbRestDay1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { ((CheckBox^)sender)->Checked ? SelectRestDay("화") : UnSelectRestDay("화"); }
		System::Void cbRestDay2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { ((CheckBox^)sender)->Checked ? SelectRestDay("수") : UnSelectRestDay("수"); }
		System::Void cbRestDay3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { ((CheckBox^)sender)->Checked ? SelectRestDay("목") : UnSelectRestDay("목"); }
		System::Void cbRestDay4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { ((CheckBox^)sender)->Checked ? SelectRestDay("금") : UnSelectRestDay("금"); }
		System::Void cbRestDay5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { ((CheckBox^)sender)->Checked ? SelectRestDay("토") : UnSelectRestDay("토"); }



	private:   // 시간 공강을 추가하는 이벤트
		System::Void btRestTimeAdd_Click(System::Object^ sender, System::EventArgs^ e) {
			if (cbRestTimeStart->SelectedIndex > cbRestTimeEnd->SelectedIndex) { MessageBox::Show("\'종료 시간\'은 \'시작 시간\'보다 나중이어야 합니다"); return; }

			auto day = ToStdString(cbRestTimeDay->Text);
			auto start = util::Split(ToStdString(cbRestTimeStart->Text), util::SplitType::Except, regex(R"(:)"));
			auto end = util::Split(ToStdString(cbRestTimeEnd->Text), util::SplitType::Except, regex(R"(:)"));

			mRestTimeList->push_back(Course::LectureTime({ day, stoi(start[0]) * 60 + stoi(start[1]),  stoi(end[0]) * 60 + stoi(end[1]) }));
			gvRestTimeList->Rows->Add(gvRestTimeList->Rows->Count, cbRestTimeDay->Text + ", " + cbRestTimeStart->Text + "~" + cbRestTimeEnd->Text);
		}



	private:   // 시간 공강을 제거하는 이벤트
		System::Void gvRestTimeList_RowHeaderMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
			int idx = e->RowIndex;

			// mSelectedCourseInfoList의 idx번째 과목 삭제	
			mRestTimeList->erase(mRestTimeList->begin() + idx);

			// gvSelectedCourse의 idx번째 과목 삭제하고 넘버링을 다시 한다
			gvRestTimeList->Rows->RemoveAt(idx);
			for (int i = 0; i < gvRestTimeList->Rows->Count; i++)
				gvRestTimeList->Rows[i]->Cells[0]->Value = i;
		}



	private:   // gvRestTimeList에서 scroll의 유무에 따라 1번 column의 너비를 변경해야 한다
		System::Void gvRestTimeList_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
			if (gvRestTimeList->Rows->Count > 5)
				gvRestTimeList->Columns[1]->Width = 358;
		}
		
		System::Void gvRestTimeList_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e) {
			if (gvRestTimeList->Rows->Count < 6)
				gvRestTimeList->Columns[1]->Width = 375;
		}



	private: // 현재의 세팅을 저장하고 시간표 생성하는 이벤트

		System::Boolean IsConflictWithRest(Course& course) {   // 선택한 course가 공강 요일 또는 공강 시간과 겹치는지 확인
			for (auto& lectureTime : course.times) {
				if (mRestDaySet->find(lectureTime.day) != mRestDaySet->end()) return true;   // course의 강의 요일이 공강 요일인 경우

				for (auto& restTime : *mRestTimeList)
					if (lectureTime.day == restTime.day && (lectureTime.start < restTime.end && lectureTime.end > restTime.start)) return true;   // course의 강의 시간이 공강 시간인 경우
			}
			return false;
		}


		System::Void btCallGenerator_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

			auto targetCredit = stoi(ToStdString(cbTargetCredit->Text));
			if (!(targetCredit > 0)) { MessageBox::Show("목표 학점을 1이상으로 설정하세요"); return; }

			auto numberOfEssentialCourse = 0;
			auto numberOfNoramlCourse = 0;
			auto courseInfoList = vector<pair<Course, int>>(1);

			for (auto& [lank, course] : *mSelectedCourseInfoList) {
				if (IsConflictWithRest(course)) continue;   // 공강 요일/시간 확인

				lank == 0 ? ++numberOfEssentialCourse : ++numberOfNoramlCourse;
				courseInfoList.push_back({ course, lank });
			}

			auto timeTabForm = gcnew TimeTabForm(targetCredit, numberOfEssentialCourse, numberOfNoramlCourse, courseInfoList);
			timeTabForm->Show();
		}	
	};
}
