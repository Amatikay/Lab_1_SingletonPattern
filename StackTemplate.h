//
// Created by sergey on 04.08.23.
//

#ifndef LAB_1_STACKTEMPLATE_H
#define LAB_1_STACKTEMPLATE_H

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "StackTemplate.h"
#include "Exception.h"

template <typename T>
class Node{
public:
    Node *next;
    T value{};
    explicit Node(T value) {this->next = nullptr; this->value = value;};//запрет неявного преобразования типов в конструкторе
    Node() {this->next = nullptr;};
    ~Node(){ /*ничего не нужно очищать*/ };
};




template <typename T>
class StackTemplate{
public:
    StackTemplate() {this->head = nullptr;};//конструктор по умолчанию.
    StackTemplate(StackTemplate const &stack);//конструктор копирования
    ~StackTemplate();//деструктор. Явная реализация требуется. Память под узлы односвязного спика я выделяю в куче.
                    // Так как я заранее не могу знать количество элементов в стеке.
    void push(T value);//метод для добавления элемента в стек
    T pop();//метод для извлечения элемента из стека
           // в случае пустого стека выбрасывается исключение EStackEmpty.


    size_t getSize();//метод для получения размера стека
    bool isEmpty();//метод для проверки стека на пустоту
    void print();//метод для вывода стека на экран
private:
    Node<T> *head;
    size_t size{};//инициализация нулем. Для предотвращения ошибок связанных с инициализацей мусором.

};


//Реализация методов шаблонного класса StackTemplate:

template<typename T>
void StackTemplate<T>::push(T value) {
    Node<T> *node = new Node<T>(value);//выделяю память под узел в куче
    node->next = this->head;//голова становится следующей
    this->head = node;//новый элемент становится головой
    this->size++;//увеличили размер на 1
}

template<typename T>
T StackTemplate<T>::pop(){
    if (this->head == nullptr) {
        throw exceptions::EStackEmpty("Stack is empty");
    }
    Node<T> *node = this->head; // сохраняем указатель на голову
    this->head = this->head->next;//голова становится следующей
    T value = node->value;//сохраняем значение
    delete node;//удаляем узел, который раньше был головой
    this->size--;//уменьшаем размер на 1
    return value;//возвращаем значение
}

template<typename T>
size_t StackTemplate<T>::getSize(){
    return this->size;
}

template<typename T>
bool StackTemplate<T>::isEmpty(){
    return this->size == 0;
}

template<typename T>
void StackTemplate<T>::print(){//перебираю каждый узел списка и вывожу его на экран
    // элементы будут выводиться в обратном порядке
    Node<T> *node = this->head;//сохраняем указатель на голову
    while (node != nullptr){//пока есть элементы в списке
        std::cout << node->value << std::endl;//выводим значение узла
        node = node->next;//переход к следующему узлу
    }
}

template<typename T>
StackTemplate<T>::StackTemplate(StackTemplate const &stack) {//копирую каждый узел стека в новый стек
    // пока не появится нулевой указатель.
    // так же будет обратный порядок.По идее стека это не является проблемой.
    // если это проблема - то самый простой способ - произвести копию скопированного стека.
    head = nullptr;//изначально голова пустая
    Node<T> *node = stack.head; // сохраняем указатель на голову стека, который копирую
    while (node != nullptr){ // пока есть элементы в списке
        this->push(node->value); // пуш в создаваемый стек элементы из копируемого
        node = node->next;//переход к следующему узлу
    }
}

template<typename T>
StackTemplate<T>::~StackTemplate() {
    while (this->head != nullptr){//пока голова не станет нулевой
        Node<T> *node = this->head;//сохраняем указатель на голову в текущей итерации
        this->head = this->head->next;//голова становится следующей
        delete node;//удаляем узел, который раньше был головой
    }
}

#endif //LAB_1_STACKTEMPLATE_H
