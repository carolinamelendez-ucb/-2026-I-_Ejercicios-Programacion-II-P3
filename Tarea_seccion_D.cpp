// Tarea_seccion_D.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;
const int MAYOR_EDAD = 18;

class Cliente
{
private:
    string nombre;
    string tipo;
    int antiguedad;
    bool impaga;

public:
    Cliente()
    {
        this->nombre = "";
        this->tipo = "";
        this->antiguedad = 0;
        this->impaga = false;
    }
    Cliente(string nombre, string tipo, int antiguedad,bool impaga)
    {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
        this->impaga = impaga;
    }
    string getTipo()
    {
        return tipo;
    }
    int  getAntiguedad()
    {
        return antiguedad;
     
    }
    bool getImpaga()
    {
        return impaga;
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
    float montoBase;
    Cliente cliente;

public:
    Factura()
    {
        
    }
    Factura(int numero, float montoBase, Cliente cliente)
    {
        this->numero = numero;
        this->montoBase = montoBase;
        this->cliente = cliente;
    }
    float calcularTotal()
    {

        if (cliente.getTipo() == "frecuente" && cliente.getAntiguedad() > 2)
        {
            float descuento = montoBase * 0.1;
            return montoBase - descuento;
        }
        else
        {
            return montoBase;
        }
    }
    void mostrarTotal()
    {
        cout << "Total a pagar: " << calcularTotal() << " Bs" << endl;
    }
    void mostrar()
    {
        cout << "Numero: " << numero << endl;
        cout << "Monto Base: " << montoBase << endl;
        cliente.mostrar();
    }

    Cliente getCliente()
    {
        return cliente;
    }
   
};
void ejercicio7()
{
    Cliente c1 = Cliente("Pepe", "frecuente", 3,false);
    Cliente c2 = Cliente("arnol", "normal", 1,false);
    Cliente c3 = Cliente("quico", "normal", 2,true);
    Cliente c4 = Cliente("ramon", "frecuente", 8,true);

    Factura facturas[4];

    facturas[0] = Factura(234, 200, c1);
    facturas[1] = Factura(345, 500, c2);
    facturas[2] = Factura(534, 356, c3);
    facturas[3] = Factura(215, 856, c4);

    for (int i = 0; i < 4; i++)
    {
        facturas[i].mostrar();
    } 
    //Monto total facturado
        int total = 0;

        for (int i = 0; i < 4; i++)
        {
            if (facturas[i].getCliente().getTipo() == "frecuente" && facturas[i].getCliente().getAntiguedad() > 2)
            {
                float totalFacturas = facturas[i].calcularTotal();
                total = total + totalFacturas;
            }
        }
        cout << "El monto total facturado de clientes mayores a 2 anios es: " << total << endl;
    //para contar facturas
    
        int contar = 0;

        for (int i = 0; i < 4; i++)
        {
            if (facturas[i].getCliente().getTipo() == "normal")
            {
                contar++;
            }

        }
        cout << "La cantidad de facturas que pertenecen a clientes normales son: " << contar << endl;
      //Muestre la factura de mayor monto de un cliente frecuente
        int mayormonto = 0;
        int indiceMAyor = -1;
        for (int i = 0; i < 4; i++)
        {
            if (facturas[i].getCliente().getTipo() == "frecuente" && facturas[i].calcularTotal() > mayormonto)
            {
                mayormonto = facturas[i].calcularTotal();
                indiceMAyor = i;
            }
        }
        cout << "La factura de mayor monto para el cliente frecuente" << endl;
        if (indiceMAyor != -1)
        {
            facturas[indiceMAyor].mostrar();
        }
    //Calcular prmedio de monto a clientes >a 5 aniso
        float sumaMayor=0;//acumula la suma total de las facturas
        int contadorMayor = 0;//Cuenta de cunatos clientes cumplen para calcular promedio
        for (int i = 0; i < 4; i++)
        {
            if (facturas[i].getCliente().getAntiguedad() > 5)
            {
                sumaMayor = sumaMayor + facturas[i].calcularTotal();
                contadorMayor++;
            }
        }
        if (sumaMayor > 0)
        {
            cout << "El promedio de monto para cliente mayor a 5anios es: " << sumaMayor / contadorMayor << " Bs " << endl;
        }
        else
        {
            cout << " no hay clientes con mas de aniso de antiguedad" << endl;
        }
    //Cuantas facturas estan impagas y total adeudado
        int contadorimpagas = 0;
        int totaldeuda = 0;
        for (int i = 0; i < 4; i++)
        {
            if (facturas[i].getCliente().getImpaga())
            {
                contadorimpagas++;
            }
            if (facturas[i].getCliente().getTipo() == "frecuente"&& facturas[i].getCliente().getImpaga())
            {
                totaldeuda = totaldeuda + facturas[i].calcularTotal();
            }
        }
        cout << "Cantidad de facturas impagas: " << contadorimpagas << endl;
        cout << "Total adeudado por clientes frecuentes: " << totaldeuda << " Bs" << endl;
}
class Cliente1
{
private:
    string nombre;
    float saldoDisponible;
    bool habilitado;
public:
    Cliente1()
    {
        this->nombre = "";
        this->saldoDisponible = 0;
        this->habilitado = false;
    }
    Cliente1(string nombre, float saldoDisponible, bool habilitado)
    {
        this->nombre = nombre;
        this->saldoDisponible = saldoDisponible;
        this->habilitado = habilitado;
    }
    bool getHabilitado()
    {
        return habilitado;
    }
    float getSaldo()
    {
        return saldoDisponible;
    }
    string getNombre()
    {
        return nombre;
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Saldo disponible: " << saldoDisponible << endl;
        cout << "Esta habilitado :" << habilitado << endl;
    }
};

class Pedido
{
private:
    int codigo;
    int importe;
    Cliente1 cliente1;
public:
    Pedido(){}
    Pedido(int codigo, int importe, Cliente1 cliente1)
    {
        this->codigo = codigo;
        this->importe = importe;
        this->cliente1 = cliente1;
    }
    bool puedeConfirmarse()
    {
        return cliente1.getHabilitado() && cliente1.getSaldo() >= importe;
    }
    void mostrarConfirmacion()
    {
        if (puedeConfirmarse())
        {
            cout << "El pedido puede confirmarse " << endl;
        }
        else
        {
            cout << "El pedido no se confirmo" << endl;
        }
    }

