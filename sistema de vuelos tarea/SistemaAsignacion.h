#pragma once
#include <iostream>
#include <string>
#include "Vuelo.h"
#include "Pasajero.h"
#include "ExcepcionesVuelo.h"

using namespace std;

const int MAX_VUELOS = 50;
const int MAX_PASAJEROS_SISTEMA = 200;

class SistemaAsignacion {
private:
    string nombreAerolinea;
    Vuelo* listaVuelos[MAX_VUELOS];
    Pasajero* listaPasajeros[MAX_PASAJEROS_SISTEMA];
    int totalVuelos;
    int totalPasajerosSistema;

public:
    SistemaAsignacion(string _nombre) : nombreAerolinea(_nombre), totalVuelos(0), totalPasajerosSistema(0) {
        for (int i = 0; i < MAX_VUELOS; i++) {
            listaVuelos[i] = nullptr;
        }
        for (int i = 0; i < MAX_PASAJEROS_SISTEMA; i++) {
            listaPasajeros[i] = nullptr;
        }
    }

    ~SistemaAsignacion() {
        for (int i = 0; i < totalVuelos; i++) {
            delete listaVuelos[i];
        }
        for (int i = 0; i < totalPasajerosSistema; i++) {
            delete listaPasajeros[i];
        }
    }

