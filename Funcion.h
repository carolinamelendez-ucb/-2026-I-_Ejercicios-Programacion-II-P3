#pragma once
#include <iostream>
#include <string>
#include "Pelicula.h"
#include "Sala.h"
#include "ArrayGenerica.h"
#include "Cliente.h"
using namespace std;

class Funcion {
private:
    Pelicula* pelicula;
    Sala* sala;
    ArrayGenerica<Cliente>* clientes;
    string horario;
    bool** asientosOcupados;

public:
    Funcion() : pelicula(nullptr), sala(nullptr), clientes(nullptr),
        horario(""), asientosOcupados(nullptr) {
    }

    Funcion(Pelicula* p, Sala* s, ArrayGenerica<Cliente>* c, string hora)
        : pelicula(p), sala(s), clientes(c), horario(hora), asientosOcupados(nullptr) {

        inicializarAsientos();
    }

    ~Funcion() {
        liberarAsientos();
    }

    Funcion(const Funcion& other)
        : pelicula(other.pelicula),
        sala(other.sala),
        clientes(other.clientes),
        horario(other.horario),
        asientosOcupados(nullptr) {

        if (sala != nullptr && other.asientosOcupados != nullptr) {
            int filas = sala->getFilas();
            int asientosPorFila = sala->getAsientosPorFila();

            asientosOcupados = new bool* [filas];
            for (int i = 0; i < filas; i++) {
                asientosOcupados[i] = new bool[asientosPorFila];
                for (int j = 0; j < asientosPorFila; j++) {
                    asientosOcupados[i][j] = other.asientosOcupados[i][j];
                }
            }
        }
    }

    Funcion& operator=(const Funcion& other) {
        if (this != &other) {
            liberarAsientos();

            pelicula = other.pelicula;
            sala = other.sala;
            clientes = other.clientes;
            horario = other.horario;

            if (sala != nullptr && other.asientosOcupados != nullptr) {
                int filas = sala->getFilas();
                int asientosPorFila = sala->getAsientosPorFila();

                asientosOcupados = new bool* [filas];
                for (int i = 0; i < filas; i++) {
                    asientosOcupados[i] = new bool[asientosPorFila];
                    for (int j = 0; j < asientosPorFila; j++) {
                        asientosOcupados[i][j] = other.asientosOcupados[i][j];
                    }
                }
            }
            else {
                asientosOcupados = nullptr;
            }
        }
        return *this;
    }

    void inicializarAsientos() {
        liberarAsientos(); 

        if (sala != nullptr) {
            int filas = sala->getFilas();
            int asientosPorFila = sala->getAsientosPorFila();

            asientosOcupados = new bool* [filas];
            for (int i = 0; i < filas; i++) {
                asientosOcupados[i] = new bool[asientosPorFila];
                for (int j = 0; j < asientosPorFila; j++) {
                    asientosOcupados[i][j] = false;
                }
            }
        }
    }

    void liberarAsientos() {
        if (asientosOcupados != nullptr && sala != nullptr) {
            int filas = sala->getFilas();
            for (int i = 0; i < filas; i++) {
                delete[] asientosOcupados[i];
            }
            delete[] asientosOcupados;
            asientosOcupados = nullptr;
        }
    }

    void registrar() {
        cout << "Horario de la función: ";
        cin.ignore();
        getline(cin, horario);
        cout << "Función registrada exitosamente" << endl;
    }

    void mostrar() const {
        cout << "Función | Película: " << pelicula->getTitulo()
            << " | Sala: " << sala->getNumeroSala()
            << " | Horario: " << horario;
    }

    void venderAsiento(Cliente& cliente, int fila, int asiento) {
        if (sala == nullptr) {
            cout << "Error: Sala no definida" << endl;
            return;
        }

        if (asientosOcupados == nullptr) {
            cout << "Error: Asientos no inicializados" << endl;
            return;
        }

        if (fila < 0 || fila >= sala->getFilas() ||
            asiento < 0 || asiento >= sala->getAsientosPorFila()) {
            cout << "Error: Asiento no válido" << endl;
            return;
        }

        if (asientosOcupados[fila][asiento]) {
            cout << "Error: Asiento ya está ocupado" << endl;
            return;
        }

        asientosOcupados[fila][asiento] = true;
        if (clientes != nullptr) {
            clientes->agregar(cliente);
        }
        cout << "Asiento vendido exitosamente a " << cliente.getNombre() << endl;
    }

    void mostrarAsientos() const {
        if (sala == nullptr) {
            cout << "Error: Sala no definida" << endl;
            return;
        }

        if (asientosOcupados == nullptr) {
            cout << "Error: Asientos no inicializados" << endl;
            return;
        }

        cout << "\nMapa de asientos:" << endl;
        cout << "   ";
        for (int j = 0; j < sala->getAsientosPorFila(); j++) {
            cout << j << " ";
        }
        cout << endl;

        for (int i = 0; i < sala->getFilas(); i++) {
            cout << i << "  ";
            for (int j = 0; j < sala->getAsientosPorFila(); j++) {
                if (asientosOcupados[i][j]) {
                    cout << "X ";
                }
                else {
                    cout << "O ";
                }
            }
            cout << endl;
        }
    }


    void setPelicula(Pelicula* p) { pelicula = p; }

    void setSala(Sala* s) {
        sala = s;
        inicializarAsientos(); 
    }

    void setClientes(ArrayGenerica<Cliente>* c) { clientes = c; }
    void setHorario(string h) { horario = h; }

    Pelicula* getPelicula() const { return pelicula; }
    Sala* getSala() const { return sala; }
    ArrayGenerica<Cliente>* getClientes() const { return clientes; }
    string getHorario() const { return horario; }
};