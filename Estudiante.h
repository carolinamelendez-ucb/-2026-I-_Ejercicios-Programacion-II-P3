#pragma once
#include "LinkedList.h"
#include "Resultado.h"


class Estudiante {
private:
	int matricula;
	string nombre;
	int edad;
	string correo;
	LinkedList<Resultado>* resultados;
public:
	Estudiante(int matricula, const string& nombre,int edad ,const string& correo)
		: matricula(matricula), nombre(nombre),edad(edad), correo(correo)
	{
		this->resultados = new LinkedList<Resultado>();
	}
	
	int getMatricula(){
		return matricula;
	}

	static bool compararMAT(int cod,Estudiante* es) {
		return cod == es->matricula;
	}

	static bool ordenarEdadDes(Estudiante* a, Estudiante* b) {
		return a->edad > b->edad;
	}

	static bool ordenarEdadAsc(Estudiante* a, Estudiante* b) {
		return a->edad < b->edad;
	}

	void mostrar() {
		cout << "Matricula:"<<matricula << endl;
		cout << "Nombre:"<<nombre << endl;
		cout << "Edad:" << edad << endl;
		cout << "Correo:"<<correo << endl;
		cout << endl;
	}

	~Estudiante(){}

};