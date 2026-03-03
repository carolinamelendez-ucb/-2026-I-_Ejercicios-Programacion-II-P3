#include <iostream>
#include <string>
using namespace std;

/*
Vamos a ver cuando se usan los punteros:
OK, acaba de crear un nuevo archivo dentro de este, "ve para archivo encabezado"







HOY VEREMOS VECTORES DE OBJETOS:
1 vector con sus casillas : 
    -tamaño/limite  = cant. max. de elementos q puede almacenar (ejm: TAM=5)
    - indice = la posicion (0 hasta tam-1)
    - cantidad = lo q colocamos nl vector (cant=3)



















*/


// esto lo haras en otro archivo q mencione a priori
class Alumno {
private:
    string nombre;
    int edad;
public:
    Alumno(string nom, int ed) {
        this->nombre = nom;
        this->edad = ed;
    }

    void mostrar() {
        cout << "Nombrar:" << nombre << endl;
        cout << "Edad:" << edad << endl;
    }
    void setNombre(string nuevoNombre) {
        this->nombre = nuevoNombre;
    }
    int GetEdad() {
        return edad;
    }
};
// Aqui lo colocas al nuevo arch
//Vector de alumnos
class AlumnosVector {
private:
    int cantidad;
    int tamanio;
    Alumno** alumnos;   //--> estos 2 '*' es para cuando se quiera declarar un vector/array de objetos con punteros
public:
    AlumnosVector(int tam) {
        this->alumnos = new Alumno*[tam];
        this->cantidad = 0;
        this->tamanio = tam;
    }
    void agregar(Alumno* nuevoAlumno) {
        alumnos[cantidad] = nuevoAlumno;
        cantidad++;
    }
    void mostrar() {
        for (int i = 0;i < cantidad;i++) {
            alumnos[i]->mostrar();
        }
    }

    void MostrarAlumnoMayorEdad() {
        int maxEdad = 0;
        int maxInd = 0;
        for (int i = 0;i < cantidad;i++) {
            if (alumnos[i]->GetEdad() > maxEdad) {
                maxEdad = alumnos[i]->GetEdad();
                maxInd = i;
            }
        }
        cout << "El mayor es:" << endl;
        alumnos[maxInd]->mostrar();
    }

};

//-----------------------------------------------------------------------

class Pasajero {
private:
    string nombre;
    int ci;
    int numeroAsiento;
public:
    Pasajero(string nom, int DNi, int numAs) {
        this->ci = DNi;
        this->nombre = nom;
        this->numeroAsiento = 0;
    }
    void Mostrar() {
        cout << "Nombre:" << nombre << endl;
        cout << "CI:" << ci << endl;
        cout << "Num.Asiento:" << numeroAsiento << endl;
    }
    void setAgregarAsiento(int NvoNum){
        numeroAsiento = NvoNum;
    }
    int getNumAsiento() {
        return numeroAsiento;
    }
    int getCi() {
        return ci;
    }
};




class PasajeroVector {
private:
    int cantidad;
    int tamanio;
    Pasajero **usuario;
public:
    PasajeroVector(int tam){
        this->cantidad = 0;
        this->tamanio = tam;
        this-> new usuario* [tam];
    }
    void agregar(Pasajero* nuevoPasajero) {
        usuario[cantidad] = nuevoPasajero;
        cantidad++;
    }
    void MostrarVec() {
        for (int i = 0;i < cantidad;i++) {
            usuario[i]->Mostrar();
        }
    }

    //No tienen asiento;
    //asientos impares
    //mostrar a un pasajero por su ci;
    void MostrarPasajerosSinAsiento() {

        for (int i = 0;i < cantidad;i++) {
            if(usuario[i]->getNumAsiento()=0) {
                usuario[i]->Mostrar();
            }
        }
    }

    void AsientosImpares(){
        for (int i = 0;i < cantidad;i++) {
            if (usuario[i]->getNumAsiento % 2 != 0) {
                usuario[i]->Mostrar();
            }
        }
    }

    void BuscarCi(int BuscarCi){
        for (int i = 0;i < cantidad;i++) {
            if(usuario[i]->getCi=BuscarCi) {
                usuario[i]->Mostrar();
            }
        }
    }


};

































void editarNombre(Alumno alum) {
    alum.setNombre("Maria");
}


void editarNombrConPuntero(Alumno alum) {
    alum.setNombre("Daniel");
}



int main() {

    //objeto sin punteros
    cout << "-------------------------------------------SIN PUNTERO" << endl;
    Alumno alumnoAna = Alumno("Ana", 20);
    cout << "Mostrar Antes:" << endl;
    alumnoAna.mostrar();
    cout << "Mostrar Despues:" << endl;
    editarNombre(alumnoAna);
    alumnoAna.mostrar();

    //Objeto con puntero
    cout << "--------------------------------------------CON PUNTERO" << endl;
    Alumno* alumnnoPedri = new Alumno("Pedri", 19);
    cout << "Mostrar Antes:" << endl;
    alumnnoPedri->mostrar();
    cout << "Mostrar Despues:" << endl;
    editarNombre(alumnnoPedri);
    alumnnoPedri->mostrar();




    /// ----Vector de Objetos-----:

    //Un puntero de objetos
    
   
    AlumnosVector misAlumnos = AlumnosVector(50);
    misAlumnos.agregar(new Alumno("Marcos", 20));
    Alumno* Keithy = new Alumno("Keithy", 30);
    misAlumnos.agregar(Keithy);
    misAlumnos.mostrar();

    // Alumnos mayor edad;
    misAlumnos.






















}

