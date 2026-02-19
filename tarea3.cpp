#include <iostream>
#include <string>

using namespace std;

class Carrera {
private:
    string nombreCarrera;
    int cantidadSemestres;

public:
    Carrera() {
        nombreCarrera = "";
        cantidadSemestres = 9;
    }

    Carrera(string n, int s) {
        nombreCarrera = n;
        cantidadSemestres = s;
    }

    void mostrar() {
        cout << "Carrera: " << nombreCarrera << endl;
        cout << "Semestres: " << cantidadSemestres << endl;
    }

    string getNombre() { return nombreCarrera; }
    int getSemestres() { return cantidadSemestres; }
};

class Estudiante {
private:
    string nombre;
    int edad;
    Carrera carrera;

public:
    Estudiante() {
        nombre = "";
        edad = 0;
    }

    Estudiante(string n, int e, Carrera c) {
        nombre = n;
        edad = e;
        carrera = c;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        carrera.mostrar();
    }
};

class Cliente {
private:
    string nombre;
    string tipo;
    int antiguedad;

public:
    Cliente() {}

    Cliente(string n, string t, int a) {
        nombre = n;
        tipo = t;
        antiguedad = a;
    }

    void mostrar() {
        cout << "Cliente: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Antiguedad: " << antiguedad << endl;
    }

    string getTipo() { return tipo; }
    int getAntiguedad() { return antiguedad; }
};

class Factura {
private:
    int nro;
    float precioUnitario;
    Cliente cliente;
    bool impaga;

public:
    Factura(int n, float p, Cliente c, bool i) {
        nro = n;
        precioUnitario = p;
        cliente = c;
        impaga = i;
    }

    float totalPagar() {
        float total = nro * precioUnitario;

        if (cliente.getTipo() == "frecuente" && cliente.getAntiguedad() > 2)
            total *= 0.9;

        return total;
    }

    bool estaImpaga() { return impaga; }
    Cliente getCliente() { return cliente; }

    void mostrar() {
        cout << "Factura Nro: " << nro << endl;
        cout << "Total: " << totalPagar() << endl;
        cliente.mostrar();
    }
};
class ClientePedido {
private:
    string nombre;
    float saldo;
    bool habilitado;

public:
    ClientePedido(string n, float s, bool h) {
        nombre = n;
        saldo = s;
        habilitado = h;
    }

    float getSaldo() { return saldo; }
    bool estaHabilitado() { return habilitado; }
};

class Pedido {
private:
    int codigo;
    float importe;
    ClientePedido cliente;

public:
    Pedido(int c, float i, ClientePedido cl) {
        codigo = c;
        importe = i;
        cliente = cl;
    }

    bool confirmar() {
        return cliente.estaHabilitado() && cliente.getSaldo() >= importe;
    }

    float getImporte() { return importe; }
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
    string direccion;
    float precio;
    Propietario propietario;

public:
    Casa(string d, float p, Propietario pr) : propietario(pr) {
        direccion = d;
        precio = p;
    }

    bool propietarioValido() {
        return propietario.getEdad() >= 18;
    }

    float getPrecio() { return precio; }
};

class Autor {
private:
    string nombre;
    int librosPublicados;

public:
    Autor(string n, int l) {
        nombre = n;
        librosPublicados = l;
    }

    int getCantidad() { return librosPublicados; }
};

class Libro {
private:
    string titulo;
    float precio;
    Autor autor;

public:
    Libro(string t, float p, Autor a) : autor(a) {
        titulo = t;
        precio = p;
    }

    bool esBestSeller() {
        return autor.getCantidad() > 5;
    }

    float getPrecio() { return precio; }
};

int main() {

    cout << "=== EJERCICIO FACTURAS ===" << endl;

    Factura lista[3] = {
        Factura(1,100,Cliente("Mauricio","frecuente",5),true),
        Factura(2,200,Cliente("Nestor","normal",5),false),
        Factura(3,300,Cliente("Diego","frecuente",1),true)
    };

    float sumaFrecuentes = 0;
    int normales = 0;
    float mayor = 0;
    int posMayor = 0;
    int impagas = 0;

    for (int i = 0; i < 3; i++) {

        float total = lista[i].totalPagar();

        if (lista[i].getCliente().getTipo() == "frecuente" &&
            lista[i].getCliente().getAntiguedad() > 2)
            sumaFrecuentes += total;

        if (lista[i].getCliente().getTipo() == "normal")
            normales++;

        if (total > mayor) {
            mayor = total;
            posMayor = i;
        }

        if (lista[i].estaImpaga())
            impagas++;
    }

    cout << "Total frecuentes: " << sumaFrecuentes << endl;
    cout << "Clientes normales: " << normales << endl;
    cout << "Mayor factura:" << endl;
    lista[posMayor].mostrar();
    cout << "Impagas: " << impagas << endl;

    return 0;
}