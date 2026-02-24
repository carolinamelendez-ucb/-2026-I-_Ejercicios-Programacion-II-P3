// DaniaCano_240226.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//paso por valor ---->copia la vatiable en una nueva posicion de memoria (CAMBIA POR UNANUEVA DIRECCION DE MEMMORIA)
//Paso por referencia ---> se envia la pos de memoria para editar su valor DIRECTO (SE MANTIENE ES ESPACIO DE MEMMORIA)

/*
* int main()
{
	int y = 10;
	duplicar(y);
	cout << "dir d ememoria de y: " << &y<< endl; // direccion de memoria de y
	cout << "valor de y: " << y << endl; //valor de y=10
	//
	int *yPtr = &y;  //asi giardamos la direccion de memoria
	//IMPORTANTE, PREGUNTA DE EXAMEN
	cout << "valor de yPtr: " << yPtr << endl; // direccion de memoria de y
	cout << "valor de yPtr: " << *yPtr << endl; //valor =20 // el * no aydua a saber q hay ene sa direccion de memoria
	cout << "valor de yPtr: " << &yPtr << endl;//direccion de memoria de yPtr
}
*/
#include <iostream>
using namespace std;

void duplicar(int valor) {
	valor=valor*2;
}
class Alumno {
private:
	string nombre;
	int ci;
public:
	Alumno(string nombre, int ci)
	{
		this->nombre = nombre;
		this->ci = ci;
	}
};

int main()
{
	//TAREA 1. Investigar cual es la diferncia de implementar objetos con/sin punteros
	// ventaja, y Desventajas.....
	//sin punteros
	Alumno camilo = Alumno("camilo", 234);
	//con puntero
	Alumno *daniela = new Alumno("daniela", 456);   //añadir un * y un new
	//En examen habra reuntas tipo:criterios: es adecuado usar punteros? o no? entrara croiterio propio. 
	
}

