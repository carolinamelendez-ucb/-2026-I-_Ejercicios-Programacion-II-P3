#include <iostream>
#include <string>
using namespace std;

const int MAYOR_DE_EDAD = 18;
const int MAYOR_60 = 60;
const int MINIMO_BESTSELLER = 5;
const int EDAD_MINIMA_INSCRIPCION = 18;

// Clases del ejercicio 7
class Cliente {
private:
    string nombre;
    int antiguedad;
    bool esFrecuente;

public:
    Cliente() {
        nombre = "";
        antiguedad = 0;
        esFrecuente = false;
    }

    Cliente(string nombre, int antiguedad, bool esFrecuente) {
        this->nombre = nombre;
        this->antiguedad = antiguedad;
        this->esFrecuente = esFrecuente;
    }

    int getAntiguedad() {
        return antiguedad;
    }

    bool getEsFrecuente() {
        return esFrecuente;
    }

    string getNombre() {
        return nombre;
    }

    void mostrar() {
        cout << "Cliente: " << nombre << endl;
        cout << "Antiguedad: " << antiguedad << " anios" << endl;
        cout << "Tipo: " << (esFrecuente ? "Frecuente" : "Normal") << endl;
    }
};

class Factura {
private:
    int numero;
    int monto;
    bool pagada;
    Cliente cliente;

public:
    Factura() {
        numero = 0;
        monto = 0;
        pagada = false;
    }

    Factura(int numero, int monto, bool pagada, Cliente cliente) {
        this->numero = numero;
        this->monto = monto;
        this->pagada = pagada;
        this->cliente = cliente;
    }

    int getMonto() {
        return monto;
    }

    bool getPagada() {
        return pagada;
    }

    Cliente getCliente() {
        return cliente;
    }

    void mostrar() {
        cout << "Factura Num: " << numero << endl;
        cout << "Monto: $" << monto << endl;
        cout << "Estado: " << (pagada ? "Pagada" : "Impaga") << endl;
        cliente.mostrar();
    }
};

// Clases del ejercicio 8
class ClientePedido {
private:
    string nombre;
    bool habilitado;
    int saldo;

public:
    ClientePedido() {
        nombre = "";
        habilitado = false;
        saldo = 0;
    }

    ClientePedido(string nombre, bool habilitado, int saldo) {
        this->nombre = nombre;
        this->habilitado = habilitado;
        this->saldo = saldo;
    }

    bool getHabilitado() {
        return habilitado;
    }

    int getSaldo() {
        return saldo;
    }

    string getNombre() {
        return nombre;
    }

    void mostrar() {
        cout << "Cliente: " << nombre << endl;
        cout << "Habilitado: " << (habilitado ? "Si" : "No") << endl;
        cout << "Saldo: $" << saldo << endl;
    }
};

class Pedido {
private:
    int numero;
    int importe;
    ClientePedido cliente;

public:
    Pedido() {
        numero = 0;
        importe = 0;
    }

    Pedido(int numero, int importe, ClientePedido cliente) {
        this->numero = numero;
        this->importe = importe;
        this->cliente = cliente;
    }

    int getImporte() {
        return importe;
    }

    ClientePedido getCliente() {
        return cliente;
    }

    bool puedeConfirmarse() {
        return cliente.getHabilitado() && cliente.getSaldo() >= importe;
    }

    void mostrar() {
        cout << "Pedido Num: " << numero << endl;
        cout << "Importe: $" << importe << endl;
        cliente.mostrar();
    }
};

// Clases del ejercicio 9
class Propietario {
private:
    string nombre;
    int dni;
    int edad;

public:
    Propietario() {
        nombre = "";
        dni = 0;
        edad = 0;
    }

    Propietario(string nombre, int dni, int edad) {
        this->nombre = nombre;
        this->dni = dni;
        this->edad = edad;
    }

    int getEdad() {
        return edad;
    }

    string getNombre() {
        return nombre;
    }

    bool esMayorEdad() {
        return edad >= MAYOR_DE_EDAD;
    }

    void mostrar() {
        cout << "Propietario: " << nombre << endl;
        cout << "DNI: " << dni << endl;
        cout << "Edad: " << edad << endl;
    }
};

