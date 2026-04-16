#pragma once
#include <iostream>
#include <string>
#include "Docente.h"
using namespace std;


class MedioTiempo :public Docente {
public:
	MedioTiempo(string nom,int ci,bool estado,double salario,int cantidadCurso)
	:Docente(nom,ci,estado,salario,cantidadCurso){}

	double calcularBono()override {
		double bono = 0;
		if (cantCursos>= 2) {
			bono = salario * 0.10;
		}
		return salario+bono;
	}

	void mostrard() override {
		cout << "Docente: " << nombre << endl;
		cout << "CiD:" << ciD << endl;
		cout << "Tipo: Medio Tiempo " << endl;
		cout << "Bono:" << calcularBono() << endl;
		if (EstadoActual == true) {
			cout << "Estado actual: Finalizado" << endl;
		}
		else{
			cout << "Estado actual: Ocupado" << endl;
		}
	}

};