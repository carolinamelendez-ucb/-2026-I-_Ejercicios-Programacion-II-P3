
//Nelly Ayza
#include <iostream>
using namespace std;

void ejercicio1(int v[])
{
    cout << "numeros pares del vector: ";
    for (int i = 0;i < 7;i++)
    {
        if (v[i] % 2 == 0)
        {
            cout << v[i] << " ";
        }
    }
   
}

void ejercicio2(int vec[])
{
    int total = 0;
    for (int i = 0;i < 7;i++)
    {
        total += vec[i];
    }
    cout << "El total de la suma del vector es: " << total << endl;

}
void mostrarmat(int m[3][3])
{

    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            cout << "matriz [" << i << "][" << j << "]: " << m[i][j] << endl;
        }
    }
}
void ejercicio3(int m[3][3])
{
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            m[i][j] = i * j;
        }
    }

    mostrarmat(m);

}

int main()
{
    int numeros[] = {13,22,5,8,34,55,60};
    int matriz[3][3] = { 0 };

    cout << "- EJERCICIO 1 -" << endl;
    ejercicio1(numeros);
    cout << "\n- EJERCICIO 2 -" << endl;
    ejercicio2(numeros);
    cout << "\n- EJERCICIO 3 -" << endl;
    ejercicio3(matriz);
    //ejercicio4();
}


