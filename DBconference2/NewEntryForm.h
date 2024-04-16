#pragma once

namespace DBconference2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� NewEntryForm
	/// </summary>
	public ref class NewEntryForm : public System::Windows::Forms::Form
	{
	public:
		NewEntryForm(String^ dbPath)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			path = dbPath;
		}
		String^ id;
		String^ path;

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~NewEntryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ addButton;

	private: System::Windows::Forms::TextBox^ entryTheme;

	private: System::Windows::Forms::TextBox^ entryCity;

	private: System::Windows::Forms::DateTimePicker^ entryStartTime;

	private: System::Windows::Forms::DateTimePicker^ entryEndTime;





	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->entryTheme = (gcnew System::Windows::Forms::TextBox());
			this->entryCity = (gcnew System::Windows::Forms::TextBox());
			this->entryStartTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->entryEndTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(10, 7);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"���� �����������:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(10, 62);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"����� ����������:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(10, 114);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"���� ������:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(10, 169);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(174, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"������ ����������� ��:";
			// 
			// addButton
			// 
			this->addButton->BackColor = System::Drawing::SystemColors::Window;
			this->addButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addButton->Location = System::Drawing::Point(141, 215);
			this->addButton->Margin = System::Windows::Forms::Padding(2);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(122, 30);
			this->addButton->TabIndex = 4;
			this->addButton->Text = L"��������";
			this->addButton->UseVisualStyleBackColor = false;
			this->addButton->Click += gcnew System::EventHandler(this, &NewEntryForm::addButton_Click);
			// 
			// entryTheme
			// 
			this->entryTheme->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->entryTheme->Location = System::Drawing::Point(10, 29);
			this->entryTheme->Margin = System::Windows::Forms::Padding(2);
			this->entryTheme->Name = L"entryTheme";
			this->entryTheme->Size = System::Drawing::Size(243, 23);
			this->entryTheme->TabIndex = 5;
			// 
			// entryCity
			// 
			this->entryCity->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(322) {
				L"������", L"����", L"�����������",
					L"�������", L"�����������", L"�����", L"�������", L"������-��������", L"�������", L"�������", L"�������", L"��������", L"�����",
					L"�����������", L"������", L"���������", L"������", L"��������", L"�������", L"��������", L"�������", L"�������", L"�������",
					L"��������", L"�������", L"������", L"��������� (�������� �������)", L"��������", L"�����������", L"������", L"���������", L"����������� (������������ �������)",
					L"�����", L"����������", L"������������ (�������� �������)", L"���", L"������������", L"��������", L"������", L"������", L"��������",
					L"����������", L"�������", L"��������", L"������� ����", L"������� ��������", L"������� �����", L"������", L"�����������", L"�����������",
					L"��������", L"���������", L"����������", L"������", L"��������", L"�������", L"������", L"�������", L"�������", L"�����������",
					L"��������", L"����������", L"������", L"�����", L"������", L"�������", L"���������", L"����������", L"������", L"�����-�������",
					L"�������", L"������", L"��������", L"������", L"����-�����������", L"�������", L"���������", L"������������", L"�������", L"������������",
					L"����������", L"�������", L"�����", L"���������", L"���������", L"����", L"������������", L"�������", L"����", L"���������",
					L"������������ (������������ ����)", L"������������ (������� �������)", L"���������", L"���������", L"��������", L"�����������",
					L"������������", L"��������", L"�������", L"����������", L"������", L"��������", L"�������", L"�������", L"����", L"�������",
					L"������-���", L"������", L"�����������", L"������", L"�������-���������", L"�������-����������", L"�������", L"�����", L"��������",
					L"��������", L"�����", L"�������", L"������", L"����� (��������� �������)", L"������-������", L"���������", L"����������", L"����",
					L"������", L"������", L"�������", L"�������", L"�����������-��-�����", L"�������", L"�������", L"��������", L"������", L"�����������",
					L"���������", L"�������������", L"�����������", L"��������������", L"����������", L"���������", L"������", L"������", L"�������",
					L"��������", L"������", L"������", L"�����", L"�����", L"�������", L"�����������", L"�������-���������", L"�����������", L"������",
					L"�����", L"�����", L"������", L"���������", L"�������", L"�������", L"������������", L"������", L"���������", L"������������",
					L"������", L"�����", L"����������� ����", L"���������", L"����������", L"���������� (�������������� ����)", L"���������", L"������",
					L"��������", L"�����", L"������", L"���������� �����", L"��������", L"�������", L"�������", L"����-�������", L"�������", L"������������",
					L"��������", L"����������", L"�����������", L"�������������", L"����������", L"������ ��������", L"������ �����", L"�����������",
					L"�����������", L"��������������", L"������������", L"������������", L"�����������", L"����������", L"�����������", L"��������������",
					L"������������", L"������������", L"����� �������", L"�������", L"��������", L"��������", L"������", L"�������", L"��������",
					L"������ (����������� �������)", L"�����������", L"����", L"����", L"��������", L"�������-�����", L"����", L"�������", L"���������� �����",
					L"�����", L"������������", L"�����", L"������������", L"�������������-����������", L"��������", L"���������", L"�����������",
					L"����������", L"�����", L"�������", L"���������", L"���������", L"�����", L"������", L"����", L"��������", L"�������", L"������-��-����",
					L"��������", L"�������", L"������", L"�������", L"������", L"������", L"�����-���������", L"�������", L"�������", L"�������",
					L"�����", L"���������", L"�����������", L"������������", L"�������", L"������� �����", L"�����", L"��������", L"���������", L"�����",
					L"�����������", L"��������-��-������", L"��������", L"���������", L"�������������", L"�������� ���", L"����", L"����������",
					L"������ �����", L"�����������", L"�������", L"������", L"�������", L"���������", L"��������", L"������", L"�����", L"���������",
					L"������", L"��������", L"��������", L"��������", L"�����", L"������", L"������", L"�������", L"����", L"������", L"�������",
					L"����-���", L"���������", L"����-������", L"������-���������", L"���������", L"����-������", L"���", L"����", L"��������", L"�������",
					L"���������", L"�����-��������", L"��������", L"�����", L"����������", L"��������", L"���������", L"���������", L"���������",
					L"���������", L"��������", L"����������", L"�����", L"���������", L"����", L"��������", L"����", L"�����", L"���", L"������",
					L"�������", L"������������", L"������", L"�������", L"����-���������", L"����", L"������", L"����", L"���������"
			});
			this->entryCity->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->entryCity->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->entryCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->entryCity->Location = System::Drawing::Point(10, 82);
			this->entryCity->Margin = System::Windows::Forms::Padding(2);
			this->entryCity->Name = L"entryCity";
			this->entryCity->Size = System::Drawing::Size(243, 23);
			this->entryCity->TabIndex = 6;
			// 
			// entryStartTime
			// 
			this->entryStartTime->CustomFormat = L"dd.MM.yyyy";
			this->entryStartTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->entryStartTime->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->entryStartTime->Location = System::Drawing::Point(10, 137);
			this->entryStartTime->Margin = System::Windows::Forms::Padding(2);
			this->entryStartTime->Name = L"entryStartTime";
			this->entryStartTime->Size = System::Drawing::Size(117, 23);
			this->entryStartTime->TabIndex = 7;
			// 
			// entryEndTime
			// 
			this->entryEndTime->CustomFormat = L"dd.MM.yyyy";
			this->entryEndTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->entryEndTime->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->entryEndTime->Location = System::Drawing::Point(10, 191);
			this->entryEndTime->Margin = System::Windows::Forms::Padding(2);
			this->entryEndTime->Name = L"entryEndTime";
			this->entryEndTime->Size = System::Drawing::Size(117, 23);
			this->entryEndTime->TabIndex = 8;
			// 
			// NewEntryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->ClientSize = System::Drawing::Size(272, 254);
			this->Controls->Add(this->entryEndTime);
			this->Controls->Add(this->entryStartTime);
			this->Controls->Add(this->entryCity);
			this->Controls->Add(this->entryTheme);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"NewEntryForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"����� ������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
