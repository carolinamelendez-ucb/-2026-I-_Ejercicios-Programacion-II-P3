#include <iostream>
#include <string>

using namespace std;

class Carrera {
private:
	string nombre;
	int semestres;
public:
	Carrera() {
		nombre = "";
		semestres = 9;
	}
    Carrera(int semestres) {
        nombre = "Ingenieria en Sistemas";
        this->semestres = semestres;
    }
	Carrera(string nombre, int semestres) {
		this->nombre = nombre;
		this->semestres = semestres;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Semestres: " << semestres << endl;
	}
	void setNombre(string nombre) { this->nombre = nombre; }
	void setSemestres(int semestres) { this->semestres = semestres; }
	string getNombre() { return nombre; }
	int getSemestres() { return semestres; }
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
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
		cout << "Carrera: " << endl;
		carrera.mostrar();
	}
	void setNombre(string nombre) { this->nombre = nombre; }
	void setEdad(int edad) { this->edad = edad; }
	void setCarrera(Carrera carrera) { this->carrera = carrera; }
	string getNombre() { return nombre; }
	int getEdad() { return edad; }
	Carrera getCarrera() { return carrera; }
};

class Cliente {
private:
    string nombre;
    string tipo;
    int antiguedad;
public:
    Cliente() {
        nombre = "";
        tipo = "";
        antiguedad = 0;
    }
    Cliente(string nombre, string tipo, int antiguedad) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Antiguedad: " << antiguedad << endl;
    }
    string getNombre() { return nombre; }
    string getTipo() { return tipo; }
    int getAntiguedad() { return antiguedad; }

};
class Factura {
private:
    int numero;
    int montoBase;
    Cliente cliente;
    bool impaga;
public:
    Factura(int numero, int montoBase, Cliente cliente, bool impaga)
    {
        this->numero = numero;
        this->montoBase = montoBase;
        this->cliente = cliente;
        this->impaga = impaga;
    }
    void mostrar() {
        cout << "Numero: " << numero << endl;
        cout << "montoBase: " << montoBase << endl;
        cout << "Cliente: " << endl;
        cliente.mostrar();
    }
    int getNumero() { return numero; }
    int getMontoBase() { return montoBase; }
    Cliente getCliente() { return cliente; }
    float getTotal() { return calcularTotal(); }
    bool getImpaga() { return impaga; }
    float calcularTotal() {
        float tot = numero * montoBase;
        if (cliente.getTipo() == "frecuente" && cliente.getAntiguedad() > 2) {
            return tot * 0.9;
        }
        else {
            return tot;
        }
    }

};

class ClientePedido {
private:
    string nombre;
    float saldoDisponible;
    bool habilitado;
public:
    ClientePedido() {
        nombre = "";
        saldoDisponible = 0;
        habilitado = false;
    }
    ClientePedido(string nombre, float saldoDisponible, bool habilitado) {
        this->nombre = nombre;
        this->saldoDisponible = saldoDisponible;
        this->habilitado = habilitado;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Saldo Disponible: " << saldoDisponible << endl;
        cout << "Habilitado: " << habilitado << endl;
    }
    float getSaldoDisponible() { return saldoDisponible; }
    bool getHabilitado() { return habilitado; }
};

class Pedido {
private:
    int codigo;
    float importe;
    ClientePedido cliente;
public:
    Pedido(int codigo, float importe, ClientePedido cliente) {
        this->codigo = codigo;
        this->importe = importe;
        this->cliente = cliente;
    }
    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Importe: " << importe << endl;
        cout << "Cliente: " << endl;
        cliente.mostrar();
    }

    float getImporte() { return importe; }
    ClientePedido getCliente() { return cliente; }

    bool puedeConfirmarse() {
        if (cliente.getHabilitado() && cliente.getSaldoDisponible() >= importe) {
            return true;
        }
        else {
            return false;
        }
    }
};

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
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << dni << endl;
        cout << "Edad: " << edad << endl;
    }
    int getEdad() { return edad; }
};

class Casa {
private:
    string direccion;
    float precio;
    Propietario propietario;
public:
    Casa(string direccion, float precio, Propietario propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }
    void mostrar() {
        cout << "Direccion: " << direccion << endl;
        cout << "Precio: " << precio << endl;
        cout << "Propietario: " << endl;
        propietario.mostrar();
    }
    float getPrecio() { return precio; }
    Propietario getPropietario() { return propietario; }
    bool esPropietarioValido() {
        if (propietario.getEdad() >= 18) {
            return true;
        }
        else {
            return false;
        }
    }
};

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
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Libros Publicados: " << cantidadDeLibrosPublicados << endl;
    }
    int getCantidadDeLibrosPublicados() { return cantidadDeLibrosPublicados; }
    string getNombre() { return nombre; }
};

