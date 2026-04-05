#pragma once
#include <iostream>
#include <string>
#include "VectorTransporte.h"
#include "VectorOperador.h"
using namespace std;
class Sistema {
private:
	VectorOperador * listaOperadores;
	VectorTransporte * listaTransportes;
public:
	Sistema(int tamanioOperador, int tamanioTransporte) {
		this->listaOperadores = new VectorOperador(tamanioOperador);
		this->listaTransportes= new VectorTransporte(tamanioTransporte);
	}

	//1
	void registrarMediosTransporte(Transporte * nuevoTransporte) {
		
		if (listaTransportes->existeTransporte(nuevoTransporte) != nullptr) {
			cout << "Placa duplicada, no se puedo registra uno de los trasnportes" << endl;
			return;
		}
		listaTransportes->agregar(nuevoTransporte);
	}

	//2
	void registrarOperadores(Operador * nuevoOperador) {
		if (listaOperadores->existeOperador(nuevoOperador) != nullptr) {
			cout << "ci duplicado, no se puedo registra uno de los operadores" << endl;
			return;
		}
		listaOperadores->agregar(nuevoOperador);
	}

	//3

	void asignarTransporteOperador(int ci, Transporte * transporte) {
		Operador* auxOperador= listaOperadores->buscarCi(ci);
		if (auxOperador == nullptr) {
			cout << "Operador no encontrado, error!" << endl;
			return;
		}
		auxOperador->asignarTransporte(transporte);
	}
	//4
	void calcularCostoOperador(int ci) {
		Operador* auxOperador = listaOperadores->buscarCi(ci);
		if (auxOperador == nullptr) {
			cout << "Operador no encontrado, error!" << endl;
			return;
		}
		cout << "Costo generado del Operador "<<auxOperador->getCi()<<": "
			<< auxOperador->calcularCostoGenerado() << endl;
		
	}

	//5
	void calcularCostoGeneral() {
		cout << "Costo General es: " << listaOperadores->CostoGeneral() << endl;
	}
	//6
	void mostrarOperadorMenor() {
		listaOperadores->buscarMenor()->mostrar();
	}
};
