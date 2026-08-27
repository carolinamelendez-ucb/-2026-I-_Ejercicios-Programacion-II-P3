#include <iostream>
#include <vector>
#include "Autor.h"
#include "Libro.h"

using namespace std;

int main() {
    Autor* a1 = new Autor("Gabriel Garcia Marquez", "Colombiano", 15);
    Autor* a2 = new Autor("Autor Novato", "Boliviano", 2);
    Autor* a3 = new Autor("Isabel Allende", "Chilena", 10);
    Autor* a4 = new Autor("Escritor Nuevo", "Mexicano", 1);

    vector<Libro*> libros;
    libros.push_back(new Libro("Cien anos de soledad", 150.0, a1));
    libros.push_back(new Libro("Mi primer libro", 50.0, a2));
    libros.push_back(new Libro("La casa de los espiritus", 120.0, a3));
    libros.push_back(new Libro("Aprendiendo C++", 80.0, a4));
    libros.push_back(new Libro("El amor en tiempos del colera", 130.0, a1));

    cout << "--- RESULTADOS DEL EJERCICIO 4 ---" << endl;

    int N = 3;
    double suma1 = 0;
    int cont1 = 0;
    for (int i = 0; i < libros.size(); i++) {
        if (libros[i]->getAutor()->getCantidadLibrosPublicados() > N) {
            suma1 = suma1 + libros[i]->getPrecio();
            cont1++;
        }
    }
    if (cont1 > 0) {
        double promedio1 = suma1 / cont1;
        cout << "1. Promedio precio (Autores con mas de " << N << " libros): " << promedio1 << endl;
    }

    double suma2 = 0;
    int cont2 = 0;
    for (int i = 0; i < libros.size(); i++) {
        if (libros[i]->esBestSeller()) {
            suma2 = suma2 + libros[i]->getPrecio();
            cont2++;
        }
    }
    if (cont2 > 0) {
        double promedio2 = suma2 / cont2;
        cout << "2. Promedio precio de libros Best Seller: " << promedio2 << endl;
    }

    Libro* masCaro = nullptr;
    for (int i = 0; i < libros.size(); i++) {
        if (libros[i]->esBestSeller()) {
            if (masCaro == nullptr || libros[i]->getPrecio() > masCaro->getPrecio()) {
                masCaro = libros[i];
            }
        }
    }
    if (masCaro != nullptr) {
        cout << "3. El libro reconocido mas caro es: " << masCaro->getTitulo() << endl;
    }

    int contNovatos = 0;
    for (int i = 0; i < libros.size(); i++) {
        if (libros[i]->getAutor()->getCantidadLibrosPublicados() <= 5) {
            contNovatos++;
        }
    }
    cout << "4. Cantidad de libros de autores novatos: " << contNovatos << endl;

    double totalRecaudado = 0;
    for (int i = 0; i < libros.size(); i++) {
        if (libros[i]->esBestSeller()) {
            totalRecaudado = totalRecaudado + libros[i]->getPrecio();
        }
    }
    cout << "5. Total recaudado por autores productivos: " << totalRecaudado << endl;

    for (int i = 0; i < libros.size(); i++) {
        delete libros[i];
    }
    delete a1;
    delete a2;
    delete a3;
    delete a4;

    return 0;
}