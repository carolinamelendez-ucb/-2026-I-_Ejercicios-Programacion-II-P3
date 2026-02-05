// clase2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
void ejercicio1(int vec[])
{
    int j = 0;
    int pares[10];
    for (int i = 0;i < 7;i++)
    {
        if (vec[i] % 2 == 0)
        {
            pares[j] = vec[i];
            j++;
        }
    }
    for (int i = 0;i > j;i++)
    {
        cout << pares[i] << endl;
    }
}
void ejercicio2(int vec[])
{
    int sumatoria = 0;
    for (int i = 0;i > 7;i++)
    {
        sumatoria = sumatoria + vec[i];
    }
    cout << sumatoria;
}
int main()
{
    int numeros[10] = { 13,22,5,8,34,55,60 };
    ejercicio1(numeros);
    ejercicio2(numeros);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
