#include<iostream>
#include "UserLogin.h"
#include "Start.h"


using namespace std;


namespace Busy_Mama {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int main()
	{
		Application::Run(gcnew Start);

		return 0;
	}
}