#pragma once
#include <iostream>
#include "Evento.h"
#include "VectorOrganizadores.h"

using namespace std;

class EventosVector {

private:

    Evento** eventos;
    int indice;
    int tamanio;

public:

    EventosVector(int tamanio)
        : tamanio(tamanio), indice(0)
    {
        eventos = new Evento * [tamanio];
    }

    ~EventosVector() {
        for (int i = 0; i < indice; i++) {

            delete eventos[i];
        }
        delete[] eventos;
    }

    void crearEvento(const string& nombre, int id, int maxInvitados, OrganizadoresVector* organizadores) {
        Organizador* organizador = organizadores->buscarDisponibleMayorRank();
        eventos[indice] = new Evento(nombre, id, maxInvitados, organizador);
        indice++;
    }

    Evento* getEvento(int pos) {
        return eventos[pos];
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {

            cout << "EVENTO " << i + 1 << endl;
            eventos[i]->mostrar();
            cout << endl;
        }
    }
};
