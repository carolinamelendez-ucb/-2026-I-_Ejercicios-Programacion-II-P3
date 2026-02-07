// Ejercicio Clase 2.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*Ejemplo - Cuenta Bancaria
            Atributos -->   - Saldo
                            - Nombre
                            - Numero de Cuenta
                            - Estado
                            - Tipo de Cuenta
            Metodos -->     - Deposito
                            - Retiro
                            - Consulta de Saldo
                            - Bloquear Cuenta
                            - 
*/

#include <iostream>
#include <string>
using namespace std;

class cuenta {
    private:
    int saldo;
    string nombre;
    int numeroCuenta;
    string Estado;
    string Tipo;

    public:
        cuenta(int saldo, string nombre, int numeroCuenta, string Estado, string Tipo) {
            this->saldo = saldo;
            this->nombre = nombre;
            this->numeroCuenta = numeroCuenta;
            this->Estado = Estado;
            this->Tipo = Tipo;
    }
        void mostrar() {
            cout << "Saldo: " << saldo << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Numero de cuenta: " << numeroCuenta << endl;
            cout << "Estado: " << Estado << endl;
            cout << "Tipo: " << Tipo << endl;
            }
        void setsaldo(int nuevosaldo) {
            this->saldo = nuevosaldo;
        }
};
int main()
{
    cuenta cuenta1 = cuenta (200,"Alan ", 56421, "Credito" , "Bs");
    cuenta1.mostrar();
    cuenta1.setsaldo(300);
    cuenta1.mostrar();


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
