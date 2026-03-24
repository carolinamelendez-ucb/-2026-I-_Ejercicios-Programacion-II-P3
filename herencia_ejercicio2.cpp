// herencia_ejercicio2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
using namespace std;
class Empleado {
protected:
    string nombre;
    float salario_base;
    string departamento;
public:
    Empleado(const string& nombre, float salario_base, const string& departamento)
        : nombre(nombre), salario_base(salario_base), departamento(departamento)
    {
    }
    float setcalcularSalario() {
        return salario_base;
    }
   void  mostrar() {
       cout << "nombre: " <<nombre<< endl;
       cout << "salrio_base" << salario_base << endl;
       cout << "departamento: " << departamento << endl;
       
    }
};
class Empleado_planta : public Empleado {
private:
    float salario_extra;
public:
    Empleado_planta(const string& nombre, float salario_base, const string& departamento,float salario_extra):
        Empleado(nombre,salario_base,departamento) {
        this->salario_extra = salario_extra;
    }
    
    float setcalcularSalario() {
        Empleado::setcalcularSalario() + salario_extra;
    }
    void mostrar() {
        Empleado::mostrar();
        cout << "salarioFijado" << endl;
        setcalcularSalario();
    }
};
class Contratista : public Empleado {
private:
   int dia_trabajos;
public:
    Contratista(string nombre,float salario_base,string departamento,int dias) :
        Empleado(nombre,salario_base,departamento){
        this->dia_trabajos = dias;
    }
    float calcularSalario() {
        Empleado::setcalcularSalario()* dia_trabajos;
    }
    void mostrar() {
        Empleado::mostrar();
        cout << "salarioFijado" << endl;
        calcularSalario();
    }
};
class Ejecutivo : public Empleado {
private:
    float comision;
public:
    Ejecutivo(string nombre, float salario_base, string departamento, float comision) :
        Empleado(nombre, salario_base, departamento) {
        this->comision = comision;
    }
    float calcularSalario() {
        Empleado::setcalcularSalario() * comision;
    }
    void mostrar() {
        Empleado::mostrar();
        cout << "salarioFijado" << endl;
        calcularSalario();
    }
};
int main()
{
    Empleado_planta empleado1 = Empleado_planta("carlos", 1000, "la paz", 100);
    empleado1.setcalcularSalario();
    empleado1.mostrar();

}

