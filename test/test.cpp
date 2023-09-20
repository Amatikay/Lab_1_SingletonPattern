//
// Created by sergey on 20.09.23.
//
#include <gtest/gtest.h>
#include "../include/StackTemplate.h"

TEST(StackTest, IsEmpty) {//Проверка того, что новый стек пуст
    StackTemplate<int> stack;
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackTest, PushAndSize) {//Проверка того, что размер стека увеличивается при добавлении элемента
    // и что стек не пустой после добавления элемента
    StackTemplate<int> stack;
    stack.push(1);
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(stack.getSize(), 1);
}

TEST(StackTest, PopAndSize) {//Проверка того, что размер стека уменьшается при извлечении элемента
    // и что стек пустой после извлечения элемента
    StackTemplate<int> stack;
    stack.push(2);
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.getSize(), 0);
}

TEST(StackTest, PopFromEmpty) {//Проверка исключения при попытке извлечь элемент из пустого стека
    StackTemplate<int> stack;
    EXPECT_THROW(stack.pop(), exceptions::EStackEmpty);
}

TEST(StackTest, CopyConstructor) { // проверка конструктора копирования
    StackTemplate<int> stack;
    stack.push(1);
    stack.push(2);
    StackTemplate<int> stack2(stack);
    EXPECT_EQ(stack2.getSize(), 2);
    EXPECT_EQ(stack2.pop(), 1);
    EXPECT_EQ(stack2.pop(), 2);
}

TEST(StackTest, IsEmpty_string) {
    StackTemplate<std::string> stack;
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackTest, PushAndSize_string) {
    // и что стек не пустой после добавления элемента
    StackTemplate<std::string> stack;
    stack.push("hello");
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(stack.getSize(), 1);
}

TEST(StackTest, PopAndSize_string) {
    // и что стек пустой после извлечения элемента
    StackTemplate<std::string> stack;
    stack.push("hello");
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.getSize(), 0);
}

TEST(StackTest, PopFromEmpty_string) {
    StackTemplate<std::string> stack;
    EXPECT_THROW(stack.pop(), exceptions::EStackEmpty);
}

TEST(StackTest, CopyConstructor_string) {
    StackTemplate<std::string> stack;
    stack.push("hello");
    stack.push("world");
    StackTemplate<std::string> stack2(stack);
    EXPECT_EQ(stack2.getSize(), 2);
    EXPECT_EQ(stack2.pop(), "hello");
    EXPECT_EQ(stack2.pop(), "world");
}

int main() { //Запуск тестов
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}