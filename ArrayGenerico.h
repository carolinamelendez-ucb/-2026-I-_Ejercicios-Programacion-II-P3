#pragma once
#include <iostream>
using namespace std;

template<class T>
class ArrayGenerico {
    private:
    T* lista;
    int tamanio;
    int indice;

    public:
    ArrayGenerico (int tamanio)
        : tamanio (tamanio), indice (0)
    {
        this->lista = new T[tamanio];
    }

    ~ArrayGenerico () {
        delete[] lista;
    }

    void agregar (T nuevoElemento) {
        if(indice < tamanio) {
            lista[indice] = nuevoElemento;
            indice++;
        }
        else {
            cout << "  [!] Array lleno." << endl;
        }
    }

    T obtener (int i) const {
        return lista[i];
    }

    int getIndice () const {
        return indice;
    }

    int getTamanio () const {
        return tamanio;
    }
};