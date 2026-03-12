#include <iostream>
#include <string>
using namespace std;


class Organizador {
private:
    int id;
    string nombre;
    int rank;
    bool disponible;
public:
    Organizador(int ID,string nom,int rk,bool dis) {
        this->id = ID;
        this->nombre = nom;
        this->rank = rk;
        this->disponible = dis;
    }
    void Mostrar_Organizador() {
        cout << "ID:"<<id<<endl;
        cout << "Nombre:" << nombre << endl;
        cout << "Rank:" << rank << endl;
        cout << "Disponible:" << disponible << endl;
    }

    string getOrganizador() {
        return nombre;
    }
    int getRank() {
        return rank;
    }

};


class Invitado{
private:
    string nombre;
    int telefono;
public:
    Invitado(string nom,int telf){
        this->nombre = nom;
        this->telefono = telf;
    }
    void Mostrar_Invitado() {
        cout << "Nombre:" << nombre << endl;
        cout << "Telefono:" << telefono << endl;
    }
    


};

class Evento{
private:
    int id;
    string nombre_Evento;
    int max_Invitados;
    Invitado** lista_Invitados;
    int numInvitados;
    string fechaFin;
    Organizador* organizadorAsignado;
public:
    Evento(string nom,int MaxInv,Organizador* org){
        this->nombre_Evento = nom;
        this->id = 0;
        this->max_Invitados = MaxInv;
        this->numInvitados = 0;
        this->fechaFin = "";
        this->lista_Invitados = new Invitado * [numInvitados];
    }
    void mostrarEvento(){
        cout << "ID:" << endl;
        cout << "Nombre:" << endl;
        cout << "Invitados:"<<numInvitados << endl;
        cout << "Organizador:"<<organizadorAsignado->getOrganizador() << endl;
        cout << "Rank del Organizador: "<<organizadorAsignado->getRank() << endl;
    }
    
    /*
    void Orden_Por_Rank() {
        int intercambio;
        for (int i = 0;i<numInvitados-1;i++) {
            for (int j = 0;j<numInvitados-1-i;j++) {
                if (organizadorAsignado->getRank()>organizadorAsignado->getRank()) {
                    intercambio = organizadorAsignado->getRank();
                    organizadorAsignado->getRank() = organizadorAsignado->getRank();
                    organizadorAsignado->getRank() = intercambio;
                }

            }
        }
    }
    */


    ~Evento() {
        for (int i = 0;i < numInvitados;i++) {
            delete lista_Invitados[i];
        }
    }

};


int main(){
    
   // Organizador o1=Organizador(4, 'Pablo', 1);




}

