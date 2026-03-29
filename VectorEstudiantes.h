#pragma once
#include "Estudiante.h"

class VectorEstudiantes{
	private:
	Estudiante** estudiantes;
	int indice;
	int tamanio;
	public:

	VectorEstudiantes (int tamanio)
		: indice (0), tamanio (tamanio)
	{
		this->estudiantes = new Estudiante * [tamanio];
	}

	void registrarEstudiante (Estudiante* nuevoEstudiante){
		if(indice < tamanio){
			estudiantes[indice] = nuevoEstudiante;
			indice++;
		}
	}

	void mostrar (){
		for(int i = 0; i < indice; i++){
			estudiantes[i]->mostrar ();
		}
	}

	Estudiante* verificarCiDuplicado (int ci){
		for(int i = 0; i < indice; i++){
			if(estudiantes[i]->getCi () == ci){
				return estudiantes[i];
			}
		}
		return nullptr;
	}

	Estudiante* buscarEstudiantePorCi (int ci){
		for(int i = 0; i < indice; i++){
			if(estudiantes[i]->getCi () == ci){
				return estudiantes[i];
			}
		}
		return nullptr;
	}

	void mostrarEstudiantesCon5Prestamos (){
		for(int i = 0; i < indice; i++){
			if(estudiantes[i]->getCantidadPrestamosActivos () == 5){
				estudiantes[i]->mostrar ();
			}
		}
	}
};