// Simulacro Progra II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//diagnositoc

#include <iostream>
#include <string.h>

using namespace std;

void Ejercicio1() {
	int n[] = { 13,22,5,8,34,55,60 };
	int tam = 7;
	cout<<"Ejercicio 1"<<endl;
	for (int i = 0;i < tam;i++) {
		if (n[i] % 2 == 0) {
			cout << n[i] << " ";
		}
	}
	cout<<endl;
}

void Ejercicio2() {
	int n[] = { 1,2,3,4,3,2,1 };  //Suma 16
	int tam = 7;
	int sum = 0;
	cout<<"Ejercicio 2"<<endl;
	for (int i = 0;i < tam;i++) {
		sum = sum + n[i];
	}
	cout << sum << endl;
}
/*
void Ejercicio3() {
	int m[][]={(3,2,1),(3,2,1),(3,2,1)};
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {

		}
	}

}

void Ejercicio4() {
	int n[]={1,2,3,4,5,6,8,9};
	int num=3;
	int vec[];
	bool flag;
	int n;
	cout<<"1 si quiere pares y 2 impares";
	cin>>flag;
	if (flag) {
		for (int i = 0;i < 8 < i++) {
			if (n[i] % num == 0) {
				
			}
		}

	}
}
*/

int main()
{
	Ejercicio1();
	Ejercicio2();
	//Ejercicio3();
	//Ejercicio4();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
