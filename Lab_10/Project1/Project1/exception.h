#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class invalidIndex : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid index";
    }
};

#endif