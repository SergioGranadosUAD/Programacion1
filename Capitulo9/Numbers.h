//Numbers.h
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;
using std::ios_base;

namespace Numbers {
	void error(string);

	//Clase ocupada por los ejercicios 13, 17,18. Representa una fracción y permite hacer cálculos sobre estas.
	class Rational {
	public:
		//Constructores
		Rational():
			numerator(0), denominator(1) {}
		Rational(int num):
			numerator(num), denominator(1) {}
		Rational(int num, int den):
			numerator(num), denominator(den) {}

		//Sobrecarga de operadores para operaciones que ocupan objetos de tipo Rational.
		friend Rational operator+(const Rational& r1, const Rational& r2);
		friend Rational operator-(const Rational& r1, const Rational& r2);
		friend Rational operator*(const Rational& r1, const Rational& r2);
		friend Rational operator/(const Rational& r1, const Rational& r2);
		friend bool operator==(const Rational& r1, const Rational& r2);
		friend bool operator!=(const Rational& r1, const Rational& r2);

		//Método auxiliar para convertir fracciones en numeros decimales.
		double ToDouble();
	private:
		//Declaración de sus propiedades.
		int numerator;
		int denominator;
	};

	
	//Clase ocupada por los ejercicios 14-16. Representa un valor monetario expresado en centavos, así como el tipo de cambio al que pertenece.
	class Money {
	public:
		//Enumerador para asignar el tipo de cambio de la moneda.
		enum Currency {
			MXN, USD, EUR
		};

		//Constructores
		Money():
			cents(0), currency(USD) {}
		Money(long int cent):
			cents(cent), currency(USD) {}
		Money(int dllr, int cent):
			cents((dllr*100)+cent), currency(USD) {}
		Money(long int cent, Currency curr):
			cents(cent), currency(curr) {}
		Money(int dllr, int cent, Currency curr):
			cents((dllr*100)+cent), currency(curr) {}

		//Métodos de retorno de valores.
		int GetDollar() const { return cents / 100; }
		int GetCents() const { return cents % 100; }
		int GetMoney() const { return cents; }

		//Sobrecarga de operadores para operaciones que ocupan objetos de tipo Money.
		friend Money operator+(const Money& r1, const Money& r2);
		friend Money operator-(const Money& r1, const Money& r2);
		friend Money operator*(const Money& r1, int i);
		friend Money operator/(const Money& r1, int i);
		friend istream& operator>>(istream& is, Money& r1);
		friend ostream& operator<<(ostream& os, const Money& r1);

	private:
		//Declaración de sus propiedades.
		long int cents;
		Currency currency;
	};

	//Funciones auxiliares para operaciones relacionadas a la clase Money.
	long int RoundUnit(double d);
	double ExchangeRate(Money::Currency curr1, Money::Currency curr2);
}