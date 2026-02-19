// TAREA_0212.cpp 
// 18/02/26

/* Ejercicio 7. Relación  Factura – Cliente

- En el main(), cree un arreglo de facturas.
- Implemente un método que recorra el arreglo y calcule el monto total facturado solo para 
  clientes frecuentes con más de 2 años de antigüedad.
- Implemente un método que recorra el arreglo y cuente cuántas facturas pertenecen a clientes normales.
- Implemente un método que recorra el arreglo y muestre la factura de mayor monto correspondiente a un cliente frecuente.
- Implemente un método que recorra el arreglo y calcule el promedio de monto de las facturas emitidas 
  a clientes con más de 5 años de antigüedad.
- Implemente un método que recorra el arreglo y muestre cuántas facturas están impagas y el total adeudado por clientes frecuentes.
*/

#include <iostream>
#include <string>
using namespace std;

class Cliente
{
private:
    string nombre;
    string tipo;
    int antiguedad;

public:
    Cliente()
    {
        nombre = "";
        tipo = "";
        antiguedad = 0;
    }

    Cliente(string nombre, string tipo, int antiguedad)
    {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
    }
    string getNombre()
    {
        return nombre;
    }
    string getTipo()
    {
        return tipo;
    }
    int getAntiguedad()
    {
        return antiguedad;
    }
};

class Factura
{
private:
    int numero;
    float monto;
    bool pagada;
    Cliente cliente;

public:
    Factura()
    {
        this->numero = 0;
        this->monto = 0;
        this->pagada = false;
        this->cliente = Cliente();
    }
    Factura(int numero, float monto, bool pagada, Cliente cliente)
    {
        this->numero = numero;
        this->monto = monto;
        this->pagada = pagada;
        this->cliente = cliente;
    }
    int getNumero()
    {
        return numero;
    }

    float getMonto()
    {
        return monto;
    }

    bool isPagada()
    {
        return pagada;
    }

    Cliente getCliente()
    {
        return cliente;
    }

    void mostrar()
    {
        cout << "Numero: " << numero << endl;
        cout << "Monto: " << monto << endl;
        cout << "Pagada: " << (pagada ? "Si" : "No") << endl;
        cout << "Cliente: " << cliente.getNombre() << endl;
        cout << "Tipo: " << cliente.getTipo() << endl;
        cout << "Antiguedad: " << cliente.getAntiguedad() << endl;
        cout << "------------------------" << endl;
    }
};



int main()
{
    //SECCION D
    Cliente c1("Ana", "frecuente", 3);
    Cliente c2("Luis", "normal", 1);
    Cliente c3("Pedro", "frecuente", 6);

    Factura facturas[5];

    facturas[0] = Factura(1, 500, false, c1);
    facturas[1] = Factura(2, 300, true, c2);
    facturas[2] = Factura(3, 800, false, c3);
    facturas[3] = Factura(4, 200, true, c1);
    facturas[4] = Factura(5, 1000, false, c3);

    int n = 5;

    //Total facturado clientes frecuentes >2 años
    float totalFrecuentes = 0;
    for (int i = 0; i < n; i++)
    {
        if (facturas[i].getCliente().getTipo() == "frecuente" && facturas[i].getCliente().getAntiguedad() > 2)
        {
            totalFrecuentes += facturas[i].getMonto();
        }
    }
    cout << "Total facturado clientes frecuentes >2 anios: " << totalFrecuentes << endl;

    //Contar facturas clientes normales
    int contNormales = 0;
    for (int i = 0; i < n; i++)
    {
        if (facturas[i].getCliente().getTipo() == "normal")
        {
            contNormales++;
        }
    }
    cout << "Cantidad facturas clientes normales: " << contNormales << endl;

    //Factura mayor monto cliente frecuente
    float mayor = 0;
    int posMayor = -1;

    for (int i = 0; i < n; i++)
    {
        if (facturas[i].getCliente().getTipo() == "frecuente")
        {
            if (facturas[i].getMonto() > mayor)
            {
                mayor = facturas[i].getMonto();
                posMayor = i;
            }
        }
    }

    if (posMayor != -1)
    {
        cout << "Factura mayor de cliente frecuente:" << endl;
        facturas[posMayor].mostrar();
    }

    //Promedio clientes >5 años
    float suma = 0;
    int contador = 0;

    for (int i = 0; i < n; i++)
    {
        if (facturas[i].getCliente().getAntiguedad() > 5)
        {
            suma += facturas[i].getMonto();
            contador++;
        }
    }

    if (contador > 0)
        cout << "Promedio clientes >5 anios: " << suma / contador << endl;
    else
        cout << "No hay clientes con mas de 5 anios." << endl;


    //Facturas impagas y total adeudado clientes frecuentes
    int cantidadImpagas = 0;
    float totalAdeudado = 0;

    for (int i = 0; i < n; i++)
    {
        if (!facturas[i].isPagada() && facturas[i].getCliente().getTipo() == "frecuente")
        {
            cantidadImpagas++;
            totalAdeudado += facturas[i].getMonto();
        }
    }
    cout << "Facturas impagas clientes frecuentes: " << cantidadImpagas << endl;
    cout << "Total adeudado clientes frecuentes: " << totalAdeudado << endl;

    return 0;
}

