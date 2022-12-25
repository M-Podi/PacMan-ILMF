#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class DefaultError : public std::runtime_error{
    using std::runtime_error::runtime_error;
};
class InvalidNameError : public DefaultError {
public:
    explicit InvalidNameError(const std::string &error) : DefaultError("Error - Invalid Name: " + error) {}
};
class ResolutionUnsupported : public DefaultError{
public:
    explicit ResolutionUnsupported(const std::string &error) : DefaultError("Error - Your current Screen Resolution is no Supported" + error) {}
};


#endif //OOP_EXCEPTIONS_H
