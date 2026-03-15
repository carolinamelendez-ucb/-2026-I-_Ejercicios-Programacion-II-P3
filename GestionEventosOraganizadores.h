#pragma once
#include <iostream>
#include <string>
#include "VectorEvento.h"
#include "VectorOrganizado.h"
#include "VectorInvitados.h"
using namespace std;
class GestorEmpresa {
private:
	string nombre;
	VectorOrganizador misOrganizadores;
	VectorEvento misEventos;
public:
	GestorEmpresa() = default;
    GestorEmpresa(string nombre, int tamOrg, int tamEventos)
        : nombre(nombre), misOrganizadores(tamOrg), misEventos(tamEventos, &misOrganizadores)
    {
    }

    void registrarOrganizador(string nombreOrg, bool disponibilidad, int rank) {
        Organizador* nuevo = new Organizador(nombreOrg, disponibilidad, rank);
        misOrganizadores.agregar(nuevo);
    }

    void mostrarOrganizadores() {
        cout << "--- ORGANIZADORES ---"<<endl;
        misOrganizadores.mostrar();
    }

    void registrarEvento(string nombreEvento, int maxInvitados) {
        VectorInvitado lista(100); 
        Evento* nuevoEvento = new Evento(nombreEvento, maxInvitados, lista, nullptr);// nullptr puntero vacio
        misEventos.agregar(nuevoEvento);
    }

    void mostrarEventos() {
        cout << "--- EVENTOS ---"<<endl;
        misEventos.mostrar();
    }

    void finalizarEvento(int posEvento) {
        misEventos.finalizarEvento(posEvento);
    }
    void registrarInvitadoEvento(int posEvento, string nombreInv, string telefono) {
        
        Invitado* nuevo = new Invitado(nombreInv, telefono);
        misEventos.getEvento(posEvento)->agregarInvitadoDesdeEvento(nuevo);
    }



};