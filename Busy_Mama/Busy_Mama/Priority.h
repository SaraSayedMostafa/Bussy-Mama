#ifndef prio_H
#define prio_H
#include "User.h"

namespace Busy_Mama {
	using namespace System;
	using namespace std;

	struct Priority
	{
		bool operator()(Task const& proi1, Task const& proi2)
		{
			return proi1.taskPriority < proi2.taskPriority;
		}
	};
}


#endif