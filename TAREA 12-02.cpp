#include <iostream>
#include <string>
using namespace std;


//ejercicio 7
class Cliente {
private:
    string nombre;
    string tipo;
    int antiguedad;

public:
    Cliente() {}
    Cliente(string nombre, string tipo, int antiguedad) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
    }

    string getNombre() { return nombre; }
    string getTipo() { return tipo; }
    int getAntiguedad() { return antiguedad; }
};

class Factura {
private:
    int num;
    int montoBase;
    bool impaga;
    Cliente cliente;

public:
    Factura(int num, int montoBase, bool impaga, Cliente cliente) {
        this->num = num;
        this->montoBase = montoBase;
        this->impaga = impaga;
        this->cliente = cliente;
    }

    int getMonto() { return montoBase; }
    bool estaImpaga() { return impaga; }
    Cliente getCliente() { return cliente; }
    int getNumero() { return num; }
};

//ejercicio 8
class ClienteP {
private:
    string nombre;
    int saldo;
    bool habilitado;

public:
    ClienteP() {}
    ClienteP(string nombre, int saldo, bool habilitado) {
        this->nombre = nombre;
        this->saldo = saldo;
        this->habilitado = habilitado;
    }
    string getNombre() { return nombre; }
    int getSaldo() { return saldo; }
    bool getHabilitado() { return habilitado; }
};
class Pedido {
private:
    int codigo;
    int importe;
    ClienteP cliente;

public:
    Pedido(int codigo, int importe, ClienteP cliente) {
        this->codigo = codigo;
        this->importe = importe;
        this->cliente = cliente;
    }
    int getImporte() { return importe; }
    ClienteP getCliente() { return cliente; }
    bool puedeConfirmarse() {
        return cliente.getHabilitado() && cliente.getSaldo() >= importe;
    }
};

//ejercicio 9
class Propietario {
private:
    string nombre;
    int edad;
public:
    Propietario() {}
    Propietario(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }
    int getEdad() { return edad; }
};

class Casa {
private:
    int precio;
    Propietario propietario;
public:
    Casa(int precio, Propietario propietario) {
        this->precio = precio;
        this->propietario = propietario;
    }
    int getPrecio() { return precio; }
    Propietario getPropietario() { return propietario; }
};

//ejercicio 10
class Autor {
private:
    string nombre;
    string nacionalidad;
    int cantidadLibros;

public:
    Autor(){}
    Autor(string nombre, string nacionalidad, int cantidadLibros) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadLibros = cantidadLibros;
    }
    string getNombre() { return nombre; }
    int getCantidadLibros() { return cantidadLibros; }
};

class Libro {
private:
    string titulo;
    double precio;
    Autor autor;

public:
    Libro(string titulo, int precio, Autor autor) {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }
    int getPrecio() { return precio; }
    string getTitulo() { return titulo; }
    Autor getAutor() { return autor; }
    bool esBestSeller() {
        return autor.getCantidadLibros() > 5;
    }
};

