// prueba.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
using namespace std;
/*Dado el siguiente arrego de enteros, imprime los elementos pares */
void Ejercicio_1()
{
    int numeros[] = { 13,22,5,8,34,55,60 };
    int tam=7;
    for (int pos = 0;pos < tam;pos++)
    {
        if (numeros[pos] % 2 == 0)
        {
            cout << "Los numero son: ";
            cout << numeros[pos]<<endl;
       }
    }

}
void Ejercicio_2()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int tam = 5;
    int suma = 0;
    for (int pos = 0;pos < tam;pos++)
    {
        suma = suma + arr[pos];
    }
    cout << "La suma es: " << suma << endl;
}
/*void Ejercicio_3()
{
int mat 

}
*/
int main()
{
    cout << "Ejercicio 1" << endl;
    Ejercicio_1();
    cout << "Ejercicio 2" << endl;
    Ejercicio_2();
}
