// Simulacro.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "SistemaAcademico.h"
#include "utils.h"
using namespace std;

void printTestHeader(int numero, const string& nombreTest) {
	cout << "\n===== TEST " << numero << ": " << nombreTest << " =====" << endl;
}

void testRegistrarCursoOk() {
	printTestHeader(1, "testRegistrarCursoOk");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	Curso* curso = new Curso("P1", "Programacion 1", "PRESENCIAL", 20);

	sistema->registrarCurso(curso);

	assertEquals(curso->getCupos(), 20);
}

void testRegistrarCursoDuplicadoException() {
	printTestHeader(2, "testRegistrarCursoDuplicadoException");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	sistema->registrarCurso(new Curso("P1", "Programacion 1", "PRESENCIAL", 20));

	try {
		sistema->registrarCurso(new Curso("P1", "Programacion 2", "VIRTUAL", 15));
		assertTrue(false);
	}
	catch (CursoDuplicadoException& err) {
		assertEquals(string(err.what()), string("El nuevo curso tiene un codigo duplicado"));
	}
}

void testRegistrarCursoCupoInvalidoMenorIgualCero() {
	printTestHeader(3, "testRegistrarCursoCupoInvalidoMenorIgualCero");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");

	try {
		sistema->registrarCurso(new Curso("P1", "Programacion 1", "PRESENCIAL", 0));
		assertTrue(false);
	}
	catch (CupoInvalidoException& err) {
		assertEquals(string(err.what()), string("La capacidad maxima del curso es menor o igual a 0 o mayor a 30"));
	}
}

void testRegistrarCursoCupoInvalidoMayor30() {
	printTestHeader(4, "testRegistrarCursoCupoInvalidoMayor30");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");

	try {
		sistema->registrarCurso(new Curso("P1", "Programacion 1", "PRESENCIAL", 31));
		assertTrue(false);
	}
	catch (CupoInvalidoException& err) {
		assertEquals(string(err.what()), string("La capacidad maxima del curso es menor o igual a 0 o mayor a 30"));
	}
}

void testRegistrarEstudianteDuplicadoException() {
	printTestHeader(5, "testRegistrarEstudianteDuplicadoException");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	sistema->registrarEstudiante(new Estudiante(123, "Sofia", "Rojas"));

	try {
		sistema->registrarEstudiante(new Estudiante(123, "Ana", "Perez"));
		assertTrue(false);
	}
	catch (EstudianteDuplicadoException& err) {
		assertEquals(string(err.what()), string("El estudiante tiene un CI duplicado"));
	}
}

void testRegistrarInscripcionEstudianteNoEncontrado() {
	printTestHeader(6, "testRegistrarInscripcionEstudianteNoEncontrado");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	sistema->registrarCurso(new Curso("V1", "Excel", "VIRTUAL", 10));

	try {
		sistema->registrarInscripcion(new Inscripcion("2026-05-19", "ACTIVA"), 999, "VIRTUAL");
		assertTrue(false);
	}
	catch (EstudianteNoEncontradoException& err) {
		assertEquals(string(err.what()), string("El estudiante no existe"));
	}
}

void testRegistrarInscripcionSinCursosDisponiblesSinModalidad() {
	printTestHeader(7, "testRegistrarInscripcionSinCursosDisponiblesSinModalidad");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	sistema->registrarEstudiante(new Estudiante(123, "Sofia", "Rojas"));

	try {
		sistema->registrarInscripcion(new Inscripcion("2026-05-19", "ACTIVA"), 123, "VIRTUAL");
		assertTrue(false);
	}
	catch (SinCursosDisponiblesException& err) {
		assertEquals(string(err.what()), string("No existen cursos con cupos disponibles en esa modalidad"));
	}
}

void testRegistrarInscripcionSinCursosDisponiblesSinCupos() {
	printTestHeader(8, "testRegistrarInscripcionSinCursosDisponiblesSinCupos");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	sistema->registrarCurso(new Curso("V1", "Excel", "VIRTUAL", 1));
	sistema->registrarEstudiante(new Estudiante(111, "Luis", "Lopez"));
	sistema->registrarEstudiante(new Estudiante(222, "Marta", "Ruiz"));

	sistema->registrarInscripcion(new Inscripcion("2026-05-19", "ACTIVA"), 111, "VIRTUAL");

	try {
		sistema->registrarInscripcion(new Inscripcion("2026-05-20", "ACTIVA"), 222, "VIRTUAL");
		assertTrue(false);
	}
	catch (SinCursosDisponiblesException& err) {
		assertEquals(string(err.what()), string("No existen cursos con cupos disponibles en esa modalidad"));
	}
}

void testRegistrarInscripcionExitosaDisminuyeCuposYAsignaReferencias() {
	printTestHeader(9, "testRegistrarInscripcionExitosaDisminuyeCuposYAsignaReferencias");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	Curso* curso = new Curso("V1", "Excel", "VIRTUAL", 2);
	Estudiante* estudiante = new Estudiante(123, "Sofia", "Rojas");
	Inscripcion* inscripcion = new Inscripcion("2026-05-19", "ACTIVA");

	sistema->registrarCurso(curso);
	sistema->registrarEstudiante(estudiante);
	sistema->registrarInscripcion(inscripcion, 123, "VIRTUAL");

	assertEquals(curso->getCupos(), 1);
	assertEquals(inscripcion->getCurso(), curso);
	assertEquals(inscripcion->getEstudiante(), estudiante);
	assertEquals(inscripcion->getEstado(), string("ACTIVA"));
}

