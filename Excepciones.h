#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class BasicException : public exception {
private:
	string mensaje;
public:
	BasicException(string men) {
		this->mensaje = men;
	}

	virtual char const* what() const noexcept override {
		return mensaje.c_str();
	}
};

class EstudianteDuplicadoException : public BasicException {
public:EstudianteDuplicadoException(int cod) :
	BasicException(mensajeA(cod)){}
private:
	static string mensajeA(int c) {
		stringstream ss;
		ss << "La matricula " << c << " esta duplicada.";
		return ss.str();
	}
};


class ExamenDuplicadoException : public BasicException {
public:ExamenDuplicadoException(int cod) :
	BasicException(mensajeA(cod)) {
}
private:
	static string mensajeA(int c) {
		stringstream ss;
		ss << "El id " << c << " esta duplicado.";
		return ss.str();
	}
};


class EstudianteNoExistenteException : public BasicException {
public:
	EstudianteNoExistenteException(int cod):
		BasicException(mensajeA(cod)){}
private:
	static string mensajeA(int c) {
		stringstream ss;
		ss << "La matricula " << c << " no existe.";
		return ss.str();
	}
};


class ExamenNoExistenteException : public BasicException {
public:
	ExamenNoExistenteException(int cod) :
		BasicException(mensajeA(cod)) {
	}
private:
	static string mensajeA(int c) {
		stringstream ss;
		ss << "El codigo " << c << " no existe.";
		return ss.str();
	}
};


class PreguntaNoEncontradaException : public BasicException {
public:
	PreguntaNoEncontradaException(int cod):
		BasicException(mensajeA(cod)){}
private:
	static string mensajeA(int m) {
		stringstream ss;
		ss << "La pregunta con codigo " << m << " no existe.";
		return ss.str();
	}
};



class PreguntaDuplicadaException : public BasicException {
public:
	PreguntaDuplicadaException(int cod):
		BasicException(mensajeA(cod)){ }
private:
	static string mensajeA(int m){
		stringstream ss;
		ss << "La pregunta con codigo " << m << " esta duplicada.";
		return ss.str();
	}

};