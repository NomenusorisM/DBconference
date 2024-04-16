#include "SearchForm.h"

System::String^ DBconference2::SearchForm::ReDate(String^ date) //Преобразователь данных АБ2003
{
    // 02.11.2021 0:00 : 00 (Данные на входе)
    // #2009/04/21# (Данные на выходе)
    if (date == "")
        return date;
    String^ NewDate = "#";
    int k = 0;
    String^ Year, ^ Month, ^ Day;
    for each (wchar_t i in date) {
        if (6 <= k && k <= 9)
            Year += i;
        if (3 <= k && k <= 4)
            Month += i;
        if (0 <= k && k <= 1)
            Day += i;
        k++;
    }

    NewDate += Year + "/" + Month + "/" + Day;
    NewDate += "#";
    return NewDate;
}

System::Void DBconference2::SearchForm::sortVisible_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (sortVisible->Checked)
        SortGroup->Visible = true;
    else
        SortGroup->Visible = false;
}

System::Void DBconference2::SearchForm::buttonGoSearch_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Проверяем данные на наличие запрещённого символа "'"
    if (searchTheme->Text->Contains("'") ||
        searchCity->Text->Contains("'")) {
        MessageBox::Show(
            "Введён недопустимый символ (')!",
            "Внимание!",
            MessageBoxButtons::OK,
            MessageBoxIcon::Warning);
        return;
    }

    //Генерим запросик

    searchQuery = "SELECT * FROM Конференции WHERE";

    bool isNext = false; //Это чтобы знать, нужен нам AND или нет

    if (searchTheme->Text != "" && !searchTheme->Text->Contains("'")) {
        searchQuery += " Тема = '" + searchTheme->Text + "'";
        isNext = true;
    }

    if (searchCity->Text != "" && isNext && !searchCity->Text->Contains("'")) {
        searchQuery += " AND Город = '" + searchCity->Text + "'";
    }
    else
        if (searchCity->Text != "" && !searchCity->Text->Contains("'")) {
            searchQuery += " Город = '" + searchCity->Text + "'";
            isNext = true;
        }

    if(searchStartParam->Text !="" && isNext && !searchStartParam->Text->Contains("'")){
        String^ sTime = ReDate(searchStartTime->Text);
        searchQuery += " AND Начало " + searchStartParam->Text + " (" + sTime + ")";
    }   
    else 
        if (searchStartParam->Text != "" && !isNext && !searchStartParam->Text->Contains("'")) {
            String^ sTime = ReDate(searchStartTime->Text);
            searchQuery += " Начало " + searchStartParam->Text + " (" + sTime + ")";
            isNext = true;
        }

    String^ curDate = DateTime::Now.Day.ToString() + "/" + DateTime::Now.Month.ToString() + "/" + DateTime::Now.Year.ToString(); //Получаем текущую дату

    if (searchEndTime->Text != "") {
        if (isNext)
            searchQuery += " AND";
        if (searchEndTime->Text == "Принимаются") {
            searchQuery += " ТезисыДо > #" + curDate + "#";
            isNext = true;
        }    
        else {
            searchQuery += " ТезисыДо < #" + curDate + "#";
            isNext = true;
        }  
    }

    if (!isNext)
        searchQuery = "SELECT * FROM Конференции"; //А вдруг пользователь захотел просто отсортировать? А у нас там WHERE

    //А теперь сортировка
    if (sortVisible->Checked && sortColumn->Text != "") {
        searchQuery += " ORDER BY " + sortColumn->Text;
        if (isDesc->Checked)
            searchQuery += " DESC";
    }
    this->Close();
}

//Проверяем правильность ввода в listboxы, а то юзер может не то ввести и sql запрос поломается
System::Void DBconference2::SearchForm::searchStartParam_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!searchStartParam->Items->Contains(searchStartParam->Text))
        searchStartParam->Text = "";
}
System::Void DBconference2::SearchForm::searchStartParam_TextUpdate(System::Object^ sender, System::EventArgs^ e)
{
    if (!searchStartParam->Items->Contains(searchStartParam->Text))
        searchStartParam->Text = "";
}
System::Void DBconference2::SearchForm::searchEndTime_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!searchEndTime->Items->Contains(searchEndTime->Text))
        searchEndTime->Text = "";
}
System::Void DBconference2::SearchForm::searchEndTime_TextUpdate(System::Object^ sender, System::EventArgs^ e)
{
    if (!searchEndTime->Items->Contains(searchEndTime->Text))
        searchEndTime->Text = "";
}
System::Void DBconference2::SearchForm::sortColumn_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!sortColumn->Items->Contains(sortColumn->Text))
        sortColumn->Text = "";
}
System::Void DBconference2::SearchForm::sortColumn_TextUpdate(System::Object^ sender, System::EventArgs^ e)
{
    if (!sortColumn->Items->Contains(sortColumn->Text))
        sortColumn->Text = "";
}
