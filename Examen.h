#pragma once
#include "Pregunta.h"
#include "LinkedList.h"

class Examen{
private:
	int id;
	string titulo;
	string docente;
	int duracionMinutos;
	LinkedList<Pregunta>* preguntas;
public:
	Examen(int id, const string& titulo, const string& docente, int duracionMinutos)
		: id(id), titulo(titulo), docente(docente), duracionMinutos(duracionMinutos)
	{
		this->preguntas =new LinkedList<Pregunta>();
	}

	int getID(){
		return id;
	}

	static bool compararIdEXAM(int id,Examen* e) {
		return  id == e->id;
	}

	void agregarPregunta(Pregunta* nvaPregunta) {
		preguntas->agregar(nvaPregunta);
	}

	void mostrar() {
		cout << "Id Examen:" << id << endl;
		cout << "Titulo:" << titulo << endl;
		cout << "Duracion del Examen:" << duracionMinutos << endl;
		cout << endl;
	}


	~Examen(){
		delete preguntas;
	}

};
