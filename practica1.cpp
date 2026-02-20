#include <iostream>
using namespace std;
//Ejercicio1
void ejercicio1() {
	int numeros[] = { 13,22,5,8,34,60};
	for (int i = 0; i <= 6; i++)
	{
		if (numeros[i] % 2 == 0) {
			cout << numeros[i] << " ";
		}
	}
}
//Ejercicio 2
void ejercicio2() {
	int numeros[] = { 1,2,3,4,5 };
	int suma = 0;
	for (int i = 0; i < 5; i++)
	{
		suma += numeros[i];
	}
	cout << "Resultado de la suma= " << suma << endl;;
}
int main()
{
	cout << "Resultado ejercicio 1" << endl;
	ejercicio1();
	cout << endl;
	cout << "Resultado ejercicio 2" << endl;
	ejercicio2();
}