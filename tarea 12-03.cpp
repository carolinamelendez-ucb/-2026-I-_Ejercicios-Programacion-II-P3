#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Empresa.h"
#include "Organizador.h"
using namespace std;

int main()
{
    srand(time(0));
    Empresa PIl(5,5);
    PIl.registrarOrganizador(new Organizador("joel",7));
    PIl.registrarOrganizador(new Organizador("pedro",8));
    PIl.registrarOrganizador(new Organizador("Juan",20));
    PIl.registrarOrganizador(new Organizador("Dilan"));
    PIl.RegistrarEventoConMayorRank(new Evento("Boda", 20,34));
    PIl.finalizar(34);
    //PIl.RegistrarEvento(new Evento("Boda", 30,34));
    //PIl.agregarInvitado(34,new Invitado("joel",74548723));
   // PIl.mostrarEventos();
    //PIl.mostrarEventos();
    PIl.mostrarOrganizadores();
}

