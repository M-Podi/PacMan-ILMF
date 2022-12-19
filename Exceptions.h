#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <stdexcept>
#include <string>


class InvalidNameError : public std::runtime_error {
public:
    explicit InvalidNameError(const std::string &error) : runtime_error("Error - Invalid Name: " + error) {}
};


#endif //OOP_EXCEPTIONS_H
