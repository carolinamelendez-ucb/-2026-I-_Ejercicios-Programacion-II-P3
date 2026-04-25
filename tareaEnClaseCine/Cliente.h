#pragma once
#include <iostream>
#include <string>

using namespace std;

// registro cliente
template <typename t>
class Cliente {
public:
    t id;
    string nombre;
    string email;

    Cliente(t id = t(), string nombre = "", string email = "") {
        this->id = id;
        this->nombre = nombre;
        this->email = email;
    }

    void mostrar() {
        cout << "id: " << id << " nombre: " << nombre << " email: " << email << endl;
    }
};
