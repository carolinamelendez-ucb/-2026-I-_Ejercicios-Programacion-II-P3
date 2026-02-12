// practica 3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

class cliente {
private:
    string nombre;
    int saldodisponible;
    bool habilitado;
public:
    cliente(string nombre, int saldodisponible, bool habilitado) {
        this->nombre = nombre;
        this->saldodisponible = saldodisponible;
        this->habilitado = habilitado;
    }
    bool getHabilitado() {
        return habilitado;
    }
    int getSalario() {
        return saldodisponible;
    }
};

class perdido {
private:
    int codigo;
    string ObjetoCliente;
    int importe;
    cliente clienteAsociado;

public:
    perdido(int codigo, string Objetocliente, int importe, cliente clienteAsociado)
        : clienteAsociado(clienteAsociado) {

        this->codigo = codigo;
        this->ObjetoCliente = Objetocliente;
        this->importe = importe;
    }

    void saldodisponible() {
        if (clienteAsociado.getSalario() > 100) {
            cout << "El cliente esta habilitado para pagar" << endl;
        }
        else {
            cout << "El cliente no esta habilitado para pagar" << endl;
        }
    }

    void mostrarQuepuedeConfirmarse() {
        if (clienteAsociado.getHabilitado()) {
            cout << "El cliente si esta habilitado" << endl;
        }
        else {
            cout << "El cliente no esta habilitado" << endl;
        }
    }
};
void ejercicio3() {
    cliente cliente1("Berna B.", 200, true);
    perdido perdido1(23456, "botas", 12, cliente1);
    perdido1.mostrarQuepuedeConfirmarse();
    perdido1.saldodisponible();
}
int main() {
    ejercicio3();
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
