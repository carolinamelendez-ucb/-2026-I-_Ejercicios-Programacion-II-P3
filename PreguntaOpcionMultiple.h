#pragma once
#include "LinkedList.h"
#include "Pregunta.h"

class PreguntaOpcionMultiple : public Pregunta {
private:
	LinkedList<string>* opciones;
	string indiceRespuestaCorrecta;
public:
	PreguntaOpcionMultiple(string codigo,string enunciado,int puntaje)
		:Pregunta(codigo,enunciado,puntaje,"MEDIA") {
		this->opciones = new LinkedList<string>();
		this->indiceRespuestaCorrecta = "";
	}

	void agregarOpcion(string opcion) {
		opciones->agregar(new string(opcion));			// OJO CON ESO
	}

	void setIndiqueRespuestaCorrecta(int respuesta) {
		this->indiceRespuestaCorrecta = respuesta;
	}



	double corregir(string respuesta) override{
		int indice = 0;
		
		

		if (respuesta==indiceRespuestaCorrecta) {
			return 1.0;
		}
		else{
			return 0.0;
		}
	}

	void mostrar() override {
		cout << "Pregunta Op. Multiple:" << endl;
	}

	~PreguntaOpcionMultiple(){
	}

};