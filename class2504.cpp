// class2504.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "SsitemaCine.h"

int main()
{
    SistemaCine miCine = SistemaCine(5, 5, 5, 5);

    //1

    miCine.registrarClientes(new Cliente("1", "Dania"));
    miCine.registrarClientes(new Cliente("2", "Carla"));
    miCine.registrarClientes(new Cliente("3", "Sofia"));
    cout << "Se regitro...." << endl;
     //2

    miCine.registrarSalas(new Sala("A1", "Nombre", 5, 5));



}
