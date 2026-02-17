#include <iostream>
#include <string>

using namespace std;

//7

class Cliente1 {
private:
    string nombre;
    string tipo;
    int antiguedad;

public:
    Cliente1() {
        nombre = "";
        tipo = "normal";
        antiguedad = 0;
    }

    Cliente1(string nombre, string tipo, int antiguedad) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
    }

    string getNombre() { return nombre; }
    string getTipo() { return tipo; }
    int getAntiguedad() { return antiguedad; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setTipo(string tipo) { this->tipo = tipo; }
    void setAntiguedad(int antiguedad) { this->antiguedad = antiguedad; }
};

class Factura {
private:
    int numero;
    float montoBase;
    bool pagada;
    Cliente1 cliente;

public:
    Factura() {
        numero = 0;
        montoBase = 0;
        pagada = false;
        cliente = Cliente1();
    }

    Factura(int numero, float montoBase, bool pagada, Cliente1 cliente) {
        this->numero = numero;
        this->montoBase = montoBase;
        this->pagada = pagada;
        this->cliente = cliente;
    }

    float calcularTotal() {
        if (cliente.getTipo() == "frecuente" && cliente.getAntiguedad() > 2) {
            return montoBase * 0.9;
        }
        return montoBase;
    }

    int getNumero() { return numero; }
    double getMontoBase() { return montoBase; }
    bool getPagada() { return pagada; }
    Cliente1 getCliente() { return cliente; }
};

float frec2anios (Factura f[], int tam) {
    float T=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getCliente().getAntiguedad() > 2 && f[i].getCliente().getTipo() == "Frecuente") {
             T += f[i].getMontoBase();
        }
    }
    return T;
}

float contNormales (Factura f[], int tam) {
    float T=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getCliente().getTipo() == "Normal") {
             T += 1;
        }
    }
    return T;
}

void mayorFrecuente (Factura f[], int tam) {
    float May=0;
    int pos=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getCliente().getTipo() == "Frecuente") {
            if (f[i].getMontoBase()>May) {
                May = f[i].getMontoBase();
                pos = i;
            }
        }
    }

    cout << "El cliente frecuente con factura de mayor monto es el cliente " << f[pos].getNumero() << " con un monto de " << May << endl;
}

float promedioMonto (Factura f[], int tam) {
    float T=0,P=0;
    int cont=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getCliente().getAntiguedad() > 5) {
            T += f[i].getMontoBase();
            cont += 1;
        }
    }

    if (cont == 0) {
        return 0;
    }
    else {
        P = T/cont;
        return P;
    }
}

void factImpagas (Factura f[], int tam) {
    float T=0;
    int cont=0;
    for (int i=0;i!=tam;i++) {
        if (!f[i].getPagada() && f[i].getCliente().getTipo() == "Frecuente") {
            cont += 1;
            T += f[i].getMontoBase();
        }
    }

    cout << "Facturas impagas de clientes frecuentes: " << cont << endl;
    cout << "Total adeudado: " << T << endl;
}

//8

class Cliente2 {
private:
    string nombre;
    float saldoDisponible;
    bool habilitado;

public:
    Cliente2() {
        nombre = "";
        saldoDisponible = 0;
        habilitado = false;
    }

    Cliente2(string nombre, float saldoDisponible, bool habilitado) {
        this->nombre = nombre;
        this->saldoDisponible = saldoDisponible;
        this->habilitado = habilitado;
    }

    string getNombre() { return nombre; }
    float getSaldoDisponible() { return saldoDisponible; }
    bool getHabilitado() { return habilitado; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setSaldoDisponible(float saldoDisponible) { this->saldoDisponible = saldoDisponible; }
    void setHabilitado(bool habilitado) { this->habilitado = habilitado; }
};

class Pedido {
private:
    int codigo;
    float importe;
    Cliente2 cliente;

public:
    Pedido() {
        codigo = 0;
        importe = 0;
        cliente = Cliente2();
    }

    Pedido(int codigo, float importe, Cliente2 cliente) {
        this->codigo = codigo;
        this->importe = importe;
        this->cliente = cliente;
    }

