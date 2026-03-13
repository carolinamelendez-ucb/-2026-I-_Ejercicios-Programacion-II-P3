#pragma once 
#include <iostream>
#include <string>

using namespace std;


class Invitado
{   
    private:
    string nombreInvitado;
    string telefonoInvitado;

    public:

    Invitado(string nombreInvitado, string telefonoInvitado)
    {
        this->nombreInvitado = nombreInvitado;
        this->telefonoInvitado= telefonoInvitado;
    }

    

    void mostrar()
    {
        cout << " Nombre del invitado : " << nombreInvitado << endl;
        cout << " Telefono del invitado : " << telefonoInvitado << endl; 
    }

};