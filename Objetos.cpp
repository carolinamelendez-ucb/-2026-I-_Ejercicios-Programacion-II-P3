#include <iostream>
#include <string>
using namespace std;

class Auto {
private:
    string marca;
    string modelo;
    string color;
    int anio;
    string combustible;

public: 
    Auto(string marcaA, string modeloA, string colorA, int anioA, string combustibleA){ 
        marca=marcaA;
        modelo=modeloA;
        color=colorA;
        anio=anioA;
        combustible=combustibleA;
    }
    void mostrar() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Color: " << color << endl;
        cout << "Anio: " << anio << endl;
        cout << "Combustible: " << combustible << endl;
    }
    void setAnio(int nuevoAnio) {
        this->anio = nuevoAnio;
    }
    void encender(){
        cout << "El auto se esta encendiendo" << endl;
    }
    void acelerar(){
        cout << "El auto esta acelerando" << endl;
    }
    void frenar(){
        cout << "El auto esta frenando" << endl;
    }
    void girar(){
        cout << "El auto esta girando" << endl;
    }
    void apagar(){
        cout << "El auto se esta apagando" << endl;
    }
};

int main()
{
    cout << "== Auto1 ==" << endl;
    Auto auto1("Ford", "Mustang", "Negro", 1960, "Gasolina");
    auto1.encender();
    auto1.encender();
    auto1.encender();
    auto1.encender();
    auto1.apagar();
    auto1.mostrar();
    cout << endl;
    cout << "== Auto2 ==" << endl;
    Auto auto2("Toyota", "Corolla", "Blanco", 2020, "Hibrido");
    auto2.acelerar();
    auto2.frenar();
    auto2.apagar();
    auto2.mostrar();
    auto2.setAnio(2010);
    cout << "-------------" << endl;
    auto2.mostrar();
}
