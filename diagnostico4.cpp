#include <iostream>
#include <string>

using namespace std;

int filtrador(int arr[], int tam , int num , bool flag , int resultado[])
{
    int tam_k;

    for (int i = 0 ; i < tam ; i ++)
    {
        if (flag && arr[i] % num == 0)
        {
            resultado[tam_k++] = arr[i];
        }
    }
    return tam_k;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int tamanio = 9;
    int num = 3;
    bool flag = true;
    int resultado[9];

    int tam = filtrador(arr,tamanio,num,flag,resultado);

    cout << " resultado  : " ;
    for (int i = 0 ; i < tam;i++)
    {
        cout << resultado[i]<< " " ;
    }

    return 0;
}