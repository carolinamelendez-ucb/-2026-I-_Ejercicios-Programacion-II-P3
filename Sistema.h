#pragma once
#include "LinkedList.h"
#include "Vehiculo.h"
#include "Excepciones.h"


class Sistema {
private:
	string nombre;
	LinkedList<Vehiculo>* listaVehiculos;
public:
	Sistema(string nom) {
		this->nombre = nom;
		listaVehiculos = new LinkedList<Vehiculo>();
	}

	void registrarVehiculo(Vehiculo* nvoVehiculo) {
		Vehiculo* vehi = listaVehiculos->buscar(nvoVehiculo->getMatricula(), Vehiculo::compararMATRICULA);
		if (vehi!=nullptr) {
			throw VehiculoDuplicadoException(nvoVehiculo->getMatricula()); 
		}

		if (nvoVehiculo->getUnidadesEnergia() <= 0) {
			throw EnergiaMenorException(nvoVehiculo->getUnidadesEnergia());
		}

		listaVehiculos->agregar(nvoVehiculo);
	}

	void mostrarVehiculo() {
		listaVehiculos->mostrar();
		cout << endl;
		listaVehiculos->contador();
	}
	
	void Disminuir(int matricula) {
		Vehiculo* vehi = listaVehiculos->buscar(matricula,Vehiculo::compararMATRICULA);
		if (vehi==nullptr) {
			throw VehiculoNoEncontradoException(matricula);
		}
		vehi->disminuir();
	}

	void buscarPlaca(int matricula) {
		Vehiculo* vehi = listaVehiculos->buscar(matricula, Vehiculo::compararMATRICULA);
		if (vehi==nullptr) {
			throw VehiculoNoEncontradoException(matricula);
		}
		listaVehiculos->mostrar();
	}

	void VehiculosMenorEnergia() {
		cout << "Cantidad de vehiculos:"<<listaVehiculos->contarCondicion2(Vehiculo::energiaMenor);
	}



};