// tarea-12-02-2026.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

class ClienteFactura {
private:
    string nombre;
    string tipo; 
    int antiguedad; 
public:
    ClienteFactura() {
        this->nombre = "";
        this->tipo = "normal";
        this->antiguedad = 0;
    }

    ClienteFactura(string nombre, string tipo, int antiguedad) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
    }

    string getNombre() { return nombre; }
    string getTipo() { return tipo; }
    int getAntiguedad() { return antiguedad; }

    void setNombre(string nuevoNombre) { this->nombre = nuevoNombre; }
    void setTipo(string nuevoTipo) { this->tipo = nuevoTipo; }
    void setAntiguedad(int nuevaAntiguedad) { this->antiguedad = nuevaAntiguedad; }
};

class Factura {
private:
    int numero;
    float montoBase;
    bool impaga;
    ClienteFactura cliente;
public:
    Factura() {
        this->numero = 0;
        this->montoBase = 0;
        this->impaga = false;
    }

    Factura(int numero, float montoBase, bool impaga, ClienteFactura cliente) : cliente(cliente) {
        this->numero = numero;
        this->montoBase = montoBase;
        this->impaga = impaga;
    }

    int getNumero() { return numero; }
    float getMontoBase() { return montoBase; }
    bool getImpaga() { return impaga; }
    ClienteFactura getCliente() { return cliente; }

    void setNumero(int nuevoNumero) { this->numero = nuevoNumero; }
    void setMontoBase(float nuevoMontoBase) { this->montoBase = nuevoMontoBase; }
    void setImpaga(bool nuevaImpaga) { this->impaga = nuevaImpaga; }
    void setCliente(ClienteFactura nuevoCliente) { this->cliente = nuevoCliente; }

    float calcularTotal() {
        if (cliente.getTipo() == "frecuente" && cliente.getAntiguedad() > 2) {
            return montoBase * 0.90f;
        }
        return montoBase;
    }

    void mostrar() {
        cout << "Factura Nro: " << numero << endl;
        cout << "Cliente: " << cliente.getNombre() << endl;
        cout << "Tipo: " << cliente.getTipo() << endl;
        cout << "Antiguedad: " << cliente.getAntiguedad() << endl;
        cout << "Monto base: " << montoBase << endl;
        cout << "Total (con regla): " << calcularTotal() << endl;
        cout << "Estado: " << (impaga ? "IMPAGA" : "PAGADA") << endl;
    }
};

class ClientePedido {
private:
    string nombre;
    float saldoDisponible;
    bool habilitado;
public:
    ClientePedido() {
        this->nombre = "";
        this->saldoDisponible = 0;
        this->habilitado = false;
    }

    ClientePedido(string nombre, float saldoDisponible, bool habilitado) {
        this->nombre = nombre;
        this->saldoDisponible = saldoDisponible;
        this->habilitado = habilitado;
    }

    string getNombre() { return nombre; }
    float getSaldoDisponible() { return saldoDisponible; }
    bool getHabilitado() { return habilitado; }

    void setNombre(string nuevoNombre) { this->nombre = nuevoNombre; }
    void setSaldoDisponible(float nuevoSaldo) { this->saldoDisponible = nuevoSaldo; }
    void setHabilitado(bool nuevoHabilitado) { this->habilitado = nuevoHabilitado; }
};
class Pedido {
private:
    string codigo;
    float importe;
    ClientePedido cliente;
public:
    Pedido() {
        this->codigo = "";
        this->importe = 0;
    }

    Pedido(string codigo, float importe, ClientePedido cliente) : cliente(cliente) {
        this->codigo = codigo;
        this->importe = importe;
    }

    string getCodigo() { return codigo; }
    float getImporte() { return importe; }
    ClientePedido getCliente() { return cliente; }

    void setCodigo(string nuevoCodigo) { this->codigo = nuevoCodigo; }
    void setImporte(float nuevoImporte) { this->importe = nuevoImporte; }
    void setCliente(ClientePedido nuevoCliente) { this->cliente = nuevoCliente; }

