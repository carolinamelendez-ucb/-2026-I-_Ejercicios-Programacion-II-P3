#include <iostream>
#include <string>
using namespace std;


//  EMPLEADO (clase padre)

class Empleado
{
protected:
    string nombre;
    float  salarioBase;
    string departamento;
public:
    Empleado(string nombre, float salarioBase, string departamento)
    {
        this->nombre = nombre;
        this->salarioBase = salarioBase;
        this->departamento = departamento;
    }

    float calcularSalario()
    {
        return salarioBase;
    }

    void mostrar()
    {
        cout << "  Nombre       : " << nombre << endl;
        cout << "  Departamento : " << departamento << endl;
        cout << "  Salario base : " << salarioBase << endl;
        cout << "  Salario total: " << calcularSalario() << endl;
    }
};


//  EMPLEADO PLANTA (hijo)
class EmpleadoPlanta : public Empleado
{
private:
    float salarioExtra;
public:
    EmpleadoPlanta(string nombre, float salarioBase,
        string departamento, float salarioExtra = 0)
        : Empleado(nombre, salarioBase, departamento)
    {
        this->salarioExtra = salarioExtra;
    }

    float calcularSalario()
    {
        return salarioBase + 1000 + salarioExtra;
    }

    void mostrar()
    {
        cout << "  [Empleado de Planta]" << endl;
        cout << "  Nombre       : " << nombre << endl;
        cout << "  Departamento : " << departamento << endl;
        cout << "  Salario base : " << salarioBase << endl;
        cout << "  Salario extra: " << salarioExtra << endl;
        cout << "  Salario total: " << calcularSalario() << endl;
    }
};


class Contratista : public Empleado
{
private:
    int diasTrabajados;
public:
    Contratista(string nombre, float salarioBase,
        string departamento, int diasTrabajados)
        : Empleado(nombre, salarioBase, departamento)
    {
        this->diasTrabajados = diasTrabajados;
    }

    
    float calcularSalario()
    {
        return salarioBase * diasTrabajados;
    }

    void mostrar()
    {
        cout << "  [Contratista]" << endl;
        cout << "  Nombre         : " << nombre << endl;
        cout << "  Departamento   : " << departamento << endl;
        cout << "  Salario base   : " << salarioBase << endl;
        cout << "  Dias trabajados: " << diasTrabajados << endl;
        cout << "  Salario total  : " << calcularSalario() << endl;
    }
};


//  EJECUTIVO (hijo)

class Ejecutivo : public Empleado
{
private:
    float comision;
public:
    Ejecutivo(string nombre, float salarioBase,
        string departamento, float comision)
        : Empleado(nombre, salarioBase, departamento)
    {
        this->comision = comision;
    }

   
    float calcularSalario()
    {
        return salarioBase + comision;
    }

    void mostrar()
    {
        cout << "  [Ejecutivo]" << endl;
        cout << "  Nombre       : " << nombre << endl;
        cout << "  Departamento : " << departamento << endl;
        cout << "  Salario base : " << salarioBase << endl;
        cout << "  Comision     : " << comision << endl;
        cout << "  Salario total: " << calcularSalario() << endl;
    }
};


int main()
{
    cout << "=== Sistema de Gestion de Empleados ===" << endl;

    
    EmpleadoPlanta e1("Ana Torres", 3000, "Produccion", 500);
    EmpleadoPlanta e2("Luis Rios", 2500, "Logistica");    // sin salario extra
    Contratista    e3("Pedro Vargas", 100, "Sistemas", 20);
    Ejecutivo      e4("Maria Lopez", 5000, "Gerencia", 2000);

    cout << ".................salarios ===" << endl;
    cout << "Ana    (Planta)     : " << e1.calcularSalario() << endl;
    cout << "Luis   (Planta)     : " << e2.calcularSalario() << endl;
    cout << "Pedro  (Contratista): " << e3.calcularSalario() << endl;
    cout << "Maria  (Ejecutivo)  : " << e4.calcularSalario() << endl;


    cout << "Empleado 1 ---" << endl;
    e1.mostrar();

    cout << " Empleado 2 ---" << endl;
    e2.mostrar();

    cout << "Empleado 3 ---" << endl;
    e3.mostrar();

    cout << " Empleado 4 ---" << endl;
    e4.mostrar();

    
    

    return 0;
}