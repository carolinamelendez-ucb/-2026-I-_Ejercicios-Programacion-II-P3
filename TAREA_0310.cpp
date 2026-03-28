// TAREA_0310.cpp
/*  */

#include "SistemaOrganizadorEventos.h"

int main()
{
    SistemaOrganizadorEventos sistema(10, 10);

    sistema.registrarOrganizador(1, "Ana");
    sistema.registrarOrganizador(2, "Sara");

    sistema.registrarEvento(103, "Bautizo", 3);
    sistema.registrarEvento(101, "Cumpleanios", 5);
    sistema.registrarEvento(102, "Boda", 10);
    

    sistema.mostrarEventos();
    
}

