#pragma once
#include <iostream>
#include <string>
#include "Figura.h"
using namespace std;

class Rectangulo :public Figura
{
private:
	float base;
	float altura;
public:


	Rectangulo(float base, float altura)
		: base(base), altura(altura)
	{}
	float  calcularArea() override
	{
		return base * altura;
	}
};