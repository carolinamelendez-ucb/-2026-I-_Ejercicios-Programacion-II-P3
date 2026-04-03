#include <iostream>
#include <string>
#include "Empresa.h"
#include "EmpleadoPorHoras.h"
#include "EmpleadoTiempoCompleto.h"
using namespace std;

int main(){
    
    Empresa emprecita = Empresa(5);

    emprecita.registrarEmpleado(new EmpleadoTiempoCompleto(2,"Samuel",450,8));
    emprecita.registrarEmpleado(new EmpleadoPorHoras(3, "Jorge", 100));

    emprecita.mostrar();

    emprecita.mostrarSalario();


}


