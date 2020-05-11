#pragma once
#include "Task.h"
#include <ctime>
#include <windows.h>
#include "Conversions.h"
#include "UserTasks.h"
#include "User.h"
#include <set>
#include<queue>
#include "Priority.h"
#include "Reminder.h"
#include "XXOO.h"

using namespace std;
namespace Busy_Mama {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	static User user;
	static set<string> s;
	/// <summary>
	/// Summary for UserTasks
	/// </summary>
	public ref class UserTasks : public System::Windows::Forms::Form
	{
	public:

		UserTasks(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}


		UserTasks(User currentUser)
		{
			InitializeComponent();
			user = currentUser;
			DateTime t = t.Now;
			string currentDate = cc.StringTostring(t.ToString("MM/dd/yyyy"));
			user.GetTodayTasks(currentDate);
			if (!(user.undone_tasks.empty()))
			{
				bool delay;
				if (MessageBox::Show("You Have Unfinished Tasks...Do you want to delay Them To Today List?\n If you Choose No they Will Be Deleted", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
					delay = 1;
				else
					delay = 0;
				user.del(delay,currentDate);
			}

			for (int i = 0; i < user.userTasks.size(); i++)
			{
				s.insert(user.userTasks[i].taskDate);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserTasks()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;


	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  btnAddTask;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DateTimePicker^  dtbTaskDate;

	private: System::Windows::Forms::ComboBox^  cbAddTaskPriority;
	private: System::Windows::Forms::Button^  btnShowTodayTasks;

	private: System::Windows::Forms::Button^  btnShowAllTasks;
	private: System::Windows::Forms::DataGridView^  dgShowTasks;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TaskName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Priority;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TaskDate;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnUpdate;
	private: System::Windows::Forms::DateTimePicker^  dtpUpdateTaskDate;
	private: System::Windows::Forms::ComboBox^  cbUpdateTaskPriority;

	private: System::Windows::Forms::ComboBox^  cbTaskName;
	private: System::Windows::Forms::TextBox^  txtTaskNameAdd;
	private: System::Windows::Forms::ComboBox^  cbShowTaskDate;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Button^  btnEndTask;
	private: System::Windows::Forms::ComboBox^  cbEndTasksName;
	private: System::Windows::Forms::DataGridView^  dgShowEndTasks;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  EndTasks;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TextBox^  txtMinutes;
	private: System::Windows::Forms::TextBox^  txtHours;
	private: System::Windows::Forms::Button^  btnReminder;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Timer^  Reminder;

	private: System::ComponentModel::IContainer^  components;





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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UserTasks::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btnAddTask = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dtbTaskDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->cbAddTaskPriority = (gcnew System::Windows::Forms::ComboBox());
			this->txtTaskNameAdd = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->cbShowTaskDate = (gcnew System::Windows::Forms::ComboBox());
			this->btnShowTodayTasks = (gcnew System::Windows::Forms::Button());
			this->btnShowAllTasks = (gcnew System::Windows::Forms::Button());
			this->dgShowTasks = (gcnew System::Windows::Forms::DataGridView());
			this->TaskName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Priority = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TaskDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->dtpUpdateTaskDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->cbUpdateTaskPriority = (gcnew System::Windows::Forms::ComboBox());
			this->cbTaskName = (gcnew System::Windows::Forms::ComboBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->dgShowEndTasks = (gcnew System::Windows::Forms::DataGridView());
			this->EndTasks = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnEndTask = (gcnew System::Windows::Forms::Button());
			this->cbEndTasksName = (gcnew System::Windows::Forms::ComboBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->txtMinutes = (gcnew System::Windows::Forms::TextBox());
			this->txtHours = (gcnew System::Windows::Forms::TextBox());
			this->btnReminder = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->Reminder = (gcnew System::Windows::Forms::Timer(this->components));
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgShowTasks))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgShowEndTasks))->BeginInit();
			this->tabPage5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Location = System::Drawing::Point(0, 2);
			this->tabControl1->Multiline = true;
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(574, 499);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabPage1.BackgroundImage")));
			this->tabPage1->Controls->Add(this->btnAddTask);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->dtbTaskDate);
			this->tabPage1->Controls->Add(this->cbAddTaskPriority);
			this->tabPage1->Controls->Add(this->txtTaskNameAdd);
			this->tabPage1->Location = System::Drawing::Point(4, 46);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tabPage1->Size = System::Drawing::Size(566, 449);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Add New Task";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// btnAddTask
			// 
			this->btnAddTask->BackColor = System::Drawing::Color::LavenderBlush;
			this->btnAddTask->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAddTask->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnAddTask->Location = System::Drawing::Point(208, 208);
			this->btnAddTask->Name = L"btnAddTask";
			this->btnAddTask->Size = System::Drawing::Size(133, 39);
			this->btnAddTask->TabIndex = 6;
			this->btnAddTask->Text = L"Add Task";
			this->btnAddTask->UseVisualStyleBackColor = false;
			this->btnAddTask->Click += gcnew System::EventHandler(this, &UserTasks::btnAddTask_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(356, 96);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(110, 28);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Task Date";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(181, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 34);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Priority";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(26, 98);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 34);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Task Name";
			// 
			// dtbTaskDate
			// 
			this->dtbTaskDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtbTaskDate->Location = System::Drawing::Point(361, 135);
			this->dtbTaskDate->MaxDate = System::DateTime(2019, 12, 31, 0, 0, 0, 0);
			this->dtbTaskDate->MinDate = System::DateTime(2019, 12, 25, 0, 0, 0, 0);
			this->dtbTaskDate->Name = L"dtbTaskDate";
			this->dtbTaskDate->Size = System::Drawing::Size(133, 22);
			this->dtbTaskDate->TabIndex = 2;
			this->dtbTaskDate->Value = System::DateTime(2019, 12, 25, 0, 0, 0, 0);
			// 
			// cbAddTaskPriority
			// 
			this->cbAddTaskPriority->BackColor = System::Drawing::Color::LavenderBlush;
			this->cbAddTaskPriority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbAddTaskPriority->FormattingEnabled = true;
			this->cbAddTaskPriority->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10"
			});
			this->cbAddTaskPriority->Location = System::Drawing::Point(187, 133);
			this->cbAddTaskPriority->Name = L"cbAddTaskPriority";
			this->cbAddTaskPriority->Size = System::Drawing::Size(121, 24);
			this->cbAddTaskPriority->TabIndex = 1;
			// 
			// txtTaskNameAdd
			// 
			this->txtTaskNameAdd->Location = System::Drawing::Point(32, 135);
			this->txtTaskNameAdd->Name = L"txtTaskNameAdd";
			this->txtTaskNameAdd->Size = System::Drawing::Size(130, 22);
			this->txtTaskNameAdd->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabPage2.BackgroundImage")));
			this->tabPage2->Controls->Add(this->cbShowTaskDate);
			this->tabPage2->Controls->Add(this->btnShowTodayTasks);
			this->tabPage2->Controls->Add(this->btnShowAllTasks);
			this->tabPage2->Controls->Add(this->dgShowTasks);
			this->tabPage2->Location = System::Drawing::Point(4, 46);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(566, 449);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Show Tasks";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Enter += gcnew System::EventHandler(this, &UserTasks::tabPage2_Enter);
			// 
			// cbShowTaskDate
			// 
			this->cbShowTaskDate->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbShowTaskDate->FormattingEnabled = true;
			this->cbShowTaskDate->Location = System::Drawing::Point(26, 50);
			this->cbShowTaskDate->Name = L"cbShowTaskDate";
			this->cbShowTaskDate->Size = System::Drawing::Size(121, 24);
			this->cbShowTaskDate->TabIndex = 3;
			// 
			// btnShowTodayTasks
			// 
			this->btnShowTodayTasks->BackColor = System::Drawing::Color::LavenderBlush;
			this->btnShowTodayTasks->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnShowTodayTasks->Location = System::Drawing::Point(8, 282);
			this->btnShowTodayTasks->Name = L"btnShowTodayTasks";
			this->btnShowTodayTasks->Size = System::Drawing::Size(153, 48);
			this->btnShowTodayTasks->TabIndex = 2;
			this->btnShowTodayTasks->Text = L"Show Today Tasks";
			this->btnShowTodayTasks->UseVisualStyleBackColor = false;
			this->btnShowTodayTasks->Click += gcnew System::EventHandler(this, &UserTasks::btnShowTodayTasks_Click);
			// 
			// btnShowAllTasks
			// 
			this->btnShowAllTasks->BackColor = System::Drawing::Color::LavenderBlush;
			this->btnShowAllTasks->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnShowAllTasks->Location = System::Drawing::Point(26, 107);
			this->btnShowAllTasks->Name = L"btnShowAllTasks";
			this->btnShowAllTasks->Size = System::Drawing::Size(121, 36);
			this->btnShowAllTasks->TabIndex = 1;
			this->btnShowAllTasks->Text = L"Show Tasks";
			this->btnShowAllTasks->UseVisualStyleBackColor = false;
			this->btnShowAllTasks->Click += gcnew System::EventHandler(this, &UserTasks::btnShowAllTasks_Click);
			// 
			// dgShowTasks
			// 
			this->dgShowTasks->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgShowTasks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgShowTasks->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->TaskName,
					this->Priority, this->TaskDate
			});
			this->dgShowTasks->Location = System::Drawing::Point(167, 3);
			this->dgShowTasks->Name = L"dgShowTasks";
			this->dgShowTasks->RowTemplate->Height = 24;
			this->dgShowTasks->Size = System::Drawing::Size(404, 461);
			this->dgShowTasks->TabIndex = 0;
			// 
			// TaskName
			// 
			this->TaskName->HeaderText = L"Task Name";
			this->TaskName->Name = L"TaskName";
			this->TaskName->ReadOnly = true;
			// 
			// Priority
			// 
			this->Priority->HeaderText = L"Priority";
			this->Priority->Name = L"Priority";
			this->Priority->ReadOnly = true;
			// 
			// TaskDate
			// 
			this->TaskDate->HeaderText = L"Task Date";
			this->TaskDate->Name = L"TaskDate";
			this->TaskDate->ReadOnly = true;
			// 
			// tabPage3
			// 
			this->tabPage3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabPage3.BackgroundImage")));
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Controls->Add(this->label5);
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Controls->Add(this->btnUpdate);
			this->tabPage3->Controls->Add(this->dtpUpdateTaskDate);
			this->tabPage3->Controls->Add(this->cbUpdateTaskPriority);
			this->tabPage3->Controls->Add(this->cbTaskName);
			this->tabPage3->Location = System::Drawing::Point(4, 46);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(566, 449);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Update Task";
			this->tabPage3->UseVisualStyleBackColor = true;
			this->tabPage3->Enter += gcnew System::EventHandler(this, &UserTasks::tabPage3_Enter);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Magneto", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(354, 87);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(145, 28);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Task Date";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Magneto", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(195, 87);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(117, 28);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Priority";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Magneto", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(19, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(160, 28);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Task Name";
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::Color::LavenderBlush;
			this->btnUpdate->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnUpdate->Location = System::Drawing::Point(233, 207);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(86, 39);
			this->btnUpdate->TabIndex = 3;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &UserTasks::btnUpdate_Click);
			// 
			// dtpUpdateTaskDate
			// 
			this->dtpUpdateTaskDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpUpdateTaskDate->Location = System::Drawing::Point(361, 118);
			this->dtpUpdateTaskDate->MaxDate = System::DateTime(2019, 12, 31, 0, 0, 0, 0);
			this->dtpUpdateTaskDate->MinDate = System::DateTime(2019, 12, 25, 0, 0, 0, 0);
			this->dtpUpdateTaskDate->Name = L"dtpUpdateTaskDate";
			this->dtpUpdateTaskDate->Size = System::Drawing::Size(138, 22);
			this->dtpUpdateTaskDate->TabIndex = 2;
			this->dtpUpdateTaskDate->Value = System::DateTime(2019, 12, 25, 0, 0, 0, 0);
			// 
			// cbUpdateTaskPriority
			// 
			this->cbUpdateTaskPriority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbUpdateTaskPriority->FormattingEnabled = true;
			this->cbUpdateTaskPriority->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10"
			});
			this->cbUpdateTaskPriority->Location = System::Drawing::Point(200, 118);
			this->cbUpdateTaskPriority->Name = L"cbUpdateTaskPriority";
			this->cbUpdateTaskPriority->Size = System::Drawing::Size(121, 24);
			this->cbUpdateTaskPriority->TabIndex = 1;
			// 
			// cbTaskName
			// 
			this->cbTaskName->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbTaskName->FormattingEnabled = true;
			this->cbTaskName->Location = System::Drawing::Point(24, 120);
			this->cbTaskName->Name = L"cbTaskName";
			this->cbTaskName->Size = System::Drawing::Size(145, 24);
			this->cbTaskName->TabIndex = 0;
			// 
			// tabPage4
			// 
			this->tabPage4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabPage4.BackgroundImage")));
			this->tabPage4->Controls->Add(this->dgShowEndTasks);
			this->tabPage4->Controls->Add(this->btnEndTask);
			this->tabPage4->Controls->Add(this->cbEndTasksName);
			this->tabPage4->Location = System::Drawing::Point(4, 46);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(566, 449);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"End Task";
			this->tabPage4->UseVisualStyleBackColor = true;
			this->tabPage4->Enter += gcnew System::EventHandler(this, &UserTasks::tabPage4_Enter);
			// 
			// dgShowEndTasks
			// 
			this->dgShowEndTasks->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgShowEndTasks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgShowEndTasks->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->EndTasks });
			this->dgShowEndTasks->Location = System::Drawing::Point(368, 3);
			this->dgShowEndTasks->Name = L"dgShowEndTasks";
			this->dgShowEndTasks->RowTemplate->Height = 24;
			this->dgShowEndTasks->Size = System::Drawing::Size(236, 446);
			this->dgShowEndTasks->TabIndex = 2;
			// 
			// EndTasks
			// 
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Strikeout)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->EndTasks->DefaultCellStyle = dataGridViewCellStyle2;
			this->EndTasks->HeaderText = L"End Tasks";
			this->EndTasks->Name = L"EndTasks";
			this->EndTasks->ReadOnly = true;
			// 
			// btnEndTask
			// 
			this->btnEndTask->BackColor = System::Drawing::Color::LavenderBlush;
			this->btnEndTask->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnEndTask->Location = System::Drawing::Point(152, 149);
			this->btnEndTask->Name = L"btnEndTask";
			this->btnEndTask->Size = System::Drawing::Size(99, 39);
			this->btnEndTask->TabIndex = 1;
			this->btnEndTask->Text = L"End Task";
			this->btnEndTask->UseVisualStyleBackColor = false;
			this->btnEndTask->Click += gcnew System::EventHandler(this, &UserTasks::btnEndTask_Click);
			// 
			// cbEndTasksName
			// 
			this->cbEndTasksName->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbEndTasksName->FormattingEnabled = true;
			this->cbEndTasksName->Location = System::Drawing::Point(50, 75);
			this->cbEndTasksName->Name = L"cbEndTasksName";
			this->cbEndTasksName->Size = System::Drawing::Size(254, 24);
			this->cbEndTasksName->TabIndex = 0;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->txtMinutes);
			this->tabPage5->Controls->Add(this->txtHours);
			this->tabPage5->Controls->Add(this->btnReminder);
			this->tabPage5->Location = System::Drawing::Point(4, 46);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(566, 449);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Reminder";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// txtMinutes
			// 
			this->txtMinutes->Location = System::Drawing::Point(312, 206);
			this->txtMinutes->Name = L"txtMinutes";
			this->txtMinutes->Size = System::Drawing::Size(100, 22);
			this->txtMinutes->TabIndex = 2;
			// 
			// txtHours
			// 
			this->txtHours->Location = System::Drawing::Point(163, 206);
			this->txtHours->Name = L"txtHours";
			this->txtHours->Size = System::Drawing::Size(100, 22);
			this->txtHours->TabIndex = 1;
			// 
			// btnReminder
			// 
			this->btnReminder->Location = System::Drawing::Point(249, 268);
			this->btnReminder->Name = L"btnReminder";
			this->btnReminder->Size = System::Drawing::Size(75, 23);
			this->btnReminder->TabIndex = 0;
			this->btnReminder->Text = L"button1";
			this->btnReminder->UseVisualStyleBackColor = true;
			this->btnReminder->Click += gcnew System::EventHandler(this, &UserTasks::btnReminder_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &UserTasks::backgroundWorker1_DoWork);
			// 
			// Reminder
			// 
			this->Reminder->Enabled = true;
			this->Reminder->Interval = 60000;
			this->Reminder->Tick += gcnew System::EventHandler(this, &UserTasks::Reminder_Tick_1);
			// 
			// UserTasks
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(713, 639);
			this->Controls->Add(this->tabControl1);
			this->Name = L"UserTasks";
			this->Text = L"UserTasks";
			this->Load += gcnew System::EventHandler(this, &UserTasks::UserTasks_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgShowTasks))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgShowEndTasks))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



	private: System::Void btnAddTask_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 if (txtTaskNameAdd->Text == "" || cbAddTaskPriority->Text == "")
					 MessageBox::Show("Please Enter The Task Name And Priority");
				 else
				 {
					 DateTime t = t.Now;
					 string currentDate = cc.StringTostring(t.ToString("MM/dd/yyyy"));
					 string name = cc.StringTostring(txtTaskNameAdd->Text);
					 int priority = Convert::ToInt32(cbAddTaskPriority->Text);
					 string date = cc.StringTostring((dtbTaskDate->Value).ToString("MM/dd/yyyy"));
					 user.AddNewTask(name, priority, date, currentDate);
					 s.insert(date);
				 }
				 txtTaskNameAdd->Text = "";
				 cbAddTaskPriority->SelectedIndex = -1;

	}

			 Conversions cc;
			 array<String ^> ^ FillComboBoxNames()
			 {
				 array<String ^> ^ names = gcnew array<String ^>(user.userTasks.size());
				 for (int i = 0; i < user.userTasks.size(); i++)
					 names[i] = cc.stringToString(user.userTasks[i].taskName);
				 return names;

			 }
			 array<String^> ^FillComboBoxDates()
			 {
				 array<String^> ^ TaskDates = gcnew array<String^>(s.size());
				 int i = 0;

				 if (!s.empty())
				 for (auto it = s.begin(); it != s.end(); ++it)
				 {
					 TaskDates[i] = cc.stringToString(*it);
					 i++;
				 }
				 return TaskDates;
			 }

			 array<String^> ^ FillComboBoxEndTasks()
			 {
				 array<String^> ^ EndTasksNames = gcnew array<String^>(user.TodayTasks.Size());
				 user.temp = user.TodayTasks;
				 int i = 0;
				 while (!user.temp.Empty())
				 {
					 EndTasksNames[i] = cc.stringToString(user.temp.Top().taskName);
					 user.temp.Pop();
					 i++;
				 }
				 return EndTasksNames;

			 }

			 void ShowTodayTasks()
			 {
				 user.temp = user.TodayTasks;
				 if (user.temp.Empty())
					 MessageBox::Show("There Is No Tasks Today");
				 else
				 {
					 dgShowTasks->Rows->Add(user.temp.Size());
					 int i = 0;
					 while (!user.temp.Empty())
					 {
						 dgShowTasks->Rows[i]->Cells[0]->Value = cc.stringToString(user.temp.Top().taskName);
						 dgShowTasks->Rows[i]->Cells[1]->Value = user.temp.Top().taskPriority.ToString();
						 dgShowTasks->Rows[i]->Cells[2]->Value = cc.stringToString(user.temp.Top().taskDate);
						 i++;
						 user.temp.Pop();
					 }
				 }
			 }
			 void ShowTasksByDate()
			 {
				 string date = cc.StringTostring(cbShowTaskDate->Text);
				 user.Filteration(date);
				 if (user.temp.Empty())
				 {
					 MessageBox::Show("There Is No Tasks in That Date");
					 s.erase(date);
				 }
				 else
				 {
					 dgShowTasks->Rows->Add(user.temp.Size());
					 int i = 0;
					 while (!user.temp.Empty())
					 {
						 dgShowTasks->Rows[i]->Cells[0]->Value = cc.stringToString(user.temp.Top().taskName);
						 dgShowTasks->Rows[i]->Cells[1]->Value = user.temp.Top().taskPriority.ToString();
						 dgShowTasks->Rows[i]->Cells[2]->Value = cc.stringToString(user.temp.Top().taskDate);
						 i++;
						 user.temp.Pop();
					 }
				 }
			 }

			 void UpdateTask()
			 {
				 DateTime t = t.Now;
				 string name = cc.StringTostring(cbTaskName->Text);
				 int newPriority = Convert::ToInt32(cbUpdateTaskPriority->Text);
				 string newDate = cc.StringTostring((dtpUpdateTaskDate->Value).ToString("MM/dd/yyyy"));
				 string currentDate = cc.StringTostring(t.ToString("MM/dd/yyyy"));

				 user.UpdateTodayTask(name, newPriority, newDate, currentDate);
				 s.insert(newDate);

			 }

	private: System::Void btnShowAllTasks_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 dgShowTasks->Rows->Clear();
				 cbTaskName->Items->Clear();
				 ShowTasksByDate();

	}

	private: System::Void tabPage3_Enter(System::Object^  sender, System::EventArgs^  e)
	{
				 cbTaskName->Items->Clear();
				 array<String ^> ^ TaskNames = FillComboBoxNames();
				 cbTaskName->Items->AddRange(TaskNames);
	}
	private: System::Void tabPage2_Enter(System::Object^  sender, System::EventArgs^  e)
	{
				 dgShowTasks->Rows->Clear();
				 cbShowTaskDate->Items->Clear();
				 array<String^> ^ TaskDates = FillComboBoxDates();

				 cbShowTaskDate->Items->AddRange(TaskDates);

	}
	private: System::Void btnShowTodayTasks_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 dgShowTasks->Rows->Clear();
				 cbTaskName->Items->Clear();
				 ShowTodayTasks();

	}
	private: System::Void btnUpdate_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 if (cbUpdateTaskPriority->Text == "" || cbTaskName->Text == "")
					 MessageBox::Show("Please Enter The Task Name And Priority");
				 else
				 {
					 UpdateTask();
				 }
				 cbTaskName->SelectedIndex = -1;
				 cbUpdateTaskPriority->SelectedIndex = -1;
	}

	private: System::Void tabPage4_Enter(System::Object^  sender, System::EventArgs^  e)
	{
				 cbEndTasksName->Items->Clear();
				 array<String ^> ^ EndTasksName = FillComboBoxEndTasks();
				 cbEndTasksName->Items->AddRange(EndTasksName);
	}
	private: System::Void btnEndTask_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 if (cbEndTasksName->Text == "")
					 MessageBox::Show("Please Choose Task Name");
				 else
				 {
					 dgShowEndTasks->Rows->Clear();
					 string name = cc.StringTostring(cbEndTasksName->Text);
					 user.EndTodayTask(name);
					 cbEndTasksName->Items->Clear();
					 array<String ^> ^ EndTasksName = FillComboBoxEndTasks();
					 cbEndTasksName->Items->AddRange(EndTasksName);
					 user.EndTasksName.push_back(name);

					 dgShowEndTasks->Rows->Add(user.EndTasksName.size());
					 for (int i = 0; i < user.EndTasksName.size(); i++)
					 {
						 dgShowEndTasks->Rows[i]->Cells[0]->Value = cc.stringToString(user.EndTasksName[i]);
					 }
				 if (user.TodayTasks.Empty())
				 {
					 MessageBox::Show("Hey Mama!\n Has Anyone Told You That You Are Doing An Awesome Job");
					 XXOO^ xo = gcnew XXOO();
					 xo->ShowDialog();
				 }

				 }
	}
	private: System::Void Reminder_Tick(System::Object^  sender, System::EventArgs^  e)
	{
				 if (!user.TodayTasks.Empty())
					 MessageBox::Show("you have to finish " + cc.stringToString(user.TodayTasks.Top().taskName));
	}
	private: System::Void btnReminder_Click(System::Object^  sender, System::EventArgs^  e)
	{
				/* Reminder r;
		    r.GetTime(Convert::ToInt32(txtHours->Text), Convert::ToInt32(txtMinutes->Text));*/
			
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
				 /*Reminder m;
				 m.StartReminder();*/
	}
		public: User GetUpdatedUser()
			 {
				 return user;
			 }
private: System::Void Reminder_Tick_1(System::Object^  sender, System::EventArgs^  e)
{
			 if (!user.TodayTasks.Empty())
			 MessageBox::Show("You have to finish " + cc.stringToString(user.TodayTasks.Top().taskName));
}
private: System::Void UserTasks_Load(System::Object^  sender, System::EventArgs^  e) 
{
			 /*DateTime t = t.Now;
			 dtbTaskDate->Value = t;*/
			 dtbTaskDate->MinDate = dtbTaskDate->Value.Now;
			 dtpUpdateTaskDate->MinDate = dtpUpdateTaskDate->Value.Now;
}
};
}