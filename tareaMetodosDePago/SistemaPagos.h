#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;

class SistemaPagos {
public:
    Cliente** clientes;
    int cantidadClientes;
    int tamanioMax;

public:
    SistemaPagos(int maxClientes)
        : cantidadClientes(0), tamanioMax(maxClientes) {
        clientes = new Cliente * [maxClientes];
    }

    void agregarCliente(Cliente* nuevoCliente) {
        if (cantidadClientes < tamanioMax) {
            clientes[cantidadClientes] = nuevoCliente;
            cantidadClientes++;
            cout << "Cliente agregado exitosamente" << endl;
        }
        else {
            cout << "Error: No se pueden agregar mas clientes" << endl;
        }
    }

    Cliente* buscarCliente(const string& nombre) {
        for (int i = 0; i < cantidadClientes; i++) {
            if (clientes[i]->nombre == nombre) {
                return clientes[i];
            }
        }
        return nullptr;
    }

    void procesarTodasLasTransacciones() {
        for (int i = 0; i < cantidadClientes; i++) {
            clientes[i]->procesarTodasLasTransacciones();
        }
    }

    void mostrarTodosLosClientes() {
        for (int i = 0; i < cantidadClientes; i++) {
            clientes[i]->mostrarTransacciones();
        }
    }

    float calcularTotalGeneral() {
        float total = 0;
        for (int i = 0; i < cantidadClientes; i++) {
            total += clientes[i]->calcularTotalCliente();
        }
        return total;
    }

    void mostrarTotalGeneral() {
        cout << "---" << endl;
        cout << "TOTAL GENERAL PROCESADO: " << calcularTotalGeneral() << endl;
    }

    ~SistemaPagos() {
        for (int i = 0; i < cantidadClientes; i++) {
            delete clientes[i];
        }
        delete[] clientes;
    }
};