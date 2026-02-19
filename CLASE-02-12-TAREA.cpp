#include <iostream>
#include <string>
using namespace std;

class Direccion {
private:
    string calle, ciudad;
public:
    Direccion() {}
    Direccion(string c, string ci) { calle = c; ciudad = ci; }

    string getCalle() { return calle; }
    string getCiudad() { return ciudad; }
    void setCalle(string c) { calle = c; }
    void setCiudad(string ci) { ciudad = ci; }
};

class Persona {
private:
    string nombre;
    Direccion dir;
public:
    Persona() {}
    Persona(string n, Direccion d) { nombre = n; dir = d; }

    string getNombre() { return nombre; }
    void setNombre(string n) { nombre = n; }
};

class Autor {
private:
    string nombre;
public:
    Autor() {}
    Autor(string n) { nombre = n; }

    string getNombre() { return nombre; }
    void setNombre(string n) { nombre = n; }
};

class Libro {
private:
    string titulo;
    Autor autor;
public:
    Libro() {}
    Libro(string t, Autor a) { titulo = t; autor = a; }

    string getTitulo() { return titulo; }
};

class Motor {
private:
    int potencia;
public:
    Motor() {}
    Motor(int p) { potencia = p; }
    int getPotencia() { return potencia; }
};

class Coche {
private:
    string marca;
    Motor motor;
public:
    Coche() {}
    Coche(string m, Motor mo) { marca = m; motor = mo; }
};
class Cliente {
private:
    string nombre, tipo;
    int antiguedad;
public:
    Cliente(string n = "", string t = "normal", int a = 0) {
        nombre = n; tipo = t; antiguedad = a;
    }

    string getTipo() { return tipo; }
    int getAntiguedad() { return antiguedad; }
};

class Factura {
private:
    int numero;
    double montoBase;
    Cliente cliente;
public:
    Factura(int n = 0, double m = 0, Cliente c = Cliente()) {
        numero = n; montoBase = m; cliente = c;
    }

    double calcularTotal() {
        if (cliente.getTipo() == "frecuente" && cliente.getAntiguedad() > 2)
            return montoBase * 0.9;
        return montoBase;
    }
};
class ClientePedido {
private:
    string nombre;
    double saldo;
    bool habilitado;
public:
    ClientePedido(string n = "", double s = 0, bool h = true) {
        nombre = n; saldo = s; habilitado = h;
    }

    bool estaHabilitado() { return habilitado; }
    double getSaldo() { return saldo; }
};

class Pedido {
private:
    int codigo;
    double importe;
    ClientePedido cliente;
public:
    Pedido(int c = 0, double i = 0, ClientePedido cl = ClientePedido()) {
        codigo = c; importe = i; cliente = cl;
    }

    bool puedeConfirmarse() {
        return cliente.estaHabilitado() &&
            cliente.getSaldo() >= importe;
    }

    double getImporte() { return importe; }
};
class Propietario {
private:
    string nombre;
    int dni, edad;
public:
    Propietario(string n = "", int d = 0, int e = 0) {
        nombre = n; dni = d; edad = e;
    }

    int getEdad() { return edad; }
};

class Casa {
private:
    string direccion;
    double precio;
    Propietario propietario;
public:
    Casa(string d = "", double p = 0, Propietario pr = Propietario()) {
        direccion = d; precio = p; propietario = pr;
    }

    bool esPropietarioValido() {
        return propietario.getEdad() >= 18;
    }

    double getPrecio() { return precio; }
};
class Autor2 {
private:
    string nombre, nacionalidad;
    int libros;
public:
    Autor2(string n = "", string na = "", int l = 0) {
        nombre = n; nacionalidad = na; libros = l;
    }

    int getLibros() { return libros; }
};

class Libro2 {
private:
    string titulo;
    double precio;
    Autor2 autor;
public:
    Libro2(string t = "", double p = 0, Autor2 a = Autor2()) {
        titulo = t; precio = p; autor = a;
    }

    bool esBestSeller() {
        return autor.getLibros() > 5;
    }

    double getPrecio() { return precio; }
};
class Carrera {
private:
    string nombre;
    int duracion, cupo;
public:
    Carrera(string n = "", int d = 0, int c = 0) {
        nombre = n; duracion = d; cupo = c;
    }

    int getDuracion() { return duracion; }
    int getCupo() { return cupo; }
};

class Estudiante {
private:
    string nombre;
    int edad;
    Carrera carrera;
public:
    Estudiante(string n = "", int e = 0, Carrera c = Carrera()) {
        nombre = n; edad = e; carrera = c;
    }

    bool puedeInscribirse() {
        return edad >= 18 && carrera.getCupo() > 0;
    }

    int getEdad() { return edad; }
};
double totalFrecuentes(Factura f[], int n) {
    double total = 0;
    for (int i = 0;i < n;i++)
        total += f[i].calcularTotal();
    return total;
}
int pedidosConfirmados(Pedido p[], int n) {
    int cont = 0;
    for (int i = 0;i < n;i++)
        if (p[i].puedeConfirmarse())
            cont++;
    return cont;
}
double totalCasasValidas(Casa c[], int n) {
    double total = 0;
    for (int i = 0;i < n;i++)
        if (c[i].esPropietarioValido())
            total += c[i].getPrecio();
    return total;
}
double promedioBestSeller(Libro2 l[], int n) {
    double suma = 0; int cont = 0;
    for (int i = 0;i < n;i++) {
        if (l[i].esBestSeller()) {
            suma += l[i].getPrecio();
            cont++;
        }
    }
    return cont ? suma / cont : 0;
}
int estudiantesInscribibles(Estudiante e[], int n) {
    int cont = 0;
    for (int i = 0;i < n;i++)
        if (e[i].puedeInscribirse())
            cont++;
    return cont;
}
int main() {
    Cliente c("Carlos", "frecuente", 3);
    Factura f(1, 500, c);
    cout << "Total factura: " << f.calcularTotal() << endl;

    ClientePedido cp("Ana", 1000, true);
    Pedido p(10, 500, cp);
    cout << "Pedido confirmable: " << p.puedeConfirmarse() << endl;

    Propietario pr("Luis", 123, 40);
    Casa casa("Av Siempre Viva", 80000, pr);
    cout << "Propietario valido: " << casa.esPropietarioValido() << endl;

    Autor2 a("Borges", "Argentina", 10);
    Libro2 l("Libro X", 200, a);
    cout << "Best seller: " << l.esBestSeller() << endl;

    Carrera car("Ing Sistemas", 5, 10);
    Estudiante e("Mario", 20, car);
    cout << "Puede inscribirse: " << e.puedeInscribirse() << endl;

    return 0;
}
