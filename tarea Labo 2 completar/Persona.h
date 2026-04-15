#pragma once
#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    int ci;
    string nombre;
    string email;
    float totalPagado;
    float salarioTotal;

    Persona(int ci, const string& nombre, const string& email)
        : ci(ci), nombre(nombre), email(email), totalPagado(0), salarioTotal(0) {
    }

    virtual float calcularPago() = 0;
    virtual void mostrarInformacion() = 0;
    virtual void agregarPago() = 0;
    virtual void agregarSalario() = 0;
    virtual bool esEstudiante() = 0;
    virtual bool esDocente() = 0;
    virtual ~Persona() {
    }
};