#pragma once
#include <iostream>
#include <string>
#include "CapacidadMaximaException.h"

using namespace std;

template <class T>
class ArrayGenerico {
private:
    T** lista;
    int tamano;
    int indice;
    static int totalArraysCreados;

public:
    ArrayGenerico(int max) {
        this->lista = new T * [max];
        this->tamano = max;
        this->indice = 0;
        totalArraysCreados++;
    }

    void registrar(T* nuevoElemento) {
        if (indice < tamano) {
            lista[indice] = nuevoElemento;
            indice++;
        }
        else {
            throw CapacidadMaximaException(tamano);
        }
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            cout << *lista[i] << " ";
        }
        cout << endl;
    }

    int obtenerIndice() const {
        return indice;
    }

    T* obtenerElemento(int posicion) const {
        if (posicion >= 0 && posicion < indice) {
            return lista[posicion];
        }
        return nullptr;
    }

    static void mostrarTotalArraysCreados() {
        cout << "Total arrays creados: " << totalArraysCreados << endl;
    }

    ~ArrayGenerico() {
        for (int i = 0; i < indice; i++) {
            delete lista[i];
        }
        delete[] lista;
        cout << "ArrayGenerico destruido" << endl;
        totalArraysCreados--;
    }
};

template <class T>
int ArrayGenerico<T>::totalArraysCreados = 0;