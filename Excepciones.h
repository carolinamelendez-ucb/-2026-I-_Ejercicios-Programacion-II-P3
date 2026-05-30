#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class BasicException : public exception {
private:
	string mensaje;
public:
	BasicException(string mensaje) {
		this->mensaje = mensaje;
	}
	virtual char const* what() const noexcept override {
		return mensaje.c_str();
	}
};


class VehiculoDuplicadoException : public BasicException {
public:
	VehiculoDuplicadoException(int matricula) :
		BasicException(mensajeA(matricula)) {
	}
private:
	static string mensajeA(int mat) {
		stringstream ss;
		ss << "La matricula " << mat << " de este vehiculo esta duplicada";
		return ss.str();
	}
};

class VehiculoNoEncontradoException : public BasicException {
public:
	VehiculoNoEncontradoException(int matricula):
		BasicException(mensajeA(matricula)){ 
	}
private:
	static string mensajeA(int mat) {
		stringstream ss;
		ss << "La matricula " << mat << " no existe";
		return ss.str();
	}
};

class EnergiaMenorException : public BasicException {
public:
	EnergiaMenorException(int energia) :
		BasicException(mensajeA(energia)) {
	}
private:
	static string mensajeA(int energia) {
		stringstream ss;
		ss << "La energia no puede ser " << energia <<" .Es Invalida";
		return ss.str();
	}
};