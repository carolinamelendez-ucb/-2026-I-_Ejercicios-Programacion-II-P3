#include <string>
#include <iostream>
using namespace std;
const int MAYOR_DE_EDAD = 18;

//EJERCICIO 7
class Cliente
{
private:
    string nombre;
    string tipo;
    int antiguedad;
public:
    Cliente()
    {
        nombre = "";
        tipo = "normal";
        antiguedad = 0;
    }
    Cliente(string nombre, string tipo, int antiguedad)
    {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
    }
    string getTipo()
    {
        return tipo;
    }
    int getAntiguedad()
    {
        return antiguedad;
    }
    bool esFrecuente()
    {
        return tipo == "frecuente";
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Antiguedad: " << antiguedad << endl;
    }
};
class Factura
{
private:
    int numero;
    double montoBase;
    bool pagada;
    Cliente cliente;
public:
    Factura()
    {
        numero = 0;
        montoBase = 0;
        pagada = false;
    }
    Factura(int numero, double montoBase, bool pagada, Cliente cliente)
    {
        this->numero = numero;
        this->montoBase = montoBase;
        this->pagada = pagada;
        this->cliente = cliente;
    }
    double calcularTotal()
    {
        if (cliente.esFrecuente() && cliente.getAntiguedad() > 2)
        {
            return montoBase * 0.90;
        }
        return montoBase;
    }
    bool estaPagada()
    {
        return pagada;
    }
    bool clienteFrecuente()
    {
        return cliente.esFrecuente();
    }
    bool clienteNormal()
    {
        return !cliente.esFrecuente();
    }
    int getAntiguedadCliente()
    {
        return cliente.getAntiguedad();
    }
    void mostrar()
    {
        cout << "Numero: " << numero << endl;
        cout << "Monto Base: " << montoBase << endl;
        cout << "Total: " << calcularTotal() << endl;
        cout << "Pagada: " << (pagada ? "Si" : "No") << endl;
        cliente.mostrar();
    }
};

double totalFrecuentesMas2(Factura facturas[], int tamano)
{
    double suma = 0;

    for (int i = 0; i < tamano; i++)
    {
        if (facturas[i].clienteFrecuente() && facturas[i].getAntiguedadCliente() > 2)
        {
            suma += facturas[i].calcularTotal();
        }
    }

    return suma;
}
int contarNormales(Factura facturas[], int tamano)
{
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (facturas[i].clienteNormal())
        {
            contador++;
        }
    }
    return contador;
}
void mostrarMayorFrecuente(Factura facturas[], int tamano)
{
    int pos = -1;
    for (int i = 0; i < tamano; i++)
    {
        if (facturas[i].clienteFrecuente())
        {
            if (pos == -1 ||
                facturas[i].calcularTotal() > facturas[pos].calcularTotal())
            {
                pos = i;
            }
        }
    }

    if (pos != -1)
    {
        facturas[pos].mostrar();
    }
    else
    {
        cout << "No hay facturas de clientes frecuentes." << endl;
    }
}
double promedioMas5(Factura facturas[], int tamano)
{
    double suma = 0;
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (facturas[i].getAntiguedadCliente() > 5)
        {
            suma += facturas[i].calcularTotal();
            contador++;
        }
    }
    if (contador == 0)
    {
        return 0;
    }
    return suma / contador;
}
void impagasYDeudaFrecuentes(Factura facturas[], int tamano)
{
    int contadorImpagas = 0;
    double totalDeudaFrecuentes = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (!facturas[i].estaPagada())
        {
            contadorImpagas++;
            if (facturas[i].clienteFrecuente())
            {
                totalDeudaFrecuentes += facturas[i].calcularTotal();
            }
        }
    }

    cout << "Cantidad facturas impagas: " << contadorImpagas << endl;
    cout << "Total adeudado por clientes frecuentes: "
        << totalDeudaFrecuentes << endl;
}
void Ejercicio7()
{
    Cliente c1("Ana", "frecuente", 3);
    Cliente c2("Luis", "normal", 1);
    Cliente c3("Maria", "frecuente", 6);
    Cliente c4("Carlos", "normal", 8);

    Factura facturas[4];

    facturas[0] = Factura(1, 1000, true, c1);
    facturas[1] = Factura(2, 500, false, c2);
    facturas[2] = Factura(3, 800, false, c3);
    facturas[3] = Factura(4, 1200, true, c4);

    cout << "Monto total de factuas con clientes frecuentes mas de 2 anios: "<< totalFrecuentesMas2(facturas, 4) << endl;
    cout << "Cantidad facturas clientes normales: " << contarNormales(facturas, 4) << endl;
    cout << "Factura mayor monto cliente frecuente:" << endl; mostrarMayorFrecuente(facturas, 4);
    cout << "Promedio clientes con mas de 5 anios de antiguedad: " << promedioMas5(facturas, 4) << endl;
    impagasYDeudaFrecuentes(facturas, 4);
}

