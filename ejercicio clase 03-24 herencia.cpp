// ejercicio clase 03-24 herencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>

using namespace std;

class Empleado
{
protected:
    string nombre;
    float salarioBase;
    string departamento;
public:
    Empleado(const string& nombre, float salarioBase, const string& departamento)
        : nombre(nombre), salarioBase(salarioBase), departamento(departamento)
    {
    }
    void mostrar()
    {
        cout << "nombre " << nombre<<endl;
        cout << "salario base: " << salarioBase<<endl;
        cout << "departamento: " << departamento<<endl;
    }

    float calcularSalario()
    {
        return salarioBase;
    }
};

class EmpleadoPlanta:public Empleado
{
private:
    float salarioExtra;
public:
    EmpleadoPlanta(string nombre, string departamento, float salarioExtra) :
        Empleado(nombre, 1000, departamento)
    {
        this->salarioExtra = salarioExtra;
    }
    float calcularSalario()
    {
        return salarioBase + salarioExtra;
    }
    void mostrar()
    {
        Empleado::mostrar();
        cout << "el nuevo salrio es: " << calcularSalario() << endl;
    }

};


#include <iostream>

int main()
{
    Empleado empleado1 = Empleado("carlitos", 1000, "cochabamba");
    empleado1.calcularSalario();
    empleado1.mostrar();

    EmpleadoPlanta empleado2 = EmpleadoPlanta("estfania", "oruro", 500);
    empleado2.calcularSalario();
    empleado2.mostrar();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
