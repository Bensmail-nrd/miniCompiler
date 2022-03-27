#pragma once

namespace FINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for lex_result
	/// </summary>
	public ref class lex_result : public System::Windows::Forms::Form
	{
	public:
		lex_result(void)
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
		~lex_result()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::RichTextBox^ lex_result_text;
	private: System::Windows::Forms::Label^ label1;
	public:


	public:
	protected:

	protected:

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
			this->lex_result_text = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lex_result_text
			// 
			this->lex_result_text->Location = System::Drawing::Point(23, 81);
			this->lex_result_text->Name = L"lex_result_text";
			this->lex_result_text->Size = System::Drawing::Size(602, 506);
			this->lex_result_text->TabIndex = 0;
			this->lex_result_text->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(232, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(184, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Lexicale result";
			// 
			// lex_result
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(648, 613);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lex_result_text);
			this->Name = L"lex_result";
			this->Text = L"lex_result";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