//EJERCICIO 8
class Cliente2
{
private:
    string nombre;
    double saldoDisponible;
    bool habilitado;
public:
    Cliente2()
    {
        nombre = "";
        saldoDisponible = 0;
        habilitado = false;
    }
    Cliente2(string nombre, double saldoDisponible, bool habilitado)
    {
        this->nombre = nombre;
        this->saldoDisponible = saldoDisponible;
        this->habilitado = habilitado;
    }
    string getNombre()
    {
        return nombre;
    }
    double getSaldoDisponible()
    {
        return saldoDisponible;
    }
    bool estaHabilitado()
    {
        return habilitado;
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Saldo: " << saldoDisponible << endl;
        cout << "Habilitado: " << (habilitado ? "Si" : "No") << endl;
    }
};
class Pedido
{
private:
    int codigo;
    double importe;
    Cliente2 cliente;
public:
    Pedido()
    {
        codigo = 0;
        importe = 0;
    }
    Pedido(int codigo, double importe, Cliente2 cliente)
    {
        this->codigo = codigo;
        this->importe = importe;
        this->cliente = cliente;
    }
    double getImporte()
    {
        return importe;
    }
    string getNombreCliente()
    {
        return cliente.getNombre();
    }
    bool puedeConfirmarse()
    {
        return cliente.estaHabilitado() && cliente.getSaldoDisponible() >= importe;
    }
    bool rechazadoPorSaldo()
    {
        return cliente.estaHabilitado() && cliente.getSaldoDisponible() < importe;
    }

    void mostrar()
    {
        cout << "Codigo: " << codigo << endl;
        cout << "Importe: " << importe << endl;
        cliente.mostrar();
    }
};

int contarConfirmados(Pedido pedidos[], int tamano)
{
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (pedidos[i].puedeConfirmarse())
        {
            contador++;
        }
    }
    return contador;
}
double totalConfirmados(Pedido pedidos[], int tamano)
{
    double suma = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (pedidos[i].puedeConfirmarse())
        {
            suma += pedidos[i].getImporte();
        }
    }
    return suma;
}
int contarRechazadosPorSaldo(Pedido pedidos[], int tamano)
{
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (pedidos[i].rechazadoPorSaldo())
        {
            contador++;
        }
    }
    return contador;
}
void mostrarPedidoMayor(Pedido pedidos[], int tamano)
{
    int pos = 0;
    for (int i = 1; i < tamano; i++)
    {
        if (pedidos[i].getImporte() > pedidos[pos].getImporte())
        {
            pos = i;
        }
    }
    pedidos[pos].mostrar();
}
void mostrarClientePedidoMasCaro(Pedido pedidos[], int tamano)
{
    int pos = 0;
    for (int i = 1; i < tamano; i++)
    {
        if (pedidos[i].getImporte() > pedidos[pos].getImporte())
        {
            pos = i;
        }
    }
    cout << "Cliente con pedido mas caro: " << pedidos[pos].getNombreCliente() << endl;
}
void Ejercicio8()
{
    Cliente2 c1("Ernesto", 1000, true);
    Cliente2 c2("Luis", 200, true);
    Cliente2 c3("Celeste", 1500, false);
    Cliente2 c4("Nazaret", 800, true);
    
    Pedido pedidos[4];

    pedidos[0] = Pedido(1, 500, c1);
    pedidos[1] = Pedido(2, 300, c2);
    pedidos[2] = Pedido(3, 700, c3);
    pedidos[3] = Pedido(4, 900, c4);

    cout << "Pedidos que pueden confirmarse: " << contarConfirmados(pedidos, 4) << endl;
    cout << "Total importe de los pedidos confirmados: " << totalConfirmados(pedidos, 4) << endl;
    cout << "Pedidos rechazados por falta de saldo: " << contarRechazadosPorSaldo(pedidos, 4) << endl;
    cout << "Pedido de mayor importe:" << endl;
    mostrarPedidoMayor(pedidos, 4);
    mostrarClientePedidoMasCaro(pedidos, 4);
}

