#include <iostream>

using namespace std;

//NOTACION -> Pascal CASE -> MiPrimeraPalabra (este se usa)
//NOTACION -> Camel CASE -> miPrimeraPalabra
//NOTACION -> snake CASE -> mi_primera_palabra

class Pelota
{
    //Atributos
private: 
    string color;
    string tamaño;
    int peso;
    string material;
    string marca;
    string tipo;
    string textura;

    //Metodos
public:
    /*Esta seccion es la declaracion de los valores de los atributos, se llama consultorio*/
    Pelota(string colorP, string tam, int pes, string mat, string mar, string tip, string tex) { //Para cuando se quiera variar algun dato (esto se llama constructor)
        color = colorP;
        tamaño = tam;
        peso = pes;
        material = mat;
        marca = mar;
        tipo = tip;
        textura = tex;
    }

    //Estas son las funciones, los metodos
    void mostrar()
    {
        cout << "color: " << color << endl;
        cout << "tamaño: " << tamaño << endl;
        cout << "peso: " << peso << endl;
        cout << "material: " << material << endl;
        cout << "marca: " << marca << endl;
        cout << "tipo: " << tipo << endl;
        cout << "textura: " << textura << endl;
        cout << endl;
    }

    void rodar()
    {
        cout << "Pelota rueda" << endl;
    }

    void detener()
    {
        cout << "Pelota se detiene" << endl;
    }

    void rebotar() {}
    
    void inflar() {}
    
    void desinflar() {}
    
    void reventar() {}
    
    void desgastar() {}

    void setPeso(int nuevoPeso)
    {
        peso = nuevoPeso;
    }
};


int main()
{
    Pelota pel1 = Pelota("azul");

    pel1.rodar();
    pel1.rodar();
    pel1.rodar();
    pel1.rodar();
    pel1.detener();
    pel1.mostrar();

    Pelota pel2 = Pelota("rojo"); //Se ponen los datos que se varian, como en una función, si quieres cambiar dichos datos posteriormente, se usan setters, osea metodos para modificar (arriba)
    pel2.mostrar();
    pel2.setPeso(30);
    pel2.mostrar();
    Pelota pel3 = Pelota("amarillo");
    pel3.mostrar();
}
