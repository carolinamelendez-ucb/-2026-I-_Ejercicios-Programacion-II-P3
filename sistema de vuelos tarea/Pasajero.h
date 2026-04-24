#pragma once
#include <iostream>
#include <string>

using namespace std;

class Asiento;
class Vuelo;

class Pasajero {
private:
    string ci;
    string nombre;
    string apellido;
    Asiento* asientoAsignado;
    Vuelo* vueloAsignado;

public:
    Pasajero() : ci(""), nombre(""), apellido(""), asientoAsignado(nullptr), vueloAsignado(nullptr) {
    }

    Pasajero(string _ci, string _nombre, string _apellido)
        : ci(_ci), nombre(_nombre), apellido(_apellido),
        asientoAsignado(nullptr), vueloAsignado(nullptr) {
    }

    string obtenerCI() const { 
        return ci; 
    }

    string obtenerNombre() const { 
        return nombre; 
    }

    string obtenerApellido() const { 
        return apellido; 
    }

    Asiento* obtenerAsiento() const { 
        return asientoAsignado; 
    }

    Vuelo* obtenerVuelo() const { 
        return vueloAsignado; 
    }

    bool tieneAsiento() const { 
        return asientoAsignado != nullptr; 
    }

    void asignarAsiento(Asiento* asiento) { 
        asientoAsignado = asiento; 
    }

    void asignarVuelo(Vuelo* vuelo) { 
        vueloAsignado = vuelo; 
    }

    string obtenerNombreCompleto() const {
        return nombre + " " + apellido;
    }

    string obtenerCodigoAsiento() const {
        if (asientoAsignado != nullptr) {
            return asientoAsignado->obtenerCodigo();
        }
        return "Sin asiento";
    }
};
