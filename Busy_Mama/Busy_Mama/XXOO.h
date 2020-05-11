#pragma once

namespace Busy_Mama {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for XXOO
	/// </summary>
	public ref class XXOO : public System::Windows::Forms::Form
	{
	public:
		int click1, turn, click2, click3, click4, click5, click6, click7, click8, click9, player2, player1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  displayturn;
	public:

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  player1score;
	private: System::Windows::Forms::Label^  player2score;
	private: System::Windows::Forms::Button^  btn_play;
	private: System::Windows::Forms::Button^  btn_reset;



	private: System::Windows::Forms::Label^  label3;

	public: XXOO(void)
	{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
				click1 = 0;
				click2 = 0;
				click3 = 0;
				click4 = 0;
				click5 = 0;
				click6 = 0;
				click7 = 0;
				click8 = 0;
				click9 = 0;
				player1 = 0;
				player2 = 0;
				turn = 1;
	}
	public: void reset()
	{
				turn = 1;
				click1 = 0;
				click2 = 0;
				click3 = 0;
				click4 = 0;
				click5 = 0;
				click6 = 0;
				click7 = 0;
				click8 = 0;
				click9 = 0;
				player1 = 0;
				player2 = 0;
				displayturn->Text = "";
				button1->BackColor = Color::LightGray;
				//button1->ForeColor = Color::LightGray;
				button1->Text = "";
				button2->BackColor = Color::LightGray;
				button2->Text = "";
				//button2->ForeColor = Color::LightGray;
				button3->BackColor = Color::LightGray;
				//button3->ForeColor = Color::Gray;
				button3->Text = "";
				button4->BackColor = Color::LightGray;
				//button4->ForeColor = Color::White;
				button4->Text = "";
				button5->BackColor = Color::LightGray;
				//button5->ForeColor = Color::White;
				button5->Text = "";
				button6->BackColor = Color::LightGray;
				//button6->ForeColor = Color::White;
				button6->Text = "";
				button7->BackColor = Color::LightGray;
				//button7->ForeColor = Color::White;
				button7->Text = "";
				button8->BackColor = Color::LightGray;
				//button8->ForeColor = Color::White;
				button8->Text = "";
				button9->BackColor = Color::LightGray;
				//button9->ForeColor = Color::White;
				button9->Text = "";
				player1score->Text = "";
				player2score->Text = "";
	}
	public: void cleargame()
	{
				displayturn->Text = "";
				turn = 1;
				click1 = 0;
				click2 = 0;
				click3 = 0;
				click4 = 0;
				click5 = 0;
				click6 = 0;
				click7 = 0;
				click8 = 0;
				click9 = 0;
				button1->BackColor = Color::LightGray;
				//button1->ForeColor = Color::LightGray;
				button1->Text = "";
				button2->BackColor = Color::LightGray;
				button2->Text = "";
				//button2->ForeColor = Color::LightGray;
				button3->BackColor = Color::LightGray;
				//button3->ForeColor = Color::Gray;
				button3->Text = "";
				button4->BackColor = Color::LightGray;
				//button4->ForeColor = Color::White;
				button4->Text = "";
				button5->BackColor = Color::LightGray;
				//button5->ForeColor = Color::White;
				button5->Text = "";
				button6->BackColor = Color::LightGray;
				//button6->ForeColor = Color::White;
				button6->Text = "";
				button7->BackColor = Color::LightGray;
				//button7->ForeColor = Color::White;
				button7->Text = "";
				button8->BackColor = Color::LightGray;
				//button8->ForeColor = Color::White;
				button8->Text = "";
				button9->BackColor = Color::LightGray;
				//button9->ForeColor = Color::White;
				button9->Text = "";
				//player1score->Text = "";

	}
	public: void checkit()
	{
				if (button1->Text != "" && button2->Text != "" && button3->Text != "")
				{
					if (button1->Text == button2->Text && button1->Text == button3->Text)
					{

						button1->BackColor = Color::Green;
						button1->ForeColor = Color::White;
						button2->BackColor = Color::Green;
						button2->ForeColor = Color::White;
						button3->BackColor = Color::Green;
						button3->ForeColor = Color::White;
						if (button1->Text == "X")
						{
							MessageBox::Show("Player 1 Wins!");
							player1++;
							player1score->Text = player1.ToString();

						}
						else
						{
							MessageBox::Show("Player 2 Wins!");
							player2++;
							player2score->Text = player2.ToString();
						}
						//cleargame();
					}
				}
				if (button4->Text != "" && button5->Text != "" && button6->Text != "")
				{
					if (button4->Text == button5->Text && button4->Text == button6->Text)
					{

						button4->BackColor = Color::Green;
						button4->ForeColor = Color::White;
						button5->BackColor = Color::Green;
						button5->ForeColor = Color::White;
						button6->BackColor = Color::Green;
						button6->ForeColor = Color::White;
						if (button4->Text == "X")
						{
							MessageBox::Show("Player 1 Wins!");
							player1++;
							player1score->Text = player1.ToString();
						}
						else
						{
							MessageBox::Show("Player 2 Wins!");
							player2++;
							player2score->Text = player2.ToString();
						}
						//cleargame();
					}
				}
				if (button7->Text != "" && button8->Text != "" && button9->Text != "")
				{
					if (button7->Text == button8->Text && button7->Text == button9->Text)
					{

						button7->BackColor = Color::Green;
						button7->ForeColor = Color::White;
						button8->BackColor = Color::Green;
						button8->ForeColor = Color::White;
						button9->BackColor = Color::Green;
						button9->ForeColor = Color::White;
						if (button7->Text == "X")
						{
							MessageBox::Show("Player 1 Wins!");
							player1++;
							player1score->Text = player1.ToString();
						}
						else
						{
							MessageBox::Show("Player 2 Wins!");
							player2++;
							player2score->Text = player2.ToString();
						}
						//cleargame();
					}
				}
				if (button1->Text != "" && button4->Text != "" && button7->Text != "")
				{
					if (button1->Text == button4->Text && button1->Text == button7->Text)
					{

						button1->BackColor = Color::Green;
						button1->ForeColor = Color::White;
						button4->BackColor = Color::Green;
						button4->ForeColor = Color::White;
						button7->BackColor = Color::Green;
						button7->ForeColor = Color::White;
						if (button1->Text == "X")
						{
							MessageBox::Show("Player 1 Wins!");
							player1++;
							player1score->Text = player1.ToString();
						}
						else
						{
							MessageBox::Show("Player 2 Wins!");
							player2++;
							player2score->Text = player2.ToString();
						}
						//cleargame();
					}
				}
				if (button2->Text != "" && button5->Text != "" && button8->Text != "")
				{
					if (button2->Text == button5->Text && button2->Text == button8->Text)
					{

						button2->BackColor = Color::Green;
						button2->ForeColor = Color::White;
						button5->BackColor = Color::Green;
						button5->ForeColor = Color::White;
						button8->BackColor = Color::Green;
						button8->ForeColor = Color::White;
						if (button2->Text == "X")
						{
							MessageBox::Show("Player 1 Wins!");
							player1++;
							player1score->Text = player1.ToString();
						}
						else
						{
							MessageBox::Show("Player 2 Wins!");
							player2++;
							player2score->Text = player2.ToString();
						}
						//cleargame();
					}
				}
				if (button3->Text != "" && button6->Text != "" && button9->Text != "")
				{
					if (button3->Text == button6->Text && button3->Text == button9->Text)
					{

						button3->BackColor = Color::Green;
						button3->ForeColor = Color::White;
						button6->BackColor = Color::Green;
						button6->ForeColor = Color::White;
						button9->BackColor = Color::Green;
						button9->ForeColor = Color::White;
						if (button3->Text == "X")
						{
							MessageBox::Show("Player 1 Wins!");
							player1++;
							player1score->Text = player1.ToString();
						}
						else
						{
							MessageBox::Show("Player 2 Wins!");
							player2++;
							player2score->Text = player2.ToString();
						}
						//cleargame();
					}
				}
				if (button1->Text != "" && button5->Text != "" && button9->Text != "")
				{
					if (button1->Text == button5->Text && button1->Text == button9->Text)
					{

						button1->BackColor = Color::Green;
						button1->ForeColor = Color::White;
						button5->BackColor = Color::Green;
						button5->ForeColor = Color::White;
						button9->BackColor = Color::Green;
						button9->ForeColor = Color::White;
						if (button1->Text == "X")
						{
							MessageBox::Show("Player 1 Wins!");
							player1++;
							player1score->Text = player1.ToString();
						}
						else
						{
							MessageBox::Show("Player 2 Wins!");
							player2++;
							player2score->Text = player2.ToString();
						}
						//cleargame();
					}
				}
				if (button3->Text != "" && button5->Text != "" && button7->Text != "")
				{
					if (button3->Text == button5->Text && button3->Text == button7->Text)
					{

						button3->BackColor = Color::Green;
						button3->ForeColor = Color::White;
						button5->BackColor = Color::Green;
						button5->ForeColor = Color::White;
						button7->BackColor = Color::Green;
						button7->ForeColor = Color::White;
						if (button3->Text == "X")
						{
							MessageBox::Show("Player 1 Wins!");
							player1++;
							player1score->Text = player1.ToString();
						}
						else
						{
							MessageBox::Show("Player 2 Wins!");
							player2++;
							player2score->Text = player2.ToString();
						}
						//cleargame();
					}
				}
	}

	public: void display()
	{
				if (turn % 2 != 0)
				{
					displayturn->Text = "Player 1";
				}
				else
				{
					displayturn->Text = "Player 2";
				}
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~XXOO()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->displayturn = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->player1score = (gcnew System::Windows::Forms::Label());
			this->player2score = (gcnew System::Windows::Forms::Label());
			this->btn_play = (gcnew System::Windows::Forms::Button());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightGray;
			this->button1->Location = System::Drawing::Point(44, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 60);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &XXOO::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightGray;
			this->button2->Location = System::Drawing::Point(143, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 60);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &XXOO::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LightGray;
			this->button3->Location = System::Drawing::Point(245, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 60);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &XXOO::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightGray;
			this->button4->Location = System::Drawing::Point(44, 78);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 59);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &XXOO::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LightGray;
			this->button5->Location = System::Drawing::Point(143, 78);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 59);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &XXOO::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::LightGray;
			this->button6->Location = System::Drawing::Point(245, 78);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 59);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &XXOO::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::LightGray;
			this->button7->Location = System::Drawing::Point(44, 143);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 56);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &XXOO::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::LightGray;
			this->button8->Location = System::Drawing::Point(143, 143);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 56);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &XXOO::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::LightGray;
			this->button9->Location = System::Drawing::Point(245, 143);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 56);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &XXOO::button9_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->BackColor = System::Drawing::Color::DarkCyan;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(465, 119);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 33);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Turn";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// displayturn
			// 
			this->displayturn->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->displayturn->Location = System::Drawing::Point(465, 152);
			this->displayturn->Name = L"displayturn";
			this->displayturn->Size = System::Drawing::Size(111, 45);
			this->displayturn->TabIndex = 10;
			this->displayturn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::IndianRed;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(370, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 39);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Player1";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::IndianRed;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(538, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 39);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Player2";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// player1score
			// 
			this->player1score->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->player1score->Location = System::Drawing::Point(370, 59);
			this->player1score->Name = L"player1score";
			this->player1score->Size = System::Drawing::Size(119, 45);
			this->player1score->TabIndex = 13;
			this->player1score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// player2score
			// 
			this->player2score->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->player2score->Location = System::Drawing::Point(538, 59);
			this->player2score->Name = L"player2score";
			this->player2score->Size = System::Drawing::Size(119, 45);
			this->player2score->TabIndex = 14;
			this->player2score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_play
			// 
			this->btn_play->BackColor = System::Drawing::SystemColors::Highlight;
			this->btn_play->Location = System::Drawing::Point(437, 225);
			this->btn_play->Name = L"btn_play";
			this->btn_play->Size = System::Drawing::Size(139, 61);
			this->btn_play->TabIndex = 16;
			this->btn_play->Text = L"Play Again";
			this->btn_play->UseVisualStyleBackColor = false;
			this->btn_play->Click += gcnew System::EventHandler(this, &XXOO::btn_play_Click);
			// 
			// btn_reset
			// 
			this->btn_reset->BackColor = System::Drawing::SystemColors::HotTrack;
			this->btn_reset->Location = System::Drawing::Point(159, 226);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(139, 60);
			this->btn_reset->TabIndex = 17;
			this->btn_reset->Text = L"Reset Game";
			this->btn_reset->UseVisualStyleBackColor = false;
			this->btn_reset->Click += gcnew System::EventHandler(this, &XXOO::btn_reset_Click);
			// 
			// XXOO
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(711, 336);
			this->Controls->Add(this->btn_reset);
			this->Controls->Add(this->btn_play);
			this->Controls->Add(this->player2score);
			this->Controls->Add(this->player1score);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->displayturn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"XXOO";
			this->Text = L"XXOO";
			this->ResumeLayout(false);

		}
