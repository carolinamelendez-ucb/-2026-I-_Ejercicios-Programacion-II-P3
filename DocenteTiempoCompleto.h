#pragma once
#include "Docente.h"

class DocenteTiempoCompleto:public Docente
{
private:
	int aniosAntiguedad;
public:
	DocenteTiempoCompleto(string nombre, int ci, int aniosAntiguedad, bool aproboEntrevista)
		:Docente(nombre, ci, 3000, aproboEntrevista)
	{
		this->aniosAntiguedad = aniosAntiguedad;
	}

	float calculaSalario()
	{
		if (aniosAntiguedad >= 0 && aniosAntiguedad<=5)
		{
			return salarioBase * (1.05);
		}
		else if (aniosAntiguedad >= 6 && aniosAntiguedad <= 10)
		{
			return salarioBase * (1.15);
		}
		else if (aniosAntiguedad > 10)
		{
			return salarioBase * (1.25);
		}
	}
	void mostrar()
	{
		Docente::mostrar();
		cout << "Anios de antiguedad: " << aniosAntiguedad << endl;
		cout << "el Salario final sera: " << calculaSalario() << endl;
	}
};