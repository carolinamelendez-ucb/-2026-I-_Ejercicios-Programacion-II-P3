// Clase 10-02.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

class Cuenta {
private:
    string titular;
    int cantidad;
public:
    Cuenta(string titular, int cantidad) {
        this->titular = titular;
        this->cantidad = cantidad;
    }
    Cuenta(string titular) {
        this->titular = titular;
        this->cantidad = 0;
    }
    void setCantidad(int nuevaC) {
        this->cantidad = nuevaC;
    }
    int getCantidad() {
        return cantidad;
    }
    void setTitular(string nuevoT) {
        this->titular = nuevoT;
    }
    string getTitular() {
        return titular;
    }
    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
    void ingresar(int cantidadIngresada) {
        if (cantidadIngresada >= 0) {
            cantidad = cantidad + cantidadIngresada;
        }

    }
    void retirar(int cantidadRetirada) {
        int restante = cantidad - cantidadRetirada;
        if (restante < 0) {
            this->cantidad = 0;
        }
     
    }
};

int main()
{
    Cuenta cuenta1 = Cuenta("Juan", 200);
    Cuenta cuenta2 = Cuenta("Pedro");
    cuenta1.mostrar();
    cuenta2.mostrar();
    cuenta2.setCantidad(150);
    cuenta2.mostrar();
    cuenta1.ingresar(45);
    cuenta2.retirar(225);
    cuenta1.mostrar();
    cuenta2.mostrar();
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
