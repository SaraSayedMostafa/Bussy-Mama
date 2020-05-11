#pragma once
#include <iostream>
#include <string>
#include<utility>
#include<queue>
#include<sstream>//stringstream
#include<fstream>//file
#include "Task.h"
#include <ctime>
#include "Conversions.h"
#include "UserTasks.h"
#include <msclr\marshal_cppstd.h>
#include<vector>


namespace Busy_Mama {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace std;
	static vector<User> users;
	/// <summary>
	/// Summary for UserLogin
	/// </summary>
	public ref class UserLogin : public System::Windows::Forms::Form
	{

	public:
		UserLogin(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here

			//
		}

		void read_file(vector<User>& v)//put values into vectors
		{
			int n = -1; bool first = 1;
			User u;
			string line, name;

			ifstream busy;
			busy.open("busy.txt");
			Task t;
			if (busy.is_open())
			while (!busy.eof())
			{
				getline(busy, line);
				if (line == "*")
				{
					///cout << "*\n";
					n = 0;
					if (first)
						first = 0;
					else
					{
						v.push_back(u);
						u.userTasks.clear();
					}
					continue;
				}
				else if (n == 0)
				{
					u.name = line;
					///cout <<"name read : "<< u.name << endl;
				}
				else if (n == 1)
				{
					u.password = line;
					//8ayart el func //u = User(name, password);
					///cout << "pass : " << u.password << endl;
				}
				else if (n % 3 == 2)
				{
					t.taskName = line;
					//cout <<"read task : "<< t.taskName << endl;
				}
				else if (n % 3 == 0)
				{
					stringstream conv(line);
					conv >> t.taskPriority;
					///cout << t.priority << endl;
				}
				else if (n % 3 == 1)///date
				{
					t.taskDate = line;
					///cout << t.dat << endl;
					/*stringstream conv(line);
					conv >> t.dat.day >> t.dat.month >> t.dat.year;
					cout << t.dat.day << ' ' << t.dat.month << ' ' << t.dat.year << endl;*/
					u.userTasks.push_back(t);
					//v.push_back(u);
					//break;
				}

				n++;
			}
			busy.close();

		}

		void overwrite()
		{
			//
			ofstream busy;
			busy.open("busy.txt", ios::out | ios::trunc);

			//
			busy << "*\n";
			int size = users.size();
			for (int i = 0; i < size; i++)
			{
				//int task_no = 0;
				//task_no = users[i].tasks_size();
				//cout<<"number of tasks : " << task_no<<endl;
				User x = users[i];
				string nam = users[i].name;
				string p = x.password;
				//cout <<"*\n"<<"name : "<< nam << endl<<"pass : "<<p<<endl;
				busy << nam << "\n" << p << "\n";
				for (int j = 0; j < users[i].userTasks.size(); j++)
				{
					busy << users[i].userTasks[j].taskName << "\n" << users[i].userTasks[j].taskPriority << "\n" << users[i].userTasks[j].taskDate << "\n";
				}
				busy << "*";
				if (i != size - 1)
					busy << "\n";
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnLogin;
	private: System::Windows::Forms::TextBox^  txtUserName;
	private: System::Windows::Forms::TextBox^  txtPassword;
	protected:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
private: System::IO::FileSystemWatcher^  fileSystemWatcher1;



	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UserLogin::typeid));
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->txtUserName = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::LavenderBlush;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnLogin->Location = System::Drawing::Point(413, 206);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(109, 58);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &UserLogin::btnLogin_Click);
			// 
			// txtUserName
			// 
			this->txtUserName->Location = System::Drawing::Point(209, 143);
			this->txtUserName->Name = L"txtUserName";
			this->txtUserName->Size = System::Drawing::Size(186, 22);
			this->txtUserName->TabIndex = 1;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(210, 196);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(186, 22);
			this->txtPassword->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(44, 130);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 40);
			this->label1->TabIndex = 3;
			this->label1->Text = L"User Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(46, 183);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(139, 40);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Password";
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			// 
			// UserLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(713, 639);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtUserName);
			this->Controls->Add(this->btnLogin);
			this->Name = L"UserLogin";
			this->Text = L"UserLogin";
			this->Load += gcnew System::EventHandler(this, &UserLogin::UserLogin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnLogin_Click(System::Object^  sender, System::EventArgs^  e)
	{

				 Conversions c;
				 if (!String::IsNullOrWhiteSpace(txtUserName->Text) && !String::IsNullOrWhiteSpace(txtPassword->Text))
				 {
					 string name = c.StringTostring(txtUserName->Text);
					 string password = c.StringTostring(txtPassword->Text);
					 bool exists = false;
					 for (int i = 0; i < users.size(); i++)
					 {

						 if ((users[i].name == name) && (users[i].password == password))
						 {
							 exists = true;
							 UserTasks^ userTasks = gcnew UserTasks(users[i]);
							 userTasks->ShowDialog();
							 users[i] = userTasks->GetUpdatedUser();
							 overwrite();
							 break;
						 }
					 }
					 if (exists == false)
						 MessageBox::Show(" INCCORRECT User Name OR Password ");
				 }
				 else
					 MessageBox::Show("Please Enter Your Name And Password");
	}

	private: System::Void UserLogin_Load(System::Object^  sender, System::EventArgs^  e)
	{
				 read_file(users);
				 //MessageBox(NULL, "you have unfinished Tasks...", "The Title", MB_YESNO)
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{

}
};
}

	