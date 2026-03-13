#pragma once 
#include <string>
#include <iostream>
#include "INVITADO.h"

using namespace std;

class VectorDeInvitados
{
    private:
    Invitado** invitados;
    int tamanio; 
    int indice;

    public:

    VectorDeInvitados(int tamanio)
    {
        this-> tamanio = tamanio;
        this ->invitados = new Invitado*[tamanio];
        this->indice = 0;
    }

    void agregar(Invitado* nuevoInvitado)
    {
        this ->invitados[indice]= nuevoInvitado;
        indice++;
    }
    
    void imprimirInvitados()
    {
        for (int i = 0 ; i < indice ; i ++)
        {
            invitados[i]->mostrar();
        }
    }

};