    int getCodigo() { return codigo; }
    double getImporte() { return importe; }
    Cliente2 getCliente() { return cliente; }

    bool puedeConfirmarse() {
        if (cliente.getHabilitado() && cliente.getSaldoDisponible() >= importe) {
            return true;
        }
        return false;
    }
};

int contConfirmados (Pedido f[], int tam) {
    int cont=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].puedeConfirmarse()) {
             cont += 1;
        }
    }
    return cont;
}

float importeTotal (Pedido f[], int tam) {
    float T=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].puedeConfirmarse()) {
             T += f[i].getImporte();
        }
    }
    return T;
}

int rechazadosSaldo (Pedido f[], int tam) {
    int cont=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getCliente().getHabilitado() && f[i].getCliente().getSaldoDisponible() < f[i].getImporte()) {
             cont += 1;
        }
    }
    return cont;
}

void mayorImporte (Pedido f[], int tam) {
    float may=0;
    int pos=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getImporte() > may) {
            may = f[i].getImporte();
            pos = i;
        }
    }
    cout << "El pedido de mayor importe es del cliente " << f[pos].getCodigo() << " con un importe de " << may << endl;
}

void pedidoCaro (Pedido f[], int tam) {
    float may=0;
    int pos=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getImporte() > may) {
            may = f[i].getImporte();
            pos = i;
        }
    }
    cout << "El cliente con el pedido mas caro es " << f[pos].getCliente().getNombre() << endl;
}

//9

class Propietario {
private:
    string nombre;
    string dni;
    int edad;

public:
    Propietario() {
        nombre = "";
        dni = "";
        edad = 0;
    }

    Propietario(string nombre, string dni, int edad) {
        this->nombre = nombre;
        this->dni = dni;
        this->edad = edad;
    }

    string getNombre() { return nombre; }
    string getDni() { return dni; }
    int getEdad() { return edad; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setDni(string dni) { this->dni = dni; }
    void setEdad(int edad) { this->edad = edad; }
};

class Casa {
private:
    string direccion;
    float precio;
    Propietario propietario;

public:
    Casa() {
        direccion = "";
        precio = 0;
        propietario = Propietario();
    }

    Casa(string direccion, float precio, Propietario propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }

    string getDireccion() { return direccion; }
    float getPrecio() { return precio; }
    Propietario getPropietario() { return propietario; }

    bool esPropietarioValido() {
        return propietario.getEdad() >= 18;
    }
};

float totalPrecios (Casa f[], int tam) {
    float T = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].esPropietarioValido()) {
            T += f[i].getPrecio();
        }
    }
    return T;
}

int contMayores (Casa f[], int tam) {
    int cont = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].esPropietarioValido()) {
            cont += 1;
        }
    }
    return cont;
}

float total60 (Casa f[], int tam) {
    float T = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getPropietario().getEdad() > 60) {
            T += f[i].getPrecio();
        }
    }
    return T;
}

void mayorValido (Casa f[], int tam) {
    int pos = 0;
    float may = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].esPropietarioValido() && f[i].getPrecio() > may) {
            may = f[i].getPrecio();
            pos = i;
        }
    }
    cout << "El propietario valido con casa de mayor valor es " << f[pos].getPropietario().getNombre() << " con un valor de " << may << endl;
}

float promedio30y50 (Casa f[], int tam) {
    float T = 0, P = 0;
    int cont = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getPropietario().getEdad() >= 30 && f[i].getPropietario().getEdad() <= 50) {
            T += f[i].getPrecio();
            cont += 1;
        }
    }
    if (cont == 0) {
        return 0;
    }
    else {
        P = T/cont;
        return P;
    }
}

int contMenores (Casa f[], int tam) {
    int cont = 0;
    for (int i=0;i!=tam;i++) {
        if (!f[i].esPropietarioValido()) {
            cont += 1;
        }
    }
    return cont;
}

