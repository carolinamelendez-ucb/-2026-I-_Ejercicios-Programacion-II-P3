#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sala {
private:
	int id;
	int numeroFilas;
	int numeroPorFilas; //columnas
public:


	Sala() = default;

	Sala(int id, int numeroFilas, int numeroPorFilas)
		: id(id), numeroFilas(numeroFilas), numeroPorFilas(numeroPorFilas)
	{
	}
	int getNumeroFilas() {
		return numeroFilas;
	}
	int getNumeroPorfila() {
		return numeroPorFilas;
	}
	int getId() {
		return id;
	}
	
	void mostrar() {
		cout << "Id de Sala: " << id<<endl;
		cout << "Numero de filas de la Sala: " << numeroFilas << endl;
		cout << "Numero de Asientos por Fila: " << numeroPorFilas << endl;
	}
};