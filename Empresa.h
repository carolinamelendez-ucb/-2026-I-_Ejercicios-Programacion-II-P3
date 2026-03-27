#pragma once
#include "ListaEventos.h"
#include "ListaOrganizadores.h"
#include "Invitado.h"
class Empresa
{
private:
	ListaEventos* Eventos;
	ListaOrganizadores* Organizadores;
public:
	Empresa(int tamEventos, int tamOrganizadores)
	{
		Eventos = new ListaEventos(tamEventos);
		Organizadores = new ListaOrganizadores(tamOrganizadores);
	}
	void registrarOrganizador(Organizador* organizador)
	{
		Organizadores->registrarOrganizador(organizador);
	}
	void mostrarOrganizadores()
	{
		Organizadores->OrdenarOrganizadores();
		Organizadores->mostrar();
	}
	void RegistrarEvento(Evento* evento)
	{
		Organizador* libre = Organizadores->BuscarLibre();
		if (libre != nullptr)
		{
			evento->asignarOrganizador(libre);
			Eventos->registrar(evento);
		}
		else
		{
			cout << "no se registro el evento porque no hay organizador libre";
		}
	}
	void mostrarEventos()
	{
		Eventos->mostrarEvento();
	}
	void agregarInvitado(int id,Invitado* invitado)
	{
		Eventos->buscarEvento(id,invitado);
	}
	void RegistrarEventoConMayorRank(Evento* evento)
	{
		Organizador* libre = Organizadores->BuscarmayorRank();
		if (libre != nullptr)
		{
			evento->asignarOrganizador(libre);
			Eventos->registrar(evento);
		}
		else
		{
			cout << "no se registro el evento porque no hay organizador libre";
		}
	}
	void finalizar(int id)
	{
		Eventos->finalizarEventos(34);
	}
};

