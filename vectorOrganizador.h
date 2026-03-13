#pragma once

#include <iostream>
#include <string>

#include "organizador.h"

using namespace std;

class VectorOrganizador
{

    private:

    int tamanio;
    int indice;
    Organizador** organizadores;

    public:

    VectorOrganizador(int tamanio)
    {
        this ->indice  = 0;
        this ->tamanio = tamanio;
        this->organizadores = new Organizador*[tamanio];
    }

    void agregar(Organizador* nuevoOrganizador)
    {
        this->organizadores[indice]= nuevoOrganizador;
        indice++;
    }

   

    Organizador * buscarOrganizadorDisponible()
    {
        for (int i = 0 ; i < indice ; i++)
        {
            if(organizadores[i]->disponible())
            {
                return organizadores[i];
            }
        }
        return nullptr;
    }

    void ordenarPorRank()
    {
        for(int i = 0 ; i < indice - 1 ; i++)
        {
            for(int j = 0 ; j < indice - i - 1 ; j++ )
            {
                if(organizadores[j]->getRank()< organizadores[j+1]->getRank())
                {
                    Organizador* temp = organizadores[j];
                    organizadores[j]= organizadores[j+1];
                    organizadores[j+1] = temp;
                }
            }
        }
    }

    void mostrarListaOrganizador()
    {
        for (int i = 0 ; i < indice ; i++)
        {
            organizadores[i]->mostrarOrganizador();
            cout << endl;
            
        }
    }



};