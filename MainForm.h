#pragma once

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
	/// ���� Form: ������ ���� ����Ʈ���� ���ϴ� ������ �����ϰ� �켱������ �ο�
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void) { InitializeComponent(); }

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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SelectList_Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SelectList_Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SelectList_Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SelectList_Column4;
	private: System::Windows::Forms::Label^ lbIdxSelect;
	private: System::Windows::Forms::Label^ lbIDSelect;


	private: System::Windows::Forms::TextBox^ tbIdxSelect;
	private: System::Windows::Forms::Button^ btIdxSelect;
	private: System::Windows::Forms::TextBox^ tbIDSelect;
	private: System::Windows::Forms::Button^ btIDSelect;








	protected:

	protected:

	private:
		/// <summary>
		/// �ʼ� �����̳� ����
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼���
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
			this->SelectList_Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SelectList_Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SelectList_Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SelectList_Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cbTargetCredit = (gcnew System::Windows::Forms::ComboBox());
			this->lbTargetCredit = (gcnew System::Windows::Forms::Label());
			this->lbIdxSelect = (gcnew System::Windows::Forms::Label());
			this->lbIDSelect = (gcnew System::Windows::Forms::Label());
			this->tbIdxSelect = (gcnew System::Windows::Forms::TextBox());
			this->btIdxSelect = (gcnew System::Windows::Forms::Button());
			this->tbIDSelect = (gcnew System::Windows::Forms::TextBox());
			this->btIDSelect = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvCourseList))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvSelectCourse))->BeginInit();
			this->SuspendLayout();
			// 
			// btCallGenerator
			// 
			this->btCallGenerator->Font = (gcnew System::Drawing::Font(L"����", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->btCallGenerator->Location = System::Drawing::Point(922, 12);
			this->btCallGenerator->Name = L"btCallGenerator";
			this->btCallGenerator->Size = System::Drawing::Size(453, 51);
			this->btCallGenerator->TabIndex = 1;
			this->btCallGenerator->Text = L"�ð�ǥ ����";
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
			this->gvCourseList->Location = System::Drawing::Point(12, 68);
			this->gvCourseList->MultiSelect = false;
			this->gvCourseList->Name = L"gvCourseList";
			this->gvCourseList->ReadOnly = true;
			this->gvCourseList->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->gvCourseList->RowTemplate->Height = 23;
			this->gvCourseList->Size = System::Drawing::Size(895, 570);
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
			this->Column1->HeaderText = L"��������";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"�м���ȣ";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"�������";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"����";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"��米��";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"���ǽð�1";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"���ǽð�2";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"���ǽð�3";
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
				this->SelectList_Column1,
					this->SelectList_Column2, this->SelectList_Column3, this->SelectList_Column4
			});
			this->gvSelectCourse->Location = System::Drawing::Point(922, 99);
			this->gvSelectCourse->MultiSelect = false;
			this->gvSelectCourse->Name = L"gvSelectCourse";
			this->gvSelectCourse->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->gvSelectCourse->RowTemplate->Height = 23;
			this->gvSelectCourse->Size = System::Drawing::Size(453, 539);
			this->gvSelectCourse->TabIndex = 3;
			this->gvSelectCourse->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::gvSelectCourse_CellValueChanged);
			this->gvSelectCourse->RowHeaderMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainForm::gvSelectCourse_RowHeaderMouseDoubleClick);
			this->gvSelectCourse->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &MainForm::gvSelectCourse_RowsAdded);
			this->gvSelectCourse->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &MainForm::gvSelectCourse_RowsRemoved);
			this->gvSelectCourse->Sorted += gcnew System::EventHandler(this, &MainForm::gvSelectCourse_Sorted);
			// 
			// SelectList_Column1
			// 
			this->SelectList_Column1->HeaderText = L"Idx";
			this->SelectList_Column1->Name = L"SelectList_Column1";
			this->SelectList_Column1->ReadOnly = true;
			this->SelectList_Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->SelectList_Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->SelectList_Column1->Width = 35;
			// 
			// SelectList_Column2
			// 
			this->SelectList_Column2->HeaderText = L"�м���ȣ";
			this->SelectList_Column2->Name = L"SelectList_Column2";
			this->SelectList_Column2->ReadOnly = true;
			this->SelectList_Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// SelectList_Column3
			// 
			this->SelectList_Column3->HeaderText = L"�������";
			this->SelectList_Column3->Name = L"SelectList_Column3";
			this->SelectList_Column3->ReadOnly = true;
			this->SelectList_Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// SelectList_Column4
			// 
			this->SelectList_Column4->HeaderText = L"��米��";
			this->SelectList_Column4->Name = L"SelectList_Column4";
			this->SelectList_Column4->ReadOnly = true;
			this->SelectList_Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// cbTargetCredit
			// 
			this->cbTargetCredit->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbTargetCredit->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->cbTargetCredit->FormattingEnabled = true;
			this->cbTargetCredit->Items->AddRange(gcnew cli::array< System::Object^  >(25) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24"
			});
			this->cbTargetCredit->Location = System::Drawing::Point(1120, 68);
			this->cbTargetCredit->Name = L"cbTargetCredit";
			this->cbTargetCredit->Size = System::Drawing::Size(213, 24);
			this->cbTargetCredit->TabIndex = 4;
			// 
			// lbTargetCredit
			// 
			this->lbTargetCredit->AutoSize = true;
			this->lbTargetCredit->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbTargetCredit->Location = System::Drawing::Point(979, 73);
			this->lbTargetCredit->Name = L"lbTargetCredit";
			this->lbTargetCredit->Size = System::Drawing::Size(113, 16);
			this->lbTargetCredit->TabIndex = 5;
			this->lbTargetCredit->Text = L"��ǥ ���� ����";
			// 
			// lbIdxSelect
			// 
			this->lbIdxSelect->AutoSize = true;
			this->lbIdxSelect->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbIdxSelect->Location = System::Drawing::Point(55, 28);
			this->lbIdxSelect->Name = L"lbIdxSelect";
			this->lbIdxSelect->Size = System::Drawing::Size(118, 16);
			this->lbIdxSelect->TabIndex = 6;
			this->lbIdxSelect->Text = L"Idx�� ���� ����";
			// 
			// lbIDSelect
			// 
			this->lbIDSelect->AutoSize = true;
			this->lbIDSelect->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbIDSelect->Location = System::Drawing::Point(452, 28);
			this->lbIDSelect->Name = L"lbIDSelect";
			this->lbIDSelect->Size = System::Drawing::Size(161, 16);
			this->lbIDSelect->TabIndex = 7;
			this->lbIDSelect->Text = L"�м���ȣ�� ���� ����";
			// 
			// tbIdxSelect
			// 
			this->tbIdxSelect->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbIdxSelect->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbIdxSelect->Location = System::Drawing::Point(179, 23);
			this->tbIdxSelect->Name = L"tbIdxSelect";
			this->tbIdxSelect->Size = System::Drawing::Size(145, 26);
			this->tbIdxSelect->TabIndex = 8;
			this->tbIdxSelect->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::tbIdxSelect_KeyPress);
			// 
			// btIdxSelect
			// 
			this->btIdxSelect->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->btIdxSelect->Location = System::Drawing::Point(330, 21);
			this->btIdxSelect->Name = L"btIdxSelect";
			this->btIdxSelect->Size = System::Drawing::Size(80, 30);
			this->btIdxSelect->TabIndex = 9;
			this->btIdxSelect->Text = L"�߰�";
			this->btIdxSelect->UseVisualStyleBackColor = true;
			this->btIdxSelect->Click += gcnew System::EventHandler(this, &MainForm::btIdxSelect_Click);
			// 
			// tbIDSelect
			// 
			this->tbIDSelect->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbIDSelect->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbIDSelect->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbIDSelect->Location = System::Drawing::Point(619, 23);
			this->tbIDSelect->Name = L"tbIDSelect";
			this->tbIDSelect->ReadOnly = true;
			this->tbIDSelect->Size = System::Drawing::Size(145, 26);
			this->tbIDSelect->TabIndex = 10;
			this->tbIDSelect->Text = L"�̱���";
			// 
			// btIDSelect
			// 
			this->btIDSelect->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->btIDSelect->Location = System::Drawing::Point(770, 21);
			this->btIDSelect->Name = L"btIDSelect";
			this->btIDSelect->Size = System::Drawing::Size(80, 30);
			this->btIDSelect->TabIndex = 11;
			this->btIDSelect->Text = L"�߰�";
			this->btIDSelect->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1390, 651);
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
			this->Text = L"�ð�ǥ ������";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvCourseList))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gvSelectCourse))->EndInit();
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
		List<bool>^ isSelectedCourse;



	private: // ���� �� �ʱ�ȭ
		bool isInitializing = true;
		System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			Init_gvCourseList();
			Init_gvSelectCourse();
			Init_cbTargetCredit();
			isInitializing = false;
		}

		System::Void Init_gvCourseList() {
			isSelectedCourse = gcnew List<bool>();
			for (auto& course : CourseManager::Load_CourseList()) {
				gvCourseList->Rows->Add(
					gvCourseList->Rows->Count.ToString(),
					ToGcString(course.curriculum),
					ToGcString(course.id.format()),
					ToGcString(course.name),
					ToGcString(course.credit),
					ToGcString(course.professor),
					course.times.size() > 0 ? ToGcString(course.times[0].format()) : ToGcString(string()),
					course.times.size() > 1 ? ToGcString(course.times[1].format()) : ToGcString(string()),
					course.times.size() > 2 ? ToGcString(course.times[2].format()) : ToGcString(string())
				);
				isSelectedCourse->Add(false);
			}
		}

		System::Void Init_gvSelectCourse() {
			DataGridViewComboBoxColumn^ cbColumn = gcnew DataGridViewComboBoxColumn();
			cbColumn->Width = 75;
			cbColumn->HeaderText = "�켱����";
			cbColumn->DisplayStyle = DataGridViewComboBoxDisplayStyle::ComboBox;
			cbColumn->Items->Add("0�ʼ�");
			cbColumn->Items->Add("1����");
			cbColumn->Items->Add("2����");
			cbColumn->Items->Add("3����");
			cbColumn->Items->Add("4����");
			cbColumn->Items->Add("5����");
			gvSelectCourse->Columns->Add(cbColumn);
		}

		System::Void Init_cbTargetCredit() {
			cbTargetCredit->SelectedIndex = 0;
		}



	private: // gvCourseList���� ������ �����ϴ� �̺�Ʈ
		System::Void Select_Form_CourseList(int cListIdx) {	// courseList���� ������ ������ selectCourse�� �߰�
			if (isSelectedCourse[cListIdx]) { MessageBox::Show("�̹� ������ �����Դϴ�"); return; }

			isSelectedCourse[cListIdx] = true;
			int sListIdx = gvSelectCourse->Rows->Add(
				cListIdx.ToString(),
				gvCourseList->Rows[cListIdx]->Cells[2]->Value,
				gvCourseList->Rows[cListIdx]->Cells[3]->Value,
				gvCourseList->Rows[cListIdx]->Cells[5]->Value
			);
			DataGridViewComboBoxCell^ cbCell = (DataGridViewComboBoxCell^)(gvSelectCourse->Rows[sListIdx]->Cells[4]);
			cbCell->Value = cbCell->Items[5]->ToString();
		}

		System::Void gridView_courseList_RowHeaderMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {	// ���� Ŭ��
			Select_Form_CourseList(e->RowIndex);
		}

		System::Void btIdxSelect_Click(System::Object^ sender, System::EventArgs^ e) {	// Idx �Է� �� ��ư
			int cListIdx = -1;
			if (int::TryParse(tbIdxSelect->Text, cListIdx) && (0 <= cListIdx && cListIdx < gvCourseList->Rows->Count)) Select_Form_CourseList(cListIdx);
			else if (cListIdx >= gvCourseList->Rows->Count) MessageBox::Show("Idx �ִ밪�� " + gvCourseList->Rows->Count.ToString() + "�Դϴ�");
			else MessageBox::Show("\"" + tbIdxSelect->Text + "\"��(��) " + "�ڿ����� ��ȯ�� �� �����ϴ�");
		}

		System::Void tbIdxSelect_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {	// Idx �Է� �� enterŰ
			if (e->KeyChar == (char)Keys::Enter) {
				int cListIdx = -1;
				if (int::TryParse(tbIdxSelect->Text, cListIdx) && (0 <= cListIdx && cListIdx < gvCourseList->Rows->Count)) Select_Form_CourseList(cListIdx);
				else if (cListIdx >= gvCourseList->Rows->Count) MessageBox::Show("Idx �ִ밪�� " + gvCourseList->Rows->Count.ToString() + "�Դϴ�");
				else MessageBox::Show("\"" + tbIdxSelect->Text + "\"��(��) " + "�ڿ����� ��ȯ�� �� �����ϴ�");
			}
		}



	private: // gvSelectCourse���� ������ ������ �����ϴ� �̺�Ʈ
		System::Void gvSelectCourse_RowHeaderMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
			int sListIdx = e->RowIndex;
			isSelectedCourse[int::Parse(gvSelectCourse->Rows[sListIdx]->Cells[0]->Value->ToString())] = false;
			gvSelectCourse->Rows->RemoveAt(sListIdx);
		}



	private: // gvSelectCourse���� ������ �켱������ �������� ��, �߻��ϴ� ���� �̺�Ʈ
		bool isEnd_CellStateChangedEvent = true;
		System::Void gvSelectCourse_Sorted(System::Object^ sender, System::EventArgs^ e) {
			if (isInitializing) return;
			isEnd_CellStateChangedEvent = true;
		}

		System::Void gvSelectCourse_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (isInitializing) return;
			if (isEnd_CellStateChangedEvent) gvSelectCourse->Sort(gvSelectCourse->Columns[4], ListSortDirection::Ascending);
			else isEnd_CellStateChangedEvent = false;
		}



	private: // ������ ������ �����ϰ� �ð�ǥ �����ϴ� �̺�Ʈ
		System::Void btCallGenerator_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

			auto targetCredit = stoi(ToStdString(cbTargetCredit->Text));
			if (!(targetCredit > 0)) { MessageBox::Show("��ǥ ������ 1�̻����� �����ϼ���"); return; }

			auto allCourseList = CourseManager::Load_CourseList();
			auto essCourseList = vector<Course>(1);
			auto nomCourseList = vector<Course>(1);
			auto nomCourseLank = vector<int>(1);

			for (int i = 0; i < gvSelectCourse->RowCount; i++) {
				int cosLank = ToStdString(gvSelectCourse->Rows[i]->Cells[4]->Value->ToString())[0] - 48;
				int cosNum = stoi(ToStdString(gvSelectCourse->Rows[i]->Cells[0]->Value->ToString()));

				if (cosLank == 0) {
					targetCredit -= allCourseList[cosNum].credit;
					essCourseList.push_back(allCourseList[cosNum]);
				}
				else if (cosLank > 0) {
					nomCourseList.push_back(allCourseList[cosNum]);
					nomCourseLank.push_back(cosLank);
				}
			}

			auto timeTabForm = gcnew TimeTabForm(targetCredit, essCourseList, nomCourseList, nomCourseLank);
			timeTabForm->Show();
		}



	private: // gvSelectCourse���� scroll�� ������ ���� 3�� column�� �ʺ� �����ؾ� �Ѵ�
		System::Void gvSelectCourse_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
			if (gvSelectCourse->Rows->Count > 22) 
				gvSelectCourse->Columns[3]->Width = 82;
		}

		System::Void gvSelectCourse_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e) {
			if (gvSelectCourse->Rows->Count < 23)
				gvSelectCourse->Columns[3]->Width = 100;
		}
	};
}
