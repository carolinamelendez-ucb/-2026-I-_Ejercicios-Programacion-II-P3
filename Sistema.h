#pragma once
#include "VectorEstudiante.h"

class Sistema {
private:
	VectorEstudiante* listaEstudiantes;
public:
	Sistema(int maxEstudiantes) {
		this->listaEstudiantes = VectorEstudiante(maxEstudiantes);
	}
};
