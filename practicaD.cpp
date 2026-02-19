#include <iostream>
#include <string>
using namespace std;
class Cliente {
private:
    string nombre;
    string tipo;
    int antiguedad;

public:
    Cliente(string n, string t, int a) {
        nombre = n;
        tipo = t;
        antiguedad = a;
    }

    string getNombre() { return nombre; }
    string getTipo() { return tipo; }
    int getAntiguedad() { return antiguedad; }
};

class Factura {
private:
    int numero;
    int monto;
    bool impaga;
    Cliente cliente;

public:
    Factura(int num, int m, bool i, Cliente c)
        : cliente(c) {
        numero = num;
        monto = m;
        impaga = i;
    }

    int getMonto() { return monto; }
    bool estaImpaga() { return impaga; }
    Cliente getCliente() { return cliente; }
};
class ClienteP {
private:
    string nombre;
    int saldo;
    bool habilitado;

public:
    ClienteP(string n, int s, bool h) {
        nombre = n;
        saldo = s;
        habilitado = h;
    }

    string getNombre() { return nombre; }
    int getSaldo() { return saldo; }
    bool estaHabilitado() { return habilitado; }
};

class Pedido {
private:
    int codigo;
    int importe;
    ClienteP cliente;

public:
    Pedido(int c, int i, ClienteP cl)
        : cliente(cl) {
        codigo = c;
        importe = i;
    }

    int getImporte() { return importe; }
    ClienteP getCliente() { return cliente; }

    bool puedeConfirmarse() {
        if (cliente.estaHabilitado() && cliente.getSaldo() >= importe)
            return true;
        else
            return false;
    }
};
class Propietario {
private:
    string nombre;
    int edad;

public:
    Propietario(string n, int e) {
        nombre = n;
        edad = e;
    }

    int getEdad() { return edad; }
};

class Casa {
private:
    int precio;
    Propietario propietario;

public:
    Casa(int p, Propietario prop)
        : propietario(prop) {
        precio = p;
    }

    int getPrecio() { return precio; }
    Propietario getPropietario() { return propietario; }
};
class Autor {
private:
    string nombre;
    int cantidadLibros;

public:
    Autor(string n, int c) {
        nombre = n;
        cantidadLibros = c;
    }

    int getCantidadLibros() { return cantidadLibros; }
};

class Libro {
private:
    string titulo;
    int precio;
    Autor autor;

public:
    Libro(string t, int p, Autor a)
        : autor(a) {
        titulo = t;
        precio = p;
    }

    int getPrecio() { return precio; }
    string getTitulo() { return titulo; }
    Autor getAutor() { return autor; }

    bool esBestSeller() {
        if (autor.getCantidadLibros() > 5)
            return true;
        else
            return false;
    }
};
class Carrera {
private:
    string nombre;
    int duracion;
    int cupo;

public:
    Carrera(string n, int d, int c) {
        nombre = n;
        duracion = d;
        cupo = c;
    }

    string getNombre() { return nombre; }
    int getDuracion() { return duracion; }
    int getCupo() { return cupo; }
};

class Estudiante {
private:
    string nombre;
    int edad;
    Carrera carrera;

public:
    Estudiante(string n, int e, Carrera c)
        : carrera(c) {
        nombre = n;
        edad = e;
    }

    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    Carrera getCarrera() { return carrera; }

    bool puedeInscribirse() {
        if (edad >= 18 && carrera.getCupo() > 0)
            return true;
        else
            return false;
    }
};
int main() {

    cout << "===== EJERCICIO 7 =====" << endl;

    Cliente c1("Juan", "frecuente", 3);
    Cliente c2("Maria", "normal", 1);
    Cliente c3("Luis", "frecuente", 6);

    Factura f1(1, 500, true, c1);
    Factura f2(2, 300, false, c2);
    Factura f3(3, 800, true, c3);

    Factura facturas[3] = { f1, f2, f3 };

    int totalFrecuentes = 0;
    int impagas = 0;

    for (int i = 0; i < 3; i++) {
        if (facturas[i].getCliente().getTipo() == "frecuente" &&
            facturas[i].getCliente().getAntiguedad() > 2) {

            totalFrecuentes += facturas[i].getMonto();
        }

        if (facturas[i].estaImpaga())
            impagas++;
    }

    cout << "Total frecuentes: " << totalFrecuentes << endl;
    cout << "Facturas impagas: " << impagas << endl;


    cout << "\n===== EJERCICIO 8 =====" << endl;

    ClienteP cp1("Ana", 1000, true);
    Pedido p1(1, 400, cp1);

    if (p1.puedeConfirmarse())
        cout << "Pedido confirmado" << endl;
    else
        cout << "Pedido rechazado" << endl;


    cout << "\n===== EJERCICIO 9 =====" << endl;

    Propietario pr1("Carlos", 65);
    Casa casa1(100000, pr1);

    if (casa1.getPropietario().getEdad() >= 18)
        cout << "Casa valida" << endl;


    cout << "\n===== EJERCICIO 10 =====" << endl;

    Autor a1("Borges", 10);
    Libro l1("Libro A", 100, a1);

    if (l1.esBestSeller())
        cout << "Es best seller" << endl;


    cout << "\n===== EJERCICIO 11 =====" << endl;

    Carrera car1("Ingenieria", 5, 10);
    Estudiante e1("Juan", 20, car1);

    if (e1.puedeInscribirse())
        cout << "Puede inscribirse" << endl;
}




