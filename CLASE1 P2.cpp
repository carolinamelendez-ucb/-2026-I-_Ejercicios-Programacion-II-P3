// CLASE1 P2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;
class casa
{
private:
	int habitaciones;
	int precio;
	string ubicacion;
public:
	//SOBRECARGA DE CONSTRUCTORES
	// TENER EL MISMO TIPO DE DATO Y ORDEN PUEDE AFECTAR AL MAIN A IDENTIFICAR, SOLUCION CAMBIAR EL ORDEN
	//FIRMA DE UN METODO:TIPO DE RETORNO,TIPO DE INGRESO,ORDEN DE ARGUMENTOS Y NOMBRE DE METODOS
	casa(int habitaciones, int precio,string ubicacion)
	{
		this->habitaciones = habitaciones;
		this->precio = precio;
		this->ubicacion = ubicacion;
	}
	casa(int habitaciones, string ubicacion)
	{
		this->habitaciones = habitaciones;
		this->precio =0;
		this->ubicacion = ubicacion;
	}
	casa(string ubicacion)
	{
		this->habitaciones =0;
		this->precio = 0;
		this->ubicacion = ubicacion;
	}
	void mostrar()
	{
		cout << habitaciones << endl;
		cout << precio << endl;
		cout << ubicacion << endl;
		cout << endl;
	}
	int getHabitaciones()
	{
		return habitaciones;
	}
	int getprecio()
	{
		return precio;
	}
};
class cuenta
{
private:
	string titular;
	int cantidad;
public:
	cuenta(string titular,int cantidad)
	{
		this->titular = titular;
		this->cantidad = cantidad;
	}
	cuenta(string titular)
	{
		this->titular = titular;
		this->cantidad = 0;
	}
	void set(int nuevacantidad)
	{
		this->cantidad = nuevacantidad;
	}
	int getCntidad()
	{
		return cantidad;
	}
	void setTitular(int nuevoTitular)
	{
		this->titular = nuevoTitular;
	}
	string getTitular()
	{
		return titular;
	}
	void mostrar()
	{
		cout <<titular << endl;
		cout << cantidad << endl;
		cout << endl;
	}
	void ingresar(int canIngresada)
	{
		if (canIngresada >= 0)
		{
			cantidad = cantidad + canIngresada;
		}
	}
	void retirar(int retirada)
	{
		int restante = cantidad - retirada;
		if (restante < 0)
		{
			cantidad = 0;
		}
	}
};
int main()
{
	//constructor 1
	cuenta cuenta1("joel delgado",500);
	cuenta1.mostrar();
	//constructor 2
	cuenta cuenta2("dilan crespo");
	cuenta2.mostrar();

	//usando sets
	cuenta2.set(100);
	cuenta2.mostrar();

	//ingresar y retirar
	cuenta1.retirar(300);
	cuenta1.mostrar(); 

		cuenta2.ingresar(300);
		cuenta2.mostrar();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