class Casa {
private:
    string direccion;
    int precio;
    Propietario propietario;

public:
    Casa() {
        direccion = "";
        precio = 0;
    }

    Casa(string direccion, int precio, Propietario propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }

    int getPrecio() {
        return precio;
    }

    Propietario getPropietario() {
        return propietario;
    }

    bool esPropietarioValido() {
        return propietario.esMayorEdad();
    }

    void mostrar() {
        cout << "Casa en: " << direccion << endl;
        cout << "Precio: $" << precio << endl;
        propietario.mostrar();
    }
};

// Clases del ejercicio 10
class Autor {
private:
    string nombre;
    string nacionalidad;
    int cantidadDeLibrosPublicados;

public:
    Autor() {
        nombre = "";
        nacionalidad = "";
        cantidadDeLibrosPublicados = 0;
    }

    Autor(string nombre, string nacionalidad, int cantidadDeLibrosPublicados) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadDeLibrosPublicados = cantidadDeLibrosPublicados;
    }

    int getCantidadDeLibrosPublicados() {
        return cantidadDeLibrosPublicados;
    }

    string getNombre() {
        return nombre;
    }

    bool esBestSeller() {
        return cantidadDeLibrosPublicados > MINIMO_BESTSELLER;
    }

    bool esAutorProductivo() {
        return cantidadDeLibrosPublicados > 10;
    }

    bool esAutorNovato() {
        return cantidadDeLibrosPublicados <= 3;
    }

    void mostrar() {
        cout << "Autor: " << nombre << endl;
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Libros publicados: " << cantidadDeLibrosPublicados << endl;
    }
};

class Libro {
private:
    string titulo;
    int precio;
    Autor autor;

public:
    Libro() {
        titulo = "";
        precio = 0;
    }

    Libro(string titulo, int precio, Autor autor) {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }

    int getPrecio() {
        return precio;
    }

    Autor getAutor() {
        return autor;
    }

    bool esBestSeller() {
        return autor.esBestSeller();
    }

    void mostrar() {
        cout << "Libro: " << titulo << endl;
        cout << "Precio: $" << precio << endl;
        autor.mostrar();
    }
};

// Clases del ejercicio 11
class Carrera {
private:
    string nombre;
    int duracion;
    bool tieneCupo;

public:
    Carrera() {
        nombre = "";
        duracion = 0;
        tieneCupo = false;
    }

    Carrera(string nombre, int duracion, bool tieneCupo) {
        this->nombre = nombre;
        this->duracion = duracion;
        this->tieneCupo = tieneCupo;
    }

    int getDuracion() {
        return duracion;
    }

    bool getTieneCupo() {
        return tieneCupo;
    }

    string getNombre() {
        return nombre;
    }

    void mostrar() {
        cout << "Carrera: " << nombre << endl;
        cout << "Duracion: " << duracion << " anios" << endl;
        cout << "Cupo: " << (tieneCupo ? "Disponible" : "Completo") << endl;
    }
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

    Estudiante(string nombre, int edad, Carrera carrera) {
        this->nombre = nombre;
        this->edad = edad;
        this->carrera = carrera;
    }

    int getEdad() {
        return edad;
    }

    string getNombre() {
        return nombre;
    }

    Carrera getCarrera() {
        return carrera;
    }

    bool puedeInscribirse() {
        return edad >= EDAD_MINIMA_INSCRIPCION && carrera.getTieneCupo();
    }

    void mostrar() {
        cout << "Estudiante: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        carrera.mostrar();
    }
};

// Metodos del ejercicio 7
int montoTotalFacturadoClientesFrecuentesConMasDe2Anios(Factura facturas[], int cantidad) {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = facturas[i].getCliente();
        if (cliente.getEsFrecuente() && cliente.getAntiguedad() > 2) {
            total += facturas[i].getMonto();
        }
    }
    return total;
}

int contarFacturasClientesNormales(Factura facturas[], int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        if (!facturas[i].getCliente().getEsFrecuente()) {
            contador++;
        }
    }
    return contador;
}

