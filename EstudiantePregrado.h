#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;

class EstudiantePregrado: public Estudiante {
public:
	EstudiantePregrado(int ci, const string& nombre, int matricula,bool pago)
		: Estudiante(ci,nombre,matricula,"Pregrado",pago)
	{
	}
};