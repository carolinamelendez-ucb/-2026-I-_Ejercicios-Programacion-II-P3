
#include <iostream>
using namespace std;
void ejercicio1(int vec[])
{
    for (int i = 0;i < 7;i++)
    {
        if (vec[i] % 2 == 0)
            cout << vec[i] << endl;
    }
}
void ejercicio2(int vec[], int n)
{
    int suma = 0;
    for (int i = 0;i < n; i++)
    {
        suma = suma + vec[i];
    }
    cout << suma << endl;
}
void ejercicio3(int vec[][3])
{
    for (int i = 0;i < 3; i++)
    {
        for (int j = 0;j < 3;j++)
    }
}
int main()
{
    int mat[3][3];
    int vec[7] = { 13,22,5,8,34,55,60 };
    ejercicio1(vec);
    ejercicio2(vec, 7);
}
