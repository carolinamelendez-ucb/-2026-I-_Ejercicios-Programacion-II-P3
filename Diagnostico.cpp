// Diagnostico.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#define TAM 50
using namespace std;

void ejer1() {
    int a[7] = { 13,22,5,8,34,55,60 };
    for (int i = 0;i < 7;i++) {
        if (a[i]% 2 == 0) {
            cout << a[i] << " ";
        }

    }
}
void ejer2() {
    int a[7] = { 13,22,5,8,34,55,60 };
    int aux = 0;
    for (int i = 0;i < 7;i++) {
        aux += a[i];
       
    }

}

void ejer3(int v[TAM][TAM]) {
    
    for (int i= 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            v[i][j] = (i+1) * (j+1);
            cout << v[i][j] << " ";
            
        }
    }
    
}
void ejer4() {


}
int main()
{
    int v[TAM][TAM];
    
    ejer1();
    ejer2();
    ejer3(v);
    ejer4

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
