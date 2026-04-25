#include <iostream>
#include <string>
#include "ArrayGenerico.h"
#include "Cliente.h"
int main()
{
    ArrayGenerico<Cliente>* listaClientes = new ArrayGenerico<Cliente>(4);
    listaClientes->agergar(new Cliente("PEPE", 1234));
}