    bool puedeConfirmarse() {
        return cliente.getHabilitado() && cliente.getSaldoDisponible() >= importe;
    }

    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Importe: " << importe << endl;
        cout << "Cliente: " << cliente.getNombre() << endl;
        cout << "Saldo: " << cliente.getSaldoDisponible() << endl;
        cout << "Habilitado: " << (cliente.getHabilitado() ? "SI" : "NO") << endl;
        cout << "Confirmable: " << (puedeConfirmarse() ? "SI" : "NO") << endl;
    }
};
class Propietario {
private:
    string nombre;
    int dni;
    int edad;
public:
    Propietario() {
        this->nombre = "";
        this->dni = 0;
        this->edad = 0;
    }

    Propietario(string nombre, int dni, int edad) {
        this->nombre = nombre;
        this->dni = dni;
        this->edad = edad;
    }

    string getNombre() { return nombre; }
    int getDni() { return dni; }
    int getEdad() { return edad; }

    void setNombre(string nuevoNombre) { this->nombre = nuevoNombre; }
    void setDni(int nuevoDni) { this->dni = nuevoDni; }
    void setEdad(int nuevaEdad) { this->edad = nuevaEdad; }
};

class Casa {
private:
    string direccion;
    float precio;
    Propietario propietario;
public:
    Casa() {
        this->direccion = "";
        this->precio = 0;
    }

    Casa(string direccion, float precio, Propietario propietario) : propietario(propietario) {
        this->direccion = direccion;
        this->precio = precio;
    }

    string getDireccion() { return direccion; }
    float getPrecio() { return precio; }
    Propietario getPropietario() { return propietario; }

    void setDireccion(string nuevaDireccion) { this->direccion = nuevaDireccion; }
    void setPrecio(float nuevoPrecio) { this->precio = nuevoPrecio; }
    void setPropietario(Propietario nuevoPropietario) { this->propietario = nuevoPropietario; }

    bool esPropietarioValido() {
        return propietario.getEdad() >= 18;
    }

    void mostrar() {
        cout << "Direccion: " << direccion << endl;
        cout << "Precio: " << precio << endl;
        cout << "Propietario: " << propietario.getNombre() << endl;
        cout << "Edad propietario: " << propietario.getEdad() << endl;
    }
};
class Autor {
private:
    string nombre;
    string nacionalidad;
    int cantidadDeLibrosPublicados;
public:
    Autor() {
        this->nombre = "";
        this->nacionalidad = "";
        this->cantidadDeLibrosPublicados = 0;
    }

    Autor(string nombre, string nacionalidad, int cantidadDeLibrosPublicados) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadDeLibrosPublicados = cantidadDeLibrosPublicados;
    }

    string getNombre() { return nombre; }
    string getNacionalidad() { return nacionalidad; }
    int getCantidadDeLibrosPublicados() { return cantidadDeLibrosPublicados; }

    void setNombre(string nuevoNombre) { this->nombre = nuevoNombre; }
    void setNacionalidad(string nuevaNacionalidad) { this->nacionalidad = nuevaNacionalidad; }
    void setCantidadDeLibrosPublicados(int nuevaCantidad) { this->cantidadDeLibrosPublicados = nuevaCantidad; }
};

class Libro {
private:
    string titulo;
    float precio;
    Autor autor;
public:
    Libro() {
        this->titulo = "";
        this->precio = 0;
    }

    Libro(string titulo, float precio, Autor autor) : autor(autor) {
        this->titulo = titulo;
        this->precio = precio;
    }

    string getTitulo() { return titulo; }
    float getPrecio() { return precio; }
    Autor getAutor() { return autor; }

    void setTitulo(string nuevoTitulo) { this->titulo = nuevoTitulo; }
    void setPrecio(float nuevoPrecio) { this->precio = nuevoPrecio; }
    void setAutor(Autor nuevoAutor) { this->autor = nuevoAutor; }