//EJERCICIO 9
class Propietario
{
private:
    string nombre;
    int dni;
    int edad;
public:
    Propietario()
    {
        nombre = "";
        dni = 0;
        edad = 0;
    }
    Propietario(string nombre, int dni, int edad)
    {
        this->nombre = nombre;
        this->dni = dni;
        this->edad = edad;
    }
    int getEdad()
    {
        return edad;
    }
    void mostrar()
    {
        cout << "NOMBRE: " << nombre << endl;
        cout << "DNI: " << dni << endl;
        cout << "EDAD: " << edad << endl;
    }
};
class Casa
{
private:
    string direccion;
    int precio;
    Propietario propietario;
public:
    Casa()
    {
        direccion = "";
        precio = 0;
    }
    Casa(string direccion, int precio, Propietario propietario)
    {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }
    int getPrecio()
    {
        return precio;
    }
    int getEdadPropietario()
    {
        return propietario.getEdad();
    }
    bool esPropietarioValido()
    {
        return propietario.getEdad() >= MAYOR_DE_EDAD;
    }
    /*void mostrarTitularidadValida()
    {
        if (esPropietarioValido())
        {
            cout << "La titularidad es valida" << endl;
        }
        else
        {
            cout << "La titularidad es invalida" << endl;
        }
    }*/
    void mostrar()
    {
        cout << "DIRECCION: " << direccion << endl;
        cout << "PRECIO: " << precio << endl;
        propietario.mostrar();
    }
};

int precioTotalMayores(Casa casas[], int tamano)
{
    int suma = 0;
    for (int i=0;i<tamano;i++)
    {
        if (casas[i].esPropietarioValido())
        {
            suma = suma + casas[i].getPrecio();
        }
    }
    return suma;
}
int contarMayores(Casa casas[], int tamano)
{
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (casas[i].esPropietarioValido())
        {
            contador=contador+1;
        }
    }
    return contador;
}
int precioMayores60(Casa casas[],int tamano)
{
    int suma = 0;
    for (int i=0;i<tamano;i++)
    {
        if (casas[i].getEdadPropietario() > 60)
        {
            suma = suma + casas[i].getPrecio();
        }
    }
    return suma;
}
void mostrarCasaMayorValor(Casa casas[], int tamano)
{
    int mayorPrecio = 0;
    int pos = -1;
    for (int i = 0; i < tamano; i++)
    {
        if (casas[i].esPropietarioValido() && casas[i].getPrecio() > mayorPrecio)
        {
            mayorPrecio = casas[i].getPrecio();
            pos = i;
        }
    }
    if (pos != -1)
    {
        casas[pos].mostrar();
    }
    else
    {
        cout << "No hay casas con propietario valido." << endl;
    }
}
double promedioEntre30y50(Casa casas[], int tamano)
{
    int suma = 0;
    int contador = 0;

    for (int i = 0; i < tamano; i++)
    {
        int edad = casas[i].getEdadPropietario();
        if (edad >= 30 && edad <= 50)
        {
            suma = suma+casas[i].getPrecio();
            contador++;
        }
    }

    if (contador == 0)
    {
        return 0;
    }
    return (double)suma / contador;
}
int contarMenores(Casa casas[], int tamano)
{
    int contador = 0;

    for (int i = 0; i < tamano; i++)
    {
        if (casas[i].getEdadPropietario() < MAYOR_DE_EDAD)
        {
            contador++;
        }
    }
    return contador;
}
void Ejercicio9()
{
    Propietario p1 = Propietario("Aileen", 111, 49);
    Propietario p2 = Propietario("Samuel", 222, 17);
    Propietario p3 = Propietario("Ariana", 333, 65);
    Propietario p4 = Propietario("Wilson", 444, 33);

    Casa misCasas[4];

    misCasas[0] = Casa("Av.Libertador", 550, p1);
    misCasas[1] = Casa("Av.America", 200, p2);
    misCasas[2] = Casa("Av.Ecuador", 150, p3);
    misCasas[3] = Casa("Av.Circun", 300, p4);

    cout << "Precio total de las casas cuyos propietarios sean mayores de edad: " << precioTotalMayores(misCasas, 4) << endl;
    cout << "Cantidad de casas que pertenecen a propietarios mayores de edad: " << contarMayores(misCasas, 4) << endl;
    cout << "Precio total de las casas cuyos propietarios sean mayores de 60: " << precioMayores60(misCasas, 4) << endl;
    cout << "Casa de mayor valor con propietario valido:" << endl;
    mostrarCasaMayorValor(misCasas, 4);
    cout << "Promedio valor de las casas con propietarios entre 30 y 50: " << promedioEntre30y50(misCasas, 4) << endl;
    cout << "Cantidad de casas con propietarios menores de edad: "<< contarMenores(misCasas, 4) << endl;
}

