// EF_SistemaEvaluaciones.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Plataforma.h"
#include "Estudiante.h"
#include "Examen.h"
#include "Resultado.h"
#include "Pregunta.h"
#include "Excepciones.h"
#include "utils.h"

using namespace std;

void printTestHeader(int numero, const string& nombreTest) {
	cout << "\n===== TEST " << numero << ": " << nombreTest << " =====" << endl;
}

// ============ MINI TEST ENUMS / POLIMORFISMO ============

void ejemploMiniEnumsEvaluaciones() {
	printTestHeader(0, "ejemploMiniEnumsEvaluaciones");
	Dificultad facil = Dificultad::FACIL;
	Dificultad media = Dificultad::MEDIA;

	assertEnumEquals(facil, Dificultad::FACIL);
	assertEnumEquals(media, Dificultad::MEDIA);
}

// ============ FLUJO COMPLETO (EJEMPLO DEL PDF) ============

void testFlujoCompletoExamenAprobado() {
	printTestHeader(1, "testFlujoCompletoExamenAprobado");

	Plataforma* plataformaEvaluacion =
		new Plataforma("Sistema de Evaluaciones");

	Estudiante* estudianteJuanPerez =
		new Estudiante("2025001", "Juan Perez", "juan@correo.com");

	Examen* examenProgramacion =
		new Examen(1, "Programacion II", "Docente A", 90);

	plataformaEvaluacion->registrarEstudiante(estudianteJuanPerez);
	plataformaEvaluacion->registrarExamen(examenProgramacion);

	Pregunta* preguntaCapitalBolivia =
		new PreguntaOpcionMultiple("P1", "Capital de Bolivia", 10);
	preguntaCapitalBolivia->agregarOpcion("La Paz");
	preguntaCapitalBolivia->agregarOpcion("Sucre");
	preguntaCapitalBolivia->agregarOpcion("Santa Cruz");
	preguntaCapitalBolivia->setIndiceRespuestaCorrecta(1);
	plataformaEvaluacion->agregarPregunta(1, preguntaCapitalBolivia);

	PreguntaVerdaderoFalso* preguntaCppPOO =
		new PreguntaVerdaderoFalso("P2", "C++ es orientado a objetos", 20);
	preguntaCppPOO->setRespuestaCorrecta("verdadero");
	plataformaEvaluacion->agregarPregunta(1, preguntaCppPOO);

	plataformaEvaluacion->iniciarExamen("2025001", 1);
	plataformaEvaluacion->responderPregunta("2025001", 1, "P1", "Sucre");
	plataformaEvaluacion->responderPregunta("2025001", 1, "P2", "verdadero");
	plataformaEvaluacion->finalizarExamen("2025001", 1);

	Resultado* resultadoExamenProgramacion =
		plataformaEvaluacion->obtenerResultado("2025001", 1);

	assertEquals(resultadoExamenProgramacion->getPuntajeObtenido(), 30.0);
	assertEquals(resultadoExamenProgramacion->getEstado(), string("APROBADO"));
}

void testFlujoCompletoExamenReprobado() {
	printTestHeader(2, "testFlujoCompletoExamenReprobado");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarEstudiante(new Estudiante("2025002", "Ana Lopez", "ana@correo.com"));
	plataforma->registrarExamen(new Examen(2, "Bases de Datos", "Docente B", 60));

	PreguntaVerdaderoFalso* p1 = new PreguntaVerdaderoFalso("P1", "SQL es un lenguaje", 50);
	p1->setRespuestaCorrecta("verdadero");
	plataforma->agregarPregunta(2, p1);

	plataforma->iniciarExamen("2025002", 2);
	plataforma->responderPregunta("2025002", 2, "P1", "falso"); // mal
	plataforma->finalizarExamen("2025002", 2);

	Resultado* r = plataforma->obtenerResultado("2025002", 2);
	assertEquals(r->getPuntajeObtenido(), 0.0);
	assertEquals(r->getEstado(), string("REPROBADO"));
}

// ============ 1. REGISTRAR ESTUDIANTE ============

