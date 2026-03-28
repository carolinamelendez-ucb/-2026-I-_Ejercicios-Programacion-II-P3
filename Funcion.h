#pragma once
#include <iostream>
#include "Empleado.h"
#include "VectorEspectadores.h"

using namespace std;

class Funcion {

private:
    string nombrePelicula;
    int codigo;
    int maxEspectadores;
    VectorEspectadores* espectadores;
    Empleado* empleadoAsignado;
    bool activa;

public:

    Funcion(int codigo, const string& nombrePelicula, int maxEspectadores, Empleado* empleadoAsignado)
        : codigo(codigo), nombrePelicula(nombrePelicula),
        empleadoAsignado(empleadoAsignado), activa(true)
    {
        espectadores = new VectorEspectadores(maxEspectadores);
        empleadoAsignado->ocupar();
    }

    ~Funcion() {
        delete espectadores;
    }

    int getCodigo() { return codigo; }
    bool estaActiva() { return activa; }

    void agregarEspectador(const string& nombre, const string& telefono) {
        espectadores->agregar(new Espectador(nombre, telefono));
    }

    void finalizar() {
        activa = false;
        empleadoAsignado->liberar();
        empleadoAsignado->incrementarFunciones();
    }

    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Pelicula: " << nombrePelicula << endl;
        cout << "Cantidad espectadores: " << espectadores->getCantidad() << endl;

        cout << "Empleado asignado:" << endl;
        empleadoAsignado->mostrar();
    }
};