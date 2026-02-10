// Ejercicio1_objetos.cpp 
// 08/02/26

/* 1. Crea una clase llamada Libro con las siguientes condiciones :
● Implementar los siguientes atributos : titulo, autor, paginas
● Crea un constructor con todos los atributos.
● Métodos set para cada atributo.
● Método mostrar() que muestre la información del libro.
En el main :
1. Crea un libro.
2. Muestra sus datos.
3. Cambia el número de páginas con setPaginas.
4. Vuelve a mostrar */

#include <iostream>
#include <string>
using namespace std;

class Libro
{
    private:
        //ATRIBUTOS
        string titulo;
        string autor;
        int paginas;

    public: 
        //CONSTRUCTOR
        Libro(string T, string A, int P)
        {
            titulo = T;
            autor = A;
            paginas = P;
        }
        //METODO MOSTRAR()
        void mostrar()
        {
            cout << "Titulo: " << titulo << endl;
            cout << "Autor: " << autor << endl;
            cout << "Paginas: " << paginas << endl;
        }
        //METODO SET
        void setTitulo(string nuevoTitulo)
        {
            this->titulo = nuevoTitulo;
        }
        void setAutor(string nuevoAutor)
        {
            this->autor = nuevoAutor;
        }
        void setPaginas(int nuevaPaginas)
        {
            this->paginas = nuevaPaginas;
        }
};

int main()
{
    cout << "-- LIBRO 1 --\n" << endl;
    Libro libro1 = Libro("Relato de un naufrago", "Gabriel Garcia Marquez", 256);
    libro1.mostrar();
    
    cout << "\nCambiando datos del LIBRO 1...\n" << endl;
    libro1.setPaginas(350);
    libro1.mostrar();
}

