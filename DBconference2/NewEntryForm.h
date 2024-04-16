#pragma once

namespace DBconference2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для NewEntryForm
	/// </summary>
	public ref class NewEntryForm : public System::Windows::Forms::Form
	{
	public:
		NewEntryForm(String^ dbPath)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			path = dbPath;
		}
		String^ id;
		String^ path;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~NewEntryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ addButton;

	private: System::Windows::Forms::TextBox^ entryTheme;

	private: System::Windows::Forms::TextBox^ entryCity;

	private: System::Windows::Forms::DateTimePicker^ entryStartTime;

	private: System::Windows::Forms::DateTimePicker^ entryEndTime;





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->entryTheme = (gcnew System::Windows::Forms::TextBox());
			this->entryCity = (gcnew System::Windows::Forms::TextBox());
			this->entryStartTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->entryEndTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(10, 7);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Тема конференции:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(10, 62);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Город проведения:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(10, 114);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Дата начала:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(10, 169);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(174, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Тезисы принимаются до:";
			// 
			// addButton
			// 
			this->addButton->BackColor = System::Drawing::SystemColors::Window;
			this->addButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addButton->Location = System::Drawing::Point(141, 215);
			this->addButton->Margin = System::Windows::Forms::Padding(2);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(122, 30);
			this->addButton->TabIndex = 4;
			this->addButton->Text = L"Добавить";
			this->addButton->UseVisualStyleBackColor = false;
			this->addButton->Click += gcnew System::EventHandler(this, &NewEntryForm::addButton_Click);
			// 
			// entryTheme
			// 
			this->entryTheme->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->entryTheme->Location = System::Drawing::Point(10, 29);
			this->entryTheme->Margin = System::Windows::Forms::Padding(2);
			this->entryTheme->Name = L"entryTheme";
			this->entryTheme->Size = System::Drawing::Size(243, 23);
			this->entryTheme->TabIndex = 5;
			// 
			// entryCity
			// 
			this->entryCity->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(322) {
				L"Абакан", L"Азов", L"Александров",
					L"Алексин", L"Альметьевск", L"Анапа", L"Ангарск", L"Анжеро-Судженск", L"Апатиты", L"Арзамас", L"Армавир", L"Арсеньев", L"Артем",
					L"Архангельск", L"Асбест", L"Астрахань", L"Ачинск", L"Балаково", L"Балахна", L"Балашиха", L"Балашов", L"Барнаул", L"Батайск",
					L"Белгород", L"Белебей", L"Белово", L"Белогорск (Амурская область)", L"Белорецк", L"Белореченск", L"Бердск", L"Березники", L"Березовский (Свердловская область)",
					L"Бийск", L"Биробиджан", L"Благовещенск (Амурская область)", L"Бор", L"Борисоглебск", L"Боровичи", L"Братск", L"Брянск", L"Бугульма",
					L"Буденновск", L"Бузулук", L"Буйнакск", L"Великие Луки", L"Великий Новгород", L"Верхняя Пышма", L"Видное", L"Владивосток", L"Владикавказ",
					L"Владимир", L"Волгоград", L"Волгодонск", L"Волжск", L"Волжский", L"Вологда", L"Вольск", L"Воркута", L"Воронеж", L"Воскресенск",
					L"Воткинск", L"Всеволожск", L"Выборг", L"Выкса", L"Вязьма", L"Гатчина", L"Геленджик", L"Георгиевск", L"Глазов", L"Горно-Алтайск",
					L"Грозный", L"Губкин", L"Гудермес", L"Гуково", L"Гусь-Хрустальный", L"Дербент", L"Дзержинск", L"Димитровград", L"Дмитров", L"Долгопрудный",
					L"Домодедово", L"Донской", L"Дубна", L"Евпатория", L"Егорьевск", L"Ейск", L"Екатеринбург", L"Елабуга", L"Елец", L"Ессентуки",
					L"Железногорск (Красноярский край)", L"Железногорск (Курская область)", L"Жигулевск", L"Жуковский", L"Заречный", L"Зеленогорск",
					L"Зеленодольск", L"Златоуст", L"Иваново", L"Ивантеевка", L"Ижевск", L"Избербаш", L"Иркутск", L"Искитим", L"Ишим", L"Ишимбай",
					L"Йошкар-Ола", L"Казань", L"Калининград", L"Калуга", L"Каменск-Уральский", L"Каменск-Шахтинский", L"Камышин", L"Канск", L"Каспийск",
					L"Кемерово", L"Керчь", L"Кинешма", L"Кириши", L"Киров (Кировская область)", L"Кирово-Чепецк", L"Киселевск", L"Кисловодск", L"Клин",
					L"Клинцы", L"Ковров", L"Когалым", L"Коломна", L"Комсомольск-на-Амуре", L"Копейск", L"Королев", L"Кострома", L"Котлас", L"Красногорск",
					L"Краснодар", L"Краснокаменск", L"Краснокамск", L"Краснотурьинск", L"Красноярск", L"Кропоткин", L"Крымск", L"Кстово", L"Кузнецк",
					L"Кумертау", L"Кунгур", L"Курган", L"Курск", L"Кызыл", L"Лабинск", L"Лениногорск", L"Ленинск-Кузнецкий", L"Лесосибирск", L"Липецк",
					L"Лиски", L"Лобня", L"Лысьва", L"Лыткарино", L"Люберцы", L"Магадан", L"Магнитогорск", L"Майкоп", L"Махачкала", L"Междуреченск",
					L"Мелеуз", L"Миасс", L"Минеральные Воды", L"Минусинск", L"Михайловка", L"Михайловск (Ставропольский край)", L"Мичуринск", L"Москва",
					L"Мурманск", L"Муром", L"Мытищи", L"Набережные Челны", L"Назарово", L"Назрань", L"Нальчик", L"Наро-Фоминск", L"Находка", L"Невинномысск",
					L"Нерюнгри", L"Нефтекамск", L"Нефтеюганск", L"Нижневартовск", L"Нижнекамск", L"Нижний Новгород", L"Нижний Тагил", L"Новоалтайск",
					L"Новокузнецк", L"Новокуйбышевск", L"Новомосковск", L"Новороссийск", L"Новосибирск", L"Новотроицк", L"Новоуральск", L"Новочебоксарск",
					L"Новочеркасск", L"Новошахтинск", L"Новый Уренгой", L"Ногинск", L"Норильск", L"Ноябрьск", L"Нягань", L"Обнинск", L"Одинцово",
					L"Озерск (Челябинская область)", L"Октябрьский", L"Омск", L"Орел", L"Оренбург", L"Орехово-Зуево", L"Орск", L"Павлово", L"Павловский Посад",
					L"Пенза", L"Первоуральск", L"Пермь", L"Петрозаводск", L"Петропавловск-Камчатский", L"Подольск", L"Полевской", L"Прокопьевск",
					L"Прохладный", L"Псков", L"Пушкино", L"Пятигорск", L"Раменское", L"Ревда", L"Реутов", L"Ржев", L"Рославль", L"Россошь", L"Ростов-на-Дону",
					L"Рубцовск", L"Рыбинск", L"Рязань", L"Салават", L"Сальск", L"Самара", L"Санкт-Петербург", L"Саранск", L"Сарапул", L"Саратов",
					L"Саров", L"Свободный", L"Севастополь", L"Северодвинск", L"Северск", L"Сергиев Посад", L"Серов", L"Серпухов", L"Сертолово", L"Сибай",
					L"Симферополь", L"Славянск-на-Кубани", L"Смоленск", L"Соликамск", L"Солнечногорск", L"Сосновый Бор", L"Сочи", L"Ставрополь",
					L"Старый Оскол", L"Стерлитамак", L"Ступино", L"Сургут", L"Сызрань", L"Сыктывкар", L"Таганрог", L"Тамбов", L"Тверь", L"Тимашевск",
					L"Тихвин", L"Тихорецк", L"Тобольск", L"Тольятти", L"Томск", L"Троицк", L"Туапсе", L"Туймазы", L"Тула", L"Тюмень", L"Узловая",
					L"Улан-Удэ", L"Ульяновск", L"Урус-Мартан", L"Усолье-Сибирское", L"Уссурийск", L"Усть-Илимск", L"Уфа", L"Ухта", L"Феодосия", L"Фрязино",
					L"Хабаровск", L"Ханты-Мансийск", L"Хасавюрт", L"Химки", L"Чайковский", L"Чапаевск", L"Чебоксары", L"Челябинск", L"Черемхово",
					L"Череповец", L"Черкесск", L"Черногорск", L"Чехов", L"Чистополь", L"Чита", L"Шадринск", L"Шали", L"Шахты", L"Шуя", L"Щекино",
					L"Щелково", L"Электросталь", L"Элиста", L"Энгельс", L"Южно-Сахалинск", L"Юрга", L"Якутск", L"Ялта", L"Ярославль"
			});
			this->entryCity->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->entryCity->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->entryCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->entryCity->Location = System::Drawing::Point(10, 82);
			this->entryCity->Margin = System::Windows::Forms::Padding(2);
			this->entryCity->Name = L"entryCity";
			this->entryCity->Size = System::Drawing::Size(243, 23);
			this->entryCity->TabIndex = 6;
			// 
			// entryStartTime
			// 
			this->entryStartTime->CustomFormat = L"dd.MM.yyyy";
			this->entryStartTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->entryStartTime->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->entryStartTime->Location = System::Drawing::Point(10, 137);
			this->entryStartTime->Margin = System::Windows::Forms::Padding(2);
			this->entryStartTime->Name = L"entryStartTime";
			this->entryStartTime->Size = System::Drawing::Size(117, 23);
			this->entryStartTime->TabIndex = 7;
			// 
			// entryEndTime
			// 
			this->entryEndTime->CustomFormat = L"dd.MM.yyyy";
			this->entryEndTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->entryEndTime->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->entryEndTime->Location = System::Drawing::Point(10, 191);
			this->entryEndTime->Margin = System::Windows::Forms::Padding(2);
			this->entryEndTime->Name = L"entryEndTime";
			this->entryEndTime->Size = System::Drawing::Size(117, 23);
			this->entryEndTime->TabIndex = 8;
			// 
			// NewEntryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->ClientSize = System::Drawing::Size(272, 254);
			this->Controls->Add(this->entryEndTime);
			this->Controls->Add(this->entryStartTime);
			this->Controls->Add(this->entryCity);
			this->Controls->Add(this->entryTheme);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"NewEntryForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Новая запись";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
