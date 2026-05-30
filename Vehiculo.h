#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
private:
	int matricula;
	string marca;
	int UnidadesEnergia;
	int nivelDeAceleracion;
public:
	Vehiculo(int matricula, const string& marca, int UnidadesEnergia, int nivelDeAceleracion)
		: matricula(matricula), marca(marca), UnidadesEnergia(UnidadesEnergia), nivelDeAceleracion(nivelDeAceleracion)
	{}

	static bool compararMATRICULA(int matricula, Vehiculo* v) {
		return matricula == v->matricula;
	}

	int getMatricula() {
		return matricula;
	}

	int getUnidadesEnergia() {
		return UnidadesEnergia;
	}

	int getNivelAceleracion() {
		return nivelDeAceleracion;
	}

	void disminuir(){
		 UnidadesEnergia -= nivelDeAceleracion;
	}

	static bool energiaMenor(Vehiculo* v) {
		return v->UnidadesEnergia < 50;
	}


	void mostrar() {
		cout << "Matricula:"<< matricula << endl;
		cout << "Marca:"<< marca << endl;
		cout << "Unidades de Energia:"<< UnidadesEnergia << endl;
		cout << "Niveles de aceleracion:"<< nivelDeAceleracion << endl;
	}


};