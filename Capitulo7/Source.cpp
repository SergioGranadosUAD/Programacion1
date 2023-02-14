#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;
using std::cerr;
using std::fmod;

void EjercicioUno();
void EjercicioDos();
void EjercicioTres();
void EjercicioCuatro();
void EjercicioCinco();
void EjercicioSeis();
void EjercicioSiete();
void EjercicioOcho();
void EjercicioNueve();
void EjercicioDiez();
void EjercicioOnce();

void calculate();


void error(string);

double factorial(double);
void PrintInstructions();

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
	Token_stream();
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
	Variable(string var, double val):
		name(var), value(val), isConst(false) {}
	Variable(string var, double val, bool b):
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

//Constructor de la clase Token_stream.
Token_stream::Token_stream() :
	full(false), buffer(0) {}


Symbol_table st;
const int number = 8;
const char printResult = ';';
const char exitProgram = 'q';
const char showHelp = 'h';
const char name = 'a';
const char let = 'L';
const char logaritmo = 'n';
const string declkey = "let";
const string exitkey = "quit";
const string helpkey = "help";
const string logkey = "log";
const string prompt = "> ";
const string result = "= ";

void clean_up_mess(Token_stream&);

double declaration(Token_stream&);
double statement(Token_stream&);
double expression(Token_stream&);
double term(Token_stream&);
double primary(Token_stream&);

int main() {
	int opcion;
	cout << "Introduzca el numero del ejercicio al que desea acceder (del 1 al 11)." << endl;
	cin >> opcion;
	switch (opcion) {
	case 1:
		EjercicioUno();
		break;
	case 2:
		EjercicioDos();
		break;
	case 3:
		EjercicioTres();
		break;
	case 4:
		EjercicioCuatro();
		break;
	case 5:
		EjercicioCinco();
		break;
	case 6:
		EjercicioSeis();
		break;
	case 7:
		EjercicioSiete();
		break;
	case 8:
		EjercicioOcho();
		break;
	case 9:
		EjercicioNueve();
		break;
	case 10:
		EjercicioDiez();
		break;
	case 11:
		EjercicioOnce();
		break;
	default:
		cout << "No se introdujo un numero correcto" << endl;
	}
	return 0;
}

//Este ejercicio contiene la calculadora actualizada. Además, para el primer ejercicio se modificó la función de Token_stream::get() para que los nombres de variables también
//aceptaran guión bajo ("_").
void EjercicioUno() {
	try {
		st.define_name("pi", 3.1415926535, true);
		st.define_name("e", 2.718218284, true);

		PrintInstructions();

		calculate();
		cout << "Ha terminado el programa." << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << '\n';
	}
	catch (...) {
		cerr << "exception \n";
	}
}

//Este ejercicio agrega el operador '=' que permite volver a asignarle valor a variables ya declaradas. Estos cambios se reflejan en las funciones primary() y Token_stream::get().
void EjercicioDos() {

}

//Este ejercicio le agrega la habilidad de diferenciar entre constantes o no a las variables de la calculadora. Los cambios se ven reflejados en la declaración de la clase
//Variable, y en la función set_value().
void EjercicioTres() {

}

//Este ejercicio agrupaba varias funciones dentro de una clase de nombre Symbol_table, y modifica los usos de estas para que funcionen debidamente.
void EjercicioCuatro() {

}

//Este ejercicio modifica la función Token_stream::get() para que identificara carácteres de newline ("\n") y lo tomara como impresión de resultados.
//Estos cambios se ven reflejados en la función antes mencionada.
void EjercicioCinco() {

}

//Este ejercicio modifica el programa para que le permita al usuario escribir el caracter 'h' para mostrar opciones. Los cambios se ven reflejados en las funciones
//Token_stream::get() y en calculate(). A pesar de esto se ve sobreescrito por el siguiente ejercicio.
void EjercicioSeis() {

}

//Este ejercicio modifica el programa para que le permita al usuario escribir la palabra "help" para mostrar opciones, así como "quit" para salir del programa.
//Los cambios se ven reflejados en las funciones Token_stream::get() y en calculate().
void EjercicioSiete() {

}

void EjercicioOcho() {

}

//Ejercicio que sugiere tres nuevas mejoras a la calculadora e implementa una de estas.
void EjercicioNueve() {
	//Añadir una función de potencia a la calculadora.
	//Añadir una función de raiz cuadrada a la calculadora.
	//Añadir una función de cálculo de logaritmos naturales. Esta fue la que se decidió agregar, reflejándose los cambios en la función primary() y en Token_stream::get().

}


void EjercicioDiez() {

}

void EjercicioOnce() {

}


void error(string s) {
	throw runtime_error(s);
}

//Esta función evalua las expresiones introducidas hasta que le indique que pare.
void calculate() {
	Token_stream ts;
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();

			while (t.kind == printResult) t = ts.get();
			if (t.kind == exitProgram) {
				break;
			}
			else if (t.kind == showHelp) {
				PrintInstructions();
			}
			ts.putback(t);
			cout << result << statement(ts) << endl;
		}
		catch (runtime_error& e) {
			cerr << e.what() << endl;
			clean_up_mess(ts);
		}
	}
}

double statement(Token_stream& ts) {
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(ts);
	default:
		ts.putback(t);
		return expression(ts);
	}
}

