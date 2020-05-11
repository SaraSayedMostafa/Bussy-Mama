#ifndef MYSTRUCT_H
#define MYSTRUCT_H
#include <ctime>
#include<string>
using namespace std;

namespace Busy_Mama {

	using namespace System;
	public ref class Conversions
	{

	public:
		static DateTime ConvertTimetToDatetime(time_t date);
		static time_t ConvertDatetimeToTimet(DateTime date);
		String^ stringToString(string s);
		string StringTostring(String^ s);
		
	};
}
#endif