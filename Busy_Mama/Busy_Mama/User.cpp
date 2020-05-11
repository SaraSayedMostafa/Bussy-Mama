#include "User.h"

namespace Busy_Mama {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	User::User()
	{
	}

	void User::AddNewTask(string name, int priority, string date,string currentDate)
	{
		    Task task;
			task.taskName = name;
		   task. taskPriority = priority;
		    task.taskDate = date;

				stack <Task> S;
				bool exists = false;

				if (date == currentDate)
				{
				while (!TodayTasks.Empty())
				{
					if (TodayTasks.Top().taskName == name)
					{
						exists = true;
						break;
					}

					S.push(TodayTasks.Top());
					TodayTasks.Pop();
					//break;
				}
				while (!S.empty())
				{
					TodayTasks.Push(S.top(), S.top().taskPriority);
					S.pop();
				}

				if (exists == true)
					  MessageBox::Show("Task Already Exists");
				else
				{	
				TodayTasks.Push(task, priority);
		     	userTasks.push_back(task);
				}
				}
				else
				userTasks.push_back(task);

			}

	void User::Filteration(string date)
	{
		for (int i = 0; i < userTasks.size(); i++)
		{
			if (date == userTasks[i].taskDate)
				temp.Push(userTasks[i] , userTasks[i].taskPriority);
		}
	}

	Task User::UpdateTask(string name,int priority, string date)
	{
		int indx;
		for (int i = 0; i < userTasks.size(); i++)
		{
			if (userTasks[i].taskName == name)
				indx = i;
		}
		
		userTasks[indx].taskPriority = priority;
		userTasks[indx].taskDate = date;
		return userTasks[indx];
	}
	void User::UpdateTodayTask(string name,int priority, string date ,string currentDate)
	{
		stack<Task> st;
		bool isTodayTask = false;//msh 
		while (!TodayTasks.Empty())
		{
			if (name == TodayTasks.Top().taskName)
			{
				
				Task t = TodayTasks.Top();
				t.taskPriority = priority;
			    //TodayTasks.top().taskPriority = priority;
				TodayTasks.Pop();
				TodayTasks.Push(t, t.taskPriority);

				if (currentDate == date)
				{
					Task tt = TodayTasks.Top();
					tt.taskDate = date;
					TodayTasks.Pop();
					TodayTasks.Push(tt, tt.taskPriority);
				}
				else
					TodayTasks.Pop();
				
				isTodayTask = true;
				break;
			}
			else
			{
				st.push(TodayTasks.Top());
				TodayTasks.Pop();
			}
		}
		while (!st.empty())
		{
			TodayTasks.Push(st.top() , st.top().taskPriority);
			st.pop();
		}
	  Task t =	UpdateTask(name, priority,date);

		if (isTodayTask == false && currentDate == date)
			TodayTasks.Push(t , t.taskPriority);

	}
	
	void User::EndTodayTask(string name)
	{
		stack<Task> st;
		while (!TodayTasks.Empty())
		{
			Task t = TodayTasks.Top();
			if (t.taskName == name)
			{
				TodayTasks.Pop();
				break;
			}
			else
			{
				st.push(TodayTasks.Top());
				TodayTasks.Pop();
			}
		}
		while (!st.empty())
		{
			TodayTasks.Push(st.top() , st.top().taskPriority);
			st.pop();
		}
		int indx;
		for (int i = 0; i < userTasks.size(); i++)
		{
			if (name == userTasks[i].taskName)
			{
				indx = i;
		       userTasks.erase(userTasks.begin() + indx);
				break;
			}
		}
	}
	void User::del(bool delay , string currentDate)
	{
		int size = undone_tasks.size();
		int indx;
		for (int i = 0; i < size; i++)
		{
			indx = undone_tasks[i];
			if (delay == 1)
			{
				UpdateTodayTask(userTasks[indx].taskName, userTasks[i].taskPriority, currentDate, currentDate);
			}
			else
			{
				userTasks.erase(userTasks.begin() + indx);
			}
		}
		undone_tasks.clear();
	}
	bool User::compare_date(string d, string cd)/*msh 5alsana*/
	{
		int month_d = (d[0] - '0') * 10 + (d[1] - '0');
		int month_cd = (cd[0] - '0') * 10 + (cd[1] - '0');
		int day_d = (d[3] - '0') * 10 + (d[4] - '0');
		int day_cd = (cd[3] - '0') * 10 + (cd[4] - '0');
		int year_d = (d[6] - '0') * 1000 + (d[7] - '0') * 100 + (d[8] - '0') * 10 + (d[9] - '0');
		int year_cd = (cd[6] - '0') * 1000 + (cd[7] - '0') * 100 + (cd[8] - '0') * 10 + (cd[9] - '0');
		if ((year_d < year_cd) || ((year_d == year_cd) && (month_d < month_cd)) || ((year_d == year_cd) && (month_d == month_cd) && (day_d < day_cd)))
			return 1;
		return 0;
	}
	void User::GetTodayTasks(string currentDate)
	{
		for (int i = 0; i < userTasks.size(); i++)
		{
			if (userTasks[i].taskDate == currentDate)
				TodayTasks.Push(userTasks[i],userTasks[i].taskPriority);
			else if (compare_date(userTasks[i].taskDate, currentDate))//fat
				undone_tasks.push_back(i);
		}
	}
}