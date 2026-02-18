
#include <iostream>
#include<conio.h>
#include <string>
using namespace std;
class Cajero {
private:
    int saldo;
    string nombre;
    int pedidos;
    int precio;
    int total;
public:
    Cajero(int saldo, string nombre, int pedidos, int precio, int total) {
        this->saldo = 0;
        this->nombre = "";
        this->pedidos = 0;
        this->precio = 0;
        this->total = 0;
    }
    void verificadorypedir() {
        int mayor = 0;
        cout << "Ingrese la cantidad de pedidos que desea realizar :" << endl;
        cin >> pedidos;
        cout << "Ingrese el monto de dinero que desea gastar :" << endl;
        cin >> saldo;
        for (int i = 0; i < pedidos;i++) {
            cout << "Ingrese el costo del producto a llevar :" << endl;
            cin >> precio;
            if (precio>mayor) {
                mayor = precio;
            }
            saldo = saldo - precio;
            if (saldo < 0) {
                cout << "No le queda suficiente saldo" << endl;
                cout << "Le faltan :" << saldo*-1 <<"Bs"<< endl;
            }
            else{
                cout << "Pedido realizado correctamente" << endl;
            }
            total = total + precio;
        }
        cout << "El pedido con mayor valor es :" <<mayor<< "Bs" << endl;
    }
};
int main()
{
    int clientes;
    Cajero cajero(0,"",0,0,0);
    cout << "Cuantos clientes habrá?" << endl;
    cin >> clientes;
    for (int i = 0; i < clientes; i++) {
        cajero.verificadorypedir();
    }
    return 0;
}
