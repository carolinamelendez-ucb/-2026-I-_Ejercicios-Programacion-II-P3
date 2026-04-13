#pragma once
#include "Docente.h"
#include "VectorEstudiantes.h"

class Curso {
private:
	int codigo;
	int maxEstudiantes;
	Docente* docenteAsignado;
	VectorEstudiantes* listaEstudiantes;
public:
	Curso(int codigo, int maxEstudiantes) {
		this->codigo = codigo;
		this->maxEstudiantes = maxEstudiantes;
		this->docenteAsignado = nullptr;
		this->listaEstudiantes = new VectorEstudiantes(maxEstudiantes);
	}
	int getCodigo() {
		return codigo;
	}
	bool asignarDocente(Docente* docente) {
		if (!docente->estaAprobado()) {
			return false;
		}
		else {
			docenteAsignado = docente;
			return true;
		}
	}
	bool agregarEstudiante(Estudiante* newEstudiante) {
		if (!newEstudiante->pagoRealizado()) {
			return false;
		}
		if (listaEstudiantes->getIndice() >= maxEstudiantes) {
			return false;
		}
		if (listaEstudiantes->buscarCi(newEstudiante->getCI()) != nullptr) {
			return false;
		}
		listaEstudiantes->agregar(newEstudiante);
		return true;
	}
	VectorEstudiantes* getEstudiantes() {
		return listaEstudiantes;
	}
};
