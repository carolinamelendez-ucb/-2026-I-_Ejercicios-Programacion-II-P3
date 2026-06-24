#pragma once

#include <exception>
#include <string>

using namespace std;

class BasicException : public exception {
private:
	string mensaje;

public:
	explicit BasicException(const string& mensaje)
		: mensaje(mensaje) {
	}

	virtual const char* what() const noexcept override {
		return mensaje.c_str();
	}
};

class EstudianteDuplicadoException : public BasicException {
public:
	EstudianteDuplicadoException(string matricula)
		: BasicException("El estudiante con matricula '" + matricula + "' ya existe") {
	}
};


class ExamenDuplicadoException : public BasicException {
public:
	ExamenDuplicadoException(string titulo)
		: BasicException("El examen con titulo '" + titulo + "' ya existe") {
	}
};

class ExamenNoEncontradoException : public BasicException {
public:
	ExamenNoEncontradoException(int id)
		: BasicException("No existe un examen con id " + to_string(id)) {
	}
};

class EstudianteNoEncontradoException : public BasicException {
public:
	EstudianteNoEncontradoException(string matricula)
		: BasicException("No existe un estudiante con matricula '" + matricula + "'") {
	}
};

class PreguntaDuplicadaException : public BasicException {
public:
	PreguntaDuplicadaException(string enunciado)
		: BasicException("La pregunta con enunciado '" + enunciado + "' ya existe en el examen") {
	}
};

class LimitePreguntasException : public BasicException {
public:
	LimitePreguntasException(int id)
		: BasicException("El examen con id " + to_string(id) + " ya tiene el limite maximo de 20 preguntas") {
	}
};

class PreguntaNoEncontradaException : public BasicException {
public:
	PreguntaNoEncontradaException(string codigo)
		: BasicException("No existe una pregunta con codigo '" + codigo + "' en el examen") {
	}
};

class SinResultadosException : public BasicException {
public:
	SinResultadosException(string matricula)
		: BasicException("El estudiante con matricula '" + matricula + "' no ha finalizado ningun examen") {
	}
};