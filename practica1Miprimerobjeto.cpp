#include <iostream>
#include <string>
using namespace std;

// ========== CLASE LIBRO (Ejercicio 1) ==========
class Libro {
private:
    string titulo;
    string autor;
    int paginas;

public:
    // Constructor
    Libro(string t, string a, int p) {
        titulo = t;
        autor = a;
        paginas = p;
    }

    // Setters
    void setTitulo(string t) { titulo = t; }
    void setAutor(string a) { autor = a; }
    void setPaginas(int p) { paginas = p; }

    // Método mostrar
    void mostrar() {
        cout << "=== LIBRO ===" << endl;
        cout << "Título: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Páginas: " << paginas << endl;
        cout << "==============" << endl;
    }
};

// ========== CLASE PRODUCTO (Ejercicio 2) ==========
class Producto {
private:
    string nombre;
    double precio;
    int stock;

public:
    // Constructor (stock inicia en 0)
    Producto(string n, double p) {
        nombre = n;
        precio = p;
        stock = 0;
    }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setPrecio(double p) { precio = p; }
    void setStock(int s) { stock = s; }

    // Método mostrar
    void mostrar() {
        cout << "=== PRODUCTO ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Stock: " << stock << " unidades" << endl;
        cout << "================" << endl;
    }
};

// ========== CLASE PELICULA (Ejercicio 3) ==========
class Pelicula {
private:
    string titulo;
    string genero;
    int duracion; // en minutos

public:
    // Constructor
    Pelicula(string t, string g, int d) {
        titulo = t;
        genero = g;
        duracion = d;
    }

    // Setters
    void setTitulo(string t) { titulo = t; }
    void setGenero(string g) { genero = g; }
    void setDuracion(int d) { duracion = d; }

    // Método mostrar
    void mostrar() {
        cout << "=== PELÍCULA ===" << endl;
        cout << "Título: " << titulo << endl;
        cout << "Género: " << genero << endl;
        cout << "Duración: " << duracion << " minutos" << endl;
        cout << "================" << endl;
    }
};

// ========== CLASE MASCOTA (Ejercicio 4) ==========
class Mascota {
private:
    string nombre;
    string tipo;
    int edad;

public:
    // Constructor
    Mascota(string n, string t, int e) {
        nombre = n;
        tipo = t;
        edad = e;
    }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setTipo(string t) { tipo = t; }
    void setEdad(int e) { edad = e; }

    // Método mostrar
    void mostrar() {
        cout << "=== MASCOTA ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "================" << endl;
    }
};

// ========== CLASE PEDIDO (Ejercicio 5) ==========
class Pedido {
private:
    string codigo;
    string producto;
    int cantidad;
    double precioUnitario;

public:
    // Constructor
    Pedido(string c, string p, int cant, double precio) {
        codigo = c;
        producto = p;
        cantidad = cant;
        precioUnitario = precio;
    }

    // Setters (solo para cantidad y precioUnitario como pide el ejercicio)
    void setCantidad(int c) { cantidad = c; }
    void setPrecioUnitario(double p) { precioUnitario = p; }

    // Método para calcular el total
    double calcularTotal() {
        return cantidad * precioUnitario;
    }

    // Método mostrar
    void mostrar() {
        cout << "=== PEDIDO ===" << endl;
        cout << "Código: " << codigo << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio Unitario: $" << precioUnitario << endl;
        cout << "Total: $" << calcularTotal() << endl;
        cout << "==============" << endl;
    }
};