class Libro {
private:
    string titulo;
    float precio;
    Autor autor;
public:
    Libro(string titulo, float precio, Autor autor) {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }
    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Precio: " << precio << endl;
        cout << "Autor: " << endl;
        autor.mostrar();
    }
    float getPrecio() { return precio; }
    Autor getAutor() { return autor; }
    bool esBestSeller() {
        if (autor.getCantidadDeLibrosPublicados() > 5) {
            return true;
        }
        else {
            return false;
        }
    }
};

class CarreraNueva {
private:
    string nombre;
    int duracion;
    int cupoDisponible;
public:
    CarreraNueva() {
        nombre = "";
        duracion = 0;
        cupoDisponible = 0;
    }
    CarreraNueva(string nombre, int duracion, int cupo) {
        this->nombre = nombre;
        this->duracion = duracion;
        this->cupoDisponible = cupo;
    }
    int getDuracion() { return duracion; }
    string getNombre() { return nombre; }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Duracion: " << duracion << " años" << endl;
        cout << "Cupo Disponible: " << cupoDisponible << endl;
    }
    int getCupoDisponible() { return cupoDisponible; }
};

class EstudianteNuevo {
private:
    string nombre;
    int edad;
    CarreraNueva carrera;
public:
    EstudianteNuevo(string nombre, int edad, CarreraNueva carrera) {
        this->nombre = nombre;
        this->edad = edad;
        this->carrera = carrera;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Carrera: " << endl;
        carrera.mostrar();
    }
    int getEdad() { return edad; }
    string getNombre() { return nombre; }
    CarreraNueva getCarrera() { return carrera; }
    bool puedeInscribirse() {
        if (edad >= 18 && carrera.getCupoDisponible() > 0) {
            return true;
        }
        else {
            return false;
        }
    }
};


void ejercicio1() {
	Carrera miCarrera = Carrera("Ingenieria en Sistemas", 9);
	Estudiante miEstudiante = Estudiante("Benjamin", 21, miCarrera);
	miEstudiante.mostrar();
}

void ejercicio2() {
    Cliente miCliente1 = Cliente("Omar", "frecuente", 5);
    miCliente1.mostrar();
    cout << endl;
    Factura miFactura1 = Factura(5, 21, miCliente1, true);
    miFactura1.mostrar();
    cout << "El monto a pagar para el primer cliente es: " << miFactura1.calcularTotal() << endl << endl;
    Cliente miCliente2 = Cliente("Nestor", "normal", 5);
    miCliente2.mostrar();
    cout << endl;
    Factura miFactura2 = Factura(5, 21, miCliente2, false);
    miFactura2.mostrar();
    cout << "El monto a pagar para el segundo cliente es: " << miFactura2.calcularTotal() << endl << endl;
}

void ejercicio3() {
    ClientePedido miCliente = ClientePedido("Gabo", 500, true);
    Pedido miPedido = Pedido(101, 300, miCliente);

    miCliente.mostrar();
	miPedido.mostrar();
    cout << "Está habilitado: " << miPedido.puedeConfirmarse() << endl;
}

void ejercicio4() {
    Propietario miPropietario = Propietario("Leo", 102548, 25);
    Casa miCasa = Casa("Calle Moliere", 20000, miPropietario);

    miPropietario.mostrar();
	miCasa.mostrar();
    cout << "Válido " << miCasa.esPropietarioValido() << endl;
}

void ejercicio5() {
    Autor miAutor = Autor("José Mauro de Vasconcelos", "Brazilenio", 10);
    Libro miLibro = Libro("Mi Planta de Naranja Lima", 120, miAutor);
    
    miAutor.mostrar();
	miLibro.mostrar();
    cout << " Best Seller: " << miLibro.esBestSeller() << endl;
}

void ejercicio6() {
    CarreraNueva miCarrera = CarreraNueva("Ingenieria Industrial", 5, 10);
    EstudianteNuevo miEstudiante = EstudianteNuevo("Fabro", 19, miCarrera);

	miCarrera.mostrar();
    miEstudiante.mostrar();
    cout << "¿Puede inscribirse? " << miEstudiante.puedeInscribirse() << endl;
}

