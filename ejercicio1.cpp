
#include <iostream>

using namespace std;

class Libro
{
private:
    string titulo;
    string autor;
    int paginas;
public:
    Libro(string titulo, string autor, int paginas) {
        this->titulo = titulo;
        this->autor = autor;
        this->paginas = paginas;
    }

    void setTitulo(string nuevoTitulo) {
        this->titulo = nuevoTitulo;
    }

    void setAutor(string nuevoAutor) {
        this->autor = nuevoAutor;
    }

    void setPaginas(int nuevaPagina) {
        this->paginas = nuevaPagina;
    }

    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Numero de paginas: " << paginas << endl;
    }
};

int main()
{
    Libro  libro1 = Libro("La Odisea", "Homero", 268);
    libro1.mostrar();
    cout << endl;
    cout << "Cambio numero de paginas: " << endl;
    libro1.setPaginas(280);
    libro1.mostrar();
}

