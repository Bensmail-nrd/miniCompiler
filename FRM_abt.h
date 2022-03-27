#pragma once

namespace FINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FRM_abt
	/// </summary>
	public ref class FRM_abt : public System::Windows::Forms::Form
	{
	public:
		FRM_abt(void)
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
		~FRM_abt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label5;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btn_end_abt;
	private: Bunifu::Framework::UI::BunifuElipse^ bunifuElipse1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FRM_abt::typeid));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_end_abt = (gcnew System::Windows::Forms::Button());
			this->bunifuElipse1 = (gcnew Bunifu::Framework::UI::BunifuElipse(this->components));
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Navy;
			this->label5->Location = System::Drawing::Point(303, 114);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 43);
			this->label5->TabIndex = 1;
			this->label5->Text = L"lang";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 25.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::DarkTurquoise;
			this->label6->Location = System::Drawing::Point(358, 139);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(193, 58);
			this->label6->TabIndex = 2;
			this->label6->Text = L"compiler";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Vivaldi", 72, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label4->Location = System::Drawing::Point(145, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(207, 142);
			this->label4->TabIndex = 3;
			this->label4->Text = L"N";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(15, 211);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(653, 165);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"About";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(167, 126);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(291, 31);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Based on .NET Framwork";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(148, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(336, 31);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Using CLR Features from C++";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(598, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"This Application is made by : BENSMAIL Noureddine";
			// 
			// btn_end_abt
			// 
			this->btn_end_abt->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_end_abt.BackgroundImage")));
			this->btn_end_abt->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_end_abt->FlatAppearance->BorderSize = 0;
			this->btn_end_abt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_end_abt->Location = System::Drawing::Point(618, 382);
			this->btn_end_abt->Name = L"btn_end_abt";
			this->btn_end_abt->Size = System::Drawing::Size(50, 50);
			this->btn_end_abt->TabIndex = 5;
			this->btn_end_abt->UseVisualStyleBackColor = true;
			this->btn_end_abt->Click += gcnew System::EventHandler(this, &FRM_abt::btn_end_abt_Click);
			// 
			// bunifuElipse1
			// 
			this->bunifuElipse1->ElipseRadius = 50;
			this->bunifuElipse1->TargetControl = this;
			// 
			// FRM_abt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(685, 437);
			this->Controls->Add(this->btn_end_abt);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FRM_abt";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FRM_abt";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_end_abt_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