    bool esBestSeller() {
        return autor.getCantidadDeLibrosPublicados() > 5;
    }

    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Precio: " << precio << endl;
        cout << "Autor: " << autor.getNombre() << endl;
        cout << "Libros publicados: " << autor.getCantidadDeLibrosPublicados() << endl;
    }
};
class Carrera {
private:
    string nombre;
    int duracion; 
    bool cupoDisponible;
public:
    Carrera() {
        this->nombre = "";
        this->duracion = 0;
        this->cupoDisponible = false;
    }

    Carrera(string nombre, int duracion, bool cupoDisponible) {
        this->nombre = nombre;
        this->duracion = duracion;
        this->cupoDisponible = cupoDisponible;
    }

    string getNombre() { return nombre; }
    int getDuracion() { return duracion; }
    bool getCupoDisponible() { return cupoDisponible; }

    void setNombre(string nuevoNombre) { this->nombre = nuevoNombre; }
    void setDuracion(int nuevaDuracion) { this->duracion = nuevaDuracion; }
    void setCupoDisponible(bool nuevoCupoDisponible) { this->cupoDisponible = nuevoCupoDisponible; }
};

class Estudiante {
private:
    string nombre;
    int edad;
    Carrera carrera;
public:
    Estudiante() {
        this->nombre = "";
        this->edad = 0;
    }

    Estudiante(string nombre, int edad, Carrera carrera) : carrera(carrera) {
        this->nombre = nombre;
        this->edad = edad;
    }

    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    Carrera getCarrera() { return carrera; }

    void setNombre(string nuevoNombre) { this->nombre = nuevoNombre; }
    void setEdad(int nuevaEdad) { this->edad = nuevaEdad; }
    void setCarrera(Carrera nuevaCarrera) { this->carrera = nuevaCarrera; }

    bool puedeInscribirse() {
        return edad >= 18 && carrera.getCupoDisponible();
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Carrera: " << carrera.getNombre() << endl;
        cout << "Duracion: " << carrera.getDuracion() << endl;
        cout << "Cupo: " << (carrera.getCupoDisponible() ? "SI" : "NO") << endl;
    }
};
// //ejercicio 7 
float totalFacturadoFrecuentesMas2(Factura facturas[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        ClienteFactura c = facturas[i].getCliente();
        if (c.getTipo() == "frecuente" && c.getAntiguedad() > 2) {
            total += facturas[i].calcularTotal();
        }
    }
    return total;
}

int contarFacturasClientesNormales(Factura facturas[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (facturas[i].getCliente().getTipo() == "normal") cont++;
    }
    return cont;
}

int indiceFacturaMayorMontoFrecuente(Factura facturas[], int n) {
    int idx = -1;
    float mayor = -1;
    for (int i = 0; i < n; i++) {
        ClienteFactura c = facturas[i].getCliente();
        if (c.getTipo() == "frecuente") {
            if (facturas[i].getMontoBase() > mayor) {
                mayor = facturas[i].getMontoBase();
                idx = i;
            }
        }
    }
    return idx;
}

float promedioMontoAntiguedadMas5(Factura facturas[], int n) {
    float suma = 0;
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (facturas[i].getCliente().getAntiguedad() > 5) {
            suma += facturas[i].getMontoBase();
            cont++;
        }
    }
    if (cont == 0) return 0;
    return suma / cont;
}

void impagasYTotalAdeudadoFrecuentes(Factura facturas[], int n) {
    int impagas = 0;
    float adeudadoFrecuentes = 0;
    for (int i = 0; i < n; i++) {
        if (facturas[i].getImpaga()) impagas++;
        if (facturas[i].getImpaga() && facturas[i].getCliente().getTipo() == "frecuente") {
            adeudadoFrecuentes += facturas[i].getMontoBase();
        }
    }
    cout << "Facturas impagas: " << impagas << endl;
    cout << "Total adeudado por clientes frecuentes: " << adeudadoFrecuentes << endl;
}

