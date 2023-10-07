#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdio>

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
};


int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PhoneBook phoneBook;

    while (true) {
        std::cout << "Выберите операцию:" << std::endl;
        std::cout << "1. Добавить контакт" << std::endl;
        std::cout << "2. Показать контакт" << std::endl;
        std::cout << "3. Выйти" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 3) {
            break;
        }

        switch (choice) {
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
            break;
        }
        case 2: {
            phoneBook.printContact();
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
    Info{ (!InfoP.empty()) ? new std::string(InfoP) : nullptr } {}

// Реализация конструктора по умолчанию
PhoneBook::PhoneBook()
    : name(nullptr), HomePhone(0), WorkPhone(0), MobilePhone(0), Info(nullptr) {}

// Реализация деструктора
PhoneBook::~PhoneBook() {
    delete name;
    delete Info;
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
