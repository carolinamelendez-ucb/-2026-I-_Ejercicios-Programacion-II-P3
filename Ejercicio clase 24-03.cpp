// Ejercicio clase 24-03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;
    float salario;
    string departamento;
public:
    
    Empleado (const string& nombre, float salario, const string& departamento)
    : nombre (nombre), salario (salario), departamento (departamento)
    {
    }

    void mostrar (){
         cout << "Nombre: " << nombre << endl;
         cout << "Salario: " << salario << endl;
         cout << "Departamento: " << departamento << endl;
    }

    int calcularSalario (){
        return salario;
    }
};

class EmpleadoPlanta : public Empleado {
private:
    int salarioExtra;
public:
    EmpleadoPlanta(string nombre, float salario, int salarioExtra) : Empleado (nombre, salario , "Planta"){
        this -> salarioExtra = salarioExtra;
    }

    int calcularSalario (){
        return Empleado :: calcularSalario()  + salarioExtra + 1000;
    }
};

class Contratista : public Empleado {
    private:
    int diasTrabajados;
    public:
    Contratista (string nombre, float salario, int diasTrabajados) : Empleado (nombre, salario , "Contratos"){
        this->diasTrabajados = diasTrabajados;
    }

    int calcularSalario (){
        return (Empleado::calcularSalario () / 30) * diasTrabajados;
    }
};

class Ejecutivo : public Empleado {
    private:
    int comision;
    int ventas;
    public:
    Ejecutivo (string nombre, float salario, int comision, int ventas) : Empleado (nombre, salario, "Ventas"){
        this->comision = comision;
        this-> ventas = ventas;
    }

    int calcularSalario (){
        return Empleado::calcularSalario () + (comision * ventas) ;
    }
};

int main()
{
    Empleado empleado = Empleado ("Alan" , 1000 , "Gerencia");

    empleado.mostrar();
    cout << endl;

    EmpleadoPlanta planta1 = EmpleadoPlanta("Jorge" , 500 , 500);
    planta1.mostrar();
    cout << "Nuevo salario: " << planta1.calcularSalario () << endl;

    cout << endl;
    cout << endl;
    Contratista contratista1 = Contratista ("Fabian" , 3000 , 10);
    contratista1.mostrar();
    cout << "Salario actual: " << contratista1.calcularSalario()<<endl;
    cout << endl;
    cout << endl;
    Ejecutivo ejecutivo1 = Ejecutivo("Marcelo" , 1000 , 200 , 5);
    ejecutivo1.mostrar();
    cout << "Salario mas comision de ventas es: " << ejecutivo1.calcularSalario()<<endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