void ejercicio7() {
    ClienteFactura c1("Ana", "frecuente", 4);
    ClienteFactura c2("Luis", "normal", 1);
    ClienteFactura c3("Maria", "frecuente", 6);
    ClienteFactura c4("Pedro", "normal", 8);
    ClienteFactura c5("Sofia", "frecuente", 2);

    Factura facturas[5] = {
        Factura(101, 500, true, c1),
        Factura(102, 300, false, c2),
        Factura(103, 900, true, c3),
        Factura(104, 250, true, c4),
        Factura(105, 700, false, c5)
    };

    cout << "\n//ejercicio 7" << endl;
    cout << "Total facturado (frecuentes >2 anios): " << totalFacturadoFrecuentesMas2(facturas, 5) << endl;
    cout << "Cantidad de facturas de clientes normales: " << contarFacturasClientesNormales(facturas, 5) << endl;

    int idxMayor = indiceFacturaMayorMontoFrecuente(facturas, 5);
    if (idxMayor != -1) {
        cout << "Factura de mayor monto de cliente frecuente:" << endl;
        facturas[idxMayor].mostrar();
    }
    else {
        cout << "No hay facturas de clientes frecuentes" << endl;
    }

    cout << "Promedio de monto (clientes con >5 anios antiguedad): " << promedioMontoAntiguedadMas5(facturas, 5) << endl;
    impagasYTotalAdeudadoFrecuentes(facturas, 5);
}
// //ejercicio 8 
int contarPedidosConfirmables(Pedido pedidos[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (pedidos[i].puedeConfirmarse()) cont++;
    }
    return cont;
}

float totalImporteConfirmados(Pedido pedidos[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        if (pedidos[i].puedeConfirmarse()) {
            total += pedidos[i].getImporte();
        }
    }
    return total;
}

int contarRechazadosPorFaltaSaldo(Pedido pedidos[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        ClientePedido c = pedidos[i].getCliente();
        if (c.getHabilitado() && c.getSaldoDisponible() < pedidos[i].getImporte()) {
            cont++;
        }
    }
    return cont;
}

int indicePedidoMayorImporte(Pedido pedidos[], int n) {
    if (n <= 0) return -1;
    int idx = 0;
    float mayor = pedidos[0].getImporte();
    for (int i = 1; i < n; i++) {
        if (pedidos[i].getImporte() > mayor) {
            mayor = pedidos[i].getImporte();
            idx = i;
        }
    }
    return idx;
}

void ejercicio8() {
    ClientePedido cp1("Juan", 600, true);
    ClientePedido cp2("Elena", 100, true);
    ClientePedido cp3("Raul", 900, false);
    ClientePedido cp4("Nora", 450, true);

    Pedido pedidos[5] = {
        Pedido("P-01", 200, cp1),
        Pedido("P-02", 150, cp2),
        Pedido("P-03", 800, cp3),
        Pedido("P-04", 500, cp4),
        Pedido("P-05", 120, cp1)
    };

    cout << "\n//ejercicio 8" << endl;
    cout << "Pedidos que pueden confirmarse: " << contarPedidosConfirmables(pedidos, 5) << endl;
    cout << "Importe total de pedidos confirmados: " << totalImporteConfirmados(pedidos, 5) << endl;
    cout << "Pedidos rechazados por falta de saldo: " << contarRechazadosPorFaltaSaldo(pedidos, 5) << endl;

    int idx = indicePedidoMayorImporte(pedidos, 5);
    if (idx != -1) {
        cout << "Pedido de mayor importe:" << endl;
        pedidos[idx].mostrar();
        cout << "Nombre del cliente con el pedido mas caro: " << pedidos[idx].getCliente().getNombre() << endl;
    }
}
// //ejercicio 9 
float totalPrecioCasasPropietarioMayorEdad(Casa casas[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        if (casas[i].esPropietarioValido()) total += casas[i].getPrecio();
    }
    return total;
}

int contarCasasPropietarioMayorEdad(Casa casas[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (casas[i].esPropietarioValido()) cont++;
    }
    return cont;
}

float totalPrecioCasasPropietarioMas60(Casa casas[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        if (casas[i].getPropietario().getEdad() > 60) total += casas[i].getPrecio();
    }
    return total;
}

