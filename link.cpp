
#include <iostream>
#include <string>  
using namespace std;


template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T d) {
        dato = d;
        siguiente = nullptr;
    }
};


template <typename T>
class LinkedList {
private:
    Nodo<T>* cabeza;

public:
    LinkedList() {
        cabeza = nullptr;
    }

    void agregar(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);

        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
    }
};




int main() {

    
}