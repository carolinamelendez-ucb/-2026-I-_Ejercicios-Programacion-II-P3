#include <iostream>
#include <string>

using namespace std;

class Cuenta 
{
    private:
    string titular;
    int cantidad;


    public:

    Cuenta (string titular,int cantidad)
    {
        this -> titular = titular;
        this -> cantidad = cantidad;
    }
    Cuenta (string titular)
    {
        this -> titular = titular;
        this -> cantidad = 0;
    }

    void setCantidad(int nuevaCantidad)
    {
        this -> cantidad = nuevaCantidad;
    }

    int getCantidad()
    {
        return cantidad;
    }

    void setTitular(int nuevoTitular)
    {
        this ->titular= nuevoTitular;
    }
    string getTitular()
    {
        return titular;
    }

    void mostrar()
    {
        cout << " Titular : " << titular << endl;
        cout << " CANTIDAD : " << cantidad << endl;
    }

    void ingresar(int nuevaCantidad)
    {
        if(cantidad >=  0 )
        {
            cantidad+=nuevaCantidad;
        }
    }

    void retirar(int cantidadRetirada)
    {
        int restante = cantidad - cantidadRetirada;
        if (restante < 0)
        {
            this -> cantidad = 0 ;
        }
        cantidad= restante;
    }
};

int main()
{

    Cuenta cuenta1 = Cuenta("Jose Castro",1000);
    cuenta1.mostrar();
    cuenta1.ingresar(500);
    cuenta1.mostrar();
    cuenta1.retirar(400);
    cuenta1.mostrar();
    return 0;
}