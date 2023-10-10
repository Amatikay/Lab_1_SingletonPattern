//
// Created by sergey on 04.08.23.
//

#ifndef LAB_1_EXCEPTION_H
#define LAB_1_EXCEPTION_H

#include <iostream>
#include <cstring>

namespace exceptions{

    class Exception{
    private:
        char* message;
    public:
//        explicit - запрет на неявное преобразование типа
        explicit Exception(const char* arg_message)
        {
            message = new char[strlen(arg_message)+1];

            strcpy(message,arg_message);
        }

        Exception(const Exception& arg)
        {
            message = new char[strlen(arg.message)+1];

            strcpy(message,arg.message);
        }

        ~Exception()
        {
            delete message;
        }

        const char* what() const{ return message; }
    };

    class ExceptionData: public Exception{//обработка исключений связанными с некорректными данными
    public:
        explicit ExceptionData(const char* arg) : Exception(arg){
            std::cerr << what()<< std::endl;
        }

    };
    class ExceptionFile: public Exception{//обработка исключений связанных с файлами (не открытия файла)
    public:
        explicit ExceptionFile(const char* arg) : Exception(arg){
            std::cerr << what()<< std::endl;
        }

    };
    class EStackEmpty: public Exception{//обработка исключений связанных с пустым стеком
    public:
        explicit EStackEmpty(const char* arg) : Exception(arg){
            std::cerr << what()<< std::endl;
        }

    };
}




#endif //LAB_1_EXCEPTION_H
