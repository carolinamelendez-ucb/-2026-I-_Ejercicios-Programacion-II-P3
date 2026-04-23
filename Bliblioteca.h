#pragma once
#include <string>
#include <iostream>
#include "vecLibro.h"
#include "VecEstudiante.h"
#include <exception>
using namespace std;
class Biblioteca {
private:
	VecEstudiante* estudainte;
	VecLibro* libro;
	int maxTamanio;
public:
	Biblioteca(int maxTamanio) {
		this->maxTamanio = maxTamanio;
		this->estudainte = new  VecEstudiante(maxTamanio);
		this->libro = new  VecLibro(maxTamanio);
	}

};