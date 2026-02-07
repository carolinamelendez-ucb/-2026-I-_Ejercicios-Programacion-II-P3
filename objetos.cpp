#include <iostream>
#include <string>
using namespace std;

// Notacion -> Pascal CASE -> MiPrimeraPalabra
// Notacion -> Camel CASE -> miPrimeraPalabra
// Notacion -> snake CASE -> mi_primera_palabra


class Mochila {
private:
    // Atributos
    string modelo;
    string color;
    string marca;
    string tamano;
public:
    Mochila(string modeloMochila, string colorA, string marcaB, string tamanoC) {
        this->modelo = modeloMochila;
        this->color = colorA;
        this->marca = marcaB;
        this->tamano = tamanoC;
    }
    void mostrar() {
        cout << "Modelo" << modelo << endl;
        cout << "Color" << color << endl;
        cout << "Marca" << marca << endl;
        cout << "Tamano" << tamano << endl;
    }
    // Metodos
    void abrir() {
         cout << "Mochila se abre..." << endl;
    }
    void cerrar() {
        cout << "Mochila se cierra..." << endl;
    }
    void guardar() {}
    void colgar() {}
    void transportar() {}

    // Set
    void setModelo(string nuevoModelo) {
        this->modelo = nuevoModelo;
    }
};

int main()
{
    cout << "-- Mochila 1" << endl;
    Mochila mochila1 = Mochila("Escolar", "Verde", "Totto", "Grande");
    cout << "-- Mochila 2" << endl;
    Mochila mochila2 = Mochila("Montañera", "Cafe", "JanSport", "Mediano");
    cout << "-- Mochila 3" << endl;
    Mochila mochila3 = Mochila("Fitness", "Amarillo", "Osprey", "Pequeño");
    cout << "-- Mochila 4" << endl;
    Mochila mochila4 = Mochila("Urbana", "Verde", "Delsey", "Grande");
    mochila4.mostrar();
    mochila4.setModelo("Totto");
    cout << "------------" << endl;
    mochila4.mostrar();
}
