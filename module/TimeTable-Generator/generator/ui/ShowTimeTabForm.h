
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
	/// �ð�ǥ�� �ð�ȭ�Ͽ� �����ش�
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
	private: System::Windows::Forms::PictureBox^ pbTimeTabBackGround;

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
			this->pbTimeTabBackGround = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTimeTabBackGround))->BeginInit();
			this->SuspendLayout();
			// 
			// pbTimeTabBackGround
			// 
			this->pbTimeTabBackGround->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pbTimeTabBackGround->Location = System::Drawing::Point(9, 9);
			this->pbTimeTabBackGround->Margin = System::Windows::Forms::Padding(0);
			this->pbTimeTabBackGround->Name = L"pbTimeTabBackGround";
			this->pbTimeTabBackGround->Size = System::Drawing::Size(435, 990);
			this->pbTimeTabBackGround->TabIndex = 1;
			this->pbTimeTabBackGround->TabStop = false;
			// 
			// ShowTimeTabForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(460, 750);
			this->Controls->Add(this->pbTimeTabBackGround);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ShowTimeTabForm";
			this->Text = L"�ð�ǥ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTimeTabBackGround))->EndInit();
			this->ResumeLayout(false);

		}



#pragma endregion
	private:
		static String^ ToGcString(string& stdString) { return gcnew String(stdString.data()); }
		static string ToStdString(String^ gcString) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(gcString)).ToPointer();
			string stdString = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			return stdString;
		}



	private:		
		ref class EventReceiver {   // �������� �Ҵ�� Control�� Event�� �߰��ϱ� ���� EventReceiver
		private:
			vector<Course>* mCourseList;

		public:
			EventReceiver(vector<Course>& courseList) :mCourseList(&courseList) {}

			void CourseBlock_Click(System::Object^ sender, System::EventArgs^ e) {
				auto courseIdx = stoi(util::Split(ToStdString(((Button^)sender)->Name), util::SplitType::Contain, regex(R"(\d)"))[0]);
				auto& course = (*mCourseList)[courseIdx];

				String^ message
					= "�����        " + ToGcString(course.name) + "-" + ToGcString(course.id.div)
					+ Environment::NewLine + "������        " + ToGcString(course.professor)
					+ Environment::NewLine + "����           " + course.credit + "����"
					+ Environment::NewLine + "�м���ȣ     " + ToGcString(course.id.ToString());

				int idx = 0;
				message += Environment::NewLine;
				for (auto& time : course.times)
					message += Environment::NewLine + "���ǽð�" + (++idx) + "    " + ToGcString(time.ToString());

				MessageBox::Show(message, "���� ����");
			}
		};



	private:
		System::Int32 DayToInt(string& day) {	// ���� ������ �ð�ǥ�� column�ε����� ��ȯ
			if (day == "��") return 0;
			if (day == "ȭ") return 1;
			if (day == "��") return 2;
			if (day == "��") return 3;
			if (day == "��") return 4;
			if (day == "��") return 5;
			if (day == "��") return 6;
			return -1;
		}

		Button^ CreateBlock(string& day, int start, int end) {
			auto defaultPoint = Point(35 + 9, 23 + 13);
			auto defaultSize = Point(80, 60);
			auto block = gcnew Button();

			this->Controls->Add(block);
			block->BringToFront();
			block->Visible = true;
			block->FlatStyle = FlatStyle::Flat;
			block->FlatAppearance->BorderSize = 0;
			block->Font = gcnew System::Drawing::Font("", 10, FontStyle::Bold);
			block->TextAlign = ContentAlignment::TopLeft;
			block->ForeColor = Color::White;

			block->Left = defaultPoint.X + (DayToInt(day) * defaultSize.X);
			block->Top = defaultPoint.Y + (((start / 60) - 8) * defaultSize.Y) + (start % 60);
			block->Width = defaultSize.X - 1;
			block->Height = (((end - start) / 60) * defaultSize.Y) + ((end - start) % 60) - 1;

			return block;
		}

		Color CouseNumToColor(int courseNum) {	// ���Ǹ� ��Ÿ���� ����� ���� ����
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

		System::Void InitialzerMembers(vector<Course>& courseList) {
			EventReceiver^ MyEventReceiver = gcnew EventReceiver(courseList);
	
			int courseIdx = 0;
			for (auto& course : courseList) {
				for (auto& time : course.times) {
					// ���� ��� ����
					auto block = CreateBlock(time.day, time.start, time.end);

					// ���� ����� Name, Text, BackColor����
					block->Name = "course" + courseIdx;
					block->Text = ToGcString(course.name) + Environment::NewLine + ToGcString(course.professor);
					block->BackColor = CouseNumToColor(courseIdx);

					// ���� ��Ͽ� Event �ο�
					block->Click += gcnew System::EventHandler(MyEventReceiver, &EventReceiver::CourseBlock_Click);
				}
				courseIdx++;
			}

			pbTimeTabBackGround->BackgroundImage = Image::FromFile(System::IO::Directory::GetCurrentDirectory() + "\\documents\\image\\background_timetable.png");
		}
	};
}