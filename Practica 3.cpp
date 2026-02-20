#include <iostream>
#include <string>
using namespace std;


class Cliente {
private:
    string nombre;
    string tipo;
    int antiguedad;
    bool habilitado;
    double saldo;
public:
    Cliente() {}
    Cliente(string nombre, string tipo, int antiguedad, bool habilitado, double saldo) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
        this->habilitado = habilitado;
        this->saldo = saldo;
    }
    string getNombre() {
        return nombre; 
    }
    string getTipo() {
        return tipo; 
    }
    int getAntiguedad() {
        return antiguedad; 
    }
    bool getHabilitado() {
        return habilitado; 
    }
    double getSaldo() {
        return saldo; 
    }
};

class Factura {
private:
    int numero;
    double monto;
    bool pagada;
    Cliente cliente;
public:
    Factura() {}
    Factura(int numero, double monto, bool pagada, Cliente cliente) {
        this->numero = numero;
        this->monto = monto;
        this->pagada = pagada;
        this->cliente = cliente;
    }
    double getMonto() { 
        return monto; 
    }
    bool getPagada() {
        return pagada;
    }
    Cliente getCliente() {
        return cliente; 
    }
};

class Pedido {
private:
    int numero;
    double importe;
    Cliente cliente;
public:
    Pedido() {}
    Pedido(int numero, double importe, Cliente cliente) {
        this->numero = numero;
        this->importe = importe;
        this->cliente = cliente;
    }
    double getImporte() { 
        return importe; 
    }
    Cliente getCliente() {
        return cliente; 
    }
};

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
    int getEdad() { 
        return edad; 
    }
};

class Casa {
private:
    string direccion;
    double precio;
    Propietario propietario;
public:
    Casa() {}
    Casa(string direccion, double precio, Propietario propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }
    double getPrecio() {
        return precio;
    }
    Propietario getPropietario() {
        return propietario; 
    }
};

class Autor {
private:
    string nombre;
    int librosPublicados;
    bool reconocido;
public:
    Autor() {}
    Autor(string nombre, int libros, bool reconocido) {
        this->nombre = nombre;
        this->librosPublicados = libros;
        this->reconocido = reconocido;
    }
    int getLibros() {
        return librosPublicados;
    }
    bool getReconocido() {
        return reconocido; 
    }
};

class Libro {
private:
    string titulo;
    double precio;
    bool bestSeller;
    Autor autor;
public:
    Libro() {}
    Libro(string titulo, double precio, bool bestSeller, Autor autor) {
        this->titulo = titulo;
        this->precio = precio;
        this->bestSeller = bestSeller;
        this->autor = autor;
    }
    double getPrecio() { 
        return precio; 
    }
    bool getBestSeller() {
        return bestSeller; 
    }
    Autor getAutor() {
        return autor; 
    }
};

class Carrera {
private:
    string nombre;
    int duracion;
    bool cupo;
public:
    Carrera() {}
    Carrera(string nombre, int duracion, bool cupo) {
        this->nombre = nombre;
        this->duracion = duracion;
        this->cupo = cupo;
    }
    int getDuracion() { 
        return duracion; 
    }
    bool getCupo() { 
        return cupo;
    }
    string getNombre() {
        return nombre; 
    }
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
    int getEdad() {
        return edad;
    }
    Carrera getCarrera() {
        return carrera; 
    }
    string getNombre() {
        return nombre; 
    }
};


void ejer7() {
   

    Cliente c1("Juan", "frecuente", 6, true, 5000);
    Cliente c2("Ana", "normal", 1, true, 200);

    Factura f[3] = {
        Factura(1,1000,false,c1),
        Factura(2,500,true,c2),
        Factura(3,2000,false,c1)
    };

    double total = 0;
    for (int i = 0; i < 3; i++) {
        if (f[i].getCliente().getTipo() == "frecuente" &&
            f[i].getCliente().getAntiguedad() > 2) {
            total += f[i].getMonto();
        }
    }
    cout << "Total frecuentes >2 años: " << total << endl;
}



void ejer8() {
   

    Cliente c1("Juan", "frecuente", 6, true, 5000);
    Cliente c2("Ana", "normal", 1, true, 100);

    Pedido p[2] = {
        Pedido(1,1000,c1),
        Pedido(2,500,c2)
    };

    int confirmados = 0;
    for (int i = 0; i < 2; i++) {
        if (p[i].getCliente().getHabilitado() &&
            p[i].getCliente().getSaldo() >= p[i].getImporte()) {
            confirmados++;
        }
    }
    cout << "Pedidos confirmados: " << confirmados << endl;
}



void ejer9() {
   

    Propietario p1("Luis", 25);
    Propietario p2("Mario", 15);

    Casa c[2] = {
        Casa("Av1",100000,p1),
        Casa("Av2",80000,p2)
    };

    double total = 0;
    for (int i = 0; i < 2; i++) {
        if (c[i].getPropietario().getEdad() >= 18) {
            total += c[i].getPrecio();
        }
    }
    cout << "Total casas propietarios mayores: " << total << endl;
}



void ejer10() {
    

    Autor a1("Carlos", 10, true);
    Autor a2("Pedro", 1, false);

    Libro l[2] = {
        Libro("Libro1",100,true,a1),
        Libro("Libro2",50,false,a2)
    };

    double total = 0;
    int c = 0;
    for (int i = 0; i < 2; i++) {
        if (l[i].getBestSeller()) {
            total += l[i].getPrecio();
            c++;
        }
    }

    if (c > 0)
        cout << "Promedio best sellers: " << total / c << endl;
}


void ejer11() {
   

    Carrera car1("Sistemas", 5, true);
    Carrera car2("Derecho", 4, false);

    Estudiante e[2] = {
        Estudiante("Juan",20,car1),
        Estudiante("Ana",22,car2)
    };

    int pueden = 0;
    for (int i = 0; i < 2; i++) {
        if (e[i].getEdad() >= 18 &&
            e[i].getCarrera().getCupo()) {
            pueden++;
        }
    }

    cout << "Estudiantes que pueden inscribirse: " << pueden << endl;
}



int main() {

    int op;

    do {
        cout << "========= MENU ========" << endl;
        cout << "1. Ejercicio 7" << endl;
        cout << "2. Ejercicio 8" << endl;
        cout << "3. Ejercicio 9" << endl;
        cout << "4. Ejercicio 10" << endl;
        cout << "5. Ejercicio 11" << endl;
        cout << "6. Salir"<<endl;
        cout << "Ingrese op: " ;
        cin >> op;

        switch (op) {
        case 1:
            ejer7(); 
            break;
        case 2:
            ejer8();
            break;
        case 3: 
            ejer9();
            break;
        case 4: 
            ejer10();
            break;
        case 5: 
            
            ejer11();
            break;
        
           
        default: 
            cout << "Saliendo...";
        }

    } while (op != 6);

    return 0;
}
