#ifndef CLION_PROGRAMMING_PATTERNS_EXCEPTIONS_H
#define CLION_PROGRAMMING_PATTERNS_EXCEPTIONS_H
#include <exception>
#include <iostream>
#include <utility>

class QueException {
private:
    std::string err;
public:
    QueException(std::string msg) : err(std::move(msg)){};

    ~QueException() = default;

    std::string get_error() const {return(err);};
};

#endif //CLION_PROGRAMMING_PATTERNS_EXCEPTIONS_H
