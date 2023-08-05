//
// Created by sergey on 05.08.23.
//

#ifndef LAB_1_PERSONKEEPER_H
#define LAB_1_PERSONKEEPER_H


#include <fstream>
#include "Person.h"
#include "StackTemplate.h"
#include "Exception.h"

class PersonKeeper : public Person {
private:
    static PersonKeeper* instance;
    StackTemplate<Person> personsStack;
    PersonKeeper() {}
public:
    static PersonKeeper* getInstance() {
        if (instance == nullptr)
            instance = new PersonKeeper();
        return instance;
    }

    void readPersons(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw exceptions::ExceptionFile("File not exist");
        }
        std::string str;
        while (std::getline(file, str)) {
            personsStack.push(Person(str));
        }
        file.close();
    }

    void writePersons(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw exceptions::ExceptionFile("File not exist");
        }
        while (!personsStack.isEmpty()) {
            file << personsStack.pop().getName() << std::endl;
        }
        file.close();
    }
};

PersonKeeper* PersonKeeper::instance = nullptr;



#endif //LAB_1_PERSONKEEPER_H
