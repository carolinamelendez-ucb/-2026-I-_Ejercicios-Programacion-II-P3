// Practica 1 Programacion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;


//1.-
/*
class Libro {
    private:
        string titulo;
        string autor;
        int pag;
    public:
        Libro(string titulo, string autor, int pag) {
            this->titulo = titulo;
            this->autor = autor;
            this->pag = pag;
        }
        void mostrar() {
            cout << "Titulo: " << titulo << endl;
            cout << "Autor: " << autor << endl;
            cout << "Paginas: " << pag << endl;
        }
        void setTitulo(string nuevoT) {
            titulo = nuevoT;
        }
        void setAutor(string nuevoA) {
            autor = nuevoA;
        }
        void setPag(int nuevoP) {
            pag = nuevoP;
        }
};

int main()
{
    Libro libro1 = Libro("Chespirito", "Alan", 200);
    libro1.mostrar();
    libro1.setPag(250);
    libro1.mostrar();
}
*/
/*
//2.-
class Producto {
private:
        string nombre;
        int precio;
        int stock;
public:
    Producto(string nombre,int precio) {
        this->nombre = nombre;
        this->precio = precio;
        stock = 0;
    }
    void setNombre(string nuevoN) {
        nombre = nuevoN;
    }
    void setPrecio(int nuevoP) {
        precio = nuevoP;
    }
    void setStock(int nuevoS) {
        stock = nuevoS;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
    }
};

int main()
{
    Producto producto1 = Producto("celular", 1600);
    producto1.mostrar();
    producto1.setStock(5);
    producto1.setPrecio(1700);
    producto1.mostrar();
}
*/
/*
//3.-
class Pelicula {
private:
    string titulo;
    string genero;;
    int duracion;
public:
    Pelicula(string titulo, string genero, int duracion) {
        this->titulo = titulo;
        this->genero = genero;
        this->duracion = duracion;
    }
    void mostrar() {
        cout << "Pelicula: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "duracion: " << duracion << endl;
    }
    void setTitulo(string nuevoT) {
        titulo = nuevoT;
    }
    void setGenero(string nuevoG) {
        genero = nuevoG;
    }
    void setDuracion(int nuevoD) {
        duracion = nuevoD;
    }
};

int main()
{
    string gen;
    int dur;
    Pelicula pelicula1 = Pelicula("Titanic", "", 0);
    Pelicula pelicula2 = Pelicula("Sonic", "", 0);
    cout << "Ingrese el genero de las pelicula 1: " << endl;
    cin >> gen;
    cout << "Ingrese la duracion de la peliucula 1: " << endl;
    cin >> dur;
    pelicula1.setGenero(gen);
    pelicula1.setDuracion(dur); 

    cout << "Ingrese el genero de las pelicula 2: " << endl;
    cin >> gen;
    cout << "Ingrese la duracion de la peliucula 2: " << endl;
    cin >> dur;
    pelicula2.setGenero(gen);
    pelicula2.setDuracion(dur);

    cout << "Pelicula 1: " << endl;
    pelicula1.mostrar();
    cout << "Pelicula 2: " << endl;
    pelicula2.mostrar();

    pelicula1.setDuracion(185);

    cout << "Pelicula 1: " << endl;
    pelicula1.mostrar();
    cout << "Pelicula 2: " << endl;
    pelicula2.mostrar();

}*/


//4.-
/*
class Mascota {
private:
    string nombre;
        string tipo;
    int edad;
public:
    Mascota(string nombre, string tipo, int edad) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->edad = edad;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Edad: " << edad << endl;
    }
    void setNombre(string nuevoN) {
        nombre = nuevoN;
    }
    void setGenero(string nuevoT) {
        tipo = nuevoT;
    }
    void setEdad(int nuevoE) {
        edad = nuevoE;
    }
};

int main()
{
    int eda;
    Mascota mascota1 = Mascota("Kiara", "Snauser", 0);
    Mascota mascota2 = Mascota("Pelusa", "Pomerania", 0);;
    cout << "Ingrese la edad de la mascota 1: " << endl;
    cin >> eda;
    mascota1.setEdad(eda);

    cout << "Ingrese la edad de la mascota 2: " << endl;
    cin >> eda;

    mascota2.setEdad(eda);

    cout << "Masctota 1: " << endl;
    mascota1.mostrar();
    cout << "Masctora 2: " << endl;
    mascota2.mostrar();

    mascota1.setEdad(3);

    cout << "Masctota 1: " << endl;
    mascota1.mostrar();
    cout << "Masctora 2: " << endl;
    mascota2.mostrar();

}
*/


//5.-
#include <iostream>
#include <string>
using namespace std;

class Pedido {
private:
    int codigo;
    string producto;
    int cantidad;
    float precioUnitario;

public:
    Pedido(int codigo, string producto, int cantidad, float precioUnitario) {
        this->codigo = codigo;
        this->producto = producto;
        this->cantidad = cantidad;
        this->precioUnitario = precioUnitario;
    }

    void setCantidad(int nuevoC) {
        cantidad = nuevoC;
    }

    void setPrecioUnitario(float NuevoP) {
        precioUnitario = NuevoP;
    }

    float calcularTotal() {
        return cantidad * precioUnitario;
    }

    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio Unitario: " << precioUnitario << endl;
        cout << "Total del pedido: " << calcularTotal() << endl;
    }
};

int main() {
    int cant;
    float precio;

    Pedido pedido1 = Pedido(1, "Laptop", 0, 0);
    Pedido pedido2 = Pedido(2, "Mouse", 0, 0);

    cout << "Ingrese cantidad del pedido 1: " << endl;
    cin >> cant;
    cout << "Ingrese precio unitario del pedido 1: " << endl;
    cin >> precio;

    pedido1.setCantidad(cant);
    pedido1.setPrecioUnitario(precio);

    cout << "Ingrese cantidad del pedido 2: " << endl;
    cin >> cant;
    cout << "Ingrese precio unitario del pedido 2: " << endl;
    cin >> precio;

    pedido2.setCantidad(cant);
    pedido2.setPrecioUnitario(precio);

    cout << "Pedido 1:" << endl;
    pedido1.mostrar();
    cout << endl;

    cout << "Pedido 2:" << endl;
    pedido2.mostrar();
    cout << endl;

    pedido1.setCantidad(5);

    cout << "Pedido 1 actualizado:" << endl;
    pedido1.mostrar();
    cout << endl;

    cout << "Pedido 2:" << endl;
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
