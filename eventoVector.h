#pragma once 
#include <iostream>
#include "evento.h"
using namespace std;
class EventoVector
{
    Evento** eventos;
    int tamanio;
    int indice;


    public:

    EventoVector(int tamanio)
    {
        this -> tamanio = tamanio;
        this->indice = 0;
        this ->eventos = new Evento * [tamanio];
    }

    void agregarEvento(Evento* nuevoEvento)
    {
        this ->eventos[indice] = nuevoEvento;
        indice++;
    }


    Evento* buscarEvento(int id)
    {
        for (int i = 0 ; i < indice ; i++)
        {
           if(eventos[i]->getIdEvento()==id)
           {
            return eventos[i];
           }
        }
        return nullptr;
    }

    void mostrarListaEventos()
    {
        for (int i = 0 ; i < indice ; i++)
        {
            eventos[i]->mostrar();
            cout << endl;
        }
    }

    

};