void mostrarFacturaMayorMontoClienteFrecuente(Factura facturas[], int cantidad) {
    int mayorMonto = -1;
    int indiceMayor = -1;

    for (int i = 0; i < cantidad; i++) {
        if (facturas[i].getCliente().getEsFrecuente()) {
            if (facturas[i].getMonto() > mayorMonto) {
                mayorMonto = facturas[i].getMonto();
                indiceMayor = i;
            }
        }
    }

    if (indiceMayor != -1) {
        cout << "Factura de mayor monto para cliente frecuente:" << endl;
        facturas[indiceMayor].mostrar();
    }
    else {
        cout << "No hay facturas de clientes frecuentes" << endl;
    }
}

int promedioFacturasClientesMasDe5Anios(Factura facturas[], int cantidad) {
    int total = 0;
    int contador = 0;

    for (int i = 0; i < cantidad; i++) {
        if (facturas[i].getCliente().getAntiguedad() > 5) {
            total += facturas[i].getMonto();
            contador++;
        }
    }

    if (contador > 0) {
        return total / contador;
    }
    return 0;
}

void mostrarFacturasImpagasYTotalAdeudadoFrecuentes(Factura facturas[], int cantidad) {
    int impagas = 0;
    int totalAdeudado = 0;

    for (int i = 0; i < cantidad; i++) {
        if (!facturas[i].getPagada() && facturas[i].getCliente().getEsFrecuente()) {
            impagas++;
            totalAdeudado += facturas[i].getMonto();
        }
    }

    cout << "Facturas impagas de clientes frecuentes: " << impagas << endl;
    cout << "Total adeudado por clientes frecuentes: $" << totalAdeudado << endl;
}

// Metodos del ejercicio 8
int contarPedidosConfirmados(Pedido pedidos[], int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        if (pedidos[i].puedeConfirmarse()) {
            contador++;
        }
    }
    return contador;
}

int importeTotalPedidosConfirmados(Pedido pedidos[], int cantidad) {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        if (pedidos[i].puedeConfirmarse()) {
            total += pedidos[i].getImporte();
        }
    }
    return total;
}

int contarPedidosRechazadosPorFaltaDeSaldo(Pedido pedidos[], int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        ClientePedido cliente = pedidos[i].getCliente();
        if (cliente.getHabilitado() && cliente.getSaldo() < pedidos[i].getImporte()) {
            contador++;
        }
    }
    return contador;
}

void mostrarPedidoMayorImporte(Pedido pedidos[], int cantidad) {
    int mayorImporte = -1;
    int indiceMayor = -1;

    for (int i = 0; i < cantidad; i++) {
        if (pedidos[i].getImporte() > mayorImporte) {
            mayorImporte = pedidos[i].getImporte();
            indiceMayor = i;
        }
    }

    if (indiceMayor != -1) {
        cout << "Pedido de mayor importe:" << endl;
        pedidos[indiceMayor].mostrar();
    }
}

void mostrarNombreClientePedidoMasCaro(Pedido pedidos[], int cantidad) {
    int mayorImporte = -1;
    int indiceMayor = -1;

    for (int i = 0; i < cantidad; i++) {
        if (pedidos[i].getImporte() > mayorImporte) {
            mayorImporte = pedidos[i].getImporte();
            indiceMayor = i;
        }
    }

    if (indiceMayor != -1) {
        cout << "Cliente con el pedido mas caro: " << pedidos[indiceMayor].getCliente().getNombre() << endl;
    }
}

// Metodos del ejercicio 9
int precioTotalCasasPropietariosMayoresEdad(Casa casas[], int cantidad) {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        if (casas[i].getPropietario().getEdad() >= MAYOR_DE_EDAD) {
            total += casas[i].getPrecio();
        }
    }
    return total;
}

int contarCasasPropietariosMayoresEdad(Casa casas[], int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        if (casas[i].getPropietario().getEdad() >= MAYOR_DE_EDAD) {
            contador++;
        }
    }
    return contador;
}

int precioTotalCasasPropietariosMasDe60(Casa casas[], int cantidad) {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        if (casas[i].getPropietario().getEdad() > MAYOR_60) {
            total += casas[i].getPrecio();
        }
    }
    return total;
}

