

#include <iostream>
#include <string>
using namespace std;

/*
En la clase anterior hicimos:
Atributos y metodos
contructor  ->   inicializar los atributos 
setter  ->  Modificar el valor dl atributos, 1 a la vez
this    -> especificador
Modificadores: private, public, protected
*/

/*Hoy veremos la sobrecarga de Constructores*/
/*
class Casa{
private:
    int numHabitaciones;
    string ubicacion;
    int precio;
public:

    Casa(int NroHabitaciones, int precioS, string ubicacionS) {
        this->numHabitaciones = NroHabitaciones;
        this->precio = precioS;
        this->ubicacion = ubicacionS;
    }

    void mostrar() {
        cout << "Nro Habitaciones: "<<numHabitaciones << endl;
        cout << "Precio $: "<<precio << endl;
        cout << "Ubicacion:"<<ubicacion<<endl;
    }

    void Nuevaubicacion(string NvUbi) {
        this->ubicacion = Nuevaubicacion;
    }
    
    //      Getters
    int getPrecio() {
        return precio;
    }

};
*/
class Cuenta{
private:
    string titular;
    int cantidad;
public:
    Cuenta(string titularS, int cantidadS) {
        this->titular = titularS;
        this->cantidad = cantidadS;
    }
    Cuenta(string titularN) {
        this->titular = titularN;
        this->cantidad = 0;
    }
    void setCantidad(int nuevaCantidad) {
        this->cantidad = nuevaCantidad;
    }
    int getCantidad() {
        return cantidad;
    }
    void setTitular(int Nuevo_Titular) {
        this->cantidad = Nuevo_Titular;
    }
    string getTirular(){
        return titular;
    }
    void mostrar() {
        cout << "TITULAR: " <<titular<< endl;
        cout << "CANTIDAD: "<<cantidad << endl;
    }
    void retirar() {
        
    }
};







int main() {
    /*
    Casa casa1(5, 100000, "Av Simon Lopez");
    casa1.mostrar();
    Casa Ubi("Cll. Antezana");
    Ubi.mostrar();
    
    Casa cs = Casa(3, 1000, "Av. Simon Lopez");
    cout << "--Precio--:" << cs.getPrecio;
    */
    Cuenta ct1 = Cuenta("Pollo", 10);
    ct1.mostrar();
    ct1.setCantidad(25);
    ct1.getTirular();
    ct1.mostrar();




    }