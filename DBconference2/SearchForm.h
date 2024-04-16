#pragma once

namespace DBconference2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SearchForm
	/// </summary>
	public ref class SearchForm : public System::Windows::Forms::Form
	{
	public:
		SearchForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
    public:
        String^ searchQuery = ""; //Тут мы будем хранить наш sql запрос

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SearchForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Label^ label1;
    protected:
    private: System::Windows::Forms::GroupBox^ groupBox1;

    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::DateTimePicker^ searchStartTime;

    private: System::Windows::Forms::TextBox^ searchTheme;
    private: System::Windows::Forms::Label^ label2;




    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::GroupBox^ SortGroup;
    private: System::Windows::Forms::CheckBox^ sortVisible;
    private: System::Windows::Forms::ComboBox^ searchEndTime;
    private: System::Windows::Forms::ComboBox^ searchStartParam;


    private: System::Windows::Forms::ComboBox^ searchCity;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::CheckBox^ isDesc;
    private: System::Windows::Forms::ComboBox^ sortColumn;
    private: System::Windows::Forms::Button^ buttonGoSearch;


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
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->searchEndTime = (gcnew System::Windows::Forms::ComboBox());
            this->searchStartParam = (gcnew System::Windows::Forms::ComboBox());
            this->searchCity = (gcnew System::Windows::Forms::ComboBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->searchStartTime = (gcnew System::Windows::Forms::DateTimePicker());
            this->searchTheme = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SortGroup = (gcnew System::Windows::Forms::GroupBox());
            this->isDesc = (gcnew System::Windows::Forms::CheckBox());
            this->sortColumn = (gcnew System::Windows::Forms::ComboBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->sortVisible = (gcnew System::Windows::Forms::CheckBox());
            this->buttonGoSearch = (gcnew System::Windows::Forms::Button());
            this->groupBox1->SuspendLayout();
            this->SortGroup->SuspendLayout();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(5, 62);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(48, 17);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Город";
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->searchEndTime);
            this->groupBox1->Controls->Add(this->searchStartParam);
            this->groupBox1->Controls->Add(this->searchCity);
            this->groupBox1->Controls->Add(this->label4);
            this->groupBox1->Controls->Add(this->label3);
            this->groupBox1->Controls->Add(this->searchStartTime);
            this->groupBox1->Controls->Add(this->searchTheme);
            this->groupBox1->Controls->Add(this->label2);
            this->groupBox1->Controls->Add(this->label1);
            this->groupBox1->Location = System::Drawing::Point(11, 10);
            this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->groupBox1->Size = System::Drawing::Size(253, 154);
            this->groupBox1->TabIndex = 1;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Поиск";
            // 
            // searchEndTime
            // 
            this->searchEndTime->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Принимаются", L"Не принимаются" });
            this->searchEndTime->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->searchEndTime->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
            this->searchEndTime->FormattingEnabled = true;
            this->searchEndTime->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Принимаются", L"Не принимаются" });
            this->searchEndTime->Location = System::Drawing::Point(68, 119);
            this->searchEndTime->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->searchEndTime->Name = L"searchEndTime";
            this->searchEndTime->Size = System::Drawing::Size(178, 24);
            this->searchEndTime->TabIndex = 4;
            this->searchEndTime->TextUpdate += gcnew System::EventHandler(this, &SearchForm::searchEndTime_TextUpdate);
            this->searchEndTime->TextChanged += gcnew System::EventHandler(this, &SearchForm::searchEndTime_TextChanged);
            // 
            // searchStartParam
            // 
            this->searchStartParam->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(5) {
                L" ", L"не", L"=", L"до",
                    L"после"
            });
            this->searchStartParam->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->searchStartParam->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
            this->searchStartParam->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"<>", L"=", L">", L"<" });
            this->searchStartParam->Location = System::Drawing::Point(68, 89);
            this->searchStartParam->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->searchStartParam->Name = L"searchStartParam";
            this->searchStartParam->Size = System::Drawing::Size(53, 24);
            this->searchStartParam->TabIndex = 4;
            this->searchStartParam->TextUpdate += gcnew System::EventHandler(this, &SearchForm::searchStartParam_TextUpdate);
            this->searchStartParam->TextChanged += gcnew System::EventHandler(this, &SearchForm::searchStartParam_TextChanged);
            // 
            // searchCity
            // 
            this->searchCity->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(322) {
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
            this->searchCity->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->searchCity->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
            this->searchCity->FormattingEnabled = true;
            this->searchCity->Items->AddRange(gcnew cli::array< System::Object^  >(322) {
                L"Абакан", L"Азов", L"Александров", L"Алексин",
                    L"Альметьевск", L"Анапа", L"Ангарск", L"Анжеро-Судженск", L"Апатиты", L"Арзамас", L"Армавир", L"Арсеньев", L"Артем", L"Архангельск",
                    L"Асбест", L"Астрахань", L"Ачинск", L"Балаково", L"Балахна", L"Балашиха", L"Балашов", L"Барнаул", L"Батайск", L"Белгород", L"Белебей",
                    L"Белово", L"Белогорск (Амурская область)", L"Белорецк", L"Белореченск", L"Бердск", L"Березники", L"Березовский (Свердловская область)",
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
            this->searchCity->Location = System::Drawing::Point(68, 60);
            this->searchCity->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->searchCity->Name = L"searchCity";
            this->searchCity->Size = System::Drawing::Size(178, 24);
            this->searchCity->TabIndex = 4;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(5, 122);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(57, 17);
            this->label4->TabIndex = 7;
            this->label4->Text = L"Тезисы";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(5, 91);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(58, 17);
            this->label3->TabIndex = 6;
            this->label3->Text = L"Начало";
            // 
            // searchStartTime
            // 
            this->searchStartTime->CustomFormat = L"dd/MM/yyyy";
            this->searchStartTime->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
            this->searchStartTime->Location = System::Drawing::Point(124, 90);
            this->searchStartTime->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->searchStartTime->Name = L"searchStartTime";
            this->searchStartTime->Size = System::Drawing::Size(123, 22);
            this->searchStartTime->TabIndex = 4;
            this->searchStartTime->Value = System::DateTime(2023, 1, 1, 0, 0, 0, 0);
            // 
            // searchTheme
            // 
            this->searchTheme->Location = System::Drawing::Point(68, 29);
            this->searchTheme->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->searchTheme->Name = L"searchTheme";
            this->searchTheme->Size = System::Drawing::Size(178, 22);
            this->searchTheme->TabIndex = 3;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(5, 31);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(42, 17);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Тема";
            // 
            // SortGroup
            // 
            this->SortGroup->Controls->Add(this->isDesc);
            this->SortGroup->Controls->Add(this->sortColumn);
            this->SortGroup->Controls->Add(this->label5);
            this->SortGroup->Location = System::Drawing::Point(280, 44);
            this->SortGroup->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->SortGroup->Name = L"SortGroup";
            this->SortGroup->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->SortGroup->Size = System::Drawing::Size(252, 77);
            this->SortGroup->TabIndex = 2;
            this->SortGroup->TabStop = false;
            this->SortGroup->Text = L"Сортировка";
            this->SortGroup->Visible = false;
            // 
            // isDesc
            // 
            this->isDesc->AutoSize = true;
            this->isDesc->Location = System::Drawing::Point(9, 50);
            this->isDesc->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->isDesc->Name = L"isDesc";
            this->isDesc->Size = System::Drawing::Size(194, 21);
            this->isDesc->TabIndex = 2;
            this->isDesc->Text = L"от большего к меньшему";
            this->isDesc->UseVisualStyleBackColor = true;
            // 
            // sortColumn
            // 
            this->sortColumn->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(5) {
                L"№", L"Тема", L"Город", L"Начало",
                    L"ТезисыДо"
            });
            this->sortColumn->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->sortColumn->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
            this->sortColumn->FormattingEnabled = true;
            this->sortColumn->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"№", L"Тема", L"Город", L"Начало", L"ТезисыДо" });
            this->sortColumn->Location = System::Drawing::Point(95, 23);
            this->sortColumn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->sortColumn->Name = L"sortColumn";
            this->sortColumn->Size = System::Drawing::Size(151, 24);
            this->sortColumn->TabIndex = 1;
            this->sortColumn->TextUpdate += gcnew System::EventHandler(this, &SearchForm::sortColumn_TextUpdate);
            this->sortColumn->TextChanged += gcnew System::EventHandler(this, &SearchForm::sortColumn_TextChanged);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(5, 26);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(83, 17);
            this->label5->TabIndex = 0;
            this->label5->Text = L"По столбцу";
            // 
            // sortVisible
            // 
            this->sortVisible->AutoSize = true;
            this->sortVisible->Location = System::Drawing::Point(288, 15);
            this->sortVisible->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->sortVisible->Name = L"sortVisible";
            this->sortVisible->Size = System::Drawing::Size(108, 21);
            this->sortVisible->TabIndex = 3;
            this->sortVisible->Text = L"Сортировка";
            this->sortVisible->UseVisualStyleBackColor = true;
            this->sortVisible->CheckedChanged += gcnew System::EventHandler(this, &SearchForm::sortVisible_CheckedChanged);
            // 
            // buttonGoSearch
            // 
            this->buttonGoSearch->BackColor = System::Drawing::SystemColors::Window;
            this->buttonGoSearch->Cursor = System::Windows::Forms::Cursors::Hand;
            this->buttonGoSearch->Location = System::Drawing::Point(375, 135);
            this->buttonGoSearch->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->buttonGoSearch->Name = L"buttonGoSearch";
            this->buttonGoSearch->Size = System::Drawing::Size(152, 29);
            this->buttonGoSearch->TabIndex = 4;
            this->buttonGoSearch->Text = L"Выполнить";
            this->buttonGoSearch->UseVisualStyleBackColor = false;
            this->buttonGoSearch->Click += gcnew System::EventHandler(this, &SearchForm::buttonGoSearch_Click);
            // 
            // SearchForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FloralWhite;
            this->ClientSize = System::Drawing::Size(538, 172);
            this->Controls->Add(this->buttonGoSearch);
            this->Controls->Add(this->sortVisible);
            this->Controls->Add(this->SortGroup);
            this->Controls->Add(this->groupBox1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"SearchForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Поиск";
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->SortGroup->ResumeLayout(false);
            this->SortGroup->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
        private: System::String^ ReDate(String^ date);
#pragma endregion
private: System::Void sortVisible_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonGoSearch_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void searchStartParam_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void searchStartParam_TextUpdate(System::Object^ sender, System::EventArgs^ e);
private: System::Void searchEndTime_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void searchEndTime_TextUpdate(System::Object^ sender, System::EventArgs^ e);
private: System::Void sortColumn_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void sortColumn_TextUpdate(System::Object^ sender, System::EventArgs^ e);
};
}
