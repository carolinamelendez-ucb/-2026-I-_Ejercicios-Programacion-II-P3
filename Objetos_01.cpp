#include <iostream>
#include <string>

/* 
    Atributos -> Caracteristicas 
      (AVION)
    - Motor
    - Capacidad
    - Velocidad
    - Coordenadas
    - Modelo

    Metodos  -> Acciones
    - Despegar 
    - Aterrizar
    - Acelerar
    - Encender Motores
    - Volar
*/
// NOTACION -> Pascal CASE -> MiPrimeraPalabra
// NOTACION -> CAMEL CASE -> miprimeraPalabra
// NOTACION -> snake CASE -> mi_primera_Palabra

//constructor -> es para inicializar todos los atributos 

//stters -> Modificar ; metodos que vana a modificar el valor de los atributos de la clase
using namespace std;
class Bicicleta {
private:

    int velocidad;
    string color;
    string marca;
    string tipo;
public:
    Bicicleta(int velocidadB,string colorB,string tipoB,string marcaB) {
        velocidad = velocidadB;
        color = colorB;
        tipo = tipoB;
        marca = marcaB;

    }
    void mostrar() {
        cout << "Velocidad: " << velocidad << endl;
        cout << "color: " << color << endl;
        cout << "tipo: " << tipo << endl;
        cout << "Marca: " << marca << endl;
    }
    void avanzar() {
        cout << "Bicicleta avanza" << endl;
    }
    void detener() { cout << "Bicicleta se Detiene" << endl; }
    void desmantelar(){}
    void cambiarCaja() {}
    
};

class Alumno {
private:
    string nombre;
    int edad;
    int ci;
public:
    Alumno(string nombreA, int edadA, int ciA) {
        this->nombre = nombreA;
        this->edad = edadA;
        this->ci = ciA;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "EDAD: " << edad << endl;
        cout << "CI: " << ci << endl;
    }
    void setEdad(int nuevaEdad) {
        this->edad = nuevaEdad;
    }
};
int main()
{
    Bicicleta bicicleta1 = Bicicleta(10,"rojo","montanera","trek");
    cout << "Datos Bicicleta 1" << endl;
    bicicleta1.avanzar();
    bicicleta1.detener();
    bicicleta1.mostrar();
    cout << endl;
    Bicicleta bicicleta2 = Bicicleta(40,"negro","ciclismo","trek");
    cout << "Datos Bicicleta 2" << endl;
    bicicleta2.mostrar();
    cout << endl;
    Bicicleta bicicleta3 = Bicicleta(15,"verde","montanera","trek");
    cout << "Datos Bicicleta 3" << endl;
    bicicleta3.mostrar();

    cout << "Mostrar Alumno" << endl;
    Alumno Alumno1 = Alumno("Javier",23,1234);
    Alumno1.mostrar();
    Alumno1.setEdad(20);
    cout << "----------" << endl;
    Alumno1.mostrar();
}
