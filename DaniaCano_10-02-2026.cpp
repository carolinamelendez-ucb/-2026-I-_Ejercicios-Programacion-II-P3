// DaniaCano_10-02-2026.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*  TRABAJO DE CLASE
#include <iostream>
using namespace std;
class Casa {
private:
    int Nhabi;
    int precio;
    string ubicacion;
    string material;
    bool estaDisponible;
public:
    void setNhabi(int NuevoNhabi)
    {
        if (NuevoNhabi >= 1) {
            Nhabi = NuevoNhabi;
        }
        //no es bueno mostrar cout a menos que sea en mostarr
        //else
        //{
         //  cout << "nUMERO DE ABITACIONES INVALIDO" << NuevoNhabi << endl;}
    }



    //para decolver el valor
    int getNhabi() {
        return Nhabi;
    }
    int getPrecio() {
        return precio;
    }
    string getDisponibilidad() {
        if (estaDisponible) {
            return "Dosponible";
        }return "NO Disponible";
    }

    int gethabitaciones() {
        return Nhabi;
    }


//contructor 1
Casa(int Nhabi, int precio, string  ubicacion)
{
    this->Nhabi = Nhabi;
    this->precio = precio;
    this->ubicacion = ubicacion;
    this->material = "";
}
//contructor 2
Casa(int Nhabi, string  ubicacion)
{
    this->Nhabi= Nhabi;
    this->precio = 0;
    this->ubicacion = ubicacion;
    this->material = "";
}

//constructor 3.1
Casa(string  material)
{
    this->Nhabi = 0;
    this->precio = 0;
    this->ubicacion = "";
    this->material = material;
}
//constructor 3.2
//Casa(string  ubicacion){
 //   this->Nhabi = 0;
  //  this->precio = 0;
 //   this->ubicacion = ubicacion;
  //  this->material = "";}

//contructor 4

Casa(int precio)
{
    this->Nhabi = 0;
    this->precio = 0;
    this->ubicacion = ubicacion;
    this->material = "";
}

void mostrar()
{
    cout << "Numero de habitaciones: " <<Nhabi<< endl;
    cout << "Precio: " << precio << endl;
    cout << "Ubicacion: " << ubicacion<< endl;
    cout << endl;
}

};
int main()
{
    Casa micasa1 = Casa(20, 850, "Av. Libertador");
    cout << "precio: " << micasa.getPrecio() << endl;
    if (micasa1.getPrecio() > 1000)
    {
        cout << "muy caro" < endl;
    }
    else
    {
        cout << "es accesible" << endl;
    }
    cout << "Habitaciones" << micasa1.gethabitaciones() << endl;
    if (micasa1.gethabitaciones() > 10)
    {
        cout << "La casa es grande" < endl;
    }
    else
    {
        cout << "La casa es pequeña" << endl;
    }

    //Casa micasa2 = Casa(5, "Av. Circunvalacion");
    //micasa2.mostrar();

    //Casa micasa3 = Casa("Av. Libertador");
    //micasa3.mostrar();


}


*/

//EJERCICIO 1

#include <iostream>
using namespace std;

class Cuenta {
private
    string titular;
    int cantidad;
public

Cuenta(string titular)
{
    this->titular = titular;
    this->cantidad = 0
}
Cuenta( string titular,int cantidad)
{
    this->cantidad = cantidad;
    this->titular = titular;
}
string getTitular()
{
    return titular;
}
int getCantidad()
{
    return cantidad;
}

void settitular(strint titular)
{
    this->titular = titular;
}
void setcantidad(int cantidad)
{
    this->cantidad = cantidad;
}
void mostrar()
{
    cout << "TITULAR: " << titular << endl;
    cout << "CANTIDAD: " << cantidad<< endl;
}
vod ingresar(int cantidad)
{
    if (cantidad >= 0) {
        this->cantidad=cantidad
    }
}
void retirar(int cantidad)
{
    int restante = this->cantidad - cantidad;
}

int main
{


}
