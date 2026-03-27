#include <iostream>
#include <string>
#include "OrganizadorVector.h"
#include "EventoVector.h"
using namespace std;

int main()
{
    OrganizadorVector orgs(5);
    orgs.agregarOrganizador(new Organizador("Ana"));
    orgs.agregarOrganizador(new Organizador("Luis"));
    orgs.agregarOrganizador(new Organizador("Pedro"));
    EventoVector eventos(5);
    Organizador* org = orgs.mejorDisponible();
    if (org != 0) {
        Evento* nuevo = new Evento("Conferencia", 3, org);
        nuevo->registrarInvitado("Maria", 777111);
        nuevo->registrarInvitado("Carlos", 444222);
        eventos.agregarEvento(nuevo);
        nuevo->finalizar();
    }
    else {
        cout << "No hay organizadores disponibles" << endl;
    }
    cout << "== EVENTOS ==" << endl;
    eventos.mostrarEventos();
    cout << "== ORGANIZADORES ==" << endl;
    orgs.mostrar();
}
