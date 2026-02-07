using namespace std;
#include <iostream>
#include <string>
using namespace std;
class Celular {
private:
    int bateria;
    string color;
    string marca;
    string almacenamiento;
    int modelo;
public:
    Celular(int B, string C, string M, string A, string Mo) {
        bateria = B;
        color = C;
        marca = M;
        almacenamiento = A;
        modelo = Mo;
    };
};
void setMarca(string nuevo) {
    this->marca = nuevo;
}
void mostrar() {
    cout << "bateria: " << bateria << endl;
    cout << "color: " << color << endl;
    cout << "marca" << marca << endl;
    cout << "almacenamiento: " << almacenamiento << endl;
    cout << "modelo: " << modelo << endl;
};
public:
void Llamar() {
    cout << "Llamando...." << endl;

};
void Enviarmensaje() {
    cout << "Enviando mensaje..." << endl;
};
void Tomarfotos() {};
void Cargarbateria() {};
void Reproducirmusica() {};

int main()
{
    llamar();
    llamar();
    llamar();
    llamar();
    Enviarmensaje();


}