int indiceCasaMayorValorConPropValido(Casa casas[], int n) {
    int idx = -1;
    float mayor = -1;
    for (int i = 0; i < n; i++) {
        if (casas[i].esPropietarioValido()) {
            if (casas[i].getPrecio() > mayor) {
                mayor = casas[i].getPrecio();
                idx = i;
            }
        }
    }
    return idx;
}

float promedioCasasPropEntre30y50(Casa casas[], int n) {
    float suma = 0;
    int cont = 0;
    for (int i = 0; i < n; i++) {
        int edad = casas[i].getPropietario().getEdad();
        if (edad >= 30 && edad <= 50) {
            suma += casas[i].getPrecio();
            cont++;
        }
    }
    if (cont == 0) return 0;
    return suma / cont;
}

int contarCasasPropietarioMenorEdad(Casa casas[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (casas[i].getPropietario().getEdad() < 18) cont++;
    }
    return cont;
}

void ejercicio9() {
    Propietario p1("Miguel", 123, 25);
    Propietario p2("Lucia", 456, 16);
    Propietario p3("Carlos", 789, 67);
    Propietario p4("Rosa", 159, 45);
    Propietario p5("Pepe", 753, 12);

    Casa casas[5] = {
        Casa("Av. Libertador 123", 250000, p1),
        Casa("Calle 8 #45", 180000, p2),
        Casa("Zona Norte 77", 500000, p3),
        Casa("Av. Siempre Viva 742", 320000, p4),
        Casa("Barrio Sur 10", 150000, p5)
    };

    cout << "\n//ejercicio 9" << endl;
    cout << "Total precio casas con propietario mayor de edad: " << totalPrecioCasasPropietarioMayorEdad(casas, 5) << endl;
    cout << "Cantidad casas con propietario mayor de edad: " << contarCasasPropietarioMayorEdad(casas, 5) << endl;
    cout << "Total precio casas con propietario > 60 anios: " << totalPrecioCasasPropietarioMas60(casas, 5) << endl;

    int idx = indiceCasaMayorValorConPropValido(casas, 5);
    if (idx != -1) {
        cout << "Casa de mayor valor con propietario valido:" << endl;
        casas[idx].mostrar();
    }

    cout << "Promedio valor casas con propietarios entre 30 y 50: " << promedioCasasPropEntre30y50(casas, 5) << endl;
    cout << "Cantidad de casas con propietarios menores de edad: " << contarCasasPropietarioMenorEdad(casas, 5) << endl;
}
// //ejercicio 10 
float promedioPrecioAutoresMasN(Libro libros[], int n, int N) {
    float suma = 0;
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() > N) {
            suma += libros[i].getPrecio();
            cont++;
        }
    }
    if (cont == 0) return 0;
    return suma / cont;
}

float promedioPrecioBestSeller(Libro libros[], int n) {
    float suma = 0;
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (libros[i].esBestSeller()) {
            suma += libros[i].getPrecio();
            cont++;
        }
    }
    if (cont == 0) return 0;
    return suma / cont;
}

int indiceLibroMasCaroAutorReconocido(Libro libros[], int n) {
    int idx = -1;
    float mayor = -1;
    for (int i = 0; i < n; i++) {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() > 5) {
            if (libros[i].getPrecio() > mayor) {
                mayor = libros[i].getPrecio();
                idx = i;
            }
        }
    }
    return idx;
}

int contarLibrosAutoresNovatos(Libro libros[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        int pub = libros[i].getAutor().getCantidadDeLibrosPublicados();
        if (pub <= 2) cont++;
    }
    return cont;
}

float totalRecaudadoAutoresProductivos(Libro libros[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() > 5) {
            total += libros[i].getPrecio();
        }
    }
    return total;
}

