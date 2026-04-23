#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Libro.h"
#include "Estudiante.h"
using namespace std;


class Biblioteca {
private:
	string nombre;
	Libro** listaLibros;
	Estudiante** listaEstudiantes;
	int tamanioLibro;
	int tamanioEstudiante;
	int cantidadLibro;
	int cantidadEstudiante;
public:
	Biblioteca(string nom, int tamLibros, int tamEstudiantes) {
		this->nombre = nom;
		this->cantidadEstudiante = 0;
		this->cantidadLibro = 0;
		this->tamanioEstudiante = tamEstudiantes;
		this->tamanioLibro = tamLibros;
		this->listaLibros = new Libro * [tamLibros];
		this->listaEstudiantes = new Estudiante * [tamEstudiantes];
	}

	void AgregarLibro(Libro* nvoLibro) {
		if (cantidadLibro < tamanioLibro) {
			listaLibros[cantidadLibro] = nvoLibro;
			cantidadLibro++;
		}
	}

	void AgregarEstudiante(Estudiante* nvoEstudiante) {
		if (cantidadEstudiante < tamanioEstudiante) {
			listaEstudiantes[cantidadEstudiante] = nvoEstudiante;
			cantidadEstudiante++;
		}
	}


	Libro* libroBuscado(int codigoBuscado) {
		for (int i = 0;i < cantidadLibro;i++) {
			if (codigoBuscado==listaLibros[i]->getCodigo()) {
				return listaLibros[i];
			}
		}
		cout << "Codigo NO encontrado" << endl;
	}

	Estudiante* EstuBuscado(int ciBuscado) {
		for (int i = 0;i < cantidadEstudiante;i++) {
			if (ciBuscado == listaEstudiantes[i]->getCi()) {
				return listaEstudiantes[i];
			}
		}
		cout << "Ci NO encontrado" << endl;
	}

};
