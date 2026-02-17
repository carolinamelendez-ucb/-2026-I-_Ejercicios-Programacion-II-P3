// EJERCICIO_Clase1202.cpp 
// 12/02/26

/*#include <iostream>
#include <string>
using namespace std;

const int MAYOR_DE_EDAD=18;

class Propietario
{
private:
	string nombre;
	int DNI;
	int edad;
public:
	Propietario(string nombre, int DNI, int edad)
	{
		this->nombre = nombre;
		this->DNI = DNI;
		this->edad = edad;
	}
	void getEdad()
	{
		return edad;
	}

};

class Casa
{
private:
	string direccion;
	int precio;
	Propietario propietario;
public:
	Casa(string direccion, int precio, Propietario propietario)
	{
		this->direccion = direccion;
		this->precio = precio;
		this->propietario = propietario;
	}

	bool esPropietarioValido()
	{
		int edadPropietario = propietario.getEdad();
		return edadPropietario >= MAYOR_DE_EDAD;
	}
	void mostrarTitularidadValida()
	{
		if (esPropietarioValido())
		{
			cout << "La titularidad es valida..." << endl;
		}
		else
		{
			cout << "La titularidad NO es valida..." << endl;
		}
	}
};

void ejercicio4()
{
	Propietario p1 = Propietario("Miguel", 123, 25);
	Casa casa1 = Casa("Av. Libertador", 250, p1);
	casa1.mostrarTitularidadValida();
}

int main()
{
	ejercicio4();

	return 0;
   
}*/

#include <iostream>
#include <string>
using namespace std;

class Autor
{
private:
	string nombre;
	string nacionalidad;
	int cant_Libros;

public:
	Autor(string nombre, string nacionalidad, int cant_Libros)
	{
		this->nombre = nombre;
		this->nacionalidad = nacionalidad;
		this->cant_Libros = cant_Libros;
	}
};

int getCant_Libros()
{
	return cant_Libros;
}

class Libro
{
private:
	string titulo;
	float precio;
	Autor autor;

public:
	Libro(string titulo, float precio, Autor autor)
	{
		this->titulo = titulo;
		this->precio=precio;
		this->autor = autor;
	}
	bool esBestSeller()
	{
		int cantidad = autor.getCant_Libros();
			return cantidad >= 5;

	}
	void mostrar()
	{
		cout << "Titulo: " << titulo << endl;
		cout<<"Precio: "<<precio<<endl; 
		cout << "Autor:" << autor << endl;

	}


};

int main()
{
	Autor a1 = Autor("Juan","bolibiana",7);

	Libro l1 = Libro("Cumbres borrascosas",48.99,a1);
	l1.mostrar();
		



}

