#include <iostream>
#include <string>
using namespace std;

/*
En la clase anterior 
vimos: 
-Sobrecarga de constructores
-Getters y setters
// Tambien esta hablando de como "const int MAXpeso=10 ": es algo ya definido

Hoy veremos Ejrs con Array(vectores) con objetos.(tenes una prueba el 21)
*/

/* Clase como objeto de atributo*/

//EJM:
class Profesor {
    string NomPrf;
    int AniosExpereriencia;
    string Asignatura;
};

class Alumno {
    int edad;
    string NomAlm;
    Profesor profe;
};


//ejm2:
/*
const int MayorEdad = 18;

class Propietario {
private:
    string NombreP;
    int dni;
    int edad;
public:
    //Propietario (){}
    Propietario(string nomP,int Dnip,int edadp);
    this->NombreP = nomP;
    this->dni = Dnip;
    this->edad = edadp;

    int GetEdad() {
        return;
    }
};

class Casa {
private:
    string Direccion;

   
public:

};
*/
// EJRCICIO EN CLASE

class Autor{
private:
    string NomArt;
    string Nacionalidad;
    int CantidadDeLibrosPublicados;
public:
    Autor(string nomA,string Nld,int cantL){
        this->NomArt = nomA;
        this->Nacionalidad = Nld;
        this->CantidadDeLibrosPublicados = cantL;
    }
    void MostrarAutor() {
        cout << "Nombre: " <<NomArt<< endl;
        cout << "Nacionalidad: " << Nacionalidad << endl;
        cout << "Cantidad De libros publicado: " << CantidadDeLibrosPublicados << endl;
    }

};

class Libro {
private:
    string Titulo;
    int precio;
    // Autor Genero;
public:
    Libro(string tutuloL, int precioL) {
        this->Titulo = tutuloL;
        this->precio = precioL;
    }
    void MostrarLibro() {
        cout << "Titulo: " << Titulo << endl;
        cout << "Precio:" << precio << endl;
    }
    bool EsBestSeller( ) {
        
    }
};






int main(){
    cout<<"Hello World!";
}

