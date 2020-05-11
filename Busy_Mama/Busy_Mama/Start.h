#pragma once

#include"UserLogin.h"

namespace Busy_Mama {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Start
	/// </summary>
	public ref class Start : public System::Windows::Forms::Form
	{
	public:
		Start(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Start()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Start::typeid));
			this->SuspendLayout();
			// 
			// Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(713, 639);
			this->Name = L"Start";
			this->Text = L"Start";
			this->Load += gcnew System::EventHandler(this, &Start::Start_Load);
			this->Shown += gcnew System::EventHandler(this, &Start::Start_Shown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Start_Load(System::Object^  sender, System::EventArgs^  e)
	{
				
	}
			
	
	private: System::Void Start_Shown(System::Object^  sender, System::EventArgs^  e) 
	{
				 Sleep(3000);

				 this->Hide();
				 UserLogin^ userLogin = gcnew UserLogin();
				 userLogin->ShowDialog();
	}
	};
}
