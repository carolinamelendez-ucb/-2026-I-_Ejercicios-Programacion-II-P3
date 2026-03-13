#pragma once
#include <string>
#include <iostream>

using namespace std;

class Organizador
{
    private:
    string nombre;
    int id;
    int rank;
    bool estaDisponible;

    public:
    Organizador(string nombre)
    {
        this ->nombre = nombre;
        this ->id = rand();
        this ->rank = 0;
        this ->estaDisponible = true;
    }

    
    void ocupar()
    {
        estaDisponible = false;
    }

    void liberar()
    {
        estaDisponible = true;
        rank++;
    }

    int getRank()
    {
        return rank;
    }

    bool disponible()
    {
        return estaDisponible;
    }

    void mostrarOrganizador()
    {
        cout << " El nombre del organizador es : " << nombre << endl;
        cout << " Id del organizador es : " << id << endl;
        cout << " Su rank es : " << rank << endl;
    }


};