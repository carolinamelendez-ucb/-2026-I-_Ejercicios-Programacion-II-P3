// tarea-obj.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
//EJERCICIO 1
class libro{
private:
    string titulo;
    string autor;
    int paginas;

public:
    libro(string titulo, string autor, int paginas)
    {
        this->titulo = titulo;
        this->autor = autor;
        this->paginas = paginas;
    }

    void settitulo(string nuevotitulo)
    {
        this->titulo = nuevotitulo;
    }

    void setautor(string nuevoautor)
    {
        this->autor = nuevoautor;
    }

    void setpaginas(int nuevapaginas)
    {
        this->paginas = nuevapaginas;
    }

    void mostrar()
    {
        cout << "titulo: " << titulo << endl;
        cout << "autor: " << autor << endl;
        cout << "paginas: " << paginas << endl;
    }
};
//EJERCICIO 2
class producto {
private:
    string nombre;
    float precio;
    int stock;

public:
    producto(string nombre, float precio)
    {
        this->nombre = nombre;
        this->precio = precio;
        this->stock = 0;
    }

    void setnombre(string nuevonombre)
    {
        this->nombre = nuevonombre;
    }

    void setprecio(float nuevoprecio)
    {
        this->precio = nuevoprecio;
    }

    void setstock(int nuevostock)
    {
        this->stock = nuevostock;
    }

    void mostrar()
    {
        cout << "nombre: " << nombre << endl;
        cout << "precio: " << precio << " bs" << endl;
        cout << "stock: " << stock << endl;
    }
};
//EJERCICIO 3
class pelicula {
private:
    string titulo;
    string genero;
    int duracion; // minutos

public:
    pelicula(string titulo, string genero, int duracion)
    {
        this->titulo = titulo;
        this->genero = genero;
        this->duracion = duracion;
    }

    void settitulo(string nuevotitulo)
    {
        this->titulo = nuevotitulo;
    }

    void setgenero(string nuevogenero)
    {
        this->genero = nuevogenero;
    }

    void setduracion(int nuevaduracion)
    {
        this->duracion = nuevaduracion;
    }

    void mostrar()
    {
        cout << "titulo: " << titulo << endl;
        cout << "genero: " << genero << endl;
        cout << "duracion: " << duracion << " min" << endl;
    }
};
//EJERCICIO 4
class mascota {
private:
    string nombre;
    string tipo;
    int edad;

public:
    mascota(string nombre, string tipo, int edad)
    {
        this->nombre = nombre;
        this->tipo = tipo;
        this->edad = edad;
    }

    void setnombre(string nuevonombre)
    {
        this->nombre = nuevonombre;
    }

    void settipo(string nuevotipo)
    {
        this->tipo = nuevotipo;
    }

    void setedad(int nuevaedad)
    {
        this->edad = nuevaedad;
    }

    void mostrar()
    {
        cout << "nombre: " << nombre << endl;
        cout << "tipo: " << tipo << endl;
        cout << "edad: " << edad << " anios" << endl;
    }
};
//EJERCICIO 5
class pedido {
private:
    string codigo;
    string producto;
    int cantidad;
    float precioUnitario;

public:
    pedido(string codigo, string producto, int cantidad, float precioUnitario)
    {
        this->codigo = codigo;
        this->producto = producto;
        this->cantidad = cantidad;
        this->precioUnitario = precioUnitario;
    }

    void setcantidad(int nuevacantidad)
    {
        this->cantidad = nuevacantidad;
    }

    void setprecioUnitario(float nuevoprecioUnitario)
    {
        this->precioUnitario = nuevoprecioUnitario;
    }

    float calcularTotal()
    {
        return cantidad * precioUnitario;
    }

    void mostrar()
    {
        cout << "codigo: " << codigo << endl;
        cout << "producto: " << producto << endl;
        cout << "cantidad: " << cantidad << endl;
        cout << "precio unitario: " << precioUnitario << " bs" << endl;
        cout << "total del pedido: " << calcularTotal() << " bs" << endl;
    }
};


