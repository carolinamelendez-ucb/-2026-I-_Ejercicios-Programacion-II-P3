// Ejercicio_Clase.cpp 
// 10/02/26
//costructores-> Seidentifica a traves del tipo de datos y el orden de los 

#include <iostream>
#include <string>
using namespace std;

class Casa
{
private:
	int num_habitacion;
	int precio;
	string ubicacion;
	string material;
	bool disponible;

public:
	void setNum_habitacio(int nuevoNum_habitacion)
	{
		num_habitacion = nuevoNum_habitacion;
	}
	int getHabitaciones()
	{
		return num_habitacion;
	}
	string getDisponible()
	{
		if (disponible)
		{
			return "DISPONIBLE...";
		}
		else
		{
			return "NO DISPONIBLE...";
		}
	}
	int getPrecio()
	{
		return precio;
	}
	//CONSTRUXTOR 1
	Casa(int num_habintacion,int precio, string ubicacion)
	{
		this->num_habitacion = num_habintacion;
		this->precio = precio;
		this->ubicacion = ubicacion;
		this->material="";
	}
	//COSTRUNTOR 2
	Casa(int num_habintacion, string ubicacion)
	{
		this->num_habitacion = num_habintacion;
		this->precio = 0;
		this->ubicacion = ubicacion;
		this->material = "";
	}
	//CONSTRUCTOR 3
	Casa( int precio)
	{
		this->num_habitacion = 0;
		this->precio = precio;
		this->ubicacion = "";
		this->material = "";
	}
	//CONSTRUCTOR 3.2
	//Casa(string material)
	//{
	//	this->num_habitacion = 0;
	//	this->precio = 0;
	//	this->ubicacion = "";
	//	this->material = material;
	//}
	//CONSTRUCTOR 4
	Casa(string ubicacion)
	{
		this->num_habitacion = 0;
		this->precio = 0;
		this->ubicacion = ubicacion;
		this->material = "";
	}

	void mostrar()
	{
		cout << "Nro habitaciones: " << num_habitacion << endl;
		cout << "Precio: " << precio << endl;
		cout << "Ubicacion: " << ubicacion << endl;
		cout << endl;
	}

};

int main()
{
	Casa miCasa1 = Casa(8, 850, "Av. Libertador");
	cout << "-- PRECIO: " << miCasa1.getPrecio() << endl;
	cout << "-- HABITACIONES: " << miCasa1.getHabitaciones() << endl;

	if (miCasa1.getHabitaciones() >= 5)
	{
		cout << "La casa es grande..." << endl;
	}
	else
	{
		cout << "La casa es pequeña..." << endl;
	}

	if (miCasa1.getPrecio() > 1000)
	{
		cout << "Muy caro..." << endl;
	}
	else
	{
		cout << "Esta accesible..." << endl;
	}
	miCasa1.mostrar();

	Casa miCasa2 = Casa(5, "Av. America");
	miCasa2.mostrar();

	Casa miCasa3 = Casa("Av. Circunvalacion");
	miCasa3.mostrar();
   

}

