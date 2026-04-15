#pragma once
#include <iostream>
#include <string>
#include "Docente.h"
using namespace std;

class DocenteMedioTiempo: public Docente {
public:
	DocenteMedioTiempo(int ci, const string& nombre, int salario, bool finalizo)
		: Docente(ci,nombre,salario,0,"Medio Tiempo",finalizo)
	{
	}
};