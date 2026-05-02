#pragma once
#include "ArrayGenerico.h"
#include "Espacio.h"
#include "Vehiculo.h"
#include "CodigoVehiculoDuplicadoException.h"
#include "VehiculoNoEncontradoException.h"
#include "CodigoEspacioDupliadoException.h"
#include "NoHayEspacioDisponibleException.h"
#include "VehiculoYaAsigandoException.h"

class SistemaParqueo {
private:
	string nombreEmpresa;
	string direccion;
	int capacidadMaxima;
	ArrayGenerico<Espacio>* listaEspacios;
	ArrayGenerico<Vehiculo>* listaVehiculos;
public:

	SistemaParqueo(const string& nombreEmpresa, const string& direccion, int capacidadMaxima)
		: nombreEmpresa(nombreEmpresa), direccion(direccion), capacidadMaxima(capacidadMaxima)
	{
		this->listaEspacios = new ArrayGenerico<Espacio>(capacidadMaxima);
		this->listaVehiculos = new ArrayGenerico<Vehiculo>(capacidadMaxima);
	}

	void registrarEspacio(Espacio * nuevoEspacio) {
		string codigo = nuevoEspacio->getCodigo();
		Espacio* espacioExiste = listaEspacios->buscar(codigo, Espacio::compararCodigo);
		try {
			if (espacioExiste != nullptr) {
				throw CodigoEspacioDuplicadoException();
			}
			listaEspacios->agregar(nuevoEspacio);
		}
		catch (exception &err) {
			cout << "Error: " << err.what() << endl;
		}

	}

	void registrarVehiculo(Vehiculo* nuevoVehiculo) {
		string placa = nuevoVehiculo->getPlaca();
		Vehiculo* vehiculoExiste = listaVehiculos->buscar(placa, Vehiculo::compararPlaca);
		try {
			if (vehiculoExiste != nullptr) {
				throw CodigoVehiculoDuplicadoException();
			}
			listaVehiculos->agregar(nuevoVehiculo);
		}
		catch (exception& err) {
			cout << "Error: " << err.what() << endl;
		}
	}
	void asignarEspacioAVehiculo(string placa) {
		Vehiculo* vehiculoExiste = listaVehiculos->buscar(placa, Vehiculo::compararPlaca);
		try {
			if (vehiculoExiste == nullptr) {
				throw VehiculoNoEncontradoException();
			}
			bool estado = true;
			Espacio* espacioDisponible = listaEspacios->buscar(estado, Espacio::compararDisponibilidad);
			if (espacioDisponible == nullptr) {
				throw NoHayEspacioDisponibleException();
			}
			if (vehiculoExiste->VehiculoYaEstaAsignado()) {
				throw VehiculoYaAsigandoException();
			}

			vehiculoExiste->AsignarEspacioAVehiculo(espacioDisponible);
			espacioDisponible->estaOcupado();
		}
		catch (exception& err) {
			cout << "Error: " << err.what() << endl;
		}
	}

	void buscarVehiculo(string placa) {
		Vehiculo* vehiculoExiste = listaVehiculos->buscar(placa, Vehiculo::compararPlaca);
		try {
			if (vehiculoExiste == nullptr) {
				throw VehiculoNoEncontradoException();
			}
			vehiculoExiste->mostrar();
		}
		catch (exception& err) {
			cout << "Error: " << err.what() << endl;
		}
	}
	void ordenarPorMarca() {
		listaVehiculos->ordenar(Vehiculo::ordenarPorMarca);
	}
	void mostrarVehiculos() {
		listaVehiculos->mostrar();
	}

	void mostrarEspaciosDisponibles() {
		bool estado = true;
		listaEspacios->mostrar(estado, Espacio::compararDisponibilidad);
	}

	void  mostrarVehiculosEstacionados() {
		bool tieneEspacio = true; 
		listaVehiculos->mostrar(tieneEspacio, Vehiculo::compararTieneEspacio);
	}
	~SistemaParqueo() {
		delete listaVehiculos;
		delete listaEspacios;
	}
};