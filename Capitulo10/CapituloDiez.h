//ActividadDiez.h
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::runtime_error;
using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::ios_base;
using std::fmod;
using std::endl;
using std::cerr;

namespace CapituloDiez {
	//Esta clase representa un numero romano y tiene las funciones necesarias para su conversión a numeros arábigos.
	class Roman_int {
	public:
		//Constructores
		Roman_int():
			number("") {}
		Roman_int(string i):
			number(i) {}

		//Getters y Setters.
		string GetNumber() const {
			return number;
		}

		void SetNumber(string s);

		//Función auxiliar que convierte el número romano en un número arábigo.
		int as_int();

		//Sobrecarga de operadores.
		friend istream& operator>>(istream& is, Roman_int& r);
		friend ostream& operator<<(ostream& os, Roman_int& r);
	private:
		//Declaración de las propiedades.
		string number;

		//Funciones auxiliares solo ocupadas por otras funciones.
		bool Validate(string s);
		bool IsValidChar(char c);
		vector<int> GetCharValue(string s);
	};

	//Función que convierte un número arábigo en uno romano.
	string IntToRomanInt(int val);
/*
----------------------------------------
DECLARACIONES DE LA CALCULADORA
----------------------------------------
*/


	//Esta clase es ocupada por los ejercicios de la calculadora y permite diferenciar si se trata de un caracter o de un numero.
	class Token {
	public:
		char kind;
		double value;
		string name;
		Token(char ch) :
			kind(ch), value(0) {}
		Token(char ch, double val) :
			kind(ch), value(val) {}
		Token(char ch, string var) :
			kind(ch), value(0), name(var) {}
	};

	//Esta clase se ocupa para iterar sobre cada uno de los caracteres que se introduzcan en la calculadora, obteniendolos, clasificandolos y guardandolos para su uso.
	class Token_stream {
	public:
		Token_stream():
			full(false), buffer(0) {}
		Token get();
		void putback(Token t);
		void ignore(char c);
	private:
		bool full;
		Token buffer;
	};

	//Esta clase crea un objeto que se ocupa para almacenar variables introducidas en la calculadora.
	class Variable {
	public:
		string name;
		double value;
		bool isConst;
		Variable(string var, double val) :
			name(var), value(val), isConst(false) {}
		Variable(string var, double val, bool b) :
			name(var), value(val), isConst(b) {}
	};

	//Esta clase es ocupada por el ejercicio 4, junta todas las operaciones relacionadas al vector var_table en una sola clase así como protege este vector.
	class Symbol_table {
	public:
		double get_value(string s);
		void set_value(string s, double d);
		bool is_declared(string var);
		double define_name(string var, double val, bool b = false);
	private:
		vector<Variable> var_table;
	};

	void clean_up_mess(Token_stream&);

	double declaration(Token_stream&);
	double statement(Token_stream&);
	double expression(Token_stream&);
	double term(Token_stream&);
	double primary(Token_stream&);

	void calculate();
	void calculate(ifstream& ifs, ofstream& ofs);
	double factorial(double);
	void PrintInstructions();

	void error(string);
}