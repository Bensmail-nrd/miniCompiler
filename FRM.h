#include"Code.h"
#include"FRM_abt.h"
#include"lex_result.h"
#include"syn_result.h"
namespace FINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for FRM
	/// </summary>
	public ref class FRM : public System::Windows::Forms::Form
	{
	public:
		int move, movx, movy;

		bool etat_lex, etat_syn, etat_gen;
	private: System::Windows::Forms::Button^ button1;
	private: Bunifu::Framework::UI::BunifuElipse^ bunifuElipse1;
	private: Bunifu::Framework::UI::BunifuElipse^ bunifuElipse2;
	public:
	private: System::Windows::Forms::FontDialog^ fontDialog1;
	public:
		FRM(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Home->BringToFront();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FRM()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ textCode;
	private: System::Windows::Forms::Panel^ navbar;


	private: System::Windows::Forms::Button^ btn_save;

	private: System::Windows::Forms::Button^ btn_open;
	private: System::Windows::Forms::Panel^ pnl_yes_lex;
	private: System::Windows::Forms::Panel^ pnl_no_syn;


	private: System::Windows::Forms::Button^ btn_view_lex;
	private: System::Windows::Forms::Button^ btn_view_syn;
	private: System::Windows::Forms::Panel^ pnl_yes_syn;





	private: System::Windows::Forms::Panel^ pnl_no_lex;
	private: System::Windows::Forms::Button^ btn_abt;

	private: System::Windows::Forms::Button^ btn_exit;

	private: System::Windows::Forms::Panel^ Principale;
	private: System::Windows::Forms::Panel^ Home;
	private: System::Windows::Forms::Button^ btn_end;
	private: System::Windows::Forms::Button^ btn_about;
	private: System::Windows::Forms::Button^ btn_start;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;





















	protected:
	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FRM::typeid));
			this->navbar = (gcnew System::Windows::Forms::Panel());
			this->btn_abt = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->btn_save = (gcnew System::Windows::Forms::Button());
			this->btn_open = (gcnew System::Windows::Forms::Button());
			this->textCode = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pnl_yes_lex = (gcnew System::Windows::Forms::Panel());
			this->pnl_no_syn = (gcnew System::Windows::Forms::Panel());
			this->btn_view_lex = (gcnew System::Windows::Forms::Button());
			this->btn_view_syn = (gcnew System::Windows::Forms::Button());
			this->pnl_yes_syn = (gcnew System::Windows::Forms::Panel());
			this->pnl_no_lex = (gcnew System::Windows::Forms::Panel());
			this->Principale = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Home = (gcnew System::Windows::Forms::Panel());
			this->btn_end = (gcnew System::Windows::Forms::Button());
			this->btn_about = (gcnew System::Windows::Forms::Button());
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->bunifuElipse1 = (gcnew Bunifu::Framework::UI::BunifuElipse(this->components));
			this->bunifuElipse2 = (gcnew Bunifu::Framework::UI::BunifuElipse(this->components));
			this->navbar->SuspendLayout();
			this->Principale->SuspendLayout();
			this->Home->SuspendLayout();
			this->SuspendLayout();
			// 
			// navbar
			// 
			this->navbar->Controls->Add(this->btn_abt);
			this->navbar->Controls->Add(this->btn_exit);
			this->navbar->Controls->Add(this->btn_save);
			this->navbar->Controls->Add(this->btn_open);
			this->navbar->Dock = System::Windows::Forms::DockStyle::Top;
			this->navbar->Location = System::Drawing::Point(0, 0);
			this->navbar->Name = L"navbar";
			this->navbar->Size = System::Drawing::Size(964, 56);
			this->navbar->TabIndex = 0;
			// 
			// btn_abt
			// 
			this->btn_abt->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_abt.BackgroundImage")));
			this->btn_abt->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_abt->FlatAppearance->BorderSize = 0;
			this->btn_abt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_abt->Location = System::Drawing::Point(847, 2);
			this->btn_abt->Name = L"btn_abt";
			this->btn_abt->Size = System::Drawing::Size(50, 50);
			this->btn_abt->TabIndex = 6;
			this->btn_abt->UseVisualStyleBackColor = true;
			this->btn_abt->Click += gcnew System::EventHandler(this, &FRM::btn_abt_Click);
			// 
			// btn_exit
			// 
			this->btn_exit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_exit.BackgroundImage")));
			this->btn_exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_exit->FlatAppearance->BorderSize = 0;
			this->btn_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_exit->Location = System::Drawing::Point(907, 2);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(50, 50);
			this->btn_exit->TabIndex = 6;
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &FRM::btn_exit_Click);
			// 
			// btn_save
			// 
			this->btn_save->BackColor = System::Drawing::Color::CadetBlue;
			this->btn_save->Dock = System::Windows::Forms::DockStyle::Left;
			this->btn_save->FlatAppearance->BorderSize = 0;
			this->btn_save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_save->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Bold));
			this->btn_save->Location = System::Drawing::Point(414, 0);
			this->btn_save->Name = L"btn_save";
			this->btn_save->Size = System::Drawing::Size(396, 56);
			this->btn_save->TabIndex = 2;
			this->btn_save->Text = L"Save";
			this->btn_save->UseVisualStyleBackColor = false;
			this->btn_save->Click += gcnew System::EventHandler(this, &FRM::btn_save_Click);
			// 
			// btn_open
			// 
			this->btn_open->BackColor = System::Drawing::Color::CadetBlue;
			this->btn_open->Dock = System::Windows::Forms::DockStyle::Left;
			this->btn_open->FlatAppearance->BorderSize = 0;
			this->btn_open->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_open->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_open->Location = System::Drawing::Point(0, 0);
			this->btn_open->Name = L"btn_open";
			this->btn_open->Size = System::Drawing::Size(414, 56);
			this->btn_open->TabIndex = 1;
			this->btn_open->Text = L"Open";
			this->btn_open->UseVisualStyleBackColor = false;
			this->btn_open->Click += gcnew System::EventHandler(this, &FRM::btn_open_Click);
			// 
			// textCode
			// 
			this->textCode->Location = System::Drawing::Point(26, 157);
			this->textCode->Name = L"textCode";
			this->textCode->Size = System::Drawing::Size(621, 458);
			this->textCode->TabIndex = 1;
			this->textCode->Text = L"";
			this->textCode->TextChanged += gcnew System::EventHandler(this, &FRM::textCode_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 25.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(27, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 49);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Code";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(680, 184);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(192, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Lexical result :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(680, 347);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(215, 32);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Syntactic result :";
			// 
			// pnl_yes_lex
			// 
			this->pnl_yes_lex->BackColor = System::Drawing::Color::Transparent;
			this->pnl_yes_lex->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_yes_lex.BackgroundImage")));
			this->pnl_yes_lex->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pnl_yes_lex->Location = System::Drawing::Point(686, 230);
			this->pnl_yes_lex->Name = L"pnl_yes_lex";
			this->pnl_yes_lex->Size = System::Drawing::Size(82, 48);
			this->pnl_yes_lex->TabIndex = 4;
			// 
			// pnl_no_syn
			// 
			this->pnl_no_syn->BackColor = System::Drawing::Color::Transparent;
			this->pnl_no_syn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_no_syn.BackgroundImage")));
			this->pnl_no_syn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pnl_no_syn->Location = System::Drawing::Point(686, 392);
			this->pnl_no_syn->Name = L"pnl_no_syn";
			this->pnl_no_syn->Size = System::Drawing::Size(82, 48);
			this->pnl_no_syn->TabIndex = 4;
			// 
			// btn_view_lex
			// 
			this->btn_view_lex->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_view_lex.BackgroundImage")));
			this->btn_view_lex->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_view_lex->FlatAppearance->BorderSize = 0;
			this->btn_view_lex->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_view_lex->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_view_lex->Location = System::Drawing::Point(774, 230);
			this->btn_view_lex->Name = L"btn_view_lex";
			this->btn_view_lex->Size = System::Drawing::Size(174, 47);
			this->btn_view_lex->TabIndex = 5;
			this->btn_view_lex->Text = L"Show result";
			this->btn_view_lex->UseVisualStyleBackColor = true;
			this->btn_view_lex->Click += gcnew System::EventHandler(this, &FRM::button1_Click_1);
			// 
			// btn_view_syn
			// 
			this->btn_view_syn->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->btn_view_syn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_view_syn.BackgroundImage")));
			this->btn_view_syn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_view_syn->FlatAppearance->BorderSize = 0;
			this->btn_view_syn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_view_syn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_view_syn->Location = System::Drawing::Point(774, 392);
			this->btn_view_syn->Name = L"btn_view_syn";
			this->btn_view_syn->Size = System::Drawing::Size(174, 48);
			this->btn_view_syn->TabIndex = 5;
			this->btn_view_syn->Text = L"Show result";
			this->btn_view_syn->UseVisualStyleBackColor = true;
			this->btn_view_syn->Click += gcnew System::EventHandler(this, &FRM::btn_view_syn_Click);
			// 
			// pnl_yes_syn
			// 
			this->pnl_yes_syn->BackColor = System::Drawing::Color::Transparent;
			this->pnl_yes_syn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_yes_syn.BackgroundImage")));
			this->pnl_yes_syn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pnl_yes_syn->Location = System::Drawing::Point(686, 392);
			this->pnl_yes_syn->Name = L"pnl_yes_syn";
			this->pnl_yes_syn->Size = System::Drawing::Size(82, 48);
			this->pnl_yes_syn->TabIndex = 4;
			// 
			// pnl_no_lex
			// 
			this->pnl_no_lex->BackColor = System::Drawing::Color::Transparent;
			this->pnl_no_lex->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_no_lex.BackgroundImage")));
			this->pnl_no_lex->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pnl_no_lex->Location = System::Drawing::Point(686, 230);
			this->pnl_no_lex->Name = L"pnl_no_lex";
			this->pnl_no_lex->Size = System::Drawing::Size(82, 48);
			this->pnl_no_lex->TabIndex = 4;
			// 
			// Principale
			// 
			this->Principale->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Principale->Controls->Add(this->button1);
			this->Principale->Controls->Add(this->textCode);
			this->Principale->Controls->Add(this->label1);
			this->Principale->Controls->Add(this->label2);
			this->Principale->Controls->Add(this->label3);
			this->Principale->Controls->Add(this->pnl_yes_syn);
			this->Principale->Controls->Add(this->pnl_no_syn);
			this->Principale->Controls->Add(this->pnl_yes_lex);
			this->Principale->Controls->Add(this->pnl_no_lex);
			this->Principale->Controls->Add(this->btn_view_lex);
			this->Principale->Controls->Add(this->btn_view_syn);
			this->Principale->Controls->Add(this->navbar);
			this->Principale->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Principale->Location = System::Drawing::Point(0, 0);
			this->Principale->Name = L"Principale";
			this->Principale->Size = System::Drawing::Size(964, 676);
			this->Principale->TabIndex = 6;
			this->Principale->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FRM::Principale_MouseDown);
			this->Principale->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FRM::Principale_MouseMove);
			this->Principale->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FRM::Principale_MouseUp);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightCyan;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(569, 102);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(77, 37);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Font !";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FRM::button1_Click_3);
			// 
			// Home
			// 
			this->Home->BackColor = System::Drawing::Color::DarkSlateGray;
			this->Home->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Home.BackgroundImage")));
			this->Home->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Home->Controls->Add(this->btn_end);
			this->Home->Controls->Add(this->btn_about);
			this->Home->Controls->Add(this->btn_start);
			this->Home->Controls->Add(this->label5);
			this->Home->Controls->Add(this->label6);
			this->Home->Controls->Add(this->label4);
			this->Home->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Home->Location = System::Drawing::Point(0, 0);
			this->Home->Name = L"Home";
			this->Home->Size = System::Drawing::Size(964, 676);
			this->Home->TabIndex = 6;
			this->Home->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FRM::Home_MouseClick);
			this->Home->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FRM::Home_MouseDown);
			this->Home->MouseLeave += gcnew System::EventHandler(this, &FRM::Home_MouseLeave);
			this->Home->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FRM::Home_MouseMove);
			this->Home->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FRM::Home_MouseUp);
			// 
			// btn_end
			// 
			this->btn_end->BackColor = System::Drawing::Color::Transparent;
			this->btn_end->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_end.BackgroundImage")));
			this->btn_end->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_end->FlatAppearance->BorderSize = 0;
			this->btn_end->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_end->Location = System::Drawing::Point(768, 539);
			this->btn_end->Name = L"btn_end";
			this->btn_end->Size = System::Drawing::Size(85, 81);
			this->btn_end->TabIndex = 1;
			this->btn_end->UseVisualStyleBackColor = false;
			this->btn_end->Click += gcnew System::EventHandler(this, &FRM::btn_end_Click);
			this->btn_end->MouseHover += gcnew System::EventHandler(this, &FRM::btn_end_MouseHover);
			// 
			// btn_about
			// 
			this->btn_about->BackColor = System::Drawing::Color::Transparent;
			this->btn_about->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_about.BackgroundImage")));
			this->btn_about->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_about->FlatAppearance->BorderSize = 0;
			this->btn_about->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_about->Location = System::Drawing::Point(617, 490);
			this->btn_about->Name = L"btn_about";
			this->btn_about->Size = System::Drawing::Size(105, 101);
			this->btn_about->TabIndex = 1;
			this->btn_about->UseVisualStyleBackColor = false;
			this->btn_about->Click += gcnew System::EventHandler(this, &FRM::btn_about_Click);
			// 
			// btn_start
			// 
			this->btn_start->BackColor = System::Drawing::Color::Transparent;
			this->btn_start->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_start.BackgroundImage")));
			this->btn_start->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_start->FlatAppearance->BorderSize = 0;
			this->btn_start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_start->Location = System::Drawing::Point(401, 399);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(195, 191);
			this->btn_start->TabIndex = 1;
			this->btn_start->UseVisualStyleBackColor = false;
			this->btn_start->Click += gcnew System::EventHandler(this, &FRM::btn_start_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::LavenderBlush;
			this->label5->Location = System::Drawing::Point(330, 232);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 43);
			this->label5->TabIndex = 0;
			this->label5->Text = L"lang";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 25.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Lavender;
			this->label6->Location = System::Drawing::Point(385, 257);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(193, 58);
			this->label6->TabIndex = 0;
			this->label6->Text = L"compiler";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Vivaldi", 72, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::LavenderBlush;
			this->label4->Location = System::Drawing::Point(172, 156);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(207, 142);
			this->label4->TabIndex = 0;
			this->label4->Text = L"N";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// bunifuElipse1
			// 
			this->bunifuElipse1->ElipseRadius = 40;
			this->bunifuElipse1->TargetControl = this;
			// 
			// bunifuElipse2
			// 
			this->bunifuElipse2->ElipseRadius = 50;
			this->bunifuElipse2->TargetControl = this->button1;
			// 
			// FRM
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(964, 676);
			this->Controls->Add(this->Principale);
			this->Controls->Add(this->Home);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FRM";
			this->Text = L"FRM";
			this->Load += gcnew System::EventHandler(this, &FRM::FRM_Load);
			this->navbar->ResumeLayout(false);
			this->Principale->ResumeLayout(false);
			this->Principale->PerformLayout();
			this->Home->ResumeLayout(false);
			this->Home->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void FRM_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_abt_2_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		lex_result^ l = gcnew lex_result();
		StreamReader reader("./result");
		l->lex_result_text->Text = reader.ReadToEnd();
		reader.Close();
		l->Show();
	}
