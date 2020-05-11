#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>

namespace Busy_Mama {
    class Reminder
	{
	private:
		tm AskedTime, CurrntTime, DiffrenceTime;
		time_t Now;
	public:
		Reminder();
		void GetTime(int Hour, int Minute);
		void StartReminder();
		void DiffrencetBtweenCrruntandAskedtime();
	};
}