//10

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

    Autor(string nombre, string nacionalidad, int cantidad) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadDeLibrosPublicados = cantidad;
    }

    string getNombre() { return nombre; }
    string getNacionalidad() { return nacionalidad; }
    int getCantidadDeLibrosPublicados() { return cantidadDeLibrosPublicados; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setNacionalidad(string nacionalidad) { this->nacionalidad = nacionalidad; }
    void setCantidadDeLibrosPublicados(int cantidad) { this->cantidadDeLibrosPublicados = cantidad; }
};

class Libro {
private:
    string titulo;
    float precio;
    int cantVendidos;
    Autor autor;

public:
    Libro() {
        titulo = "";
        precio = 0;
        cantVendidos = 0;
        autor = Autor();
    }

    Libro(string titulo, float precio, int cantVendidos, Autor autor) {
        this->titulo = titulo;
        this->precio = precio;
        this->cantVendidos = cantVendidos;
        this->autor = autor;
    }

    string getTitulo() { return titulo; }
    float getPrecio() { return precio; }
    int getCantidadVendidos() { return cantVendidos; }
    Autor getAutor() { return autor; }

    bool esBestSeller() {
        return autor.getCantidadDeLibrosPublicados() > 5;
    }
};

float promedioN (Libro f[], int tam, int num){
    float T = 0, P = 0;
    int cont = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getAutor().getCantidadDeLibrosPublicados() > num) {
            T += f[i].getPrecio();
            cont += 1;
        }
    }
    if (cont == 0) {
        return 0;
    }
    else {
        P = T/cont;
        return P;
    }
}

float promedioBestSeller (Libro f[], int tam){
    float T = 0, P = 0;
    int cont = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].esBestSeller()) {
            T += f[i].getPrecio();
            cont += 1;
        }
    }
    if (cont == 0) {
        return 0;
    }
    else {
        P = T/cont;
        return P;
    }
}

void mayorReconocido (Libro f[], int tam) { //el estandar a usarse para un autor reconocido sera de 8 libros o mas
    int pos = 0;
    float may = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getAutor().getCantidadDeLibrosPublicados() >= 8) {
            if (f[i].getPrecio() > may) {
                may = f[i].getPrecio();
                pos = i;
            }
        }
    }
    cout << "El libro de autor reconocido mas caro es " << f[pos].getTitulo() << " con un valor de " << may << endl;
}

int contNovato (Libro f[], int tam) { //el estandar a usarse para un autor novato sera de 3 libros o menos
    int cont = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getAutor().getCantidadDeLibrosPublicados() <= 3) {
            cont += 1;
        }
    }
    return cont;
}

float totalProductivos (Libro f[], int tam) { //el estandar a usarse para un autor productivo sera de 5 libros o mas
    float T = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getAutor().getCantidadDeLibrosPublicados() >= 5) {
            T += f[i].getPrecio()*f[i].getCantidadVendidos();
        }
    }
    return T;
}

//11

class Carrera {
private:
    string nombre;
    int duracion;
    int cupoDisponible;
    int estInscritos;

public:
    Carrera() {
        nombre = "";
        duracion = 0;
        cupoDisponible = 0;
        estInscritos = 0;
    }

    Carrera(string nombre, int duracion, int cupoDisponible, int estInscritos) {
        this->nombre = nombre;
        this->duracion = duracion;
        this->cupoDisponible = cupoDisponible;
        this->estInscritos = estInscritos;
    }

    string getNombre() { return nombre; }
    int getDuracion() { return duracion; }
    int getCupoDisponible() { return cupoDisponible; }
    int getEstInscritos() { return estInscritos; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setDuracion(int duracion) { this->duracion = duracion; }
    void setCupoDisponible(int cupoDisponible) { this->cupoDisponible = cupoDisponible; }
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
        carrera = Carrera();
    }

    Estudiante(string nombre, int edad, Carrera carrera) {
        this->nombre = nombre;
        this->edad = edad;
        this->carrera = carrera;
    }

    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    Carrera getCarrera() { return carrera; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setEdad(int edad) { this->edad = edad; }
    void setCarrera(Carrera carrera) { this->carrera = carrera; }

    bool puedeInscribirse() {
        return (edad >= 18 && carrera.getCupoDisponible() > 0);
    }
};

int contInscripcion (Estudiante f[], int tam) {
    int cont=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].puedeInscribirse()) {
             cont += 1;
        }
    }
    return cont;
}

