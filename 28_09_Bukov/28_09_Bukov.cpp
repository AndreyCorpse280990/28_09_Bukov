#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

class PhoneBook
{
private:
    std::string* name;
    unsigned int HomePhone;
    unsigned int WorkPhone;
    unsigned int MobilePhone;
    std::string* Info;

public:
    // Конструктор с полным набором параметров
    PhoneBook(const std::string& nameP, unsigned int HomePhoneP, unsigned int WorkPhoneP, unsigned int MobilePhoneP, const std::string& InfoP);

    // Конструктор по умолчанию
    PhoneBook();

    // деструктор
    ~PhoneBook();

    // Метод для отображения контакта
    void printContact() const;

    // Метод для добавления контакта
    void addContact(const std::string& contactName, unsigned int homePhone, unsigned int workPhone, unsigned int mobilePhone, const std::string& info);

    // Метод для сохранения данных в файл
    void saveToFile();

    // Метод для загрузки контакта из файла по имени
    void loadFromFile(const std::string& filename, const std::string& contactName);

    // Функция для вывода списка контактов в файле
    void listContacts(const std::string& filename);
};

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PhoneBook phoneBook;
    while (true)
    {
        std::cout << "Выберите операцию:" << std::endl;
        std::cout << "1. Добавить контакт" << std::endl;
        std::cout << "2. Показать контакт" << std::endl;
        std::cout << "3. Загрузить контакт из файла" << std::endl;
        std::cout << "4. Выйти" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 4)
        {
            break;
        }

        switch (choice)
        {
        case 1: {
            unsigned int homePhone, workPhone, mobilePhone;
            std::string info;

            std::cin.ignore();
            std::cout << "Введите ФИО: ";
            std::string contactName;
            std::getline(std::cin, contactName);

            std::cout << "Введите домашний телефон: ";
            std::cin >> homePhone;

            std::cout << "Введите рабочий телефон: ";
            std::cin >> workPhone;

            std::cout << "Введите мобильный телефон: ";
            std::cin >> mobilePhone;

            std::cin.ignore();
            std::cout << "Введите дополнительную информацию: ";
            std::getline(std::cin, info);

            phoneBook.addContact(contactName, homePhone, workPhone, mobilePhone, info);
            std::cout << "Контакт '" << contactName << "' добавлен в телефонную книгу." << std::endl;

            std::cout << "Желаете сохранить этот контакт в файл? (да/нет): ";
            std::string saveChoice;
            std::cin >> saveChoice;
            if (saveChoice == "да") {
                phoneBook.saveToFile();
                std::cout << "Контакт сохранен в файле: phone.txt" << std::endl;
            }

            break;
        }
        case 2: {
            phoneBook.printContact();
            break;
        }
        case 3: {
            phoneBook.listContacts("phone.txt");
            std::cout << "Введите имя контакта, который хотите загрузить из phone.txt: ";
            std::string contactToLoad;
            std::cin.ignore();
            std::getline(std::cin, contactToLoad);

            // Загрузить контакт по имени
            phoneBook.loadFromFile("phone.txt", contactToLoad);
            std::cout << "Контакт '" << contactToLoad << "' загружен." << std::endl;
            break;
        }

        default:
            std::cout << "Некорректный выбор. Попробуйте еще раз." << std::endl;
        }
    }

    return 0;
}


// Реализация конструктора с полным набором параметров
PhoneBook::PhoneBook(const std::string& nameP, unsigned int HomePhoneP, unsigned int WorkPhoneP, unsigned int MobilePhoneP, const std::string& InfoP)
    : name{ (!nameP.empty()) ? new std::string(nameP) : nullptr },
    HomePhone{ HomePhoneP },
    WorkPhone{ WorkPhoneP },
    MobilePhone{ MobilePhoneP },
    Info{ (!InfoP.empty()) ? new std::string(InfoP) : nullptr }
{
    std::cout << "Конструктор c полным набором параметров отработал" << std::endl;
}

// Реализация конструктора по умолчанию
PhoneBook::PhoneBook()
    : name(nullptr), HomePhone(0), WorkPhone(0), MobilePhone(0), Info(nullptr)
{
    std::cout << "Конструктор по умолчанию отработал" << std::endl;
}


// Реализация деструктора
PhoneBook::~PhoneBook() {
    delete name;
    delete Info;
    std::cout << "Деструктор отработал  " << std::endl;
}

// Реализация метода для отображения контакта
void PhoneBook::printContact() const {
    if (name != nullptr && Info != nullptr) {
        std::cout << "Имя: " << *name << std::endl;
        std::cout << "Домашний телефон: " << HomePhone << std::endl;
        std::cout << "Рабочий телефон: " << WorkPhone << std::endl;
        std::cout << "Мобильный телефон: " << MobilePhone << std::endl;
        std::cout << "Дополнительная информация: " << *Info << std::endl;
    }
    else {
        std::cout << "Контакт не содержит данных." << std::endl;
    }
}

// Реализация метода для добавления контакта
void PhoneBook::addContact(const std::string& contactName, unsigned int homePhone, unsigned int workPhone, unsigned int mobilePhone, const std::string& info) {
    if (name != nullptr) {
        delete name;
        name = nullptr;
    }
    if (Info != nullptr) {
        delete Info;
        Info = nullptr;
    }

    name = new std::string(contactName);
    HomePhone = homePhone;
    WorkPhone = workPhone;
    MobilePhone = mobilePhone;
    Info = new std::string(info);
}

// Реализация метода для сохранения в файл  
void PhoneBook::saveToFile()
{
    std::ofstream file("phone.txt", std::ofstream::out | std::ofstream::app);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла phone.txt" << std::endl;
        return;
    }

    file << *name << std::endl;
    file << HomePhone << std::endl;
    file << WorkPhone << std::endl;
    file << MobilePhone << std::endl;
    file << *Info << std::endl;

    file.close();
}

// Функция для вывода списка контактов в файле
void PhoneBook::listContacts(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    std::string line;
    std::cout << "Список контактов в файле " << filename << ":" << std::endl;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;

        // Пропускаем строки (телефоны и дополнительную информацию)
        for (int i = 0; i < 4; ++i)
        {
            std::getline(file, line);
        }
    }

    file.close();
}


// Реализация метода для загрузки контакта из файла по имени
void PhoneBook::loadFromFile(const std::string& filename, const std::string& contactName)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    // Очищаем текущий контакт
    if (name != nullptr)
    {
        delete name;
        name = nullptr;
    }
    if (Info != nullptr)
    {
        delete Info;
        Info = nullptr;
    }

    std::string line;
    bool found = false;
    while (std::getline(file, line))
    {
        if (line == contactName)
        {
            name = new std::string(line); // Записываем ФИО

            // Считываем далее строки (телефоны и дополнительную информацию)
            std::getline(file, line); // Домашний телефон
            HomePhone = std::stoul(line);

            std::getline(file, line); // Рабочий телефон
            WorkPhone = std::stoul(line);

            std::getline(file, line); // Мобильный телефон
            MobilePhone = std::stoul(line);

            std::getline(file, line); // Дополнительная информация
            Info = new std::string(line);

            found = true;
            break;
        }
        else
        {
            // Пропускаем строки (телефоны и дополнительную информацию)
            std::getline(file, line);
            std::getline(file, line);
            std::getline(file, line);
            std::getline(file, line);
        }
    }

    // Если контакт был найден, выводим сообщение
    if (found)
    {
        std::cout << "Контакт '" << contactName << "' загружен." << std::endl;
    }
    else
    {
        std::cout << "Контакт с именем '" << contactName << "' не найден в файле." << std::endl;
    }

    file.close();
}
