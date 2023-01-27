#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;
using std::default_random_engine;
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

bool sentence();
bool conjunction();
bool noun();
bool verb();

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

//Clase ocupada por el ejercicio seis, itera por un string.
class String_stream {
public:
	String_stream();
	string get();
	void putback(string s);
private:
	bool full;
	string buffer;
};

//Constructor de la clase String_stream.
String_stream::String_stream():
	full(false), buffer("") {}


//Clase ocupada por el ejercicio cuatro, combina lo que serian dos vectores en uno solo para la modificacion del ejercicio 19 del capitulo 4.
class Name_value {
public:
	string nombre;
	int puntaje;
	Name_value(string nom, int punt) :
		nombre(nom), puntaje(punt) {}
};

Token_stream ts;
String_stream ss;

int main() {
	int opcion;
	cout << "Introduzca el numero del ejercicio al que desea acceder (del 1 al 10)." << endl;
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

//Ejercicio que le agrega el pronombre "The" a la gramática del lenguaje inglés vista en el libro.
void EjercicioCinco() {
	/*Gramatica del lenguaje ingles:
	Sentence:
		Subject Verb .
		"The" Subject Verb .
		Sentence Conjunction Sentence .
	
	Conjunction:
		"and"
		"or"
		"but"
	
	Noun:
		"birds"
		"fish"
		"C++"
	
	Verb:
		"rules"
		"fly"
		"swim"*/
}

//Este ejercicio adapta la gramatica de inglés utilizada en el libro para la creación de un programa que verifica si un texto cumple con la gramatica.
void EjercicioSeis() {
	cout << "Introduzca una frase. Terminela con un espacio seguido de un punto." << endl;
	bool terminar = false;
	while (!terminar) {
		bool estado = sentence();
		if (!estado) {
			cout << "Not OK" << endl;
			terminar = true;
		}
		string s = ss.get();
		if (s == ".") {
			cout << "OK" << endl;
			terminar = true;
		}
		else {
			ss.putback(s);
			estado = conjunction();
			if (!estado) {
				cout << "Not OK" << endl;
				terminar = true;
			}
		}
	}
}

//Ejercicio que establece una gramática para las operaciones lógicas de bits.
void EjercicioSiete() {
	/*Gramatica de operaciones logicas de bits:
	OR:
		XOR
		OR '|' XOR

	XOR:
		AND
		XOR '^' AND

	AND:
		Unary
		AND '&' Unary
	
	Unary:
		Primary
		Unary '!' Primary
		Unary '~' Primary
	
	Primary:
		Number

	Number:
		floating-point-literal
	*/
}

//Ejercicio que modifica el ejercicio 12 del capítulo 5 para que acepte letras en vez de números.
void EjercicioOcho() {
	vector<char> adivinanza;
	vector<char> intento;
	vector <char> numeros = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char entrada = ' ';
	int i = 0, bulls = 0, cows = 0, intentos = 0, seed = 0;
	bool repetido = false;

	cout << "Introduzca un valor para generar la secuencia aleatorio." << endl;
	cin >> seed;
	srand(seed);

	shuffle(numeros.begin(), numeros.end(), default_random_engine(seed));

	for (int i = 0; i < 4; ++i) {
		adivinanza.push_back(numeros[i]);
	}

	//cout << "intento: " << adivinanza[0] << " " << adivinanza[1] << " " << adivinanza[2] << " " << adivinanza[3] << endl;

	while (bulls < 4) {
		intento.clear();
		bulls = 0;
		cows = 0;
		i = 0;
		repetido = false;

		cout << "Introduzca cuatro letras. (No pueden estar repetidas)" << endl;
		while (i < 4) {
			cin >> entrada;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "El valor introducido no es una letra, intentelo nuevamente." << endl;
			}
			else if (int(entrada) < 60 || int(entrada) > 123) {
				cout << "El valor introducido no es una letra, intentelo nuevamente." << endl;
			}
			else {
				if (intento.empty()) {
					intento.push_back(entrada);
					++i;
				}
				else {
					for (int x : intento) {
						if (entrada == x) {
							repetido = true;
						}
					}
					if (repetido) {
						cout << "La letra introducida esta repetida, introduzca otro." << endl;
					}
					else {
						intento.push_back(entrada);
						++i;
					}
					repetido = false;
				}
			}
		}
		cout << "intento: " << intento[0] << intento[1] << intento[2] << intento[3] << endl;


		for (int i = 0; i < adivinanza.size(); ++i) {
			for (int j = 0; j < intento.size(); ++j) {
				if (adivinanza[i] == intento[j]) {
					if (i == j) {
						++bulls;
					}
					else {
						++cows;
					}
				}
			}
		}

		cout << "Hay " << bulls << " Toros y " << cows << " Vacas." << endl;
		++intentos;
	}

	cout << "Has ganado! La secuencia secreta era " << adivinanza[0] << adivinanza[1] << adivinanza[2] << adivinanza[3] << endl;
	cout << "Te ha tomado " << intentos << " intentos adivinar la secuencia." << endl;
}

