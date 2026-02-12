#include <iostream>
#include <string>
using namespace std;

class Password {
private:
    int longitud;
    string contrasena;

public:

    Password() {
        longitud = 8;
        contrasena = "ABC12345";
    }
    Password(int l) {
        longitud = l;
        contrasena = "";
    }

    void setPassword(string c) {
        contrasena = c;
        longitud = c.length();
    }

    bool esFuerte() {
        int mayus = 0;
        int minus = 0;
        int numeros = 0;

        for (int i = 0; i < contrasena.length(); i++) {

            if (contrasena[i] >= 'A' && contrasena[i] <= 'Z')
                mayus++;

            else if (contrasena[i] >= 'a' && contrasena[i] <= 'z')
                minus++;

            else if (contrasena[i] >= '0' && contrasena[i] <= '9')
                numeros++;
        }

        if (mayus > 2 && minus > 1 && numeros > 3)
            return true;
        else
            return false;
    }

    void mostrar() {
        cout << "Password: " << contrasena << endl;
        cout << "Longitud: " << longitud << endl;
    }
};

int main() {
int L;
string C;

    Password p1;
    p1.mostrar();
    if (p1.esFuerte())
        cout << "Es fuerte" << endl;
    else
        cout << "No es fuerte" << endl;

    cout<<"ingrese otra clave"<<endl;
    cin>>C;
    p1.setPassword(C);
    p1.mostrar();

    if (p1.esFuerte())
        cout << "Es fuerte" << endl;
    else
        cout << "No es fuerte" << endl;

}
