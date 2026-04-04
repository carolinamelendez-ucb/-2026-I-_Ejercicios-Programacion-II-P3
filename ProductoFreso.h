#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

class ProductoFresco : public Producto {
private:
	int diasRestantes;
public:
	ProductoFresco(string nom, double prB, int diaR)
		: Producto(nom, prB), diasRestantes(diaR) {
	}

	double calcularPrecioFinal()override {
		int diasParaDescuento = max(0, 7 - diasRestantes);
		double descuento = precioBase * (1 - min(0.05 * (7 - diasRestantes), 0.3));
	}

	void mostrarInfo(){
		cout << "Producto Fresco: "<<nombre 
			<<"Precio base: $"<<precioBase 
			<<"Dias Restantes: "<<diasRestantes
			<<"Precio Final: $"<<calcularPrecioFinal() << endl;
	}

};

