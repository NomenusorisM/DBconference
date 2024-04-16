#include "SearchForm.h"

System::String^ DBconference2::SearchForm::ReDate(String^ date) //��������������� ������ ��2003
{
    // 02.11.2021 0:00 : 00 (������ �� �����)
    // #2009/04/21# (������ �� ������)
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
    // ��������� ������ �� ������� ������������ ������� "'"
    if (searchTheme->Text->Contains("'") ||
        searchCity->Text->Contains("'")) {
        MessageBox::Show(
            "����� ������������ ������ (')!",
            "��������!",
            MessageBoxButtons::OK,
            MessageBoxIcon::Warning);
        return;
    }

    //������� ��������

    searchQuery = "SELECT * FROM ����������� WHERE";

    bool isNext = false; //��� ����� �����, ����� ��� AND ��� ���

    if (searchTheme->Text != "" && !searchTheme->Text->Contains("'")) {
        searchQuery += " ���� = '" + searchTheme->Text + "'";
        isNext = true;
    }

    if (searchCity->Text != "" && isNext && !searchCity->Text->Contains("'")) {
        searchQuery += " AND ����� = '" + searchCity->Text + "'";
    }
    else
        if (searchCity->Text != "" && !searchCity->Text->Contains("'")) {
            searchQuery += " ����� = '" + searchCity->Text + "'";
            isNext = true;
        }

    if(searchStartParam->Text !="" && isNext && !searchStartParam->Text->Contains("'")){
        String^ sTime = ReDate(searchStartTime->Text);
        searchQuery += " AND ������ " + searchStartParam->Text + " (" + sTime + ")";
    }   
    else 
        if (searchStartParam->Text != "" && !isNext && !searchStartParam->Text->Contains("'")) {
            String^ sTime = ReDate(searchStartTime->Text);
            searchQuery += " ������ " + searchStartParam->Text + " (" + sTime + ")";
            isNext = true;
        }

    String^ curDate = DateTime::Now.Day.ToString() + "/" + DateTime::Now.Month.ToString() + "/" + DateTime::Now.Year.ToString(); //�������� ������� ����

    if (searchEndTime->Text != "") {
        if (isNext)
            searchQuery += " AND";
        if (searchEndTime->Text == "�����������") {
            searchQuery += " �������� > #" + curDate + "#";
            isNext = true;
        }    
        else {
            searchQuery += " �������� < #" + curDate + "#";
            isNext = true;
        }  
    }

    if (!isNext)
        searchQuery = "SELECT * FROM �����������"; //� ����� ������������ ������� ������ �������������? � � ��� ��� WHERE

    //� ������ ����������
    if (sortVisible->Checked && sortColumn->Text != "") {
        searchQuery += " ORDER BY " + sortColumn->Text;
        if (isDesc->Checked)
            searchQuery += " DESC";
    }
    this->Close();
}

//��������� ������������ ����� � listbox�, � �� ���� ����� �� �� ������ � sql ������ ����������
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
