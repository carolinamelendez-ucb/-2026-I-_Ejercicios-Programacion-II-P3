#include <iostream>
#include <vector>

using namespace std;

// Ejercicio 1: Dado el arreglo de enteros, imprime los elementos pares
void ejercicio1() {
    cout << "=== Ejercicio 1 ===" << endl;

    int numeros[] = { 13, 22, 5, 8, 34, 55, 68 };
    int longitud = sizeof(numeros) / sizeof(numeros[0]);

    cout << "Arreglo original: ";
    for (int i = 0; i < longitud; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    cout << "Elementos pares: ";
    for (int i = 0; i < longitud; i++) {
        if (numeros[i] % 2 == 0) {
            cout << numeros[i] << " ";
        }
    }
    cout << endl << endl;
}

// Ejercicio 2: Fragmento de código que use un ciclo for para sumar todos los elementos de un arreglo
void ejercicio2() {
    cout << "=== Ejercicio 2 ===" << endl;

    int arreglo[] = { 2, 4, 6, 8, 10, 12, 14 };
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
    int suma = 0;

    cout << "Arreglo: ";
    for (int i = 0; i < longitud; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < longitud; i++) {
        suma += arreglo[i];
    }

    cout << "Suma de todos los elementos: " << suma << endl << endl;
}

// Ejercicio 3: Declara una matriz de 3x3 y llena sus valores con el número de la fila multiplicado por el número de la columna
void ejercicio3() {
    cout << "=== Ejercicio 3 ===" << endl;

    int matriz[3][3];

    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            matriz[fila][columna] = fila * columna;
        }
    }

    cout << "Matriz 3x3 (fila * columna):" << endl;
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            cout << matriz[fila][columna] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Ejercicio 4 : Función que recibe tres parámetros y filtra según flag
void ejercicio4() {
    cout << "=== Ejercicio 4 ===" << endl;

    vector<int> filtrarMultiplos(int arr[], int size, int num, bool flag);

    // Ejemplo 1: flag = true
    int arr1[] = { 1, 2, 3, 4, 5, 6, 8, 9 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int num1 = 3;
    bool flag1 = true;

    cout << "Ejemplo 1:" << endl;
    cout << "Arreglo: [";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i];
        if (i < size1 - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "num = " << num1 << ", flag = " << (flag1 ? "true" : "false") << endl;

    vector<int> resultado1 = filtrarMultiplos(arr1, size1, num1, flag1);

    cout << "Resultado: [";
    for (size_t i = 0; i < resultado1.size(); i++) {
        cout << resultado1[i];
        if (i < resultado1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // Ejemplo 2: flag = false
    int arr2[] = { 1, 2, 3, 4, 5, 6, 8, 9 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int num2 = 3;
    bool flag2 = false;

    cout << "\nEjemplo 2:" << endl;
    cout << "Arreglo: [";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i];
        if (i < size2 - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "num = " << num2 << ", flag = " << (flag2 ? "true" : "false") << endl;

    vector<int> resultado2 = filtrarMultiplos(arr2, size2, num2, flag2);

    cout << "Resultado: [";
    for (size_t i = 0; i < resultado2.size(); i++) {
        cout << resultado2[i];
        if (i < resultado2.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
}

vector<int> filtrarMultiplos(int arr[], int size, int num, bool flag) {
    vector<int> resultado;

    for (int i = 0; i < size; i++) {
        if (flag) {
            if (arr[i] % num == 0) {
                resultado.push_back(arr[i]);
            }
        }
        else {
            if (arr[i] % num != 0) {
                resultado.push_back(arr[i]);
            }
        }
    }

    return resultado;
}

int main() {

    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio4();

    return 0;
}