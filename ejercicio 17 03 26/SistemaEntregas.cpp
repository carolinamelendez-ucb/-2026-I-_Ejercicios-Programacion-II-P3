#include "SistemaEntregas.h"

#include <iostream>
#include <string>

using namespace std;

bool SistemaEntregas::registrarRepartidor(string nombre, int id) {
    if (repartidores.buscarPorId(id) != 0) {
        cout << "Error: Ya existe un repartidor con el Id " << id << endl;
        return false;
    }

    Repartidor nuevoRepartidor(nombre, id);
    repartidores.agregar(nuevoRepartidor);
    cout << "Repartidor registrado exitosamente: " << nombre << " (Id: " << id << ")" << endl;
    return true;
}

bool SistemaEntregas::registrarEntrega(int id, string direccion) {
    if (entregas.buscarPorId(id) != 0) {
        cout << "Error: Ya existe una entrega con el Id " << id << endl;
        return false;
    }

    Repartidor* repartidorLibre = repartidores.buscarLibre();

    if (repartidorLibre == 0) {
        cout << "Error: No hay repartidores libres disponibles" << endl;
        return false;
    }

    Entrega nuevaEntrega(id, direccion);
    nuevaEntrega.repartidorAsignado = repartidorLibre;
    repartidorLibre->estado = "ocupado";

    entregas.agregar(nuevaEntrega);
    cout << "Entrega registrada exitosamente. ID: " << id << ", Direccion: " << direccion
        << ", Repartidor asignado: " << repartidorLibre->nombre << " (Id: " << repartidorLibre->id << ")" << endl;
    return true;
}

void SistemaEntregas::mostrarRepartidoresOrdenados() {
    if (repartidores.getCantidad() == 0) {
        cout << "No hay repartidores registrados" << endl;
        return;
    }

    // Ordenar una copia para no modificar el original
    VectorRepartidores copia;
    for (int i = 0; i < repartidores.getCantidad(); i++) {
        Repartidor* r = repartidores.obtener(i);
        if (r != 0) {
            copia.agregar(*r);
        }
    }

    copia.ordenarPorEntregas();

    cout << "\n--- Repartidores Ordenados Por Entregas (Ascendentemente) ---" << endl;
    for (int i = 0; i < copia.getCantidad(); i++) {
        Repartidor* r = copia.obtener(i);
        if (r != 0) {
            cout << "Nombre: " << r->nombre
                << ", Id: " << r->id
                << ", Entregas: " << r->entregasRealizadas
                << ", Estado: " << r->estado << endl;
        }
    }
    cout << "----------------------------------------------------\n" << endl;
}

bool SistemaEntregas::aumentarPaquetesEntrega(int idEntrega, int cantidad) {
    Entrega* entrega = entregas.buscarPorId(idEntrega);

    if (entrega == 0) {
        cout << "Error: No se encontro una entrega con el Id " << idEntrega << endl;
        return false;
    }

    if (entrega->estado == "finalizada") {
        cout << "Error: La entrega con Id " << idEntrega << " ya esta finalizada" << endl;
        return false;
    }

    entrega->cantidadPaquetes += cantidad;
    cout << "Se agregaron " << cantidad << " paquetes a la entrega Id " << idEntrega
        << ". Total actual: " << entrega->cantidadPaquetes << endl;
    return true;
}

bool SistemaEntregas::finalizarEntrega(int idEntrega) {
    Entrega* entrega = entregas.buscarPorId(idEntrega);

    if (entrega == 0) {
        cout << "Error: No se encontro una entrega con el Id " << idEntrega << endl;
        return false;
    }

    if (entrega->estado == "finalizada") {
        cout << "Error: La entrega con Id " << idEntrega << " ya esta finalizada" << endl;
        return false;
    }

    Repartidor* repartidor = entrega->repartidorAsignado;

    if (repartidor != 0) {
        repartidor->estado = "libre";
        repartidor->entregasRealizadas++;
    }

    entrega->estado = "finalizada";

    cout << "Entrega Id " << idEntrega << " finalizada exitosamente." << endl;
    cout << "Repartidor " << repartidor->nombre << " ahora esta libre y ha realizado "
        << repartidor->entregasRealizadas << " entregas." << endl;
    return true;
}

void SistemaEntregas::mostrarRepartidorMenorEntregas() {
    Repartidor* menor = repartidores.obtenerMenorEntregas();

    if (menor == 0) {
        cout << "No hay repartidores registrados" << endl;
        return;
    }

    cout << "\n--- Repartidor Con Menor Cantidad De Entregas ---" << endl;
    cout << "Nombre: " << menor->nombre
        << ", Id: " << menor->id
        << ", Entregas: " << menor->entregasRealizadas
        << ", Estado: " << menor->estado << endl;
    cout << "------------------------------------------------\n" << endl;
}