void mayorDuracion (Estudiante f[], int tam) {
    int pos = 0;
    float may = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getCarrera().getDuracion() > may) {
            may = f[i].getCarrera().getDuracion();
            pos = i;
        }
    }
    cout << "El estudiante en la carrera de mayor duracion es " << f[pos].getNombre() << ", esta en la carrera " << f[pos].getCarrera().getNombre() << " con una duracion de " << may << " anios" << endl;
}

float promedioEdadCupo (Estudiante f[], int tam){
    float T = 0, P = 0;
    int cont = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getCarrera().getCupoDisponible() > 0) {
            T += f[i].getEdad();
            cont += 1;
        }
    }
    if (cont == 0) {
        return 0;
    }
    else {
        P = T/cont;
        return P;
    }
}

int contNoInscripcion (Estudiante f[], int tam) {
    int cont=0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getCarrera().getCupoDisponible() <= 0) {
             cont += 1;
        }
    }
    return cont;
}

float totalEstudiantes (Estudiante f[], int tam, string carr) {
    float T = 0;
    for (int i=0;i!=tam;i++) {
        if (f[i].getCarrera().getNombre() == carr) {
            T += f[i].getCarrera().getEstInscritos();
        }
    }
    return T;
}

//

void ejercicio7() {
    cout << "EJERCICIO 7" << endl;
    Cliente1 C1=Cliente1 ("Alejandro Reyes","Normal",6),C2=Cliente1 ("Lenny Diaz","Frecuente",7),C3=Cliente1 ("Edy Reyes","Frecuente",10);
    Cliente1 C4=Cliente1 ("Helen Fernandez","Normal",7),C5=Cliente1 ("Juan Perez","Frecuente",4);

    Factura F[5];

    F[0] = Factura (1,100,true,C1);
    F[1] = Factura (2,500,false,C2);
    F[2] = Factura (3,10,false,C3);
    F[3] = Factura (4,50,true,C4);
    F[4] = Factura (5,300,false,C5);

    cout << "Monto total solo de clientes frecuentes con mas de 2 anios de antiguedad: " << frec2anios (F,5) << endl;
    cout << "Cantidad de facturas pertenecientes a clientes normales: " << contNormales (F,5) << endl;
    mayorFrecuente (F,5);
    cout << "Promedio de facturas emitidas a clientes con mas de 5 anios de antiguedad: " << promedioMonto (F,5) << endl;
    factImpagas (F,5);
    cout << endl;
}

void ejercicio8() {
    cout << "EJERCICIO 8" << endl;
    Cliente2 C1=Cliente2 ("Alejandro Reyes",0,true),C2=Cliente2 ("Lenny Diaz",1000,false),C3=Cliente2 ("Edy Reyes",20,false);
    Cliente2 C4=Cliente2 ("Helen Fernandez",200,true),C5=Cliente2 ("Juan Perez",0,true);

    Pedido P[5];

    P[0] = Pedido (1,100,C1);
    P[1] = Pedido (2,50,C2);
    P[2] = Pedido (3,200,C3);
    P[3] = Pedido (4,20,C4);
    P[4] = Pedido (5,150,C5);

    cout << "Pedidos habilitados: " << contConfirmados (P, 5) << endl;
    cout << "Importe total de pedidos confirmados:  " << importeTotal (P, 5) << endl;
    cout << "Cantidad de pedidos rechazados por falta de saldo:  " << rechazadosSaldo (P, 5) << endl;
    mayorImporte (P, 5);
    pedidoCaro (P, 5);
    cout << endl;
}

