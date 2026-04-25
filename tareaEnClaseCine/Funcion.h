#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

// registro funcion 
template <typename t>
class Funcion {
public:
    t id_funcion;
    string horario;
    string pelicula_asignada;
    string sala_asignada;
    string cliente_asignado;

    Funcion(t id_funcion = t(), string horario = "") {
        this->id_funcion = id_funcion;
        this->horario = horario;
        this->pelicula_asignada = "sin asignar";
        this->sala_asignada = "sin asignar";
        this->cliente_asignado = "sin asignar";
    }

    // asignar pelicula a una funcion punto 5
    void asignar_pelicula(string pelicula_titulo) {
        if (pelicula_titulo == "") {
            throw invalid_argument("error nombre pelicula vacio");
        }
        pelicula_asignada = pelicula_titulo;
    }

    // asignar funcion a una sala punto 6
    void asignar_sala(string sala_numero) {
        if (sala_numero == "") {
            throw invalid_argument("error numero sala vacio");
        }
        sala_asignada = sala_numero;
    }

    // asignar cliente a una funcion punto 7
    void asignar_cliente(string cliente_nombre) {
        if (cliente_nombre == "") {
            throw invalid_argument("error nombre cliente vacio");
        }
        cliente_asignado = cliente_nombre;
    }

    void mostrar() {
        cout << "id funcion: " << id_funcion << " horario: " << horario
            << " pelicula: " << pelicula_asignada
            << " sala: " << sala_asignada
            << " cliente: " << cliente_asignado << endl;
    }
};