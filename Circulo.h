#pragma once
#include "Figura.h"

class Circulo : public Figura
{
private:
	float radio;

public:
	Circulo(float radio)
	{
		this->radio = radio;

	}

	float calcularArea() override
	{
		return 3.1416 * radio * radio;
	}
};