#pragma once
#include <iostream>
#include <string>

using namespace std;

class Figura
{
public:
	virtual float calcularArea() = 0;

	virtual ~Figura(){}
};