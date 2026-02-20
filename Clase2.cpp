#include <iostream>
#include <string>

using namespace std;
// NOTACION -> Pascal CASE -> MiPrimeraPalabra
// NOTACION -> camel CASE -> miPrimeraPalabra
// NOTACION -> Pascal CASE -> mi_primera_palabra


class Celular {
//Atributos
private:
    int peso;
    string marca;
    int almacenamiento;
    string color;
    int tamanio;

// Metodos
public:

    Celular(int peso1, string marca1, int almacenamiento1, string color1, int tamanio1) {
        peso = peso1;
        marca = marca1;
        almacenamiento = almacenamiento1;
        color = color1;
        tamanio = tamanio1;
    }

    void mostrar() {
        cout << "Peso : " << peso << endl;
        cout << "marca : " << marca << endl;
        cout << "almacenamiento : " << almacenamiento << endl;
        cout << "color : " << color << endl;
        cout << "tamaño : " << tamanio << endl;
    }

    void llamar (){
        cout << "Llamando......" << endl;
    
    }
    void mensajear () {}
    void fotografiar () {}
    void grabar () {}
    void jugar () {}
};


int main()
{
    Celular celular1 = Celular( 26, "iphone", 126, "negro", 16);
    Celular celular2 = Celular(20, "samsumg", 252, "rojo", 18);
    Celular celular3 = Celular(18, "xiaomi", 64, "blanco", 14);

}
