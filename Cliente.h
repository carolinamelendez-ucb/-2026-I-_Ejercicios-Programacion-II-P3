#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string nombre;
    string cedula;
    string telefono;

public:
    Cliente() : nombre(""), cedula(""), telefono("") {}

    Cliente(string nom, string ced, string tel)
        : nombre(nom), cedula(ced), telefono(tel) {
    }

    void registrar() {
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Cedula: ";
        getline(cin, cedula);
        cout << "Telefono: ";
        getline(cin, telefono);
    }

    void mostrar() const {
        cout << "Cliente: " << nombre << " | Cedula: " << cedula
            << " | Telefono: " << telefono;
    }

    string getNombre() const { return nombre; }
    string getCedula() const { return cedula; }
    string getTelefono() const { return telefono; }
};