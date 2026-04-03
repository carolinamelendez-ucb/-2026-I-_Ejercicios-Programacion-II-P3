#pragma once
#include "Figura.h"

class Rectangulo : public Figura
{
private:
	float base;
	float altura;
public:
	Rectangulo(float base, float altura)
	{
		this->base = base;
		this->altura = altura;
	}

	float calcularArea()override
	{
		return base * altura;
	}

};
