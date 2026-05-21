#pragma once
#include <iostream>
#include <string>

using namespace std;


// juampi utils
void assertEquals(double a, double b) {
    double error = 0.002;
    double difference = a - b;
    //abs
    if (difference < 0) difference = difference * -1;
    if (difference < 0.002) {
        cout << "ASSERT PASS :)" << endl;
    }
    else {
        cout << "ASSERT FAILS: " << a << " != " << b << endl;
    }
}

void assertEquals(const string& a, const string& b) {
    if (a == b) {
        cout << "ASSERT PASS :)" << endl;
    }
    else {
        cout << "ASSERT FAILS: " << a << " != " << b << endl;
    }
}

template <class T>
void assertEquals(T a, T b) {
    if (a == b) {
        cout << "ASSERT PASS :)" << endl;
    }
    else {
        cout << "ASSERT FAILS: " << endl;
        cout << " - Actual:   " << "[" << a << "]" << endl;
        cout << " - Esperado: " << "[" << b << "]" << endl;
    }
}

void assertTrue(bool value) {
    if (value) {
        cout << "ASSERT PASS :)" << endl;
    }
    else {
        cout << "ASSERT FAILS: " << value << " should be true" << endl;
    }
}

void assertFalse(bool value) {
    assertTrue(!value);
}

template<typename TException>
void assertThrows(
    string mensajeEsperado,
    void (*func)(int),
    int param1
) {
    try {
        func(param1);
        cout << "ASSERT FAILS: No se lanzó excepción" << endl;
    }
    catch (TException& ex) {

        if (ex.what() == mensajeEsperado) {
            cout << "ASSERT PASS :)" << endl;
        }
        else {
            cout << "ASSERT FAILS: mensaje incorrecto" << endl;
            cout << "Esperado: " << mensajeEsperado << endl;
            cout << "Actual: " << ex.what() << endl;
        }
    }
    catch (...) {
        cout << "ASSERT FAILS: tipo de excepción incorrecto" << endl;
    }
}
