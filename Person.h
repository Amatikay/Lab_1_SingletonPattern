//
// Created by sergey on 05.08.23.
//

#ifndef LAB_1_PERSON_H
#define LAB_1_PERSON_H


#include <string>

class Person {
protected:
    std::string fullName = {};
public:
    Person() = default;
    explicit Person(const std::string& fullName){this->fullName = fullName;};
    std::string getName(){return fullName;};
};


#endif //LAB_1_PERSON_H
