#include <iostream>
#include <fstream>
#include "Chat.h"

void Chat::startChat()
{
    work_ = true;
}

std::shared_ptr<User> Chat::getUserLog(const std::string& login) const
{
    for (const auto& user : userArr_)
    {
        if (login == user.getlog())
        {
            return std::make_shared<User>(user);
        }
    }
    return nullptr;
}

std::shared_ptr<User> Chat::getUserName(const std::string& name) const
{
    for (const auto& user : userArr_)
    {
        if (name == user.getName())
        {
            return std::make_shared<User>(user);
        }
    }
    return nullptr;
}

void Chat::userLogin()
{
    const std::string login_check = "login.txt";
    const std::string password_check = "password.txt";
    std::ifstream log(login_check);
    std::ifstream pass(password_check);
    std::string login, password;
    if (!log.is_open() && !pass.is_open())
    {
        std::cout << "Ошибка!" << std::endl;
    }
    else {
        do
        {
            char op;


            while (!log.eof())
            {
                login = "";
                log >> login;
            }
            while (!pass.eof())
            {
                password = "";
                pass >> password;
            }
            std::string _log;
            std::string _pass;
            std::cout << "Авторизация." << std::endl;
            std::cout << "Логин: " << std::endl;
            std::cin >> _log;
            std::cout << "Пароль: " << std::endl;
            std::cin >> _pass;
            if (_log != login && _pass != password)
            {
                std::cout << "Пароль или логин введен не правильно!" << std::endl;
            }
            else
            {
                currentUser_ = getUserLog(login);
            }
        } while (!currentUser_);
    }
}

void Chat::userRegistration()
{
    std::cout << "Регистрация" << std::endl;
    const std::string login_check = "login.txt";
    const std::string password_check = "password";




}

void Chat::showAllUsers() const
{
    for (const auto& user : userArr_)
    {
        cout << user.getName() << endl;
    }
}

void Chat::showChat() const
{
    for (const auto& message : messageArr_)
    {
        cout << message << endl; // видимо здесь надо было преобразовать в const char *, но если я помню, то на курсе такому не учили, по крайней мере у меня не получилось)
    }
}

void Chat::showLoginMenu()
{
    char op;
    while (!currentUser_)
    {
        cout << "1 - Регистрация, 2 - Авторизация, 0 - выход" << endl;
        cin >> op;


        switch (op)
        {
        case '1':
            try
            {
                userRegistration();
            }
            catch (const UserLoginEx& e)
            {
                cout << e.what() << endl;
            }
            break;
        case '2':
            userLogin();
            break;
        case '0':
            work_ = false;
            break;
        default:
            cout << "Введите 1,2 или 0" << endl;
        }
    }
}