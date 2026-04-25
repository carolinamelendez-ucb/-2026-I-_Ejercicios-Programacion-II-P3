#pragma once
#include <iostream>
using namespace std;
#include "ArrayGenerico.h"
#include "Sala.h"
#include "Pelicula.h"
#include "Funcion.h"
#include "Cliente.h"

class SistemaCine {
    private:
    int cap;
    ArrayGenerico<Sala*>* salas;
    ArrayGenerico<Pelicula*>* peliculas;
    ArrayGenerico<Funcion*>* funciones;
    ArrayGenerico<Cliente*>* clientes;

    public:
    SistemaCine (int cap ): cap (cap){
        salas = new ArrayGenerico<Sala*> (cap);
        peliculas = new ArrayGenerico<Pelicula*> (cap);
        funciones = new ArrayGenerico<Funcion*> (cap);
        clientes = new ArrayGenerico<Cliente*> (cap);
    }

    ~SistemaCine () {
        delete salas;
        delete peliculas;
        delete funciones;
        delete clientes;
    }

    void registrarCliente (Cliente* c)   { clientes->agregar (c); }
    void registrarSala (Sala* s)         { salas->agregar (s); }
    void registrarPelicula (Pelicula* p) { peliculas->agregar (p); }
    void registrarFuncion (Funcion* f)   { funciones->agregar (f); }

    void asignarPeliculaAFuncion (int idxFuncion, int idxPelicula) {
        funciones->obtener (idxFuncion)->asignarPelicula (peliculas->obtener (idxPelicula));
    }

    void asignarFuncionASala (int idxSala, int idxFuncion) {
        salas->obtener (idxSala)->asignarFuncion (funciones->obtener (idxFuncion));
    }

    void asignarClienteAFuncion (int idxCliente, int idxFuncion) {
        funciones->obtener (idxFuncion)->agregarCliente (clientes->obtener (idxCliente));
    }

    void mostrarClientes () const {
        cout << "=== Clientes ===" << endl;
        for(int i = 0; i < clientes->getIndice (); i++)
            clientes->obtener (i)->mostrar ();
    }

    void mostrarSalas () const {
        cout << "=== Salas ===" << endl;
        for(int i = 0; i < salas->getIndice (); i++)
            salas->obtener (i)->mostrar ();
    }

    void mostrarPeliculas () const {
        cout << "=== Peliculas ===" << endl;
        for(int i = 0; i < peliculas->getIndice (); i++)
            peliculas->obtener (i)->mostrar ();
    }

    void mostrarFunciones () const {
        cout << "=== Funciones ===" << endl;
        for(int i = 0; i < funciones->getIndice (); i++)
            funciones->obtener (i)->mostrar ();
    }
};