#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class ArrayGenerica {
private:
    vector<T> elementos;

public:
    void agregar(const T& elemento) {
        elementos.push_back(elemento);
    }

    void mostrar() const {
        for (size_t i = 0; i < elementos.size(); i++) {
            cout << i + 1 << ". ";
            elementos[i].mostrar();
            cout << endl;
        }
    }

    T& operator[](int index) {
        return elementos[index];
    }

    int size() const {
        return static_cast<int>(elementos.size());
    }

    bool isEmpty() const {
        return elementos.empty();
    }
};
