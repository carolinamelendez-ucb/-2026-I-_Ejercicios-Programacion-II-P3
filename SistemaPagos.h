#pragma once
#include "VectorClientes.h"

class SistemaPagos {

private:
    VectorClientes* clientes;

public:

    SistemaPagos(int tamanio) {
        clientes = new VectorClientes(tamanio);
    }

    ~SistemaPagos() {
        delete clientes;
    }

    void registrarCliente(Cliente* clienteNuevo) {
        clientes->agregar(clienteNuevo);
    }

    void mostrarTodo() {
        clientes->mostrar();
        cout << "----------------------------------" << endl;
        cout << "TOTAL GENERAL PROCESADO: " << clientes->totalGeneral() << endl;
    }
};
