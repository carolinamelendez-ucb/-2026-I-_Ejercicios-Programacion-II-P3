#pragma once
#include "Docente.h"

class TiempoCompleto : public Docente {
private:
	int antiguedad;
public:
	TiempoCompleto(int ci, string nombre, float salario, int antiguedad)
		: Docente(ci, nombre, salario){
		this->antiguedad = antiguedad;
	}
    float calcularSalario() override {
        float bono = 0;
        if (antiguedad <= 5) {
            bono = 0.05;
        }
        else {
            if (antiguedad <= 10) {
                bono = 0.15;
            }
            else {
                bono = 0.25;
            }
        }
        return salario + salario * bono;
    }
};
