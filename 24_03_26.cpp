#include <iostream>
#include <string>
using namespace std;

/*
Hoy veremos HERENCIA

a) todo esto es herencia pura
b) herencia con atributos
c) herencia con extension de atributos
d) herencia con extencion de metodos
e) herencia con sobre-escritura de metodos

*/


// CLASE PADRE

class Animal {
protected:                        /// INVESTIGA ESO (its your homework)
    string raza;
    string nombre;
    int peso;
public:
    Animal(string nom,string rz,int ps){
        this->nombre = nom;
        this->raza = rz;
        this->peso = ps;
    }
    void mostrar() {
        cout << "Raza:"<<raza << endl;
        cout << "Nombre:"<<nombre << endl;
        cout << "Peso:"<<peso << endl;
    }
    void ladrar() {
        cout << "Wao wao" << endl;
    }
    int calcularEdad() {
        return (peso * 2) + 500;  
    }
};


class Perro : public Animal {
public: 
    Perro(string raza, string nombre, int peso):
        Animal(nombre, raza, peso)
    { 
    }
};


// c herecia con atributos externos
class Perro : public Animal {
public:
    Perro(string raza, string nombre, int peso):
        Animal("Chihuahua", raza, peso)
    {

    }
};

class Perro : public Animal {
private:
    string tipoPelaje;
public:
    Perro(string raza, string nombre, int peso,string tipoPel):
        Animal(nombre, raza, peso)//you can put here the other 
    {
        this->tipoPelaje = tipoPel;
    }
    void mostrar() {
        Animal::mostrar();  /// this is the form for show and add the other attribute
        cout << "Tipo pelaje: "<<tipoPelaje<< endl;
    }
};




/// EJERCICIO DE CLASEEEEEEEEEEEEEEE

class Empleado {
protected:
    string nombre;
    float salario_base;
    string departamento;
public:
    Empleado(string nom,float sal,string dep){
        this->nombre = nom;
        this->departamento = dep;
        this->salario_base = sal;
    }
    void mostrar() {
        cout << "Nombre:"<<nombre << endl;
        cout << "Departamento:" << departamento << endl;
        cout << "Salario Base:" << salario_base << endl;
    }
};


class EmpleadoPlanta: public Empleado {
private:
    float salario_extra;
public:
    EmpleadoPlanta(string nom, float sal, string dep,float salarioEx) :
        Empleado("oficinista", 10000, "oficinas") {
        this->salario_extra = salarioEx;
    }
    void mostrar() {
        Empleado::mostrar();
        cout << "Salario extra:" << salario_extra << endl;
    }
};

class Contratista : public Empleado {
private:
    int dias_trabajados;
public:
    Contratista(string nom, float sal, string dep, int dias) :
        Empleado("Contratista", 12000, "Ejecucion de Contratos") {
        this->dias_trabajados = dias;
    }
    void mostrar() {
        Empleado::mostrar();
        cout << "Dias de trabajo:" << dias_trabajados << endl;
    }
};

class Ejecutivo : public Empleado {
private:
    float comision;
public:
    Ejecutivo(string nom,float sal,string dep,float comi):
        Empleado("Ejecutivo",20000,"Gerencia") {
        this->comision = comi;
    }
    void mostrar() {
        cout << "Comision:"<<comision << endl;
    }
};











int main(){
    Animal animal1= Animal("Palomino", "caniche", 5);
    animal1.mostrar();

   // Perro perro1 = Perro("golden","Tongo",8);
}

