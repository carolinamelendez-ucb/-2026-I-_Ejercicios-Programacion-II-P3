#include <iostream>
#include "SistemaCine.h"

using namespace std;

int main() {

    SistemaCine cine;

    cine.registrarCliente("Carlos", 111);
    cine.registrarCliente("Ana", 222);

    cine.registrarSala(1, 5, 10);
    cine.registrarSala(2, 4, 8);

    cine.registrarPelicula("Batman", 1);
    cine.registrarPelicula("Avatar", 2);

    cine.registrarFuncion(101, 0, 0, 30);
    cine.registrarFuncion(102, 1, 1, 35);

    cine.venderBoleto(0);
    cine.venderBoleto(0);
    cine.venderBoleto(1);

    cout << "FUNCIONES" << endl;
    cine.mostrarFunciones();

    cout << "GANANCIA FUNCION 0" << endl;
    cine.reporteFuncion(0);

}