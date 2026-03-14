#pragma once
#include "ClientesVector.h"
#include "SalasVector.h"
#include "PeliculasVector.h"
#include "FuncionesVector.h"

class SistemaCine {

private:
    ClientesVector clientes;
    SalasVector salas;
    PeliculasVector peliculas;
    FuncionesVector funciones;

public:

    SistemaCine()
        : clientes(10), salas(10), peliculas(10), funciones(10)
    {
    }

    void registrarCliente(string nombre, int telefono) {
        clientes.agregar(new Cliente(nombre, telefono));
    }

    void registrarSala(int numero, int filas, int asientos) {
        salas.agregar(new Sala(numero, filas, asientos));
    }

    void registrarPelicula(string nombre, int codigo) {
        peliculas.agregar(new Pelicula(nombre, codigo));
    }

    void registrarFuncion(int codigo, int salaPos, int peliculaPos, float precio) {
        funciones.agregar(new Funcion(
            codigo,
            salas.getSala(salaPos),
            peliculas.getPelicula(peliculaPos),
            precio
        ));
    }

    void venderBoleto(int funcionPos) {
        funciones.getFuncion(funcionPos)->venderBoleto();
    }

    void mostrarClientes() { clientes.mostrar(); }
    void mostrarSalas() { salas.mostrar(); }
    void mostrarPeliculas() { peliculas.mostrar(); }
    void mostrarFunciones() { funciones.mostrar(); }

    void reporteFuncion(int pos) {
        cout << "Ganancia: " << funciones.getFuncion(pos)->getGanancia() << endl;
    }

};