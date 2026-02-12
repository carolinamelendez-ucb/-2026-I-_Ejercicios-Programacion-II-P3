// Ejercicio de clase 02-12.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;
const int MAYOR_DE_EDAD = 18;
class Carrera
{
private:
	string nombre;
	int duracion;
	int cupoDisponible;
public:
	Carrera()
	{
		nombre = "";
		duracion = 0;
		cupoDisponible = 0;
	}
	Carrera(string nombre, int duracion, int cupoDisponible)
	{
		this->nombre = nombre;
		this->duracion = duracion;
		this->cupoDisponible = cupoDisponible;
	}

};
class Estudiante
{
private:
	string nombre;
	int edad;
	Carrera carrera;
public:
	Estudiante(string nombre, int edad, Carrera carrera)
	{
		this->nombre = nombre;
		this->edad = edad;
		this->carrera = carrera;
	}
	/*
	bool puedeInscribirse()
	{
		
		if(edad=>MAYOR_DE_EDAD)
		{
		return true;
		cout << "Si hay cupo  disponible" << endl;
		}
	}
	*/

};

int main()
{
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
