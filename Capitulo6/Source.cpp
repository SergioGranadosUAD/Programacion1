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

double expression();
double term();
double primary();

string sentence();
string conjunction();
string noun();
string verb();

void error(string);

double factorial(double);

//Esta clase es ocupada por los ejercicios de la calculadora y permite diferenciar si se trata de un caracter o de un numero.
class Token {
public:
	char kind;
	double value;
	Token(char ch):
		kind(ch), value(0) {}
	Token(char ch, double val):
		kind(ch), value(val) {}
};

//Esta clase se ocupa para iterar sobre cada uno de los caracteres que se introduzcan en la calculadora, obteniendolos, clasificandolos y guardandolos para su uso.
class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
private:
	bool full;
	Token buffer;
};

//Constructor de la clase Token_stream.
Token_stream::Token_stream():
	full(false), buffer(0) {}

//Clase ocupada por el ejercicio cuatro, combina lo que serian dos vectores en uno solo para la modificacion del ejercicio 19 del capitulo 4.
class Name_value {
public:
	string nombre;
	int puntaje;
	Name_value(string nom, int punt) :
		nombre(nom), puntaje(punt) {}
};

Token_stream ts;

int main() {
	int opcion;
	cout << "Introduzca el numero del ejercicio al que desea acceder (del 1 al 14)." << endl;
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
	default:
		cout << "No se introdujo un numero correcto" << endl;
	}
	return 0;
}

//Ejercicio que contiene todos los "Try this" del capítulo 6.
void EjercicioUno() {
	//El primer "Try this" es de conceptualización y se hace en papel.

	//Segundo "Try this"
	/*try {
	while (cin)
		cout << expression() << '\n';
	}
	catch (runtime_error& e) {
		cerr << e.what() << '\n';
	}
	catch (...) {
		cerr << "exception \n";
	}*/

	//Tercer "Try this"
	try {
		cout << "Esta es una calculadora sencilla." << endl;
		cout << "Introduzca la operacion matematica que desea realizar. (Acepta numeros decimales)" << endl;
		cout << "Suma: '+', Resta: '-', Multiplicacion: '*', division: '/'." << endl;
		cout << "Para calcular el resultado introduzca '=', para salir del programa introduzca 'q'." << endl;
		while (cin) {
			Token t = ts.get();


			/*if (t.kind == 'q') {
				break;
			}
			if (t.kind == '=') {
				cout << "=" << val << endl;
				ts.putback(Token('8', val));
			}
			else {
				ts.putback(t);
			}*/

			while (t.kind == '=') t = ts.get();
			if (t.kind == 'q') {
				break;
			}
			ts.putback(t);
			cout << "= " << expression() << endl;
			
		}
		cout << "Ha terminado el programa." << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << '\n';
	}
	catch (...) {
		cerr << "exception \n";
	}
}

void EjercicioDos() {
	//El siguiente ejercicio se ve reflejada en las funciones primary() y Token_stream::get(), modificándolas para que el programa acepte corchetes además de paréntesis.
}

void EjercicioTres() {
	//Este ejercicio se ve reflejado en las funciones primary(), factorial() y Token_stream::get(), modificándolas para que el programa pueda calcular factoriales.
}

//Ejercicio que modifica el ejercicio 19 del capitulo 4 para ocupe un solo vector de un tipo de dato generado por el usuario en vez de ocupar dos vectores.
void EjercicioCuatro() {
	vector<Name_value> lista;
	vector<int> puntajesLista;
	string nombre = "";
	string repetido = "";
	int puntaje = 0;

	cout << "Inserte un nombre seguido de su puntaje para su almacenamiento, escriba 'NoName 0' para dejar de capturar elementos." << endl;
	cin >> nombre >> puntaje;
	lista.push_back(Name_value{ nombre, puntaje });

	while (nombre != "NoName" || puntaje != 0) {
		cin >> nombre >> puntaje;
		for (int i = 0; i < lista.size(); ++i) {
			if (lista[i].nombre == nombre) {
				repetido = nombre;
			}
		}
		if (repetido == nombre) {
			cout << "Ese nombre ya existe!" << endl;
		}
		else if (nombre == "NoName") {
			cout << "Has terminado de capturar elementos." << endl;
		}
		else {
			lista.push_back(Name_value{ nombre, puntaje });
		}
	}

	for (int i = 0; i < lista.size(); ++i) {
		cout << "(" << lista[i].nombre << "," << lista[i].puntaje << ")" << endl;
	}
}

void EjercicioCinco() {
	/*Gramatica del lenguaje ingles:
	Sentence:
		Subject Verb
		"the" Subject Verb
		Sentence Conjunction Sentence
	
	Conjunction:
		"and"
		"or"
		but"
	
	Noun:
		"birds"
		"fish"
		"C++"
	
	Verb:
		"rules"
		"fly"
		"swim"*/
}

void EjercicioSeis() {

}

void EjercicioSiete() {
	/*Gramatica de operaciones logicas de bits:
	*/
}

void EjercicioOcho() {

}

void EjercicioNueve() {

}

void EjercicioDiez() {

}

void error(string s) {
	throw runtime_error(s);
}

//Esta función evalua si el token se trata de una expresión ocupando las reglas gramaticales ya establecidas.
double expression() {
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

//Esta función evalua si el token se trata de un termino ocupando las reglas gramaticales ya establecidas.
double term() {
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{ double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
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
double primary() {
	Token t = ts.get();
	double d = 0;
	switch (t.kind) {
	case '{':
	{
		d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		break;
	}
	case '(':
		d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		break;

	case '8':
		d = t.value;
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
	cin >> ch; //note that >> skips whitespace(space, newline, tab, etc.)
		switch (ch) {
			case '=': //for “print”
			case 'q': //for “quit”
			case '(': case ')': case '+': case '-': case '*': case '/': case '{': case '}': case '!':
				return Token{ ch }; //let each character represent itself
			case '.':
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
			{ 
				cin.putback(ch); //put digit back into the input stream
				double val;
				cin >> val; //read a floating - point number
				return Token{ '8',val}; //let ‘8’ represent “a number”
			}
			default:
				error("Bad token");
		}
}

//Esta funcion es usada por el ejercicio tres, calcula y devuelve la factorial de un numero si cumple con los requisitos.
double factorial(double num) {
	int check = num;
	if (double(check) != num) {
		error("No se puede calcular factorial para decimales.");
	}
	else if (num == 0) {
		return 1;
	}
	else {
		int resultado = check;
		for (int i = check - 1; i > 0; --i) {
			resultado *= i;
		}
		return resultado;
	}
}

string sentence() {
	return "";
}

string conjunction() {
	return "";
}

string noun() {
	return "";
}

string verb() {
	return "";
}