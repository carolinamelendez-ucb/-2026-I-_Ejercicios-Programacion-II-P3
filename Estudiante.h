#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Resultado.h"
using namespace std;

class Estudiante {
private:
	string matricula;
	string nombre;
	string correo;
	LinkedList<Resultado>* resultados;

public:
	Estudiante(const string& matricula, const string& nombre, const string& correo)
		: matricula(matricula), nombre(nombre), correo(correo)
	{
		this->resultados = new LinkedList<Resultado>();
	}

	void agregarResultado(Resultado* nuevoResultado) {
		resultados->agregar(nuevoResultado);
	}

	Resultado* buscarResultado(int idExamen) {
		return resultados->buscar(idExamen, Resultado::compararExamen);
	}

	int contarResultadosFinalizados() {
		return resultados->contarCriterio(true, esFinalizado);
	}

	string getMatricula() {
		return matricula;
	}
	string getNombre() {
		return nombre;
	}
	string getCorreo() {
		return correo;
	}
	LinkedList<Resultado>* getResultados() {
		return resultados;
	}

	static bool compararMatricula(string matricula, Estudiante* estudianteComparado) {
		return matricula == estudianteComparado->matricula;
	}

	static bool esFinalizado(bool valor, Resultado* resultadoComparado) {
		return (resultadoComparado->getEstado() != "EN_CURSO") == valor;
	}
	static bool finalizoExamen(int idExamen, Estudiante* estudianteComparado) {
		Resultado* r = estudianteComparado->buscarResultado(idExamen);
		return r != nullptr && r->getEstado() != "EN_CURSO";
	}
	static bool aproboExamen(int idExamen, Estudiante* estudianteComparado) {
		Resultado* r = estudianteComparado->buscarResultado(idExamen);
		return r != nullptr && r->getEstado() == "APROBADO";
	}
};