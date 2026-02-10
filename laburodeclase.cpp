using namespace std;
#include <iostream>
#include <string>
/*class casa {
private:
    int Nhabitaciones;
    int precio;
    string ubicacion;
public:
    casa(int NH, int P, string U) {
        this->Nhabitaciones = NH;
        this->precio = P;
        this->ubicacion = U;
    }
    casa(int NH, string U) {
        this->Nhabitaciones = NH;
        this->precio = 0;
        this->ubicacion = U;
    }
    casa( string U) {
        this->Nhabitaciones = 0;
        this->precio = 0;
        this->ubicacion = U;
    }
    void mostrar() {
        cout << "Nro habitaciones: " << Nhabitaciones<<endl;
        cout << "Precio: " << precio << endl;
        cout << "Ubicacion: " << ubicacion << endl;

    }
    int getPrecio() { return precio; }
    int getHabitaciones() { return Nhabitaciones; }
    string getubicacion() { return ubicacion; }


};*/
class cuenta {
private:
    string titular;
    int cantidad;
public:
    cuenta(string T, int C) {
        this->titular = T;
        this->cantidad = C;
    }
    cuenta(string T) {
        this->titular = T;
        this->cantidad = 0;
    }
    void setcantidad(int nuevacantidad) { this->cantidad = nuevacantidad; }
    int getcantidad() { return cantidad; }
    void settitular(int nuevotitular) { this->titular=nuevotitular; }
    string gettitular() { return titular; }
    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "cantidad: " << cantidad << endl;

    }
    void ingresar(int CI) {
        if (CI >= 0) {
            this->cantidad = this->cantidad + cantidad;
        };
    }
    void retirar(int CR) {
        int restante = cantidad + CR;
    }
    };
 int main()
{

    /*casa micasa = casa(8, 200, "av libertador");
    micasa.mostrar();

    casa micasa2 = casa(8, "av libertador");
    micasa2.mostrar();

    casa micasa3 = casa("av libertador");
    micasa3.mostrar();

    micasa.getPrecio();
    micasa2.getHabitaciones();
    micasa3.getubicacion();*/

};

