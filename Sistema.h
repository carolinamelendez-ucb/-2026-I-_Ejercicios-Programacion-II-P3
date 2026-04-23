#pragma once
#include "VectorEstudiante.h"
#include "VectorLibro.h"

class Sistema {
private:
	VectorEstudiante* listaEstudiantes;
	VectorLibro* listaLibros;
public:
	Sistema(int maxEstudiantes, int maxLibros) {
		this->listaEstudiantes = new VectorEstudiante(maxEstudiantes);
		this->listaLibros = new VectorLibro(maxLibros);
	}
	void registrarEstudiante(Estudiante* newEstudiante) {
		int estudianteCI = newEstudiante->getCI;
	}
};
