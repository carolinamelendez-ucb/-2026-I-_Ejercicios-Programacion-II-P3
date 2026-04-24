#pragma once
#include <iostream>
#include <string>
#include "Asiento.h"
#include "Pasajero.h"
#include "ExcepcionesVuelo.h"

using namespace std;

const int MAX_ASIENTOS = 200;
const int MAX_PASAJEROS = 200;

class Vuelo {
private:
    string codigoVuelo;
    string horaPartida;
    string horaLlegadaEsperada;
    string horaLlegadaActual;
    Asiento* asientos[MAX_ASIENTOS];
    Pasajero* pasajeros[MAX_PASAJEROS];
    int totalAsientos;
    int totalPasajeros;
    int filas;
    int columnas;

public:
    Vuelo() : codigoVuelo(""), horaPartida(""), horaLlegadaEsperada(""),
        horaLlegadaActual(""), totalAsientos(0), totalPasajeros(0), filas(0), columnas(0) {
        for (int i = 0; i < MAX_ASIENTOS; i++) {
            asientos[i] = nullptr;
        }
        for (int i = 0; i < MAX_PASAJEROS; i++) {
            pasajeros[i] = nullptr;
        }
    }

    Vuelo(string _codigo, string _horaPartida, string _horaLlegadaEsperada,
        int _filas, int _columnas)
        : codigoVuelo(_codigo), horaPartida(_horaPartida),
        horaLlegadaEsperada(_horaLlegadaEsperada),
        horaLlegadaActual(_horaLlegadaEsperada),
        totalAsientos(0), totalPasajeros(0), filas(_filas), columnas(_columnas) {
        for (int i = 0; i < MAX_ASIENTOS; i++) {
            asientos[i] = nullptr;
        }
        for (int i = 0; i < MAX_PASAJEROS; i++) {
            pasajeros[i] = nullptr;
        }
    }

    string obtenerCodigo() const { 
        return codigoVuelo; 
    }

    string obtenerHoraPartida() const { 
        return horaPartida; 
    }

    string obtenerHoraLlegadaEsperada() const { 
        return horaLlegadaEsperada; 
    }

    string obtenerHoraLlegadaActual() const { 
        return horaLlegadaActual; 
    }

    int obtenerTotalAsientos() const { 
        return totalAsientos; 
    }

    int obtenerTotalPasajeros() const { 
        return totalPasajeros; 
    }

    int obtenerFilas() const { 
        return filas; 
    }

    int obtenerColumnas() const { 
        return columnas; 
    }

    void actualizarHoraLlegada(string nuevaHora) { 
        horaLlegadaActual = nuevaHora; 
    }

    bool llegoATiempo() const {
        return horaLlegadaActual <= horaLlegadaEsperada;
    }

    int calcularRetraso() const {
        if (horaLlegadaActual > horaLlegadaEsperada) {
            int horaActual = stoi(horaLlegadaActual.substr(0, 2));
            int minActual = stoi(horaLlegadaActual.substr(3, 2));
            int horaEsperada = stoi(horaLlegadaEsperada.substr(0, 2));
            int minEsperada = stoi(horaLlegadaEsperada.substr(3, 2));
            return (horaActual * 60 + minActual) - (horaEsperada * 60 + minEsperada);
        }
        return 0;
    }

    void agregarAsiento(string codigoAsiento) {
        if (totalAsientos < MAX_ASIENTOS && totalAsientos < filas * columnas) {
            Asiento* nuevoAsiento = new Asiento(codigoAsiento);
            asientos[totalAsientos] = nuevoAsiento;
            totalAsientos++;
        }
        else {
            throw CapacidadMaximaException();
        }
    }

    Asiento* buscarAsiento(string codigoAsiento) {
        for (int i = 0; i < totalAsientos; i++) {
            if (asientos[i]->obtenerCodigo() == codigoAsiento) {
                return asientos[i];
            }
        }
        return nullptr;
    }

    bool existePasajero(string ci) {
        for (int i = 0; i < totalPasajeros; i++) {
            if (pasajeros[i]->obtenerCI() == ci) {
                return true;
            }
        }
        return false;
    }

