#pragma one 
#include <iostream>
#include <string>
#include "eventoVector.h"
#include "vectorOrganizador.h"
#include "evento.h"

using namespace std;

class SistemaOrganizadorEventos 
{
    private:

    VectorOrganizador* listaOrganizadores;
    EventoVector* listaEventos;

    public :
    SistemaOrganizadorEventos(int tamOrg, int tamEve)
    {
        this -> listaEventos= new EventoVector(tamEve);
        this->listaOrganizadores= new VectorOrganizador(tamOrg);
    }

    void registrarOrganizador(Organizador* org)
    {
        listaOrganizadores->agregar(org);
    }

    void registrarEvento(Evento* eve)
    {
        listaEventos->agregarEvento(eve);
    }


    void mostrarOrganizadores()
    {
        listaOrganizadores->ordenarPorRank();
        listaOrganizadores->mostrarListaOrganizador();
    }

    void mostrarEventos()
    {
        listaEventos->mostrarListaEventos();
        
    }


};