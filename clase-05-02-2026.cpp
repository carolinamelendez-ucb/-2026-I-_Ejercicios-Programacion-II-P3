// clase-05-02-2026.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

void ejercicio1(int num[],int tam)
{
    int cont;
    cout << "numeros pares: ";
    for (int i = 0; i < tam; i++)
    {
        if (num[i] % 2 == 0)
        {
            cout << num[i] << " ";
        }
    }
}

int main()
{
    ejercicio1();
    int numeros[] = { 13,22,5,8,34,55,60 };
    int tam = 7;
    ejercicio1(numeros,tam);
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
