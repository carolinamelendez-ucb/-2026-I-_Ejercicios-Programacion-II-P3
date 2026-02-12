#include <iostream>
#include <string>
using namespace std;
class Cliente {
private:
    string nombre;
    string tipo;
    int antiguedad;
public:
    Cliente() {
        nombre = "";
        tipo = "";
        antiguedad = 0;
    }
    Cliente(string nombre, string tipo, int antiguedad) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
    }
};
class Factura {
private:
    int numero;
    int montoBase;
    Cliente cliente;
public:
    Factura(int numero, int montoBase, Cliente cliente) {
        this->numero = numero;
        this->montoBase = montoBase;
        this->cliente = cliente;
    }
    float calcularTotal() {

    }
    void ejercicio2() {
        Cliente cliente1 = Cliente("Mariana", "Normal", 3);
    }
};

int main()
{
  
}