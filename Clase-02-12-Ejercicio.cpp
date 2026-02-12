#include <iostream>
#include <string>
using namespace std;
const int BEST_SELLER = 5;
class Autor
{
private:
    string nombre;
    string nacionalidad;
    int cantidadDeLibrosPublicados;
public:
    Autor()
    {
        nombre = "";
        nacionalidad = "";
        cantidadDeLibrosPublicados = 0;
    }
    Autor(string nombre,string nacionalidad, int cantidadDeLibrosPublicados)
    {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadDeLibrosPublicados = cantidadDeLibrosPublicados;
    }
    int getcantidadDeLibrosPublicados()
    {
        return cantidadDeLibrosPublicados;
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Cantidad de Libros Publicados: " << cantidadDeLibrosPublicados << endl;
    }
};
class Libro
{
private:
    string titulo;
    int precio;
    Autor autor;
public:
    Libro(string titulo, int precio, Autor autor)
    {
        this->titulo = titulo;
        this->precio = precio;
        this->autor=autor;
    }
    bool esBestSeller()
    {
        int cantidadDeLibrosPublicadosAutor = autor.getcantidadDeLibrosPublicados();
        return cantidadDeLibrosPublicadosAutor > BEST_SELLER;
    }
    void mostrarBestSeller()
    {
        if (esBestSeller())
        {
            cout << "El libro es considerado best seller" << endl;
        }
        else
        {
            cout << "El libro no es considerado best seller" << endl;
        }
    }
    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Precio: " << precio << endl;
    }
};
void Ejercicio5()
{
    cout << "---AUTOR--" << endl;
    Autor autor1 = Autor("Fernando", "Frances", 6);
    Libro libro1 = Libro("Apocalipsis", 250, autor1);
    autor1.mostrar();
    cout << "-----------------------" << endl;
    cout << "---LIBRO--" << endl;
    libro1.mostrar();
    libro1.mostrarBestSeller();
}

int main()
{
    Ejercicio5();
}