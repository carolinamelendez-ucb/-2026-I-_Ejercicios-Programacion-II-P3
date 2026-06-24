#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

enum class Dificultad {
	FACIL, MEDIA, DIFICIL
};

// Clase base abstracta
class Pregunta {
protected:
	string codigo;
	string enunciado;
	double puntaje;
	Dificultad nivelDificultad;
	string etiqueta;

public:
	Pregunta(const string& codigo, const string& enunciado, double puntaje)
		: codigo(codigo), enunciado(enunciado), puntaje(puntaje),
		nivelDificultad(Dificultad::MEDIA), etiqueta("")
	{
	}

	virtual double corregir(string respuesta) = 0;

	double obtenerPuntaje(string respuesta) {
		return corregir(respuesta) * puntaje;
	}

	string getCodigo() {
		return codigo;
	}
	string getEnunciado() {
		return enunciado;
	}
	double getPuntaje() {
		return puntaje;
	}
	Dificultad getNivelDificultad() {
		return nivelDificultad;
	}
	string getEtiqueta() {
		return etiqueta;
	}
	void setNivelDificultad(Dificultad nivel) {
		this->nivelDificultad = nivel;
	}


	static bool compararCodigo(string codigo, Pregunta* preguntaComparada) {
		return codigo == preguntaComparada->codigo;
	}
	static bool compararEnunciado(string enunciado, Pregunta* preguntaComparada) {
		return enunciado == preguntaComparada->enunciado;
	}
	virtual void agregarOpcion(string opcion) {
	}
	virtual void setIndiceRespuestaCorrecta(int indice) {
	}
	virtual ~Pregunta() {}
};

// ---------- PreguntaOpcionMultiple ----------
class PreguntaOpcionMultiple : public Pregunta {
private:
	LinkedList<string>* opciones;
	int indiceRespuestaCorrecta;

public:
	PreguntaOpcionMultiple(const string& codigo, const string& enunciado, double puntaje)
		: Pregunta(codigo, enunciado, puntaje), indiceRespuestaCorrecta(-1)
	{
		this->opciones = new LinkedList<string>();
	}

	virtual void agregarOpcion(string opcion) override {
		opciones->agregar(new string(opcion));
	}
	virtual void setIndiceRespuestaCorrecta(int indice) override {
		this->indiceRespuestaCorrecta = indice;
	}

	double corregir(string respuesta) override {
		string* correcta = opciones->obtenerPorIndice(indiceRespuestaCorrecta);
		if (correcta != nullptr && *correcta == respuesta) {
			return 1.0;
		}
		return 0.0;
	}
};

// ---------- PreguntaVerdaderoFalso ----------
class PreguntaVerdaderoFalso : public Pregunta {
private:
	string respuestaCorrecta;

public:
	PreguntaVerdaderoFalso(const string& codigo, const string& enunciado, double puntaje)
		: Pregunta(codigo, enunciado, puntaje), respuestaCorrecta("")
	{
	}

	void setRespuestaCorrecta(string respuestaCorrecta) {
		this->respuestaCorrecta = respuestaCorrecta;
	}

	double corregir(string respuesta) override {
		if (respuesta == respuestaCorrecta) {
			return 1.0;
		}
		return 0.0;
	}
};

// ---------- PreguntaAbierta ----------
class PreguntaAbierta : public Pregunta {
private:
	LinkedList<string>* palabrasClave;

public:
	PreguntaAbierta(const string& codigo, const string& enunciado, double puntaje)
		: Pregunta(codigo, enunciado, puntaje)
	{
		this->palabrasClave = new LinkedList<string>();
	}

	void agregarPalabraClave(string palabra) {
		palabrasClave->agregar(new string(palabra));
	}

	static bool contienePalabra(string respuesta, string* palabra) {
		return respuesta.find(*palabra) != string::npos;
	}

	double corregir(string respuesta) override {
		int total = palabrasClave->contar();
		if (total == 0) {
			return 0.0;
		}
		int encontradas = palabrasClave->contarCriterio(respuesta, contienePalabra);
		return (double)encontradas / (double)total;
	}
};