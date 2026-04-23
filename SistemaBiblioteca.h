#pragma once
#include "VectorEstudiantes.h"
#include "VectorLibros.h"
class SistemaBiblioteca
{
private:
	VectorEstudiantes* listaEstudiantes;
	VectorLibros* listaLibros;
public:
	SistemaBiblioteca(int tamEst, int tamLib)
	{
		this->listaEstudiantes = new VectorEstudiantes(tamEst);
		this->listaLibros = new VectorLibros(tamLib);
	}
	void registrarPrestamo(int ci, int codigo)
	{

	}
};

