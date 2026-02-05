// prueba.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

void ejercicio1()
{
	int numeros[7]={13, 22, 5, 8, 34, 55, 60};
	for (int i = 0;i < 7;i++)
	{
		if (numeros[i] % 2 == 0)
		{
			cout << numeros[i] << " ";
		}
	}	
	cout << endl;
}
void ejercicio2()
{ 
	int numeros[7] = { 1, 2, 5, 3, 1, 1, 1 };
	int suma=0;
	for (int i = 0;i < 7;i++)
	{
		suma=suma+ numeros[i];
		
	}
	cout << suma << endl;
}
void ejercicio3()
{

	int matriz[3][3];
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			matriz[i][j] = i * j;
		}
	}

	//mostarr matriz
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout<< matriz[i][j];
		}
	}

}

int main()
{
	ejercicio1();
	ejercicio2();
	ejercicio3();
//ejercicio4();


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
