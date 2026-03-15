// Ejer2Dania.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "GestionEventosOraganizadores.h"
int main()
{
    srand((unsigned)time(NULL));//cda vez me aparezacan numero 

    GestorEmpresa empresa("Dolphin", 10, 10);

    empresa.registrarOrganizador("Esteban", true, 5);
    empresa.registrarOrganizador("Luis", false, 8);
    empresa.registrarOrganizador("Ester", true, 3);

    empresa.mostrarOrganizadores();

    empresa.registrarEvento("Boda", 50);
    empresa.registrarEvento("Cumpleaños", 80);

    empresa.mostrarEventos();
    cout << endl;
    
    empresa.registrarInvitadoEvento(0, "Carlos", "71234567");
    empresa.registrarInvitadoEvento(0, "Maria", "72345678");

    empresa.registrarInvitadoEvento(1, "Lucas", "71534567");
    empresa.registrarInvitadoEvento(1, "Charo", "72346009");

    empresa.mostrarEventos();


    empresa.finalizarEvento(0);
    cout << "Estado de Organizadores despues de finalizacion de Evento 0 (Esteban)" << endl;
    empresa.mostrarOrganizadores();
}

 