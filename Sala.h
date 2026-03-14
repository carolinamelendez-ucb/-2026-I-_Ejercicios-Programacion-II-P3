#pragma once
#include <iostream>
#include <string>
using namespace std; 

class Sala {
private:
	int Nro;
	int NroDeFilas;
	int asientoPorFilas;
public:
	Sala(int Nro, int NroDeFilas, int asientosPorFilas) {
		this->Nro = Nro;
		this->NroDeFilas = NroDeFilas;
		this->asientoPorFilas = asientosPorFilas;
	}
	void mostrar() {
		cout << "Nro. de Sala: " << Nro << endl;
		cout << "Nro de filas: " << NroDeFilas << endl;
		cout << "Asientos por fila: " << asientoPorFilas << endl;
	}
};
