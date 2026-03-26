#pragma once
#include "Equipo.h"
class VectorEquipo
{
private:
	Equipo** equipos;
	int ind;
	int tamanio;
public:
	VectorEquipo(int tamanio)
	{
		this->equipos = new Equipo * [tamanio];
		this->ind = 0;
		this->tamanio = tamanio;
	}
	~VectorEquipo()
	{
		delete[] equipos;
	}
	void registrar(Equipo* e1)
	{
		equipos[ind] = e1;
		ind++;
	}
	void mostrar()
	{
		cout << "equipos:" << endl;
		for (int i = 0; i < ind; i++)
		{
			equipos[i]->mostrar();
			cout << endl;
		}
	}
	void buscarSocio(int ci)
	{
		for (int i = 0; i < ind; i++)
		{
			if (equipos[i]->getPiloto()->getCi() == ci)
			{
				cout << "socio encontrado en el equipo " << i + 1 << endl;
				equipos[i]->getnombre();
			}
			else if (equipos[i]->getCopiloto()->getCi() == ci)
			{
				cout << "socio encontrado en el equipo " << i+1<< endl;
				equipos[i]->getnombre();
			}


		}

	}
};

