#include <iostream>
#include <string>
using namespace std;
class bisicleta {
private:
    //atributos
    string marca;
    string color;
    int  velocidad;
    string tipo;

public:
    bisicleta(int velocidadA ,string colorA, string tipoA, string marcaA) {
       this-> velocidad = velocidadA;
       this-> color = colorA;
       this-> tipo = tipoA;
       this-> marca= marcaA;
    }
    //metodos
    void mostrar() {
        cout << "velocidad es : " << velocidad << endl;
        cout << "color es : " << color << endl;
        cout << "modelo es : " << tipo << endl;
        cout << "marca es : " << marca << endl;
    };

    //void manejar() { cout << "Bicicleta avanza ..." << endl; }
   // void detener() { cout << "Bicicleta se detiene ..." << endl; }
   // void modificar() { cout << "Bicicleta se modifica ..." << endl; }

};
int main()
{
    cout << "-- Bicicleta 1" << endl;
    bisicleta bisicleta1 = bisicleta(10, "rojo","dead","montañosa");
    bisicleta1.mostrar();
    cout << "--------------------------" << endl;
    cout << "-- Bicicleta 2" << endl;
    bisicleta bisicleta2 = bisicleta(20, "amarrillo", "dead", "montañosa");
    bisicleta2.mostrar();
    cout << "--------------------------" << endl;
    cout << "-- Bicicleta 3" << endl;
    bisicleta bisicleta3 = bisicleta(15, "azul", "dead", "montañosa");
    bisicleta3.mostrar();
    cout << "--------------------------" << endl;
    cout << "-- Bicicleta 4" << endl;
    bisicleta bisicleta4 = bisicleta(16, "morado", "dead", "montañosa");
    bisicleta4.mostrar();
     cout << "--------------------------" << endl;
}
