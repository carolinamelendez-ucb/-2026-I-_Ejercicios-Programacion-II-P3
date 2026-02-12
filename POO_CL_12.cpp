#include <iostream>
#include <string>
#define LibrosP 5
using namespace std;

class Libro {

private:
    string nombre; 
    string nacionalidad;
    int cantidadDeLibrosPublicados;
public:
    Libro() {
        this->cantidadDeLibrosPublicados=0;
        this->nacionalidad = "";
        this->nombre = "";
    }
    Libro(string nombreL, string nacionalidadL, int cantidadLibrosPublicadosL) {
        this->cantidadDeLibrosPublicados = cantidadLibrosPublicadosL;
        this->nacionalidad = nacionalidadL;
        this->nombre = nombreL;
    }
    int getCantidadLibro() {
        return cantidadDeLibrosPublicados;
    }
};
class Autor {
private:
    string título;
    int precio;
    Libro libro;
public:
    Autor(string tituloA, int precioA, Libro libro) {
        this->precio = precioA;
        this->título = tituloA;
    }
    bool esBestSeller() {
        int cantidad_Libro = libro.getCantidadLibro();
        return cantidad_Libro >= LibrosP;
    }
    void mostrarEsBestSeller() {
        if (esBestSeller())
        {
            cout << "El autor tiene mas de 5 libros publicados" << endl;
        }
        else {
            cout << "No tiene mas de 5 libros publicados" << endl;
        }
    }
};
int main()
{
    Libro libro1 = Libro("Narnia", "peruana", 4);
    Autor autor1 = Autor("javier", 100, libro1);
    autor1.mostrarEsBestSeller();
}