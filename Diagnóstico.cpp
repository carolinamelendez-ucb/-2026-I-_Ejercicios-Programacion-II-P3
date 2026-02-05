#include <iostream>
using namespace std;
void ejercicio1(int vec[]) {
    for (int i = 0;i < 6;i++) {
        if (vec[i] % 2 != 0) {
            cout<<vec[i];
        }
    }
}

int ejercicio2(int vec[]) {
    int suma = 0;
    for (int i = 0;i < 6;i++) {
        suma = suma + vec[i];
    }
    return suma;
    cout << "La suma de los valores enteros son " << suma << endl;
}

int main()
{
    int vec[7] = { 13, 22, 5, 8, 34, 55, 60 };
    int suma;
    ejercicio1(vec);
    ejercicio2(vec);

}

