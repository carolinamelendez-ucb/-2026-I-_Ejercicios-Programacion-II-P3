// Diagnostico_fsf.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include <iostream>
using namespace std;
#define TAM 50

void ejercicio1(int v[TAM], int cant, int vf[TAM]);
{
    for (int i = 0;i < cant;i++) {
        if (v[i] % 2 == 0) {
            vf[i] = v[i];
        }
    }
}

void ejercicio2(int v2[TAM], int cant, int total);
{
    cout << "Digite sus nums: ";
    for (int i = 0;i < cant;i++) {
        cin >> v2[i];
    }
    for (i = 0;i < cant;i++) {
        total = v2[i]++;
    }}

void ejercicio3(int mat[TAM][TAM], int cantidad);
{
    for (int f = 0;f < cantidad;f++) {
        for (int c = 0;c < cantidad;c++) {
            
        }
    }
}


int main(){
    int vec1=[13,22,5,8,34,55,60], vecf[TAM], vec2[TAM];
  
    //EJR 1:
    ejercicio1(vec1, 50, vecf);
    //EJR 2:
    //ejercicio2();
    
}


