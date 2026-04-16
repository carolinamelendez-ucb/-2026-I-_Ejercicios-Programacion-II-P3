#pragma once
#include "VectorCursos.h"
#include "VectorDocentes.h"
#include "VectorEstudiantes.h"
#include "MedioTiempo.h"

class UniversidadSistema {
private:
    VectorEstudiantes* est;
    VectorDocentes* doc;
    VectorCursos* cursos;

public:
    UniversidadSistema(int e, int d, int c) {
        est = new VectorEstudiantes(e);
        doc = new VectorDocentes(d);
        cursos = new VectorCursos(c);
    }


    void registrarEstudiante(Estudiante* e) {
        if (!est->buscarPorCi(e->getCi()))
            est->agregar(e);
        else
            cout << "CI duplicado estudiante\n";
    }

    void registrarDocente(Docente* d) {
        if (!doc->buscarPorCi(d->getCi()))
            doc->agregar(d);
        else
            cout << "CI duplicado docente\n";
    }

    void registrarCurso(Curso* c) {
        if (!cursos->buscar(c->getCodigo()))
            cursos->agregar(c);
        else
            cout << "Codigo duplicado curso\n";
    }

    void asignarDocente(string ci, string cod) {
        Docente* d = doc->buscarPorCi(ci);
        Curso* c = cursos->buscar(cod);

        if (!d || !c) {
            cout << "Error en asignacion\n";
            return;
        }

        if (d->aproboEntrevista()) {
            c->asignarDocente(d);

            MedioTiempo* mt = (MedioTiempo*)d;
            if (mt != nullptr) {
                mt->incrementarCurso();
            }
        }
    }

    void inscribir(string ci, string cod) {
        Estudiante* e = est->buscarPorCi(ci);
        Curso* c = cursos->buscar(cod);

        if (!e || !c) {
            cout << "No existe\n";
            return;
        }

        if (!e->getPago()) {
            cout << "No pago matricula\n";
            return;
        }

        if (!c->agregarEstudiante(e)) {
            cout << "Curso lleno\n";
        }
    }

    void mostrarEstudiantes() {
        for (int i = 0; i < est->getIndice(); i++) {
            Estudiante* e = est->get(i);
            cout << e->getNombre()
                << " paga: " << e->calcularPago() << endl;
        }
    }

    void mostrarDocentes() {
        for (int i = 0; i < doc->getIndice(); i++) {
            Docente* d = doc->get(i);
            cout << d->getNombre()
                << " salario: " << d->calcularSalario() << endl;
        }
    }

    void mostrarCursos() {
        for (int i = 0; i < cursos->getIndice(); i++) {
            cursos->get(i)->mostrar();
        }
    }

    void totalRecaudado() {
        float total = 0;
        for (int i = 0; i < est->getIndice(); i++)
            total += est->get(i)->calcularPago();

        cout << "Total recaudado: " << total << endl;
    }

    void estudianteMayorPago() {
        float max = -1;
        Estudiante* mejor = nullptr;

        for (int i = 0; i < est->getIndice(); i++) {
            float pago = est->get(i)->calcularPago();
            if (pago > max) {
                max = pago;
                mejor = est->get(i);
            }
        }

        if (mejor)
            cout << "Mayor paga: " << mejor->getNombre() << endl;
    }

    void cursoMasEconomico() {
        float min = 999999;
        Curso* mejor = nullptr;

        for (int i = 0; i < cursos->getIndice(); i++) {
            float costo = cursos->get(i)->costoCurso();
            if (costo < min) {
                min = costo;
                mejor = cursos->get(i);
            }
        }

        if (mejor)
            cout << "Curso mas economico: " << mejor->getCodigo() << endl;
    }
};