//Esta función evalua si el token se trata de una expresión ocupando las reglas gramaticales actualizadas en el capítulo 7.
double declaration(Token_stream& ts){
	Token t = ts.get();
	if (t.kind != name) error("Nombre esperado durante la declaracion.");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("Falta '=' en la declaracion de la variable.");

	double d = expression(ts);
	st.define_name(var_name, d);
	
	return d;
}

//Esta función evalua si el token se trata de una expresión ocupando las reglas gramaticales ya establecidas.
double expression(Token_stream& ts) {
	double left = term(ts);
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term(ts);
			t = ts.get();
			break;
		case '-':
			left -= term(ts);
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

//Esta función evalua si el token se trata de un termino ocupando las reglas gramaticales ya establecidas.
double term(Token_stream& ts) {
	double left = primary(ts);
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary(ts);
			t = ts.get();
			break;
		case '/':
		{ double d = primary(ts);
		if (d == 0) error("divide by zero");
		left /= d;
		t = ts.get();
		break;
		}
		case '%':
		{ double d = primary(ts);
		if (d == 0) error("divide by zero");
		left = fmod(left, d);
		t = ts.get();
		break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

//Esta función evalua si el token se trata de un valor primario ocupando las reglas gramaticales ya establecidas.
double primary(Token_stream& ts) {
	Token t = ts.get();
	double d = 0;
	switch (t.kind) {
	case '{':
	{
		d = expression(ts);
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		break;
	}
	case '(':
		d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		break;
	case name:
	{ Token t2 = ts.get();
	if (t2.kind == '=') {
		d = expression(ts);
		st.set_value(t.name, d);
		return d;
	}
	else {
		ts.putback(t2);
		return st.get_value(t.name);
	}
	}
	case number:
		d = t.value;
		break;
	case logaritmo:
		double ln;
		t = ts.get();
		if(t.kind != '(') error("')' expected");
		ln = expression(ts);
		//t = ts.get();
		//if (t.kind != number) error("El valor introducido no es numerico");
		d = log(ln);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		break;
	case '+':
		d = primary(ts);
		break;
	case '-':
		return -primary(ts);
		break;
	default:
		error("primary expected");
	}

	t = ts.get();
	if (t.kind == '!') {
		return factorial(d);
	}
	else {
		ts.putback(t);
		return d;
	}
}

//Esta función es usada por el ejercicio tres, calcula y devuelve la factorial de un numero si cumple con los requisitos.
double factorial(double num) {
	if (int(num) != num) {
		error("No se puede calcular factorial para decimales.");
	}
	else if (num == 0) {
		return 1;
	}
	else {
		return(num * factorial(num - 1));
	}

}

//Esta función es ocupada por la clase Token_stream para guardar un token para su uso posterior.
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t; // copy t to buffer
	full = true; // buffer is now full
}

//Esta función obtiene tokens del usuario y determina si se trata de un caracter valido o de un numero.
Token Token_stream::get()
{
	if (full) { //do we already have a Token ready ?
		full = false; //remove Token from buffer
		return buffer;
	}
	char ch;
	cin.get(ch);

	while (isspace(ch)) {
		if (ch == '\n') return Token(printResult);
		cin.get(ch);
	}

	switch (ch) {
	case printResult: //for “print”
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '{':
	case '}':
	case '!':
	case '%':
	case '=':
		return Token{ ch }; //let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch); //put digit back into the input stream
		double val;
		cin >> val; //read a floating - point number
		return Token{ number,val }; //let ‘8’ represent “a number”
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			cin.putback(ch);
			if (s == declkey) return Token{ let };
			if (s == exitkey) return Token{ exitProgram };
			if (s == helpkey) return Token{ showHelp };
			if (s == logkey) return Token{ logaritmo };
			return Token{ name,s };
		}
		error("Bad token");
	}
}

//Esta función descarta todos los caracteres en el stream hasta que encuentra el caracter de salida (c).
void Token_stream::ignore(char c) {
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

//Esta función limpia el resto de la expresión hasta encontrar el caracter de impresión, permitiendo volver a calcular sin cerrar el programa.
void clean_up_mess(Token_stream& ts) {
	ts.ignore(printResult);
}

double Symbol_table::get_value(string s) {
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable");
}

void Symbol_table::set_value(string s, double d) {
	for (Variable& v : var_table) {
		if (v.name == s) {
			if (v.isConst == false) {
				v.value = d;
				return;
			}
			error("No se puede modificar una constante.");
		}
	}
	error("set: undefined variable");
}

bool Symbol_table::is_declared(string var) {
	for (const Variable& v : var_table)
		if (v.name == var) return true;
	return false;
}

double Symbol_table::define_name(string var, double val, bool b) {
	if (is_declared(var)) error("variable declarada dos veces.");
	var_table.push_back(Variable{ var,val,b });
	return val;
}

void PrintInstructions() {
	cout << "Esta es una calculadora sencilla." << endl;
	cout << "Introduzca la operacion matematica que desea realizar. (Acepta numeros decimales)" << endl;
	cout << "Suma: '+', Resta: '-', Multiplicacion: '*', division: '/'." << endl;
	cout << "Para calcular el resultado introduzca ';'." << endl;
	cout << "Para imprimir este mensaje nuevamente escriba 'help', para salir del programa escriba 'quit'." << endl;
}