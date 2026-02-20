#include <iostream>
#include <string>
using namespace std;
class Auto {
private:
    //Atributos
    string marca;
    string modelo;
    string tipo;
    string color;
    int velocidad;
public:
    Auto(string marca, string modelo, string tipo, string color, int velocidad) {
        marca = "Isuzu";
        modelo = "D-MAX";
        tipo = "montaniera";
        color = "rojo";
        velocidad = 180;
    }
};
//Métodos


    void mostrar() {
        cout << "Velocidad: " << velocidad << endl;
    }
void avanzar() {
    cout << "Bicicleta... Avanza..." << endl;
}
void detener() {
    cout << "Bicicleta... Detente..." << endl;
}

void transportar() {

}

void cambiarCaja() {

}

void encender() {

}

int main()
{
    Auto auto1;
    auto1.avanzar();
    auto1.avanzar();
    auto1.avanzar();
    auto1.avanzar();
    auto1.detener();
}

///POO Paradigma de Programación orientada a Objetos
///Características de un objeto (Bicicleta1): Velocidad=10Km/h, color=celeste, tipo=montañera, marca=trek. ESTADO DEL OBJETO
///Características de un objeto (Bicicleta2): Velocidad=20Km/h, color=rojo, tipo=urbana, marca=canyon. ESTADO DEL OBJETO
///Acciones (Verbos): Manejar, avanzar, detener, desmantelar, cambiar caja, ejercitar.
/// Características -> Atributos
/// Acciones -> Métodos
/// Notación -> Pascal CASE -> MiPrimeraPalabra
/// Notación -> Camel CASE -> miPrimeraPalabra
/// Notación -> Snake CASE -> mi_primera_palabra