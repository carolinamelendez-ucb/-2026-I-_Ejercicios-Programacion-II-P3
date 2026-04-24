#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class VueloNoEncontradoException : public exception {
private:
    string mensaje;

public:
    VueloNoEncontradoException() {
        mensaje = "[VueloNoEncontradoException] El vuelo no existe en el sistema.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};

class PasajeroNoEncontradoException : public exception {
private:
    string mensaje;

public:
    PasajeroNoEncontradoException() {
        mensaje = "[PasajeroNoEncontradoException] El pasajero no existe en el sistema.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};

class AsientoNoExisteException : public exception {
private:
    string mensaje;

public:
    AsientoNoExisteException() {
        mensaje = "[AsientoNoExisteException] El asiento no existe en este vuelo.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};

class AsientoNoDisponibleException : public exception {
private:
    string mensaje;

public:
    AsientoNoDisponibleException() {
        mensaje = "[AsientoNoDisponibleException] El asiento no esta disponible.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};

class CapacidadMaximaException : public exception {
private:
    string mensaje;

public:
    CapacidadMaximaException() {
        mensaje = "[CapacidadMaximaException] Se supero la capacidad maxima de asientos del vuelo.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};

class PasajeroDuplicadoException : public exception {
private:
    string mensaje;

public:
    PasajeroDuplicadoException() {
        mensaje = "[PasajeroDuplicadoException] Ya existe un pasajero con esa CI en el vuelo.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};

class PasajeroYaEnVueloException : public exception {
private:
    string mensaje;

public:
    PasajeroYaEnVueloException() {
        mensaje = "[PasajeroYaEnVueloException] El pasajero ya tiene un asiento asignado en este vuelo.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};
