#pragma once
#include<string>
#include <vector>
#include <queue>
#include <stack>
#include "Task.h"
#include "Priority.h"
#include"Priority_Queue.cpp"
using namespace std;

namespace Busy_Mama {
	class User
	{
	public:
		int userID;
		string name;
		string password;
		vector<Task> userTasks;
		vector<int>undone_tasks;

		Priority_queue<Task> TodayTasks;
		Priority_queue<Task> temp;
	//	priority_queue<Task, vector<Task>, Priority> TodayTasks;
	//	priority_queue<Task, vector<Task>, Priority> temp;

		vector<string> EndTasksName;

	public:
		User();
		void AddNewTask(string name, int priority, string date , string currentDate);
		void Filteration(string date);
		void UpdateTodayTask(string name, int priority, string date, string currentDate);
		Task UpdateTask(string name,int priority, string date);
		void EndTodayTask(string name);
		void GetTodayTasks(string currentDate);
		bool compare_date(string d1, string d2);
		void del(bool delay,string currentDate);

	};

}