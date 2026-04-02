#pragma once
#include <iostream>
#include <string>
using namespace std;
class Figura {
 
public:
    virtual float calcularArea() = 0;

    void mostrar() {
        cout << "Area: " << calcularArea() << " [m^2] " << endl;
    }

};