//EJERCICIO 10
class Autor
{
private:
    string nombre;
    string nacionalidad;
    int cantidadDeLibrosPublicados;
public:
    Autor()
    {
        nombre = "";
        nacionalidad = "";
        cantidadDeLibrosPublicados = 0;
    }
    Autor(string nombre, string nacionalidad, int cantidad)
    {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadDeLibrosPublicados = cantidad;
    }
    string getNombre()
    {
        return nombre;
    }
    int getCantidadLibros()
    {
        return cantidadDeLibrosPublicados;
    }
    void mostrar()
    {
        cout << "Autor: " << nombre << endl;
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Libros publicados: " << cantidadDeLibrosPublicados << endl;
    }
};
class Libro
{
private:
    string titulo;
    double precio;
    Autor autor;
public:
    Libro()
    {
        titulo = "";
        precio = 0;
    }
    Libro(string titulo, double precio, Autor autor)
    {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }
    double getPrecio()
    {
        return precio;
    }
    int getCantidadLibrosAutor()
    {
        return autor.getCantidadLibros();
    }
    string getNombreAutor()
    {
        return autor.getNombre();
    }
    bool esBestSeller()
    {
        return autor.getCantidadLibros() > 5;
    }
    bool esAutorNovato()
    {
        return autor.getCantidadLibros() <= 2;
    }
    bool esAutorProductivo()
    {
        return autor.getCantidadLibros() > 10;
    }
    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Precio: " << precio << endl;
        autor.mostrar();
    }
};
double promedioMasDeN(Libro libros[], int tamano, int N)
{
    double suma = 0;
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (libros[i].getCantidadLibrosAutor() > N)
        {
            suma += libros[i].getPrecio();
            contador++;
        }
    }
    if (contador == 0)
    {
        return 0;
    }
    return suma / contador;
}
double promedioBestSeller(Libro libros[], int tamano)
{
    double suma = 0;
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (libros[i].esBestSeller())
        {
            suma += libros[i].getPrecio();
            contador++;
        }
    }
    if (contador == 0)
    {
        return 0;
    }
    return suma / contador;
}
void mostrarLibroMasCaroReconocido(Libro libros[], int tamano)
{
    int pos = -1;
    for (int i = 0; i < tamano; i++)
    {
        if (libros[i].esBestSeller())
        {
            if (pos == -1 ||
                libros[i].getPrecio() > libros[pos].getPrecio())
            {
                pos = i;
            }
        }
    }
    if (pos != -1)
    {
        libros[pos].mostrar();
    }
    else
    {
        cout << "No hay libros de autores reconocidos." << endl;
    }
}
int contarNovatos(Libro libros[], int tamano)
{
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (libros[i].esAutorNovato())
        {
            contador++;
        }
    }
    return contador;
}
double totalAutoresProductivos(Libro libros[], int tamano)
{
    double suma = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (libros[i].esAutorProductivo())
        {
            suma += libros[i].getPrecio();
        }
    }
    return suma;
}
void Ejercicio10()
{
    Autor a1("Garcia", "Argentina", 3);
    Autor a2("Ruiz", "Chile", 7);
    Autor a3("Riveros", "Peru", 12);
    Autor a4("Ayaviri", "Mexico", 1);

    Libro libros[4];

    libros[0] = Libro("Libro A", 100, a1);
    libros[1] = Libro("Libro B", 200, a2);
    libros[2] = Libro("Libro C", 300, a3);
    libros[3] = Libro("Libro D", 150, a4);

    cout << "Promedio precio de los libros cuyos autores tengan mas de 5 libros: " << promedioMasDeN(libros, 4, 5) << endl;
    cout << "Precio promedio de los libros best seller: " << promedioBestSeller(libros, 4) << endl;
    cout << "Libro mas caro de autor reconocido:" << endl; mostrarLibroMasCaroReconocido(libros, 4);
    cout << "Cantidad de libros de autores novatos: " << contarNovatos(libros, 4) << endl;
    cout << "Total recaudado por autores productivos: " << totalAutoresProductivos(libros, 4) << endl;
}

