//
// Created by sergey on 05.08.23.
//

#ifndef LAB_1_PERSON_H
#define LAB_1_PERSON_H


#include <string>

class Person {
protected:
    std::string fullName = {};//поле для хранения имени
public:
    Person() = default;//конструктор по умолчанию
    explicit Person(const std::string& fullName){this->fullName = fullName;};//конструктор с параметром строка
    std::string getName(){return fullName;};//метод для получения имени
};


#endif //LAB_1_PERSON_H
