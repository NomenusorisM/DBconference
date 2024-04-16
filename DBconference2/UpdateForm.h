#pragma once

namespace DBconference2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� UpdateForm
	/// </summary>
	public ref class UpdateForm1 : public System::Windows::Forms::Form
	{
	public:
		UpdateForm1(String^ filePath, int index)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			this->dbPath = filePath;
			this->updateIndex = index;
		}
		String^ dbPath;
		int updateIndex;
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~UpdateForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ changeTheme;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ changeCity;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DateTimePicker^ changeStartTime;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DateTimePicker^ changeEndTime;

	private: System::Windows::Forms::Button^ buttonConfirm;

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
			this->changeTheme = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->changeCity = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->changeStartTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->changeEndTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->buttonConfirm = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"����";
			// 
			// changeTheme
			// 
			this->changeTheme->Location = System::Drawing::Point(13, 34);
			this->changeTheme->Name = L"changeTheme";
			this->changeTheme->Size = System::Drawing::Size(198, 22);
			this->changeTheme->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"�����";
			// 
			// changeCity
			// 
			this->changeCity->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(322) {
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
			this->changeCity->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->changeCity->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->changeCity->Location = System::Drawing::Point(13, 84);
			this->changeCity->Name = L"changeCity";
			this->changeCity->Size = System::Drawing::Size(198, 22);
			this->changeCity->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 113);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"���� ������";
			// 
			// changeStartTime
			// 
			this->changeStartTime->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->changeStartTime->Location = System::Drawing::Point(13, 134);
			this->changeStartTime->Name = L"changeStartTime";
			this->changeStartTime->Size = System::Drawing::Size(200, 22);
			this->changeStartTime->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 163);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(205, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"��������� �������� �������";
			// 
			// changeEndTime
			// 
			this->changeEndTime->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->changeEndTime->Location = System::Drawing::Point(13, 184);
			this->changeEndTime->Name = L"changeEndTime";
			this->changeEndTime->Size = System::Drawing::Size(200, 22);
			this->changeEndTime->TabIndex = 7;
			// 
			// buttonConfirm
			// 
			this->buttonConfirm->BackColor = System::Drawing::SystemColors::Window;
			this->buttonConfirm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonConfirm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonConfirm->Location = System::Drawing::Point(12, 221);
			this->buttonConfirm->Name = L"buttonConfirm";
			this->buttonConfirm->Size = System::Drawing::Size(201, 33);
			this->buttonConfirm->TabIndex = 8;
			this->buttonConfirm->Text = L"��������";
			this->buttonConfirm->UseVisualStyleBackColor = false;
			this->buttonConfirm->Click += gcnew System::EventHandler(this, &UpdateForm1::buttonConfirm_Click);
			// 
			// UpdateForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->ClientSize = System::Drawing::Size(223, 266);
			this->Controls->Add(this->buttonConfirm);
			this->Controls->Add(this->changeEndTime);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->changeStartTime);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->changeCity);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->changeTheme);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"UpdateForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�������� ������";
			this->Load += gcnew System::EventHandler(this, &UpdateForm1::UpdateForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonConfirm_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void UpdateForm_Load(System::Object^ sender, System::EventArgs^ e);
};
}
