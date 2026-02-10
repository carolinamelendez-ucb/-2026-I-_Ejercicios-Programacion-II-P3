#include <iostream>
#include <string>

using namespace std;

//EJERCICIO 1
class Libro {
private:
    string titulo;
    string autor;
    int paginas;

public:
    Libro(string tituloLib, string autorLib, int paginasLib) {
        titulo = tituloLib;
        autor = autorLib;
        paginas = paginasLib;
    }

    void setTitulo(string nuevoTitulo) {
        titulo = nuevoTitulo;
    }

    void setAutor(string nuevoAutor) {
        autor = nuevoAutor;
    }

    void setPaginas(int nuevasPaginas) {
        paginas = nuevasPaginas;
    }

    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Paginas: " << paginas << endl;
    }
};

//EJERCICIO 2
class Producto {
private:
    string nombre;
    int precio;
    int stock;

public:
    Producto(string nombreProd, int precioProd) {
        nombre = nombreProd;
        precio = precioProd;
        stock = 0;
    }

    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    void setPrecio(int nuevoPrecio) {
        precio = nuevoPrecio;
    }

    void setStock(int nuevoStock) {
        stock = nuevoStock;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
    }
};

//EJERCICIO 3
class Pelicula {
private:
    string titulo;
    string genero;
    int duracion;

public:
    Pelicula(string tituloPeli, string generoPeli, int duracionPeli) {
        titulo = tituloPeli;
        genero = generoPeli;
        duracion = duracionPeli;
    }

    void setTitulo(string nuevoTitulo) {
        titulo = nuevoTitulo;
    }

    void setGenero(string nuevoGenero) {
        genero = nuevoGenero;
    }

    void setDuracion(int nuevaDuracion) {
        duracion = nuevaDuracion;
    }

    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion: " << duracion << " minutos" << endl;
    }
};

//EJERCICIO 4
class Mascota {
private:
    string nombre;
    string tipo;
    int edad;

public:
    Mascota(string nombreMasc, string tipoMasc, int edadMasc) {
        nombre = nombreMasc;
        tipo = tipoMasc;
        edad = edadMasc;
    }

    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    void setTipo(string nuevoTipo) {
        tipo = nuevoTipo;
    }

    void setEdad(int nuevaEdad) {
        edad = nuevaEdad;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Edad: " << edad << endl;
    }
};

//EJERCICIO 5
class Pedido {
private:
    int codigo;
    string producto;
    int cantidad;
    int precioUnitario;

public:
    Pedido(int codPed, string prodPed, int cantPed, int precioUnitPed) {
        codigo = codPed;
        producto = prodPed;
        cantidad = cantPed;
        precioUnitario = precioUnitPed;
    }

    void setCantidad(int nuevaCantidad) {
        cantidad = nuevaCantidad;
    }

    void setPrecioUnitario(int nuevoPrecio) {
        precioUnitario = nuevoPrecio;
    }

    int calcularTotal() {
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

int main()
{
    int op;

	Libro miLibro = Libro("Mi Planta de Naranja Lima", "Marcelo", 351);

    Producto miProducto = Producto("PC", 1500);

    Pelicula miPelicula1 = Pelicula("Interestellar", "Ciencia Ficción", 150);
    Pelicula miPelicula2 = Pelicula("Avatar", "Ciencia Ficción", 180);
    string genero;

	Mascota miMascota1 = Mascota("Drago", "Perro", 9);
    Mascota miMascota2 = Mascota("Chichico", "Gato", 4);
	int edad;

	Pedido miPedido1 = Pedido(458, "PlayStation", 10, 900);
	Pedido miPedido2 = Pedido(674, "LEGO", 20, 100);
    int cant, precio;

    do
    {
		cout << "Seleccione el numero de ejercico que quiera ver, o 0 para salir" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
			cout << "Ejercicio 1" << endl;
			miLibro.mostrar();
			miLibro.setPaginas(500);
            cout << "Despues de usar el set:" << endl;
			miLibro.mostrar();
            break;
        case 2:
			cout << "Ejercicio 2" << endl;
			miProducto.mostrar();
			miProducto.setStock(10);
			miProducto.setPrecio(1000);
			cout << "Despues de usar el set:" << endl;
			miProducto.mostrar();
            break;
        case 3:
			cout << "Ejercicio 3" << endl;
            cout << "Ingrese el genero para la primera pelicula" << endl;
            cin >> genero;
			miPelicula1.setGenero(genero);
            cout << "Ingrese el genero para la segunda pelicula" << endl;
			cin >> genero;
			miPelicula2.setGenero(genero);
			miPelicula1.mostrar();
			miPelicula2.mostrar();
			miPelicula1.setDuracion(100);
			cout << "Despues de usar el set:" << endl;
			miPelicula1.mostrar();
			miPelicula2.mostrar();
            break;
        case 4:
            cout << "Ejercicio 4" << endl;
            cout << "Ingrese la edad para la primera mascota" << endl;
            cin >> edad;
			miMascota1.setEdad(edad);
			cout << "Ingrese la edad para la segunda mascota" << endl;
            cin >> edad;
			miMascota2.setEdad(edad);
            miMascota1.mostrar();
            miMascota2.mostrar();
			miMascota1.setEdad(10);
            cout << "Despues de usar el set:" << endl;
			miMascota1.mostrar();
			miMascota2.mostrar();
            break;
        case 5:
			cout << "Ejercicio 5" << endl;
			cout << "Ingrese la cantidad para el primer pedido" << endl;
			cin >> cant;
			miPedido1.setCantidad(cant);
			cout << "Ingrese el precio unitario para el primer pedido" << endl;
			cin >> precio;
			miPedido1.setPrecioUnitario(precio);
			cout << "Ingrese la cantidad para el segundo pedido" << endl;
			cin >> cant;
			miPedido2.setCantidad(cant);
			cout << "Ingrese el precio unitario para el segundo pedido" << endl;
			cin >> precio;
			miPedido2.setPrecioUnitario(precio);
			miPedido1.mostrar();
			miPedido2.mostrar();
			miPedido1.setCantidad(5);
			cout << "Despues de usar el set:" << endl;
			miPedido1.mostrar();
			miPedido2.mostrar();
            break;
        }
	} while (op != 0);
    

}