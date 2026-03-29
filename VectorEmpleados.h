#pragma once
#include "Empleado.h"

class VectorEmpleados{
private:
	Empleado** empleados;
	int indice;
	int tamanio;
public:

	VectorEmpleados ( int tamanio)
		: indice (0), tamanio (tamanio)
	{
	this->empleados= new Empleado* [tamanio];
	}
	void registrarEmpleado (Empleado* nuevoEmpleado){
		if(indice < tamanio){
			empleados[indice] = nuevoEmpleado;
			indice++;
		}
	}

	void mostrar (){
		for(int i = 0; i < indice; i++){
			empleados[i]->mostrar ();
		}
	}

	Empleado* verificarCiDuplicado (int ci){
		for(int i = 0; i < indice; i++){
			if(empleados[i]->getCi () == ci){
				return empleados[i];
			}
		}
		return nullptr;
	}

	Empleado* verificarDisponibilidad (){
		for(int i = 0; i < indice; i++){
			if(empleados[i]->getEstado () == true){
				return empleados[i];
			}
		}
		return nullptr;
	}


	void ordenarPorFunciones (){
		for(int i = 0; i < indice; i++){
			for(int j = i + 1; j < indice; j++){
				if(empleados[i]->getCantidadFunciones () > empleados[j]->getCantidadFunciones()){
					Empleado* aux = empleados[i];
					empleados[i] = empleados [j];
					empleados[j] = aux;
				}
			}
			
		}
	}

};