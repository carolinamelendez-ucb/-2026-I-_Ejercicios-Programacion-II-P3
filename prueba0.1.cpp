// prueba0.1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
///parte1
void parte1(int v[7], int n,int vec[],int &k){
    int k = 0;
    for (int i = 0; i <= n; i++) {
        if (v[i] % 2 == 0) {
            vec[k] = v[i];
            k++;
        }
    }
}
void mostrar(int vec[], int n) {
    for(int i=0;i<=n;i++){
        cout << vec[i] << "|";
    }
}
///parte2
int mar(vec[], int n, ) {
    int j = 0;
    for (int i = 0;i <= n;i++) {
        j = vec[i] + j;
    }
    return j;
}
///
int main()
{
    int vec[]= { 13,22,5,8,34,55,60 };
    int v[];
    int j;
    parte1(vec, 7, v, j);
    mostrar(v, j);
int v= mar(vec, 7);
cout << "El resultado de la suma de todo un vector es:" << v << endl;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
