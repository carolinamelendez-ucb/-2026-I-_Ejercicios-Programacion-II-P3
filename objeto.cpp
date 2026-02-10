
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//NOTACIÓN --> Pascal CASE -->MiPrimeraPalabra (NOMBRE DEL OBJETO)
//NOTACIÓN --> cAMEL CASE --> miPrimeraPalabra 
//NOTACIÓN-- > snake CASE-- > mi_primera_palabra 
class celular {
private: //Poner si o si para los atributos
    string marca;
    string modelo;
    int almacenamiento;
    string color;
    int bateria;
public: //Poner si o si para los metodos
    celular(string marcax, string modelox, int almacenamientox, string colorx, int bateriax) {//CONSTRUCTOR(SE LE DA VALORES A LAS VARIABLES)
        marca = marcax;
        almacenamiento = almacenamientox;
        color = colorx;
        bateria = bateriax;
    } 
    void mostrar() {
        cout << "Marca :" << marca <<endl;
        cout << "Modelo :" << modelo << endl;
        cout << "Almacenamiento :" << almacenamiento << endl;
        cout << "Color :" << color << endl;
        cout << "Bateria :" << bateria << endl;
    }
void encender() {
    cout << "Celular enciendete" << endl;
}
void instalarapli(){
    cout << "Instala aplicaciones" << endl;
}
void tomarfotos() {
    cout << "Toma fotos" << endl;
}
void vervideos(){
    cout << "Ver videos" << endl;
}
void cargarcelular() {
    cout << "Cargar el celular" << endl;
}
  
};
int main()
{
    celular celular1 = celular("iPHONE", "17 pro max", 128, "Naranja", 100);
    celular celular2 = celular("iPHONE", "16 pro max", 128, "Blanco", 98);
    celular celular3 = celular("iPHONE", "15 pro max", 128, "Plomo", 99);
    celular celular4 = celular("iPHONE", "14 pro max", 128, "Negro", 97);
    celular1.mostrar();
    celular2.mostrar();
    celular3.mostrar();
    celular4.mostrar();
    return 0;
}

