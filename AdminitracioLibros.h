#pragma once
#include <iostream>
#include <string>
#include "VectorEstudiante.h"
#include "VectorLibro.h"
#include "VectorPrestamo.h"
using namespace std;
class AdminitracionLibros {
private: 
	VectorEstudiante * listaEstudiantes;
	VectorLibro * listaLibros;
	VectorPrestamo * listaPrestamos;
public:
	AdminitracionLibros(int tamanoEstudiante, int tamanoLibro, int tamanoPrestamo) {
		listaEstudiantes = new VectorEstudiante(tamanoEstudiante);
		listaLibros = new VectorLibro(tamanoLibro);
		listaPrestamos = new VectorPrestamo(tamanoPrestamo);
	}

	//1
	void registrarEstudiantes(int ci, string nombre) {
		Estudiante* nuevoEstudiante = new Estudiante(ci, nombre);

		if (!listaEstudiantes->BuscarEstudiante(ci)) {
			listaEstudiantes->agregar(nuevoEstudiante);
		}
		else {
			cout << "Ci de un estudiante ya se encuentra en sistema!, no se aplico registro" << endl;
		}
	}
	void mostrarEstudiantes() {
		listaEstudiantes->mostrar();
	}
	//2
	void registrarLibros(int codigo, string titulo) {
		Libro* nuevoLibro = new Libro(codigo, titulo);

		if (!listaLibros->BuscarLibro(codigo)) {
			listaLibros->agregar(nuevoLibro);
		}
		else {
			cout << "Codigo de un libro ya se encuentra en sistema!, no se palico registro" << endl;
		}
	}
	void mostrarLibros() {
		listaLibros->mostrar();
	}

	//3
	void prestarLibro(int ciEstudiante, int codigoLibro) {

		Estudiante* auxEstudiante = listaEstudiantes->getEstudiante(ciEstudiante);
		Libro* auxLibro = listaLibros->getLibro(codigoLibro);


		if (auxEstudiante == nullptr || auxLibro == nullptr) {
			cout << "Estudinate o libro no encontrado,error!" << endl;
			return;
		}
		if (auxEstudiante->getCantidadLibrosPrestadosActivos() < 5 && auxLibro->getDisponible() == true) {
			Prestamo* nuevoPrestamo = new Prestamo(ciEstudiante, codigoLibro);
			listaPrestamos->agregar(nuevoPrestamo);
			auxEstudiante->aumentarCantidadLibrosPrestadosActivos();
			auxLibro->estadoNiDisponible();
		}
		else {
			cout << "No se pudo realizar prestamos, error!" << endl;
		}
	}
	//4

	void devolverLibro(int ciEstudiante, int codigoLibro) {

		Estudiante* auxEstudiante = listaEstudiantes->getEstudiante(ciEstudiante);
		Libro* auxLibro = listaLibros->getLibro(codigoLibro);


		if (auxEstudiante == nullptr || auxLibro == nullptr) {
			cout << "Estudinate o libro no encontrado,error!" << endl;
			return;
		}
		Prestamo* auxPrestamo = listaPrestamos->getPrestamo(ciEstudiante, codigoLibro);

		if (auxPrestamo == nullptr || auxPrestamo->getEstado()==false) {
			cout << "Prestamo no encontrado o libro no prestado,error!" << endl;
			return;
		}
			auxEstudiante->reducirCantidadLibrosPrestadosActivos();
			auxLibro->estadoDisponible();
			auxPrestamo->setestado(false);
		
	}

	//5
	void mostrarEstudiantes5Prestamos() {
		listaEstudiantes->buscarEstudiantes5prestamos();
	}

	//6

	void mostrarPrestamos() {
		listaPrestamos->mostrar();
	}

	~AdminitracionLibros() {
		delete listaEstudiantes;
		delete listaLibros;
		delete listaPrestamos;
	}

};