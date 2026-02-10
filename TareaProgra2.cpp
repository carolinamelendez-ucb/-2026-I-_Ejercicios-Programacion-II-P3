// TareaProgra2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Libro
{
private:
    string titulo;
    string autor;
    int paginas;

public:
    Libro(string t, string a, int p)
    {
        titulo = t;
        autor = a;
        paginas = p;
    }

    void setTitulo(string t)
    {
        titulo = t;
    }

    void setAutor(string a)
    {
        autor = a;
    }

    void setPaginas(int p)
    {
        paginas = p;
    }

    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Paginas: " << paginas << endl;
    }
};

int main()
{
    Libro libro1("Cien anios de soledad", "Gabriel Garcia Marquez", 417);

    libro1.mostrar();

    cout << endl;

    libro1.setPaginas(500);

    libro1.mostrar();

    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
