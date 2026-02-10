#include <iostream>

using namespace std;

class Libro
{
private:
    string titulo;
    string autor;
    int paginas;

public:
    Libro(string tituloL,string autorL,int pagL) { 
        titulo=tituloL;
        autor=autorL;
        paginas=pagL;
    }

    void mostrar()
    {
        cout << "DATOS DEL LIBRO" << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Paginas: " << paginas << endl;
        cout << endl;
    }

    void setTitulo(string nTitulo)
    {
        titulo = nTitulo;
    }

    void setAutor(string nAutor)
    {
        autor = nAutor;
    }

    void setPag(int nPag)
    {
        paginas = nPag;
    }
};


int main()
{
    Libro L1 = Libro("El Principito","Antoine de Saint-Exupery",70);

    L1.mostrar();
    L1.setPag(100);
    L1.mostrar();
}
