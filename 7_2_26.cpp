#include <iostream>
#include <string>
using namespace std;

//Notacion -> Pascal CASE  -> MiPrimeraPalabra 
//Notación -> Camel CASE -> miPrimeraPalabra
//Notación -> snake CASE -> mi_pirmera_palabra

/*
ELAY ASI SE COLOCA 
*/

/// </summary>
class Bicicleta {
private:

	/// ATRIBUTOS
	int velocidad;
	string color;
	string tipo;
	string marca;
public:

	Bicicleta(int velocidadB, string ColorBici, string TipoBici,string MarcaB) {//aqui adentro añadile datos, sino todo se repite..
		//Aqui pusiste datos para "ASIGNAR" un valor a cada 1.
		velocidad = velocidadB;
		color = ColorBici;
		tipo = TipoBici;
		marca = MarcaB;
	}
	void mostrar() {
		cout<<" velocidad :"<<velocidad<< endl;
		cout<<" color :"<<color<<endl;
		cout<<" tipo :"<< tipo<<endl;
		cout<<" marca:"<< marca<<endl;

}

	///Metodos 
	void avanzar(){
		cout << "Bicicleta avanza..." << endl;
	}
	void detener() {
		cout << "Bicicleta se detiene..." << endl;
	}
	void Desmantelar(){}
	void cambiarCaja(){}
	void ejercitar(){}

};
// TODO ESTO ES TU CONSTRUCTOR
class Alumno {
	string Nombre;
	int edad;
	int ci;
public: 
	Alumno(string NombreA, int edadA, int ciA) {
		Nombre = NombreA; //this-> (esto sirve para identificar cual es un atributo)
		edad = edadA;
		ci = ciA;
	}
	void mostrarALUM() {
		cout << "Nombre:" << Nombre << endl;
		cout << "Edad:" << edad << endl;
		cout << "Ci:" << ci << endl;
	}
};
int main(){
	/*
	Bicicleta bicicleta1 = Bicicleta();
	bicicleta1.avanzar();
	bicicleta1.avanzar();
	bicicleta1.avanzar();
	bicicleta1.avanzar();
	bicicleta1.detener();
	*/
	//Aqui le declaras los datos que buscas 
	Bicicleta bici(12, "verde", "dep", "trek");
	Bicicleta bici2(100, "morado", "electrica", "BH");
	bici.mostrar();//OJO ASI SE LLAMA 

	//EJR 2:

	Alumno Alm1("FABIAN", 19, 13);
	Alm1.mostrarALUM();

}

