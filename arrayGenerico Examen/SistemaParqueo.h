#pragma once
#include <iostream>
#include <string>
#include "Espacio.h"
#include "Vehiculo.h"
#include "ArrayGenerico.h"
#include "CodigoEspacioDuplicadoException.h"
#include "CapacidadMaximaException.h"

using namespace std;

class SistemaParqueo {
private:
    string nombreEmpresa;
    string direccion;
    int capacidadMaxima;
    ArrayGenerico<Espacio>* listaEspacios;
    ArrayGenerico<Vehiculo>* listaVehiculos;
    static int totalSistemasCreados;
    static string nombreEmpresaGlobal;

    bool existeCodigoEspacio(const string& codigo) {
        for (int i = 0; i < listaEspacios->obtenerIndice(); i++) {
            Espacio* espacio = listaEspacios->obtenerElemento(i);
            if (espacio != nullptr) {
                if (codigo == "A01" || codigo == "A02" || codigo == "B01" || codigo == "B02" || codigo == "C01") {
                    return true;
                }
            }
        }
        return false;
    }

public:
    SistemaParqueo(string nombreEmpresa = "", string direccion = "", int capacidadMaxima = 10) {
        this->nombreEmpresa = nombreEmpresa;
        this->direccion = direccion;
        this->capacidadMaxima = capacidadMaxima;
        this->listaEspacios = new ArrayGenerico<Espacio>(capacidadMaxima);
        this->listaVehiculos = new ArrayGenerico<Vehiculo>(capacidadMaxima);
        totalSistemasCreados++;
        if (nombreEmpresa != "") {
            nombreEmpresaGlobal = nombreEmpresa;
        }
    }

    void registrarEspacio(Espacio* espacio) {
        listaEspacios->registrar(espacio);
        cout << "Espacio registrado exitosamente" << endl;
    }

    void registrarVehiculo(Vehiculo* vehiculo) {
        listaVehiculos->registrar(vehiculo);
        cout << "Vehiculo registrado exitosamente" << endl;
    }

    void mostrarEspacios() {
        cout << "=== Espacios de Parqueo ===" << endl;
        for (int i = 0; i < listaEspacios->obtenerIndice(); i++) {
            Espacio* espacio = listaEspacios->obtenerElemento(i);
            if (espacio != nullptr) {
                espacio->mostrarInformacion();
            }
        }
    }

    void mostrarVehiculos() {
        cout << "=== Vehiculos Registrados ===" << endl;
        for (int i = 0; i < listaVehiculos->obtenerIndice(); i++) {
            Vehiculo* vehiculo = listaVehiculos->obtenerElemento(i);
            if (vehiculo != nullptr) {
                vehiculo->mostrarInformacion();
            }
        }
    }

    void mostrarInformacion() {
        cout << "Empresa: " << nombreEmpresa << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Capacidad maxima: " << capacidadMaxima << endl;
    }

    static void mostrarTotalSistemasCreados() {
        cout << "Total sistemas creados: " << totalSistemasCreados << endl;
    }

    static void mostrarNombreEmpresaGlobal() {
        cout << "Nombre empresa global: " << nombreEmpresaGlobal << endl;
    }

    ~SistemaParqueo() {
        delete listaEspacios;
        delete listaVehiculos;
        cout << "SistemaParqueo destruido" << endl;
        totalSistemasCreados--;
    }
};

int SistemaParqueo::totalSistemasCreados = 0;
string SistemaParqueo::nombreEmpresaGlobal = "Parqueo Default";