//ejercicio 11
class Carrera {
private:
    string nombre;
    int duracion;
    int cupo;

public:
    Carrera() {}
    Carrera(string nombre, int duracion, int cupo) {
        this->nombre = nombre;
        this->duracion = duracion;
        this->cupo = cupo;
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
    Estudiante() {}
    Estudiante(string nombre, int edad, Carrera carrera) {
        this->nombre = nombre;
        this->edad = edad;
        this->carrera = carrera;
    }
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    Carrera getCarrera() { return carrera; }
    bool puedeInscribirse() {
        return edad >= 18 && carrera.getCupo() > 0;
    }
};

int main() {
        cout << "=== EJERCICIO 7 ===" << endl;
        Cliente c1("Juan", "frecuente", 3);
        Cliente c2("Maria", "normal", 1);
        Cliente c3("Luis", "frecuente", 6);
        Factura facturas[3] = {
            Factura(1, 500, true, c1),
            Factura(2, 300, false, c2),
            Factura(3, 800, true, c3)
        };
        int totalFrecuentes = 0;
        int contadorNormales = 0;
        int mayor = 0;
        int sumaAntiguos = 0;
        int contAntiguos = 0;
        int impagas = 0;
        int totalDeuda = 0;
        for (int i = 0;i < 3;i++) {
            Cliente cli = facturas[i].getCliente();
            if (cli.getTipo() == "frecuente" && cli.getAntiguedad() > 2)
                totalFrecuentes = totalFrecuentes + facturas[i].getMonto();
            if (cli.getTipo() == "normal")
                contadorNormales++;
            if (cli.getTipo() == "frecuente" && facturas[i].getMonto() > mayor)
                mayor = facturas[i].getMonto();
            if (cli.getAntiguedad() > 5) {
                sumaAntiguos = sumaAntiguos + facturas[i].getMonto();
                contAntiguos++;
            }
            if (facturas[i].estaImpaga()) {
                impagas++;
                if (cli.getTipo() == "frecuente")
                    totalDeuda = totalDeuda + facturas[i].getMonto();
            }
        }
        cout << "Total facturado a frecuentes > 2 anios: " << totalFrecuentes << endl;
        cout << "Cantidad de facturas normales: " << contadorNormales << endl;
        cout << "Mayor factura de frecuente: " << mayor << endl;
        cout << "Promedio clientes > 5 anios: " << sumaAntiguos / contAntiguos << endl;
        cout << "Facturas impagas: " << impagas << endl;
        cout << "Total adeudado por frecuentes: " << totalDeuda << endl;
        cout << endl;
        cout << "=== EJERCICIO 8 ===" << endl;
        ClienteP cp1("Ana", 1000, true);
        ClienteP cp2("Pedro", 200, false);
        ClienteP cp3("Sofia", 500, true);
        Pedido pedidos[3] = {
            Pedido(1,400,cp1),
            Pedido(2,300,cp2),
            Pedido(3,600,cp3)
        };
        int confirmados = 0;
        int totalConfirmados = 0;
        int rechazadosSaldo = 0;
        int mayorImporte = 0;
        string clienteMayor = "";
        for (int i = 0;i < 3;i++) {
            if (pedidos[i].puedeConfirmarse()) {
                confirmados++;
                totalConfirmados = totalConfirmados + pedidos[i].getImporte();
            }
            if (!pedidos[i].puedeConfirmarse() && pedidos[i].getCliente().getSaldo() < pedidos[i].getImporte())
                rechazadosSaldo++;
            if (pedidos[i].getImporte() > mayorImporte) {
                mayorImporte = pedidos[i].getImporte();
                clienteMayor = pedidos[i].getCliente().getNombre();
            }
        }
        cout << "Pedidos confirmados: " << confirmados << endl;
        cout << "Total confirmados: " << totalConfirmados << endl;
        cout << "Rechazados por saldo: " << rechazadosSaldo << endl;
        cout << "Mayor importe: " << mayorImporte << endl;
        cout << "Cliente con pedido mas caro: " << clienteMayor << endl;
        cout << endl;
        cout << "=== EJERCICIO 9 ===" << endl;
        Propietario p1("Carlos", 65);
        Propietario p2("Ana", 45);
        Propietario p3("Luis", 16);
        Casa casas[3] = {
            Casa(100000,p1),
            Casa(80000,p2),
            Casa(50000,p3)
        };
        int totalMayores = 0;
        int contMayores = 0;
        int total60 = 0;
        int mayorValor = 0;
        double suma3050 = 0;
        int cont3050 = 0;
        int menores = 0;
        for (int i = 0;i < 3;i++) {
            int edad = casas[i].getPropietario().getEdad();
            if (edad >= 18) {
                totalMayores = totalMayores + casas[i].getPrecio();
                contMayores++;
            }
            if (edad > 60)
                total60 = total60 + casas[i].getPrecio();
            if (edad >= 18 && casas[i].getPrecio() > mayorValor)
                mayorValor = casas[i].getPrecio();
            if (edad >= 30 && edad <= 50) {
                suma3050 = suma3050 + casas[i].getPrecio();
                cont3050++;
            }
            if (edad < 18)
                menores++;
        }
        cout << "Total casas mayores edad: " << totalMayores << endl;
        cout << "Cantidad mayores edad: " << contMayores << endl;
        cout << "Total mayores 60: " << total60 << endl;
        cout << "Casa mayor valor valida: " << mayorValor << endl;
        cout << "Promedio de propietarios con 30-50 anios: " << suma3050 / cont3050 << endl;
        cout << "Casas con menores: " << menores << endl;
        cout << endl;
        cout << "=== EJERCICIO 10 ===" << endl;
        Autor a1("Borges", "Argentina", 10);
        Autor a2("Ana Lopez", "Bolivia", 2);
        Autor a3("Garcia", "Colombia", 7);
        Libro libros[3] = {
            Libro("Libro A",100,a1),
            Libro("Libro B",50,a2),
            Libro("Libro C",150,a3)
        };
        int N = 5;
        double sumaN = 0;
        int contN = 0;
        double sumaBest = 0;
        int contBest = 0;
        double mayorL = 0;
        string tituloMayor = "";
        int novatos = 0;
        double totalProductivos = 0;
        for (int i = 0;i < 3;i++) {
            int cant = libros[i].getAutor().getCantidadLibros();
            if (cant > N) {
                sumaN = sumaN + libros[i].getPrecio();
                contN++;
            }
            if (libros[i].esBestSeller()) {
                sumaBest = sumaBest + libros[i].getPrecio();
                contBest++;
            }
            if (cant > 5 && libros[i].getPrecio() > mayorL) {
                mayorL = libros[i].getPrecio();
                tituloMayor = libros[i].getTitulo();
            }
            if (cant <= 2)
                novatos++;
            if (cant > 5)
                totalProductivos = totalProductivos + libros[i].getPrecio();
        }
        cout << "Promedio precio autores > N: " << sumaN / contN << endl;
        cout << "Promedio precio best seller: " << sumaBest / contBest << endl;
        cout << "Libro mas caro autor reconocido: " << tituloMayor << endl;
        cout << "Cantidad libros autores novatos: " << novatos << endl;
        cout << "Total recaudado autores productivos: " << totalProductivos << endl;
        cout << endl;
        cout << "=== EJERCICIO 11 ===" << endl;
        Carrera car1("Ingenieria", 5, 10);
        Carrera car2("Derecho", 4, 0);
        Carrera car3("Medicina", 6, 5);
        Estudiante estudiantes[3] = {
            Estudiante("Juan",20,car1),
            Estudiante("Maria",17,car2),
            Estudiante("Luis",22,car3)
        };
        int pueden = 0;
        string nombreMayorDuracion = "";
        int mayorDuracion = 0;
        double sumaEdades = 0;
        int contCupo = 0;
        int sinCupo = 0;
        int contadorCarrera = 0;
        string buscarCarrera = "Ingenieria";
        for (int i = 0;i < 3;i++) {
            if (estudiantes[i].puedeInscribirse())
                pueden++;
            if (estudiantes[i].getCarrera().getDuracion() > mayorDuracion) {
                mayorDuracion = estudiantes[i].getCarrera().getDuracion();
                nombreMayorDuracion = estudiantes[i].getNombre();
            }
            if (estudiantes[i].getCarrera().getCupo() > 0) {
                sumaEdades = sumaEdades + estudiantes[i].getEdad();
                contCupo++;
            }
            if (estudiantes[i].getCarrera().getCupo() == 0)
                sinCupo++;
            if (estudiantes[i].getCarrera().getNombre() == buscarCarrera)
                contadorCarrera++;
        }
        cout << "Estudiantes que pueden inscribirse: " << pueden << endl;
        cout << "Estudiante con carrera mas larga: " << nombreMayorDuracion << endl;
        cout << "Promedio edad carreras con cupo: " << sumaEdades / contCupo << endl;
        cout << "Estudiantes sin cupo: " << sinCupo << endl;
        cout << "Cantidad en carrera " << buscarCarrera << ": " << contadorCarrera << endl;
 }
