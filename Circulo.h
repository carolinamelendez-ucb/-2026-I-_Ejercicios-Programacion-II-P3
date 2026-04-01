#pragma once
#include <iostream>
#include <string>
#include "Figura.h"
using namespace std;

class Circulo: public Figura
{
private:
	float radio;
public:

	Circulo(float radio)
		: radio(radio)
	{}
	float  calcularArea() override
	{
		return 3.1416 * (radio * radio);
	}
};

