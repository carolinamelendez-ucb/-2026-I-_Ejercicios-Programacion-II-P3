#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Biblioteca.h"
class ErrorBiblioteca : public exception
{
private:
    string mensaje;

public:
    ErrorBiblioteca(string m)
    {
        mensaje = m;
    }

    const char* what() const noexcept override
    {
        return mensaje.c_str();
    }
};



