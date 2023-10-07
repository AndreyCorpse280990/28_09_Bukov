#include <iostream>
#include <string>

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
    PhoneBook(const std::string& nameP, unsigned int HomePhoneP, unsigned int WorkPhoneP, unsigned int MobilePhoneP, const std::string& InfoP)
        : name{ (!nameP.empty()) ? new std::string(nameP) : nullptr },
        HomePhone{ HomePhoneP },
        WorkPhone{ WorkPhoneP },
        MobilePhone{ MobilePhoneP },
        Info{ (!InfoP.empty()) ? new std::string(InfoP) : nullptr }
    {
        std::cout << "Конструктор с полным набором параметров отработал" << std::endl;
    }

    // Конструктор по умолчанию
    PhoneBook()
        : name(nullptr), HomePhone(0), WorkPhone(0), MobilePhone(0), Info(nullptr)
    {
        std::cout << "Конструктор по умолчанию отработал" << std::endl;
    }

    // конструктор с именем
    PhoneBook(const std::string& nameP)
        : name{ (!nameP.empty()) ? new std::string(nameP) : nullptr },
        HomePhone(0), WorkPhone(0), MobilePhone(0), Info(nullptr)
    {
        std::cout << "Конструктор c 1 параметром отработал" << std::endl;
    }

    // конструктор с именем, дом телефоном
    PhoneBook(const std::string& nameP, unsigned int HomePhoneP)
        : name{ (!nameP.empty()) ? new std::string(nameP) : nullptr },
        HomePhone{ HomePhoneP }, WorkPhone(0), MobilePhone(0), Info(nullptr)
    {
        std::cout << "Конструктор с 2 параметрами отработал" << std::endl;
    }

    // конструктор именем, домашним, рабочим телефоном
    PhoneBook(const std::string& nameP, unsigned int HomePhoneP, unsigned int WorkPhoneP)
        : name{ (!nameP.empty()) ? new std::string(nameP) : nullptr },
        HomePhone{ HomePhoneP }, WorkPhone{ WorkPhoneP }, MobilePhone(0), Info(nullptr)
    {
        std::cout << "Конструктор с 3 параметрами отработал" << std::endl;
    }

    // конструктор с именем, домашним, рабочим и мобильным телефоном
    PhoneBook(const std::string& nameP, unsigned int HomePhoneP, unsigned int WorkPhoneP, unsigned int MobilePhoneP)
        : name{ (!nameP.empty()) ? new std::string(nameP) : nullptr },
        HomePhone{ HomePhoneP }, WorkPhone{ WorkPhoneP }, MobilePhone{ MobilePhoneP }, Info(nullptr)
    {
        std::cout << "Конструктор с 4 параметрами отработал" << std::endl;
    }

    // дестуктор
    ~PhoneBook()
    {
        delete name;
        delete Info;
    }


};

int main()
{
    setlocale(LC_ALL, "rus");
    PhoneBook per1;
    return 0;
}