void ejercicio7() {
	Factura facturas[3] = {
		Factura(1, 100, Cliente("Mauricio", "frecuente", 5), true),
		Factura(2, 200, Cliente("Nestor", "normal", 5), false),
		Factura(3, 300, Cliente("Diego", "frecuente", 1), true)
	};

    float totalFrecuentes = 0;
    int contadorNormales = 0;
    float mayorMonto = 0;
    int posMayor = -1;
    float sumaMas5 = 0;
    int contMas5 = 0;
    int impagas = 0;
    float deudaFrecuentes = 0;

    for (int i = 0;i < 3;i++) {

        // Total facturado frecuente >2 años
        if (facturas[i].getCliente().getTipo() == "frecuente" &&
            facturas[i].getCliente().getAntiguedad() > 2) {
            totalFrecuentes += facturas[i].getTotal();
        }

        // Contar normales
        if (facturas[i].getCliente().getTipo() == "normal") {
            contadorNormales++;
        }

        // Mayor monto frecuente
        if (facturas[i].getCliente().getTipo() == "frecuente" &&
            facturas[i].getTotal() > mayorMonto) {
            mayorMonto = facturas[i].getTotal();
            posMayor = i;
        }

        // Promedio antiguedad >5
        if (facturas[i].getCliente().getAntiguedad() > 5) {
            sumaMas5 += facturas[i].getTotal();
            contMas5++;
        }

        // Impagas
        if (facturas[i].getImpaga()) {
            impagas++;
            if (facturas[i].getCliente().getTipo() == "frecuente") {
                deudaFrecuentes += facturas[i].getTotal();
            }
        }
    }

    cout << "Total facturado frecuentes: " << totalFrecuentes << endl;
    cout << "Cantidad facturas normales: " << contadorNormales << endl;
    if (posMayor != -1) {
        cout << "Factura frecuente mayor monto:" << endl;
        facturas[posMayor].mostrar();
    }
    cout << "Promedio >5 años: " << (contMas5 > 0 ? sumaMas5 / contMas5 : 0) << endl;
    cout << "Facturas impagas: " << impagas << endl;
    cout << "Total adeudado frecuentes: " << deudaFrecuentes << endl;
}

void ejercicio8() {

    Pedido pedidos[3] = {
        Pedido(1,300,ClientePedido("Ana",500,true)),
        Pedido(2,600,ClientePedido("Luis",200,true)),
        Pedido(3,150,ClientePedido("Pedro",1000,false))
    };

    int confirmados = 0;
    float totalConfirmados = 0;
    int rechazadosSaldo = 0;
    float mayor = 0;
    int posMayor = 0;

    for (int i = 0;i < 3;i++) {

        if (pedidos[i].puedeConfirmarse()) {
            confirmados++;
            totalConfirmados += pedidos[i].getImporte();
        }
        else {
            if (pedidos[i].getCliente().getHabilitado())
                rechazadosSaldo++;
        }

        if (pedidos[i].getImporte() > mayor) {
            mayor = pedidos[i].getImporte();
            posMayor = i;
        }
    }

    cout << "Pedidos confirmados: " << confirmados << endl;
    cout << "Total importe confirmados: " << totalConfirmados << endl;
    cout << "Rechazados por saldo: " << rechazadosSaldo << endl;
    cout << "Pedido mayor importe:" << endl;
    pedidos[posMayor].mostrar();
    cout << "Cliente pedido mas caro: " << pedidos[posMayor].getCliente().getSaldoDisponible() << endl;
}

void ejercicio9() {

    Casa casas[3] = {
        Casa("Zona Norte",100000,Propietario("Juan",123,35)),
        Casa("Centro",200000,Propietario("Luis",456,65)),
        Casa("Sur",150000,Propietario("Ana",789,16))
    };

    float totalMayores = 0;
    int contMayores = 0;
    float total60 = 0;
    float mayor = 0;
    int posMayor = 0;
    float suma30_50 = 0;
    int cont30_50 = 0;
    int menores = 0;

    for (int i = 0;i < 3;i++) {

        int edad = casas[i].getPropietario().getEdad();
        float precio = casas[i].getPrecio();

        if (edad >= 18) {
            totalMayores += precio;
            contMayores++;
        }

        if (edad > 60)
            total60 += precio;

        if (edad >= 18 && precio > mayor) {
            mayor = precio;
            posMayor = i;
        }

        if (edad >= 30 && edad <= 50) {
            suma30_50 += precio;
            cont30_50++;
        }

        if (edad < 18)
            menores++;
    }

    cout << "Total mayores edad: " << totalMayores << endl;
    cout << "Cantidad mayores edad: " << contMayores << endl;
    cout << "Total >60 años: " << total60 << endl;
    cout << "Casa mayor valor valida:" << endl;
    casas[posMayor].mostrar();
    cout << "Promedio 30-50: " << (cont30_50 > 0 ? suma30_50 / cont30_50 : 0) << endl;
    cout << "Casas con menores edad: " << menores << endl;
}

