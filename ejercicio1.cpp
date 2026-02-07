#include <iostream>
#include <string>
using namespace std;

class Avion
{
    private:
    
    int velocidadMaxima;
    int capacidadCombustible;
    int cantidadAsientos;
    string aerolinea;
    string color;
    string tipoDeAvion;

    public:

    Avion(int velocidadMaxima, int capacidadMaxima, int cantidadAsientos)
    {
        this -> velocidadMaxima;
        this -> capacidadCombustible;
        this -> cantidadAsientos ;
        this -> aerolinea = "Boa";
        this -> color = "Blanco";
        this -> tipoDeAvion = "Comercial-Boeing 747";
    }

    void mostrar()
    {
        cout << " Velocidad Maxima :" << velocidadMaxima << endl;
        cout << " Capacidad Combustble : " << capacidadCombustible << endl;
        cout << " Cantidad de Asientos :" << cantidadAsientos << endl;
        cout << " Nombre Aerolinea : " << aerolinea << endl;
        cout << " Color : " << color  << endl;
        cout << " Tipo de Avion : "<< tipoDeAvion << endl;
    }

    void setCantidadAsientos(int nuevaCantidad)
    {
        this-> cantidadAsientos = nuevaCantidad;
    }

    void despegar()
    {
        cout << " Avion Despega" <<endl;
    }
    void aterrizar()
    {
        cout << " Avion Aterriza" << endl;
    }
    void sobreVolar(){
        cout << " Avion sobre vuela" << endl;
    }
    void descender(){
        cout << " Avion desciende " << endl;
    }
    void ascender(){
        cout << " Avion ascendiendo "<< endl;
    }
};



int main()
{

    Avion avion1 = Avion(9000,20000,50);
    Avion avion2 = Avion(10000,50000,70);
    /*avion1.sobreVolar();
    avion1.aterrizar();
    avion1.despegar();
    avion1.ascender();
    avion1.descender();*/

    cout << " AVION 1 " << endl;
    avion1.setCantidadAsientos(300);
    avion1.mostrar();
   

    cout << " Avions 2 " << endl ;
    avion2.setCantidadAsientos(100);
    avion2.mostrar();

    return 0;
}