#include <iostream>

using namespace std;

void ejercicio1()
{
    int v[7] = {13,22,5,8,34,55,60};

    for (int i = 0;i != 7;i++)
    {
        if (v[i] % 2 == 0)
        {
            cout << v[i] << " " << endl;
        }
    }
}

void ejercicio2()
{
    int s = 0;
    int v[7] = {13, 22, 5, 8, 34, 55, 60};
    for (int i = 0;i != 7;i++)
    {
        s += v[i];
    }
    cout << s << endl;
}

void ejercicio3()
{
    int m[3][3];
    for (int i = 0;i != 3;i++)
    {
        for (int j = 0;j != 3;j++)
        {
            m[i][j] = (i + 1) * (j + 1);
            cout << "[" << i << "] [" << j << "]=" << m[i][j] << endl;
        }
    }
}



void ejercicio4()
{
    int vec[9];
    int num,op;
    bool flag;
    cout << "Ingrese 9 numeros para el array: " << endl;

    for (int i = 0;i < 10;i++)
    {
        cin >> vec[i];
    }

    cout << "Ingrese un numero: " << endl;
    cin >> num;

    cout << "Escriba 1 para true en el bool, 0 para false: ";
    cin >> op;

    if (op == 1)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }

}

int main()
{
    cout << "Hello World!" << endl;
    cout << "EJERCICIO 1" << endl;
    ejercicio1();
    cout << "EJERCICIO 2" << endl;
    ejercicio2();
    cout << "EJERCICIO 3" << endl;
    ejercicio3();
    cout << "EJERCICIO 4" << endl;
    ejercicio4();
}