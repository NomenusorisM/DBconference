#include "NewEntryForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

//��������� �������
System::Void DBconference2::NewEntryForm::addButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ��������� ������
	if (entryTheme->Text == "" ||
		entryCity->Text == "" ||
		entryStartTime->Text == "" ||
		entryEndTime->Text == "") {
		MessageBox::Show(
			"������� �� ��� ������!",
			"��������!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	// ��������� ������ �� ������� ������������ ������� "'"
	if (entryTheme->Text->Contains("'") ||
		entryCity->Text->Contains("'")) {
		MessageBox::Show(
			"����� ������������ ������ (')!",
			"��������!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	//��������� ������ � ��
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + path; //���� ������������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//������������

	dbConnection->Open();
	String^ query = "INSERT INTO ����������� (����, ������, �����, ��������) VALUES ('" + entryTheme->Text + "', '" + entryStartTime->Text + "', '" + entryCity->Text + "', '" + entryEndTime->Text + "')";//��� ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//���� �������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//��������� ������
	dbConnection->Close();

	//������� ���������� �� �������� ����������
	MessageBox::Show(
		"������ ����������",
		"�������",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);
	
	this->Close();
}
