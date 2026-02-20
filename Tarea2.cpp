// Tarea2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
# include <string>
using namespace std;
class Libro
{
private:
    string titulo;
    string autor;
    int pag;
public:
    Libro(string titulo, string autor, int pag)
    {
        this->titulo = titulo;
        this->autor = autor;
        this->pag = pag;
    }
    void mostrar()
    {
        cout << "titulo del libro: " << titulo << endl;
        cout << " el nombre del autor: " << autor << endl;
        cout << "la cantiad de paginas: " << pag << endl;
    }
    void setTiltulo(string Ntitulo)
    {
        this->titulo = Ntitulo;
    }
    void setAutor(string Nautor)
    {
        this->autor = Nautor;
    }
    void setPaginas(int Npag )
    {
        this->pag = Npag;
    }
};
class Producto
{
private:
    string nombre;
    int precio;
    int stock;

public:
    Producto(string nombre, int precio)
    {
        this->nombre = nombre;
        this->precio = precio;
        this->stock = 0;
    }
    void mostrar()
    {
        cout << "el nombre del producto: " <<nombre  << endl;
        cout << "el precio del producto: " <<precio << endl;
        cout << "" << "el stock: "<<stock << endl;
    }
    void setNombre(string Nnombre)
    {
        this->nombre = Nnombre;
    }
    void setPrecio(int Nprecio)
    {
        this->precio = Nprecio;
    }
    void setStock(int Nstock)
    {
        this->stock = Nstock;
    }
};
class Pelicula
{
private:
    string titulo;
    string genero;
    int duracion;

public:
    Pelicula(string titulo, string genero, int duracion)
    {
        this->titulo = titulo;
        this->genero = genero;
        this->duracion = duracion;
    }
    void setTitulo(string Ntitulo)
    {
        this->titulo = Ntitulo;
    }
    void setGenero(string Ngenero)
    {
        this->genero = Ngenero;
    }
    void setDuracion(int Nduracion)
    {
        this->duracion = Nduracion;
    }
    void mostrar()
    {

        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion: " << duracion << endl;
    }

};
class Mascota
{
private:
    string nombre;
    string tipo;
    int edad;
public:
    Mascota(string nombre, string tipo, int edad)
    {
        this->nombre = nombre;
        this->tipo = tipo;
        this->edad = edad;
    }
    void setNombre(string Nnombre)
    {
        this->nombre = Nnombre;
    }
    void setTipo(string Ntipo)
    {
        this->tipo = Ntipo;
    }
    void setEdad(int Nedad)
    {
        this->edad = Nedad;
    }
    void mostrar()
    {

        cout << "nombre: " << nombre << endl;
        cout << "tipo: " << tipo << endl;
        cout << "edad: " << edad << endl;
       
    }
};
class Pedido
{
private:
    int codigo;
    string producto;
    int cantidad;
    float precioUnitario;
public:
    Pedido(int codigo, string producto,int cantidad,float precioUnitario)
    {
        this->codigo = codigo;
        this->producto = producto;
        this->cantidad = cantidad;
        this->precioUnitario = precioUnitario;
   }
    void setCantidad(int Ncantidad)
    {
        this->cantidad = Ncantidad;
    }

    void setPrecioUnitario(float Nprecio)
    {
        this->precioUnitario = Nprecio;
    }
    float calcularTotal()
    {
        return cantidad * precioUnitario;
    }
    void mostrar()
    {
        cout << "Codigo: " << codigo << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio unitario: " << precioUnitario << endl;
        cout << "Total del pedido: " << calcularTotal() << endl;
      
    }
};


