#pragma once
#include "Proyecto.h"

class VectorProyectos {
private:
    Proyecto** lista;
    int indice, tamanio;

public:
    VectorProyectos(int tamaniot) {
       this-> tamanio = tamanio;
        this->indice = 0;
       this-> lista = new Proyecto * [tamanio];
    }

    bool agregar(Proyecto* nuevoProyecto) {
        for (int i = 0; i < indice; i++)
            if (lista[i]->getCodigo() == nuevoProyecto->getCodigo())
                return false;

        lista[indice++] = nuevoProyecto;
        return true;
    }

    Proyecto* mayorCosto() {
        if (indice == 0) return nullptr;

        Proyecto* mayor = lista[0];

        for (int i = 1; i < indice; i++)
            if (lista[i]->calcularCosto() > mayor->calcularCosto())
                mayor = lista[i];

        return mayor;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++)
            lista[i]->mostrarInformacion();
    }
};