void mostrarCasaMayorValorPropietarioValido(Casa casas[], int cantidad) {
    int mayorValor = -1;
    int indiceMayor = -1;

    for (int i = 0; i < cantidad; i++) {
        if (casas[i].esPropietarioValido()) {
            if (casas[i].getPrecio() > mayorValor) {
                mayorValor = casas[i].getPrecio();
                indiceMayor = i;
            }
        }
    }

    if (indiceMayor != -1) {
        cout << "Casa de mayor valor con propietario valido:" << endl;
        casas[indiceMayor].mostrar();
    }
}

int promedioValorCasasPropietarios30a50(Casa casas[], int cantidad) {
    int total = 0;
    int contador = 0;

    for (int i = 0; i < cantidad; i++) {
        int edad = casas[i].getPropietario().getEdad();
        if (edad >= 30 && edad <= 50) {
            total += casas[i].getPrecio();
            contador++;
        }
    }

    if (contador > 0) {
        return total / contador;
    }
    return 0;
}

int contarCasasPropietariosMenoresEdad(Casa casas[], int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        if (casas[i].getPropietario().getEdad() < MAYOR_DE_EDAD) {
            contador++;
        }
    }
    return contador;
}

// Metodos del ejercicio 10
int promedioPrecioLibrosAutoresConMasDeNLibros(Libro libros[], int cantidad, int n) {
    int total = 0;
    int contador = 0;

    for (int i = 0; i < cantidad; i++) {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() > n) {
            total += libros[i].getPrecio();
            contador++;
        }
    }

    if (contador > 0) {
        return total / contador;
    }
    return 0;
}

int precioPromedioLibrosBestSeller(Libro libros[], int cantidad) {
    int total = 0;
    int contador = 0;

    for (int i = 0; i < cantidad; i++) {
        if (libros[i].esBestSeller()) {
            total += libros[i].getPrecio();
            contador++;
        }
    }

    if (contador > 0) {
        return total / contador;
    }
    return 0;
}

void mostrarLibroMasCaroAutorReconocido(Libro libros[], int cantidad) {
    int mayorPrecio = -1;
    int indiceMayor = -1;

    for (int i = 0; i < cantidad; i++) {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() > 10) {
            if (libros[i].getPrecio() > mayorPrecio) {
                mayorPrecio = libros[i].getPrecio();
                indiceMayor = i;
            }
        }
    }

    if (indiceMayor != -1) {
        cout << "Libro mas caro de autor reconocido:" << endl;
        libros[indiceMayor].mostrar();
    }
}

int contarLibrosAutoresNovatos(Libro libros[], int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() <= 3) {
            contador++;
        }
    }
    return contador;
}

int totalRecaudadoLibrosAutoresProductivos(Libro libros[], int cantidad) {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() > 10) {
            total += libros[i].getPrecio();
        }
    }
    return total;
}

// Metodos del ejercicio 11
int contarEstudiantesPuedenInscribirse(Estudiante estudiantes[], int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].puedeInscribirse()) {
            contador++;
        }
    }
    return contador;
}

void mostrarNombreEstudianteCarreraMayorDuracion(Estudiante estudiantes[], int cantidad) {
    int mayorDuracion = -1;
    int indiceMayor = -1;

    for (int i = 0; i < cantidad; i++) {
        int duracion = estudiantes[i].getCarrera().getDuracion();
        if (duracion > mayorDuracion) {
            mayorDuracion = duracion;
            indiceMayor = i;
        }
    }

    if (indiceMayor != -1) {
        cout << "Estudiante con carrera de mayor duracion: " << estudiantes[indiceMayor].getNombre() << endl;
    }
}

int edadPromedioEstudiantesCarrerasConCupo(Estudiante estudiantes[], int cantidad) {
    int totalEdad = 0;
    int contador = 0;

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].getCarrera().getTieneCupo()) {
            totalEdad += estudiantes[i].getEdad();
            contador++;
        }
    }

    if (contador > 0) {
        return totalEdad / contador;
    }
    return 0;
}

