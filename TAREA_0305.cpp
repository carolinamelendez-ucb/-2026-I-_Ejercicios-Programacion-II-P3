// TAREA_0305.cpp 

#include "SistemaAutomovilistico.h"

int main()
{
    SistemaAutomovilistico sistema(10, 10, 10);

    sistema.registrarSocio(1, "Sara", "123");
    sistema.registrarSocio(2, "Ana", "456");
    sistema.registrarSocio(3, "Carlos", "789");

    sistema.registrarEquipo("Invencibles", "Toyota", 1, 2);
    sistema.registrarEquipo("Aferrados", "Nissan", 2, 3);

    sistema.crearCompetencia("Rally 2026", 5);

    cout << "---- SOCIOS ORDENADOS ALFAVETICAMENTE ----" << endl;
    sistema.mostrarSocios();
    cout << "--------- EQUIPOS --------" << endl;
    sistema.mostrarEquipos();
    cout << "--------- EQUIPOS DEL SOCIO 2 --------" << endl;
    sistema.buscarEquiposDeSocio(2);
}

