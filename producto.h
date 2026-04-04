#pragma once
#include <iostream>
#include <string>
using namespace std;
class Producto {
	protected:
	float precioBase;
	string nombre;
	public:
	Producto(string nombre,float precio) {
	this->nombre=nombre;
	this->precioBase=precio;

	}
	virtual float calcularpreciofinal();
	string getNombre(){return nombre;}
	void mostrar() {
		cout<<"Nombre: "<<nombre<<endl;
		cout<<"Precio Final: "<<calcularpreciofinal()<<endl;

	}
	virtual ~Producto() {}
};
class ProductoFresco :public Producto {
private:

int diasRestantes;
public:
	ProductoFresco(string nombre, float precio,int dias): Producto(nombre,precio){
	this->diasRestantes=dias;

}
	float calcularpreciofinal() {
	int descuento;
		if (diasRestantes <= 20) {
		  descuento=precioBase-(precioBase*(1-(0,5*(7-diasRestantes))));
		}
		else {
			descuento=precioBase-(precioBase*0,3);
		}
		return descuento;
}
};
class ProductoEnvasado :public Producto {
	private:
		
	int pesoKG;
	public:
		ProductoEnvasado(int pesoKG, string nombre, float precio) : Producto(nombre, precio) {
			this->pesoKG=pesoKG;
	}
		float calcularpreciofinal() {
			int descuentoEnvasado;
		descuentoEnvasado=precioBase-(precioBase*1,10+(pesoKG*2));
		return descuentoEnvasado;
	}
};
class ProductoPromocional :public Producto {
	private:
	float desPromocion;
	int cantidad;
	public:
		ProductoPromocional(float desPromocion, int cantidad, string nombre, float precio) : Producto(nombre,precio){
		this->desPromocion=desPromocion;
		this->cantidad=cantidad;

	}
		float calcularpreciofinal() {
		int descuentoPromocional;
			if (cantidad >= 5) {
			 descuentoPromocional=precioBase-(precioBase*desPromocion)-(precioBase*0,5);
			}
			else {
				descuentoPromocional= precioBase - (precioBase * desPromocion);
			}
			return descuentoPromocional;
	}
};
class ProductoPremium :public ProductoEnvasado {
	private:
	float pesoKG;
	public:
		ProductoPremium(float pesoKG,float peso, string nombre, float precio) :ProductoEnvasado(peso, nombre, precio) {
		this->pesoKG=pesoKG;
	}
		float calcularpreciofinal() {
		int descuentoPremium;
		descuentoPremium=precioBase-ProductoEnvasado::calcularpreciofinal();

	}
};
