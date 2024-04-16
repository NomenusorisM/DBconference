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

//Вспомогательные функции
void DBconference2::MyForm::ReloadGrid() {
	dataGrid->Rows->Clear();
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //Куда подключаемся
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//Подключаемся
	dbConnection->Open();
	String^ query = "SELECT * FROM Конференции";//Наш запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//Наша команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//Считываем данные

	//Проверочка
	if (dbReader->HasRows == false)
		MessageBox::Show("Ошибка чтения данных", "Ошибка");
	else
		while (dbReader->Read())
			dataGrid->Rows->Add(dbReader["№"], dbReader["Тема"], dbReader["Город"], dbReader["Начало"], dbReader["ТезисыДо"]);

	//Закрываем
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

void DBconference2::MyForm::addElementsSearchTab(TabPage^ tab, String^ query) //ДОбавляем таблицу с результатами поиска в окно
{
	DataGridView^ grid = gcnew DataGridView();

	//Параметры
	grid->Name = "grid";
	grid->Size = Drawing::Size(600, 370);
	grid->BackgroundColor = Color::White;
	grid->ScrollBars = ScrollBars::Both;
	grid->ReadOnly = true;
	grid->AllowUserToAddRows = false;
	
	//Задаём столбцы
	grid->Columns->Add("id", "№");
	grid->Columns[0]->SortMode = DataGridViewColumnSortMode::NotSortable;
	grid->Columns[0]->Width = 40;
	grid->Columns->Add("theme", "Тема");
	grid->Columns[1]->SortMode = DataGridViewColumnSortMode::NotSortable;
	grid->Columns[1]->Width = 197;
	grid->Columns->Add("city", "Город");
	grid->Columns[2]->SortMode = DataGridViewColumnSortMode::NotSortable;
	grid->Columns[2]->Width = 140;
	grid->Columns->Add("startTime", "Начало");
	grid->Columns[3]->SortMode = DataGridViewColumnSortMode::NotSortable;
	grid->Columns[3]->Width = 90;
	grid->Columns[3]->DefaultCellStyle->Format = "d";
	grid->Columns->Add("endTime", "Тезисы до");
	grid->Columns[4]->SortMode = DataGridViewColumnSortMode::NotSortable;
	grid->Columns[4]->Width = 90;
	grid->Columns[4]->DefaultCellStyle->Format = "d";

	//Отрисовываем нашу таблицу
	tab->Controls->Add(grid);

	//Заполняем табличку
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //Куда подключаемся
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//Подключаемся
	dbConnection->Open();
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//Наша команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//Считываем данные

	//Проверочка
	if (dbReader->HasRows == false) {
		MessageBox::Show(
			"Подходящих строк не найдено",
			"Внимание",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		tabControl1->TabPages->RemoveAt(tabControl1->TabCount - 1); //Закрываем вкладку, если ничего не найдено
	}
	else
		while (dbReader->Read())
			grid->Rows->Add(dbReader["№"], dbReader["Тема"], dbReader["Город"], dbReader["Начало"], dbReader["ТезисыДо"]);

	//Закрываем
	dbReader->Close();
	dbConnection->Close();
}

//Обработка нажатий
System::Void DBconference2::MyForm::ExitTop_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show(
		"Вы уверены, что хотите выйти?",
		"Выход",
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
		"Данная программа предназначена для учёта, добавления и поиска информации о конференциях",
		"Марио",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);
}

System::Void DBconference2::MyForm::buttonLoad_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGrid->Rows->Clear();

	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //Куда подключаемся
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//Подключаемся
	dbConnection->Open();
	String^ query = "SELECT * FROM Конференции";//Наш запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//Наша команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//Считываем данные

	//Проверочка
	if (dbReader->HasRows == false)
		MessageBox::Show(
			"Ошибка чтения данных",
			"Ошибка",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else
		while (dbReader->Read())
			dataGrid->Rows->Add(dbReader["№"], dbReader["Тема"], dbReader["Город"], dbReader["Начало"], dbReader["ТезисыДо"]);
	gridLoaded = true;

	//Закрываем
	dbReader->Close();
	dbConnection->Close();

	MessageBox::Show(
		"Данные успешно загружены",
		"Успешно!",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);

	return System::Void();
}

System::Void DBconference2::MyForm::buttonNew_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!gridLoaded) {
		MessageBox::Show(
			"Сначала нужно загрузить данные",
			"Ошибка",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}
	NewEntryForm^ newEntry = gcnew NewEntryForm(dataSource);
	newEntry->ShowDialog();

	//Заносим добавленные значения в программу
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //Куда подключаемся
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//Подключаемся
	dbConnection->Open();
	String^ query = "SELECT * FROM Конференции WHERE № = (SELECT MAX(№) FROM Конференции)";//Наш запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//Наша команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//Считываем данные

	//Проверочка
	if (dbReader->HasRows == false)
		MessageBox::Show(
			"Ошибка чтения данных",
			"Ошибка",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else {
		dbReader->Read();
		dataGrid->Rows->Add(dbReader["№"], dbReader["Тема"], dbReader["Город"], dbReader["Начало"], dbReader["ТезисыДо"]);
	}

	//Проверяем чтобы запись не продублировалась, т.к. пользователь может выйти из формы добавления не записывая данные
	int index = dataGrid->Rows->Count - 1;
	if (index != 0 && dataGrid->Rows[index]->Cells[0]->Value->ToString() == dataGrid->Rows[index - 1]->Cells[0]->Value->ToString())
		dataGrid->Rows->RemoveAt(index);

	//Закрываем
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void DBconference2::MyForm::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGrid->SelectedRows->Count != 1) {
		MessageBox::Show(
			"Требуется выбрать 1 строку для изменения",
			"Внимание!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);
		return;
	}

	// Получаем индекс выбранной строки
	int index = dataGrid->SelectedRows[0]->Index + 1;

	UpdateForm1^ update = gcnew UpdateForm1(dataSource, index);
	update->ShowDialog(); // Открываем форму обновления данных
	
	//Обновляем значения в основной форме
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //Куда подключаемся
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//Подключаемся
	dbConnection->Open();
	String^ query = "SELECT * FROM Конференции WHERE № = " + index;//Наш запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//Наша команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//Считываем данные

	//Проверочка
	if (dbReader->HasRows == false)
		MessageBox::Show(
			"Ошибка чтения данных",
			"Ошибка",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else {
		dbReader->Read();
		dataGrid->Rows[index - 1]->Cells[1]->Value = Convert::ToString(dbReader["Тема"]);
		dataGrid->Rows[index - 1]->Cells[2]->Value = Convert::ToString(dbReader["Город"]);
		dataGrid->Rows[index - 1]->Cells[3]->Value = Convert::ToString(dbReader["Начало"])->Remove(10);
		dataGrid->Rows[index - 1]->Cells[4]->Value = Convert::ToString(dbReader["ТезисыДо"])->Remove(10);
	}

	dbConnection->Close();
	update->Close();
	return System::Void();
}

System::Void DBconference2::MyForm::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор строки
	if (dataGrid->SelectedRows->Count != 1) {
		MessageBox::Show(
			"Требуется выбрать 1 строку для удаления", 
			"Внимание!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	// Получаем индекс выбранной строки
	int index = dataGrid->SelectedRows[0]->Index;

	if (dataGrid->Rows[index]->Cells[0]->Value == nullptr 
		&& dataGrid->Rows[index]->Cells[1]->Value == nullptr) {
		MessageBox::Show(
			"Нельзя удалить пустую ячейку",
			"Внимание!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	if (MessageBox::Show(
		"Вы уверены, что хотите безвозвратно удалить строку?",
		"Внимание!",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::No)
		return;

	String^ id = dataGrid->Rows[index]->Cells[0]->Value->ToString();

	//Выполняем запрос к бд
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataSource; //Куда подключаемся
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);//Подключаемся

	dbConnection->Open();
	String^ query = "DELETE FROM Конференции WHERE № =" + id; //Наш запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//Наша команда

	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show(
			"Данные не удалены",
			"Ошибка!",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else {
		MessageBox::Show(
			"Данные удалены",
			"Успешно",
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
		"Вы уверены, что хотите выйти?",
		"Выход",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) ==
		System::Windows::Forms::DialogResult::Yes) {
		Application::ExitThread();
	}
	else
		e->Cancel = true; //Отменяем закрытие
}

System::Void DBconference2::MyForm::buttonSearch_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!gridLoaded) {
		MessageBox::Show(
			"Сначала нужно загрузить данные!",
			"Внимание!");
		return;
	}
	//Форма где будем узнавать что хочет найти пользователь
	SearchForm^ search = gcnew SearchForm();
	search->ShowDialog();
	
	//На случай, если пользователь просто закрыл форму, не выполняя поиск
	if (search->searchQuery == "") {
		search->Close();
		return;
	}

	//Создаём новую вкладку под результаты поиска
	int tabNum = tabControl1->TabCount; //Номер добавленной вкладки

	if (tabNum == 1) {
		TabPage^ searchRes = gcnew TabPage();
		searchRes->Text = "Результаты поиска";
		tabControl1->TabPages->Add(searchRes);
		addElementsSearchTab(searchRes, search->searchQuery);
	}
	else {
		TabPage^ searchRes = gcnew TabPage();

		searchRes->Text = "Результаты поиска (" + Convert::ToString(tabNum - 1) + ")";
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
			"Нельзя закрыть основную вкладку!",
			"Внимание",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}
	else
		tabControl1->TabPages->RemoveAt(lastIndex);
}

System::Void DBconference2::MyForm::задатьПутьКФайлуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	EnterValue^ newPath = gcnew EnterValue;
	newPath->ShowDialog();
	if (newPath->resValue != "" && newPath->resValue->Contains("accdb")) {
		if (System::IO::File::Exists(newPath->resValue))
			dataSource = newPath->resValue;
		else
			MessageBox::Show(
				"Данного файла не существует!",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
	}
	newPath->Close();
}

