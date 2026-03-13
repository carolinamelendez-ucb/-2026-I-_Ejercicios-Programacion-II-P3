#include <iostream>
#include "Organizador.h"
#include "Evento.h"
#include "VectorOrganizadores.h"
#include "VectorEventos.h"

using namespace std;

int main() {

    OrganizadoresVector organizadores(5);

    organizadores.agregar(new Organizador("Carlos", 1));
    organizadores.agregar(new Organizador("Ana", 2));
    organizadores.agregar(new Organizador("Luis", 3));

    cout << "ORGANIZADORES REGISTRADOS" << endl;
    cout << endl;
    organizadores.mostrar();

    EventosVector eventos(5);

    eventos.crearEvento("Conferencia", 101, 3, &organizadores);
    eventos.crearEvento("Feria", 102, 2, &organizadores);

    eventos.getEvento(0)->registrarInvitado("Pedro", 777111);
    eventos.getEvento(0)->registrarInvitado("Maria", 777222);

    eventos.getEvento(1)->registrarInvitado("Jose", 777333);

    cout << endl;
    cout << "EVENTOS" << endl;
    cout << endl;
    eventos.mostrar();

    cout << endl;
    cout << "FINALIZANDO EVENTO" << endl;
    eventos.getEvento(0)->finalizar();

    cout << endl;
    cout << "ORGANIZADORES ACTUALIZADOS" << endl;
    cout << endl;
    organizadores.mostrar();

}