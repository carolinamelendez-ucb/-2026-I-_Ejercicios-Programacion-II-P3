#pragma once
#include"Equipo.cpp"
class VectEquipo {
private:
	Equipo** equipos;
	int tamanio;
	int indice;
public:
	VectEquipo(int tamanio) {
		this->indice = 0;
		this->equipos = new Equipo * [tamanio];
		this->tamanio = tamanio;
	}
	Equipo agregar(Equipo* nequipo)
	{
		equipos[indice] = nequipo;
		indice++;
	}
	void mostrar()
	{
		for (int i = 0;i < indice;i++)
		{
			equipos[i]->mostrar();
			cout << "----------------------------------" << endl;
		}
	}
};