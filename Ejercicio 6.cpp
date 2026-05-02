// Ejercicio 6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "SistemaTorneo.h"

int main()
{
	SistemaTorneo* sistema = new SistemaTorneo("Fuchibol", 50, 50);

	sistema->registrarEquipo(new Equipo(123, "Zorros", 12));
	sistema->registrarEquipo(new Equipo(12, "Albuadores", 12));
	sistema->registrarEquipo(new Equipo(123, "Los kiko", 12));
	//sistema->mostrarEquipos();
	cout << endl;
	sistema->registrarJugador(new Jugador(1, "Kiko", "Delantero", 10));
	sistema->registrarJugador(new Jugador(2, "Alan", "Defensa", 9));
	sistema->registrarJugador(new Jugador(1, "Carlos", "Delantero", 8));
	//sistema->mostrarJugadores();
	cout << endl;
	sistema->asignarJugadorAEquipo(1, 123);
	//sistema->asignarJugadorAEquipo(1, 12);
	sistema->asignarJugadorAEquipo(1435, 12);

	sistema->buscarJugadorCi(1);
	sistema->ordenar();
//	sistema->mostrarEquipos();

	cout << endl;
	//sistema->mostrarJugadores();

	sistema->mayor();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
