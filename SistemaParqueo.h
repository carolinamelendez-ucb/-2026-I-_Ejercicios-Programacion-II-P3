#pragma once
#include <iostream>
#include "Espacio.h"
#include "Vehiculo.h"
#include "ArrayGenerico.h"
#include "CodigoEspacioDuplicadoException.h"
#include "PlacaDuplicadaException.h"
#include "VehiculoNoEncontradoException.h"
#include "NoHayEspaciosDisponiblesException.h"
#include "VehiculoYaAsignadoException.h"
using namespace std;

class SistemaParqueo {
private:
    string nombreEmpresa;
    string direccion;
    int    capacidadMaxima;
    ArrayGenerico<Espacio>* listaEspacios;
    ArrayGenerico<Vehiculo>* listaVehiculos;

public:
    SistemaParqueo(string nombre, string direccion, int maxEspacios, int maxVehiculos) {
        this->nombreEmpresa = nombre;
        this->direccion = direccion;
        this->capacidadMaxima = maxEspacios;
        this->listaEspacios = new ArrayGenerico<Espacio>(maxEspacios);
        this->listaVehiculos = new ArrayGenerico<Vehiculo>(maxVehiculos);
    }

    ~SistemaParqueo() {
        delete listaEspacios;
        delete listaVehiculos;
    }

    void registrarEspacioEstacionamiento(Espacio* nuevoEspacio) {
        try {
            string codigoNuevo = nuevoEspacio->getCodigo();
            Espacio* duplicado =
                listaEspacios->buscar(codigoNuevo, Espacio::compararCodigo);

            if (duplicado != nullptr) {
                throw CodigoEspacioDuplicadoException();
            }

            listaEspacios->registrar(nuevoEspacio);
            cout << "  Espacio [" << codigoNuevo << "] registrado correctamente." << endl;
        }
        catch (exception& err) {
            cout << "Error al registrar espacio: " << err.what() << endl;
            delete nuevoEspacio;
        }
    }

    void registrarVehiculo(Vehiculo* nuevoVehiculo) {
        try {
            string placaNueva = nuevoVehiculo->getPlaca();
            Vehiculo* duplicado =
                listaVehiculos->buscar(placaNueva, Vehiculo::compararPlaca);

            if (duplicado != nullptr) {
                throw PlacaDuplicadaException();
            }

            listaVehiculos->registrar(nuevoVehiculo); // puede lanzar CapacidadMaximaException
            cout << "  Vehiculo [" << placaNueva << "] registrado correctamente." << endl;
        }
        catch (exception& err) {
            cout << "Error al registrar vehiculo: " << err.what() << endl;
            delete nuevoVehiculo;
        }
    }

    void asignarVehiculo(string placa) {
        try {
            bool estaOcupado = false;
            Espacio* espacioDisponible =
                listaEspacios->buscar(estaOcupado, Espacio::compararDisponibilidad);

            if (espacioDisponible == nullptr) {
                throw NoHayEspaciosDisponiblesException();
            }

            Vehiculo* vehiculoBuscado =
                listaVehiculos->buscar(placa, Vehiculo::compararPlaca);

            if (vehiculoBuscado == nullptr) {
                throw VehiculoNoEncontradoException();
            }

            if (vehiculoBuscado->tieneEspacioAsignado()) {
                throw VehiculoYaAsignadoException();
            }

            vehiculoBuscado->asignarEspacio(espacioDisponible);
            cout << "  Vehiculo [" << placa << "] asignado al espacio ["
                << espacioDisponible->getCodigo() << "]." << endl;
        }
        catch (exception& err) {
            cout << "Error al asignar vehiculo: " << err.what() << endl;
        }
    }

    void buscarVehiculo(string placa) {
        Vehiculo* encontrado =
            listaVehiculos->buscar(placa, Vehiculo::compararPlaca);

        cout << "\n=== Busqueda de vehiculo [" << placa << "] ===" << endl;
        if (encontrado != nullptr) {
            encontrado->mostrar();
        }
        else {
            cout << "  Vehiculo no encontrado." << endl;
        }
    }

    void ordenarYMostrarVehiculosPorMarca() {
        listaVehiculos->ordenar(Vehiculo::compararMarca);
        cout << "\n=== Vehiculos ordenados por marca ===" << endl;
        listaVehiculos->mostrarTodos();
    }

    void mostrarEspaciosDisponibles() {
        cout << "\n=== Espacios disponibles en " << nombreEmpresa << " ===" << endl;
        bool estaOcupado = false;
        listaEspacios->mostrar(estaOcupado, Espacio::compararDisponibilidad);
    }

   
    void mostrarVehiculosEstacionados() {
        cout << "\n=== Vehiculos actualmente estacionados ===" << endl;
        bool tieneEspacio = true;
      
        listaVehiculos->mostrar(tieneEspacio,
            [](Vehiculo* v, bool val) { return v->tieneEspacioAsignado() == val; });
    }
};