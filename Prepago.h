#pragma once
#include "Estudiante.h"

class Prepago : public Estudiante {
public:
    Prepago(string ci, string nombre)
        : Estudiante(ci, nombre, 2000) {
    }
};
