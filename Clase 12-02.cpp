#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string nombre;
    string tipo;
    int antiguedad;

public:
    Cliente (){}
    Cliente(string nombre, string tipo, int antiguedad) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
    }

    string getTipo() {
        return tipo;
    }

    int getAntiguedad() {
        return antiguedad;
    }

};

class Factura {
private:
    int num;
    double montoBase;
    Cliente cliente;

public:
    Factura(int num, int montoBase, Cliente cliente){
        this->num = num;
        this->montoBase = montoBase;
        this->cliente = cliente; 
    }

    void calcularTotal() {
        double descuento = 0;
        double total = 0;
        string Tipo = cliente.getTipo();
        int Anios = cliente.getAntiguedad();

        if (Tipo == "frecuente" && Anios > 2) {
            descuento = montoBase * 0.10;
            total = montoBase - descuento;
            cout << "Cliente frecuente con mas de 2 anios " << endl;
            cout << "Descuento aplicado: 10% " << endl;
        }

        cout << "Total a pagar: Bs. " << total << endl;
    }
};

int main() {
    Cliente cliente1("Juan Perez", "frecuente", 3);
    Factura factura1(1001, 500, cliente1);
    factura1.calcularTotal();
}

