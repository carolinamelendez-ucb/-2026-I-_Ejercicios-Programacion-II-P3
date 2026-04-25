#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Pelicula.h"
#include "ArrayGenerico.h"
#include "Cliente.h"

class Funcion {
    private:
    int nroFuncion;
    Pelicula* peliculaAsignada;
    ArrayGenerico<Cliente*>* listaClientes;  // fix: un solo array de punteros a Cliente

    public:
    Funcion () : nroFuncion (0), peliculaAsignada (nullptr), listaClientes (nullptr) {}

    Funcion (int nroFuncion, int capacidad)
        : nroFuncion (nroFuncion), peliculaAsignada (nullptr)
    {
        this->listaClientes = new ArrayGenerico<Cliente*> (capacidad);
    }

    ~Funcion () {
        delete listaClientes;
    }

    int getNroFuncion ()           const { return nroFuncion; }
    Pelicula* getPelicula ()       const { return peliculaAsignada; }

    // 5. Asignar película a una función
    void asignarPelicula (Pelicula* p) {
        peliculaAsignada = p;
        cout << "  Pelicula \"" << p->getNombre ()
            << "\" asignada a funcion " << nroFuncion << endl;
    }

    // 7. Asignar cliente a una función
    void agregarCliente (Cliente* c) {
        listaClientes->agregar (c);
        cout << "  Cliente \"" << c->getNombre ()
            << "\" agregado a funcion " << nroFuncion << endl;
    }

    void mostrar () const {
        cout << "  Funcion #" << nroFuncion;
        if(peliculaAsignada)
            cout << " | Pelicula: " << peliculaAsignada->getNombre ();
        else
            cout << " | Sin pelicula asignada";
        cout << " | Clientes: " << listaClientes->getIndice () << endl;

        for(int i = 0; i < listaClientes->getIndice (); i++) {
            cout << "    - ";
            listaClientes->obtener (i)->mostrar ();
        }
    }
};