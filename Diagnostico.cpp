#include <iostream>

using namespace std;

void ejercicio1()
{
    int num[7] = { 13,22,5,8,34,55,60 };
    for (int i = 0;i < 7;i++)
    {
        if (num[i] % 2 == 0)
        {
            cout << num[i] << " ";
        }
    }
    cout << endl;
}

void ejercicio2(int num[],int t)
{
    int suma=0;
    for (int i = 0;i < t;i++)
    {
        suma += num[i];
    }
    cout << "La suma de los numero es: " << suma<<endl;
}

void ejercicio3()
{
    int arr[3][3];
}

void ejercicio4(int arr[],int num,bool flag,int t)
{
    int res[7];
    int cont=-1;
    if (flag)
    {
        for (int i= 0;i < t;i++)
        {
            if (arr[i] % num == 0)
            {
                cont += 1;
                res[cont] = arr[i];
            }
        }
    }
    else
    {
        for (int i = 0;i < t;i++)
        {
            if (arr[i] % num != 0)
            {
                cont += 1;
                res[cont] = arr[i];
            }
        }
    }
    cout << "El resultado es: ";
    for (int i = 0;i < cont;i++)
    {
        cout << res[i] << " ";
    }
}

int main()
{
    int num[7] = { 13,22,5,8,34,55,60 };
    ejercicio1();
    ejercicio2(num, 7);
    ejercicio4(num, 3, true, 7);
}
