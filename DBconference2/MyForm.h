#pragma once

#include "NewEntryForm.h"
#include "SearchForm.h"
#include "EnterValue.h"
#include "UpdateForm.h"

namespace DBconference2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	public:
		bool gridLoaded = false; //ѕровер€ет загружены ли данные
		String^ dataSource = "conference.accdb"; //‘айл Ѕƒ либо путь к нему, откуда мы берЄм данные

	private: System::Windows::Forms::ToolStripMenuItem^ settingsTop;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ renameTab;

	private: System::Windows::Forms::ToolStripMenuItem^ closeTab;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Theme;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ City;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ StartTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ EndTime;
	private: System::Windows::Forms::TabControl^ tabControl1;

	public:
	private: System::Windows::Forms::ToolStripMenuItem^ задатьѕуть ‘айлуToolStripMenuItem;

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ InformationTop;
	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ ExitTop;
	private: System::Windows::Forms::DataGridView^ dataGrid;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonDelete;

	private: System::Windows::Forms::Button^ buttonUpdate;

	private: System::Windows::Forms::Button^ buttonNew;

	private: System::Windows::Forms::Button^ buttonLoad;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ buttonSearch;



	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->settingsTop = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->задатьѕуть ‘айлуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->InformationTop = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitTop = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Theme = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->City = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StartTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EndTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonUpdate = (gcnew System::Windows::Forms::Button());
			this->buttonNew = (gcnew System::Windows::Forms::Button());
			this->buttonLoad = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSearch = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->renameTab = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeTab = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FloralWhite;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->settingsTop, this->InformationTop,
					this->ExitTop
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(772, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// settingsTop
			// 
			this->settingsTop->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->задатьѕуть ‘айлуToolStripMenuItem });
			this->settingsTop->Name = L"settingsTop";
			this->settingsTop->Size = System::Drawing::Size(98, 24);
			this->settingsTop->Text = L"Ќастройки";
			// 
			// задатьѕуть ‘айлуToolStripMenuItem
			// 
			this->задатьѕуть ‘айлуToolStripMenuItem->Name = L"задатьѕуть ‘айлуToolStripMenuItem";
			this->задатьѕуть ‘айлуToolStripMenuItem->Size = System::Drawing::Size(229, 26);
			this->задатьѕуть ‘айлуToolStripMenuItem->Text = L"«адать путь к файлу";
			this->задатьѕуть ‘айлуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::задатьѕуть ‘айлуToolStripMenuItem_Click);
			// 
			// InformationTop
			// 
			this->InformationTop->Name = L"InformationTop";
			this->InformationTop->Size = System::Drawing::Size(116, 24);
			this->InformationTop->Text = L"»нформаци€";
			this->InformationTop->Click += gcnew System::EventHandler(this, &MyForm::InformationTop_Click);
			// 
			// ExitTop
			// 
			this->ExitTop->Name = L"ExitTop";
			this->ExitTop->Size = System::Drawing::Size(67, 24);
			this->ExitTop->Text = L"¬ыход";
			this->ExitTop->Click += gcnew System::EventHandler(this, &MyForm::ExitTop_Click);
			// 
			// dataGrid
			// 
			this->dataGrid->AllowUserToAddRows = false;
			this->dataGrid->BackgroundColor = System::Drawing::Color::White;
			this->dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->id, this->Theme,
					this->City, this->StartTime, this->EndTime
			});
			this->dataGrid->Location = System::Drawing::Point(10, 67);
			this->dataGrid->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->dataGrid->MultiSelect = false;
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->ReadOnly = true;
			this->dataGrid->RowHeadersWidth = 51;
			this->dataGrid->RowTemplate->Height = 24;
			this->dataGrid->Size = System::Drawing::Size(728, 384);
			this->dataGrid->TabIndex = 1;
			// 
			// id
			// 
			this->id->Frozen = true;
			this->id->HeaderText = L"є";
			this->id->MinimumWidth = 6;
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Width = 40;
			// 
			// Theme
			// 
			this->Theme->HeaderText = L"“ема";
			this->Theme->MinimumWidth = 6;
			this->Theme->Name = L"Theme";
			this->Theme->ReadOnly = true;
			this->Theme->Width = 175;
			// 
			// City
			// 
			this->City->HeaderText = L"√ород";
			this->City->MinimumWidth = 6;
			this->City->Name = L"City";
			this->City->ReadOnly = true;
			this->City->Width = 130;
			// 
			// StartTime
			// 
			dataGridViewCellStyle1->Format = L"d";
			this->StartTime->DefaultCellStyle = dataGridViewCellStyle1;
			this->StartTime->HeaderText = L"Ќачало";
			this->StartTime->MinimumWidth = 6;
			this->StartTime->Name = L"StartTime";
			this->StartTime->ReadOnly = true;
			this->StartTime->Width = 90;
			// 
			// EndTime
			// 
			dataGridViewCellStyle2->Format = L"d";
			this->EndTime->DefaultCellStyle = dataGridViewCellStyle2;
			this->EndTime->HeaderText = L"“езисы до";
			this->EndTime->MinimumWidth = 6;
			this->EndTime->Name = L"EndTime";
			this->EndTime->ReadOnly = true;
			this->EndTime->Width = 90;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::White;
			this->groupBox1->Controls->Add(this->buttonDelete);
			this->groupBox1->Controls->Add(this->buttonUpdate);
			this->groupBox1->Controls->Add(this->buttonNew);
			this->groupBox1->Location = System::Drawing::Point(292, 5);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->groupBox1->Size = System::Drawing::Size(422, 55);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"–абота со строками";
			// 
			// buttonDelete
			// 
			this->buttonDelete->BackColor = System::Drawing::Color::FloralWhite;
			this->buttonDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDelete->Location = System::Drawing::Point(282, 19);
			this->buttonDelete->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(133, 30);
			this->buttonDelete->TabIndex = 3;
			this->buttonDelete->Text = L"”далить";
			this->buttonDelete->UseVisualStyleBackColor = false;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm::buttonDelete_Click);
			// 
			// buttonUpdate
			// 
			this->buttonUpdate->BackColor = System::Drawing::Color::FloralWhite;
			this->buttonUpdate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonUpdate->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonUpdate->Location = System::Drawing::Point(143, 19);
			this->buttonUpdate->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->buttonUpdate->Name = L"buttonUpdate";
			this->buttonUpdate->Size = System::Drawing::Size(133, 30);
			this->buttonUpdate->TabIndex = 2;
			this->buttonUpdate->Text = L"»зменить";
			this->buttonUpdate->UseVisualStyleBackColor = false;
			this->buttonUpdate->Click += gcnew System::EventHandler(this, &MyForm::buttonUpdate_Click);
			// 
			// buttonNew
			// 
			this->buttonNew->BackColor = System::Drawing::Color::FloralWhite;
			this->buttonNew->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonNew->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonNew->Location = System::Drawing::Point(5, 19);
			this->buttonNew->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->buttonNew->Name = L"buttonNew";
			this->buttonNew->Size = System::Drawing::Size(133, 30);
			this->buttonNew->TabIndex = 1;
			this->buttonNew->Text = L"ƒобавить";
			this->buttonNew->UseVisualStyleBackColor = false;
			this->buttonNew->Click += gcnew System::EventHandler(this, &MyForm::buttonNew_Click);
			// 
			// buttonLoad
			// 
			this->buttonLoad->BackColor = System::Drawing::Color::FloralWhite;
			this->buttonLoad->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->buttonLoad->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonLoad->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLoad->ForeColor = System::Drawing::Color::Black;
			this->buttonLoad->Location = System::Drawing::Point(5, 19);
			this->buttonLoad->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->buttonLoad->Name = L"buttonLoad";
			this->buttonLoad->Size = System::Drawing::Size(133, 30);
			this->buttonLoad->TabIndex = 0;
			this->buttonLoad->Text = L"«агрузить";
			this->buttonLoad->UseVisualStyleBackColor = false;
			this->buttonLoad->Click += gcnew System::EventHandler(this, &MyForm::buttonLoad_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::White;
			this->groupBox2->Controls->Add(this->buttonSearch);
			this->groupBox2->Controls->Add(this->buttonLoad);
			this->groupBox2->Location = System::Drawing::Point(5, 5);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(282, 55);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"”правление данными";
			// 
			// buttonSearch
			// 
			this->buttonSearch->BackColor = System::Drawing::Color::FloralWhite;
			this->buttonSearch->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonSearch->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSearch->Location = System::Drawing::Point(143, 19);
			this->buttonSearch->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->buttonSearch->Name = L"buttonSearch";
			this->buttonSearch->Size = System::Drawing::Size(133, 30);
			this->buttonSearch->TabIndex = 1;
			this->buttonSearch->Text = L"ѕоиск";
			this->buttonSearch->UseVisualStyleBackColor = false;
			this->buttonSearch->Click += gcnew System::EventHandler(this, &MyForm::buttonSearch_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(8, 30);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(760, 490);
			this->tabControl1->TabIndex = 4;
			this->tabControl1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::tabControl1_MouseClick);
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->dataGrid);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2);
			this->tabPage1->Size = System::Drawing::Size(752, 461);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L" онференции";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->renameTab,
					this->closeTab
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(191, 52);
			// 
			// renameTab
			// 
			this->renameTab->Name = L"renameTab";
			this->renameTab->Size = System::Drawing::Size(190, 24);
			this->renameTab->Text = L"ѕереименовать";
			this->renameTab->Click += gcnew System::EventHandler(this, &MyForm::renameTab_Click);
			// 
			// closeTab
			// 
			this->closeTab->Name = L"closeTab";
			this->closeTab->Size = System::Drawing::Size(190, 24);
			this->closeTab->Text = L"«акрыть";
			this->closeTab->Click += gcnew System::EventHandler(this, &MyForm::closeTab_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->ClientSize = System::Drawing::Size(772, 525);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L" онференции";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//¬спомогательные функции
	private:void ReloadGrid();
	private:void addElementsSearchTab(TabPage^ tab, String^ query);

	//—обыти€ нажати€ на кнопки
	private: System::Void ExitTop_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void InformationTop_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonLoad_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonNew_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void buttonSearch_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void renameTab_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void tabControl1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void closeTab_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void задатьѕуть ‘айлуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
