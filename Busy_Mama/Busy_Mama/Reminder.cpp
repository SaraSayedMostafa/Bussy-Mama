
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "Reminder.h"

using namespace std;
using namespace System::Threading;

namespace Busy_Mama {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

		Reminder::Reminder() //constructor of the class
		{
			Now = time(0);
			CurrntTime = *localtime(&Now);
			AskedTime = CurrntTime;
			AskedTime.tm_sec = 0;
		}


		void Reminder::GetTime(int Hour,int Minute)
		{
			//int Hour = 0, Minute = 0;
			/*cout << "Enter Time in 24-Hour format [HH:MM]" << endl;
			cout << "Enter Hours then Minutes" << endl;
			cin >> Hour >> Minute;*/
			AskedTime.tm_hour = Hour;
			AskedTime.tm_min = Minute;

		};
		void Reminder:: StartReminder()
		{
			while (true)
			{
				system("cls");
				Now = time(0);
				CurrntTime = *localtime(&Now);
				DiffrencetBtweenCrruntandAskedtime();
			    // cout << "TIME REMAINING:    " << DiffrenceTime.tm_hour << ":" << DiffrenceTime.tm_min << ":" << DiffrenceTime.tm_sec << endl;
				
				if (DiffrenceTime.tm_hour == 0 && DiffrenceTime.tm_min == 0 && DiffrenceTime.tm_sec == 0)
				{
				//	cout << "HARRY UP to make your TASK" << endl; //mmkn ntl3 raqm el task el bnfkro beh aw asmo hna gmb el masssge de
					MessageBox::Show("End task");
					break;
				}
				
				// System::Threading::Thread.Sleep(1);


			}


		};
		void Reminder:: DiffrencetBtweenCrruntandAskedtime()
		{
			int seconds = difftime(mktime(&AskedTime), Now);
			DiffrenceTime.tm_sec = seconds % 60;   //9630sec /60=0.5*60=30 sec
			DiffrenceTime.tm_min = seconds / 60;  //9630/60=160
			DiffrenceTime.tm_hour = DiffrenceTime.tm_min / 60; //160/60=2
			DiffrenceTime.tm_min = DiffrenceTime.tm_min % 60; //160/60=0.6666667*60=40 min



			if (seconds < 0)
			{
				DiffrenceTime.tm_hour = 24 + DiffrenceTime.tm_hour - 1;
				DiffrenceTime.tm_min = 0 - DiffrenceTime.tm_min;
				DiffrenceTime.tm_sec = 0 - DiffrenceTime.tm_sec;
			}



		};



	}


