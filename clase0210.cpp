#include <iostream>
#include <string>

using namespace std;

class Cuenta
{
    private:
    string titular;
    double dineroCuenta;

    public:

    Cuenta(string _titular)
    {
        this -> titular = _titular;
        this ->dineroCuenta = 0;
    }
    Cuenta(string _titular , double _dineroCuenta)
    {
        this -> titular = _titular;
        this ->dineroCuenta = _dineroCuenta;
    }

    void mostrarCuenta()
    { 
        cout << " Titular de la cuenta : " << titular << endl;
        cout << " Dinero en la cuenta : " << dineroCuenta << endl;
    }

    string getTitular()
    {
        return titular;
    }

    int getDineroCantidad()
    {
        return dineroCuenta;
    }

    void setTitular(string nuevoTitular)
    {
        this ->titular= nuevoTitular;
    }

    void setDineroCuenta(double nuevoCantidaDinero)
    {
        this ->dineroCuenta= nuevoCantidaDinero;
    }

    void ingresarDineroACuenta(double dinero)
    {   
        if(dinero >0)
        {
            dineroCuenta+=dinero;
        }
    }

    void retirarDineroCuenta(double dinero)
    {
        if (dineroCuenta - dinero <0)
        {
            dineroCuenta = 0;
        }
        else 
        {
            dineroCuenta -=dinero;
        }
    }
};

class Persona
{

   
    private:

    string nombre;
    int edad;
    string dni;
    char sexo;
    double peso;
    double altura;
     const int bajoPeso = -1;
    const int pesoIdeal = 0;
    const int sobrePeso= 1;


    public:

    Persona()
    {
        this ->nombre = "";
        this ->edad=0;
        this ->dni="";
        this ->sexo='H';
        this ->peso=0;
        this ->altura=0;
    }

    Persona(string _nombre ,int _edad , char _sexo )
    {
        this ->nombre = _nombre;
        this ->edad = _edad;
        comprobarSexo(_sexo);
        this->dni = generaDNI();
        this ->peso = 0;
        this ->altura =0;

    }

    Persona(string _nombre, int _edad, char _sexo, double _peso, double _altura)
    {
        this->nombre = _nombre;
        this->edad = _edad;
        this->peso = _peso;
        this->altura = _altura;
        comprobarSexo(_sexo);
        this->dni = generaDNI();
    }

    void comprobarSexo(char sexo)
    {
        if (sexo=='H'|| sexo == 'M')
        {   
            this -> sexo = sexo;
        }
        else 
        {
            this ->sexo = 'H';
        }
    }

    string generaDNI()
    {
        string numero = "12345678";
        char letra = 'A';
        return numero + letra;
    }


    int calcularIMC()
    {
         if(altura == 0)
        {
            return 0;
        }

        double imc = peso / (altura * altura);

        if(imc < 20)
        {
            return bajoPeso;
        }
        else if(imc >= 20 && imc <= 25)
        {
            return pesoIdeal;
        }
        else
        {
            return sobrePeso;
        }
    }

    bool esMayorDeEdad()
    {
        if(edad >= 18)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string toString()
    {
        return "Nombre: " + nombre +
               "Edad: " + to_string(edad) +
               "DNI: " + dni +
               "Sexo: " + sexo +
               "Peso: " + to_string(peso) +
               "Altura: " + to_string(altura);
    }

    void setNombre(string nuevoNombre)
    {
        this->nombre = nuevoNombre;
    }

    void setEdad(int nuevaEdad)
    {
        this->edad = nuevaEdad;
    }

    void setSexo(char nuevoSexo)
    {
        comprobarSexo(nuevoSexo);
    }

    void setPeso(double nuevoPeso)
    {
        this->peso = nuevoPeso;
    }

    void setAltura(double nuevaAltura)
    {
        this->altura = nuevaAltura;
    }

};


class Password
{
    private:
    string contrasenia;
    int longitud;
    public:

    Password()
    {   
        generarPassword();
        this->longitud = 8; // por defecto

    }

    Password(int _longitud)
    {
        this ->longitud = _longitud;
        generarPassword();
    }


    void generarPassword()
    {
        contrasenia = "";

        for(int i = 0; i < longitud; i++)
        {
            if(i % 3 == 0)
            {
                contrasenia += 'A'; // Mayuscula
            }
            else if(i % 3 == 1)
            {
                contrasenia += 'a'; // Minuscula
            }
            else
            {
                contrasenia += '5'; // Numero
            }
        }
    }

     bool esFuerte()
    {
        int mayus = 0;
        int minus = 0;
        int numeros = 0;

        for(int i = 0; i < contrasenia.length(); i++)
        {
            if(contrasenia[i] >= 'A' && contrasenia[i] <= 'Z')
            {
                mayus++;
            }
            else if(contrasenia[i] >= 'a' && contrasenia[i] <= 'z')
            {
                minus++;
            }
            else if(contrasenia[i] >= '0' && contrasenia[i] <= '9')
            {
                numeros++;
            }
        }

        if(mayus > 2 && minus > 1 && numeros > 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string getContrasenia()
    {
        return contrasenia;
    }

    int getLongitud()
    {
        return longitud;
    }

    void setLongitud(int nuevaLongitud)
    {
        this->longitud = nuevaLongitud;
        generarPassword();
    }




};




    /*void ejercicio1()

    {
        Cuenta cuenta1 = Cuenta("Fulano");
        Cuenta cuenta2 = Cuenta("mario",200);

        cuenta1.mostrarCuenta();
        cuenta2.mostrarCuenta();

        cuenta1.ingresarDineroACuenta(300);
        cuenta1.mostrarCuenta();

        cuenta2.retirarDineroCuenta(100);
        cuenta2.mostrarCuenta();
    }
*/
   /* void ejercicio2()
    {
         Persona persona1("Juan", 20, 'H', 70, 1.75);

    cout << persona1.toString() << endl;

    cout << "IMC resultado: " << persona1.calcularIMC() << endl;

    cout << "Es mayor de edad? " << persona1.esMayorDeEdad() << endl;

    
    }
    */

    void ejercicio3()
    {
    Password pass1; //primer construcotr
    Password pass2(12); //segndo constructor

    cout << "contrasenia 1: " << pass1.getContrasenia() << endl;
    cout << "Es fuelte? " << pass1.esFuerte() << endl;

    cout << "contrasenia 2: " << pass2.getContrasenia() << endl;
    cout << "Es fuelte? " << pass2.esFuerte() << endl;

    pass2.setLongitud(15);

    cout << "contrasenia 2 modificada: " << pass2.getContrasenia() << endl;
    cout << "Es fuelte? " << pass2.esFuerte() << endl;
    }
int main()
{
    //ejercicio1();
    //ejercicio2();

    ejercicio3();

    return 0;
}