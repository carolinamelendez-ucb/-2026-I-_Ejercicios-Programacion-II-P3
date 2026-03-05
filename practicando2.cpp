// practicando2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "socio.h"
using namespace std;

int main()
{
	VectorSocios socios= VectorSocios(8) ;
	socios.mostrar();

}

/*void  primerSocio() {
		for (int i = 0;i < 6;i++) {
			piloto[i] = new Socio(100 + i, "Piloto", i);
		}
	}
	void  segundoSocio() {
		for (int i = 0;i < 6;i++) {
			copiloto[i] = new Socio(200 + i, "Copiloto", i);
		}
	
}
	VectorSocios() {
		primerSocio();
		segundoSocio();
	}
	void mostrar() {
		cout << "Pilotos" << endl;
		for (int i = 0;i < 6;i++) {
			piloto[i]->mostrar();
		}
		cout << "Copilotos" << endl;
		for (int i = 0;i < 6;i++) {
			copiloto[i]->mostrar();
		}
	}*/