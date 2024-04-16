#include "UpdateForm.h"

//using namespace System::Data::OleDb;

System::Void DBconference2::UpdateForm1::UpdateForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dbPath; //���� ������������
	Data::OleDb::OleDbConnection^ dbConnection = gcnew Data::OleDb::OleDbConnection(connectionString);//������������

	dbConnection->Open();

	String^ query = "SELECT * FROM ����������� WHERE � = " + updateIndex;//��� ������
	Data::OleDb::OleDbCommand^ dbComand = gcnew Data::OleDb::OleDbCommand(query, dbConnection);//���� �������
	Data::OleDb::OleDbDataReader^ dbReader = dbComand->ExecuteReader();//��������� ������

	//����������
	if (dbReader->HasRows == false)
		MessageBox::Show(
			"������ ������ ������",
			"������",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else {
		dbReader->Read();
		changeTheme->Text = Convert::ToString(dbReader["����"]);
		changeCity->Text = Convert::ToString(dbReader["�����"]);
		changeStartTime->Text = Convert::ToString(dbReader["������"]);
		changeEndTime->Text = Convert::ToString(dbReader["��������"]);
	}

	dbConnection->Close();
}

System::Void DBconference2::UpdateForm1::buttonConfirm_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ��������� ������
	if (changeTheme->Text == "" ||
		changeCity->Text == "" ||
		changeStartTime->Text == "" ||
		changeEndTime->Text == "") {
		MessageBox::Show(
			"������� �� ��� ������!",
			"��������!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	// ��������� ������ �� ������� ������������ ������� "'"
	if (changeTheme->Text->Contains("'") ||
		changeCity->Text->Contains("'")) {
		MessageBox::Show(
			"����� ������������ ������ (')!",
			"��������!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dbPath; //���� ������������
	Data::OleDb::OleDbConnection^ dbConnection = gcnew Data::OleDb::OleDbConnection(connectionString);//������������

	dbConnection->Open();

	String^ query = "UPDATE ����������� SET ���� = '" + changeTheme->Text + "', ����� = '" + changeCity->Text + "', ������ = '" + changeStartTime->Text + "', �������� = '" + changeEndTime->Text + "' WHERE � = " + updateIndex;//��� ������
	Data::OleDb::OleDbCommand^ dbComand = gcnew Data::OleDb::OleDbCommand(query, dbConnection);//���� �������

	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show(
			"������ �� ��������!",
			"������!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else
		MessageBox::Show(
			"������ ��������!",
			"�������",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);
	dbConnection->Close();
	this->Close();
}