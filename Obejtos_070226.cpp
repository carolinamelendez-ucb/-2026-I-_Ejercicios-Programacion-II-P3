#include <iostream>
#include <string>

using namespace std;

class Celular
{
private:
    //atributos
    int espacio;
    int memoriaRAM;
    string marca;
    string camara;
    int precio;

    //metodos
public:
    Celular(int espacioCel,int memoriaCel,string marcaCel,string camaraCel, int precioCel) {
        espacio = espacioCel;
        memoriaRAM = memoriaCel;
        marca = marcaCel;
        camara =camaraCel;
        precio = precioCel;
    }
    void mostrar() {
        cout << "Espacio: " << espacio << endl;
        cout << "Memoria Ram: " << memoriaRAM << endl;
        cout << "Marca: " << marca << endl;
        cout << "Camara: " << camara << endl;
        cout << "Precio: " << precio << endl;
    }
    void setEspacio(int nuevoEspacio) {
        espacio = nuevoEspacio;
    }

    void llamar() {
        cout << "Llamando....." << endl;
    }
    void procesar() {
        cout << "Inicializando el sistema" << endl;
    }
    void mensajear() {
        cout << "Mandando mensaje....." << endl;
    }
    void reproducir() {
        cout << "Reproduciendo....." << endl;
    }
    void jugar() {
        cout << "Jugando....." << endl;
    }
};

int main()
{
    cout << "Celular 1:" << endl;
    Celular miCelu = Celular(100,8,"Apple","Buena",500);
    miCelu.llamar();
    miCelu.llamar();
    miCelu.llamar();
    miCelu.llamar();

    miCelu.mostrar();
    cout << endl << "Celular 2:" << endl;
    Celular miCelu2 = Celular(256, 16, "Xiaomi", "Muy Buena", 800);
    miCelu2.mostrar();
    cout << endl << "Celular 3:" << endl;
    Celular miCelu3 = Celular(525, 32, "Andorid", "Buena", 900);
    miCelu3.mostrar();
    cout << endl << "Celular 4:" << endl;
    Celular miCelu4 = Celular(1021, 64, "Apple", "Muy Buena", 1500);
    miCelu4.mostrar();
    cout << endl << "Usando set en Celular 4:" << endl;
    miCelu4.setEspacio(800);
    miCelu4.mostrar();
    
}
