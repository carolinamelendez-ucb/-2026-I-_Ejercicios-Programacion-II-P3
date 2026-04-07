#pragma once
#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    string email;

public:
    Estudiante(string nombre = "", string email = "")
        : nombre(nombre), email(email) {
    }

    string getNombre() { return nombre; }
    string getEmail() { return email; }

    void mostrar() {
        cout << "  Estudiante: " << nombre << " | Email: " << email << endl;
    }
};
