#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//Notacion CAMEL CASE -> MiPrimeraPalabra
//Notacion snake CASE -> mi_primera_palabra


class Smartphone
{
private:
    string marca;
    string modelo;
    int almacenamiento;
    string color;
    int bateria;

    //Constructor
public:
    Smartphone(string marcaA, string modeloA, int almacenamientoA, string colorA, int bateriaA) {
        marca = marcaA;
        modelo = modeloA;
        almacenamiento = almacenamientoA;
        color = colorA;
        bateria = bateriaA;
    }
    void mostrar() {
        cout << "Marca: " << marca;
        cout << "Modelo: " << modelo;
        cout << "Almacenamiento: " << almacenamiento;
        cout << "Color: " << color;
        cout << "Bateria: " << bateria;
    }

    //Metodos
    void encender() 
    {
        cout << "Encender" << endl;
    };
    void InstalarAplicaciones() 
    {
        cout << "Instalar Aplicaciones" << endl;
    };
    void TomarFotos()
    {
        cout << "Tomar Fotos" << endl;
    };
    void VerVideos() 
    {
        cout << "Ver Videos" << endl;
    };
    void Cargar() 
    {
        cout << "Cargar" << endl;
    };
};

int main()
{
    Smartphone iphone = Smartphone("iphone", "13", 256, "rojo", 100);
    iphone.mostrar();
   

}

