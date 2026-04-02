#pragma once
#pragma once
#include <iostream>
#include <string>
#include "Figura.h"
using namespace std;
class Rectangulo: public Figura{
private: 
	float altura;
	float base;
public:
	Rectangulo() = default;

	Rectangulo(float altura, float base)
		: altura(altura), base(base)
	{
	}

	float calcularArea() {
		return base * altura;
	}
};