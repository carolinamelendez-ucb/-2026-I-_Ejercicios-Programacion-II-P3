#include <iostream>
#include <string>
#include "Plataforma.h"
#include "Utils.h"
#include "PreguntaOpcionMultiple.h"
#include "PreguntaVerdaderoFalso.h"
using namespace std;

// 1

void printTestHeader(int numero, const string& nombreTest) {
	cout << "\n===== TEST " << numero << ": " << nombreTest << " =====" << endl;
}


void testRegistrarEstudiante() {
	printTestHeader(1, "testRegistrarEstudiante");

	Plataforma* plataformaEvalucacion = new Plataforma("Doma");
	try {


		Estudiante* estudianteFabian = new Estudiante(1111, "Fabian",20,"Fabi@correo.com");
		Estudiante* estudianteJulian = new Estudiante(2222, "Julian",26,"Juli@correo.com");
		Estudiante* estudianteIvan = new Estudiante(3333, "Ivan",25,"Iv@correo.com");
		Estudiante* estudianteStefanny = new Estudiante(4444, "Stefanny",21,"Tefy@correo.com");
		Estudiante* estudianteNicole = new Estudiante(5555, "Nicole",19,"Niki@correo.com");

		

		plataformaEvalucacion->registrarEstudiante(estudianteFabian);
		plataformaEvalucacion->registrarEstudiante(estudianteJulian);
		plataformaEvalucacion->registrarEstudiante(estudianteIvan);
		plataformaEvalucacion->registrarEstudiante(estudianteStefanny);
		plataformaEvalucacion->registrarEstudiante(estudianteNicole);



		plataformaEvalucacion->mostrarEstudiantes();

	}
	catch (EstudianteDuplicadoException& e) {
		cout << "Error:" << e.what() << endl;
	}
}

// 2

void testRegistrarExamen() {
	
	printTestHeader(2,"testRegistrarExamen");

	Plataforma* plataformaEvalucacion = new Plataforma("Doma");

	try {

		Examen* examenProgramacion = new Examen(1, "Programacion II", "Carolina", 90);
		Examen* examenCalculo = new Examen(3, "Calculo I", "Pampenio", 60);
		Examen* examenHistoria = new Examen(7, "Historia", "Martha", 45);
		Examen* examenLenguaje = new Examen(8, "Lenguaje", "Ronico", 50);
		Examen* examenBiologia = new Examen(9, "Biologia", "Sofia", 65);



		plataformaEvalucacion->registrarExamen(examenProgramacion);
		plataformaEvalucacion->registrarExamen(examenCalculo);
		plataformaEvalucacion->registrarExamen(examenHistoria);
		plataformaEvalucacion->registrarExamen(examenLenguaje);
		plataformaEvalucacion->registrarExamen(examenBiologia);

		plataformaEvalucacion->mostrarExamenes();

	}
	catch (ExamenDuplicadoException& e) {
		cout << "Error:" << e.what() << endl;
	}
	
}

// VERIFICADO ORDENAMIENTO

void testordenarPorEdadEstudiantes() {

	Plataforma* plataformaEvalucacion = new Plataforma("Doma");
	try {


		Estudiante* estudianteFabian = new Estudiante(1111, "Fabian", 20, "Fabi@correo.com");
		Estudiante* estudianteJulian = new Estudiante(2222, "Julian", 26, "Juli@correo.com");
		Estudiante* estudianteIvan = new Estudiante(3333, "Ivan", 25, "Iv@correo.com");
		Estudiante* estudianteStefanny = new Estudiante(4444, "Stefanny", 20, "Tefy@correo.com");
		Estudiante* estudianteNicole = new Estudiante(5555, "Nicole", 19, "Niki@correo.com");



		plataformaEvalucacion->registrarEstudiante(estudianteFabian);
		plataformaEvalucacion->registrarEstudiante(estudianteJulian);
		plataformaEvalucacion->registrarEstudiante(estudianteIvan);
		plataformaEvalucacion->registrarEstudiante(estudianteStefanny);
		plataformaEvalucacion->registrarEstudiante(estudianteNicole);



		plataformaEvalucacion->ordenarEstudiantesPorEdad_Mayor_Menor();

	}
	catch (EstudianteDuplicadoException& e) {
		cout << "Error:" << e.what() << endl;
	}
}


//3
void testAgregarPregunta() {

	printTestHeader(3, "testAgregarPregunta");

	Plataforma* plataformaEvalucacion = new Plataforma("Doma");
	

	try {
	
		PreguntaVerdaderoFalso* preguntaTierra = new PreguntaVerdaderoFalso("P2", "La tierra es geoide?", 10);
		PreguntaVerdaderoFalso* preguntaChoripan = new PreguntaVerdaderoFalso("P8", "Te gusta el choripan?", 10);

		plataformaEvalucacion->agregarNvaPregunta(1, preguntaTierra);
		plataformaEvalucacion->agregarNvaPregunta(1, preguntaChoripan);
		preguntaTierra->setRespuestaCorrecta("Verdadero");

	}
	catch (PreguntaDuplicadaException& p) {
		cout << "Error:" << p.what() << endl;
	}
}




int main(){ 
	//testRegistrarEstudiante();
	//testRegistrarExamen();
	//testordenarPorEdadEstudiantes();


}

