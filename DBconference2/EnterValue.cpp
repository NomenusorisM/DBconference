#include "EnterValue.h"

System::Void DBconference2::EnterValue::buttonConfirm_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (result->Text == "")
		MessageBox::Show(
			"Введите значение!",
			"Внимание",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
	else {
		resValue = result->Text;
		this->Close();
	}
}

