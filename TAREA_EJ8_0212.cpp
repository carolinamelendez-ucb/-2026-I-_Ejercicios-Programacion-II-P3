// TAREA_EJ8_0212.cpp
//18/02/26
/* Ejercicio 8. Relación Pedido – Cliente

- En el main(), cree un arreglo de pedidos
- Implemente un método que muestre cuántos pedidos pueden confirmarse, es decir, aquellos cuyo cliente 
  esté habilitado y tenga saldo suficiente.
- Implemente un método que recorra el arreglo y calcule el importe total de los pedidos confirmados.
- Implemente un método que recorra el arreglo y muestre cuántos pedidos fueron rechazados por falta de saldo.
- Implemente un método que recorra el arreglo y muestre el pedido de mayor importe.
- Implemente un método que recorra el arreglo y muestre el nombre del cliente con el pedido más caro.  */

#include <iostream>
#include <string>
using namespace std;

class Cliente
{
private:
    string nombre;
    bool habilitado;
    float saldo;

public:
    Cliente()
    {
        nombre = "";
        habilitado = false;
        saldo = 0;
    }

    Cliente(string nombre, bool habilitado, float saldo)
    {
        this->nombre = nombre;
        this->habilitado = habilitado;
        this->saldo = saldo;
    }

    string getNombre()
    {
        return nombre;
    }

    bool isHabilitado()
    {
        return habilitado;
    }

    float getSaldo()
    {
        return saldo;
    }
};

class Pedido
{
private:
    int numero;
    float importe;
    Cliente cliente;

public:
    Pedido()
    {
        numero = 0;
        importe = 0;
        cliente = Cliente();
    }

    Pedido(int numero, float importe, Cliente cliente)
    {
        this->numero = numero;
        this->importe = importe;
        this->cliente = cliente;
    }

    int getNumero()
    {
        return numero;
    }

    float getImporte()
    {
        return importe;
    }

    Cliente getCliente()
    {
        return cliente;
    }

    bool puedeConfirmarse()
    {
        return cliente.isHabilitado() && cliente.getSaldo() >= importe;
    }

    void mostrar()
    {
        cout << "Pedido : " << numero << endl;
        cout << "Importe: " << importe << endl;
        cout << "Cliente: " << cliente.getNombre() << endl;
        cout << "---------------------" << endl;
    }
};

int main()
{
    Cliente c1("Ana", true, 1000);
    Cliente c2("Luis", true, 200);
    Cliente c3("Pedro", false, 1500);

    Pedido pedidos[5];

    pedidos[0] = Pedido(1, 500, c1);
    pedidos[1] = Pedido(2, 300, c2);
    pedidos[2] = Pedido(3, 800, c1);
    pedidos[3] = Pedido(4, 400, c3);
    pedidos[4] = Pedido(5, 150, c2);

    int n = 5;

    // Cuantos pedidos pueden confirmarse
    int confirmados = 0;

    for (int i = 0; i < n; i++)
    {
        if (pedidos[i].puedeConfirmarse())
            confirmados++;
    }
    cout << "Pedidos que pueden confirmarse: " << confirmados << endl;

    //Importe total de pedidos confirmados
    float totalConfirmados = 0;

    for (int i = 0; i < n; i++)
    {
        if (pedidos[i].puedeConfirmarse())
            totalConfirmados += pedidos[i].getImporte();
    }
    cout << "Total importe pedidos confirmados: " << totalConfirmados << endl;

    //Pedidos rechazados por falta de saldo
    int rechazadosSaldo = 0;

    for (int i = 0; i < n; i++)
    {
        if (pedidos[i].getCliente().isHabilitado() && pedidos[i].getCliente().getSaldo() < pedidos[i].getImporte())
        {
            rechazadosSaldo++;
        }
    }
    cout << "Pedidos rechazados por falta de saldo: " << rechazadosSaldo << endl;

    // Pedido de mayor importe
    float mayor = 0;
    int posMayor = -1;

    for (int i = 0; i < n; i++)
    {
        if (pedidos[i].getImporte() > mayor)
        {
            mayor = pedidos[i].getImporte();
            posMayor = i;
        }
    }

    if (posMayor != -1)
    {
        cout << "Pedido de mayor importe:" << endl;
        pedidos[posMayor].mostrar();
    }

    //Nombre del cliente con el pedido mas caro
    if (posMayor != -1)
    {
        cout << "Cliente con el pedido mas caro: " << pedidos[posMayor].getCliente().getNombre() << endl;
    }
    
}

