#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class PlacaDuplicadaException : public exception {
private:
    string mensaje;
public:
    PlacaDuplicadaException() {
        mensaje = "La placa del vehiculo ya esta registrada.";
    }
    char const* what() const {
        return mensaje.c_str();
    }
};