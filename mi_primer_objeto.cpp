#include <iostream>
#include <string>

using namespace std;

//  ---  EJERCICIO 1 ---
class Libro{
private:
    string titulo;
    string autor;
    int paginas;
public:
    Libro(string tituloL, string autorL, int paginasL) {
        this->titulo = tituloL;
        this->autor = autorL;
        this->paginas = paginasL;
    }
    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Paginas: " << paginas << endl;
    }
    void setPaginas(int nuevaPag) {
        this->paginas = nuevaPag;
    }
}; 

//  ---  EJERCICIO 2 ---
class Producto {
private:
    string nombre;
    int precio;
    int stock;
public:
    Producto(string nombreP, int precioP, int stockP) {
        this->nombre = nombreP;
        this->precio = precioP;
        this->stock = 0;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
    }
    void setNombre(string nuevoNombre) {
        this->nombre = nuevoNombre;
    }
    void setPrecio(int nuevoPrecio) {
        this->precio = nuevoPrecio;
    }
    void setStock(int nuevoStock) {
        this->stock = nuevoStock;
    }
};

//  ---  EJERCICIO 3 ---
class Pelicula {
private:
    string titulo;
    string genero;
    int duracion;
public:
    Pelicula(string tituloP, string generoP, int duracionP) {
        this->duracion = duracionP;
        this->genero = generoP;
        this->titulo = tituloP;
    }
    void mostrar() {
        cout << "titulo: " << titulo << endl;
        cout << "genero: " << genero << endl;
        cout << "duracion: " << duracion << endl;
    }
    void setTitulo(string nuevoTitulo) {
        this->titulo = nuevoTitulo ;
    }
    void setGenero(string nuevoGenero) {
        this->genero = nuevoGenero;
    }
    void setDuracion(int nuevaDuracion) {
        this->duracion = nuevaDuracion;
    }
};

//  --- EJERCICIO 4 --- 
class Mascota {
private:
    string nombre;
    string tipo;
    int edad;
public:
    Mascota(string nombreM, string tipoM, int edadM) {
        this->edad = edadM;
        this->nombre = nombreM;
        this->tipo = tipoM;
    }
    void mostrar() {
        cout << "nombre: " << nombre << endl;
        cout << "edad: " << edad << endl;
        cout << "tipo: " << tipo << endl;
    }
    void setNombre(string nuevoNombre) {
        this->nombre = nuevoNombre;
    }
    void setEdad(int nuevoEdad) {
        this->edad = nuevoEdad;
    }
    void setTipo(string nuevoTipo) {
        this->tipo = nuevoTipo;
    }
};

//  --- EJERCICIO 5 --- 
class Pedido {
private:
    int codigo;
    string producto;
    int cantidad;
    float precioUnitario;
public:
    Pedido(int codigoP, string prductoP, int cantidadP, float precioUnitarioP) {
        this->cantidad = cantidadP;
        this->codigo = codigoP;
        this->precioUnitario = precioUnitarioP;
        this->producto = prductoP;
    }
    void setCantidad(int nuevaCantidad) {
        this->cantidad = nuevaCantidad;
    }
    void setPrecioUnitario(float nuevPrecioUnitario) {
        this->precioUnitario = nuevPrecioUnitario;
    }
    int calcularTotal(int cantidad,float precioUnitario) {
        float totalPrecio;
        totalPrecio = (cantidad * precioUnitario);
        return totalPrecio;
    }
    void mostrar() {
        int total;
        cout << "Codigo: " << codigo << endl;
        cout << "Producto: " << producto << endl;
        cout << "cantidad: " << cantidad << endl;
        cout << "Precio Unitario: " << precioUnitario << endl;
        total = calcularTotal(cantidad, precioUnitario);
        cout << "Total Pedido" << total << endl;
    }
};
int main()  
{
    //---  EJERCICIO 1 ---
    Libro Libro1=Libro("Harry Potter","j.k.Rowling",321);
    cout << "Datos del libro " << endl;
    Libro1.mostrar();
    Libro1.setPaginas(320);
    cout << "actualizacion de Pag. del libro" << endl;
    Libro1.mostrar();
    cout << endl;

    //---  EJERCICIO 2 ---
    Producto Producto1 = Producto("coca-cola", 20, 50);
    cout << "Datos del producto" << endl;
    Producto1.mostrar();
    Producto1.setStock(49);
    Producto1.setPrecio(18);
    cout << "actualizacion del producto" << endl;
    Producto1.mostrar();

    //---  EJERCICIO 3 ---
    Pelicula pelicula1=Pelicula("narnia","-",0);
    string generoP1;
    int duracionP1;
    cout << "Ingrese la duracion de la pelicula 1: "; cin >> duracionP1;
    cout << "Ingrese el genero de la pelicula 1: "; cin >> generoP1;
    pelicula1.setGenero(generoP1);
    pelicula1.setDuracion(duracionP1);

    Pelicula pelicula2 = Pelicula("Avatar", "-", 0);
    string generoP2;
    int duracionP2;
    cout << "Ingrese la duracion de la pelicula 2: "; cin >> duracionP2;
    cout << "Ingrese el genero de la pelicula 2: "; cin >> generoP2;
    pelicula2.setGenero(generoP2);
    pelicula2.setDuracion(duracionP2);
    cout << endl;
    cout << "Datos de Peliculas registradas " << endl;
    pelicula1.mostrar();
    pelicula2.mostrar();
    cout << endl;
    pelicula1.setDuracion(40);
    cout << "Duracion actualizada: " << endl;
    pelicula1.mostrar();
    pelicula2.mostrar();

    //---  EJERCICIO 4 ---
    Mascota mascota1 = Mascota("duki", "cocker", 5);
    Mascota mascota2 = Mascota("enzo", "pitbull", 4);
    int edad1;
    int edad2;
    cout << "Ingrese la edad de la mascota 1: "; cin >> edad1;
    cout << "Ingrese la edad de la mascota 2: "; cin >> edad2;
    mascota1.setEdad(edad1);
    mascota2.setEdad(edad2);
    cout << "Datos de las mascotas registradas: " << endl;
    mascota1.mostrar();
    mascota2.mostrar();
    mascota1.setEdad(5);
    cout << "Datos de las mascotas Actualizadas: " << endl;
    mascota1.mostrar();
    mascota2.mostrar();

    //---  EJERCICIO 5 ---
    int cantidad1; int cantidad2;
    float precio1; float precio2;
    Pedido pedido1 = Pedido(1234, "Sprite", 4, 3);
    Pedido pedido2 = Pedido(1235, "Fanta", 5, 3.5);
    cout << "Ingrese la cantidad del pedido 1: "; cin >> cantidad1;
    cout << "Ingrese el precio Unitario del pedido: "; cin >> precio1;
    cout << "Ingrese la cantidad del pedido 2: "; cin >> cantidad2;
    cout << "Ingrese el precio Unitario del pedido: "; cin >> precio2;
    pedido1.setCantidad(cantidad1);
    pedido1.setPrecioUnitario(precio1);
    pedido2.setCantidad(cantidad2);
    pedido2.setPrecioUnitario(precio2);

    cout << "---lista de pedidos --- " << endl;
    cout << "--Pedido 1--" << endl;
    pedido1.mostrar();
    cout << "--Pedido 2--" << endl;
    pedido2.mostrar();

    pedido1.setPrecioUnitario(4.5);
    cout << "---Cambio actualizado---" << endl;
    pedido1.mostrar();

}