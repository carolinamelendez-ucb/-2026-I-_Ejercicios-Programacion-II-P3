#pragma once
#include "Socio.cpp"
class VectSocio {
private:
	Socio** socio;
	int tamanio;
	int indice;
public:
	VectSocio(int tamanio)
	{
		this->indice = 0;
		this->socio = new Socio * [tamanio];
		this->tamanio = tamanio;
	}
	Socio agregar(Socio* nuevsocio)
	{
		socio[indice] = nuevsocio;
		indice++;
	}
	void mostrar()
	{
		for (int i = 0;i < indice;i++)
		{
			socio[i]->mostrar();
			cout << "----------------------------------" << endl;
		}
	}
};