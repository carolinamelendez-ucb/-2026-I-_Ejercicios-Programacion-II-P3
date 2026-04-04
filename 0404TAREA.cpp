#include <iostream>
#include "SistemaTransporte.h"
#include "Terrestre.h"
#include "Aereo.h"
#include "Maritimo.h"

using namespace std;

int main() {

    SistemaTransporte sistema(5, 5);

    cout << "Registrando transportes" << endl << endl;

    sistema.registrarTransporte(new Terrestre("T1"));
    sistema.registrarTransporte(new Aereo("A1"));
    sistema.registrarTransporte(new Maritimo("M1"));
    sistema.registrarTransporte(new Terrestre("T1")); // duplicado

    cout << endl << "Registrando operadores" << endl << endl;

    sistema.registrarOperador("Carlos", "111");
    sistema.registrarOperador("Ana", "222");
    sistema.registrarOperador("Luis", "111"); // duplicado

    cout << endl << "Asignando transportes" << endl << endl;

    sistema.asignar("111", "T1", 150);
    sistema.asignar("222", "A1", 1200);

    cout << endl << "Costo total del sistema" << endl;
    cout << sistema.costoTotal() << endl;

    cout << endl << "Menor costo generado" << endl;
    sistema.menorCosto();
}