    void registrarVuelo(string codigo, string horaPartida, string horaLlegadaEsperada,
        int filas, int columnas) {
        if (totalVuelos < MAX_VUELOS) {
            Vuelo* nuevoVuelo = new Vuelo(codigo, horaPartida, horaLlegadaEsperada, filas, columnas);
            listaVuelos[totalVuelos] = nuevoVuelo;
            totalVuelos++;
            cout << "Vuelo " << codigo << " registrado exitosamente." << endl;

            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    string codigoAsiento = string(1, char('A' + i)) + to_string(j + 1);
                    registrarAsientoEnVuelo(codigo, codigoAsiento);
                }
            }
        }
        else {
            cout << "No se pueden registrar mas vuelos. Limite alcanzado." << endl;
        }
    }

    void registrarAsientoEnVuelo(string codigoVuelo, string codigoAsiento) {
        Vuelo* vuelo = buscarVuelo(codigoVuelo);
        if (vuelo == nullptr) {
            throw VueloNoEncontradoException();
        }
        vuelo->agregarAsiento(codigoAsiento);
    }

    void registrarPasajero(string ci, string nombre, string apellido) {
        // Verificar si ya existe
        for (int i = 0; i < totalPasajerosSistema; i++) {
            if (listaPasajeros[i]->obtenerCI() == ci) {
                throw PasajeroDuplicadoException();
            }
        }

        if (totalPasajerosSistema < MAX_PASAJEROS_SISTEMA) {
            Pasajero* nuevoPasajero = new Pasajero(ci, nombre, apellido);
            listaPasajeros[totalPasajerosSistema] = nuevoPasajero;
            totalPasajerosSistema++;
            cout << "✓ Pasajero " << nombre << " " << apellido << " registrado exitosamente." << endl;
        }
        else {
            cout << "No se pueden registrar mas pasajeros. Limite alcanzado." << endl;
        }
    }

    Vuelo* buscarVuelo(string codigoVuelo) {
        for (int i = 0; i < totalVuelos; i++) {
            if (listaVuelos[i]->obtenerCodigo() == codigoVuelo) {
                return listaVuelos[i];
            }
        }
        return nullptr;
    }

    Pasajero* buscarPasajero(string ci) {
        for (int i = 0; i < totalPasajerosSistema; i++) {
            if (listaPasajeros[i]->obtenerCI() == ci) {
                return listaPasajeros[i];
            }
        }
        return nullptr;
    }

    void asignarPasajeroAVuelo(string ci, string codigoVuelo, string codigoAsiento) {
        Pasajero* pasajero = buscarPasajero(ci);
        if (pasajero == nullptr) {
            throw PasajeroNoEncontradoException();
        }

        Vuelo* vuelo = buscarVuelo(codigoVuelo);
        if (vuelo == nullptr) {
            throw VueloNoEncontradoException();
        }

        // Agregar pasajero al vuelo
        vuelo->agregarPasajero(pasajero);

        // Asignar asiento
        vuelo->asignarAsientoAPasajero(pasajero, codigoAsiento);

        cout << "Asignación exitosa: " << pasajero->obtenerNombreCompleto()
            << " asignado al vuelo " << codigoVuelo << " asiento " << codigoAsiento << endl;
    }

    void mostrarPasajerosDeVuelo(string codigoVuelo) {
        Vuelo* vuelo = buscarVuelo(codigoVuelo);
        if (vuelo == nullptr) {
            throw VueloNoEncontradoException();
        }
        vuelo->mostrarPasajeros();
    }

    void mostrarEstadisticasVuelo(string codigoVuelo) {
        Vuelo* vuelo = buscarVuelo(codigoVuelo);
        if (vuelo == nullptr) {
            throw VueloNoEncontradoException();
        }
        vuelo->mostrarEstadisticasAsientos();
    }

    void mostrarVuelosATiempo() {
        cout << "\n=== VUELOS QUE LLEGARON A TIEMPO ===" << endl;
        int contador = 0;
        for (int i = 0; i < totalVuelos; i++) {
            if (listaVuelos[i]->llegoATiempo()) {
                cout << "Vuelo: " << listaVuelos[i]->obtenerCodigo() << endl;
                contador++;
            }
        }
        cout << "Total vuelos a tiempo: " << contador << endl;
    }

    void mostrarVuelosConRetraso() {
        cout << "\n=== VUELOS CON RETRASO ===" << endl;
        int contador = 0;
        for (int i = 0; i < totalVuelos; i++) {
            if (!listaVuelos[i]->llegoATiempo()) {
                cout << "Vuelo: " << listaVuelos[i]->obtenerCodigo()
                    << " - Retraso: " << listaVuelos[i]->calcularRetraso() << " minutos" << endl;
                contador++;
            }
        }
        cout << "Total vuelos con retraso: " << contador << endl;
    }

    void mostrarVueloMayorRetraso() {
        cout << "\n=== VUELO CON MAYOR RETRASO ===" << endl;
        Vuelo* mayorRetraso = nullptr;
        int maxRetraso = -1;

        for (int i = 0; i < totalVuelos; i++) {
            int retraso = listaVuelos[i]->calcularRetraso();
            if (retraso > maxRetraso) {
                maxRetraso = retraso;
                mayorRetraso = listaVuelos[i];
            }
        }

        if (mayorRetraso != nullptr && maxRetraso > 0) {
            cout << "Vuelo: " << mayorRetraso->obtenerCodigo() << endl;
            cout << "Retraso: " << maxRetraso << " minutos" << endl;
        }
        else {
            cout << "No hay vuelos con retraso." << endl;
        }
    }

    void cambiarAsientoPasajero(string ci, string codigoVuelo, string nuevoAsiento) {
        Vuelo* vuelo = buscarVuelo(codigoVuelo);
        if (vuelo == nullptr) {
            throw VueloNoEncontradoException();
        }

        if (vuelo->cambiarAsiento(ci, nuevoAsiento)) {
            cout << "Asiento cambiado exitosamente para el pasajero CI: " << ci << endl;
        }
        else {
            cout << "No se pudo cambiar el asiento. Verifique que el pasajero exista y el asiento este disponible." << endl;
        }
    }

    void buscarPasajeroPorCI(string ci) {
        Pasajero* pasajero = buscarPasajero(ci);
        if (pasajero == nullptr) {
            throw PasajeroNoEncontradoException();
        }

        cout << "\n=== DATOS DEL PASAJERO ===" << endl;
        cout << "Nombre: " << pasajero->obtenerNombreCompleto() << endl;
        cout << "CI: " << pasajero->obtenerCI() << endl;

        Vuelo* vuelo = pasajero->obtenerVuelo();
        if (vuelo != nullptr) {
            cout << "Vuelo asignado: " << vuelo->obtenerCodigo() << endl;
            cout << "Asiento: " << pasajero->obtenerCodigoAsiento() << endl;
        }
        else {
            cout << "No tiene vuelo asignado." << endl;
        }
    }

    void ordenarPasajerosPorApellido(string codigoVuelo) {
        Vuelo* vuelo = buscarVuelo(codigoVuelo);
        if (vuelo == nullptr) {
            throw VueloNoEncontradoException();
        }
        vuelo->ordenarPasajerosPorApellido();
    }

    void mostrarVuelosDePasajero(string ci) {
        Pasajero* pasajero = buscarPasajero(ci);
        if (pasajero == nullptr) {
            throw PasajeroNoEncontradoException();
        }

        cout << "\n=== VUELOS DEL PASAJERO " << pasajero->obtenerNombreCompleto() << " ===" << endl;
        Vuelo* vuelo = pasajero->obtenerVuelo();
        if (vuelo != nullptr) {
            cout << "Vuelo: " << vuelo->obtenerCodigo() << " - Asiento: "
                << pasajero->obtenerCodigoAsiento() << endl;
        }
        else {
            cout << "No tiene vuelos asignados." << endl;
        }
    }

    void mostrarPasajeroConMasVuelos() {
        cout << "\n=== PASAJERO CON MAS VUELOS ===" << endl;
        cout << "En el sistema actual, cada pasajero solo puede tener un vuelo asignado." << endl;

        for (int i = 0; i < totalPasajerosSistema; i++) {
            if (listaPasajeros[i]->obtenerVuelo() != nullptr) {
                cout << "Pasajero: " << listaPasajeros[i]->obtenerNombreCompleto()
                    << " - Vuelo: " << listaPasajeros[i]->obtenerVuelo()->obtenerCodigo() << endl;
            }
        }
    }
};
