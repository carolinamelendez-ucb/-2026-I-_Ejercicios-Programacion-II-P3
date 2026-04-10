// PracticaHerencia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "Sistema.h"
#include "VehiculoEconomico.h"
#include "VehiculoLujo.h"
#include "ClienteBasico.h"
#include "ClienteCorporativo.h"


int main()
{
    Sistema sistema(50, 50, 50);

    Cliente* cliente1 = new ClienteBasico(1, "JUAN", 20);
    Cliente* cliente2 = new ClienteCorporativo(2, "MARIA", 20);
    Cliente* cliente3 = new ClienteBasico(3, "Pedro",20);

    sistema.agregarCliente(cliente1);
    sistema.agregarCliente(cliente2);
    sistema.agregarCliente(cliente3);

    Vehiculo* vehiculo1 = new VehiculoEconomico("ABC-123");
    Vehiculo* vehiculo2 = new VehiculoEconomico("XYZ-999");
    Vehiculo* vehiculo3 = new VehiculoEconomico("LMN-456");

    sistema.agregarVehiculo(vehiculo1);
    sistema.agregarVehiculo(vehiculo2);
    sistema.agregarVehiculo(vehiculo3);


    sistema.asignar(1, "ABC-123", 3);
    sistema.asignar(2, "XYZ-999", 2);
    sistema.asignar(3, "LMN-456", 5);

    //error de asignacion duplicado
    sistema.asignar(1, "XYZ-999", 1);

    sistema.mostrar();

    //desasignado
    cout << "Despues de cambios************************" << endl;
    cout << endl;
    sistema.desasignar(1, "ABC-123");

    sistema.mostrar();


   







    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
