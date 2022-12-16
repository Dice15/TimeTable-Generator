#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TimeTableGenerator::MainForm mainForm;
	Application::Run(% mainForm);
}