    void mostrar()
    {
        cliente1.mostrar();
        cout << "Codigo: " << codigo << endl;
        cout << "importe: " << importe << endl;

    }
    int getImporte()
    {
        return importe;
    }
    Cliente1 getcliente1()
    {
        return cliente1;
    }
};
void ejercicio8()
{
    Cliente1 c1("pedro", 250, true);
    Cliente1 c2("daza", 300, false);
    Cliente1 c3("MAriana", 500, true);

    Pedido pedidos[3];
    pedidos[0] = Pedido(234, 100, c1);
    pedidos[1] = Pedido(456, 150, c2);
    pedidos[2] = Pedido(789, 200, c3);

    for (int i = 0; i < 3; i++)
    {
        pedidos[i].mostrar();
    }

   // cunatos pedidos pueden confirmarse esta hbilitado y tengs saldo suficiente
    int contadorpedidos = 0;
    for (int i = 0; i < 3; i++)
    {
        if (pedidos[i].puedeConfirmarse())
        {
            contadorpedidos++;
        }
    }
    cout << "Los pedidos confirados son: " << contadorpedidos << endl;
    //importe total de los pedidos confrimados
    int importetotal = 0;
    for (int i = 0; i < 3; i++)
    {
        if (pedidos[i].puedeConfirmarse())
        {
            importetotal = importetotal + pedidos[i].getImporte();
        }
    }
    cout << "el importe total de los pedido confirmados es: " << importetotal << " Bs" << endl;

    //cunatos pedidos fueron rechazados por saldo
    int rechazados = 0;
    for (int i = 0; i < 3; i++)
    {
        if (pedidos[i].getcliente1().getSaldo()<pedidos[i].getImporte())
        {
            rechazados++;
        }
    }
    cout << "Cantidad de pedidos rechazados por falta de saldo: " << rechazados << endl;

    //El pedido de mayor importe
    int mayorimporte = 0;
    int indicemayor = -1;
    for (int i = 0; i < 3; i++)
    {
        if (pedidos[i].getImporte() > mayorimporte)
        {
            mayorimporte = pedidos[i].getImporte();
            indicemayor = i;
        }
    }
    cout << "Pedido de mayor importe:" << endl;
    if (indicemayor != -1)
    {
        pedidos[indicemayor].mostrar();
    }
    // mostrar el nombre del cliente con el pedidos mas caro
    if (indicemayor != -1)
    {
        cout << "cliente con el pedido mas caro es:" << pedidos[indicemayor].getcliente1().getNombre() << endl;
    }
 
}



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
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << dni << endl;
        cout << "Edad: " << edad << endl;

    }
};
class Casa
{
private:
    string direccion;
    int precio;
    Propietario propietario;

public:
    Casa(){}
    Casa(string direccion, int precio, Propietario propietario)
    {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }
    bool esPropietarioValido()
    {
        int edadpropietario = propietario.getEdad();
        return edadpropietario >= MAYOR_EDAD;
    }
    void mostrarTitularidad()
    {
        if (esPropietarioValido())
        {
            cout << "La titularidad es valida" << endl;
        }
        else
        {
            cout << "La titularidad es invalida" << endl;
        }
    }
    void mostrar()
    {
        propietario.mostrar();
        cout << "direccion: " << direccion << endl;
        cout << "precio: " << precio << endl;
    }
    int getPrecio()
    {
        return precio;
    }
    Propietario getPropietario()
    {
        return propietario;
    }
};
void ejercicio9()
{
    Propietario p1("julian", 456, 19);
    Propietario p2("ricardo", 345, 15);
    Propietario p3("pirulo", 789, 21);

    Casa casas[3];

    casas[0] = Casa("Av.america", 200, p1);
    casas[1] = Casa("Av.Circunvalacion", 300, p2);
    casas[2] = Casa("An.Dorgbini", 500, p3);

    for (int i = 0; i < 3; i++)
    {
        casas[i].mostrar();
    }

    //calcule el precio total de casas propietario mayor de edad
    int prectotal = 0;
    for (int i = 0; i < 3; i++)
    {
        if (casas[i].esPropietarioValido())
        {
            prectotal = prectotal + casas[i].getPrecio();
        }
    }
    cout << "Precio total de casas: " << prectotal << endl;
    // calcule cassa que petenecen a mayored de edad
    int acucasas = 0;
    for (int i = 0; i < 3; i++)
    {
        if (casas[i].esPropietarioValido())
        {
            acucasas++;
        }
    }
    cout << "Cantidad de casas con propietarios mayores de edad: " << acucasas << endl;
    //precio totla de propietarios mayor 60 anios
    int precio60 = 0;
    for (int i = 0; i < 3; i++)
    {
        if (casas[i].getPropietario().getEdad() > 60)
        {
            precio60 = precio60 + casas[i].getPrecio();
        }
    }
    cout << "Precio total de casas con propietarios mayores de 60 anios: " << precio60 << endl;
    //Casa con mayor valor
    int mayorvalor = 0;
    int indicemayor = -1;
    for (int i = 0; i < 3; i++)
    {
        if (casas[i].esPropietarioValido() && casas[i].getPrecio() > mayorvalor)
        {
            mayorvalor = casas[i].getPrecio();
            indicemayor = i;
        }
    }
    cout << "casa de mayor valor con propietario valido" << endl;
    if (indicemayor != -1)
    {
        casas[indicemayor].mostrar();
    }
    // Promedio  de valor de cascas con propietarios entre 30 y 50 aniso
    int sumatresycinco = 0;//suma precio de las casas que tengane entre 30 a 50 anios
    int contadortresycinco = 0;// cuenta los porpietario
    for (int i = 0; i < 3; i++)
    {
        if (casas[i].getPropietario().getEdad() >= 30 && casas[i].getPropietario().getEdad() <= 50)
        {
            sumatresycinco = sumatresycinco + casas[i].getPrecio();
            contadortresycinco++;
        }
    }
    if (contadortresycinco > 0)
    {
        cout << "El promedio de valor de las casas con propietarios entre 30 y 50 anios es: "
            << float(sumatresycinco) / contadortresycinco << endl;
    }
    else
    {
        cout << "No hay casas con propietarios entre 30 y 50 anios." << endl;
    }

    //Cuantas casas tienen los propietarios menores de edad
    int menores = 0;
    for (int i = 0; i < 3; i++)
    {
        if (casas[i].getPropietario().getEdad() < MAYOR_EDAD)
        {
            menores++;
        }
    }
    cout << "Los propietarios menores de edas son: " << menores << endl;
} 

