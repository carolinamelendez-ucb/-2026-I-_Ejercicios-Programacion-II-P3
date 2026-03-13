#pragma once
#include <iostream>
#include <string>
#include "VectorInvitados.h"
#include "Organizador.h"

using namespace std;

class Evento {

private:
    string nombre;
    int id;
    int maxInvitados;
    InvitadosVector* invitados;
    Organizador* organizador;
    bool finalizado;

public:
    Evento(const string& nombre, int id, int maxInvitados, Organizador* organizador)
        : nombre(nombre), id(id), maxInvitados(maxInvitados), organizador(organizador), finalizado(false)
    {
        invitados = new InvitadosVector(maxInvitados);
        organizador->ocupar();
    }

    ~Evento() {
        delete invitados;
    }

    void registrarInvitado(const string& nombre, int telefono) {
        invitados->agregar(new Invitado(nombre, telefono));
    }

    void finalizar() {
        if (!finalizado) {
            organizador->incrementarRank();
            organizador->liberar();
            finalizado = true;
        }
    }

    void mostrar() {
        cout << "Evento: " << nombre << endl;
        cout << "ID: " << id << endl;
        cout << "Organizador: " << organizador->getNombre() << endl;
        cout << endl;
        cout << "INVITADOS" << endl;
        cout << endl;
        invitados->mostrar();
    }

    Organizador* getOrganizador() { return organizador; }
};