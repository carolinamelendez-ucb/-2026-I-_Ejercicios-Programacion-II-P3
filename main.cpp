// Ejercicio de tarea clase refo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "SistemaOrganizadorEventos.h"
using namespace std;

int main()
{
	SistemaOrganizadorEventos sistema = SistemaOrganizadorEventos(10, 20);

	// Ejercicio 1. Registrar organizadores y mostrar todos los organizadores
	// - Registro de organizadores
	sistema.registrarOrganizador(new Organizador("Juan"));
	sistema.registrarOrganizador(new Organizador("Marcos"));
	sistema.registrarOrganizador(new Organizador("Sofi"));

	// - Mostrar todos los organizadores
	sistema.mostrarOrganizadores();
	cout << endl;

	// Ejercicio 2. Registrar y  mostrar eventos
	sistema.registrarEvento(new Evento(1, "Evento 1", 10));
	sistema.registrarEvento(new Evento(2, "Evento 2", 10));
	sistema.registrarEvento(new Evento(3, "Evento 3", 10));
	sistema.mostrarEventos();
	cout << endl;

	// Ejercicio 3. Registrar invitados dentro de un evento
	sistema.registrarInvitadoAEvento(new Invitado("Maria", 7897), 1); // Se registro Maria al evento ID: 1
	sistema.registrarInvitadoAEvento(new Invitado("Soles", 9877), 2); // Se registro Soles al evento ID: 2

	// Ejercicio 4. Al crear un evento, asignar automaticamente al organizador disponible con el rank mas alto.
	// SI no hay ningún organizador disponible, no registrar el evento

	// - implementación realizada dentro del metodo sistema.registrarEvento()

	// Ejercicio 5. Finalizar un evento actualizando el rank del organizador asignado
	sistema.finalizarEvento(1); // Se especifica finalizar el evento ID:1
}
