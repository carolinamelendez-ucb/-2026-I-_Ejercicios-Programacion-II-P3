#include <iostream>
#include <string>
using namespace std;
//EJERCICIO 1
class Libro
{
private:
    string titulo;
    string autor;
    int paginas;
public:
    Libro(string tituloLibro, string autorLibro, int paginasLibro)
    {
        titulo = tituloLibro;
        autor = autorLibro;
        paginas = paginasLibro;
    }
    void setTitulo(string nuevoTitulo)
    {
        this->titulo = nuevoTitulo;
    }
    void setAutor(string nuevoAutor)
    {
        this->autor = nuevoAutor;
    }
    void setPaginas(int nuevoPaginas)
    {
        this->paginas = nuevoPaginas;
    }
    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Paginas: " << paginas << endl;
    }
};

//EJERCICIO 2
class Producto
{
private:
    string nombre;
    int precio;
    int stock;
public:
    Producto(string nombreProducto, int precioProducto)
    {
        nombre = nombreProducto;
        precio = precioProducto;
        stock = 0;
    }
    void setNombre(string nuevoNombre)
    {
        this->nombre = nuevoNombre;
    }
    void setPrecio(int nuevoPrecio)
    {
        this->precio = nuevoPrecio;
    }
    void setStock(int nuevoStock)
    {
        this->stock = nuevoStock;
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
    }
};

//EJERCICIO 3
class Pelicula
{
private:
    string titulo;
    string genero;
    int duracion;
public:
    Pelicula(string tituloPelicula, string generoPelicula, int duracionPelicula)
    {
        titulo = tituloPelicula;
        genero = generoPelicula;
        duracion = duracionPelicula;
    }
    void setTitulo(string nuevoTitulo)
    {
        this->titulo = nuevoTitulo;
    }
    void setGenero(string nuevoGenero)
    {
        this->genero = nuevoGenero;
    }
    void setDuracion(int nuevoDuracion)
    {
        this->duracion = nuevoDuracion;
    }
    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion: " << duracion << endl;
    }
};

//EJERCICIO 4
class Mascota
{
private:
    string nombre;
    string tipo;
    int edad;
public:
    Mascota(string nombreMascota, string tipoMascota, int edadMascota)
    {
        nombre = nombreMascota;
        tipo = tipoMascota;
        edad = edadMascota;
    }
    void setNombre(string nuevoNombre)
    {
        this->nombre = nuevoNombre;
    }
    void setTipo(string nuevoTipo)
    {
        this->tipo = nuevoTipo;
    }
    void setEdad(int nuevoEdad)
    {
        this->edad = nuevoEdad;
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Edad: " << edad << endl;
    }
};

//EJERCICIO 5
class Pedido
{
private:
    string codigo;
    string producto;
    int cantidad;
    int precioUnitario;
public:
    Pedido(string codigoPedido, string productoPedido, int cantidadPedido, int precioUnitarioPedido)
    {
        codigo = codigoPedido;
        producto = productoPedido;
        cantidad = cantidadPedido;
        precioUnitario = precioUnitarioPedido;
    }
    void setCantidad(int nuevoCantidad)
    {
        this->cantidad = nuevoCantidad;
    }
    void setPrecioUnitario(int nuevoPrecioUnitario)
    {
        this->precioUnitario = nuevoPrecioUnitario;
    }
    double calcularTotal()
    {
        return cantidad * precioUnitario;
    }

    void mostrar()
    {
        cout << "Codigo: " << codigo << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio Unitario: " << precioUnitario << endl;
        cout << "Total del Pedido:"<< calcularTotal() <<endl;
    }
};

