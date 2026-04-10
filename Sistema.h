#pragma once
#include "VectorAlquileres.h"
#include "VectorClientes.h"
#include "VectorVehiculos.h"

class Sistema
{
private:
	VectorAlquileres* alquileres;
	VectorClientes* clientes;
	VectorVehiculo* vehiculos;

public:

	Sistema(int tamAlquileres, int tamClientes, int tamVehiculos)
	{
		this->alquileres = new VectorAlquileres(tamAlquileres);
		this->clientes = new VectorClientes(tamClientes);
		this->vehiculos = new VectorVehiculo(tamVehiculos);
	}

	void agregarCliente(Cliente* nuevoCliente)
	{
		clientes->agregar(nuevoCliente);
	}

	void agregarVehiculo(Vehiculo* nuevoVehiculo)
	{
		vehiculos->agregar(nuevoVehiculo);

	}

	void asignar(int ci, string placa, int dias)
	{
		Cliente* cliente = clientes->buscarCliente(ci);
		Vehiculo* vehiculo = vehiculos->buscar(placa);

		if (!cliente || !vehiculo || !vehiculo->getEstaDisponible() || cliente->tieneAlquilerActivo())
		{
			cout<< " Error de asignacion " << endl;
			return;
		}
		Alquiler* alquiler = new Alquiler(cliente, vehiculo, dias);
		alquileres->agregar(alquiler);

		vehiculo->setDisponible(false);
		cliente->setAlquilerActivo(true);
		cliente->agregarVehiculo(vehiculo);
	}

	void desasignar(int ci, string placa)
	{
		Cliente* cliente = clientes->buscarCliente(ci);
		Vehiculo* vehiculo = vehiculos->buscar(placa);

		if (cliente == nullptr)
		{
			cout << "No existe el cliente :" << ci << endl;
			cout << endl;
			return;
		}

		if (vehiculo == nullptr)
		{
			cout << "No existe el vehiculo con placa : " << placa << endl;
			cout << endl;
			return;
		}
		vehiculo->setDisponible(true);

		cout << " Vehiculo desasignado " << endl;
		cout << endl;
	}

	void mostrar()
	{
		alquileres->mostrar();
	}

	
	
};