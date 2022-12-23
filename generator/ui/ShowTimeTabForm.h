
#pragma once
#include "./../../core/C++Header_STL.h"
#include "./../../core/Course.h"


namespace TimeTableGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// 시간표를 시각화하여 보여준다
	/// </summary>
	public ref class ShowTimeTabForm : public System::Windows::Forms::Form
	{
	public:
		ShowTimeTabForm() { InitializeComponent(); }
		ShowTimeTabForm(vector<Course>& courseList) 
		{
			InitializeComponent();
			InitialzerMembers(courseList);
		}

	protected:
		~ShowTimeTabForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ gvTimeTable;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ day0;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ day1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ day2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ day3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ day4;

	private:
		/// <summary>
		/// 필수 디자이너 변수
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->gvTimeTable = (gcnew System::Windows::Forms::DataGridView());
			this->time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->day0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->day1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->day2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->day3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->day4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvTimeTable))->BeginInit();
			this->SuspendLayout();
			// 
			// gvTimeTable
			// 
			this->gvTimeTable->AllowUserToAddRows = false;
			this->gvTimeTable->AllowUserToDeleteRows = false;
			this->gvTimeTable->AllowUserToResizeColumns = false;
			this->gvTimeTable->AllowUserToResizeRows = false;
			this->gvTimeTable->CausesValidation = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"나눔스퀘어", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->gvTimeTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->gvTimeTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->gvTimeTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->time, this->day0,
					this->day1, this->day2, this->day3, this->day4
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"나눔스퀘어 Bold", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::Transparent;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->gvTimeTable->DefaultCellStyle = dataGridViewCellStyle2;
			this->gvTimeTable->Location = System::Drawing::Point(12, 12);
			this->gvTimeTable->MultiSelect = false;
			this->gvTimeTable->Name = L"gvTimeTable";
			this->gvTimeTable->ReadOnly = true;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->gvTimeTable->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->gvTimeTable->RowHeadersVisible = false;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"나눔스퀘어 Bold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->gvTimeTable->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->gvTimeTable->RowTemplate->Height = 35;
			this->gvTimeTable->Size = System::Drawing::Size(555, 860);
			this->gvTimeTable->TabIndex = 0;
			this->gvTimeTable->TabStop = false;
			// 
			// time
			// 
			this->time->HeaderText = L"";
			this->time->Name = L"time";
			this->time->ReadOnly = true;
			this->time->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->time->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->time->Width = 35;
			// 
			// day0
			// 
			this->day0->HeaderText = L"월";
			this->day0->Name = L"day0";
			this->day0->ReadOnly = true;
			this->day0->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->day0->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// day1
			// 
			this->day1->HeaderText = L"화";
			this->day1->Name = L"day1";
			this->day1->ReadOnly = true;
			this->day1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->day1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// day2
			// 
			this->day2->HeaderText = L"수";
			this->day2->Name = L"day2";
			this->day2->ReadOnly = true;
			this->day2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->day2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// day3
			// 
			this->day3->HeaderText = L"목";
			this->day3->Name = L"day3";
			this->day3->ReadOnly = true;
			this->day3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->day3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// day4
			// 
			this->day4->HeaderText = L"금";
			this->day4->Name = L"day4";
			this->day4->ReadOnly = true;
			this->day4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->day4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// ShowTimeTabForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 886);
			this->Controls->Add(this->gvTimeTable);
			this->Name = L"ShowTimeTabForm";
			this->Text = L"시간표";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvTimeTable))->EndInit();
			this->ResumeLayout(false);

		}



	private:
		String^ ToGcString(string& stdString) { return gcnew String(stdString.data()); }
		string ToStdString(String^ gcString) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(gcString)).ToPointer();
			string stdString = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			return stdString;
		}

#pragma endregion

	private:
		System::Int32 DayToColumn(string &day) {	// 강의 요일을 시간표의 column인덱스로 변환
			if (day == "월") return 1;
			if (day == "화") return 2;
			if (day == "수") return 3;
			if (day == "목") return 4;
			if (day == "금") return 5;
			return -1;
		}

		System::Int32 TimeToRow(int time) {	// 강의 시간을 시간표의 row인덱스로 변환
			int hour = time / 60;
			int minute = time % 60;
			return (hour - 8) * 2 + (minute == 0 ? 0 : 1);
		}

		Color CouseNumToColor(int courseNum) {	// 강의를 나타내는 블록의 색을 결정
			courseNum %= 9;
			if (courseNum == 0) return Color::FromArgb(240, 134, 118);
			if (courseNum == 1) return Color::FromArgb(251, 170, 104);
			if (courseNum == 2) return Color::FromArgb(236, 195, 105);
			if (courseNum == 3) return Color::FromArgb(167, 202, 112);
			if (courseNum == 4) return Color::FromArgb(125, 209, 193);
			if (courseNum == 5) return Color::FromArgb(120, 202, 136);
			if (courseNum == 6) return Color::FromArgb(122, 165, 233);
			if (courseNum == 7) return Color::FromArgb(159, 134, 225);
			if (courseNum == 8) return Color::FromArgb(211, 151, 237);
			return Color::Moccasin;
		}

		System::Void InitialzerMembers(vector<Course> &courseList) {
			for (int i = 8, rowIdx; i <= 23; i++) {
				rowIdx = gvTimeTable->Rows->Add(i.ToString());
				gvTimeTable->Rows[rowIdx]->Cells[0]->Style->ForeColor = Color::Black;
				gvTimeTable->Rows[rowIdx]->Cells[0]->Style->SelectionForeColor = Color::Black;
				gvTimeTable->Rows[rowIdx]->Cells[0]->Style->Alignment = DataGridViewContentAlignment::TopRight;

				rowIdx = gvTimeTable->Rows->Add();
				gvTimeTable->Rows[rowIdx]->Cells[0]->Style->ForeColor = Color::Black;
				gvTimeTable->Rows[rowIdx]->Cells[0]->Style->SelectionForeColor = Color::Black;
				gvTimeTable->Rows[rowIdx]->Cells[0]->Style->Alignment = DataGridViewContentAlignment::TopRight;
			}

			int colorIdx = 0;
			for (auto& course : courseList) {
				for (auto& time : course.times) 
				{
					int day = DayToColumn(time.day);
					int start = TimeToRow(time.start);
					int end = TimeToRow(time.end);

					for (int i = start; i < end; i++) {
						if (i == start) gvTimeTable->Rows[i]->Cells[day]->Value = ToGcString(course.name);
						else if (i == start + 1)gvTimeTable->Rows[i]->Cells[day]->Value = ToGcString(course.professor);
						gvTimeTable->Rows[i]->Cells[day]->Style->BackColor = CouseNumToColor(colorIdx);
					}
				}
				if (colorIdx < 11) colorIdx++;
			}
		}
	};
}