#pragma once
#include <iostream>
#include <string>
#include "Figura.h"
using namespace std;
class Circulo:public Figura {
private: 
	float radio;
public:
	Circulo() = default;

	Circulo(float radio)
		: radio(radio)
	{
	}
	float calcularArea() {
		return 3.1416 * (radio * radio);
	}
};