#include "StackTemplate.h"

int main(){
    StackTemplate<int> stack;
    stack.push(1);
    stack.push(2);
    StackTemplate<int> stack2(stack);
//    stack.print();
//    stack2.print();






    return 0;
}