class Autor
{
private:
    string nombre;
    string nacionalidad;
    int cantidadDeLibrosPublicados;
public:
    Autor()
    {
        this->nombre = "";
        this->nacionalidad = "";
        this->cantidadDeLibrosPublicados = 0;
    }
    Autor(string nombre, string nacionalidad, int cantidadDeLibrosPublicados)
    {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadDeLibrosPublicados = cantidadDeLibrosPublicados;
    }
    int getCantidadDeLibrosPublicados()
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
    int precio;
    Autor autor;
public:
    Libro(){}
    Libro(string titulo, int precio, Autor autor)
    {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }
    bool esBestSeller()
    {
        return autor.getCantidadDeLibrosPublicados() > 5;
    }
    void mostrarBestSeller()
    {
        if (esBestSeller())
        {
            cout << "El libro es considerado Best Seller" << endl;
        }
        else
        {
            cout << "El libro no es considerado Best Seller" << endl;
        }
    }
    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Precio: " << precio << " Bs" << endl;
        autor.mostrar();
    }
    int getPrecio()
    {
        return precio;
    }
    Autor getAutor()
    {
        return autor;
    }
};
void ejercicio10()
{
    Autor a1("gabriel", "colombiana", 5);
    Autor a2("gaby", "boliviana", 7);
    Autor a3("mery", "argentina", 3);

    Libro libros[3];
    libros[0] = Libro("100 anios de soledad", 100, a1);
    libros[1] = Libro("frankenstein", 50, a2);
    libros[2] = Libro("la triste", 230, a3);

    for (int i = 0; i < 3; i++)
    {
        libros[i].mostrar();
    }

    // promedio de precio libros
    int n = 5;
    int sum = 0;
    int cont = 0;
    for (int i = 0; i < 3; i++)
    {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() > n)
        {
            sum = sum + libros[i].getPrecio();
            cont++;
        }
    }
    if (cont > 0)
        cout << "Promedio de precio de libros con autores > " << n << " libros: " << (sum) / cont << endl;
    else
        cout << "No hay autores con más de " << n << " libros." << endl;
    //precio de bestseller
    int sump = 0;
    int contp = 0;
    for (int i = 0; i < 3; i++)
    {
        if (libros[i].esBestSeller())
        {
            sump = sump + libros[i].getPrecio();
            contp++;
        }
    }
    if (contp > 0)
    {
        cout << "promedio de precio de libros bestSeller es " << (sump) / contp << endl;
    }
    else
    {
        cout << "no hay libros bestSeller" << endl;
    }
    //libro mas caro con autor reconocido
    int acumayor = 0;
    int indiceMayor = -1;
    for (int i = 0; i < 3; i++)
    {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() > n && libros[i].getPrecio() > acumayor)
        {
            acumayor = libros[i].getPrecio();
            indiceMayor = i;
        }
    }
    if (indiceMayor != -1)
    {
        cout << "Libro más caro de un autor reconocido:" << endl;
        libros[indiceMayor].mostrar();
    }
    else
    {
        cout << "No hay autores reconocidos." << endl;
    }
    // cuantos libros autores novatos
    int novatos = 0;
    for (int i = 0; i < 3; i++)
    {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() <= n)
        {
            novatos++;
        }
    }
    cout << "Cantidad de libros autores novatos" << novatos << endl;
    //autpres productivos
    int productivos=0;
    for (int i = 0; i < 3; i++)
    {
        if (libros[i].getAutor().getCantidadDeLibrosPublicados() > n)
        {
            productivos = productivos + libros[i].getPrecio();
        }
    }

    cout << "Total recaudado por libros de autores productivos: " << productivos << " Bs" << endl;
}


