#include <iostream>
#include <string>

using namespace std;

class Pedido
{
private:
    int codigo;
    string producto;
    int cantidad;
    int precioU;

public:
    Pedido(int codigoP,string productoP,int cantidadP,int precioP) { 
        codigo=codigoP;
        producto=productoP;
        cantidad=cantidadP;
        precioU=precioP;
    }

    void mostrar(int total)
    {
        cout << "DATOS DEL PEDIDO" << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio Unitario: " << precioU << endl;
        cout << "Total del pedido: " << total << endl;
        cout << endl;
    }

    void setCant(int nCantidad)
    {
        cantidad = nCantidad;
    }

    void setPrecio(int nPrecio)
    {
        precioU = nPrecio;
    }

    int calcularTotal(int precioP,int cantidadP)
    {
        int T;
        T=precioP*cantidadP;
        return T;
    }
};


int main()
{
    int C[2];
    int P[2];
    int Tot[2];

    Pedido P1 = Pedido (1,"Mantequilla",0,0);
    Pedido P2 = Pedido (2,"Sprite",0,0);

    for (int i = 0; i < 2; i++)
    {
        cout << "PEDIDO " << i + 1 << endl;

        cout << "Ingrese la cantidad: ";
        cin >> C[i];

        cout << "Ingrese el precio unitario: ";
        cin >> P[i];
    }

    P1.setCant(C[0]);
    P1.setPrecio(P[0]);
    P2.setCant(C[1]);
    P2.setPrecio(P[1]);

    Tot[0]=P1.calcularTotal(P[0],C[0]);
    Tot[1]=P2.calcularTotal(P[1],C[1]);

    P1.mostrar(Tot[0]);
    P2.mostrar(Tot[1]);

    cout << "Ingrese la nueva cantidad del primer pedido: ";
    cin >> C[0];
    P1.setCant(C[0]);

    Tot[0]=P1.calcularTotal(P[0],C[0]);

    P1.mostrar(Tot[0]);
    P2.mostrar(Tot[1]);
}