// clases.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
#include   <string>
class Cliente {
private:
    string nombre;
    string tipo;
    int antiguedad;
public: 
    Cliente() {

    }
    Cliente(string nombre, string tipo, int antiguedad) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
    }
    int getantiguedad() {
        return antiguedad;
    }
    string gettipo() {
        return tipo;
    }
    void mostrar()
    {

    }
};
class Factura {
private:
    int numero;
    int monto_base;
    Cliente cliente;
public:
    Factura(int numero, int monto_base, Cliente cliente) {
        this->numero = numero;
        this->monto_base = monto_base;
        this->cliente = cliente;
    }
    void calcularTotal()
    {
        if (cliente.getantiguedad() > 2 && cliente.gettipo() == "frecuente") {
            monto_base = monto_base * 0.9;
        }
        cout << monto_base<<endl;
    }
};
void ejercicio2()
int main()
{
    //ejercicio2


}
