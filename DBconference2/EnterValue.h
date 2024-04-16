#pragma once

namespace DBconference2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ EnterValue
	/// </summary>
	public ref class EnterValue : public System::Windows::Forms::Form
	{
	public:
		EnterValue(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::Button^ buttonConfirm;
	public:
	public:
		String^ resValue = "";

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~EnterValue()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ result;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->result = (gcnew System::Windows::Forms::TextBox());
			this->buttonConfirm = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// result
			// 
			this->result->Location = System::Drawing::Point(12, 10);
			this->result->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(225, 22);
			this->result->TabIndex = 0;
			// 
			// buttonConfirm
			// 
			this->buttonConfirm->BackColor = System::Drawing::SystemColors::Window;
			this->buttonConfirm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonConfirm->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->buttonConfirm->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->buttonConfirm->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->buttonConfirm->Location = System::Drawing::Point(53, 45);
			this->buttonConfirm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->buttonConfirm->Name = L"buttonConfirm";
			this->buttonConfirm->Size = System::Drawing::Size(132, 30);
			this->buttonConfirm->TabIndex = 1;
			this->buttonConfirm->Text = L"ѕодтвердить";
			this->buttonConfirm->UseVisualStyleBackColor = false;
			this->buttonConfirm->Click += gcnew System::EventHandler(this, &EnterValue::buttonConfirm_Click);
			// 
			// EnterValue
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::OldLace;
			this->ClientSize = System::Drawing::Size(247, 82);
			this->Controls->Add(this->buttonConfirm);
			this->Controls->Add(this->result);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EnterValue";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"¬ведите значение";
			this->Load += gcnew System::EventHandler(this, &EnterValue::EnterValue_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonConfirm_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EnterValue_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
