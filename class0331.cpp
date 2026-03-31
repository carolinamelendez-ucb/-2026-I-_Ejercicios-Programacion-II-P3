// class0331.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

//UNA CLASE ABTRACTA SIGNIFICA QUE TODOS SUS METODOS SON METODOS
//OBLIGA  ALAS CLASES HIJAS A QUE IMPLEMENTE SI O SI LOS METODOS QUE SON MARCADOS COMO PUROS, SI NOS LOS PONE MARCA ERROR


class Dispositivo {                                                                                                       
protected:                                                                                                                
    string marca;
    int capacidadMemoeria;
public:                                                                                                                     


    Dispositivo(const string& marca, int capacidadMemoeria)
        : marca(marca), capacidadMemoeria(capacidadMemoeria)
    {
    }

    //este es una forma,ESTE SI LO PUEDO PONER SOLO EN ALGUNOS
    //QUIERE DECIR: este metodo posiblemnete se cambien en clase HIJA 
    virtual void mostrar() {  //añadimmos virtual para que muestre la clase hija su otro mostrar
        cout << "Nombre della marca: " << marca << endl;
        cout << "Capacidad de Memoeria: " << capacidadMemoeria << endl;
    }
    //DE ESTE ESTILO, SI OS I LO PNGO EN TODAS LAS HIJAS
    virtual int calcular() = 0;  //si no se pone , las clases hijas se volveran clases abstractas y no se podra ejecutar
    //solo pongo cuando sobrepongo el metodo en TODAS  las clases hijas.

   // virtual void mostarUsoMemoria() = 0;  //si no ponmgo esto a las hijas, no da, las clases hijas se convierten en ABSTRACTAS  
                                          //por ahora lo comentamos


};

class Celular: public Dispositivo {
private:
    int pixelesCamara;   //Herencia con extension de atributos
public:
    Celular(const string& marca, int capacidadMemoeria, int pixelesCamara )
        : Dispositivo(marca, capacidadMemoeria)
    {
        this->pixelesCamara=100;
    }

    void mostrar() {            //aobre escritura de metodos, ademas los reutilizamos
        Dispositivo::mostrar();
        cout << "Pixeles: " << pixelesCamara << endl;
    }
    int calcular() {
        cout << "CPU del Celular" << endl;
    }

};


class Television : public Dispositivo {
public:
    Television(const string& marca, int capacidadMemoeria)
        : Dispositivo(marca, capacidadMemoeria)
    {
    }
    Television(int capacidadMemoeria)//sobrecragar de contructorewa
        : Dispositivo("Samsumg", capacidadMemoeria) //asignar valor por defecto
    {
    }
    int calcular() {
        cout << "CPU del TV" << endl;
    }
};
int main()
{
    //uhn OBJETO
    //Dispositivo myTv = new Television("sam", 50);

    //aARREGLO DE VECTORES
    Dispositivo** listaDispositivos = new Dispositivo * [100];

    listaDispositivos[1] = new Celular("Xiami", 20, 200);
    listaDispositivos[2] = new Television(50);
    //PARTE DE POLIMORFISMO
    listaDispositivos[1]->mostrar(); //no muestra el atributo añadido porque el vecto al estar con la clase padre solo reconoce lo que esta ahi
                                            //añadir virtual ene l metodo de la clase padre que tiene el mismo nombre. AHORA SI MUESTRA LA SECCION DE PIXELES
}

