#include <iostream>
#include <string>
using namespace std;

#include "vectorOrganizador.h"
#include "organizador.h"
#include "InvitadoVector.h"

class Evento
{
    private:
    string nombreEvento;
    int idEvento;
    int maxInvitados;
    VectorDeInvitados* listaInvitados;
    Organizador* organizador;

    public:

    Evento(string nombreEvento , int idEvento, int maxInvitados)
    {
        this ->nombreEvento = nombreEvento;
        this ->idEvento = idEvento;
        this-> maxInvitados = maxInvitados;
        this ->organizador = nullptr;
        this ->listaInvitados = new VectorDeInvitados (maxInvitados);
    }

    

    void asignarOrganizador(Invitado * nuevoInvitado)
    {
        listaInvitados->agregar(nuevoInvitado);
    }

    void mostrar()
    {
        cout << "Evento : " << nombreEvento << endl;
        cout << "Id Evento : " << idEvento << endl;
        
        if(organizador != nullptr)
        {
            cout << "Organizador : " << endl;
            organizador->mostrarOrganizador();
        }

        cout<< "Lista de invitados" << endl;
        listaInvitados->imprimirInvitados();
    }

    int getIdEvento()
    {
        return idEvento;
    }

    void finalizar()
    {
        if(organizador != nullptr)
        {
            organizador->liberar();
        }
    }
};