void testRegistrarEstudianteOk() {
	printTestHeader(3, "testRegistrarEstudianteOk");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	Estudiante* estudiante = new Estudiante("2025010", "Carlos Diaz", "carlos@correo.com");

	plataforma->registrarEstudiante(estudiante);

	assertEquals(plataforma->getCantidadEstudiantes(), 1);
	assertEquals(estudiante->getMatricula(), string("2025010"));
	assertEquals(estudiante->getNombre(), string("Carlos Diaz"));
}

void testRegistrarEstudianteDuplicadoException() {
	printTestHeader(4, "testRegistrarEstudianteDuplicadoException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarEstudiante(new Estudiante("2025010", "Carlos Diaz", "carlos@correo.com"));

	try {
		plataforma->registrarEstudiante(new Estudiante("2025010", "Otro Nombre", "otro@correo.com"));
		assertTrue(false, "No salto el throw esperado");
	}
	catch (EstudianteDuplicadoException& err) {
		assertEquals(string(err.what()), string("El estudiante con matricula '2025010' ya existe"));
	}
}

// ============ 2. REGISTRAR EXAMEN ============

void testRegistrarExamenOk() {
	printTestHeader(5, "testRegistrarExamenOk");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	Examen* examen = new Examen(10, "Algoritmos", "Docente C", 120);

	plataforma->registrarExamen(examen);

	assertEquals(plataforma->getCantidadExamenes(), 1);
	assertEquals(examen->getTitulo(), string("Algoritmos"));
	assertEquals(examen->getId(), 10);
}

void testRegistrarExamenDuplicadoException() {
	printTestHeader(6, "testRegistrarExamenDuplicadoException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarExamen(new Examen(10, "Algoritmos", "Docente C", 120));

	try {
		plataforma->registrarExamen(new Examen(11, "Algoritmos", "Docente D", 90));
		assertTrue(false, "No salto el throw esperado");
	}
	catch (ExamenDuplicadoException& err) {
		assertEquals(string(err.what()), string("El examen con titulo 'Algoritmos' ya existe"));
	}
}

// ============ 3. AGREGAR PREGUNTA ============

void testAgregarPreguntaOk() {
	printTestHeader(7, "testAgregarPreguntaOk");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	Examen* examen = new Examen(20, "Redes", "Docente E", 60);
	plataforma->registrarExamen(examen);

	PreguntaAbierta* p = new PreguntaAbierta("P1", "Que es TCP", 10);
	p->agregarPalabraClave("protocolo");
	plataforma->agregarPregunta(20, p);

	assertEquals(examen->getCantidadPreguntas(), 1);
}

void testAgregarPreguntaExamenNoEncontradoException() {
	printTestHeader(8, "testAgregarPreguntaExamenNoEncontradoException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");

	try {
		plataforma->agregarPregunta(999, new PreguntaVerdaderoFalso("P1", "Pregunta", 10));
		assertTrue(false, "No salto el throw esperado");
	}
	catch (ExamenNoEncontradoException& err) {
		assertEquals(string(err.what()), string("No existe un examen con id 999"));
	}
}

void testAgregarPreguntaDuplicadaException() {
	printTestHeader(9, "testAgregarPreguntaDuplicadaException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarExamen(new Examen(20, "Redes", "Docente E", 60));

	plataforma->agregarPregunta(20, new PreguntaVerdaderoFalso("P1", "TCP es confiable", 10));

	try {
		plataforma->agregarPregunta(20, new PreguntaVerdaderoFalso("P2", "TCP es confiable", 15));
		assertTrue(false, "No salto el throw esperado");
	}
	catch (PreguntaDuplicadaException& err) {
		assertEquals(string(err.what()), string("La pregunta con enunciado 'TCP es confiable' ya existe en el examen"));
	}
}

void testAgregarPreguntaLimite20Exception() {
	printTestHeader(10, "testAgregarPreguntaLimite20Exception");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarExamen(new Examen(20, "Redes", "Docente E", 60));

	for (int i = 1; i <= 20; i++) {
		PreguntaVerdaderoFalso* p = new PreguntaVerdaderoFalso(
			"P" + to_string(i), "Enunciado numero " + to_string(i), 5);
		p->setRespuestaCorrecta("verdadero");
		plataforma->agregarPregunta(20, p);
	}

	try {
		plataforma->agregarPregunta(20, new PreguntaVerdaderoFalso("P21", "Enunciado 21", 5));
		assertTrue(false, "No salto el throw esperado");
	}
	catch (LimitePreguntasException& err) {
		assertEquals(string(err.what()), string("El examen con id 20 ya tiene el limite maximo de 20 preguntas"));
	}
}

// ============ 4. RESPONDER PREGUNTA ============

void testResponderPreguntaEstudianteNoEncontradoException() {
	printTestHeader(11, "testResponderPreguntaEstudianteNoEncontradoException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarExamen(new Examen(30, "Sistemas", "Docente F", 60));

	try {
		plataforma->responderPregunta("9999999", 30, "P1", "x");
		assertTrue(false, "No salto el throw esperado");
	}
	catch (EstudianteNoEncontradoException& err) {
		assertEquals(string(err.what()), string("No existe un estudiante con matricula '9999999'"));
	}
}

void testResponderPreguntaExamenNoEncontradoException() {
	printTestHeader(12, "testResponderPreguntaExamenNoEncontradoException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarEstudiante(new Estudiante("2025020", "Luis Gomez", "luis@correo.com"));

	try {
		plataforma->responderPregunta("2025020", 999, "P1", "x");
		assertTrue(false, "No salto el throw esperado");
	}
	catch (ExamenNoEncontradoException& err) {
		assertEquals(string(err.what()), string("No existe un examen con id 999"));
	}
}

void testResponderPreguntaNoEncontradaException() {
	printTestHeader(13, "testResponderPreguntaNoEncontradaException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarEstudiante(new Estudiante("2025020", "Luis Gomez", "luis@correo.com"));
	plataforma->registrarExamen(new Examen(30, "Sistemas", "Docente F", 60));
	plataforma->iniciarExamen("2025020", 30);

	try {
		plataforma->responderPregunta("2025020", 30, "PX", "x");
		assertTrue(false, "No salto el throw esperado");
	}
	catch (PreguntaNoEncontradaException& err) {
		assertEquals(string(err.what()), string("No existe una pregunta con codigo 'PX' en el examen"));
	}
}

// ============ 5. INICIAR EXAMEN ============

void testIniciarExamenEstudianteNoEncontradoException() {
	printTestHeader(14, "testIniciarExamenEstudianteNoEncontradoException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarExamen(new Examen(40, "Compiladores", "Docente G", 60));

	try {
		plataforma->iniciarExamen("0000000", 40);
		assertTrue(false, "No salto el throw esperado");
	}
	catch (EstudianteNoEncontradoException& err) {
		assertEquals(string(err.what()), string("No existe un estudiante con matricula '0000000'"));
	}
}

void testIniciarExamenExamenNoEncontradoException() {
	printTestHeader(15, "testIniciarExamenExamenNoEncontradoException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarEstudiante(new Estudiante("2025030", "Sara Ruiz", "sara@correo.com"));

	try {
		plataforma->iniciarExamen("2025030", 999);
		assertTrue(false, "No salto el throw esperado");
	}
	catch (ExamenNoEncontradoException& err) {
		assertEquals(string(err.what()), string("No existe un examen con id 999"));
	}
}

// ============ 6. FINALIZAR EXAMEN ============

void testFinalizarExamenAprobadoExacto60() {
	printTestHeader(16, "testFinalizarExamenAprobadoExacto60");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarEstudiante(new Estudiante("2025040", "Pedro Vera", "pedro@correo.com"));
	plataforma->registrarExamen(new Examen(50, "Calculo", "Docente H", 90));

	// maximo = 100, obtiene exactamente 60 => APROBADO
	PreguntaVerdaderoFalso* p1 = new PreguntaVerdaderoFalso("P1", "Derivada", 60);
	p1->setRespuestaCorrecta("verdadero");
	plataforma->agregarPregunta(50, p1);
	PreguntaVerdaderoFalso* p2 = new PreguntaVerdaderoFalso("P2", "Integral", 40);
	p2->setRespuestaCorrecta("verdadero");
	plataforma->agregarPregunta(50, p2);

	plataforma->iniciarExamen("2025040", 50);
	plataforma->responderPregunta("2025040", 50, "P1", "verdadero"); // +60
	plataforma->responderPregunta("2025040", 50, "P2", "falso");     // +0
	plataforma->finalizarExamen("2025040", 50);

	Resultado* r = plataforma->obtenerResultado("2025040", 50);
	assertEquals(r->getPuntajeObtenido(), 60.0);
	assertEquals(r->getEstado(), string("APROBADO"));
}

void testFinalizarExamenEstudianteNoEncontradoException() {
	printTestHeader(17, "testFinalizarExamenEstudianteNoEncontradoException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarExamen(new Examen(50, "Calculo", "Docente H", 90));

	try {
		plataforma->finalizarExamen("0000000", 50);
		assertTrue(false, "No salto el throw esperado");
	}
	catch (EstudianteNoEncontradoException& err) {
		assertEquals(string(err.what()), string("No existe un estudiante con matricula '0000000'"));
	}
}

// ============ 7. CONSULTAR RESULTADOS ============

void testConsultarResultadosOk() {
	printTestHeader(18, "testConsultarResultadosOk");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarEstudiante(new Estudiante("2025050", "Nora Paz", "nora@correo.com"));
	plataforma->registrarExamen(new Examen(60, "Fisica", "Docente I", 60));

	PreguntaVerdaderoFalso* p1 = new PreguntaVerdaderoFalso("P1", "Newton", 10);
	p1->setRespuestaCorrecta("verdadero");
	plataforma->agregarPregunta(60, p1);

	plataforma->iniciarExamen("2025050", 60);
	plataforma->responderPregunta("2025050", 60, "P1", "verdadero");
	plataforma->finalizarExamen("2025050", 60);

	assertEquals(plataforma->consultarResultados("2025050"), 1);
}

void testConsultarResultadosEstudianteNoEncontradoException() {
	printTestHeader(19, "testConsultarResultadosEstudianteNoEncontradoException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");

	try {
		plataforma->consultarResultados("0000000");
		assertTrue(false, "No salto el throw esperado");
	}
	catch (EstudianteNoEncontradoException& err) {
		assertEquals(string(err.what()), string("No existe un estudiante con matricula '0000000'"));
	}
}

void testConsultarResultadosSinResultadosException() {
	printTestHeader(20, "testConsultarResultadosSinResultadosException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarEstudiante(new Estudiante("2025060", "Tom Ríos", "tom@correo.com"));

	try {
		plataforma->consultarResultados("2025060");
		assertTrue(false, "No salto el throw esperado");
	}
	catch (SinResultadosException& err) {
		assertEquals(string(err.what()), string("El estudiante con matricula '2025060' no ha finalizado ningun examen"));
	}
}

// ============ 8. PORCENTAJE APROBADOS ============

void testPorcentajeAprobadosOk() {
	printTestHeader(21, "testPorcentajeAprobadosOk");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarExamen(new Examen(70, "Quimica", "Docente J", 60));

	PreguntaVerdaderoFalso* p1 = new PreguntaVerdaderoFalso("P1", "Atomo", 100);
	p1->setRespuestaCorrecta("verdadero");
	plataforma->agregarPregunta(70, p1);

	// 3 estudiantes finalizan, 2 aprueban => 66.6667%
	plataforma->registrarEstudiante(new Estudiante("A1", "E1", "e1@c.com"));
	plataforma->registrarEstudiante(new Estudiante("A2", "E2", "e2@c.com"));
	plataforma->registrarEstudiante(new Estudiante("A3", "E3", "e3@c.com"));

	plataforma->iniciarExamen("A1", 70);
	plataforma->responderPregunta("A1", 70, "P1", "verdadero");
	plataforma->finalizarExamen("A1", 70);

	plataforma->iniciarExamen("A2", 70);
	plataforma->responderPregunta("A2", 70, "P1", "verdadero");
	plataforma->finalizarExamen("A2", 70);

	plataforma->iniciarExamen("A3", 70);
	plataforma->responderPregunta("A3", 70, "P1", "falso");
	plataforma->finalizarExamen("A3", 70);

	assertEquals(plataforma->porcentajeAprobados(70), 66.6667);
}

void testPorcentajeAprobadosExamenNoEncontradoException() {
	printTestHeader(22, "testPorcentajeAprobadosExamenNoEncontradoException");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");

	try {
		plataforma->porcentajeAprobados(999);
		assertTrue(false, "No salto el throw esperado");
	}
	catch (ExamenNoEncontradoException& err) {
		assertEquals(string(err.what()), string("No existe un examen con id 999"));
	}
}

// ============ 9. RESULTADOS ORDENADOS + PREGUNTA ABIERTA ============

void testPreguntaAbiertaProporcionPalabrasClave() {
	printTestHeader(23, "testPreguntaAbiertaProporcionPalabrasClave");
	// 4 palabras clave, la respuesta contiene 3 => 0.75 * 20 = 15
	PreguntaAbierta* p = new PreguntaAbierta("P1", "Defina herencia", 20);
	p->agregarPalabraClave("clase");
	p->agregarPalabraClave("padre");
	p->agregarPalabraClave("hijo");
	p->agregarPalabraClave("atributos");

	double puntaje = p->obtenerPuntaje("una clase padre comparte con la clase hijo");
	assertEquals(puntaje, 15.0);
}

void testMostrarResultadosOrdenadosDescendente() {
	printTestHeader(24, "testMostrarResultadosOrdenadosDescendente");
	Plataforma* plataforma = new Plataforma("Sistema de Evaluaciones");
	plataforma->registrarEstudiante(new Estudiante("2025070", "Eva Soto", "eva@correo.com"));

	// examen 1: puntaje 10
	plataforma->registrarExamen(new Examen(80, "Examen Bajo", "Doc", 60));
	PreguntaVerdaderoFalso* p1 = new PreguntaVerdaderoFalso("P1", "q", 10);
	p1->setRespuestaCorrecta("verdadero");
	plataforma->agregarPregunta(80, p1);
	plataforma->iniciarExamen("2025070", 80);
	plataforma->responderPregunta("2025070", 80, "P1", "verdadero");
	plataforma->finalizarExamen("2025070", 80);

	// examen 2: puntaje 50
	plataforma->registrarExamen(new Examen(81, "Examen Alto", "Doc", 60));
	PreguntaVerdaderoFalso* p2 = new PreguntaVerdaderoFalso("P1", "q", 50);
	p2->setRespuestaCorrecta("verdadero");
	plataforma->agregarPregunta(81, p2);
	plataforma->iniciarExamen("2025070", 81);
	plataforma->responderPregunta("2025070", 81, "P1", "verdadero");
	plataforma->finalizarExamen("2025070", 81);

	plataforma->mostrarResultadosOrdenados("2025070"); // imprime 50 antes que 10

	assertEquals(plataforma->obtenerResultado("2025070", 81)->getPuntajeObtenido(), 50.0);
	assertEquals(plataforma->obtenerResultado("2025070", 80)->getPuntajeObtenido(), 10.0);
}

int main() {
	ejemploMiniEnumsEvaluaciones();
	testFlujoCompletoExamenAprobado();
	testFlujoCompletoExamenReprobado();
	testRegistrarEstudianteOk();
	testRegistrarEstudianteDuplicadoException();
	testRegistrarExamenOk();
	testRegistrarExamenDuplicadoException();
	testAgregarPreguntaOk();
	testAgregarPreguntaExamenNoEncontradoException();
	testAgregarPreguntaDuplicadaException();
	testAgregarPreguntaLimite20Exception();
	testResponderPreguntaEstudianteNoEncontradoException();
	testResponderPreguntaExamenNoEncontradoException();
	testResponderPreguntaNoEncontradaException();
	testIniciarExamenEstudianteNoEncontradoException();
	testIniciarExamenExamenNoEncontradoException();
	testFinalizarExamenAprobadoExacto60();
	testFinalizarExamenEstudianteNoEncontradoException();
	testConsultarResultadosOk();
	testConsultarResultadosEstudianteNoEncontradoException();
	testConsultarResultadosSinResultadosException();
	testPorcentajeAprobadosOk();
	testPorcentajeAprobadosExamenNoEncontradoException();
	testPreguntaAbiertaProporcionPalabrasClave();
	testMostrarResultadosOrdenadosDescendente();
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
