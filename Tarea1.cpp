#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int paginas;
public:
    Libro(string tituloL, string autorL, int paginasL) {
        titulo = tituloL;
        autor = autorL;
        paginas = paginasL;
    }
    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "N de paginas: " << paginas << endl;
    }
    void setTitulo(string newTitulo) {
        this->titulo=newTitulo;
    }
    void setAutor(string newAutor) {
        this->autor=newAutor;
    }
    void setPaginas(int newPaginas) {
        this->paginas=newPaginas;
    }
};

class Producto {
private:
    string nombre;
    int precio;
    int stock;
public:
    Producto(string nombreP, int precioP, int stockP) {
        nombre = nombreP;
        precio = precioP;
        stock = stockP;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: Bs. " << precio << endl;
        cout << "Stock: " << stock << endl;
    }
    void setNombre(string newNombre) {
        this->nombre = newNombre;
    }
    void setPrecio(int newPrecio) {
        this->precio = newPrecio;
    }
    void setStock(int newStock) {
        this->stock = newStock;
    }
};

class Pelicula {
private:
    string titulo;
    string genero;
    int duracion; 

public:
    Pelicula(string tituloP) {
        titulo = tituloP;
    }
    void setTitulo(string newTitulo) {
        this->titulo = newTitulo; 
    }
    void setGenero(string newGenero) {
        this->genero = newGenero;
    }
    void setDuracion(int newDuracion) {
        this->duracion = newDuracion;
    }
    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion: " << duracion << " minutos" << endl;
    }
};

class Mascota {
private:
    string nombre;
    string tipo;
    int edad;
public: 
    Mascota(string nombreM, string tipoM) {
        nombre = nombreM;
        tipo = tipoM;
    }
    void setNombre(int newNombre) {
        this->nombre = newNombre;
    }
    void setTipo(int newTipo) {
        this->tipo = newTipo;
    }
    void setEdad(int newEdad) {
        this->edad = newEdad;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Edad: " << edad << " anios" << endl;
    }
};

class Pedido {
private:
    int codigo;
    string producto;
    int cantidad;
    int precioUnitario;
public:
    Pedido(int codigoP, string productoP) {
        codigo = codigoP;
        producto = productoP;
    }
    void setCantidad(int newCantidad) {
        this->cantidad = newCantidad;
    }
    void setPrecioUnitario(int newPrecioUnitario) {
        this->precioUnitario= newPrecioUnitario;
    }
    int calcularTotal(int cantidad, int precioUnitario) {
        int total;
        total = cantidad * precioUnitario;
        return total;
    }
    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio Unitario: Bs. " << precioUnitario << endl;
        cout << "Total pedido: Bs. " << calcularTotal(cantidad,precioUnitario) << endl;
    }
};

int main()
{
    cout << "== Ejercicio 1 ==" << endl;
    Libro libro("El principito", "Antoine de Saint-Exupery", 96);
    libro.mostrar();
    cout << "-> Cambio de numero de paginas" << endl;
    libro.setPaginas(100);
    libro.mostrar();
    cout << endl;
    cout << "== Ejercicio 2 ==" << endl;
    Producto producto("Shampoo", 42, 0);
    producto.mostrar();
    cout << "-> Actualizacion de precio y stock" << endl;
    producto.setPrecio(45);
    producto.setStock(50);
    producto.mostrar();
    cout << endl;
    cout << "== Ejercicio 3 ==" << endl;
    Pelicula pelicula1("Enredados");
    Pelicula pelicula2("Blanca Nieves");
    string genero;
    int duracion;
    cout << "Ingrese genero y duracion en minutos de Enredados: " << endl;
    cin >> genero >> duracion;
    pelicula1.setGenero(genero);
    pelicula1.setDuracion(duracion);
    cout << "Ingrese genero y duracion en minutos de Blanca Nieves: " << endl;
    cin >> genero >> duracion;
    pelicula2.setGenero(genero);
    pelicula2.setDuracion(duracion);
    cout << "-- Primera pelicula --" << endl;
    pelicula1.mostrar();
    cout << "-- Segunda pelicula --" << endl;
    pelicula2.mostrar();
    cout << "-> Actualizacion de duracion de Enredados" << endl;
    pelicula1.setDuracion(100);
    cout << "-- Primera pelicula --" << endl;
    pelicula1.mostrar();
    cout << "-- Segunda pelicula --" << endl;
    pelicula2.mostrar();
    cout << "== Ejercicio 4 ==" << endl;
    Mascota mascota1("Max", "Gato");
    Mascota mascota2("Jack", "Perro");
    int edad;
    cout << "Ingrese la edad su mascota: " << endl;
    cin >> edad;
    mascota1.setEdad(edad);
    cout << "Ingrese la edad su otra mascota: " << endl;
    cin >> edad;
    mascota2.setEdad(edad);
    cout << "-- Primera mascota --" << endl;
    mascota1.mostrar();
    cout << "-- Segunda mascota --" << endl;
    mascota2.mostrar();
    cout << "-> Actualizacion de edad de la segunda mascota" << endl;
    cout << "-- Primera mascota --" << endl;
    mascota1.mostrar();
    cout << "-- Segunda mascota --" << endl;
    mascota2.mostrar();
    cout << endl;
    cout << "== Ejercicio 5 ==" << endl;
    Pedido producto1(3465, "Lapiz");
    Pedido producto2(4539, "Resaltador");
    int cantidad, precioUnitario;
    cout << "Ingrese la cantidad y el precio unitario del primer producto: " << endl;
    cin >> cantidad >> precioUnitario;
    producto1.setCantidad(cantidad);
    producto1.setPrecioUnitario(precioUnitario);
    cout << "Ingrese la cantidad y el precio unitario del segundo producto: " << endl;
    cin >> cantidad >> precioUnitario;
    producto2.setCantidad(cantidad);
    producto2.setPrecioUnitario(precioUnitario);
    cout << "-- Primer producto --" << endl;
    producto1.mostrar();
    cout << "-- Segundo producto --" << endl;
    producto2.mostrar();
    cout << "-> Actualizacion de la cantidad del primer producto" << endl;
    producto1.setCantidad(10);
    cout << "-- Primer producto --" << endl;
    producto1.mostrar();
}
