#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cliente7 
{
public:
    string nombre;
    bool esFrecuente;
    int antiguedad;
    Cliente7() : nombre(""), esFrecuente(false), antiguedad(0) {}
    Cliente7(string n, bool f, int a) : nombre(n), esFrecuente(f), antiguedad(a) {}
};

class Factura 
{
private:
    float monto;
    bool pagada;
    Cliente7 cliente;
public:
    Factura() : monto(0), pagada(false) {}
    Factura(float m, bool p, Cliente7 c) : monto(m), pagada(p), cliente(c) {}

    float getMonto() { return monto; }
    bool estaPagada() { return pagada; }
    Cliente7 getCliente() { return cliente; }
};

void ejercicio7() 
{
    Cliente7 c1("Juan", true, 5), c2("Ana", false, 1), c3("Luis", true, 3);
    Factura facturas[3] = { Factura(1000, true, c1), Factura(500, false, c2), Factura(1200, false, c3) };

    float totalFrecuentes = 0, totalDeudaFrecuente = 0;
    int normales = 0, impagas = 0;

    for (int i = 0; i < 3; i++) {
        if (facturas[i].getCliente().esFrecuente && facturas[i].getCliente().antiguedad > 2)
            totalFrecuentes += facturas[i].getMonto();
        if (!facturas[i].getCliente().esFrecuente) normales++;
        if (!facturas[i].estaPagada()) {
            impagas++;
            if (facturas[i].getCliente().esFrecuente) totalDeudaFrecuente += facturas[i].getMonto();
        }
    }
    cout << "Total clientes frecuentes (>2 anios): " << totalFrecuentes << endl;
    cout << "Facturas clientes normales: " << normales << endl;
    cout << "Facturas impagas: " << impagas << " | Deuda frecuentes: " << totalDeudaFrecuente << endl;
}

class Cliente8
{
public:
    string nombre;
    bool habilitado;
    float saldo;
    Cliente8() : nombre(""), habilitado(false), saldo(0) {}
    Cliente8(string n, bool h, float s) : nombre(n), habilitado(h), saldo(s) {}
};

class Pedido 
{
private:
    float importe;
    Cliente8 cliente;
public:
    Pedido() : importe(0) {}
    Pedido(float i, Cliente8 c) : importe(i), cliente(c) {}

    bool puedeConfirmarse() { return cliente.habilitado && cliente.saldo >= importe; }
    float getImporte() { return importe; }
    string getNombreCliente() { return cliente.nombre; }
    bool faltaSaldo() { return cliente.habilitado && cliente.saldo < importe; }
};

void ejercicio8() 
{
    Cliente8 c1("Pedro", true, 2000), c2("Marta", true, 100);
    Pedido pedidos[2] = { Pedido(500, c1), Pedido(300, c2) };

    int confirmados = 0, rechazadosSaldo = 0;
    float montoConfirmado = 0;

    for (int i = 0; i < 2; i++) 
    {
        if (pedidos[i].puedeConfirmarse()) 
        {
            confirmados++;
            montoConfirmado += pedidos[i].getImporte();
        }
        else if (pedidos[i].faltaSaldo()) 
        {
            rechazadosSaldo++;
        }
    }
    cout << "Pedidos confirmables: " << confirmados << " | Importe: " << montoConfirmado << endl;
    cout << "Rechazados por saldo: " << rechazadosSaldo << endl;
}

class Propietario 
{
public:
    int edad;
    Propietario() : edad(0) {}
    Propietario(int e) : edad(e) {}
};

class Casa
{
private:
    float precio;
    Propietario prop;
public:
    Casa() : precio(0) {}
    Casa(float p, Propietario pr) : precio(p), prop(pr) {}
    float getPrecio() { return precio; }
    int getEdadProp() { return prop.edad; }
};

void ejercicio9() 
{
    Casa casas[3] = { Casa(200000, Propietario(70)), Casa(150000, Propietario(40)), Casa(100000, Propietario(15)) };
    float totalAdultos = 0, totalMas60 = 0;
    int contAdultos = 0;

    for (int i = 0; i < 3; i++) {
        if (casas[i].getEdadProp() >= 18) {
            totalAdultos += casas[i].getPrecio();
            contAdultos++;
        }
        if (casas[i].getEdadProp() > 60) totalMas60 += casas[i].getPrecio();
    }
    cout << "Casas prop. adultos: " << contAdultos << " | Precio Total: " << totalAdultos << endl;
    cout << "Precio total prop. > 60 anios: " << totalMas60 << endl;
}

class Autor 
{
public:
    int librosPublicados;
    bool esReconocido;
    Autor() : librosPublicados(0), esReconocido(false) {}
    Autor(int lp, bool r) : librosPublicados(lp), esReconocido(r) {}
};

class Libro 
{
private:
    float precio;
    bool esBestSeller;
    Autor autor;
public:
    Libro() : precio(0), esBestSeller(false) {}
    Libro(float p, bool b, Autor a) : precio(p), esBestSeller(b), autor(a) {}
    float getPrecio() { return precio; }
    bool getBestSeller() { return esBestSeller; }
    Autor getAutor() { return autor; }
};

void ejercicio10() 
{
    Libro libros[2] = { Libro(50, true, Autor(15, true)), Libro(30, false, Autor(2, false)) };
    float sumaBestSeller = 0;
    int contBestSeller = 0;

    for (int i = 0; i < 2; i++) {
        if (libros[i].getBestSeller()) 
        {
            sumaBestSeller += libros[i].getPrecio();
            contBestSeller++;
        }
    }
    if (contBestSeller > 0)
        cout << "Promedio precio Best Sellers: " << sumaBestSeller / contBestSeller << endl;
}

class Carrera
{
public:
    string nombre;
    int cupo;
    int duracion;
    Carrera() : nombre(""), cupo(0), duracion(0) {}
    Carrera(string n, int c, int d) : nombre(n), cupo(c), duracion(d) {}
};

class Estudiante
{
private:
    string nombre;
    int edad;
    Carrera carrera;
public:
    Estudiante() : nombre(""), edad(0) {}
    Estudiante(string n, int e, Carrera c) : nombre(n), edad(e), carrera(c) {}
    bool puedeInscribirse() { return edad >= 18 && carrera.cupo > 0; }
    string getNombre() { return nombre; }
};

void ejercicio11() 
{
    Carrera ing("Ingenieria", 2, 5);
    Estudiante ests[2] = { Estudiante("Carlos", 20, ing), Estudiante("Santi", 17, ing) };

    int inscritos = 0;
    for (int i = 0; i < 2; i++) {
        if (ests[i].puedeInscribirse()) inscritos++;
    }
    cout << "Estudiantes que pueden inscribirse: " << inscritos << endl;
}

int main()
{
    int opcion;
    do {
        cout << "menu" << endl;
        cout << "7. Factura - Cliente" << endl;
        cout << "8. Pedido - Cliente" << endl;
        cout << "9. Casa - Propietario" << endl;
        cout << "10. Libro - Autor" << endl;
        cout << "11. Estudiante - Carrera" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << "--- RESULTADOS ---" << endl;
        switch (opcion) 
        {
        case 7: ejercicio7(); break;
        case 8: ejercicio8(); break;
        case 9: ejercicio9(); break;
        case 10: ejercicio10(); break;
        case 11: ejercicio11(); break;
        case 0: cout << "Saliendo..." << endl; break;
        default: cout << "Opcion no valida." << endl;
        }
    } 
    while (opcion != 0);

    return 0;
}