// ========== FUNCIÓN MAIN ==========
int main() {
    cout << "===== EJERCICIO 1: LIBRO =====" << endl;

    // 1. Crear un libro
    Libro libro1("Cien años de soledad", "Gabriel Garcia Marquez", 417);

    // 2. Mostrar sus datos
    cout << "\nDatos iniciales del libro:" << endl;
    libro1.mostrar();

    // 3. Cambiar el número de páginas
    libro1.setPaginas(450);

    // 4. Volver a mostrar
    cout << "\nDespues de cambiar paginas:" << endl;
    libro1.mostrar();

    cout << "\n===== EJERCICIO 2: PRODUCTO =====" << endl;

    // 1. Crear producto
    Producto producto1("Laptop", 1200.50);

    // 2. Mostrar
    cout << "\nProducto inicial:" << endl;
    producto1.mostrar();

    // 3. Actualizar stock
    producto1.setStock(15);

    // 4. Actualizar precio
    producto1.setPrecio(1100.75);

    // 5. Mostrar nuevamente
    cout << "\nProducto actualizado:" << endl;
    producto1.mostrar();

    cout << "\n===== EJERCICIO 3: PELICULA =====" << endl;

    // 1. Crear 3 objetos Pelicula
    Pelicula peli1("El Padrino", "Drama", 175);
    Pelicula peli2("Matrix", "Ciencia Ficcion", 136);
    Pelicula peli3("Toy Story", "Animacion", 81);

    // 2. y 3. Simulamos pedir por consola y usar setters
    // (En lugar de pedir por consola, usamos valores predefinidos)
    peli1.setGenero("Crimen");
    peli1.setDuracion(177);

    peli2.setGenero("Accion");
    peli2.setDuracion(138);

    peli3.setGenero("Aventura");
    peli3.setDuracion(81);

    // 4. Mostrar la información de todas las películas
    cout << "\nInformacion de todas las peliculas:" << endl;
    peli1.mostrar();
    peli2.mostrar();
    peli3.mostrar();

    // 5. Modificar la duración de una película
    peli1.setDuracion(180);

    // 6. Volver a mostrar todas
    cout << "\nDespues de modificar la duracion de la primera pelicula:" << endl;
    peli1.mostrar();
    peli2.mostrar();
    peli3.mostrar();

    cout << "\n===== EJERCICIO 4: MASCOTA =====" << endl;

    // 1. Crear 3 objetos Mascota
    Mascota mascota1("Max", "Perro", 3);
    Mascota mascota2("Mishi", "Gato", 2);
    Mascota mascota3("Lola", "Conejo", 1);

    // 2. y 3. Simulamos pedir edades por consola
    // (En lugar de pedir por consola, usamos setters)
    mascota1.setEdad(4);
    mascota2.setEdad(3);
    mascota3.setEdad(2);

    // 4. Mostrar todas las mascotas
    cout << "\nMascotas con edades actualizadas:" << endl;
    mascota1.mostrar();
    mascota2.mostrar();
    mascota3.mostrar();

    // 5. Cambiar la edad de una mascota
    mascota2.setEdad(4);

    // 6. Volver a mostrar todas
    cout << "\nDespues de cambiar la edad de la segunda mascota:" << endl;
    mascota1.mostrar();
    mascota2.mostrar();
    mascota3.mostrar();

    cout << "\n===== EJERCICIO 5: PEDIDO =====" << endl;

    // 1. Crear 2 objetos Pedido
    Pedido pedido1("P001", "Camiseta", 2, 25.99);
    Pedido pedido2("P002", "Zapatos", 1, 79.50);

    // 2. y 3. Simulamos pedir por consola y usar setters
    pedido1.setCantidad(3);
    pedido1.setPrecioUnitario(24.50);

    pedido2.setCantidad(2);
    pedido2.setPrecioUnitario(75.00);

    // 4. Mostrar ambos pedidos
    cout << "\nPedidos iniciales:" << endl;
    pedido1.mostrar();
    pedido2.mostrar();

    // 5. Modificar la cantidad de uno de los pedidos
    pedido1.setCantidad(5);

    // 6. Volver a mostrar para comprobar que el total se actualiza
    cout << "\nDespues de modificar la cantidad del primer pedido:" << endl;
    pedido1.mostrar();
    pedido2.mostrar();

    cout << "\n===== TODOS LOS EJERCICIOS COMPLETADOS =====" << endl;

    return 0;
}