//EJERCICIO 11
class Carrera
{
private:
    string nombre;
    int duracion;
    bool cupoDisponible;
public:
    Carrera()
    {
        nombre = "";
        duracion = 0;
        cupoDisponible = false;
    }
    Carrera(string nombre, int duracion, bool cupoDisponible)
    {
        this->nombre = nombre;
        this->duracion = duracion;
        this->cupoDisponible = cupoDisponible;
    }
    string getNombre()
    {
        return nombre;
    }
    int getDuracion()
    {
        return duracion;
    }
    bool tieneCupo()
    {
        return cupoDisponible;
    }
    void mostrar()
    {
        cout << "Carrera: " << nombre << endl;
        cout << "Duracion: " << duracion << endl;
        cout << "Cupo disponible: " << (cupoDisponible ? "Si" : "No") << endl;
    }
};
class Estudiante
{
private:
    string nombre;
    int edad;
    Carrera carrera;
public:
    Estudiante()
    {
        nombre = "";
        edad = 0;
    }
    Estudiante(string nombre, int edad, Carrera carrera)
    {
        this->nombre = nombre;
        this->edad = edad;
        this->carrera = carrera;
    }
    string getNombre()
    {
        return nombre;
    }
    int getEdad()
    {
        return edad;
    }
    string getNombreCarrera()
    {
        return carrera.getNombre();
    }
    int getDuracionCarrera()
    {
        return carrera.getDuracion();
    }
    bool carreraTieneCupo()
    {
        return carrera.tieneCupo();
    }
    bool puedeInscribirse()
    {
        return edad >= MAYOR_DE_EDAD && carrera.tieneCupo();
    }
    bool noPuedePorCupo()
    {
        return edad >= MAYOR_DE_EDAD && !carrera.tieneCupo();
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        carrera.mostrar();
    }
};
int contarInscribibles(Estudiante estudiantes[], int tamano)
{
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (estudiantes[i].puedeInscribirse())
        {
            contador++;
        }
    }
    return contador;
}
void estudianteCarreraMasLarga(Estudiante estudiantes[], int tamano)
{
    int pos = 0;
    for (int i = 1; i < tamano; i++)
    {
        if (estudiantes[i].getDuracionCarrera() > estudiantes[pos].getDuracionCarrera())
        {
            pos = i;
        }
    }
    cout << "Estudiante con carrera mas larga: " << estudiantes[pos].getNombre() << endl;
}
double promedioEdadConCupo(Estudiante estudiantes[], int tamano)
{
    int suma = 0;
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (estudiantes[i].carreraTieneCupo())
        {
            suma += estudiantes[i].getEdad();
            contador++;
        }
    }
    if (contador == 0)
    {
        return 0;
    }
    return (double)suma / contador;
}
int contarSinCupo(Estudiante estudiantes[], int tamano)
{
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (estudiantes[i].noPuedePorCupo())
        {
            contador++;
        }
    }
    return contador;
}
int contarPorCarrera(Estudiante estudiantes[], int tamano, string nombreCarrera)
{
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (estudiantes[i].getNombreCarrera() == nombreCarrera)
        {
            contador++;
        }
    }
    return contador;
}
void Ejercicio11()
{
    Carrera c1("Ingenieria", 5, true);
    Carrera c2("Derecho", 4, false);
    Carrera c3("Medicina", 6, true);

    Estudiante estudiantes[4];

    estudiantes[0] = Estudiante("Valeria", 20, c1);
    estudiantes[1] = Estudiante("Jorge", 17, c1);
    estudiantes[2] = Estudiante("Pablo", 22, c2);
    estudiantes[3] = Estudiante("Rafael", 25, c3);

    cout << "Estudiantes que pueden inscribirse: " << contarInscribibles(estudiantes, 4) << endl;
    estudianteCarreraMasLarga(estudiantes, 4);
    cout << "Promedio edad de los estudiantes con carreras con cupo: " << promedioEdadConCupo(estudiantes, 4) << endl;
    cout << "Cantidad de estudiantes que no pueden inscribirse por falta de cupo: " << contarSinCupo(estudiantes, 4) << endl;
    cout << "Cantidad de estudiantes en Ingenieria: " << contarPorCarrera(estudiantes, 4, "Ingenieria") << endl;
}

int main()
{
    Ejercicio7();
    cout << "-----------------------------------------------------------" << endl;
    Ejercicio8();
    cout << "-----------------------------------------------------------" << endl;
    Ejercicio9();
    cout << "-----------------------------------------------------------" << endl;
    Ejercicio10();
    cout << "-----------------------------------------------------------" << endl;
    Ejercicio11();
}
