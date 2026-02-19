// TAREA_EJ11_0212.cpp 
//18/02/26
/* Ejercicio 11. Relación Estudiante – Carrera

- En el main(), cree un arreglo de Estudiantes
- Implemente un método que muestre cuántos estudiantes pueden inscribirse, es decir, los que sean
  mayores de edad y cuya carrera tenga cupo.
- Implemente un método que recorra el arreglo y muestre el nombre del estudiante cuya carrera tenga mayor duración.
- Implemente un método que recorra el arreglo y calcule la edad promedio de los estudiantes con carreras con cupo.
- Implemente un método que recorra el arreglo y muestre cuántos estudiantes no pueden inscribirse por falta de cupo.
- Implemente un método que recorra el arreglo y muestre la cantidad de estudiantes dada una carrera.     */

#include <iostream>
#include <string>
using namespace std;

const int MAYOR_DE_EDAD = 18;

class Carrera
{
private:
    string nombre;
    int duracion; 
    bool tieneCupo;

public:
    Carrera()
    {
        nombre = "";
        duracion = 0;
        tieneCupo = false;
    }

    Carrera(string nombre, int duracion, bool tieneCupo)
    {
        this->nombre = nombre;
        this->duracion = duracion;
        this->tieneCupo = tieneCupo;
    }

    string getNombre()
    {
        return nombre;
    }

    int getDuracion()
    {
        return duracion;
    }

    bool isTieneCupo()
    {
        return tieneCupo;
    }
};

class Estudiante
{
private:
    string nombre;
    int edad;
    Carrera carrera;

public:
    Estudiante()
    {
        nombre = "";
        edad = 0;
        carrera = Carrera();
    }

    Estudiante(string nombre, int edad, Carrera carrera)
    {
        this->nombre = nombre;
        this->edad = edad;
        this->carrera = carrera;
    }

    string getNombre()
    {
        return nombre;
    }

    int getEdad()
    {
        return edad;
    }

    Carrera getCarrera()
    {
        return carrera;
    }

    bool puedeInscribirse()
    {
        return edad >= MAYOR_DE_EDAD && carrera.isTieneCupo();
    }
};


int main()
{
    Carrera c1("Ingenieria", 5, true);
    Carrera c2("Medicina", 7, false);
    Carrera c3("Derecho", 4, true);

    Estudiante estudiantes[6];

    estudiantes[0] = Estudiante("Ana", 20, c1);
    estudiantes[1] = Estudiante("Luis", 17, c1);
    estudiantes[2] = Estudiante("Pedro", 22, c2);
    estudiantes[3] = Estudiante("Maria", 25, c3);
    estudiantes[4] = Estudiante("Carlos", 19, c2);
    estudiantes[5] = Estudiante("Lucia", 21, c3);

    int n = 6;

    //Cuantos pueden inscribirse
    int pueden = 0;

    for (int i = 0; i < n; i++)
    {
        if (estudiantes[i].puedeInscribirse())
            pueden++;
    }
    cout << "Estudiantes que pueden inscribirse: " << pueden << endl;

    //Nombre del estudiante cuya carrera tenga mayor duracion
    int mayorDuracion = 0;
    int posMayor = -1;

    for (int i = 0; i < n; i++)
    {
        if (estudiantes[i].getCarrera().getDuracion() > mayorDuracion)
        {
            mayorDuracion = estudiantes[i].getCarrera().getDuracion();
            posMayor = i;
        }
    }

    if (posMayor != -1)
    {
        cout << "Estudiante con carrera de mayor duracion: " << estudiantes[posMayor].getNombre() << endl;
    }

    // Edad promedio estudiantes con carreras con cupo
    int sumaEdades = 0;
    int contador = 0;

    for (int i = 0; i < n; i++)
    {
        if (estudiantes[i].getCarrera().isTieneCupo())
        {
            sumaEdades += estudiantes[i].getEdad();
            contador++;
        }
    }

    if (contador > 0)
        cout << "Edad promedio carreras con cupo: " << sumaEdades / contador << endl;

    // Estudiantes que NO pueden inscribirse por falta de cupo
    int sinCupo = 0;

    for (int i = 0; i < n; i++)
    {
        if (!estudiantes[i].getCarrera().isTieneCupo())
            sinCupo++;
    }
    cout << "Estudiantes que no pueden inscribirse por falta de cupo: " << sinCupo << endl;

    //Cantidad de estudiantes dada una carrera
    string nombreCarreraBuscada = "Ingenieria";
    int cantidadCarrera = 0;

    for (int i = 0; i < n; i++)
    {
        if (estudiantes[i].getCarrera().getNombre() == nombreCarreraBuscada)
            cantidadCarrera++;
    }

    cout << "Cantidad de estudiantes en " << nombreCarreraBuscada << ": "<< cantidadCarrera << endl;

    return 0;
}

