#include <iostream>
#include <string>

using namespace std;
class Libro
{

    private:

    string titulo;
    string autor;
    int numPaginas;

    public:

    Libro(string _titulo , string _autor , int _numPaginas)
    {
        this ->autor = _autor;
        this ->titulo = _titulo;
        this ->numPaginas = 0;
    }

    void mostrar()
    {
        cout << " Autor del libro : " << autor << endl;
        cout << " Titulo del libro : " << titulo << endl;
        cout << " Cantidad de pags del libro : " << numPaginas << endl;
    }

    void setAutor( string nuevoAutor)
    {
        this ->autor = nuevoAutor;
    }
    void setTitulo( string nuevoTitulo)
    {
        this ->titulo = nuevoTitulo;
    }
    void setNumPaginas( int nuevoNumPaginas)
    {
        this ->numPaginas = nuevoNumPaginas;
    }
};

class Producto
{
    private:
    string nombre;
    int precio;
    int stock;

    public:

    Producto(string _nombre , int _precio , int _stock)
    {
        this ->nombre = _nombre;
        this ->precio = _precio;
        this ->stock = _stock;
    }

    void mostrar()
    {
        cout << " Nombre del producto : " << nombre << endl;
        cout << " Precio del producto : " << precio << endl;
        cout << " Stock del producto : " << stock << endl;
    }

    void setNombre( string nuevoNombre)
    {
        this ->nombre = nuevoNombre;
    }
    void setPrecio( int nuevoPrecio)
    {
        this ->precio = nuevoPrecio;
    }
    void setStock( int nuevoStock)
    {
        this ->stock = nuevoStock;
    }
    

};

class Pelicula
{
    private:
    string titulo;
    int duracionMins;
    string genero;

    public:

    Pelicula(string _titulo,int _duracionMins,string _genero)
    {
        this ->titulo = _titulo;
        this ->duracionMins = _duracionMins;
        this->genero = _genero;
    }
    void mostrar()
    {
        cout <<"El TITULO : " << titulo << endl;
        cout <<" Duracion En mins " << duracionMins <<endl;
        cout <<"Genero : " << genero<<endl;
    }

    void setTitulo( string nuevoTitulo)
    {
        this ->titulo = nuevoTitulo;
    }
    void setDuracionMins( int nuevaDuracion)
    {
        this ->duracionMins = nuevaDuracion;
    }
    void setGenero( string nuevoGenero)
    {
        this ->genero = nuevoGenero;
    }




};

class Mascota
{
    private:
    string nombre;
    string tipo;
    int edad;

    public:

    Mascota(string _nombre , string _tipo , int _edad)
    {
        this ->nombre = _nombre;
        this ->tipo = _tipo;
        this ->edad = _edad;
    }

    void mostrar()
    {
        cout << " Nombre de la mascota : " << nombre << endl;
        cout << " Tipo de mascota : " << tipo << endl;
        cout << " Edad de la mascota : " << edad << endl;
    }

    void setNombre(string nuevoNombre)
    {
        this ->nombre = nuevoNombre;
    }

    void setTipo(string nuevoTipo)
    {
        this ->tipo = nuevoTipo;
    }

    void setEdad(int nuevaEdad)
    {
        this ->edad = nuevaEdad;
    }
};

class Pedido
{
    private:
    string codigo;
    string producto;
    int cantidad;
    int precioUnitario;

    public:

    Pedido(string _codigo , string _producto , int _cantidad , int _precioUnitario)
    {
        this ->codigo = _codigo;
        this ->producto = _producto;
        this ->cantidad = _cantidad;
        this ->precioUnitario = _precioUnitario;
    }

    void setCantidad(int nuevaCantidad)
    {
        this ->cantidad = nuevaCantidad;
    }

    void setPrecioUnitario(int nuevoPrecio)
    {
        this ->precioUnitario = nuevoPrecio;
    }

    int calcularTotal()
    {
        return cantidad * precioUnitario;
    }

    void mostrar()
    {
        cout << " Codigo del pedido : " << codigo << endl;
        cout << " Producto : " << producto << endl;
        cout << " Cantidad : " << cantidad << endl;
        cout << " Precio Unitario : " << precioUnitario << endl;
        cout << " Total del pedido : " << calcularTotal() << endl;
    }
};

int main()
{
/*

        //    EJERCICIO 1 MAIN
    Libro libro1 = Libro("Harry Poter", "Howard no se XD",300);
    libro1.mostrar();
    libro1.setNumPaginas(250);
    libro1.mostrar();
*/
/*'

      ///  EJERCICIO 2 MAIN
    Producto producto1 = Producto("Ace Patito",100,50);
    producto1.mostrar();
    producto1.setStock(200);
    producto1.setPrecio(100);
    producto1.mostrar();
*/

/*
            /// EJERCICIO 3 MAIN
    Pelicula pelicula1 = Pelicula("AVATAR  " , 0, "" ); 
    Pelicula pelicula2 = Pelicula("CARS  " , 0, "" ); 

    string genero;
    int duracion; //mins

    cout << "Ingresa Genero y duracion AVATAR " << endl;
    cin >> genero;
    cin >>duracion;
    pelicula1.setGenero(genero);
    pelicula1.setDuracionMins(duracion);

    cout << "Ingresa Genero y duracion CARS " << endl;
    cin >> genero;
    cin >>duracion;
    pelicula2.setGenero(genero);
    pelicula2.setDuracionMins(duracion);

    pelicula1.mostrar();
    pelicula2.mostrar();

    pelicula1.setDuracionMins(500);

    pelicula1.mostrar();

*/

/*
            /// EJERCICIO 4 MAIN

    Mascota mascota1 = Mascota("Firulais", "Perro", 0);
    Mascota mascota2 = Mascota("Michi", "Gato", 0);

    int edad;

    cout << "Ingresa edad de Firulais" << endl;
    cin >> edad;
    mascota1.setEdad(edad);

    cout << "Ingresa edad de Michi" << endl;
    cin >> edad;
    mascota2.setEdad(edad);

    mascota1.mostrar();
    mascota2.mostrar();

    mascota1.setEdad(10);

    cout << "Despues de modificar edad :" << endl;
    mascota1.mostrar();
    mascota2.mostrar();
*/



            /// EJERCICIO 5 MAIN

    Pedido pedido1 = Pedido("001", "Laptop", 0, 0);
    Pedido pedido2 = Pedido("002", "Mouse", 0, 0);

    int cantidad;
    int precio;

    cout << "Ingresa cantidad y precio unitario del pedido 1" << endl;
    cin >> cantidad;
    cin >> precio;
    pedido1.setCantidad(cantidad);
    pedido1.setPrecioUnitario(precio);

    cout << "Ingresa cantidad y precio unitario del pedido 2" << endl;
    cin >> cantidad;
    cin >> precio;
    pedido2.setCantidad(cantidad);
    pedido2.setPrecioUnitario(precio);

    pedido1.mostrar();
    pedido2.mostrar();

    pedido1.setCantidad(10);

    cout << "Despues de modificar cantidad del pedido 1 :" << endl;
    pedido1.mostrar();
    pedido2.mostrar();






    return 0;
}