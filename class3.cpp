// class3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

class celular {
private:
    int Bateria;
    int anio;
    string modelo;
    string color;
    string marca;
public:

    celular(int bateria1, int anio1, string modelo1, string color1, string marca1) {

            Bateria = bateria1;
            anio = anio1;
            modelo = modelo1;
            color = color1;
            marca = marca1;
    }
    void mostrar() {
        cout << "Bateria: " << Bateria<<endl;
        cout << "Anio: " << anio << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Color: " << color << endl;
        cout << "Marca: " << marca << endl;
   }
    void llamar() {
        cout << "LLamando..."<<endl;
    }
    void textear() {
        cout << "Enviando texto..."<<endl;
    }
    void pagar() {
        cout << "Pagando..."<<endl;
    }
    void grabar() {
        cout << "Empezaste a grabar" << endl;
    }
    void jugar() {
        cout << "Entrando al juego..." << endl;
    }
    void setBateria(int nuevaBateria) {
        Bateria = nuevaBateria;

    }
};


int main()
{

    celular celular1 = celular(100, 2026, "PRO MAX", "NEGRO", "IPHONE");
    celular1.mostrar();
    celular1.setBateria(75);
    celular1.mostrar();
}

