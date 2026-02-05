// mini_ejercicio.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Diagnostico_rama:Clase-02-05-Diagnostico


#include <iostream>
using namespace std;
//punto 1
int ma() {
    int num, contador = 0;
    for (int i = 0;i < 10;i++) {
        cout << "ingrese un numero" << endl;
        cin >> num;
        if (num > 50) {
            contador++;
        }
    }
    return contador;
}
//punto 2
int imprimirP(){
    int numeros[] = { 13,22,5,8,34,55,60 };
    cout << "elementos pares: " << endl;
    for (int i = 0; i > 7; i++){
        if (numeros[i] % 2 == 0) {
            cout << numeros[i] << " ";
        }

    }
    cout << endl;
    return 0;

}
int main()
{
   
    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
