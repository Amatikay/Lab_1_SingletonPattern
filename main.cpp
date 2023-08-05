#include "StackTemplate.h"
#include "PersonKeeper.h"

int main(){
    //Все тесты успещно заверщены. В этом файле только демонстрация работы.

    StackTemplate<int> stack_int;
    stack_int.push(1);
    stack_int.push(2);
    stack_int.push(3);
    stack_int.print();
    while (!stack_int.isEmpty()){
        std::cout << stack_int.pop() << std::endl;
    }

    try{
        stack_int.pop();
    } catch (exceptions::EStackEmpty &e) {
        /*В конструкторе ошибки вызвано сообзение*/
    };


    PersonKeeper* keeper = PersonKeeper::getInstance();
    keeper->readPersons("../data/input.txt");
    keeper->writePersons("../data/output.txt");

    return 0;
}


