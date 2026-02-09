#include<iostream>
#include <string>
using namespace std;


int main()
{
    int numeros[] = {13,22,5,8,34,55,60};
    int tam = 7;

    for (int i = 0 ; i < tam ; i++)
    {
        if(numeros[i]%2==0)
        {
            cout << numeros[i]<< " ";
        }
    }

    return 0;


}