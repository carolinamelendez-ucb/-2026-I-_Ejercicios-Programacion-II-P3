#include <iostream>
#include <string>

using namespace std;


class Cliente
{
    string nombre ;
    double saldoHabilitado;
    bool habilitado;

    public:
    Cliente(string _nombre , double _saldoHabilitado , bool _habilitado)
    {
        this->nombre=_nombre;
        this->habilitado = _habilitado;
        this->saldoHabilitado=_saldoHabilitado;
    }

    string getNombre()
    {
        return nombre;
    }
    
    double getSaldoHabilitado()
    {
        return saldoHabilitado;
    }

    bool getHabilitado()
    {
        return habilitado;
    }

    void setSaldoDisponible(double saldoNuevo)
    {
        this ->saldoHabilitado = saldoNuevo;
    }


    void setHabilitado( bool nuevoHabilitado)
    {
        this ->habilitado = nuevoHabilitado;
    }

    void mostrarCliente()
    {
        cout << "El nombre del cliente : " << nombre << endl;
        cout << "SALDO DISPONIBLE : " << saldoHabilitado << endl;
        cout << "Habilitado "<< habilitado << endl;
    }

};


class Pedido 
{
    private:
    string codigo;
    double importe;
    Cliente cliente;

    public:

    Pedido(string _codigo, double _importe , Cliente _cliente) : cliente(_cliente)
    {
        this ->codigo= _codigo;
        this ->importe = _importe;
    }

    bool puedeConfirmarse()
    {
        if(cliente.getHabilitado()==true && cliente.getSaldoHabilitado()>= importe)
        {
                return true;
        }
        else 
        {
            return false;
        }
    }

    void mostrarPedido()
    {
        cout << " CODIGO DEL PEDIDO : " << codigo << endl;
        cout << " IMporte total : " << importe << endl;
        cliente.mostrarCliente(); 
    }




};


class Autor
{

    private:
    string nombre;
    string nacionalidad;
    int cantidadDeLibrosPublicados;

    public:
    Autor(string _nombre , string _nacionalidad , int _cantidadDeLibrosPublicados)
    {
        this ->nombre = _nombre;
        this ->nacionalidad =_nacionalidad;
        this ->cantidadDeLibrosPublicados=_cantidadDeLibrosPublicados;
    }

    int getCantidadLibrosPublicados()
    {
        return cantidadDeLibrosPublicados;
    }

    void mostrarAutor()
    {

        cout << "nombre del autor : "<< nombre << endl;
        cout << "Nacionalidad del autor : "<< nacionalidad << endl;
        cout << "cantidad de libros publicados por el autor : "<< cantidadDeLibrosPublicados << endl;

    }

};

class Libro
{
    private :
    string titulo;
    int precio;
    Autor autor1;

    public:

    Libro(string _titulo , int _precio , Autor _autor1) : autor1(_autor1)
    {
        this -> titulo = _titulo;
        this ->precio= _precio;
    }

    bool esBestSeller()
    {
        if(autor1.getCantidadLibrosPublicados()>5)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    void mostrarLibro()
    {
        cout << "Titulo del libro: " << titulo << endl;
        cout << "Precio: " << precio << endl;
        autor1.mostrarAutor();
    }

};

class Carrera
{
    private:

    string nombre;
    int duracion;
    int cupoDisponible;

    public:

    Carrera(string _nombre , int _duracion , int _cupoDisponible)
    {
        this ->nombre=_nombre;
        this ->duracion=_duracion;
        this ->cupoDisponible=_cupoDisponible;
    }

    int getCupoDisponible()
    {
        return cupoDisponible;
    }
    void mostrarCarrera()
    {
        cout << " Nombre de la carrera : "<< nombre << endl;
        cout << " Duracion en anios de la carrera : " << duracion << endl;
        cout << " Cupo disponible : "<< cupoDisponible << endl;
    }

};
class Estudiante
{
    private:
    string nombre;
    int edad;
    Carrera carrera;

    public:
    Estudiante(string _nombre , int _edad , Carrera _carrera): carrera(_carrera)
    {
        this ->nombre=_nombre;
        this ->edad=_edad;
    }



    bool puedeInscribirse()
    {
        if(edad >= 18 && carrera.getCupoDisponible()>0)
        {return true;}
        else 
        {return false;}
    }

    void mostrarEstudiante(){
        cout << " Nombre del estudiante " << nombre << endl;
        cout << " Edad del estudiate " << edad << endl;
        carrera.mostrarCarrera();
    }

};


void ejercicio3()
{
    Cliente cliente1("Juan", 500, true);

    Pedido pedido1("P001", 300, cliente1);
    pedido1.mostrarPedido();

    if(pedido1.puedeConfirmarse())
    {
        cout << " El pedido esta confirmado" << endl;
    }
    else
    {
        cout << "El pedido no se puede confirmar" << endl;
    }
    
}

void ejericio5()
{
    Autor autor1("Gabriel Garcia Marquez", "Colombiana", 10);

    Libro libro1("Cien Años de Soledad", 50000, autor1);

    libro1.mostrarLibro();

    if(libro1.esBestSeller())
    {
        cout << "El libro es considerado Best Seller" << endl;
    }
    else
    {
        cout << "El libro NO es Best Seller" << endl;
    }
}

void ejercicio6()
{
    Carrera carrera1("Ingenieria en Sistemas", 5, 10);

    Estudiante estudiante1("Carlos", 20, carrera1);

    estudiante1.mostrarEstudiante();

    if(estudiante1.puedeInscribirse())
    {
        cout << "El estudiante puede inscribirse" << endl;
    }
    else
    {
        cout << "El estudiante NO puede inscribirse" << endl;
    }

}

int main()
{
    //ejercicio3();
    //ejericio5();
    ejercicio6();

    return 0;
}
