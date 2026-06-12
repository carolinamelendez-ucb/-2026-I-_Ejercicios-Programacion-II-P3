#pragma once
#include "Pregunta.h"

class PreguntaVerdaderoFalso : public Pregunta {
private:
	string respuestaCorrecta;
public:
	PreguntaVerdaderoFalso(string codigo,string enunciado,int puntaje) 
		:Pregunta(codigo,enunciado,puntaje,"MEDIA") { 
		this->respuestaCorrecta = "";
	}

	void setRespuestaCorrecta(string res) {
		respuestaCorrecta = res;
	}	

	double corregir(string respuesta) override{
		if (respuestaCorrecta==respuesta) {
			return 1.0;
		}
		else {
			return 0.0;
		}
	}

	void mostrar() override {
		cout << "Pregunta V/F: " << enunciado << " Respuesta: " << respuestaCorrecta << endl;
	}

};