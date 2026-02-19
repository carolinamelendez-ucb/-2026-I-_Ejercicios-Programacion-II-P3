// TAREA_EJ10_0212.cpp 
//18/02/26
/* Ejercicio 10. Relación Libro – Autor

- En el main(), cree un arreglo de Libros
- Implemente un método que muestre el promedio de precio de los libros cuyos autores tengan más de N libros publicados.
- Implemente un método que recorra el arreglo y calcule el precio promedio de los libros considerados best seller.
- Implemente un método que recorra el arreglo y muestre el libro más caro de un autor reconocido.
- Implemente un método que recorra el arreglo y muestre cuántos libros pertenecen a autores novatos.
- Implemente un método que recorra el arreglo y calcule el total recaudado por libros de autores productivos. */

#include <iostream>
#include <string>
using namespace std;

class Autor
{
private:
    string nombre;
    int cantidadLibros;
    bool reconocido;
    bool novato;

public:
    Autor()
    {
        nombre = "";
        cantidadLibros = 0;
        reconocido = false;
        novato = false;
    }

    Autor(string nombre, int cantidadLibros, bool reconocido, bool novato)
    {
        this->nombre = nombre;
        this->cantidadLibros = cantidadLibros;
        this->reconocido = reconocido;
        this->novato = novato;
    }

    string getNombre()
    {
        return nombre;
    }

    int getCantidadLibros()
    {
        return cantidadLibros;
    }

    bool isReconocido()
    {
        return reconocido;
    }

    bool isNovato()
    {
        return novato;
    }
};

class Libro
{
private:
    string titulo;
    float precio;
    bool bestSeller;
    Autor autor;

public:
    Libro()
    {
        titulo = "";
        precio = 0;
        bestSeller = false;
        autor = Autor();
    }

    Libro(string titulo, float precio, bool bestSeller, Autor autor)
    {
        this->titulo = titulo;
        this->precio = precio;
        this->bestSeller = bestSeller;
        this->autor = autor;
    }

    float getPrecio()
    {
        return precio;
    }

    bool isBestSeller()
    {
        return bestSeller;
    }

    Autor getAutor()
    {
        return autor;
    }

    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Precio: " << precio << endl;
        cout << "Autor: " << autor.getNombre() << endl;
        cout << "----------------------" << endl;
    }
};

int main()
{
    int N = 3; 

    Autor a1("Gabriel", 5, true, false);
    Autor a2("Maria", 1, false, true);
    Autor a3("Carlos", 10, true, false);
    Autor a4("Luis", 2, false, true);

    Libro libros[6];

    libros[0] = Libro("Libro A", 100, true, a1);
    libros[1] = Libro("Libro B", 80, false, a2);
    libros[2] = Libro("Libro C", 150, true, a3);
    libros[3] = Libro("Libro D", 60, false, a4);
    libros[4] = Libro("Libro E", 200, true, a3);
    libros[5] = Libro("Libro F", 90, false, a1);

    int n = 6;

    //Promedio precio autores con mas de N libros publicados
    float suma1 = 0;
    int contador1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (libros[i].getAutor().getCantidadLibros() > N)
        {
            suma1 += libros[i].getPrecio();
            contador1++;
        }
    }

    if (contador1 > 0)
        cout << "Promedio precio autores con mas de " << N << " libros: " << suma1 / contador1 << endl;
    else
        cout << "No hay autores con mas de " << N << " libros." << endl;

    // Promedio precio libros best seller
    float sumaBest = 0;
    int contadorBest = 0;

    for (int i = 0; i < n; i++)
    {
        if (libros[i].isBestSeller())
        {
            sumaBest += libros[i].getPrecio();
            contadorBest++;
        }
    }

    if (contadorBest > 0)
        cout << "Promedio precio best sellers: " << sumaBest / contadorBest << endl;

    // Libro mas caro de autor reconocido
    float mayor = 0;
    int posMayor = -1;

    for (int i = 0; i < n; i++)
    {
        if (libros[i].getAutor().isReconocido())
        {
            if (libros[i].getPrecio() > mayor)
            {
                mayor = libros[i].getPrecio();
                posMayor = i;
            }
        }
    }

    if (posMayor != -1)
    {
        cout << "Libro mas caro de autor reconocido:" << endl;
        libros[posMayor].mostrar();
    }

    //Cuantos libros pertenecen a autores novatos
    int contadorNovatos = 0;

    for (int i = 0; i < n; i++)
    {
        if (libros[i].getAutor().isNovato())
            contadorNovatos++;
    }

    cout << "Libros de autores novatos: " << contadorNovatos << endl;

    //Total recaudado por libros de autores productivos
    //productivo si tiene más de 5 libros publicados

    float totalProductivos = 0;

    for (int i = 0; i < n; i++)
    {
        if (libros[i].getAutor().getCantidadLibros() > 5)
            totalProductivos += libros[i].getPrecio();
    }

    cout << "Total recaudado autores productivos: " << totalProductivos << endl;

    return 0;

}

