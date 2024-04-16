#include "MyForm.h"
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThreadAttribute]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	DBconference2::MyForm form;
	Application::Run(% form);
}

//��������������� �������
void DBconference2::MyForm::ReloadGrid() {
	dataGrid->Rows->Clear();
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //���� ������������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//������������
	dbConnection->Open();
	String^ query = "SELECT * FROM �����������";//��� ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//���� �������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//��������� ������

	//����������
	if (dbReader->HasRows == false)
		MessageBox::Show("������ ������ ������", "������");
	else
		while (dbReader->Read())
			dataGrid->Rows->Add(dbReader["�"], dbReader["����"], dbReader["�����"], dbReader["������"], dbReader["��������"]);

	//���������
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

void DBconference2::MyForm::addElementsSearchTab(TabPage^ tab, String^ query) //��������� ������� � ������������ ������ � ����
{
	DataGridView^ grid = gcnew DataGridView();

	//���������
	grid->Name = "grid";
	grid->Size = Drawing::Size(600, 370);
	grid->BackgroundColor = Color::White;
	grid->ScrollBars = ScrollBars::Both;
	grid->ReadOnly = true;
	grid->AllowUserToAddRows = false;
	
	//����� �������
	grid->Columns->Add("id", "�");
	grid->Columns[0]->SortMode = DataGridViewColumnSortMode::NotSortable;
	grid->Columns[0]->Width = 40;
	grid->Columns->Add("theme", "����");
	grid->Columns[1]->SortMode = DataGridViewColumnSortMode::NotSortable;
	grid->Columns[1]->Width = 197;
	grid->Columns->Add("city", "�����");
	grid->Columns[2]->SortMode = DataGridViewColumnSortMode::NotSortable;
	grid->Columns[2]->Width = 140;
	grid->Columns->Add("startTime", "������");
	grid->Columns[3]->SortMode = DataGridViewColumnSortMode::NotSortable;
	grid->Columns[3]->Width = 90;
	grid->Columns[3]->DefaultCellStyle->Format = "d";
	grid->Columns->Add("endTime", "������ ��");
	grid->Columns[4]->SortMode = DataGridViewColumnSortMode::NotSortable;
	grid->Columns[4]->Width = 90;
	grid->Columns[4]->DefaultCellStyle->Format = "d";

	//������������ ���� �������
	tab->Controls->Add(grid);

	//��������� ��������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //���� ������������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//������������
	dbConnection->Open();
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//���� �������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//��������� ������

	//����������
	if (dbReader->HasRows == false) {
		MessageBox::Show(
			"���������� ����� �� �������",
			"��������",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		tabControl1->TabPages->RemoveAt(tabControl1->TabCount - 1); //��������� �������, ���� ������ �� �������
	}
	else
		while (dbReader->Read())
			grid->Rows->Add(dbReader["�"], dbReader["����"], dbReader["�����"], dbReader["������"], dbReader["��������"]);

	//���������
	dbReader->Close();
	dbConnection->Close();
}

//��������� �������
System::Void DBconference2::MyForm::ExitTop_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show(
		"�� �������, ��� ������ �����?",
		"�����",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) ==
		System::Windows::Forms::DialogResult::Yes) {
		Application::ExitThread();
	}
	else
		return;
}

System::Void DBconference2::MyForm::InformationTop_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show(
		"������ ��������� ������������� ��� �����, ���������� � ������ ���������� � ������������",
		"�����",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);
}

System::Void DBconference2::MyForm::buttonLoad_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGrid->Rows->Clear();

	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //���� ������������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//������������
	dbConnection->Open();
	String^ query = "SELECT * FROM �����������";//��� ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//���� �������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//��������� ������

	//����������
	if (dbReader->HasRows == false)
		MessageBox::Show(
			"������ ������ ������",
			"������",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else
		while (dbReader->Read())
			dataGrid->Rows->Add(dbReader["�"], dbReader["����"], dbReader["�����"], dbReader["������"], dbReader["��������"]);
	gridLoaded = true;

	//���������
	dbReader->Close();
	dbConnection->Close();

	MessageBox::Show(
		"������ ������� ���������",
		"�������!",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);

	return System::Void();
}