void ejercicio9() {
    cout << "EJERCICIO 9" << endl;
    Propietario P1=Propietario ("Alejandro Reyes","13384038",33),P2=Propietario ("Lenny Diaz","28394628",40),P3=Propietario ("Edy Reyes","38919474",63);
    Propietario P4=Propietario ("Helen Fernandez","82749273",17),P5=Propietario ("Juan Perez","18365920",70);

    Casa C[5];

    C[0] = Casa ("Av. Demetrio Perez",10000,P1);
    C[1] = Casa ("Av. Villazon",5000,P2);
    C[2] = Casa ("Av. Blanco Galindo",20000,P3);
    C[3] = Casa ("Av. America",7000,P4);
    C[4] = Casa ("Av. Beijing",18000,P5);

    cout << "Total de precio de casas de propietarios mayores de edad: " << totalPrecios (C,5) << endl;
    cout << "Cantidad de propietarios mayores de edad: " << contMayores (C,5) << endl;
    mayorValido (C,5);
    cout << "Total de precio de casas de propietarios mayores de 60 anios: " << total60 (C,5) << endl;
    cout << "Promedio de precio de casas de propietarios de entre 30 y 50 anios: " << promedio30y50 (C,5) << endl;
    cout << "Cantidad de propietarios menores de edad: " << contMenores (C,5) << endl;
    cout << endl;
}

void ejercicio10() {
    int N;
    cout << "EJERCICIO 10" << endl;
    Autor A1=Autor ("Gabriel Mendoza","Boliviana",8),A2=Autor ("Laura Fernandez","Argentina",10),A3=Autor ("Ricardo Salazar","Peruana",4);
    Autor A4=Autor ("Mariana Rojas","Chilena",1),A5=Autor ("Andres Vargas","Colombiana",5);

    Libro L[5];

    L[0] = Libro ("Algoritmos Modernos",180,5,A1);
    L[1] = Libro ("Historia del Cono Sur",95,2,A2);
    L[2] = Libro ("Programacion Intermedia en C++",30,20,A3);
    L[3] = Libro ("Introduccion a la Lectura Critica",25,10,A4);
    L[4] = Libro ("Estructuras de Datos Avanzadas",120,8,A5);

    cout << "Ingrese la cantidad de libros minima requerida por autor: ";
    cin >> N;
    cout << "Promedio de precios de libros cuyos autores tienen mas de " << N << " libros publicados: " << promedioN (L, 5, N) << endl;
    cout << "Promedio de precios de libros de autores best seller:  " << promedioBestSeller (L, 5) << endl;
    mayorReconocido (L, 5);
    cout << "Cantidad de libros publicados por autores novatos:  " << contNovato (L, 5) << endl;
    cout << "Total recaudado de libros publicados por autores productivos:  " << totalProductivos (L, 5) << endl;
    cout << endl;
}

void ejercicio11() {
    string carrera;
    cin.ignore();
    cout << "EJERCICIO 11" << endl;
    Carrera C1=Carrera ("Ing. de Sistemas",5,50,250),C2=Carrera ("Mecatronica",6,0,80),C3=Carrera ("Ing. Quimica",5,40,60);
    Carrera C4=Carrera ("Medicina",10,0,500),C5=Carrera ("Derecho",4,70,80);

    Estudiante E[5];

    E[0] = Estudiante ("Alejandro Reyes",18,C1);
    E[1] = Estudiante ("Lenny Diaz",17,C2);
    E[2] = Estudiante ("Juan Perez",17,C3);
    E[3] = Estudiante ("Camilo Buitrago",25,C4);
    E[4] = Estudiante ("Esteban Mendez",21,C5);

    cout << "Cantidad de estudiantes que pueden inscribirse: " << contInscripcion (E, 5) << endl;
    mayorDuracion (E, 5);
    cout << "Promedio de edad de estudiantes cuyas carreras tienen cupo: " << promedioEdadCupo (E, 5) << endl;
    cout << "Cantidad de estudiantes que no pueden inscribirse por falta de cupo: " << contNoInscripcion (E, 5) << endl;
    cout << "Ingrese el nombre de una carrera: ";
    getline(cin, carrera);
    cout << "Cantidad de estudiantes inscritos a la carrera " << carrera << ": " << totalEstudiantes (E, 5, carrera) << endl;
    cout << endl;
}

int main()
{
    ejercicio7();
    ejercicio8();
    ejercicio9();
    ejercicio10();
    ejercicio11();
}
