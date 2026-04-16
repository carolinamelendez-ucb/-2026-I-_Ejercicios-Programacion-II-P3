#pragma once
#include <iostream>
#include <string>
#include "Docente.h"
using namespace std;

class TiempoCom :public Docente {
private:
	int cantAnios;
public:
	TiempoCom(string nom, int ci, bool estado, double salario, int cantCurso,int anios)
		:Docente(nom, ci, estado,salario,cantCurso),cantAnios(anios){
	}

	double calcularBono()override {
		double bonoPorcentaje = 0;
		if (cantAnios>=0 && cantAnios<=5) {
			bonoPorcentaje = 0.05;
		}
		else {
			if (cantAnios>=6 && cantAnios <=10) {
				bonoPorcentaje = 0.15;
			}
			else {
				if (cantAnios>10) {
					bonoPorcentaje = 0.25;
				}
			}
		}
		return salario * (1+bonoPorcentaje);
	}

	void mostrard() override {
		cout << "Docente: " << nombre << endl;
		cout << "CiD:" << ciD << endl;
		cout << "Tipo: Tiempo Completo"<< endl;
		cout << "Bono:" << calcularBono() << endl;
		if (EstadoActual == true) {
			cout << "Estado actual: Finalizado" << endl;
		}
		else {
			cout << "Estado actual: Ocupado" << endl;
		}
	}


};