//Ejercicio que lee digitos en una cadena y los convierte en enteros, imprimiendolos con la cantidad que representan.
void EjercicioNueve() {
	string entrada = "";
	vector<int> numeros;
	try {
		cin >> entrada;
		if (entrada.size() < 4) {
			error("Este programa no acepta mas de 4 numeros.");
		}

		for (char ch : entrada) {
			if (isdigit(ch)) {
				numeros.push_back(ch - '0');
			}
			else {
				error("Uno de los valores introducidos no es numerico.");
			}
		}

		switch (numeros.size()) {
		case 1:
			cout << "Hay " << numeros[0] << " unos." << endl;
			break;
		case 2:
			cout << "Hay " << numeros[0] << " dieces y " << numeros[1] << " unos." << endl;
			break;
		case 3:
			cout << "Hay " << numeros[0] << " cienes, " << numeros[1] << " dieces y " << numeros[2] << " unos." << endl;
			break;
		case 4:
			cout << "Hay " << numeros[0] << " miles, " << numeros[1] << " cienes, " << numeros[2] << " dieces y " << numeros[3] << " unos." << endl;
			break;
		}
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}
}

//Ejercicio que calcula permutaciones o combinaciones de dos numeros ocupando su fórmula y la función de factorial.
void EjercicioDiez() {
	int numero1 = 0, numero2 = 0;
	double resultado;
	char seleccion = ' ';

	try {
		cout << "Introduzca la cantidad de numeros posibles." << endl;
		cin >> numero1;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			error("El valor introducido no es un entero.");
		}

		cout << "Introduzca la cantidad de numeros que se combinaran." << endl;
		cin >> numero2;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			error("El valor introducido no es un entero.");
		}

		cout << "Introduzca 'p' para calcular la permutacion, introduzca 'c' para calcular la combinacion." << endl;
		cin >> seleccion;
		switch (seleccion) {
		case 'p':
			resultado = factorial(numero1) / (factorial(numero1 - numero2));
			cout << "El resultado de P(" << numero1 << "," << numero2 << ") es " << resultado << endl;
			break;
		case 'c':
			resultado = (factorial(numero1) / (factorial(numero1 - numero2))) / factorial(numero2);
			cout << "El resultado de C(" << numero1 << "," << numero2 << ") es " << resultado << endl;
			break;
		default:
			error("No se introdujo un valor valido.");
			break;
		}
	}
	catch (runtime_error& e) {
		cerr << e.what() << '\n';
	}
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

void String_stream::putback(string s) {
	if (full) error("putback() into a full buffer");
	buffer = s; // copy t to buffer
	full = true; // buffer is now full
}

string String_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}

	string s;
	cin >> s;
	return s;
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

//Esta función es usada por el ejercicio seis, y devuelve verdadero si se cumplen las condiciones de noun() y verb()
bool sentence() {
	return noun() && verb();
}

//Esta función es usada por el ejercicio seis, y devuelve verdadero si encuentra uno de los nexos encontrados la gramatica.
bool conjunction() {
	string s = ss.get();
	if (s == "and" || s == "or" || s == "but") {
		return true;
	}
	else {
		return false;
	}
}

//Esta función es usada por el ejercicio seis, y devuelve verdadero si encuentra uno de los sujetos encontrados la gramatica.
bool noun() {
	string s = ss.get();
	if (s == "birds" || s == "fish" || s == "C++") {
		return true;
	}
	else {
		return false;
	}
}

//Esta función es usada por el ejercicio seis, y devuelve verdadero si encuentra uno de los verbos encontrados la gramatica.
bool verb() {
	string s = ss.get();
	if (s == "rules" || s == "fly" || s == "swim") {
		return true;
	}
	else {
		return false;
	}
}