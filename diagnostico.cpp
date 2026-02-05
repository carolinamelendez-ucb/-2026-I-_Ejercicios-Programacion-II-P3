
#include <iostream>
#include <conio.h>
using namespace std;
void ejercicio1(int numeros[]) {
    for (int i = 0; i <= 6; i++) {
        if (numeros[i] % 2 == 0) {
            cout <<"Es par :" << numeros[i] << endl;
        }
    }
}
void ejercicio2(int cantidad, int arreglo[]) {
    int suma = 0;
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese los números :" << endl;
        cin >> arreglo[i];
        suma = suma + arreglo[i];
    }
    cout << "La suma total de todos los números es :" << suma << endl;
}
int main()
{
    int cantidad;
    int arreglo[100];
    int numeros[] = { 13, 22, 5, 8, 34, 55, 60 };
    ejercicio1(numeros);
    cout << "Ingrese la cantidad de números que desea ingresar y sumar :" << endl;
    cin >> cantidad;
    ejercicio2(cantidad, arreglo);
    return 0;

}
