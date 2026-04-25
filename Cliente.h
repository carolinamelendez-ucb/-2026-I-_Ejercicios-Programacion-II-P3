#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente {
    private:
    string nombre;
    int ci;
    public:

    Cliente () : nombre (""), ci (0) {}

    Cliente (const string& nombre, int ci)
        : nombre (nombre), ci (ci) {
    }

    string getNombre () 
    { 
        return nombre; 
    }
    int getCi (){   
        return ci; 
       }

    void mostrar () const {
        cout << "  Cliente: " << nombre << " | CI: " << ci << endl;
    }
};