System::Void DBconference2::MyForm::buttonNew_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!gridLoaded) {
		MessageBox::Show(
			"������� ����� ��������� ������",
			"������",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}
	NewEntryForm^ newEntry = gcnew NewEntryForm(dataSource);
	newEntry->ShowDialog();

	//������� ����������� �������� � ���������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //���� ������������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//������������
	dbConnection->Open();
	String^ query = "SELECT * FROM ����������� WHERE � = (SELECT MAX(�) FROM �����������)";//��� ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//���� �������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//��������� ������

	//����������
	if (dbReader->HasRows == false)
		MessageBox::Show(
			"������ ������ ������",
			"������",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else {
		dbReader->Read();
		dataGrid->Rows->Add(dbReader["�"], dbReader["����"], dbReader["�����"], dbReader["������"], dbReader["��������"]);
	}

	//��������� ����� ������ �� ����������������, �.�. ������������ ����� ����� �� ����� ���������� �� ��������� ������
	int index = dataGrid->Rows->Count - 1;
	if (index != 0 && dataGrid->Rows[index]->Cells[0]->Value->ToString() == dataGrid->Rows[index - 1]->Cells[0]->Value->ToString())
		dataGrid->Rows->RemoveAt(index);

	//���������
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void DBconference2::MyForm::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGrid->SelectedRows->Count != 1) {
		MessageBox::Show(
			"��������� ������� 1 ������ ��� ���������",
			"��������!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);
		return;
	}

	// �������� ������ ��������� ������
	int index = dataGrid->SelectedRows[0]->Index + 1;

	UpdateForm1^ update = gcnew UpdateForm1(dataSource, index);
	update->ShowDialog(); // ��������� ����� ���������� ������
	
	//��������� �������� � �������� �����
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //���� ������������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//������������
	dbConnection->Open();
	String^ query = "SELECT * FROM ����������� WHERE � = " + index;//��� ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//���� �������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//��������� ������

	//����������
	if (dbReader->HasRows == false)
		MessageBox::Show(
			"������ ������ ������",
			"������",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else {
		dbReader->Read();
		dataGrid->Rows[index - 1]->Cells[1]->Value = Convert::ToString(dbReader["����"]);
		dataGrid->Rows[index - 1]->Cells[2]->Value = Convert::ToString(dbReader["�����"]);
		dataGrid->Rows[index - 1]->Cells[3]->Value = Convert::ToString(dbReader["������"])->Remove(10);
		dataGrid->Rows[index - 1]->Cells[4]->Value = Convert::ToString(dbReader["��������"])->Remove(10);
	}

	dbConnection->Close();
	update->Close();
	return System::Void();
}

System::Void DBconference2::MyForm::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����� ������
	if (dataGrid->SelectedRows->Count != 1) {
		MessageBox::Show(
			"��������� ������� 1 ������ ��� ��������", 
			"��������!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	// �������� ������ ��������� ������
	int index = dataGrid->SelectedRows[0]->Index;

	if (dataGrid->Rows[index]->Cells[0]->Value == nullptr 
		&& dataGrid->Rows[index]->Cells[1]->Value == nullptr) {
		MessageBox::Show(
			"������ ������� ������ ������",
			"��������!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	if (MessageBox::Show(
		"�� �������, ��� ������ ������������ ������� ������?",
		"��������!",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::No)
		return;

	String^ id = dataGrid->Rows[index]->Cells[0]->Value->ToString();

	//��������� ������ � ��
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //���� ������������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//������������

	dbConnection->Open();
	String^ query = "DELETE FROM ����������� WHERE � =" + id; //��� ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//���� �������

	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show(
			"������ �� �������",
			"������!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else {
		MessageBox::Show(
			"������ �������",
			"�������",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);
		dataGrid->Rows->RemoveAt(index);
	};

	dbConnection->Close();
	return System::Void();
}

System::Void DBconference2::MyForm::MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (MessageBox::Show(
		"�� �������, ��� ������ �����?",
		"�����",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) ==
		System::Windows::Forms::DialogResult::Yes) {
		Application::ExitThread();
	}
	else
		e->Cancel = true; //�������� ��������
}

System::Void DBconference2::MyForm::buttonSearch_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!gridLoaded) {
		MessageBox::Show(
			"������� ����� ��������� ������!",
			"��������!");
		return;
	}
	//����� ��� ����� �������� ��� ����� ����� ������������
	SearchForm^ search = gcnew SearchForm();
	search->ShowDialog();
	
	//�� ������, ���� ������������ ������ ������ �����, �� �������� �����
	if (search->searchQuery == "") {
		search->Close();
		return;
	}

	//������ ����� ������� ��� ���������� ������
	int tabNum = tabControl1->TabCount; //����� ����������� �������

	if (tabNum == 1) {
		TabPage^ searchRes = gcnew TabPage();
		searchRes->Text = "���������� ������";
		tabControl1->TabPages->Add(searchRes);
		addElementsSearchTab(searchRes, search->searchQuery);
	}
	else {
		TabPage^ searchRes = gcnew TabPage();

		searchRes->Text = "���������� ������ (" + Convert::ToString(tabNum - 1) + ")";
		tabControl1->TabPages->Add(searchRes);
		addElementsSearchTab(searchRes, search->searchQuery);
	}
	if(tabNum == tabControl1->TabCount - 1)
		tabControl1->SelectTab(tabNum);
	search->Close();
}

System::Void DBconference2::MyForm::renameTab_Click(System::Object^ sender, System::EventArgs^ e)
{
	EnterValue^ valForm = gcnew EnterValue();
	valForm->ShowDialog();

	if (valForm->resValue == "")
		return;
	else
		this->tabControl1->SelectedTab->Text = valForm->resValue;

	valForm->Close();
}

System::Void DBconference2::MyForm::tabControl1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Right)
		contextMenuStrip1->Show(MousePosition);
}

System::Void DBconference2::MyForm::closeTab_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 1; i < tabControl1->TabCount; i++) {
		tabControl1->TabPages[i]->TabIndex = i;
	}
	int lastIndex = tabControl1->SelectedTab->TabIndex;

	if (lastIndex == 0) {
		MessageBox::Show(
			"������ ������� �������� �������!",
			"��������",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}
	else
		tabControl1->TabPages->RemoveAt(lastIndex);
}

System::Void DBconference2::MyForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	EnterValue^ newPath = gcnew EnterValue;
	newPath->ShowDialog();
	if (newPath->resValue != "" && newPath->resValue->Contains("accdb")) {
		if (System::IO::File::Exists(newPath->resValue))
			dataSource = newPath->resValue;
		else
			MessageBox::Show(
				"������� ����� �� ����������!",
				"������",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
	}
	newPath->Close();
}

