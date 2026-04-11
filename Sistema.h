#pragma once
#include <iostream>
#include <string>
#include "VectorVehiculo.h"
#include "VectorCliente.h"
#include "VectorAlquileres.h"
using namespace std;

class Sistema {
private:
	VectorAlquileres* alquileres;
	VectorCliente* clientes;
	VectorVehiculo* vehiculos;
public:

	Sistema(int tamAlquileres, int tamClientes, int tamVehiculos)
	{
		this->alquileres = new VectorAlquileres(tamAlquileres);
		this->clientes = new VectorCliente(tamClientes);
		this->vehiculos = new VectorVehiculo(tamVehiculos);
	}

	void agregarCliente(Cliente* nueClientes) {
		clientes->agregar(nueClientes);
	}

	void agregarVehiculo(Vehiculo* nueVehiculos) {
		vehiculos->agregar(nueVehiculos);
	}

	void asignar(int ci, string placa, int dias) {
		Cliente* cliente = clientes->buscar(ci);
		Vehiculo* vehiculo = vehiculos->buscar(placa);
		if (!cliente || !vehiculo || !vehiculo->estaDisponible() || cliente->tieneAlquilerActivo()) {
			cout << "Error de Asignacion" << endl;
			return;
		}
		Alquiler* alquiler = new Alquiler(cliente, vehiculo, dias);
		alquileres->agregar(alquiler);
		vehiculo->setDisponible(false);
		cliente->setAlquilerActivo(true);
		cliente->agregarVehiculo(vehiculo);
	}

	void desasignar(int ci, string placa) {
		Cliente* cliente = clientes->buscar(ci);
		Vehiculo* vehiculo = vehiculos->buscar(placa);
		if (cliente == nullptr) {
			cout << "No existe el cliente: " << ci << endl;
			cout << endl;
			return;
		}
		if (vehiculo == nullptr) {
			cout << "No existe el vehiculo con placa ingresada: " << placa << endl;
			cout << endl;
			return;
		}
		vehiculo->setDisponible(true);
		cliente->setAlquilerActivo(false);
		cout << "Vehiculo desasignado" << endl;
		cout << endl;
	}

	void mostrar() {
		alquileres->mostrar();
	}

};