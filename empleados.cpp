using namespace std;
#include <iostream>
#include <iostream>
class Empleado {
private:
    string nombre;
    float salario;
    string departamento;
public:
    Empleado(string nombre, float salario, string departamento) {
        this->nombre = nombre;
        this->salario = salario;
        this->departamento = departamento;
    }
    int salario() {
        return salario;
    }
};
class EmpleadoPlant: public Empleado{
private:
    float salarioextra;
public:
    EmpleadoPlant(string nombre, float salario, string departamento, float salarioextra) :
        Empleado(nombre, salario, departamento)
    {
        this->salarioextra = salarioextra;

    }
    int calcularsalario() {
        int total;
         total= salario() + salarioextra;
         return total;
    }
};
class Contratista : public Empleado {
private:
    int diastrabajador;
public:
    Contratista(string nombre, float salario, string departamento, int diastrabajados) :
        Empleado(nombre, salario, departamento)
    {
        this->diastrabajador = diastrabajados;

    }
    int calcularsalario() {
        int total;
        total = salario() * diastrabajador/30;
        return total;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}


