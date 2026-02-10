// Tarea_Dania Cano.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// MI PRIMER OBJETO
#include <iostream>
#include <string>
using namespace std;

//EJERCICIO 1 =========================================================================================================

class Libro
{

    //ATRIBUTOS 
private:
    string titulo;
    string autor;
    int paginas;
public:
    Libro(string tituloM, string autorM, int paginasM)
    {
        titulo = tituloM;
        autor = autorM;
        paginas = paginasM;
    }

    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Paginas: " << paginas << endl;
    }

    void setTitulo(string nuevotitulo)
    {
        titulo = nuevotitulo;
    }
    void setAutor(string nuevoautor)
    {
        autor = nuevoautor;
    }
    void setPaginas(int nuevoPaginas)
    {
        paginas = nuevoPaginas;
    }
};
//EJERCICIO 2 =================================================================================00

class Producto
{

    //ATRIBUTOS 
private:
    string nombre;
    int precio;
    int stock;
public:
    Producto(string nombreM, int precioM)
    {
        nombre = nombreM;
        precio = precioM;
        stock = 0;
    }

    void mostrar()
    {
        cout << "nombre: " << nombre << endl;
        cout << "precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
    }

    void setnombre(string nuevonombre)
    {
        nombre = nuevonombre;
    }
    void setprecio(int nuevoprecio)
    {
        precio = nuevoprecio;
    }
    void setstock(int nuevostock)
    {
        stock = nuevostock;
    }
};

//EJERCICIO 3 =================================================================================00

class pelicula
{

    //ATRIBUTOS 
private:
    string titulo;
    string genero;
    int duracion;
public:
    pelicula(string tituloM, string generoM, int duracionM)
    {
        titulo = tituloM;
        genero = generoM;
        duracion = duracionM;
    }

    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion: " << duracion << endl;
    }

    void settitulo(string nuevotitulo)
    {
        titulo = nuevotitulo;
    }
    void setgenero(string nuevogenero)
    {
        genero = nuevogenero;
    }
    void setduracion(int nuevaduracion)
    {
        duracion = nuevaduracion;
    }
};
//EJERCICIO 4 =================================================================================00

class mascota
{

    //ATRIBUTOS 
private:
    string nombre;
    string tipo;
    int edad;
public:
    mascota(string nombreM,string tipoM, int edadM)
    {
        nombre = nombreM;
        tipo = tipoM;
        edad = edadM;
    }

    void mostrar()
    {
        cout << "nombre: " << nombre << endl;
        cout << "tipo: " << tipo << endl;
        cout << "edad: " << edad << endl;
    }

    void setnombre(string nuevonombre)
    {
        nombre = nuevonombre;
    }
    void settipo(string nuevotipo)
    {
        tipo = nuevotipo;
    }
    void setedad(int nuevoedad)
    {
        edad = nuevoedad;
    }
};

//EJERCICIO 5 =================================================================================00

class pedido
{

    //ATRIBUTOS 
private:
    int codigo;
    string producto;
    int cantidad;
    float precioUni;
public:
    pedido(int codigoM, string productoM,int cantidadM, float precioUniM)
    {
        codigo = codigoM;
        producto = productoM;
        cantidad = cantidadM;
        precioUni = precioUniM;
    }

    void mostrar()
    {
        cout << "codigo: " << codigo << endl;
        cout << "producto: " << producto << endl;
        cout << "camtidad: " << cantidad << endl;
        cout << "preio Unitario: " << precioUni << endl;
        cout << "Total del pedido: " << calcularTotal() << endl;
    }

    void setcantidad(int nuevocantidad)
    {
        cantidad = nuevocantidad;
    }
   
    void setprecioUni(float nuevoprecioUni)
    {
        precioUni = nuevoprecioUni;

    }
    float calcularTotal()
    {
        return cantidad*precioUni;

    }
};

int main()
{
    //EJERCICIO 1
    cout << "EJERICICIO 1: Libro1" << endl;
    Libro libro1 = Libro("La vida es bella", "Roberto Benigni", 300);
    libro1.mostrar();
    libro1.setPaginas(244);
    cout << "Modificacion de paginas" << endl;
    libro1.mostrar();

    //EJERCICIO 2
    cout << "EJERICICIO 2: Producto1" << endl;
    Producto Producto1= Producto("Laptop", 3500);
    Producto1.mostrar();
    Producto1.setstock(15);
    Producto1.setprecio(2399);
    cout << "Resultado de datos con modificacion" << endl;
    Producto1.mostrar();

    //EJERCICIO 3
    cout << "EJERICICIO 3: Pelicula1" << endl;
    pelicula pelicula1 = pelicula("Zootopia", " ", 0);
    pelicula pelicula2 = pelicula("Harry Potter", " ", 0);
    string gen;
    int durac;

    cout << "Ingrese genero de la pelicula Zootopia: ";
    cin >> gen;
    cout << "Ingrese duracion de la pelicula Zootopia: ";
    cin >> durac;
    pelicula1.setgenero(gen);
    pelicula1.setduracion(durac);

    cout << "Ingrese genero de la pelicula Harry Ptter: ";
    cin >> gen;
    cout << "Ingrese duracion de la pelicula Harry Potter: ";
    cin >> durac;
    pelicula2.setgenero(gen);
    pelicula2.setduracion(durac);
    cout << "Mostramos datos" << endl;
    pelicula1.mostrar();
    pelicula2.mostrar();

    pelicula1.setduracion(200);
    cout << "Resultado de datos con modificacion" << endl;
    pelicula1.mostrar();
    pelicula2.mostrar();

    
    //EJERCICIO 4
    cout << "EJERICICIO 4: mascota1" << endl;
    mascota mascota1 = mascota("TOTO","perro", 7);
    mascota mascota2 = mascota("Temp", "gato", 6);
    int eda;
    cout << "Ingrese la edad de la mascota1: ";
    cin >> eda;
    mascota1.setedad(eda);
    cout << "Ingrese la edad de la mascota2: ";
    cin >> eda;
    mascota2.setedad(eda);
    cout << "Mostramos datos" << endl;
    mascota1.mostrar();
    mascota2.mostrar();
    mascota2.setedad(10);
    cout << "Resultado de datos con modificacion" << endl;
    mascota1.mostrar();
    mascota2.mostrar();

    //EJERCICIO 5
    cout << "EJERICICIO 5: pedido1" << endl;

    pedido pedido1 = pedido(1, "Cuaderno", 0, 0);
    pedido pedido2 = pedido(2, "Mochila", 0, 0);

    int cant;
    float precioU;

    cout << "Ingrese cantidad del pedido1: ";
    cin >> cant;
    cout << "Ingrese precio unitario del pedido1: ";
    cin >> precioU;
    pedido1.setcantidad(cant);
    pedido1.setprecioUni(precioU);

    cout << "Ingrese cantidad del pedido2: ";
    cin >> cant;
    cout << "Ingrese precio unitario del pedido2: ";
    cin >> precioU;
    pedido2.setcantidad(cant);
    pedido2.setprecioUni(precioU);

    cout << "Mostramos pedidos" << endl;
    pedido1.mostrar();
    pedido2.mostrar();

    // modificamos solo uno
    pedido1.setcantidad(23);

    cout << "Resultado con modificacion" << endl;
    pedido1.mostrar();
    pedido2.mostrar();

   


   
    
}