int contarEstudiantesNoPuedenInscribirsePorFaltaCupo(Estudiante estudiantes[], int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].getEdad() >= EDAD_MINIMA_INSCRIPCION && !estudiantes[i].getCarrera().getTieneCupo()) {
            contador++;
        }
    }
    return contador;
}

int contarEstudiantesPorCarrera(Estudiante estudiantes[], int cantidad, string nombreCarrera) {
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].getCarrera().getNombre() == nombreCarrera) {
            contador++;
        }
    }
    return contador;
}

// Ejercicio 7
void ejercicio7() {
    cout << "\n=== EJERCICIO 7: FACTURA - CLIENTE ===\n" << endl;

    Cliente clientes[4] = {
        Cliente("Juan Perez", 3, true),
        Cliente("Maria Lopez", 1, false),
        Cliente("Carlos Gomez", 6, true),
        Cliente("Ana Martinez", 2, false)
    };

    Factura facturas[4] = {
        Factura(1001, 1500, true, clientes[0]),
        Factura(1002, 800, false, clientes[1]),
        Factura(1003, 2500, false, clientes[2]),
        Factura(1004, 1200, true, clientes[3])
    };

    cout << "--- LISTADO DE FACTURAS ---" << endl;
    for (int i = 0; i < 4; i++) {
        facturas[i].mostrar();
        cout << "------------------------" << endl;
    }

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Monto total facturado (clientes frecuentes >2 anios): $" << montoTotalFacturadoClientesFrecuentesConMasDe2Anios(facturas, 4) << endl;
    cout << "Facturas de clientes normales: " << contarFacturasClientesNormales(facturas, 4) << endl;
    mostrarFacturaMayorMontoClienteFrecuente(facturas, 4);
    cout << "Promedio facturas (clientes >5 anios): $" << promedioFacturasClientesMasDe5Anios(facturas, 4) << endl;
    mostrarFacturasImpagasYTotalAdeudadoFrecuentes(facturas, 4);
}

// Ejercicio 8
void ejercicio8() {
    cout << "\n=== EJERCICIO 8: PEDIDO - CLIENTE ===\n" << endl;

    ClientePedido clientes[4] = {
        ClientePedido("Pedro Rodriguez", true, 5000),
        ClientePedido("Laura Sanchez", true, 1000),
        ClientePedido("Diego Fernandez", false, 3000),
        ClientePedido("Sofia Torres", true, 2000)
    };

    Pedido pedidos[4] = {
        Pedido(2001, 3000, clientes[0]),
        Pedido(2002, 1500, clientes[1]),
        Pedido(2003, 2500, clientes[2]),
        Pedido(2004, 1800, clientes[3])
    };

    cout << "--- LISTADO DE PEDIDOS ---" << endl;
    for (int i = 0; i < 4; i++) {
        pedidos[i].mostrar();
        cout << "------------------------" << endl;
    }

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Pedidos que pueden confirmarse: " << contarPedidosConfirmados(pedidos, 4) << endl;
    cout << "Importe total pedidos confirmados: $" << importeTotalPedidosConfirmados(pedidos, 4) << endl;
    cout << "Pedidos rechazados por falta de saldo: " << contarPedidosRechazadosPorFaltaDeSaldo(pedidos, 4) << endl;
    mostrarPedidoMayorImporte(pedidos, 4);
    mostrarNombreClientePedidoMasCaro(pedidos, 4);
}

// Ejercicio 9
void ejercicio9() {
    cout << "\n=== EJERCICIO 9: CASA - PROPIETARIO ===\n" << endl;

    Propietario propietarios[4] = {
        Propietario("Roberto Garcia", 12345678, 25),
        Propietario("Marta Diaz", 23456789, 17),
        Propietario("Jose Ramirez", 34567890, 65),
        Propietario("Lucia Fernandez", 45678901, 42)
    };

    Casa casas[4] = {
        Casa("Av. Cicunvalacion 123", 150000, propietarios[0]),
        Casa("Calle Heroinas 456", 90000, propietarios[1]),
        Casa("Av. Blanco Galindo 789", 250000, propietarios[2]),
        Casa("Calle Juan de la rosa 321", 180000, propietarios[3])
    };

    cout << "--- LISTADO DE CASAS ---" << endl;
    for (int i = 0; i < 4; i++) {
        casas[i].mostrar();
        cout << "------------------------" << endl;
    }

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Precio total casas (propietarios mayores edad): $" << precioTotalCasasPropietariosMayoresEdad(casas, 4) << endl;
    cout << "Casas con propietarios mayores edad: " << contarCasasPropietariosMayoresEdad(casas, 4) << endl;
    cout << "Precio total casas (propietarios >60 anios): $" << precioTotalCasasPropietariosMasDe60(casas, 4) << endl;
    mostrarCasaMayorValorPropietarioValido(casas, 4);
    cout << "Promedio valor casas (propietarios 30-50 anios): $" << promedioValorCasasPropietarios30a50(casas, 4) << endl;
    cout << "Casas con propietarios menores edad: " << contarCasasPropietariosMenoresEdad(casas, 4) << endl;
}

