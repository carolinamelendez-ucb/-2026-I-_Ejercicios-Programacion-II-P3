#include <iostream>
#include <string>
using namespace std;

class Auto {
public:
    // atributos
    int velocidad;
    string modelo;
    string color;
    string marca;
    string combustible;

    // constructor
    Auto(int vel, string col, string mod, string marc, string com) {
        velocidad = vel;
        color = col;
        modelo = mod;
        marca = marc;
        combustible = com;
    }

    void mostrar() {
        cout << "La velocidad es: " << velocidad << endl;
        cout << "El color es: " << color << endl;
        cout << "El modelo es: " << modelo << endl;
        cout << "Es de marca: " << marca << endl;
        cout << "Su combustible es: " << combustible << endl;
    }

    // métodos
    void encender() {
        cout << "El auto enciende..." << endl;
    }
    void apagar() {
        cout << "El auto se apaga..." << endl;
    }
    void acelerar() {
        cout << "El auto esta acelerando..." << endl;
    }
    void frenar() {
        cout << "El auto esta frenando..." << endl;
    }
    void girar() {
        cout << "El auto esta girando..." << endl;
    }
};

int main() {
    Auto Auto1(3, "rojo", "Bagoneta", "Ferrari", "Gasolina");
    Auto1.encender();
    Auto1.apagar();
    Auto1.acelerar();
    Auto1.frenar();
    Auto1.girar();
    Auto1.mostrar();

    Auto Auto2(3, "celeste", "Bagometa", "Ferrari", "Gasolina");
    Auto Auto3(3, "amarillo", "Bagoneta", "Ferrari", "Gasolina");
    Auto Auto4(3, "negro", "Bagoneta", "Ferrari", "Gasolina");

    return 0;
}
