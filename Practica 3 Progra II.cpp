// Practica 3 Progra II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Cliente{
private:
    string nombre;
    string tipo;
    int antiguedad;
public:
    Cliente (){
        nombre="";
        tipo="";
        antiguedad=0;
    }
    Cliente (string nombre, string tipo, int antiguedad){
        this->nombre=nombre;
        this->tipo=tipo;
        this->antiguedad=antiguedad;
    }

    string getTipo (){
        return tipo;
    }

    int getAntiguedad (){
        return antiguedad;
    }
};

class Factura{
 private:
    int numero;
    int monto;
    Cliente cliente;
public:
    Factura (int numero, int monto, Cliente cliente){
        this->numero=numero;
        this->monto=monto;
        this->cliente=cliente;
        }
    bool esPropietarioValido (){
        string tipoPropietario =  cliente.getTipo();
        return tipoPropietario == "Frecuente";
    }

    bool esAntiguo (){
        int antiguo = cliente.getAntiguedad();
        return antiguo >=2;
    }
    void setMonto (int montonuevo){
        this->monto = montonuevo;
    }
    int getMonto (){
        return monto;
    }

    void aplicarDescuento (){
       if(esPropietarioValido ()){
            if(esAntiguo ()){
              int montonuevo= monto-(monto*0.10);
              setMonto(montonuevo);
            }
        }
    }
    void mostrar (){
        cout << numero <<endl;
        cout << monto << endl;
    }
};

void Ejercicio2 (){
    Cliente cliente1 = Cliente("alan","Frecuente",3);
    Factura factura1 = Factura(234,100,cliente1);
    factura1.mostrar();
    factura1.aplicarDescuento();
    cout<<endl;
    factura1.mostrar();

}

int main()
{
    Ejercicio2();
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
