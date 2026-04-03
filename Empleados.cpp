#include "Empresa.h"
#include "EmpleadoTiempoCompleto.h"
#include "EmpleadoPorHoras.h"
#include "ProyectoInterno.h"
#include "ProyectoExterno.h"

int main() {

    Empresa empresa(10, 10);

   
    empresa.agregarEmpleado(new EmpleadoTiempoCompleto("123", "Juan Perez", 3000));
    empresa.agregarEmpleado(new EmpleadoPorHoras("456", "Maria Lopez", 40, 50));

    
    empresa.agregarProyecto(new ProyectoInterno("P1", "Sistema Interno", 5000));
    empresa.agregarProyecto(new ProyectoExterno("P2", "App Cliente", 100, 60));

    empresa.mostrarTodo();
    empresa.mostrarTotalSalarios();
    empresa.mostrarProyectoMayorCosto();

    return 0;
}