int main()
{
   
    cout << "---------------Ejercicio 1-----------------" << endl;
    Libro libro1 = Libro("Cien anios de soledad", "Gabriel Garcia MArquez", 350);
    libro1.mostrar();
    libro1.setPaginas(220);
    cout << "--------------Ahora el nuevo libro tendra: -----------------" << endl;
    libro1.mostrar();
   
    cout << "---------------Ejercicio 2-----------------" << endl;
    Producto producto1 = Producto("esponjas",300);
    producto1.mostrar();
    producto1.setPrecio(500);
    producto1.setStock(4);
    cout << "----- Producto actualizado -----" << endl;
    producto1.mostrar();
     
    cout << "---------------Ejercicio 3-----------------" << endl;
    string genero;
    int duracion;
    Pelicula pelicula1 = Pelicula("terminator", "", 0);
    Pelicula pelicula2 = Pelicula("Rapidos y furiosos", "", 0);
    Pelicula pelicula3 = Pelicula("culpa mia", "", 0);
 
    cout << "ingrese Genero de la Pelicula 1: "<<endl;
    cin >> genero;
    cout << "ingrese la duracion de la Pelicula 1 en minutos: "<< endl;
    cin >> duracion;
    pelicula1.setGenero(genero);
    pelicula1.setDuracion(duracion);
    cout << "-----------Pelicula 1----------------" << endl;
    pelicula1.mostrar();

    cout << "ingrese Genero de la Pelicula 2: " << endl;
    cin >> genero;
    cout << "ingrese la duracion de la Pelicula 2 en minutos: " << endl;
    cin >> duracion;
    pelicula2.setGenero(genero);
    pelicula2.setDuracion(duracion);
    cout << "-----------Pelicula 2----------------" << endl;
    pelicula2.mostrar();

    cout << "ingrese Genero de la Pelicula 3: " << endl;
    cin >> genero;
    cout << "ingrese la duracion de la Pelicula 3 en minutos: " << endl;
    cin >> duracion;
    pelicula3.setGenero(genero);
    pelicula3.setDuracion(duracion);
    cout << "-----------Pelicula 3----------------" << endl;
    pelicula3.mostrar();
    pelicula1.setDuracion(120);
    cout << "-------------Existe un cambio en la pelicula 1------------------" << endl;
    pelicula1.mostrar();
  
    cout << "---------------Ejercicio 4-----------------" << endl;
    int edad;
    Mascota mascota1 = Mascota("tibon", "bulldog", 0);
    Mascota mascota2 = Mascota("Luck", "pastor aleman", 0);
    Mascota mascota3 = Mascota("Max", "salchicha", 0);
    cout << "Ingrese la edad de la mascota 1: " << endl;
    cin >> edad;
    mascota1.setEdad(edad);
    mascota1.mostrar();
    cout << "Ingrese la edad de la mascota 2: " << endl;
    cin >> edad;
    mascota2.setEdad(edad);
    mascota2.mostrar();
    cout << "Ingrese la edad de la mascota 3: " << endl;
    cin >> edad;
    mascota3.setEdad(edad);
    mascota3.mostrar();
    mascota1.setEdad(3);
    cout << "-------------------" << endl;
    mascota1.mostrar();
    mascota2.mostrar();
    mascota3.mostrar();
     
    cout << "---------------Ejercicio 5-----------------" << endl;
    int cantidad;
    float precioUnitario;
    Pedido pedido1 = Pedido(1212, "lavavajillas", 0, 0);
    Pedido pedido2 = Pedido(2324, "oso de peluche", 0, 0);

    cout << "Ingrese la cantidad del pedidio 1: " << endl;
    cin >> cantidad;
    cout << "Ingrese el precio unitario del pedido 1: " << endl;
    cin >> precioUnitario;
    pedido1.setCantidad(cantidad);
    pedido1.setPrecioUnitario(precioUnitario);
    pedido1.mostrar();

    cout << "Ingrese la cantidad del pedidio 2: " << endl;
    cin >> cantidad;
    cout << "Ingrese el precio unitario del pedido 2: " << endl;
    cin >> precioUnitario;
    pedido2.setCantidad(cantidad);
    pedido2.setPrecioUnitario(precioUnitario);
    pedido2.mostrar();
    cout << "------------------------" << endl;
    pedido2.setCantidad(15);
    pedido2.mostrar();


}
