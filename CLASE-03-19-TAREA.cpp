// CLASE-03-19-TAREA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "VectorEstudiantes.h"
#include "VectorLibros.h"
#include "VectorPrestamos.h"
#include <iostream>
using namespace std;

class SistemaBiblioteca{
	private:
	VectorEstudiantes* listaEstudiantes;
	VectorLibros* listaLibros;
	VectorPrestamos* listaPrestamos;
	public:
	SistemaBiblioteca (int tamanioEstudiantes, int tamanioLibros, int tamanioPrestamos){
		this->listaEstudiantes = new VectorEstudiantes (tamanioEstudiantes);
		this->listaLibros = new VectorLibros (tamanioLibros);
		this->listaPrestamos = new VectorPrestamos (tamanioPrestamos);
	}

	void registrarEstudiante (Estudiante* nuevoEstudiante){
		Estudiante* aux = listaEstudiantes->verificarCiDuplicado (nuevoEstudiante->getCi ());
		if(aux == nullptr){
			listaEstudiantes->registrarEstudiante (nuevoEstudiante);
		}
	}

	void registrarLibro (Libro* nuevoLibro){
		Libro* aux = listaLibros->verificarCodigoDuplicado (nuevoLibro->getCodigo ());
		if(aux == nullptr){
			listaLibros->registrarLibro (nuevoLibro);
		}
	}

	void prestarLibro (int ciEstudiante, int codigoLibro, bool estado){
		Estudiante* estudiante = listaEstudiantes->buscarEstudiantePorCi (ciEstudiante);
		Libro* libro = listaLibros->buscarLibroPorCodigo (codigoLibro);

		if(estudiante != nullptr && libro != nullptr){
			if(libro->getEstado () == true && estudiante->verificarLimitePrestamos () == true){
				Prestamo* nuevoPrestamo = new Prestamo (ciEstudiante, codigoLibro, estado);
				nuevoPrestamo->asignarEstudianteYLibro (estudiante, libro);
				listaPrestamos->registrarPrestamo (nuevoPrestamo);
			}
		}
	}

	void devolverLibro (int ciEstudiante, int codigoLibro){
		Prestamo* prestamo = listaPrestamos->buscarPrestamoActivo (ciEstudiante, codigoLibro);
		if(prestamo != nullptr){
			prestamo->devolverLibro ();
		}
	}

	void mostrarEstudiantes (){
		listaEstudiantes->mostrar ();
	}

	void mostrarLibros (){
		listaLibros->mostrar ();
	}

	void mostrarPrestamos (){
		listaPrestamos->mostrar ();
	}

	void mostrarEstudiantesCon5Prestamos (){
		listaEstudiantes->mostrarEstudiantesCon5Prestamos ();
	}
};

int main ()
{
	SistemaBiblioteca sistema (10, 10, 20);

	//1
	sistema.registrarEstudiante (new Estudiante (101, "Ana"));
	sistema.registrarEstudiante (new Estudiante (102, "Luis"));
	sistema.registrarEstudiante (new Estudiante (103, "Carlos"));
	sistema.registrarEstudiante (new Estudiante (101, "Pedro"));

	cout << "\n--- ESTUDIANTES REGISTRADOS ---\n";
	sistema.mostrarEstudiantes ();

	//2
	sistema.registrarLibro (new Libro ("Cien anios de soledad", 1));
	sistema.registrarLibro (new Libro ("Don Quijote", 2));
	sistema.registrarLibro (new Libro ("La Odisea", 3));
	sistema.registrarLibro (new Libro ("Hamlet", 4));
	sistema.registrarLibro (new Libro ("El Principito", 5));
	sistema.registrarLibro (new Libro ("Rayuela", 1));

	cout << "\n--- LIBROS REGISTRADOS ---\n";
	sistema.mostrarLibros ();

	//3
	sistema.prestarLibro (101, 1, true);
	sistema.prestarLibro (101, 2, true);
	sistema.prestarLibro (101, 3, true);
	sistema.prestarLibro (101, 4, true);
	sistema.prestarLibro (101, 5, true);

	cout << "\n--- PRESTAMOS REGISTRADOS ---\n";
	sistema.mostrarPrestamos ();

	//4
	sistema.devolverLibro (101, 3);

	cout << "\n--- PRESTAMOS ACTUALIZADOS ---\n";
	sistema.mostrarPrestamos ();

	cout << "\n--- LIBROS ACTUALIZADOS ---\n";
	sistema.mostrarLibros ();

	cout << "\n--- ESTUDIANTES ACTUALIZADOS ---\n";
	sistema.mostrarEstudiantes ();

	//5
	cout << "\n--- ESTUDIANTES CON 5 PRESTAMOS ACTIVOS ---\n";
	sistema.mostrarEstudiantesCon5Prestamos ();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
