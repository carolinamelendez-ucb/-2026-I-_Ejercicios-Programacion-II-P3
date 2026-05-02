#pragma once
#include "Equipo.h"
#include "Jugador.h"
#include "EquipoDuplicadoException.h"
#include "JugadorDuplicadoException.h"
#include "JugadorNoEncontradoException.h"
#include "EquipoNoEncontradoException.h"
#include "JugadorYaAsignadoException.h"
class SistemaTorneo {
private:
	string nombre;
	ArrayGenerico<Jugador>* listaJugadores;
	ArrayGenerico<Equipo>* listaEquipos;
public:
	SistemaTorneo(string nombre, int tamMaxjugadores, int tamMaxEquipos) :nombre(nombre) {
		this->listaJugadores = new ArrayGenerico<Jugador>(tamMaxjugadores);
		this->listaEquipos = new ArrayGenerico<Equipo>(tamMaxEquipos);
	}

	void registrarEquipo(Equipo* nuevoEquipo){
		Equipo* equipoDuplicado = listaEquipos->comparar(nuevoEquipo->getCodigo(), Equipo::comparar);
		try {
			if (equipoDuplicado != nullptr) {
				throw EquipoDuplicadoException();
			}
			listaEquipos->agregar(nuevoEquipo);
		}
		catch(exception& err){
			cout << "Error: " << err.what()<<endl;
		}

	}
	void registrarJugador(Jugador* nuevoJugador) {
		Jugador* equipoDuplicado = listaJugadores->comparar(nuevoJugador->getCi(), Jugador::comparar);
		try {
			if (equipoDuplicado != nullptr) {
				throw JugadorDuplicadoException();
			}
			listaJugadores->agregar(nuevoJugador);
		}
		catch (exception& err) {
			cout << "Error: " << err.what() << endl;
		}

	}

	void asignarJugadorAEquipo(int ci, int codigo) {
		Equipo* equipoBuscado = listaEquipos->comparar(codigo, Equipo::comparar);
		Jugador* jugadorBuscado = listaJugadores->comparar(ci, Jugador::comparar);
		try {
			if (equipoBuscado == nullptr) {
				throw EquipoNoEncontradoException();
			}
			if (jugadorBuscado == nullptr) {
				throw JugadorNoEncontradoException();
			}
			if (jugadorBuscado->getEstado() == true) {
				throw JugadorYaAsignadoException();
			}
			equipoBuscado->agregarJugador(jugadorBuscado);
		}
		catch (exception& err) {
			cout << "Error: " << err.what() << endl;
		}

	}

	void buscarJugadorCi(int ci) {
		Jugador* jugadorBuscado = listaJugadores->comparar(ci, Jugador::comparar);
		try {
			if (jugadorBuscado == nullptr) {
				throw JugadorNoEncontradoException();
			}
			cout << "El jugador juega en el equipo :" << jugadorBuscado->getEquipo() << endl;
		}
		catch (exception& err) {
			cout << "Error: " << err.what() << endl;
		}
	}
	void mayor() {
		Equipo* mayor = listaEquipos->mayor(Equipo::mayor);
		cout << "El equipo con mayor numero de inscritos es: " << endl;
		mayor->mostrar();
	}

	void ordenar() {
		listaJugadores->ordenar(Jugador::ordenar);
		listaEquipos->ordenar(Equipo::ordenar);

	}
	void mostrarJugadores() {
		listaJugadores->mostrar();
	}
	void mostrarEquipos()
	{
		listaEquipos->mostrar();
	}
};