private: System::Void btn_start_Click(System::Object^ sender, System::EventArgs^ e) {
	Principale->BringToFront();
}
private: System::Void btn_end_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btn_end_MouseHover(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btn_about_Click(System::Object^ sender, System::EventArgs^ e) {
	FRM_abt^ frm = gcnew FRM_abt();
	frm->Show();
}
private: System::Void btn_exit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btn_abt_Click(System::Object^ sender, System::EventArgs^ e) {
	FRM_abt^ frm = gcnew FRM_abt();
	frm->Show();
}
private: System::Void btn_open_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->Filter = "Text Files| *.txt";
	openFileDialog1->FileName = "*.txt";
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		StreamWriter path_file("./path", false);
		path_file.Write(openFileDialog1->FileName);
		path_file.Close();
		StreamReader file(openFileDialog1->FileName, System::Text::Encoding::UTF8);
		textCode->Text = file.ReadToEnd();
		file.Close();
	}
}
private: System::Void btn_save_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->Filter = "Text Files|*.txt";
	saveFileDialog1->FileName = "*.txt";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		StreamWriter saved_file(saveFileDialog1->FileName);
		saved_file.Write(textCode->Text);
		saved_file.Close();
	}
}
private: System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e) {


}
private: System::Void btn_view_syn_Click(System::Object^ sender, System::EventArgs^ e) {
	syn_result^ s = gcnew syn_result();
	StreamReader reader("./syn");
	s->syn_result_text->Text = reader.ReadToEnd();
	reader.Close();
	s->Show();
}
private: System::Void textCode_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	StreamWriter writing_path("./code");
	writing_path.Write(textCode->Text);
	writing_path.Close();
	lex_analyser N_lang;
	N_lang.text_file_analyser("code");
	etat_gen = N_lang.etat_gen;
	etat_lex = N_lang.etat_lex;
	if (etat_gen && etat_lex)
	{
		pnl_yes_lex->BringToFront();
		N_lang.regler_table_symboles();
		etat_syn = N_lang.syn_analyser();
		if (etat_syn)
		{
			pnl_yes_syn->BringToFront();
		}
		else
		{
			pnl_no_syn->BringToFront();
		}


	}
	else
	{

		pnl_no_lex->BringToFront();

		pnl_no_syn->BringToFront();
	}
	ofstream reader_err("./syn", ios::app);
	reader_err << "\n---------------------------Erreurs List ----------------------------------\n" << "There is " << N_lang.syn_err.size() << " error " << endl;
	while (!N_lang.syn_err.empty())
	{
		reader_err << N_lang.syn_err.back().err << " in line " << N_lang.syn_err.back().ligne << endl;
		N_lang.syn_err.pop_back();
	}
	reader_err.close();
}
private: System::Void button1_Click_3(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Home_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void Home_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	move = 1;
	movx = e->X;
	movy = e->Y;


}
private: System::Void Home_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void Home_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (move == 1)
	{
		SetDesktopLocation(MousePosition.X - movx, MousePosition.Y - movy);
	}
}
private: System::Void Home_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {move = 0;
}
private: System::Void Principale_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	move = 1;
	movx = e->X;
	movy = e->Y;
}
private: System::Void Principale_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (move == 1)
	{
		SetDesktopLocation(MousePosition.X - movx, MousePosition.Y - movy);
	}
}
private: System::Void Principale_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	move = 0;
}
};
}
