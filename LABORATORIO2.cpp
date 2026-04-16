#include "UniversidadSistema.h"
#include "Prepago.h"
#include "Postgrado.h"
#include "TiempoCompleto.h"
#include "MedioTiempo.h"

int main() {

    UniversidadSistema uni(100, 50, 20);

    Estudiante* e1 = new Prepago("1", "Carlos");
    Estudiante* e2 = new Postgrado("2", "Ana", 3000);

    e1->pagar();
    e2->pagar();

    uni.registrarEstudiante(e1);
    uni.registrarEstudiante(e2);

    uni.registrarDocente(new TiempoCompleto("10", "Luis", 5000, 8));
    uni.registrarDocente(new MedioTiempo("20", "Maria", 3000));

    uni.registrarCurso(new Curso("A1", 2));

    uni.asignarDocente("20", "A1");

    uni.inscribir("1", "A1");
    uni.inscribir("2", "A1");

    uni.mostrarEstudiantes();
    uni.mostrarDocentes();
    uni.mostrarCursos();
    uni.totalRecaudado();
    uni.estudianteMayorPago();
    uni.cursoMasEconomico();

    return 0;
}