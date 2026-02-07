

#include <iostream>
#include <string>
using namespace std;

class Auto
{
private:
    //Atrributos
    int velocidad;
    string color;
    string tipo;
    string marca;

public:
    //Metodos
    /*void avanzar() { cout << "Bicicleta avanza..." << endl; }
    void detener() { cout << "Bicicleta se detiene..." << endl; }
    void desmantelar() { cout << " Bicicleta se desmantela..." << endl; }
    void cambiarCaja() { cout << " Bicicleta cambia caja..." << endl; }
    void ejercitar() { cout << "Bicicleta ejercita..." << endl; }*/

    //Constructor
    Auto(int velocidadB,string colorBicicleta,string tipoB,string marcaB)
    {
        velocidad = velocidadB;
        color = colorBicicleta;
        tipo = tipoB;
        marca = marcaB;
    }

    void mostrar()
    {
        cout << "Velocidad: " << velocidad << endl;
        cout << "color: " << color << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Marca: " << marca << endl;
    }

    void setVelocidad(int nuevaVelocidad)
    {
        this->velocidad = nuevaVelocidad;
    }
};



int main()
{
    cout << "-- AUTO 1 --" << endl;
    Auto auto1 = Auto(10,"rojo","familiar","toyota");
    auto1.mostrar();

    Auto auto2 = Auto(20, "azul", "individual", "toyota");
    Auto auto3 = Auto(30, "rosa", "familiar", "toyota");
    cout << " -- AUTO 4 -- " << endl;
    Auto auto4 = Auto(40, "negro", "familiar", "toyota");
    auto4.mostrar();

    auto4.setVelocidad(456);
    cout << "-----------" << endl;
    auto4.mostrar();

}

