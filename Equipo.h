#pragma once
#include "ArrayGenerico.h"
#include "Jugador.h"

class Equipo {
private:
	int codigo;
	string nombre;
	int maxJugadores;
	ArrayGenerico<Jugador>* listaJugadores;
	int jugadoresInscritos;

public:

	Equipo(int codigo, const string& nombre, int maxJugadores)
		: codigo(codigo), nombre(nombre), maxJugadores(maxJugadores), jugadoresInscritos(0)
	{
		this->listaJugadores = new ArrayGenerico<Jugador>(maxJugadores);
	}
	void mostrar() {
		cout<< "Codigo: " << codigo << endl;
		cout << "nombre: "<< nombre <<endl;
		cout << "Jugadores: " << endl;
		listaJugadores->mostrar();
	}
	
	int getCodigo() {
		return codigo;
	}
	static bool comparar(Equipo* equipoComparar, int codigo) {
		return equipoComparar->codigo == codigo;
	}

	void agregarJugador(Jugador* nuevoJugador) {
		listaJugadores->agregar(nuevoJugador);
		nuevoJugador->actualizarEstado();
		nuevoJugador->agregarEquipo(nombre);
		jugadoresInscritos++;
	}

	static bool ordenar(Equipo* equipoA, Equipo* equipoB) {
		return equipoA->nombre > equipoB->nombre;
	}

	static bool mayor(Equipo* equipoA, Equipo* equipoB) {
		return equipoA->jugadoresInscritos > equipoB->jugadoresInscritos;
	}
};
