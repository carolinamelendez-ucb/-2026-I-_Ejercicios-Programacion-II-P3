#include <iostream>
#include "VectorOrganizadores.h";
#include "Evento.h"
using namespace std;

int main()
{
    Organizador* o1 = new Organizador("Omar", 1);
    Organizador* o2 = new Organizador("Mauricio", 2);
    Organizador* o3 = new Organizador("Alisa", 3);

    VectorOrganizadores misOrganizadores(10);
    misOrganizadores.agregar(o1);
    misOrganizadores.agregar(o2);
    misOrganizadores.agregar(o3);

    Invitado i1 = Invitado("Raquel", 11);
    Invitado i2 = Invitado("Benjamin", 12);
    Invitado i3 = Invitado("Mariana", 13);
    Invitado i4 = Invitado("Gabriel", 14);
    Invitado i5 = Invitado("Leonardo", 15);
    Invitado i6 = Invitado("Jon", 16);
    
    Evento ev1("Evento 1", 1, 10, misOrganizadores.getOrganizador(0));
    ev1.agregarInvitados(i1);
    ev1.agregarInvitados(i2);

    Evento ev2("Evento 2", 2, 10, misOrganizadores.getOrganizador(1));
    ev1.agregarInvitados(i3);
    ev1.agregarInvitados(i4);

    Evento ev3("Evento 3", 3, 10, misOrganizadores.getOrganizador(2));
    ev1.agregarInvitados(i5);
    ev1.agregarInvitados(i6);

    
    cout << "Antes de los eventos" << endl;
    misOrganizadores.mostrar();
    ev1.mostrar();
    ev2.mostrar();
    ev3.mostrar();


    ev1.finalizarEvento();
    ev1.finalizarEvento();
    ev2.finalizarEvento();

    cout << "Después de los eventos" << endl;
    misOrganizadores.mostrar();
}

