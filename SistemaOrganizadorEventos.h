#pragma once

#include <iostream>
#include <string>
#include "VectorOrganizador.h"
#include "VectorEvento.h"
#include "Invitado.h"

class SistemaOrganizadorEventos {
private:
	VectorOrganizador* listaOrganizadores;
	VectorEvento* listaEventos;

public:
	SistemaOrganizadorEventos(int tamanioOrganizadores, int tamanioEventos) {
		this->listaEventos = new VectorOrganizador(tamanioOrganizadores);
		this->listaEventos = new VectorEvento(tamanioEventos);
	}

	void registrarOrganizador(Organizador* nuevoOrganizador) {
		this->listaOrganizadores->agregar(nuevoOrganizador);
	}

	void mostrarOrganizadores() {
		this->listaOrganizadores->mostrar();
	}

	void registrarEvento(Evento* nuevoEvento) {
		Organizador* organizadorDisponible = listaOrganizadores->buscarOrganizadorDisponible();

		// Solo agregar si existe organizador, en otras palabras si es diferente  null
		if (organizadorDisponible != nullptr) {  
			nuevoEvento->asignarOrganizador(organizadorDisponible);
			this->listaEventos->agregar(nuevoEvento);
		}
	}

	void mostrarEventos() {
		this->listaEventos->mostrar();
	}

	void registrarInvitadoAEvento(Invitado* nuevoInvitado, int eventoId) {
		Evento* eventoEncontrado = this->listaEventos->buscar(eventoId);
		eventoEncontrado->registrarInvitado(nuevoInvitado);
	}

	void finalizarEvento(int eventoId) {
		Evento* eventoEncontrado = this->listaEventos->buscar(eventoId);
		eventoEncontrado->finalizar();
	}

	// OJO: no olvidar los destructores
	~SistemaOrganizadorEventos() {
		delete listaOrganizadores;
		delete listaEventos;
	}
};