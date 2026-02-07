// ConsoleApplication7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>  
using namespace std;
class Auto {
public:
    //atributos
    int velocidad;
    string color;
    string tipo;
    string marca;

    //constructor
    Auto(int vel,string col,string tip,string marc) {
        velocidad = vel;
        color = col;
        tipo = tip;
        marca = marc;
    }
    void mostrar() {
        cout << "la velocidad es: " << velocidad<<endl;
        cout << "el color es: " << color << endl;
        cout << "es de tipo: " << tipo << endl;
        cout << "su marca es: " << marca << endl;
    }
    void setAnio(int nuevoAnio) {
        velocidad = nuevoAnio;
    }

    //metodos
    void avanzar() {
        cout << "la bicicleta avanza..." << endl;
    }
    void detener() {
        cout << "la bicicleta se detiene..." << endl;
    }
    void desmantelar() {
        cout << "la bicicleta se esta desmantelando..." << endl;
    }
    void cambiarCaja() {
        cout << "realizaste un cambio de caja..." << endl;
    }
    void ejercitar() {
        cout << "Utilizaste la bicicleta para ejercitar" << endl;
    }

};
int main()
{
    Auto bicicleta1 = Auto(2020,"azul", "montania","trek");
    bicicleta1.mostrar();
    bicicleta1.setAnio(2025);
    bicicleta1.mostrar();
}
