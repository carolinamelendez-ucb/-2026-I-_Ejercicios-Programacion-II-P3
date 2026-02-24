#include <iostream>
#include <string>
using namespace std;

/*

Hoy veremos punteros (teoria):
1ro:
matrices = memeoria de la computadora (Direccion de memoria) 

Imagina unos cuadritos en una posicion  =    jcndj781378 -> y ahi guardas un dato, ejm: "y=10" o "10"


"ESE ESPACIO TENDRA EL VALOR DE 10"

2do: ¿? pero yo quiero cambiar la direccion de memoria en otra variable ("topo")

usas un *: 
esto pasa por dentro

y=10;
 &y->xxx01

 *yPtr  =   &y
 &yPtr  ->  xxx02

 3ro:

 lo a priori es la logica por detras


 
 
 
 */



// Paso por valor --> Copia la variable en una nuevo pos de memoria
// Paso por referencia  --> Se envia la pos de memoria para editar su valor DIRECTO



class Alumno {
private: 
    string nombre;
    int ci;
public:
    Alumno(string nom, int num) {
        this->nombre = nom;
        this->ci = num;
    }
};


class Autor {
private:
    string nombre;
    string Nacionalidad;
    int CantLibrosPublicados;
public:
    Autor(string nom, string Nacio,int num) {
        this->nombre = nom;
        this->Nacionalidad = Nacio;
        this->CantLibrosPublicados=num;
    }

    string getNombre() {
        return nombre;
    }

    void setNombre(string NvoNombre) {
        this->nombre = NvoNombre;
    }

};





// Antes
class Libro {
private:
    string titulo;
    int precio;
    Autor *autor;  //--->NO PODES PONERLE UN * AQUI, TE DARA UN ERROR
public:
    Libro(string tit, int bs, Autor *aut) { //---> AQUI TAMBIEN TENES Q PONERLE UN *
        this->titulo = tit;
        this->precio = bs;
        this->autor = aut;
    }


};


// EJR : CASA - PROPIETARIO
class Propietario {
private:
    string Nombre;
    int DNI;
    int EDAD;
public:
    Propietario(string nom, int dni, int ed) {
        this->Nombre = nom;
        this->EDAD = ed;
        this->DNI = dni;
    }
    int getEdad() {
        return EDAD;
    }
    string getNombre() {
        return Nombre;
    }
    int getDNI() {
        return DNI;
    }
};


class Casa {
private:
    string Direccion;
    int precio;
    Propietario* duenio;
public:
    Casa(string direc, int bs, Propietario* admin) {
        this->Direccion = direc;
        this->precio = bs;
        this->duenio = admin;
    }
    void setPrecio(int NvoPrecio) {
        this->precio = NvoPrecio;
    }
    int getPrecio() {
        return precio;
    }
    string getDireccion() {
        return Direccion;
    }
};

















void duplicar(int &valor) { // Con el "&" dices q te pase la direccion de memoria del contenido (Te da el original)
    valor = valor*2;
}






int main() {
    //ejm:
    int y = 10;
    /**/
      //1r0  
    cout << "Direccion de memoria: " << &y << endl;  //-> AQUI NOS MUESTRA LA DIRECCION de memoria, gracias al "&"
    cout << "Valor: " << y << endl;                     // -> AQUI NOS MUESTRA EL VALOR DE AHI

    // duplicar(y);
     //cout << "Valor de Y:" << y << endl;
     // OJO: no te sale 20, te sale 10 normal, pq? pq se paso una copia del valor    (era trucho)
    cout << "---------------------------------------------------" << endl;
    //2do:  
      //("topo")(OJO-> esto será una ¿? de exam)
    int* yPtr = &y; //---> este * sirve para guardar tu espacio en otra variable ()
    cout << "Valor de yPtr:" << yPtr << endl; // te la direccion de memoria de "y"
    cout << "Valor de *yPtr:" << *yPtr << endl; // te da el valor = 10
    cout << "Valor de &yPtr:" << &yPtr << endl; //Dir. de memoria

    // 3RO
    // 
    // 
    // Tarea1: averiguar  ¿? es la diferencia deinplmetner obj con/sin punteros
    //     ventajas/desventajas...
        // SIN PUNTEROs:
    Alumno Fabian = Alumno("Marco", 123);


    // CON PUNTEROs:
    Alumno* Alejandra = new Alumno("Alejandra", 456);

    // ojo: nl exam vos usaras criterios para ver "en donde se coloca y no los punteros"

    //4to:
    Autor autorIvan =  Autor("Ivan", "Chileno", 25);
    Autor* autorIvanPtr = new Libro("Ivan", "Chileno", 25); //--->TIENE Q HABER UN * Y "new"  (REVISA ESTOOOOOOOOOOOOO)

    Libro* libro1 = new Libro("Baldor", 75, autorIvanPtr);

    
    //Obj si PUNTERO. usas "." para acceder a los metodos
    autorIvan.getNombre()//---> asi



        // "" con PUNTERO. usas  "->"  ""        ""
        autorIvanPtr->                                                      /// AQUI TAMBIEN(revisa)



    Propietario* p1 =  new Propietario("Stefanny", 4, 20);                  /// AQUI TAMBIEN(revisa)
    Propietario p2 = Propietario("Benito", 3, 30);

    Casa* VentaPtr = new Casa("Av.2da Circunvalacion", 20000, p1);




}
