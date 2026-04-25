#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <exception>

class MiExcepcion : public exception {
private:
    string mensaje;

public:
    MiExcepcion(string msg) {
        mensaje = msg;
    }

    const char* what() const override {
        return mensaje.c_str();
    }
};