class Carrera
{
private:
    string nombre;
    int duracion;
    int cupoDisponible;
public:

    Carrera()
    {
        this->nombre = "";
        this->duracion = 0;
        this->cupoDisponible = 0;
    }

    Carrera(string nombre, int duracion, int cupoDisponible)
    {
        this->nombre = nombre;
        this->duracion = duracion;
        this->cupoDisponible = cupoDisponible;
    }
    int getCupoDisponible()
    {
        return cupoDisponible;
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Duracion: " << duracion << " anios" << endl;
        cout << "Cupo Disponible: " << cupoDisponible << endl;
    }

    int getDuracion()
    {
        return duracion;
    }
    string getNombre()
    {
        return nombre;
    }
};
class Estudiante
{
private:
    string nombre;
    int edad;
    Carrera carrera;

public:
    Estudiante(){}
    Estudiante(string nombre, int edad, Carrera carrera)
    {
        this->nombre = nombre;
        this->edad = edad;
        this->carrera = carrera;
    }
    bool puedeInscribirse()
    {
        return edad >= MAYOR_EDAD && carrera.getCupoDisponible() > 0;
    }
    void mostrarInscripcion()
    {
        if (puedeInscribirse())
        {
            cout << "El estudiante puede inscribirse" << endl;
        }
        else
        {
            cout << "El estudiante no puede inscribirse" << endl;
        }
    }