    void agregarPasajero(Pasajero* pasajero) {
        if (existePasajero(pasajero->obtenerCI())) {
            throw PasajeroDuplicadoException();
        }

        if (totalPasajeros < MAX_PASAJEROS) {
            pasajeros[totalPasajeros] = pasajero;
            totalPasajeros++;
        }
    }

    void asignarAsientoAPasajero(Pasajero* pasajero, string codigoAsiento) {
        if (!existePasajero(pasajero->obtenerCI())) {
            throw PasajeroNoEncontradoException();
        }

        Asiento* asiento = buscarAsiento(codigoAsiento);
        if (asiento == nullptr) {
            throw AsientoNoExisteException();
        }

        if (!asiento->estaDisponible()) {
            throw AsientoNoDisponibleException();
        }

        if (pasajero->tieneAsiento()) {
            throw PasajeroYaEnVueloException();
        }

        asiento->ocupar();
        pasajero->asignarAsiento(asiento);
        pasajero->asignarVuelo(this);
    }

    void mostrarPasajeros() {
        cout << "\n=== PASAJEROS DEL VUELO " << codigoVuelo << " ===" << endl;
        if (totalPasajeros == 0) {
            cout << "No hay pasajeros registrados en este vuelo." << endl;
            return;
        }

        for (int i = 0; i < totalPasajeros; i++) {
            Pasajero* pasajero = pasajeros[i];
            cout << "Pasajero: " << pasajero->obtenerNombreCompleto()
                << " (CI: " << pasajero->obtenerCI() << ")" << endl;
            cout << "Asiento: " << pasajero->obtenerCodigoAsiento() << endl;
        }
    }

    void mostrarEstadisticasAsientos() {
        int disponibles = 0;
        int ocupados = 0;

        for (int i = 0; i < totalAsientos; i++) {
            if (asientos[i]->estaDisponible()) {
                disponibles++;
            }
            else {
                ocupados++;
            }
        }

        cout << "\n=== ESTADISTICAS DE ASIENTOS - VUELO " << codigoVuelo << " ===" << endl;
        cout << "Asientos disponibles: " << disponibles << endl;
        cout << "Asientos ocupados: " << ocupados << endl;
        cout << "Total asientos: " << totalAsientos << endl;
        cout << "Porcentaje de ocupacion: " << (ocupados * 100 / totalAsientos) << "%" << endl;
    }

    void ordenarPasajerosPorApellido() {
        for (int i = 0; i < totalPasajeros - 1; i++) {
            for (int j = 0; j < totalPasajeros - i - 1; j++) {
                if (pasajeros[j]->obtenerApellido() > pasajeros[j + 1]->obtenerApellido()) {
                    Pasajero* temp = pasajeros[j];
                    pasajeros[j] = pasajeros[j + 1];
                    pasajeros[j + 1] = temp;
                }
            }
        }

        cout << "\n=== PASAJEROS ORDENADOS POR APELLIDO ===" << endl;
        for (int i = 0; i < totalPasajeros; i++) {
            cout << pasajeros[i]->obtenerApellido() << ", "
                << pasajeros[i]->obtenerNombre() << " - CI: "
                << pasajeros[i]->obtenerCI() << endl;
        }
    }

    int obtenerAsientosOcupados() {
        int ocupados = 0;
        for (int i = 0; i < totalAsientos; i++) {
            if (asientos[i]->estaOcupado()) {
                ocupados++;
            }
        }
        return ocupados;
    }

    Pasajero* buscarPasajeroPorCI(string ci) {
        for (int i = 0; i < totalPasajeros; i++) {
            if (pasajeros[i]->obtenerCI() == ci) {
                return pasajeros[i];
            }
        }
        return nullptr;
    }

    bool cambiarAsiento(string ci, string nuevoCodigoAsiento) {
        Pasajero* pasajero = buscarPasajeroPorCI(ci);
        if (pasajero == nullptr) {
            return false;
        }

        Asiento* nuevoAsiento = buscarAsiento(nuevoCodigoAsiento);
        if (nuevoAsiento == nullptr || !nuevoAsiento->estaDisponible()) {
            return false;
        }

        Asiento* asientoActual = pasajero->obtenerAsiento();
        if (asientoActual != nullptr) {
            asientoActual->liberar();
        }

        nuevoAsiento->ocupar();
        pasajero->asignarAsiento(nuevoAsiento);
        return true;
    }
};

