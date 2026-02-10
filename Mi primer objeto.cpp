#include <iostream>
#include <string>
using namespace std;
    // EJERCICIO 1
class Libro {
private:
    string titulo;
    string autor;
    int paginas;
    public:
        Libro(string t, string a, int p) {
            titulo = t;
            autor = a;
            paginas = p;
        }

        void setTitulo(string tNuevo) {
            titulo = tNuevo;
        }

        void setAutor(string aNuevo) {
            autor = aNuevo;
        }

        void setPaginas(int pNuevas) {
            paginas = pNuevas;
        }

        void mostrar() {
            cout << "Titulo: " << titulo << endl;
            cout << "Autor: " << autor << endl;
            cout << "Paginas: " << paginas << endl;
        }
};

// EJERCICIO 2
class Producto {
private:
    string nombre;
    int precio;
    int stock;

public:
    Producto(string nom, int prec) {
        nombre = nom;
        precio = prec;
        stock = 0;
    }

    void setNombre(string nomNuevo) {
        nombre = nomNuevo;
    }

    void setPrecio(int precNuevo) {
        precio = precNuevo;
    }

    void setStock(int cantStock) {
        stock = cantStock;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
    }
};

// EJERCICIO 3
class Pelicula {
private:
    string titulo;
    string genero;
    int duracion;

public:
    Pelicula(string tit, string gen, int dur) {
        titulo = tit;
        genero = gen;
        duracion = dur;
    }

    void setTitulo(string titNuevo) {
        titulo = titNuevo;
    }

    void setGenero(string genNuevo) {
        genero = genNuevo;
    }

    void setDuracion(int durNueva) {
        duracion = durNueva;
    }

    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion: " << duracion << " minutos" << endl;
    }
};

// EJERCICIO 4
class Mascota {
private:
    string nombre;
    string tipo;
    int edad;

public:
    Mascota(string nomMas, string tipoMas, int edadMas) {
        nombre = nomMas;
        tipo = tipoMas;
        edad = edadMas;
    }

    void setNombre(string nomNuevo) {
        nombre = nomNuevo;
    }

    void setTipo(string tipoNuevo) {
        tipo = tipoNuevo;
    }

    void setEdad(int edadNueva) {
        edad = edadNueva;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Edad: " << edad << endl;
    }
};

// EJERCICIO 5
class Pedido {
private:
    int codigo;
    string producto;
    int cantidad;
    int precioUnitario;

public:
    Pedido(int codPed, string prodPed, int cantPed, int precioPed) {
        codigo = codPed;
        producto = prodPed;
        cantidad = cantPed;
        precioUnitario = precioPed;
    }

    void setCantidad(int cantNueva) {
        cantidad = cantNueva;
    }

    void setPrecioUnitario(int precioNuevo) {
        precioUnitario = precioNuevo;
    }

    int calcularTotal() {
        int total = cantidad * precioUnitario;
        return total;
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

    Libro libro1("Cien años de soledad", "Gabriel Garcia Marquez", 432);
    cout << "Datos iniciales del libro:" << endl;
    libro1.mostrar();
    libro1.setPaginas(500);
    cout << "\nDatos despues de cambiar el numero de paginas:" << endl;
    libro1.mostrar();

    Producto prod1("Laptop", 4500);
    cout << "Datos iniciales del producto:" << endl;
    prod1.mostrar();
    prod1.setStock(20);
    prod1.setPrecio(4800);
    cout << "\nDatos actualizados del producto:" << endl;
    prod1.mostrar();

    Pelicula p1("Avatar", "", 0);
    Pelicula p2("Titanic", "", 0);
    Pelicula p3("Matrix", "", 0);

    string gen;
    int dur;

    cout << "Ingrese genero y duracion de Avatar:" << endl;
    cin >> gen;
    cin >> dur;
    p1.setGenero(gen);
    p1.setDuracion(dur);

    cout << "\nIngrese genero y duracion de Titanic:" << endl;
    cin >> gen;
    cin >> dur;
    p2.setGenero(gen);
    p2.setDuracion(dur);

    cout << "\nIngrese genero y duracion de Matrix:" << endl;
    cin >> gen;
    cin >> dur;
    p3.setGenero(gen);
    p3.setDuracion(dur);

    cout << "\n--- Lista de peliculas ---" << endl;
    p1.mostrar();
    cout << endl;
    p2.mostrar();
    cout << endl;
    p3.mostrar();

    p2.setDuracion(200);

    cout << "\n--- Lista de peliculas (duracion modificada) ---" << endl;
    p1.mostrar();
    cout << endl;
    p2.mostrar();
    cout << endl;
    p3.mostrar();

    Mascota m1("Firulais", "Perro", 0);
    Mascota m2("Mishi", "Gato", 0);
    Mascota m3("Luna", "Conejo", 0);

    int edadIngresada;

    cout << "Ingrese la edad de Firulais:" << endl;
    cin >> edadIngresada;
    m1.setEdad(edadIngresada);

    cout << "\nIngrese la edad de Mishi:" << endl;
    cin >> edadIngresada;
    m2.setEdad(edadIngresada);

    cout << "\nIngrese la edad de Luna:" << endl;
    cin >> edadIngresada;
    m3.setEdad(edadIngresada);

    cout << "\n--- Lista de mascotas ---" << endl;
    m1.mostrar();
    cout << endl;
    m2.mostrar();
    cout << endl;
    m3.mostrar();

    m2.setEdad(5);

    cout << "\n--- Lista de mascotas (una edad modificada) ---" << endl;
    m1.mostrar();
    cout << endl;
    m2.mostrar();
    cout << endl;
    m3.mostrar();

    Pedido ped1(1, "Teclado", 0, 0);
    Pedido ped2(2, "Mouse", 0, 0);

    int cant;
    int precio;

    cout << "Ingrese cantidad y precio unitario del pedido 1:" << endl;
    cin >> cant >> precio;
    ped1.setCantidad(cant);
    ped1.setPrecioUnitario(precio);

    cout << "\nIngrese cantidad y precio unitario del pedido 2:" << endl;
    cin >> cant >> precio;
    ped2.setCantidad(cant);
    ped2.setPrecioUnitario(precio);

    cout << "\n--- Pedidos registrados ---" << endl;
    ped1.mostrar();
    cout << endl;
    ped2.mostrar();

    ped1.setCantidad(10);

    cout << "\n--- Pedidos luego de modificar cantidad ---" << endl;
    ped1.mostrar();
    cout << endl;
    ped2.mostrar();

}