#pragma once
#include "VectorEstudiantes.h"
#include "VectorLibros.h"

class Biblioteca {
private:
	VectorEstudiantes* estudiantes;
	VectorLibros* libros;
public:
	Biblioteca(int tamEst, int tamLibr) {
		this->estudiantes = new VectorEstudiantes(tamEst);
		this->libros = new VectorLibros(tamLibr);
	}
	void asignarLibroAEstudiante(int codigo, int ci) {
		estudiantes->estudianteCi(ci)->asignarLibro(libros->libroCodigo(codigo));
		libros->libroCodigo(codigo)->cambiarEstadoAOcupado();
	}
};