void ejercicio10() {
    Autor a1("Borges", "Argentina", 12);
    Autor a2("Autor Nuevo", "Bolivia", 1);
    Autor a3("Isabel", "Chile", 8);
    Autor a4("Carlos", "Peru", 3);
    Autor a5("Maria", "Mexico", 6);

    Libro libros[6] = {
        Libro("Libro A", 120, a1),
        Libro("Libro B", 80, a2),
        Libro("Libro C", 200, a3),
        Libro("Libro D", 95, a4),
        Libro("Libro E", 160, a5),
        Libro("Libro F", 60, a2)
    };

    cout << "\n//ejercicio 10" << endl;
    cout << "Promedio precio de libros con autores > N publicados (N=4): " << promedioPrecioAutoresMasN(libros, 6, 4) << endl;
    cout << "Promedio precio libros best seller: " << promedioPrecioBestSeller(libros, 6) << endl;

    int idx = indiceLibroMasCaroAutorReconocido(libros, 6);
    if (idx != -1) {
        cout << "Libro mas caro de autor reconocido:" << endl;
        libros[idx].mostrar();
    }
    else {
        cout << "No hay libros de autores reconocidos" << endl;
    }

    cout << "Cantidad de libros de autores novatos: " << contarLibrosAutoresNovatos(libros, 6) << endl;
    cout << "Total recaudado por libros de autores productivos: " << totalRecaudadoAutoresProductivos(libros, 6) << endl;
}

// //ejercicio 11
int contarEstudiantesPuedenInscribirse(Estudiante estudiantes[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].puedeInscribirse()) cont++;
    }
    return cont;
}

int indiceEstudianteCarreraMayorDuracion(Estudiante estudiantes[], int n) {
    if (n <= 0) return -1;
    int idx = 0;
    int mayorDur = estudiantes[0].getCarrera().getDuracion();
    for (int i = 1; i < n; i++) {
        if (estudiantes[i].getCarrera().getDuracion() > mayorDur) {
            mayorDur = estudiantes[i].getCarrera().getDuracion();
            idx = i;
        }
    }
    return idx;
}

float promedioEdadConCarreraConCupo(Estudiante estudiantes[], int n) {
    float suma = 0;
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].getCarrera().getCupoDisponible()) {
            suma += estudiantes[i].getEdad();
            cont++;
        }
    }
    if (cont == 0) return 0;
    return suma / cont;
}

int contarNoInscribenPorFaltaCupo(Estudiante estudiantes[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].getEdad() >= 18 && !estudiantes[i].getCarrera().getCupoDisponible()) {
            cont++;
        }
    }
    return cont;
}

int contarEstudiantesPorCarrera(Estudiante estudiantes[], int n, string nombreCarrera) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].getCarrera().getNombre() == nombreCarrera) cont++;
    }
    return cont;
}

void ejercicio11() {
    Carrera c1("Sistemas", 5, true);
    Carrera c2("Derecho", 6, false);
    Carrera c3("Medicina", 7, true);
    Carrera c4("Arquitectura", 5, false);

    Estudiante estudiantes[6] = {
        Estudiante("Luis", 19, c1),
        Estudiante("Ana", 17, c3),
        Estudiante("Pedro", 21, c2),
        Estudiante("Maria", 23, c3),
        Estudiante("Nora", 18, c4),
        Estudiante("Raul", 20, c1)
    };

    cout << "\n//ejercicio 11" << endl;
    cout << "Cantidad de estudiantes que pueden inscribirse: " << contarEstudiantesPuedenInscribirse(estudiantes, 6) << endl;

    int idx = indiceEstudianteCarreraMayorDuracion(estudiantes, 6);
    if (idx != -1) {
        cout << "Estudiante cuya carrera tiene mayor duracion: " << estudiantes[idx].getNombre() << endl;
    }

    cout << "Edad promedio de estudiantes con carreras con cupo: " << promedioEdadConCarreraConCupo(estudiantes, 6) << endl;
    cout << "Cantidad de estudiantes que no pueden inscribirse por falta de cupo: " << contarNoInscribenPorFaltaCupo(estudiantes, 6) << endl;
    cout << "Cantidad de estudiantes de la carrera Sistemas: " << contarEstudiantesPorCarrera(estudiantes, 6, "Sistemas") << endl;
}
int main() {
    ejercicio7();
    ejercicio8();
    ejercicio9();
    ejercicio10();
    ejercicio11();

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
