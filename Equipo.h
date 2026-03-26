#pragma once
#include "Socio.h"
class Equipo
{
private:
	Socio* piloto;
	Socio* copilot;
	string nombre;
	string Auto;
public:
	Equipo(string nombre, string Auto)
	{
		this->nombre = nombre;
		this->Auto = Auto;
		piloto = nullptr;
		copilot = nullptr;
	}
	void registrar(Socio* s1,Socio* s2)
	{
		if (s1->getNombre() == s2->getNombre())
		{
			cout << "no se puede agregar al mismo socio al mismo equipo";
		}
		else
		{
			piloto = s1;
			copilot = s2;
		}
	}
	void mostrar()
	{
		cout << "nombre de equipo: " << nombre << endl;
		cout << "modelo de auto: " << Auto << endl;

		if (piloto != nullptr)
			cout << "piloto: " << piloto->getNombre() << endl;
		else
			cout << "sin piloto\n";

		if (copilot != nullptr)
			cout << "copiloto: " << copilot->getNombre() << endl;
		else
			cout << "sin copiloto\n";
	}
	Socio* getPiloto()
	{
		return piloto;
	}

	Socio* getCopiloto()
	{
		return copilot;
	}
	string getnombre()
	{
		return nombre;
	}
};

