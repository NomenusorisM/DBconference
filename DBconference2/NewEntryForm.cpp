#include "NewEntryForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

//Обработка нажатий
System::Void DBconference2::NewEntryForm::addButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Проверяем данные
	if (entryTheme->Text == "" ||
		entryCity->Text == "" ||
		entryStartTime->Text == "" ||
		entryEndTime->Text == "") {
		MessageBox::Show(
			"Введены не все данные!",
			"Внимание!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	// Проверяем данные на наличие запрещённого символа "'"
	if (entryTheme->Text->Contains("'") ||
		entryCity->Text->Contains("'")) {
		MessageBox::Show(
			"Введён недопустимый символ (')!",
			"Внимание!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	//Выполняем запрос к бд
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + path; //Куда подключаемся
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//Подключаемся

	dbConnection->Open();
	String^ query = "INSERT INTO Конференции (Тема, Начало, Город, ТезисыДо) VALUES ('" + entryTheme->Text + "', '" + entryStartTime->Text + "', '" + entryCity->Text + "', '" + entryEndTime->Text + "')";//Наш запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//Наша команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//Считываем данные
	dbConnection->Close();

	//Выводим информацию об успешном добавлении
	MessageBox::Show(
		"Данные добавленны",
		"Успешно",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);
	
	this->Close();
}