// Ejercicio 10
void ejercicio10() {
    cout << "\n=== EJERCICIO 10: LIBRO - AUTOR ===\n" << endl;

    Autor autores[4] = {
        Autor("Gabriel Garcia Marquez", "Colombiana", 25),
        Autor("J.K. Rowling", "Britanica", 7),
        Autor("Juan Perez", "Argentina", 2),
        Autor("Isabel Allende", "Chilena", 20)
    };

    Libro libros[4] = {
        Libro("Cien anios de soledad", 450, autores[0]),
        Libro("Harry Potter", 350, autores[1]),
        Libro("Mi primer libro", 150, autores[2]),
        Libro("La casa de los espiritus", 400, autores[3])
    };

    cout << "--- LISTADO DE LIBROS ---" << endl;
    for (int i = 0; i < 4; i++) {
        libros[i].mostrar();
        cout << "------------------------" << endl;
    }

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Promedio precio (autores con >5 libros): $" << promedioPrecioLibrosAutoresConMasDeNLibros(libros, 4, 5) << endl;
    cout << "Precio promedio libros best seller: $" << precioPromedioLibrosBestSeller(libros, 4) << endl;
    mostrarLibroMasCaroAutorReconocido(libros, 4);
    cout << "Libros de autores novatos: " << contarLibrosAutoresNovatos(libros, 4) << endl;
    cout << "Total recaudado autores productivos: $" << totalRecaudadoLibrosAutoresProductivos(libros, 4) << endl;
}

// Ejercicio 11
void ejercicio11() {
    cout << "\n=== EJERCICIO 11: ESTUDIANTE - CARRERA ===\n" << endl;

    Carrera carreras[4] = {
        Carrera("Ingenieria de Sistemas", 5, true),
        Carrera("Medicina", 6, false),
        Carrera("Derecho", 4, true),
        Carrera("Arquitectura", 5, true)
    };

    Estudiante estudiantes[4] = {
        Estudiante("Carlos Arandia", 20, carreras[0]),
        Estudiante("Ana Perez", 17, carreras[1]),
        Estudiante("Luis Fernandez", 22, carreras[2]),
        Estudiante("Maria Polo", 19, carreras[3])
    };

    cout << "--- LISTADO DE ESTUDIANTES ---" << endl;
    for (int i = 0; i < 4; i++) {
        estudiantes[i].mostrar();
        cout << "------------------------" << endl;
    }

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Estudiantes que pueden inscribirse: " << contarEstudiantesPuedenInscribirse(estudiantes, 4) << endl;
    mostrarNombreEstudianteCarreraMayorDuracion(estudiantes, 4);
    cout << "Edad promedio (estudiantes carreras con cupo): " << edadPromedioEstudiantesCarrerasConCupo(estudiantes, 4) << endl;
    cout << "Estudiantes no pueden inscribirse (falta cupo): " << contarEstudiantesNoPuedenInscribirsePorFaltaCupo(estudiantes, 4) << endl;
    cout << "Estudiantes en Ingenieria de Sistemas: " << contarEstudiantesPorCarrera(estudiantes, 4, "Ingenieria de Sistemas") << endl;
}

// Funcion principal
int main() {
    ejercicio7();
    ejercicio8();
    ejercicio9();
    ejercicio10();
    ejercicio11();

    return 0;
}