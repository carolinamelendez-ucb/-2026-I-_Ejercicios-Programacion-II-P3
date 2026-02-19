// TAREA_EJ9_1202.cpp 
//18/02/26
/* Ejercicio 9. Relación Casa – Propietario

- En el main(), cree un arreglo de Casas
- Implemente un método que calcule el precio total de todas las casas cuyos propietarios sean mayores de edad.
- Implemente un método que recorra el vector y cuente cuántas casas pertenecen a propietarios mayores de edad.
- Implemente un método que recorra el arreglo y calcule el precio total de las casas cuyos propietarios tengan más de 60 años.
- Implemente un método que recorra el arreglo y muestre la casa de mayor valor con propietario válido.
- Implemente un método que recorra el arreglo y calcule el promedio de valor de las casas con propietarios entre 30 y 50 años.
- Implemente un método que recorra el arreglo y muestre cuántas casas tienen propietarios menores de edad. */

#include <iostream>
#include <string>
using namespace std;


const int MAYOR_DE_EDAD = 18;

class Propietario
{
private:
    string nombre;
    int DNI;
    int edad;

public:
    Propietario()
    {
        nombre = "";
        DNI = 0;
        edad = 0;
    }

    Propietario(string nombre, int DNI, int edad)
    {
        this->nombre = nombre;
        this->DNI = DNI;
        this->edad = edad;
    }

    int getEdad()
    {
        return edad;
    }

    string getNombre()
    {
        return nombre;
    }

    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << DNI << endl;
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
    Casa()
    {
        direccion = "";
        precio = 0;
        propietario = Propietario();
    }

    Casa(string direccion, int precio, Propietario propietario)
    {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }

    int getPrecio()
    {
        return precio;
    }

    Propietario getPropietario()
    {
        return propietario;
    }

    bool esPropietarioValido()
    {
        return propietario.getEdad() >= MAYOR_DE_EDAD;
    }

    void mostrar()
    {
        cout << "Direccion: " << direccion << endl;
        cout << "Precio: " << precio << endl;
        propietario.mostrar();
        cout << "------------------------" << endl;
    }
};


int main()
{
    Propietario p1("Miguel", 123, 25);
    Propietario p2("Maria", 133, 65);
    Propietario p3("Luis", 222, 16);
    Propietario p4("Ana", 333, 40);

    Casa casas[6];

    casas[0] = Casa("Av. Libertador", 600, p1);
    casas[1] = Casa("Av. Ecuador", 250, p2);
    casas[2] = Casa("Av. Petrolera", 300, p3);
    casas[3] = Casa("Av. America", 450, p4);
    casas[4] = Casa("Av. Viloma", 800, p2);
    casas[5] = Casa("Av. Blanco", 200, p3);

    int n = 6;

    //Total precio propietarios mayores de edad
    int totalMayores = 0;
    for (int i = 0; i < n; i++)
    {
        if (casas[i].esPropietarioValido())
            totalMayores += casas[i].getPrecio();
    }
    cout << "Total casas propietarios mayores de edad: " << totalMayores << endl;

    // Contar casas propietarios mayores de edad
    int contadorMayores = 0;
    for (int i = 0; i < n; i++)
    {
        if (casas[i].esPropietarioValido())
            contadorMayores++;
    }
    cout << "Cantidad casas de propietarios mayores de edad: " << contadorMayores << endl;

    //Total casas propietarios > 60 años
    int totalMayores60 = 0;
    for (int i = 0; i < n; i++)
    {
        if (casas[i].getPropietario().getEdad() > 60)
            totalMayores60 += casas[i].getPrecio();
    }
    cout << "Total casas propietarios mayores de 60: " << totalMayores60 << endl;

    //Casa de mayor valor con propietario valido
    int mayor = 0;
    int posMayor = -1;

    for (int i = 0; i < n; i++)
    {
        if (casas[i].esPropietarioValido())
        {
            if (casas[i].getPrecio() > mayor)
            {
                mayor = casas[i].getPrecio();
                posMayor = i;
            }
        }
    }

    if (posMayor != -1)
    {
        cout << "Casa de mayor valor con propietario valido:" << endl;
        casas[posMayor].mostrar();
    }


    //Promedio casas propietarios entre 30 y 50 años
    int suma = 0;
    int contador = 0;

    for (int i = 0; i < n; i++)
    {
        int edad = casas[i].getPropietario().getEdad();

        if (edad >= 30 && edad <= 50)
        {
            suma += casas[i].getPrecio();
            contador++;
        }
    }

    if (contador > 0)
        cout << "Promedio casas propietarios entre 30 y 50: " << suma / contador << endl;
    else
        cout << "No hay propietarios entre 30 y 50 años." << endl;

    //Casas con propietarios menores de edad
    int menores = 0;
    for (int i = 0; i < n; i++)
    {
        if (casas[i].getPropietario().getEdad() < MAYOR_DE_EDAD)
            menores++;
    }

    cout << "Cantidad casas con propietarios menores de edad: "<< menores << endl;

    return 0;
}

