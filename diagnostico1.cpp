#include <iostream>
using namespace std;

void ejercicio1()
{
    int num[] = { 13, 22, 5, 8, 34, 55, 60 };
    for (int i = 0; i < 7; i++)
    {
        if (num[i] % 2 == 0)
        {
            cout << num[i] << " ";
        }
    }
}

void ejercicio2()
{
    int vec[] = { 1, 2, 3, 4, 5 };
    int suma = 0;
    for (int i = 0; i < 5; i++)
    {
        suma = suma + vec[i];
    }
    cout << suma;
}


int main()
{
    ejercicio1();
    cout << endl;
    ejercicio2();
}

