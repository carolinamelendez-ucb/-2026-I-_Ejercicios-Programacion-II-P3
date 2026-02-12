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
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Antiguedad: " << antiguedad << endl;
    }
    string getNombre() {return nombre; }
    string getTipo() { return tipo; }
    int getAntiguedad() { return antiguedad; }

};
class Factura {
private:
    int numero;
    int montoBase;
    Cliente cliente;
public:
    Factura(int numero, int montoBase, Cliente cliente)
    {
        this->numero = numero;
        this->montoBase = montoBase;
        this->cliente = cliente;
    }
    void mostrar() {
        cout << "Numero: " << numero << endl;
        cout << "montoBase: " << montoBase << endl;
        cout << "Cliente: " << endl;
        cliente.mostrar();
    }
    float calcularTotal() {
        float tot = numero * montoBase;
        if (cliente.getTipo() == "frecuente" && cliente.getAntiguedad() > 2) {
            return tot * 0.9;
        }
        else {
            return tot;
        }
    }

};

void ejercicio2() {
    Cliente miCliente1 = Cliente("Omar", "frecuente", 5);
    miCliente1.mostrar();
    cout << endl;
    Factura miFactura1 = Factura(5, 21, miCliente1);
    miFactura1.mostrar();
    cout << "El monto a pagar para el primer cliente es: " << miFactura1.calcularTotal() << endl << endl;
    Cliente miCliente2 = Cliente("Nestor", "normal", 5);
    miCliente2.mostrar();
    cout << endl;
    Factura miFactura2 = Factura(5, 21, miCliente2);
    miFactura2.mostrar();
    cout << "El monto a pagar para el segundo cliente es: " << miFactura2.calcularTotal() << endl << endl;
}

int main()
{
    ejercicio2();
}

