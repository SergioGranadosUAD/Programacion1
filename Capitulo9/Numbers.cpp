//Numbers.cpp
#include "Numbers.h"

namespace Numbers {
	/*
	-------------------------------------------
	Funciones correspondientes a la clase Rational
	-------------------------------------------
	*/

	//Función auxiliar que convierte una fracción en un decimal, devolviendo double.
	double Rational::ToDouble() {
		return numerator / denominator;
	}

	//Sobrecarga de operador del ejercicio 13. Hace una suma de fracciones y devuelve el resultado como un objeto de tipo Rational.
	Rational operator+(const Rational& r1, const Rational& r2) {
		Rational result;
		if (r1.denominator == r2.denominator) {
			result.numerator = r1.numerator + r2.numerator;
			result.denominator = r1.denominator;
			return result;
		}
		else {
			result.numerator = (r1.numerator * r2.denominator) + (r2.numerator * r2.denominator);
			result.denominator = r1.denominator * r2.denominator;
			return result;
		}
	}

	//Sobrecarga de operador del ejercicio 13. Hace una resta de fracciones y devuelve el resultado como un objeto de tipo Rational.
	Rational operator-(const Rational& r1, const Rational& r2) {
		Rational result;
		if (r1.denominator == r2.denominator) {
			result.numerator = r1.numerator - r2.numerator;
			result.denominator = r1.denominator;
			return result;
		}
		else {
			result.numerator = (r1.numerator * r2.denominator) - (r2.numerator * r2.denominator);
			result.denominator = r1.denominator * r2.denominator;
			return result;
		}
	}

	//Sobrecarga de operador del ejercicio 13. Hace una multiplicación de fracciones y devuelve el resultado como un objeto de tipo Rational.
	Rational operator*(const Rational& r1, const Rational& r2) {
		Rational result;
		result.numerator = r1.numerator * r2.numerator;
		result.denominator = r1.denominator * r2.denominator;
		return result;
	}

	//Sobrecarga de operador del ejercicio 13. Hace una división de fracciones y devuelve el resultado como un objeto de tipo Rational.
	Rational operator/(const Rational& r1, const Rational& r2) {
		Rational result;
		result.numerator = r1.numerator * r2.denominator;
		result.denominator = r1.denominator * r2.numerator;
		return result;
	}

	//Sobrecarga de operador del ejercicio 13. Compara el numerador y denominador de dos objetos de tipo Rational y devuelve si son iguales o no.
	bool operator==(const Rational& r1, const Rational& r2) {
		return r1.numerator == r2.numerator && r1.denominator == r2.denominator;
	}

	//Sobrecarga de operador del ejercicio 13. Compara el numerador y denominador de dos objetos de tipo Rational y devuelve si son diferentes o no.
	bool operator!=(const Rational& r1, const Rational& r2) {
		return r1.numerator != r2.numerator && r1.denominator != r2.denominator;
	}

	/*
	-------------------------------------------
	Funciones correspondientes a la clase Money
	-------------------------------------------
	*/

	//Función auxiliar del ejercicio 14. Redondea o trunca un valor siguiendo la regla de redondeo de 4/5.
	long int RoundUnit(double d) {
		if (d < 0.5) {
			return d;
		}
		else {
			return d + 0.5;
		}
	}

	//Función auxilir del ejercicio 15. Devuelve la tasa de cambio de dos monedas en forma de double.
	double ExchangeRate(Money::Currency curr1, Money::Currency curr2) {
		switch (curr1) {
		case Money::MXN:
			if (curr2 == Money::USD) {
				return 0.054;
			}
			else if (curr2 == Money::EUR) {
				return 0.051;
			}
			else {
				return 1;
			}
			break;

		case Money::USD:
			if (curr2 == Money::MXN) {
				return 18.50;
			}
			else if (curr2 == Money::EUR) {
				return 0.94;
			}
			else {
				return 1;
			}
			break;

		case Money::EUR:
			if (curr2 == Money::MXN) {
				return 19.77;
			}
			else if (curr2 == Money::USD) {
				return 1.07;
			}
			else {
				return 1;
			}
			break;
		}
	}

	//Sobrecarga de operador ocupada por el ejercicio 15. Convierte las monedas a un mismo tipo y las suma, devolviendo el resultado.
	Money operator+(const Money& r1, const Money& r2) {
		double exchangeRate = ExchangeRate(r1.currency, r2.currency);
		return Money(r1.GetMoney() + (r2.GetMoney() * exchangeRate), r1.currency);
	}

	

	//Sobrecarga de operador ocupada por el ejercicio 15. Convierte las monedas a un mismo tipo y las resta, devolviendo el resultado.
	Money operator-(const Money& r1, const Money& r2) {
		double exchangeRate = ExchangeRate(r1.currency, r2.currency);
		return Money(r1.GetMoney() - (r2.GetMoney() * exchangeRate), r1.currency);
	}

	//Sobrecarga de operador ocupada por el ejercicio 15. Multiplica los centavos de un objeto de tipo Money por un entero y lo devuelve.
	Money operator*(const Money& r1, int i) {
		long int mult = r1.GetMoney() * i;
		return Money(mult, r1.currency);
	}

	//Sobrecarga de operador ocupada por el ejercicio 15. Divide los centavos de un objeto de tipo Money entre un entero y lo devuelve.
	Money operator/(const Money& r1, int i) {
		if (i == 0) {
			error("No se puede dividir entre 0");
		}
		double div = double(r1.GetMoney()) / i;
		long int res = RoundUnit(div);
		return Money(res, r1.currency);
	}

	//Sobrecarga de operador ocupada por el ejercicio 16. Recibe una entrada específica en la que se debe de poner el valor monetario
	//y verifica que sea coherente. De ser así, la guarda en una variable de tipo Money.
	istream& operator>>(istream& is, Money& r1) {
		int dllr = 0;
		int cent = 0;
		string currS = "";
		char point = ' ';
		Money::Currency curr;
		is >> currS >> dllr >> point >> cent;
		if (!is) {
			return is;
		}
		if ((currS != "MXN" || currS != "USD" || currS != "EUR") || point != '.') {
			is.clear(ios_base::failbit);
			return is;
		}
		if (currS == "MXN") {
			curr = Money::MXN;
		}
		else if (currS == "USD") {
			curr = Money::USD;
		}
		else if (currS == "USD") {
			curr = Money::EUR;
		}
		r1 = Money(dllr, cent, curr);
		return is;
	}

	//Sobrecarga de operador ocupada por el ejercicio 16. Imprime con formato un objeto de tipo Money.
	ostream& operator<<(ostream& os, const Money& r1) {
		string curr = "";
		switch (r1.currency) {
		case Money::MXN:
			curr = "MXN";
			break;
		case Money::USD:
			curr = "USD";
			break;
		case Money::EUR:
			curr = "EUR";
			break;
		}
		cout << "$" << curr << r1.GetDollar() << "." << r1.GetCents();
		return os;
	}

	//Función para arrojar errores.
	void error(string s) {
		throw runtime_error(s);
	}
}