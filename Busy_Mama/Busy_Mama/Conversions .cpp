#include "Conversions.h"
#include<string>
#include <msclr\marshal_cppstd.h>


namespace Busy_Mama {
	using namespace msclr::interop;

	DateTime Conversions::ConvertTimetToDatetime(time_t date)
	{
		double sec = static_cast<double>(date);
		return DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind::Utc).AddSeconds(sec);
	}
	time_t Conversions::ConvertDatetimeToTimet(DateTime date)
	{
		TimeSpan diff = date.ToUniversalTime() - DateTime(1970, 1, 1);
		return static_cast<time_t>(diff.TotalSeconds);
	}
	String^ Conversions::stringToString(string s)
	{
		 return marshal_as<String^>(s);
	}
	string Conversions::StringTostring(String^ s)
	{
		return marshal_as<string>(s);
	}
	
}