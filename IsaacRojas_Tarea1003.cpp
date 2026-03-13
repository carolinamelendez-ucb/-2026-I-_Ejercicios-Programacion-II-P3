#include <iostream>
#include <string>
#include "organizadorVector.h"
#include "eventoVector.h"
using namespace std;
int main()
{
	OrganizadorVector misOrganizadores(20);
	EventoVector misEventos(30);
	cout << "REGISTRAR A LOS ORGANIZADORES" << endl;
	cout << endl;
	Organizador* organizador1 = new Organizador("Garlot", 101);
	Organizador* organizador2 = new Organizador("Karlos", 102);
	Organizador* organizador3 = new Organizador("Mariano", 103);
	Organizador* organizador4 = new Organizador("Ruth", 104);
	for (int i = 0; i < 3; i++) {
		organizador1->incrementarRank();
	}
	for (int i = 0; i < 5; i++) {
		organizador2->incrementarRank();
	}
	for (int i = 0; i < 1; i++) {
		organizador3->incrementarRank();
	}
	misOrganizadores.agregar(organizador1);
	misOrganizadores.agregar(organizador2);
	misOrganizadores.agregar(organizador3);
	misOrganizadores.agregar(organizador4);
	cout << "ORGANIZADORES ORDENADOS POR RANK" << endl;
	misOrganizadores.ordenarPorRank();
	misOrganizadores.mostrarTodos();
	cout << "Organizadores Disponibles" << endl;
	misOrganizadores.mostrarDisponibles();
	cout << "REGISTRAR LOS EVENTOS" << endl;
	cout << endl;
	Evento* evento1 = new Evento("Concierto Años 60 y 70", 201, 3, organizador2);
	Evento* evento2 = new Evento("Fiesta Fin De Anio", 202, 2, organizador1);
	Evento* evento3 = new Evento("Concierto Studio Ghibli", 203, 4, organizador3);
	misEventos.agregar(evento1);
	misEventos.agregar(evento2);
	misEventos.agregar(evento3);
	misEventos.mostrarTodos();
	cout << endl;
	cout << "REGISTRAR A LOS INVITADOS EN UN EVENTO" << endl;
	cout << endl;
	cout << "Agregando invitados a Concierto Años 60 y 70" << endl;
	evento1->agregarInvitado("Garlot", 79286118);
	evento1->agregarInvitado("Ruth", 79097451);
	evento1->agregarInvitado("Hugo", 65173108);
	cout << "Agregando invitados a Fiesta de Fin De Anio" << endl;
	evento2->agregarInvitado("Karlos", 60561788);
	evento2->agregarInvitado("Mariana", 77729300);
	cout << "Agregando invitados a Concierto Studio Ghibli" << endl;
	evento3->agregarInvitado("Mariano", 72915171);
	cout << "Eventos con Invitados" << endl;
	misEventos.mostrarTodos();
	cout << endl;
	cout << "ASIGNAR DE FORMA AUTOMATICA AL ORGANIZADOR DISPONIBLE CON MAYOR RANK" << endl;
	cout << endl;
	cout << "Organizadores antes de nuevo evento" << endl;
	misOrganizadores.mostrarTodos();
	Organizador* disponible = misOrganizadores.buscarDisponibleConMasRank();
	if (disponible != nullptr) {
		cout << "Organizador disponible con mayor rank: " << disponible->getNombre() << " (Rank: " << disponible->getRank() << endl;
		Evento* evento4 = new Evento("Evento Automatico", 204, 2, disponible);
		misEventos.agregar(evento4);
		cout << "Nuevo evento creado y asignado a: " << disponible->getNombre() << endl;
	}
	Organizador* disponible2 = misOrganizadores.buscarDisponibleConMasRank();
	if (disponible2 == nullptr) {
		cout << "No hay organizadores disponibles..." << endl;
	}
	cout << "Organizadores despues del nuevo evento" << endl;
	misOrganizadores.mostrarTodos();
	cout << endl;
	cout << "FINALIZAR LOS EVENTOS CON RANK ACTUALIZADO" << endl;
	cout << endl;
	cout << "Evento a finalizar: Fiesta de Fin De Anio (Rank Actual: " << organizador2->getRank() << ")" << endl;
	evento1->finalizarEvento();
	cout << "Tiene el rank: " << organizador2->getRank() << endl;
	cout << "Estado final de los organizadores" << endl;
	misOrganizadores.ordenarPorRank();
	misOrganizadores.mostrarTodos();
	cout << "Eventos Actualizados" << endl;
	misEventos.mostrarTodos();
}
