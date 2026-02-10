// Practica 2 Programacion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Cuenta{
    private:
        string titular;
        int cantidad;
    public:
    Cuenta (string titular, int cantidad){
         this->titular=titular;
         this->cantidad=cantidad;
        }
    Cuenta (string titular){
        this->titular=titular;
        this->cantidad=0;
    }
    void setCantidad (int nuevaC){
        this->cantidad=nuevaC;
    }
    int getCantidad (){
        return cantidad;
    }
    void setTitular (string nuevoT){
        this->titular=nuevoT;
    }
    string getTitular (){
        return titular;
    }
    void mostrar (){
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
    void ingresar (int cantidadIngresada){
        if(cantidadIngresada >= 0){
            cantidad=cantidad + cantidadIngresada;
        }

    }
    void retirar (int cantidadRetirada){
        int restante= cantidad - cantidadRetirada;
        if(restante < 0){
            this-> cantidad = 0;
        }
        else{
        this->cantidad = restante;
        }
    }
};

int main()
{
   Cuenta cuenta1 = Cuenta("alan" , 200);
   Cuenta cuenta2 = Cuenta("fabian");
   cuenta1.mostrar();
   cuenta2.mostrar();
   cuenta2.setCantidad(200);
   cuenta2.mostrar();
   cuenta1.ingresar(100);
   cuenta2.retirar(210);
   cuenta1.mostrar ();
   cuenta2.mostrar ();
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