int main()
{
    //ejercicio 1
    libro libro1 = libro("Cien años de soledad", "Gabriel Garcia Marquez", 471);
    libro1.mostrar();

    libro1.setpaginas(500);
    cout << "------- " << endl;
    libro1.mostrar();
    //ejercicio 2
    producto producto1 = producto("Teclado mecanico", 180);
    producto1.mostrar();

    producto1.setstock(25);
    producto1.setprecio(165);

    cout << "------- " << endl;
    producto1.mostrar();
    //ejercicio 3
    pelicula pelicula1 = pelicula("Avatar", "", 0);
    pelicula pelicula2 = pelicula("Titanic", "", 0);
    pelicula pelicula3 = pelicula("Interstellar", "", 0);

    string genero;
    int duracion;

    cout << "Ingrese genero y duracion de Avatar: ";
    cin >> genero >> duracion;
    pelicula1.setgenero(genero);
    pelicula1.setduracion(duracion);

    cout << "Ingrese genero y duracion de Titanic: ";
    cin >> genero >> duracion;
    pelicula2.setgenero(genero);
    pelicula2.setduracion(duracion);

    cout << "Ingrese genero y duracion de Interstellar: ";
    cin >> genero >> duracion;
    pelicula3.setgenero(genero);
    pelicula3.setduracion(duracion);

    cout << "------- " << endl;
    pelicula1.mostrar();
    cout << "------- " << endl;
    pelicula2.mostrar();
    cout << "------- " << endl;
    pelicula3.mostrar();

        // modificar duracion de una pelicula
    pelicula2.setduracion(210);

    cout << "======= despues del cambio ======= " << endl;
    pelicula1.mostrar();
    cout << "------- " << endl;
    pelicula2.mostrar();
    cout << "------- " << endl;
    pelicula3.mostrar();
    //ejercicio 4
    mascota mascota1 = mascota("Firulais", "perro", 0);
    mascota mascota2 = mascota("Michi", "gato", 0);
    mascota mascota3 = mascota("Piolin", "ave", 0);

    int edad;

    cout << "Ingrese edad de Firulais: ";
    cin >> edad;
    mascota1.setedad(edad);

    cout << "Ingrese edad de Michi: ";
    cin >> edad;
    mascota2.setedad(edad);

    cout << "Ingrese edad de Piolin: ";
    cin >> edad;
    mascota3.setedad(edad);

    cout << "------- " << endl;
    mascota1.mostrar();
    cout << "------- " << endl;
    mascota2.mostrar();
    cout << "------- " << endl;
    mascota3.mostrar();

        // cambiar edad de una mascota
    mascota2.setedad(7);

    cout << "======= despues del cambio ======= " << endl;
    mascota1.mostrar();
    cout << "------- " << endl;
    mascota2.mostrar();
    cout << "------- " << endl;
    mascota3.mostrar();
    //ejercicio 5
    pedido pedido1 = pedido("P-001", "mouse gamer", 0, 0);
    pedido pedido2 = pedido("P-002", "audifonos", 0, 0);

    int cantidad;
    float precio;

    cout << "Ingrese cantidad y precio unitario del pedido 1: ";
    cin >> cantidad >> precio;
    pedido1.setcantidad(cantidad);
    pedido1.setprecioUnitario(precio);

    cout << "Ingrese cantidad y precio unitario del pedido 2: ";
    cin >> cantidad >> precio;
    pedido2.setcantidad(cantidad);
    pedido2.setprecioUnitario(precio);

    cout << "------- " << endl;
    pedido1.mostrar();
    cout << "------- " << endl;
    pedido2.mostrar();

        // modificar cantidad de un pedido
    pedido1.setcantidad(10);

    cout << "======= despues del cambio ======= " << endl;
    pedido1.mostrar();
    cout << "------- " << endl;
    pedido2.mostrar();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
