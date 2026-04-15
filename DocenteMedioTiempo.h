#pragma once
#include "Docente.h"

class DocenteMedioTiempo :public Docente
{
private:
	int cantidadCursosRelaizados;
public:
	DocenteMedioTiempo(string nombre, int ci, int cantidadCursosRelaizados, bool aproboEntrevista)
		:Docente(nombre, ci, 3000, aproboEntrevista)
	{
		this->cantidadCursosRelaizados = cantidadCursosRelaizados;
	}

	float calculaSalario()
	{
		if (cantidadCursosRelaizados >= 2)
		{
			return salarioBase * (1.10);
		}
		else
		{
			return salarioBase;
		}
	}
	void mostrar()
	{
		Docente::mostrar();
		cout << "Cantidad de cursos relaizados: " << cantidadCursosRelaizados << endl;
		cout << "el Salario final sera: " << calculaSalario() << endl;
	}
};