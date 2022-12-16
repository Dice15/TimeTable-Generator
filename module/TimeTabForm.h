#pragma once

#include "./../core/Course.h"
#include "./TimeTabGenerator.h"
#include "./ShowTimeTabForm.h"

namespace TimeTableGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	enum PageMove { Prev = -1, Hold = 0, Next = 1 };

	/// <summary>
	/// TimeTabForm에 대한 요약입니다.
	/// </summary>
	public ref class TimeTabForm : public System::Windows::Forms::Form
	{
	public:
		TimeTabForm() { InitializeComponent(); }
		TimeTabForm(int targetCredit, vector<Course>& essnCourseList, vector<Course>& normCourseList, vector<int>& nomCourseLank)
		{
			isInitializing = true;
			InitializeComponent();
			InitialzerMembers(targetCredit, essnCourseList, normCourseList, nomCourseLank);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~TimeTabForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btPrev;
	private: System::Windows::Forms::Button^ btNext;

	private: System::Windows::Forms::TextBox^ tbPageNum;
	private: System::Windows::Forms::TextBox^ tbTimeTab0;
	private: System::Windows::Forms::TextBox^ tbTimeTab1;
	private: System::Windows::Forms::TextBox^ tbTimeTab2;
	private: System::Windows::Forms::TextBox^ tbTimeTab3;
	private: System::Windows::Forms::TextBox^ tbTimeTab4;
	private: System::Windows::Forms::TextBox^ tbColumn0;
	private: System::Windows::Forms::TextBox^ tbColumn1;
	private: System::Windows::Forms::TextBox^ tbColumn2;
	private: System::Windows::Forms::TextBox^ tbColumn3;
	private: System::Windows::Forms::TextBox^ tbColumn4;
	private: System::Windows::Forms::TextBox^ tbLankCntL0;
	private: System::Windows::Forms::TextBox^ tbLankCntR0;
	private: System::Windows::Forms::TextBox^ tbLankCntR1;



	private: System::Windows::Forms::TextBox^ tbLankCntL1;
	private: System::Windows::Forms::TextBox^ tbLankCntR3;







	private: System::Windows::Forms::TextBox^ tbLankCntL3;
	private: System::Windows::Forms::TextBox^ tbLankCntR2;






	private: System::Windows::Forms::TextBox^ tbLankCntL2;
	private: System::Windows::Forms::TextBox^ tbLankCntR4;



	private: System::Windows::Forms::TextBox^ tbLankCntL4;
	private: System::Windows::Forms::Button^ btShowTimeTab0;
	private: System::Windows::Forms::Button^ btShowTimeTab1;
	private: System::Windows::Forms::Button^ btShowTimeTab2;
	private: System::Windows::Forms::Button^ btShowTimeTab3;
	private: System::Windows::Forms::Button^ btShowTimeTab4;






	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btPrev = (gcnew System::Windows::Forms::Button());
			this->btNext = (gcnew System::Windows::Forms::Button());
			this->tbPageNum = (gcnew System::Windows::Forms::TextBox());
			this->tbTimeTab0 = (gcnew System::Windows::Forms::TextBox());
			this->tbTimeTab1 = (gcnew System::Windows::Forms::TextBox());
			this->tbTimeTab2 = (gcnew System::Windows::Forms::TextBox());
			this->tbTimeTab3 = (gcnew System::Windows::Forms::TextBox());
			this->tbTimeTab4 = (gcnew System::Windows::Forms::TextBox());
			this->tbColumn0 = (gcnew System::Windows::Forms::TextBox());
			this->tbColumn1 = (gcnew System::Windows::Forms::TextBox());
			this->tbColumn2 = (gcnew System::Windows::Forms::TextBox());
			this->tbColumn3 = (gcnew System::Windows::Forms::TextBox());
			this->tbColumn4 = (gcnew System::Windows::Forms::TextBox());
			this->tbLankCntL0 = (gcnew System::Windows::Forms::TextBox());
			this->tbLankCntR0 = (gcnew System::Windows::Forms::TextBox());
			this->tbLankCntR1 = (gcnew System::Windows::Forms::TextBox());
			this->tbLankCntL1 = (gcnew System::Windows::Forms::TextBox());
			this->tbLankCntR3 = (gcnew System::Windows::Forms::TextBox());
			this->tbLankCntL3 = (gcnew System::Windows::Forms::TextBox());
			this->tbLankCntR2 = (gcnew System::Windows::Forms::TextBox());
			this->tbLankCntL2 = (gcnew System::Windows::Forms::TextBox());
			this->tbLankCntR4 = (gcnew System::Windows::Forms::TextBox());
			this->tbLankCntL4 = (gcnew System::Windows::Forms::TextBox());
			this->btShowTimeTab0 = (gcnew System::Windows::Forms::Button());
			this->btShowTimeTab1 = (gcnew System::Windows::Forms::Button());
			this->btShowTimeTab2 = (gcnew System::Windows::Forms::Button());
			this->btShowTimeTab3 = (gcnew System::Windows::Forms::Button());
			this->btShowTimeTab4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btPrev
			// 
			this->btPrev->Location = System::Drawing::Point(547, 608);
			this->btPrev->Name = L"btPrev";
			this->btPrev->Size = System::Drawing::Size(65, 41);
			this->btPrev->TabIndex = 1;
			this->btPrev->Text = L"이전";
			this->btPrev->UseVisualStyleBackColor = true;
			this->btPrev->Click += gcnew System::EventHandler(this, &TimeTabForm::btPrev_Click);
			// 
			// btNext
			// 
			this->btNext->Location = System::Drawing::Point(695, 608);
			this->btNext->Name = L"btNext";
			this->btNext->Size = System::Drawing::Size(65, 41);
			this->btNext->TabIndex = 2;
			this->btNext->Text = L"다음";
			this->btNext->UseVisualStyleBackColor = true;
			this->btNext->Click += gcnew System::EventHandler(this, &TimeTabForm::btNext_Click);
			// 
			// tbPageNum
			// 
			this->tbPageNum->BackColor = System::Drawing::SystemColors::Control;
			this->tbPageNum->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPageNum->Location = System::Drawing::Point(618, 623);
			this->tbPageNum->Name = L"tbPageNum";
			this->tbPageNum->ReadOnly = true;
			this->tbPageNum->Size = System::Drawing::Size(71, 14);
			this->tbPageNum->TabIndex = 4;
			this->tbPageNum->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbTimeTab0
			// 
			this->tbTimeTab0->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbTimeTab0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbTimeTab0->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbTimeTab0->Location = System::Drawing::Point(16, 57);
			this->tbTimeTab0->Multiline = true;
			this->tbTimeTab0->Name = L"tbTimeTab0";
			this->tbTimeTab0->ReadOnly = true;
			this->tbTimeTab0->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbTimeTab0->Size = System::Drawing::Size(250, 420);
			this->tbTimeTab0->TabIndex = 10;
			this->tbTimeTab0->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbTimeTab1
			// 
			this->tbTimeTab1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbTimeTab1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbTimeTab1->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbTimeTab1->Location = System::Drawing::Point(272, 57);
			this->tbTimeTab1->Multiline = true;
			this->tbTimeTab1->Name = L"tbTimeTab1";
			this->tbTimeTab1->ReadOnly = true;
			this->tbTimeTab1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbTimeTab1->Size = System::Drawing::Size(250, 420);
			this->tbTimeTab1->TabIndex = 11;
			this->tbTimeTab1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbTimeTab2
			// 
			this->tbTimeTab2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbTimeTab2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbTimeTab2->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbTimeTab2->Location = System::Drawing::Point(528, 57);
			this->tbTimeTab2->Multiline = true;
			this->tbTimeTab2->Name = L"tbTimeTab2";
			this->tbTimeTab2->ReadOnly = true;
			this->tbTimeTab2->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbTimeTab2->Size = System::Drawing::Size(250, 420);
			this->tbTimeTab2->TabIndex = 12;
			this->tbTimeTab2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbTimeTab3
			// 
			this->tbTimeTab3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbTimeTab3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbTimeTab3->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbTimeTab3->Location = System::Drawing::Point(784, 57);
			this->tbTimeTab3->Multiline = true;
			this->tbTimeTab3->Name = L"tbTimeTab3";
			this->tbTimeTab3->ReadOnly = true;
			this->tbTimeTab3->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbTimeTab3->Size = System::Drawing::Size(250, 420);
			this->tbTimeTab3->TabIndex = 13;
			this->tbTimeTab3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbTimeTab4
			// 
			this->tbTimeTab4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbTimeTab4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbTimeTab4->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbTimeTab4->Location = System::Drawing::Point(1040, 57);
			this->tbTimeTab4->Multiline = true;
			this->tbTimeTab4->Name = L"tbTimeTab4";
			this->tbTimeTab4->ReadOnly = true;
			this->tbTimeTab4->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbTimeTab4->Size = System::Drawing::Size(250, 420);
			this->tbTimeTab4->TabIndex = 14;
			this->tbTimeTab4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbColumn0
			// 
			this->tbColumn0->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbColumn0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbColumn0->Font = (gcnew System::Drawing::Font(L"굴림", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbColumn0->Location = System::Drawing::Point(16, 23);
			this->tbColumn0->Multiline = true;
			this->tbColumn0->Name = L"tbColumn0";
			this->tbColumn0->ReadOnly = true;
			this->tbColumn0->Size = System::Drawing::Size(250, 28);
			this->tbColumn0->TabIndex = 15;
			this->tbColumn0->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbColumn1
			// 
			this->tbColumn1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbColumn1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbColumn1->Font = (gcnew System::Drawing::Font(L"굴림", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbColumn1->Location = System::Drawing::Point(272, 23);
			this->tbColumn1->Multiline = true;
			this->tbColumn1->Name = L"tbColumn1";
			this->tbColumn1->ReadOnly = true;
			this->tbColumn1->Size = System::Drawing::Size(250, 28);
			this->tbColumn1->TabIndex = 16;
			this->tbColumn1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbColumn2
			// 
			this->tbColumn2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbColumn2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbColumn2->Font = (gcnew System::Drawing::Font(L"굴림", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbColumn2->Location = System::Drawing::Point(528, 23);
			this->tbColumn2->Multiline = true;
			this->tbColumn2->Name = L"tbColumn2";
			this->tbColumn2->ReadOnly = true;
			this->tbColumn2->Size = System::Drawing::Size(250, 28);
			this->tbColumn2->TabIndex = 17;
			this->tbColumn2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbColumn3
			// 
			this->tbColumn3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbColumn3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbColumn3->Font = (gcnew System::Drawing::Font(L"굴림", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbColumn3->Location = System::Drawing::Point(784, 23);
			this->tbColumn3->Multiline = true;
			this->tbColumn3->Name = L"tbColumn3";
			this->tbColumn3->ReadOnly = true;
			this->tbColumn3->Size = System::Drawing::Size(250, 28);
			this->tbColumn3->TabIndex = 18;
			this->tbColumn3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbColumn4
			// 
			this->tbColumn4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbColumn4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbColumn4->Font = (gcnew System::Drawing::Font(L"굴림", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbColumn4->Location = System::Drawing::Point(1040, 23);
			this->tbColumn4->Multiline = true;
			this->tbColumn4->Name = L"tbColumn4";
			this->tbColumn4->ReadOnly = true;
			this->tbColumn4->Size = System::Drawing::Size(250, 28);
			this->tbColumn4->TabIndex = 19;
			this->tbColumn4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbLankCntL0
			// 
			this->tbLankCntL0->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbLankCntL0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbLankCntL0->Font = (gcnew System::Drawing::Font(L"굴림", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbLankCntL0->Location = System::Drawing::Point(16, 476);
			this->tbLankCntL0->Multiline = true;
			this->tbLankCntL0->Name = L"tbLankCntL0";
			this->tbLankCntL0->ReadOnly = true;
			this->tbLankCntL0->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbLankCntL0->Size = System::Drawing::Size(126, 75);
			this->tbLankCntL0->TabIndex = 20;
			this->tbLankCntL0->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbLankCntR0
			// 
			this->tbLankCntR0->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbLankCntR0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbLankCntR0->Font = (gcnew System::Drawing::Font(L"굴림", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbLankCntR0->Location = System::Drawing::Point(140, 476);
			this->tbLankCntR0->Multiline = true;
			this->tbLankCntR0->Name = L"tbLankCntR0";
			this->tbLankCntR0->ReadOnly = true;
			this->tbLankCntR0->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbLankCntR0->Size = System::Drawing::Size(126, 75);
			this->tbLankCntR0->TabIndex = 21;
			this->tbLankCntR0->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbLankCntR1
			// 
			this->tbLankCntR1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbLankCntR1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbLankCntR1->Font = (gcnew System::Drawing::Font(L"굴림", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbLankCntR1->Location = System::Drawing::Point(396, 476);
			this->tbLankCntR1->Multiline = true;
			this->tbLankCntR1->Name = L"tbLankCntR1";
			this->tbLankCntR1->ReadOnly = true;
			this->tbLankCntR1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbLankCntR1->Size = System::Drawing::Size(126, 75);
			this->tbLankCntR1->TabIndex = 23;
			this->tbLankCntR1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbLankCntL1
			// 
			this->tbLankCntL1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbLankCntL1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbLankCntL1->Font = (gcnew System::Drawing::Font(L"굴림", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbLankCntL1->Location = System::Drawing::Point(272, 476);
			this->tbLankCntL1->Multiline = true;
			this->tbLankCntL1->Name = L"tbLankCntL1";
			this->tbLankCntL1->ReadOnly = true;
			this->tbLankCntL1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbLankCntL1->Size = System::Drawing::Size(126, 75);
			this->tbLankCntL1->TabIndex = 22;
			this->tbLankCntL1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbLankCntR3
			// 
			this->tbLankCntR3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbLankCntR3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbLankCntR3->Font = (gcnew System::Drawing::Font(L"굴림", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbLankCntR3->Location = System::Drawing::Point(908, 476);
			this->tbLankCntR3->Multiline = true;
			this->tbLankCntR3->Name = L"tbLankCntR3";
			this->tbLankCntR3->ReadOnly = true;
			this->tbLankCntR3->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbLankCntR3->Size = System::Drawing::Size(126, 75);
			this->tbLankCntR3->TabIndex = 27;
			this->tbLankCntR3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbLankCntL3
			// 
			this->tbLankCntL3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbLankCntL3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbLankCntL3->Font = (gcnew System::Drawing::Font(L"굴림", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbLankCntL3->Location = System::Drawing::Point(784, 476);
			this->tbLankCntL3->Multiline = true;
			this->tbLankCntL3->Name = L"tbLankCntL3";
			this->tbLankCntL3->ReadOnly = true;
			this->tbLankCntL3->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbLankCntL3->Size = System::Drawing::Size(126, 75);
			this->tbLankCntL3->TabIndex = 26;
			this->tbLankCntL3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbLankCntR2
			// 
			this->tbLankCntR2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbLankCntR2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbLankCntR2->Font = (gcnew System::Drawing::Font(L"굴림", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbLankCntR2->Location = System::Drawing::Point(652, 476);
			this->tbLankCntR2->Multiline = true;
			this->tbLankCntR2->Name = L"tbLankCntR2";
			this->tbLankCntR2->ReadOnly = true;
			this->tbLankCntR2->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbLankCntR2->Size = System::Drawing::Size(126, 75);
			this->tbLankCntR2->TabIndex = 25;
			this->tbLankCntR2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbLankCntL2
			// 
			this->tbLankCntL2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbLankCntL2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbLankCntL2->Font = (gcnew System::Drawing::Font(L"굴림", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbLankCntL2->Location = System::Drawing::Point(528, 476);
			this->tbLankCntL2->Multiline = true;
			this->tbLankCntL2->Name = L"tbLankCntL2";
			this->tbLankCntL2->ReadOnly = true;
			this->tbLankCntL2->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbLankCntL2->Size = System::Drawing::Size(126, 75);
			this->tbLankCntL2->TabIndex = 24;
			this->tbLankCntL2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbLankCntR4
			// 
			this->tbLankCntR4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbLankCntR4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbLankCntR4->Font = (gcnew System::Drawing::Font(L"굴림", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbLankCntR4->Location = System::Drawing::Point(1164, 476);
			this->tbLankCntR4->Multiline = true;
			this->tbLankCntR4->Name = L"tbLankCntR4";
			this->tbLankCntR4->ReadOnly = true;
			this->tbLankCntR4->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbLankCntR4->Size = System::Drawing::Size(126, 75);
			this->tbLankCntR4->TabIndex = 29;
			this->tbLankCntR4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbLankCntL4
			// 
			this->tbLankCntL4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tbLankCntL4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbLankCntL4->Font = (gcnew System::Drawing::Font(L"굴림", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tbLankCntL4->Location = System::Drawing::Point(1040, 476);
			this->tbLankCntL4->Multiline = true;
			this->tbLankCntL4->Name = L"tbLankCntL4";
			this->tbLankCntL4->ReadOnly = true;
			this->tbLankCntL4->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tbLankCntL4->Size = System::Drawing::Size(126, 75);
			this->tbLankCntL4->TabIndex = 28;
			this->tbLankCntL4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btShowTimeTab0
			// 
			this->btShowTimeTab0->Location = System::Drawing::Point(16, 557);
			this->btShowTimeTab0->Name = L"btShowTimeTab0";
			this->btShowTimeTab0->Size = System::Drawing::Size(250, 35);
			this->btShowTimeTab0->TabIndex = 30;
			this->btShowTimeTab0->Text = L"시간표 보기";
			this->btShowTimeTab0->UseVisualStyleBackColor = true;
			this->btShowTimeTab0->Click += gcnew System::EventHandler(this, &TimeTabForm::btShowTimeTab0_Click);
			// 
			// btShowTimeTab1
			// 
			this->btShowTimeTab1->Location = System::Drawing::Point(272, 557);
			this->btShowTimeTab1->Name = L"btShowTimeTab1";
			this->btShowTimeTab1->Size = System::Drawing::Size(250, 35);
			this->btShowTimeTab1->TabIndex = 31;
			this->btShowTimeTab1->Text = L"시간표 보기";
			this->btShowTimeTab1->UseVisualStyleBackColor = true;
			this->btShowTimeTab1->Click += gcnew System::EventHandler(this, &TimeTabForm::btShowTimeTab1_Click);
			// 
			// btShowTimeTab2
			// 
			this->btShowTimeTab2->Location = System::Drawing::Point(528, 557);
			this->btShowTimeTab2->Name = L"btShowTimeTab2";
			this->btShowTimeTab2->Size = System::Drawing::Size(250, 35);
			this->btShowTimeTab2->TabIndex = 32;
			this->btShowTimeTab2->Text = L"시간표 보기";
			this->btShowTimeTab2->UseVisualStyleBackColor = true;
			this->btShowTimeTab2->Click += gcnew System::EventHandler(this, &TimeTabForm::btShowTimeTab2_Click);
			// 
			// btShowTimeTab3
			// 
			this->btShowTimeTab3->Location = System::Drawing::Point(784, 557);
			this->btShowTimeTab3->Name = L"btShowTimeTab3";
			this->btShowTimeTab3->Size = System::Drawing::Size(250, 35);
			this->btShowTimeTab3->TabIndex = 33;
			this->btShowTimeTab3->Text = L"시간표 보기";
			this->btShowTimeTab3->UseVisualStyleBackColor = true;
			this->btShowTimeTab3->Click += gcnew System::EventHandler(this, &TimeTabForm::btShowTimeTab3_Click);
			// 
			// btShowTimeTab4
			// 
			this->btShowTimeTab4->Location = System::Drawing::Point(1040, 557);
			this->btShowTimeTab4->Name = L"btShowTimeTab4";
			this->btShowTimeTab4->Size = System::Drawing::Size(250, 35);
			this->btShowTimeTab4->TabIndex = 34;
			this->btShowTimeTab4->Text = L"시간표 보기";
			this->btShowTimeTab4->UseVisualStyleBackColor = true;
			this->btShowTimeTab4->Click += gcnew System::EventHandler(this, &TimeTabForm::btShowTimeTab4_Click);
			// 
			// TimeTabForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1304, 672);
			this->Controls->Add(this->btShowTimeTab4);
			this->Controls->Add(this->btShowTimeTab3);
			this->Controls->Add(this->btShowTimeTab2);
			this->Controls->Add(this->btShowTimeTab1);
			this->Controls->Add(this->btShowTimeTab0);
			this->Controls->Add(this->tbLankCntR4);
			this->Controls->Add(this->tbLankCntL4);
			this->Controls->Add(this->tbLankCntR3);
			this->Controls->Add(this->tbLankCntL3);
			this->Controls->Add(this->tbLankCntR2);
			this->Controls->Add(this->tbLankCntL2);
			this->Controls->Add(this->tbLankCntR1);
			this->Controls->Add(this->tbLankCntL1);
			this->Controls->Add(this->tbLankCntR0);
			this->Controls->Add(this->tbLankCntL0);
			this->Controls->Add(this->tbColumn4);
			this->Controls->Add(this->tbColumn3);
			this->Controls->Add(this->tbColumn2);
			this->Controls->Add(this->tbColumn1);
			this->Controls->Add(this->tbColumn0);
			this->Controls->Add(this->tbTimeTab4);
			this->Controls->Add(this->tbTimeTab3);
			this->Controls->Add(this->tbTimeTab2);
			this->Controls->Add(this->tbTimeTab1);
			this->Controls->Add(this->tbTimeTab0);
			this->Controls->Add(this->tbPageNum);
			this->Controls->Add(this->btNext);
			this->Controls->Add(this->btPrev);
			this->Name = L"TimeTabForm";
			this->Text = L"시간표";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		using Bits = long long;
		using TimeTab = Bits;

		const int kValue = 5;
		bool isInitializing = true;
		bool isPageLoading = false;

		TimeTabGenerator* mGenerator;
		vector<vector<Course>>* mCourseOfTimeTab;

		List<TextBox^>^ mColumnList;
		List<TextBox^>^ mTimeTabList;
		List<TextBox^>^ mCourseLankCountL;
		List<TextBox^>^ mCourseLankCountR;
		List<String^>^ mCourseLnakLabel;
		int mPageIndex;



	private:
		String^ ToGcString(string& stdString) { return gcnew String(stdString.data()); }
		string ToStdString(String^ gcString) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(gcString)).ToPointer();
			string stdString = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			return stdString;
		}



	private:
		System::Void InitialzerMembers(int targetCredit, vector<Course>& essnCourseList, vector<Course>& normCourseList, vector<int>& nomCourseLank) {
			isInitializing = true;

			// 멤버 초기화
			mGenerator = new TimeTabGenerator(kValue, targetCredit, essnCourseList, normCourseList, nomCourseLank);
			mCourseOfTimeTab = new vector<vector<Course>>();

			mColumnList = gcnew List<TextBox^>();
			mColumnList->Add(tbColumn0);
			mColumnList->Add(tbColumn1);
			mColumnList->Add(tbColumn2);
			mColumnList->Add(tbColumn3);
			mColumnList->Add(tbColumn4);

			mTimeTabList = gcnew List<TextBox^>();
			mTimeTabList->Add(tbTimeTab0);
			mTimeTabList->Add(tbTimeTab1);
			mTimeTabList->Add(tbTimeTab2);
			mTimeTabList->Add(tbTimeTab3);
			mTimeTabList->Add(tbTimeTab4);

			mCourseLankCountL = gcnew List<TextBox^>();
			mCourseLankCountL->Add(tbLankCntL0);
			mCourseLankCountL->Add(tbLankCntL1);
			mCourseLankCountL->Add(tbLankCntL2);
			mCourseLankCountL->Add(tbLankCntL3);
			mCourseLankCountL->Add(tbLankCntL4);

			mCourseLankCountR = gcnew List<TextBox^>();
			mCourseLankCountR->Add(tbLankCntR0);
			mCourseLankCountR->Add(tbLankCntR1);
			mCourseLankCountR->Add(tbLankCntR2);
			mCourseLankCountR->Add(tbLankCntR3);
			mCourseLankCountR->Add(tbLankCntR4);

			mCourseLnakLabel = gcnew List<String^>();
			mCourseLnakLabel->Add(" 필수");
			mCourseLnakLabel->Add("1순위");
			mCourseLnakLabel->Add("2순위");
			mCourseLnakLabel->Add("3순위");
			mCourseLnakLabel->Add("4순위");
			mCourseLnakLabel->Add("5순위");

			// 페이지 로드
			mPageIndex = 1;
			LoadPage(PageMove::Hold);

			isInitializing = false;
		}



	private:	// 시간표 페이지 관리
		System::Void AddCourse(TextBox^ timeTab, Course& course) {
			timeTab->Text += ToGcString("{ " + course.name + "-" + course.id.div + " }") + Environment::NewLine;
			timeTab->Text += ToGcString("{ " + course.id.base + "-" + course.id.div + ", " + course.professor + " }") + Environment::NewLine;
			timeTab->Text += Environment::NewLine;
		}

		System::Void CountCourseLank(TextBox^ lankL, TextBox^ lankR, vector<int>& resultMessage) {
			for (int i = 0; i < 3; i++) lankL->Text += Environment::NewLine + mCourseLnakLabel[i] + ": " + resultMessage[i].ToString() + "개";
			for (int i = 3; i < 6; i++) lankR->Text += Environment::NewLine + mCourseLnakLabel[i] + ": " + resultMessage[i].ToString() + "개";
		}

		System::Void LoadPage(PageMove pageMove) {
			if (isPageLoading) return;

			isPageLoading = true;
			mPageIndex += (int)pageMove;

			auto [essnCourseList, normCourseAdjList, timeTbCourseLankCount, resultMessage] = mGenerator->Get_TimeTable(mPageIndex);
			int timeTabCnt = normCourseAdjList.size();

			switch (resultMessage)
			{
			case TimeTabGenerator::LoadSuccessfully:
				mCourseOfTimeTab->clear();
				for (int i = 0; i < kValue; i++) {
					mColumnList[i]->Clear();
					mTimeTabList[i]->Text = Environment::NewLine;
					mCourseLankCountL[i]->Clear();
					mCourseLankCountR[i]->Clear();

					if (i < timeTabCnt) {
						mCourseOfTimeTab->push_back(vector<Course>());
						mColumnList[i]->Text = "시간표 " + (kValue * (mPageIndex - 1) + i + 1).ToString();
						for (auto& course : essnCourseList) { mCourseOfTimeTab->back().push_back(course); AddCourse(mTimeTabList[i], course); }
						for (auto& course : normCourseAdjList[i]) { mCourseOfTimeTab->back().push_back(course); AddCourse(mTimeTabList[i], course); }
						CountCourseLank(mCourseLankCountL[i], mCourseLankCountR[i], timeTbCourseLankCount[i]);
					}
				}
				tbPageNum->Text = "Page " + mPageIndex.ToString();
				break;

			case TimeTabGenerator::CannotLoadPrev:
				MessageBox::Show("맨 앞 페이지 입니다");
				mPageIndex -= (int)pageMove;
				break;

			case TimeTabGenerator::CannotLoadNext:
				MessageBox::Show("마지막 페이지 입니다");
				mPageIndex -= (int)pageMove;
				break;

			case TimeTabGenerator::EssentialConflict:
				MessageBox::Show("잘못된 Input 입니다 (필수과목 사이에서 시간 충돌이 존재합니다)");
				mPageIndex -= (int)pageMove;
				break;

			case TimeTabGenerator::CannotCreateTimeTab:
				MessageBox::Show("해당 Input으로 시간표를 생성할 수 없습니다");
				mPageIndex -= (int)pageMove;
				break;

			default:
				break;
			}

			isPageLoading = false;
		}

		System::Void btPrev_Click(System::Object^ sender, System::EventArgs^ e) {
			if (isInitializing) return;
			LoadPage(PageMove::Prev);
		}

		System::Void btNext_Click(System::Object^ sender, System::EventArgs^ e) {
			if (isInitializing) return;
			LoadPage(PageMove::Next);
		}



	private:	// 시간표 확인
		System::Void ShowTimeTab(int tabIndex) {
			if ((int)mCourseOfTimeTab->size() <= tabIndex) return;
			auto showTimeTabForm = gcnew ShowTimeTabForm((*mCourseOfTimeTab)[tabIndex]);
			showTimeTabForm->Show();
		}
		System::Void btShowTimeTab0_Click(System::Object^ sender, System::EventArgs^ e) { ShowTimeTab(0); }
		System::Void btShowTimeTab1_Click(System::Object^ sender, System::EventArgs^ e) { ShowTimeTab(1); }
		System::Void btShowTimeTab2_Click(System::Object^ sender, System::EventArgs^ e) { ShowTimeTab(2); }
		System::Void btShowTimeTab3_Click(System::Object^ sender, System::EventArgs^ e) { ShowTimeTab(3); }
		System::Void btShowTimeTab4_Click(System::Object^ sender, System::EventArgs^ e) { ShowTimeTab(4); }
	};
}