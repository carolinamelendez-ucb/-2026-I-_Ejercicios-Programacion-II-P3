#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;


class Pregrado : public Estudiante {
public:
	Pregrado(string nombre,int ci)
	:Estudiante(nombre,ci,1200,true){}

	double calcularmat() override {
		return costoMat;
	}

	void mostrar()override {
		cout<<"Cliente:"<<nombre<< endl;
		cout<<"CI:"<<ci<< endl;
		cout<<"Calculo total:"<<calcularmat()<< endl;
	}
};