int main()
{
    //EJERCICIO 1
    cout << "EJERCICIO 1" << endl;
    cout << "Libro 1: " << endl;
    Libro libro1 = Libro("La Odisea", "Homero", 400);
    libro1.mostrar();
    libro1.setPaginas(568);
    cout << "-------------------------------------" << endl;
    libro1.mostrar();
    cout << "-------------------------------------" << endl;
    //EJERCICIO 2
    cout << "EJERCICIO 2" << endl;
    cout << "Producto 1: " << endl;
    Producto producto1 = Producto("Laptop", 3500);
    producto1.mostrar();
    producto1.setStock(12);
    producto1.setPrecio(4210);
    cout << "-------------------------------------" << endl;
    producto1.mostrar();
    cout << "-------------------------------------" << endl;
    //EJERCICIO 3
    cout << "EJERCICIO 3" << endl;
    Pelicula pelicula1 = Pelicula("Avengers", "", 0);
    Pelicula pelicula2 = Pelicula("Crepusculo", "", 0);
    Pelicula pelicula3 = Pelicula("El Conjuro", "", 0);
    string genero;
    int duracion;
    cout << "Ingrese genero de la pelicula 1: ";
    cin >> genero;
    cout << "Ingrese duracion de la pelicula 1: ";
    cin >> duracion;
    pelicula1.setGenero(genero);
    pelicula1.setDuracion(duracion);
    cout << "Ingrese genero de la pelicula 2: ";
    cin >> genero;
    cout << "Ingrese duracion de la pelicula 2: ";
    cin >> duracion;
    pelicula2.setGenero(genero);
    pelicula2.setDuracion(duracion);
    cout << "Ingrese genero de la pelicula 3: ";
    cin >> genero;
    cout << "Ingrese duracion de la pelicula 3: ";
    cin >> duracion;
    pelicula3.setGenero(genero);
    pelicula3.setDuracion(duracion);
    cout << "-------------------------------------" << endl;
    cout << "Pelicula 1: " << endl;
    pelicula1.mostrar();
    cout << "Pelicula 2: " << endl;
    pelicula2.mostrar();
    cout << "Pelicula 3: " << endl;
    pelicula3.mostrar();
    pelicula2.setDuracion(175);
    cout << "-------------------------------------" << endl;
    cout << "Pelicula 1: " << endl;
    pelicula1.mostrar();
    cout << "Pelicula 2: " << endl;
    pelicula2.mostrar();
    cout << "Pelicula 3: " << endl;
    pelicula3.mostrar();
    cout << "-------------------------------------" << endl;
    //EJERCICIO 4
    cout << "EJERCICIO 4" << endl;
    Mascota mascota1 = Mascota("Firulais", "Perro", 0);
    Mascota mascota2 = Mascota("Gaspar", "Gato", 0);
    int edad;
    cout << "Ingrese edad de la mascota 1: ";
    cin >> edad;
    mascota1.setEdad(edad);
    cout << "Ingrese edad de la mascota 2: ";
    cin >> edad;
    mascota2.setEdad(edad);
    cout << "-------------------------------------" << endl;
    cout << "Mascota 1: " << endl;
    mascota1.mostrar();
    cout << "Mascota 2: " << endl;
    mascota2.mostrar();
    mascota2.setEdad(12);
    cout << "-------------------------------------" << endl;
    mascota1.mostrar();
    mascota2.mostrar();
    cout << "-------------------------------------" << endl;
    //EJERCICIO 5
    cout << "EJERCICIO 5" << endl;
    Pedido pedido1 = Pedido("1A", "Celular", 0, 0);
    Pedido pedido2 = Pedido("1B", "Laptop", 0, 0);
    int cantidad;
    int precioUnitario;
    cout << "Ingrese cantidad del pedido 1: ";
    cin >> cantidad;
    cout << "Ingrese precio unitario del pedido 1: ";
    cin >> precioUnitario;
    pedido1.setCantidad(cantidad);
    pedido1.setPrecioUnitario(precioUnitario);
    cout << "Ingrese cantidad del pedido 2: ";
    cin >> cantidad;
    cout << "Ingrese precio unitario del pedido 2: ";
    cin >> precioUnitario;
    pedido2.setCantidad(cantidad);
    pedido2.setPrecioUnitario(precioUnitario);
    cout << "-------------------------------------" << endl;
    cout << "Pedido 1: " << endl;
    pedido1.mostrar();
    cout << "Pedido 2: " << endl;
    pedido2.mostrar();
    pedido2.setCantidad(22);
    cout << "-------------------------------------" << endl;
    pedido2.mostrar();
}
