// Ejercicio de tarea clase refo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "VectorEvento.h"
using namespace std;

int main()
{
	VectorOrganizador misOrganizadores = VectorOrganizador(50);
	VectorInvitado misInvitados = VectorInvitado(50);
	VectorEvento misEventos = VectorEvento(50);

	Organizador* o1 = new Organizador("pepito", 0);
	Organizador* o2 = new Organizador("pedro", 0);

	misOrganizadores.agregar(o1);
	misOrganizadores.agregar(o2);
	misOrganizadores.mostrar();
	//delete o1;
	//delete o2;

	Invitado* i1 = new Invitado("ariana", 60732937);
	Invitado* i2 = new Invitado("adriana", 70743654);
	misInvitados.agregar(i1);
	misInvitados.agregar(i2);

	//Evento* e1 = new Evento("matrimonio", 0, 30, o1,);



}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
