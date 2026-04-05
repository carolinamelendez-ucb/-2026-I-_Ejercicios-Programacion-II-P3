#pragma once
#include <iostream>
#include<string>
#include"VectorOperadores.h"
#include"VectorTransporte.h"
class Sistema {
private:
	VectorTransporte transportes;
	VectorOperador Operadores;
public:
	Sistema(int t,int o)
		: transportes(t), Operadores(o)
	{
	}
	void registrarTransporte(Transporte* t) {
		transportes.Agregar(t);
	}
	void registrarOperador(Operador* o) {
		Operadores.Agregar(o);
	}
	void asignar(int ci, string placa, float distancia) {
		Operador* op = Operadores.buscar(ci);
		Transporte* tr = transportes.buscar(placa);

		if (op == nullptr) {
			cout << "Operador no encontrado\n";
			return;
		}
		if (tr == nullptr) {
			cout << "Transporte no encontrado\n";
			return;
		}
		op->asignarTransporte(tr, distancia);
	}

	void mostrarTodo() {
		Operadores.mostrarTodo();
	}
	void totalDelSistema() {
		cout << "Total de costos: " << Operadores.totalDecostos()<<endl;
	}
	void menorCosto() {
		Operador* op = Operadores.menorCosto();
		if (op != nullptr) {
			cout << "EL menor costo es: " << endl;
			op->mostrar();
		}
	}
};