void ejercicio10() {

    Libro libros[3] = {
        Libro("Libro1",100,Autor("Autor1","Bolivia",2)),
        Libro("Libro2",200,Autor("Autor2","Chile",10)),
        Libro("Libro3",300,Autor("Autor3","Peru",7))
    };

    float sumaN = 0; int contN = 0;
    float sumaBest = 0; int contBest = 0;
    float mayor = 0; int posMayor = 0;
    int novatos = 0;
    float totalProductivos = 0;

    int N = 5;

    for (int i = 0;i < 3;i++) {

        int cant = libros[i].getAutor().getCantidadDeLibrosPublicados();
        float precio = libros[i].getPrecio();

        if (cant > N) {
            sumaN += precio;
            contN++;
        }

        if (libros[i].esBestSeller()) {
            sumaBest += precio;
            contBest++;
        }

        if (cant > 5 && precio > mayor) {
            mayor = precio;
            posMayor = i;
        }

        if (cant <= 2)
            novatos++;

        if (cant > 5)
            totalProductivos += precio;
    }

    cout << "Promedio autores >N: " << (contN > 0 ? sumaN / contN : 0) << endl;
    cout << "Promedio best sellers: " << (contBest > 0 ? sumaBest / contBest : 0) << endl;
    cout << "Libro mas caro autor reconocido:" << endl;
    libros[posMayor].mostrar();
    cout << "Autores novatos: " << novatos << endl;
    cout << "Total recaudado productivos: " << totalProductivos << endl;
}

void ejercicio11() {

    EstudianteNuevo estudiantes[3] = {
        EstudianteNuevo("Carlos",19,CarreraNueva("Sistemas",5,10)),
        EstudianteNuevo("Ana",17,CarreraNueva("Industrial",5,5)),
        EstudianteNuevo("Luis",22,CarreraNueva("Civil",6,0))
    };

    int pueden = 0;
    int noCupo = 0;
    float sumaEdad = 0; int contCupo = 0;
    int mayorDuracion = 0; int posMayor = 0;

    for (int i = 0;i < 3;i++) {

        if (estudiantes[i].puedeInscribirse())
            pueden++;

        if (estudiantes[i].getCarrera().getCupoDisponible() == 0)
            noCupo++;

        if (estudiantes[i].getCarrera().getCupoDisponible() > 0) {
            sumaEdad += estudiantes[i].getEdad();
            contCupo++;
        }

        if (estudiantes[i].getCarrera().getDuracion() > mayorDuracion) {
            mayorDuracion = estudiantes[i].getCarrera().getDuracion();
            posMayor = i;
        }
    }

    cout << "Pueden inscribirse: " << pueden << endl;
    cout << "Carrera mayor duracion estudiante: " << estudiantes[posMayor].getNombre() << endl;
    cout << "Promedio edad con cupo: " << (contCupo > 0 ? sumaEdad / contCupo : 0) << endl;
    cout << "No pueden por falta cupo: " << noCupo << endl;
}

int main()
{
    cout << endl << "EJERCICIO 1" << endl;
	ejercicio1();
    cout << endl << "EJERCICIO 2" << endl;
    ejercicio2();
    cout << endl << "EJERCICIO 3" << endl;
    ejercicio3();
    cout << endl << "EJERCICIO 4" << endl;
	ejercicio4();
    cout << endl << "EJERCICIO 5" << endl;
	ejercicio5();
    cout << endl << "EJERCICIO 6" << endl;
	ejercicio6();
    cout << endl << "EJERCICIO 7" << endl;
	ejercicio7();
    cout << endl << "EJERCICIO 8" << endl;
	ejercicio8();
    cout << endl << "EJERCICIO 9" << endl;
	ejercicio9();
    cout << endl << "EJERCICIO 10" << endl;
	ejercicio10();
    cout << endl << "EJERCICIO 11" << endl;
	ejercicio11();
}