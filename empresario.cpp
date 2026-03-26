using namespace std;
#include <iostream>
#include <string>
class Cuentabancaria{
private:
string nombre;
int numerodecuenta;
float balance;
int registro[100];
public:
	Cuentabancaria(string nombre, int numerodecuenta, float balance) {
		this->nombre=nombre;
		this->numerodecuenta=numerodecuenta;
		this->balance=balance;
}
	int deposito(float deposi) {
			balance=balance+deposi;
	}
	float retiro(float retir){
		if (balance > retir) {
		balance=balance-retir;
		return balance;
	}
}

};
class Cuentatrans : public Cuentabancaria {
private:
	int retiro;
public:
	Cuentatrans(string nombre, int numerodecuenta,float balance,int retiro) :
	Cuentabancaria(nombre,numerodecuenta,balance)
	{
	this->retiro=retiro;
	}
	float retiro(float retiro) {
	int p;
	p=Cuentabancaria::retiro(retiro);
	cout<<p<<endl;

	}
};
int main()
{
	Cuentatrans("lola", 99393, 3333, 30);

}
