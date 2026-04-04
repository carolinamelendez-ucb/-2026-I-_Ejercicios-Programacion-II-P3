#pragma once
#include <iostream>
#include<string>
using namespace std;
class Producto {
protected:
	string nombre;
	float precio;
public:
	Producto(const string& nombre, float precio)
		: nombre(nombre), precio(precio)
	{
	}
	virtual float calcularPrecioFinal() = 0;
	string getNombre() {
		return nombre;
	}
	virtual void mostrar() {
		cout << nombre << "precio final: " << calcularPrecioFinal() << endl;
	}
	virtual ~Producto(){}
};
class ProductoFresco :public Producto {
private:
	int diasRestantes;
public:
	ProductoFresco(string nom,float precio ,int diasRestantes)
		: Producto(nom,precio),diasRestantes(diasRestantes)
	{
	}
	float calcularPrecioFinal() {
		float descuento = 0.05 * (7 - diasRestantes);
		if (descuento > 0.3) descuento = 0.3;
		if (descuento < 0) descuento = 0;

		return precio * (1 - descuento);
	}

};
class ProductoEnvasado :public Producto {
private:
	float pesokg;
public:
	ProductoEnvasado(string nom, float precio, float kg)
		: Producto(nom, precio), pesokg(kg)
	{
	}
	float calcularPrecioFinal() {
		return precio * 1.10 + (pesokg * 2);

	}
};
class ProductoPromocional :public Producto {
private:
	float decuentoProm;
	int cantidad;
public:
	ProductoPromocional(string nom, float precio, float promocion,int cantidad)
		: Producto(nom, precio), decuentoProm(promocion),cantidad(cantidad)
	{
	}
	float calcularPrecioFinal() {
		float extra =(cantidad > 5)?(precio * 0.05):0;
		return precio - decuentoProm - extra;
		
	}
};
class ProductoPremiun :public ProductoEnvasado {
private:
	float pesokg;
public:
	ProductoPremiun(string nom, float precio, float kg,float peso)
		: ProductoEnvasado(nom, precio,peso), pesokg(kg)
	{
	}
	float calcularPrecioFinal() {
		float base = ProductoEnvasado::calcularPrecioFinal();
		return base * 1.15;
	}
};