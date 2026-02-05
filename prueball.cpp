#include <iostream>
using namespace std;

void ejercicio1(int numeros[], int n) {

    for (int i = 0; i < n; i++) {
        if (numeros[i] % 2 == 0) {
            cout << numeros[i] << " ";
        }
    }
}

void ejercicio2(int numeros[], int n) {

    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma = suma + numeros[i];
    }

    cout << suma;
}

int main()
{
    int numeros[7] = { 13,22,5,8,34,55,60 };

    cout << "numeros pares " << endl;
    ejercicio1(numeros, 7);

    cout << endl << "numeros sumados " << endl;
    ejercicio2(numeros, 7);

    return 0;
}

