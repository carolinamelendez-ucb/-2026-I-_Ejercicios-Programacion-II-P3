#pragma once
#include <iostream>
#include <string>
using namespace std;

class Empleado{
private:
	string nombre;
	int ci;
	int cantidadFunciones;
	bool estado; //true = disponible
public: 
	
	Empleado (const string& nombre, int ci)
		: nombre (nombre), ci (ci), cantidadFunciones (0), estado (true)
	{
	}

	void mostrar ()  {
		cout << "Nombre: " << nombre << endl;
		cout << "CI: " << ci << endl;
		cout << "Cantidad de funciones: " << cantidadFunciones << endl;
		cout << "Estado: " << endl;
		if(estado == true){
			 cout<< "Disponible"<<endl;
		}
		else{
			cout<<"Ocupado"<<endl;
		}
	}  

	string getNombre (){
		return nombre;
	}

	int getCi (){
		return ci;
	}

	int getCantidadFunciones (){
		return cantidadFunciones;
	}

	bool getEstado (){
		return estado;
	}

	void actualizarEstado (){
		if(estado == true){
			estado = false;
		}
		else{
			estado == true;
			cantidadFunciones++;
		}
	}
};