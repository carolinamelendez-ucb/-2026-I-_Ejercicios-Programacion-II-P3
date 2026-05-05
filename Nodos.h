#include <iostream>
#include <string>
using namespace std;
template <class T>
class node
{
private:
    T date;
    node<T>* siguiente;
public:
    node(T dato)
    {
        this->dato = dato;
        this siguiente = nullptr;
    }

    T getDato()
    {
        return dato;
    }
    node<T>* getSiguiente()
    {
        return siguiente;
    }
    void setSiguiente(node<T>* Nsiguiente)
    {
        this->siguiente = Nsiguiente;
    }
   
    node(string nuevoValor);
    void setValor(string nuevoValor);
    string getValor();
    void setSiguiente(node* nuevoSiguiente);
    node* getSiguiente();
    void agregarSiguiente(string nuevoValor);
};