#pragma endregion
		//int click1 = 0, turn = 1;
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (click1 == 0)
				 {
					 if (turn % 2 != 0)
					 {
						 button1->Text = "X";
					 }
					 else
					 {
						 button1->Text = "O";
					 }
					 turn++;
					 click1++;
				 }
				 else
				 {
					 button1->Text = button1->Text;
				 }
				 display();
				 checkit();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (click2 == 0)
				 {
					 if (turn % 2 != 0)
					 {
						 button2->Text = "X";
					 }
					 else
					 {
						 button2->Text = "O";
					 }
					 turn++;
					 click2++;
				 }
				 else
				 {
					 button2->Text = button2->Text;
				 }
				 display();
				 checkit();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (click3 == 0)
				 {
					 if (turn % 2 != 0)
					 {
						 button3->Text = "X";
					 }
					 else
					 {
						 button3->Text = "O";
					 }
					 turn++;
					 click3++;
				 }
				 else
				 {
					 button3->Text = button3->Text;
				 }
				 display();
				 checkit();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (click4 == 0)
				 {
					 if (turn % 2 != 0)
					 {
						 button4->Text = "X";
					 }
					 else
					 {
						 button4->Text = "O";
					 }
					 turn++;
					 click4++;
				 }
				 else
				 {
					 button4->Text = button4->Text;
				 }
				 display();
				 checkit();
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (click5 == 0)
				 {
					 if (turn % 2 != 0)
					 {
						 button5->Text = "X";
					 }
					 else
					 {
						 button5->Text = "O";
					 }
					 turn++;
					 click5++;
				 }
				 else
				 {
					 button5->Text = button5->Text;
				 }
				 display();
				 checkit();
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (click6 == 0)
				 {
					 if (turn % 2 != 0)
					 {
						 button6->Text = "X";
					 }
					 else
					 {
						 button6->Text = "O";
					 }
					 turn++;
					 click6++;
				 }
				 else
				 {
					 button6->Text = button6->Text;
				 }
				 display();
				 checkit();
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (click7 == 0)
				 {
					 if (turn % 2 != 0)
					 {
						 button7->Text = "X";
					 }
					 else
					 {
						 button7->Text = "O";
					 }
					 turn++;
					 click7++;
				 }
				 else
				 {
					 button7->Text = button7->Text;
				 }
				 display();
				 checkit();
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (click8 == 0)
				 {
					 if (turn % 2 != 0)
					 {
						 button8->Text = "X";
					 }
					 else
					 {
						 button8->Text = "O";
					 }
					 turn++;
					 click8++;
				 }
				 else
				 {
					 button8->Text = button8->Text;
				 }
				 display();
				 checkit();
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (click9 == 0)
				 {
					 if (turn % 2 != 0)
					 {
						 button9->Text = "X";
					 }
					 else
					 {
						 button9->Text = "O";
					 }
					 turn++;
					 click9++;
				 }
				 else
				 {
					 button9->Text = button9->Text;
				 }
				 display();
				 checkit();
	}

	private: System::Void btn_play_Click(System::Object^  sender, System::EventArgs^  e) {
				 cleargame();
	}
	private: System::Void btn_reset_Click(System::Object^  sender, System::EventArgs^  e) {
				 reset();
	}
	};
}
