// Prueba1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

// 1
void Ejercicio1() {
    int numeros[] = { 13, 22, 5, 8, 34, 55, 60 };
    int n = sizeof(numeros) / sizeof(numeros[0]);

    cout << "Elementos pares: ";
    for (int i = 0; i < n; i++) {
        if (numeros[i] % 2 == 0)
            cout << numeros[i] << " ";
    }
    cout << endl;
}

// 2
void Ejercicio2() {
    int arr[] = { 10, 20, 30, 40, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int suma = 0;

    for (int i = 0; i < n; i++)
        suma += arr[i];

    cout << "Suma del arreglo: " << suma << endl;
}

// 3
void Ejercicio3() {
    int matriz[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = (i + 1) * (j + 1);
        }
    }

    cout << "Matriz 3x3 (fila*columna):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

// 4
void Ejercicio4(int vec[], int n, int num, bool flag) {
    cout << "Resultado: ";
    for (int i = 0; i < n; i++) {
        if (flag && vec[i] % num == 0)
            cout << vec[i] << " ";
        else if (!flag && vec[i] % num != 0)
            cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    Ejercicio1();
    Ejercicio2();
    Ejercicio3();

    int arr[] = { 1,2,3,4,5,6,8,9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Ejercicio4(arr, n, 3, true);

    return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