void testCancelarInscripcionNoEncontrada() {
	printTestHeader(10, "testCancelarInscripcionNoEncontrada");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");

	try {
		sistema->cancelarInscripcion(999, "X1");
		assertTrue(false);
	}
	catch (InscripcionNoEncontradaException& err) {
		assertEquals(string(err.what()), string("La inscripcion no existe"));
	}
}

void testCancelarInscripcionCambiaEstadoACancelada() {
	printTestHeader(11, "testCancelarInscripcionCambiaEstadoACancelada");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	Curso* curso = new Curso("P1", "Programacion 1", "PRESENCIAL", 10);
	Estudiante* estudiante = new Estudiante(123, "Sofia", "Rojas");
	Inscripcion* inscripcion = new Inscripcion("2026-05-19", "ACTIVA");

	sistema->registrarCurso(curso);
	sistema->registrarEstudiante(estudiante);
	sistema->registrarInscripcion(inscripcion, 123, "PRESENCIAL");
	sistema->cancelarInscripcion(123, "P1");

	// Este test valida el requerimiento 4 (estado CANCELADA).
	assertEquals(inscripcion->getEstado(), string("CANCELADA"));
}

void testCancelarInscripcionYaCanceladaException() {
	printTestHeader(12, "testCancelarInscripcionYaCanceladaException");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	Curso* curso = new Curso("P1", "Programacion 1", "PRESENCIAL", 10);
	Estudiante* estudiante = new Estudiante(123, "Sofia", "Rojas");
	Inscripcion* inscripcion = new Inscripcion("2026-05-19", "ACTIVA");

	sistema->registrarCurso(curso);
	sistema->registrarEstudiante(estudiante);
	sistema->registrarInscripcion(inscripcion, 123, "PRESENCIAL");
	sistema->cancelarInscripcion(123, "P1");

	try {
		sistema->cancelarInscripcion(123, "P1");
		assertTrue(false);
	}
	catch (InscripcionYaCanceladaException& err) {
		assertTrue(string(err.what()).size() > 0);
	}
}

void testReglaMaximo3InscripcionesActivas() {
	printTestHeader(13, "testReglaMaximo3InscripcionesActivas");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	sistema->registrarCurso(new Curso("V1", "Excel", "VIRTUAL", 10));
	sistema->registrarCurso(new Curso("V2", "Power BI", "VIRTUAL", 10));
	sistema->registrarCurso(new Curso("V3", "SQL", "VIRTUAL", 10));
	sistema->registrarCurso(new Curso("V4", "Python", "VIRTUAL", 10));
	sistema->registrarEstudiante(new Estudiante(123, "Sofia", "Rojas"));

	sistema->registrarInscripcion(new Inscripcion("2026-05-19", "ACTIVA"), 123, "VIRTUAL");
	sistema->registrarInscripcion(new Inscripcion("2026-05-20", "ACTIVA"), 123, "VIRTUAL");
	sistema->registrarInscripcion(new Inscripcion("2026-05-21", "ACTIVA"), 123, "VIRTUAL");

	try {
		sistema->registrarInscripcion(new Inscripcion("2026-05-22", "ACTIVA"), 123, "VIRTUAL");
		assertTrue(false);
	}
	catch (LimiteInscripcionesException& err) {
		assertEquals(string(err.what()), string("El estudiante supera el maximo permitido de cursos activos (maximo 3)"));
	}
}

void testAsignacionAutomaticaMayorCantidadDeCupos() {
	printTestHeader(14, "testAsignacionAutomaticaMayorCantidadDeCupos");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	Curso* cursoConMenosCupos = new Curso("V1", "Curso A", "VIRTUAL", 1);
	Curso* cursoConMasCupos = new Curso("V2", "Curso B", "VIRTUAL", 3);
	Estudiante* estudiante = new Estudiante(123, "Sofia", "Rojas");
	Inscripcion* inscripcion = new Inscripcion("2026-05-19", "ACTIVA");

	sistema->registrarCurso(cursoConMenosCupos);
	sistema->registrarCurso(cursoConMasCupos);
	sistema->registrarEstudiante(estudiante);
	sistema->registrarInscripcion(inscripcion, 123, "VIRTUAL");

	// El requerimiento pide elegir el curso con mayor cupo disponible de la modalidad.
	assertEquals(inscripcion->getCurso()->getCodigo(), string("V2"));
}

void testBuscarYMostrarNoRevientaSiExisteEstudiante() {
	printTestHeader(15, "testBuscarYMostrarNoRevientaSiExisteEstudiante");
	SistemaAcademico* sistema = new SistemaAcademico("Future Skills");
	sistema->registrarEstudiante(new Estudiante(123, "Sofia", "Rojas"));
	sistema->buscarYmostrar(123);

	assertTrue(true);
}


int main()
{
	testRegistrarCursoOk();
	
	testRegistrarCursoDuplicadoException();
	testRegistrarCursoCupoInvalidoMenorIgualCero();
	testRegistrarCursoCupoInvalidoMayor30();
	testRegistrarEstudianteDuplicadoException();
	testRegistrarInscripcionEstudianteNoEncontrado();
	testRegistrarInscripcionSinCursosDisponiblesSinModalidad();
	testRegistrarInscripcionSinCursosDisponiblesSinCupos();
	testRegistrarInscripcionExitosaDisminuyeCuposYAsignaReferencias();
	testCancelarInscripcionNoEncontrada();
	testCancelarInscripcionCambiaEstadoACancelada();
	testCancelarInscripcionYaCanceladaException();
	testReglaMaximo3InscripcionesActivas();
	testAsignacionAutomaticaMayorCantidadDeCupos();
	testBuscarYMostrarNoRevientaSiExisteEstudiante();
}