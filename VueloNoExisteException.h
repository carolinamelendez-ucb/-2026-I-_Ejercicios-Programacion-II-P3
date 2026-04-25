#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class VueloNoExisteException : public exception {
private:
    string mensaje;
public:
    VueloNoExisteException() {
        mensaje = "El vuelo no existe";
    }

    char const* what() const {
        return mensaje.c_str();
    }
};