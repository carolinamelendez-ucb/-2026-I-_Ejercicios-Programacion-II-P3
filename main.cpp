#include <iostream>
#include <string>

#include "vectorOrganizador.h"
#include "InvitadoVector.h"
#include "eventoVector.h"
#include "Organizador.h"
#include "Invitado.h"
#include "evento.h"

using namespace std;

int main()
{
    //Vectores del sistema
    VectorOrganizador misOrganizadores(50);
    EventoVector misEventos(50);

    //Crear organizadores
    Organizador* o1 = new Organizador("pepito");
    Organizador* o2 = new Organizador("pedro");

    //Registrar organizadores
    misOrganizadores.agregar(o1);
    misOrganizadores.agregar(o2);

    cout << "=== ORGANIZADORES ===" << endl;
    misOrganizadores.mostrarListaOrganizador();

    //Crear evento
    Evento* e1 = new Evento("Blah",123,10);

    //Buscar organizador disponible
    Organizador* orgDisponible = misOrganizadores.buscarOrganizadorDisponible();

    if(orgDisponible != nullptr)
    {
       
        misEventos.agregarEvento(e1);
    }

    cout << endl;
    cout << "=== EVENTOS ===" << endl;
    misEventos.mostrarListaEventos();

    //Crear invitados
    Invitado* i1 = new Invitado("ariana","60732937");
    Invitado* i2 = new Invitado("adriana","70743654");

    //Registrar invitados en evento
    e1->asignarOrganizador(i1);
    e1->asignarOrganizador(i2);

    cout << endl;
    cout << "=== EVENTO CON INVITADOS ===" << endl;
    e1->mostrar();

    //Finalizar evento (incrementa rank del organizador)
    e1->finalizar();

    cout << endl;
    cout << "=== ORGANIZADORES DESPUES DEL EVENTO ===" << endl;
    misOrganizadores.mostrarListaOrganizador();

    return 0;
}