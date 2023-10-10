//
// Created by sergey on 05.08.23.
//

#ifndef LAB_1_PERSONKEEPER_H
#define LAB_1_PERSONKEEPER_H


#include <fstream>
#include "Person.h"
#include "StackTemplate.h"
#include "Exception.h"

class PersonKeeper {//Класс PersonKeeper. Реализованный в соответствии с паттерном Singleton
private:
    static PersonKeeper* instance;//ссылка на единственный экземпляр класса. Статическое поле класса. будет иметь одно значение для всех
                                  //экземпляров класса и будет существовать вне зависимости от того, созданы какие-либо экземпляры класса или нет.
                                  //тк инициализируется как nullptr при запуске программы, а создание экземпляра при первом вызове  getInstanse()
    StackTemplate<Person> personsStack;//стек для хранения персон
    PersonKeeper() {}//конструктор приватный для реализации паттерна Singleton
public:
    static PersonKeeper* getInstance() {//статический метод для получения экземпляра класса. Ленивая инициализация.
                                        //Если экземпляр класса не создан, то создается новый экземпляр класса.
                                        //Статический метод принадлежит классу, а не его экземпляру, поэтому он может быть вызван без создания экземпляра класса.
        if (instance == nullptr)
            instance = new PersonKeeper();
        return instance;
    }


    //readPersons и writePersons реализованы не в соответсвии с принципами SOLID.
    //Эти методы зависят от конкретной реализации получения данных.
    //Если я захочу - я не смогу перенаправить вывод или ввод не изменяя реализацию самих методов.
    //Для решения этой проблемы можно в качестве аргумента передавать поток (не обязательно std, это может быть какой то буфер)
    //и пусть метод из него получает данные
    //readPersons(std::istream& input)  и writePersons(std::ostream& output)
    //Я этого не делаю, так как в задании сказано получать данные из файла и выводить в файл.
    void readPersons(const std::string& filename) {//метод для чтения персон из файла
        std::ifstream file(filename);//открытие файла
        if (!file.is_open()) {//проверка на то что файл открыт
            throw exceptions::ExceptionFile("File is not open");//выброс исключения, если файл не открыт
        }
        std::string str;//переменная для хранения строки из файла
        while (std::getline(file, str)) {//чтение строки из файла
            personsStack.push(Person(str));//добавление персоны в стек
        }
        file.close();//закрытие файла
    }

    void writePersons(const std::string& filename) {//метод для записи персон в файл
        std::ofstream file(filename);//открытие файла
        if (!file.is_open()) {//проверка на то что файл открыт
            throw exceptions::ExceptionFile("File is not open");// выброс исключения, если файл не открыт
        }
        while (!personsStack.isEmpty()) {//пока стек не пустой
            file << personsStack.pop().getName() << std::endl;//запись персоны в файл
        }
        file.close();//закрытие файла
    }
};

PersonKeeper* PersonKeeper::instance = nullptr;//инициализация экземпляра класса как пустого указателя.



#endif //LAB_1_PERSONKEEPER_H
