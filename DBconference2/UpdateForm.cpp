#include "UpdateForm.h"

//using namespace System::Data::OleDb;

System::Void DBconference2::UpdateForm1::UpdateForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dbPath; //Куда подключаемся
	Data::OleDb::OleDbConnection^ dbConnection = gcnew Data::OleDb::OleDbConnection(connectionString);//Подключаемся

	dbConnection->Open();

	String^ query = "SELECT * FROM Конференции WHERE № = " + updateIndex;//Наш запрос
	Data::OleDb::OleDbCommand^ dbComand = gcnew Data::OleDb::OleDbCommand(query, dbConnection);//Наша команда
	Data::OleDb::OleDbDataReader^ dbReader = dbComand->ExecuteReader();//Считываем данные

	//Проверочка
	if (dbReader->HasRows == false)
		MessageBox::Show(
			"Ошибка чтения данных",
			"Ошибка",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else {
		dbReader->Read();
		changeTheme->Text = Convert::ToString(dbReader["Тема"]);
		changeCity->Text = Convert::ToString(dbReader["Город"]);
		changeStartTime->Text = Convert::ToString(dbReader["Начало"]);
		changeEndTime->Text = Convert::ToString(dbReader["ТезисыДо"]);
	}

	dbConnection->Close();
}

System::Void DBconference2::UpdateForm1::buttonConfirm_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Проверяем данные
	if (changeTheme->Text == "" ||
		changeCity->Text == "" ||
		changeStartTime->Text == "" ||
		changeEndTime->Text == "") {
		MessageBox::Show(
			"Введены не все данные!",
			"Внимание!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	// Проверяем данные на наличие запрещённого символа "'"
	if (changeTheme->Text->Contains("'") ||
		changeCity->Text->Contains("'")) {
		MessageBox::Show(
			"Введён недопустимый символ (')!",
			"Внимание!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dbPath; //Куда подключаемся
	Data::OleDb::OleDbConnection^ dbConnection = gcnew Data::OleDb::OleDbConnection(connectionString);//Подключаемся

	dbConnection->Open();

	String^ query = "UPDATE Конференции SET Тема = '" + changeTheme->Text + "', Город = '" + changeCity->Text + "', Начало = '" + changeStartTime->Text + "', ТезисыДо = '" + changeEndTime->Text + "' WHERE № = " + updateIndex;//Наш запрос
	Data::OleDb::OleDbCommand^ dbComand = gcnew Data::OleDb::OleDbCommand(query, dbConnection);//Наша команда

	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show(
			"Данные не изменены!",
			"Ошибка!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else
		MessageBox::Show(
			"Данные изменены!",
			"Успешно",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);
	dbConnection->Close();
	this->Close();
}