    void mostrar()
    {
        carrera.mostrar();
        cout << "Nombre: " << nombre << endl;
        cout << "edad: " << edad << endl;

    }
    string getNombre()
    {
        return nombre;
    }
    Carrera getCarrera()
    {
        return carrera;
    }
    int getEdad()
    {
        return edad;
    }
    
};
void ejercicio11()
{
    Carrera ca1("medicina", 6, 8);
    Carrera ca2("Odontologia", 5, 10);
    Carrera ca3("Ingenieria", 4, 4);

    Estudiante estudiante[3];

    estudiante[0] = Estudiante("josefa", 21, ca1);
    estudiante[1] = Estudiante("juanito", 20, ca2);
    estudiante[2] = Estudiante("alberti", 18, ca3);
    for (int i = 0; i < 3; i++)
    {
        estudiante[i].mostrar();
    }
    //cuantos estudiante spueden inscribirse
    int inscritos = 0;
    for (int i = 0; i < 3; i++)
    {
        if (estudiante[i].puedeInscribirse())
        {
            inscritos++;
        }
    }
    cout << "Los cantidad de estudiantes inscritos es: " << inscritos << endl;

    //estudiante cuya carrra tenga mayor duracion
    int duracionmayor = 0;
    int indicemayor = -1;
    for (int i = 0; i <3; i++)
    {
        if (estudiante[i].getCarrera().getDuracion() > duracionmayor)
        {
            duracionmayor = estudiante[i].getCarrera().getDuracion();
            indicemayor=i;
        }
    }
    if (indicemayor != -1)
    {
        cout << "El estudiante con mayor duracion de carrera es: " << estudiante[indicemayor].getNombre() << endl;
    }
    // edad promedio
    int sumedad = 0;
    int contcupo = 0;
    for (int i = 0; i < 3; i++)
    {
        if(estudiante[i].getCarrera().getCupoDisponible()>0)
        { 
            sumedad = sumedad + estudiante[i].getEdad();
            contcupo++;
        }
    }
    if (contcupo > 0)
        cout << "Edad promedio de estudiantes con carreras con cupo: " << (sumedad) / contcupo << endl;
    else
        cout << "No hay estudiantes con carreras con cupo." << endl;
    //no pueden inscribirse por falta de cupo
    int sincupo = 0;
    for (int i = 0; i < 3; i++)
    {
        if (estudiante[i].getCarrera().getCupoDisponible() == 0)
        {
            sincupo++;

        }

    }
    cout<< "Cantidad de estudiantes que no pueden inscribirse por falta de cupo: " << sincupo << endl;
    //edtuaintes  dada una carrera
    string nombreCarrera = "medicina";
    int unacarrera = 0;
    for (int i = 0; i < 3; i++)
    {
        if (estudiante[i].getCarrera().getNombre() == nombreCarrera)
        {
            unacarrera++;
        }
    }
    cout << "Cantidad de estudiantes en la carrera " << nombreCarrera << ": " << unacarrera << endl;
}

int main()
{
   
   ejercicio7();
    ejercicio8();
    ejercicio9();
    ejercicio10();
    ejercicio11();
}