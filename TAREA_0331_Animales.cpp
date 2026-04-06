// TAREA_0331_Animales.cpp 

/* Implemente una clase base Animal con un método virtual hacerSonido(). A partir de esta, cree clases derivadas como 
   Perro y Gato, las cuales deben sobrescribir dicho método con comportamientos específicos (por ejemplo, 
   el Perro puede imprimir “Guau guau” y el Gato “Miau miau”).
   En la función main(), utilice un arreglo de punteros de tipo Animal para almacenar objetos 
   las clases derivadas y demuestre el uso de polimorfismo invocando el método hacerSonido() para cada elemento.
 */

#include <iostream>
#include "Perro.h"
#include "Gato.h"

using namespace std;


int main()
{
    int n = 3;

    //Arreglo de punteros 
    Animal** animales = new Animal * [n];

    animales[0] = new Perro("Firulais", "Pastor Aleman", 3, "Largo");
    animales[1] = new Gato("Nieves","Siames",2);
    animales[2] = new Perro("Rocky", "Bulldog", 5, "Corto");
    
    //Polimorfismo
    for (int i = 0; i < n; i++)
    {
        animales[i]->mostrar();
        animales[i]->hacerSonido();

        /*Perro* p = dynamic_cast<Perro*>(animales[i]); //Es de buena practica?,podria llamar a la funcion de otra forma??
        if (p != nullptr) 
        {
            p->moverCola();
        }

        Gato* g = dynamic_cast<Gato*>(animales[i]);
        if (g != nullptr)
        {
            g->ronronear();
        } */

        cout << "-------------------" << endl;
    }



    //Liberar memoria
    for (int i = 0; i < n; i++)
    {
        delete animales[i]; //llama al destructor correcto (por virtual)
    }
    delete[] animales;

    return 0;
}

