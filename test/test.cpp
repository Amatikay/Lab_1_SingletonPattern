//
// Created by sergey on 20.09.23.
//
#include <gtest/gtest.h>
#include "../include/StackTemplate.h"
#include "../include/PersonKeeper.h"


/*
 * Тестирование класса StackTemplate
 * Первая часть Лабораторной работы №1
 */

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

/*
 * Тестирование класса PersonKeeper
 * Вторая часть Лабораторной работы №1
 */

TEST(PersonKeeperTest, CanGetInstance)//тест на создание экземпляра класса
{
    PersonKeeper* instance1 = PersonKeeper::getInstance();//создание экземпляра класса
    ASSERT_NE(nullptr, instance1);//проверка на то что экземпляр класса не пустой
    PersonKeeper* instance2 = PersonKeeper::getInstance();//создание экземпляра класса
    ASSERT_EQ(instance1, instance2);//проверка на то что экземпляры класса равны
}

TEST(PersonKeeperTest, CanReadAndWritePersons)//тест на чтение и запись данных
{
    // Подготовка тестируемых данных - создание и запись в файл данных
    const std::string inputFilename = "../data/input_for_test.txt";
    const std::string outputFilename = "../data/output_for_test.txt";
    std::ofstream inputFile(inputFilename);// открытие файла на запись
    if(!inputFile.is_open()){//проверка на то что файл открыт
        throw exceptions::ExceptionFile("File not open");
    }
    std::vector<std::string> testPersons = {"Кирильков Иван Петрович",
                                            "Васильев Николай Иванович",
                                            "Петров Иван Николаевич",
    };
    for(size_t i = 0;i<testPersons.size();i++){//запись в файл подготовленных данных
        inputFile << testPersons[i] << std::endl;
    }
    inputFile.close();

    // Чтение и запись данных с помощью PersonKeeper
    PersonKeeper* keeper = PersonKeeper::getInstance();
    keeper->readPersons(inputFilename);
    keeper->writePersons(outputFilename);

    // Проверка равенства данных в исходном и выходном файлах
    std::ifstream outputFile(outputFilename);
    std::reverse(testPersons.begin(), testPersons.end()); //так как используется вектор то все персоны будут в обратном порядке.
    // разверну вектор имен для теста.
    for (size_t i = 0; i < testPersons.size(); ++i)//проверка на то что данные в файле совпадают с тестовыми данными
    {
        std::string actualPerson;//переменная для хранения данных из файла
        getline(outputFile, actualPerson);//чтение данных из файла
        ASSERT_EQ(actualPerson, testPersons[i]);//проверка на совпадение данных из файла с тестовыми данными
    }
    outputFile.close();//закрытие файла

    // Удаление тестовых файлов
    remove(inputFilename.c_str());
    remove(outputFilename.c_str());
}



int main() { //Запуск тестов
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}