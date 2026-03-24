#include <iostream>
#include <string>
using namespace std;
class Empleado {
protected:
	string nombre;
	float salario;
	string departamento;
public:
	Empleado(const string& nombre, float salario, const string& departamento)
		: nombre(nombre), salario(1000), departamento(departamento)
	{
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Salario: " << salario << endl;
		cout << "Departamento" << departamento << endl;
	}
	void calcularSlario() {
		salario = 1000 + 5500;
	}
};
class EmpleadoPlanta : public Empleado{
private:
	float salarioExtra;
public:


	EmpleadoPlanta(float salarioExtra): 
		Empleado(nombre,salario,departamento)
	{
		this->salarioExtra = salarioExtra;
	}
	void calcularSalario() {
		
	}
	void mostrar() {
		Empleado::mostrar();
		cout << "Salario: " << salarioExtra;
	}
};

class Contratista : public Empleado {
private:
	int diasTrabajados;
public:

	Contratista(int diasTrabajados)
		: Empleado(nombre, salario,departamento)
	{

	}
	void mostrar() {
		Empleado::mostrar();
		cout << "Dias trabajados: " << diasTrabajados;
	}
};
class Ejecutivo : public Empleado {
private:

public:

};
int main()
{
   
}