#pragma once
#include "Socio.h"
class VectorSocios
{
private:
	Socio** socios;
	int ind;
	int tamanio;
public:
	VectorSocios(int tamanio)
	{
		this->socios = new Socio * [tamanio];
		this->ind = 0;
		this->tamanio = tamanio;
	}
	~VectorSocios()
	{
		delete[] socios;
	}
	void mostrar()
	{
		for (int i = 0; i < ind; i++)
		{
			cout << "socio: " << i+1 << " ";
			socios[i]->mostrar();
			cout << endl;
		}
	}
	void registrarSocio(Socio* socio)
	{
		if (ind < tamanio)
		{
			socios[ind] = socio;
			ind++;
		}
		else
		{
			cout << "Vector lleno\n";
		}
	}
	Socio* getSocio(int pos)
	{
		if (pos >= 0 && pos < ind)
			return socios[pos];
		return nullptr;
	}
	void ordenar()
	{
		for (int i = 0; i < ind - 1; i++)
		{
			for (int j = i + 1; j < ind; j++)
			{
				if (socios[i]->getNombre() > socios[j]->getNombre())
				{
					Socio* aux = socios[i];
					socios[i] = socios[j];
					socios[j] = aux;
				}
			}
		}
	}
};


