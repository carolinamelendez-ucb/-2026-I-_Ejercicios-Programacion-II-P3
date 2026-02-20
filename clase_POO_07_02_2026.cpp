#include <iostream>
#include <string>
using namespace std;

//NOTACION -> Pascal CASE -> MiPrimeraPalabra
//NOTACION ->

class Auto
{
private:
    //Atributos
    int precio;
    string color;
    string modelo;
    string marca;
    string placa;
public:
    Auto(int precioAuto, string colorAuto, string modeloAuto, string placaAuto)
    {
        precio = precioAuto;
        color = colorAuto;
        modelo = modeloAuto;
        marca = "Nissan";
        placa = placaAuto;
    }
    void mostrar()
    {
        cout << "Precio: " << precio << endl;
        cout << "Color: " << color << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Marca: " << marca << endl;
        cout << "Placa: " << placa << endl;
    }

void setPrecio(int nuevoPrecio)
{
    this -> precio = nuevoPrecio;
}

    //Metodos
    void arrancar()
    {
        cout<<"Auto arranca..."<<endl;
    }
    void frenar()
    {
        cout<<"Auto frena..."<<endl;
    }
    void apagar()
    {
        cout<<"Auto se apaga..."<<endl;
    }
    void girar()
    {
        cout<<"Auto gira..."<<endl;
    }
    void acelerar()
    {
        cout<<"Auto acelera..."<<endl;
    }
};

int main()
{
    cout<<"Auto 1: "<<endl;
    Auto auto1 = Auto(20000, "rojo", "March", "4692XKJ");
    auto1.mostrar();
    cout<<"Auto 2: "<<endl;
    Auto auto2 = Auto(21000, "negro", "MarchX", "3412XDS");
    auto2.mostrar();

    auto2.setPrecio(35000);
    cout<<"-------------------------------------"<<endl;
    auto2.mostrar();
}