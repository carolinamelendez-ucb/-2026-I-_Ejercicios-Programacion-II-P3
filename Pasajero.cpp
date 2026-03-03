#include<iostream>
#include<string>
using namespace std;
class Pasajero {
private:
	int ci;
	string nombre;
	int numAsiento;
public:
	Pasajero(string nombre, int ci)
	{
		this->ci = ci;
		this->nombre = nombre;
		this->numAsiento = 0;
	}
	void asignarAsiento(int numero)
	{
		this->numAsiento = numero;
	}
};