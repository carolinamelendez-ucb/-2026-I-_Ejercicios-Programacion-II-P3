// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

void ejercicio1(int numeros[6])
{
    for (int i = 0;i < 7;i++)
    {
        if (numeros[i] % 2 == 0)
        {
            cout << numeros[i]<<endl;
        }
    }
}
void ejercicio2(int numeros[6])
{
    int aux = 0;
    for (int i = 0;i < 7;i++)
    {
        aux = aux + numeros[i];
    }
    cout << "la suma del array es: " << aux<<endl;
}
void ejercicio3((int mat[3][3])
{

}

void ejercicio4(int arr[], bool flag, int num)
{
    if (flag == true)
    {

    }
    else
    {

    }
}

int main()
{
    int numeros[] = { 13,22,5,8,34,55,60 };
    int mat[3][3];
    ejercicio1(numeros);
    ejercicio2(numeros);
    int mat[3][3];
    ejercicio3(mat);
    int arr[],num, tamanio;
    bool flag;
    cout << "ingrese el tamanio de la cadena: ";
    cin >> tamanio;
    for (int i = 0;i < tamanio;i++)
    {
        cout << i + 1 << "dato: ";
        cin >> arr[i];
    }
    cout << "ingrese un numero: ";
    cin >> num;
    cout << "ingrese 1 para true y 2 para false ";
    cin >> valor;
    if (valor == 1)
        flag = true;
    else
        flag = false;
    ejercicio4(arr,flag,num);
}
