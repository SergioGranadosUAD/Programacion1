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

void fib(int);

void error(string);
bool IsPalindrome(string);

enum ejercicios {EJERCICIO_UNO, EJERCICIO_DOS, EJERCICIO_TRES};

int main() {
	int eleccion = 0;
	bool salida = true;

	try {
		while (salida) {
			cout << "Introduzca el numero del ejercicio al que desea acceder. Introduzca cualquier otro numero para salir." << endl;
			cout << "'0': Ejercicio que determina si el string introducido es un palindromo." << endl;
			cout << "'1': Ejercicio que imprime n cantidad de numeros de la secuencia de fibonacci en base a la entrada del usuario." << endl;
			cout << "'2': Ejercicio que imprime una escalera de numeros hasta el numero indicado por el usuario." << endl;

			cin >> eleccion;
			if (cin.fail()) error("No se introdujo un numero entero.");

			cout << endl;

			switch (eleccion) {
			case ejercicios::EJERCICIO_UNO:
				EjercicioUno();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_DOS:
				EjercicioDos();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_TRES:
				EjercicioTres();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			default:
				cout << "Se ha terminado el programa." << endl;
				salida = false;
				break;
			}
		}
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
	}
}

//Ejercicio que verifica si una palabra introducida por el usuario es un palíndromo o no.
void EjercicioUno(){
	string palabra = "";

	cout << "Introduzca una palabra o frase que desea verificar." << endl;
	cin.ignore(265, '\n');
	getline(cin, palabra, '\n');

	palabra.erase(remove(palabra.begin(), palabra.end(), ' '), palabra.end());

	if (IsPalindrome(palabra)) cout << "El string introducido es un palindromo." << endl;
	else cout << "El string introducido NO es un palindromo." << endl;
}

//Ejercicio que imprime n ciclos de la secuencia de fibonacci que le indica el usuario.
void EjercicioDos() {
	int numero = 0;

	cout << "Introduzca el numero de ciclos de fibonacci que desea calcular." << endl;
	cin >> numero;
	if (cin.fail()) error("No se introdujo un numero entero.");
	fib(numero);
}

//Ejercicio que imprime una 'escalera' de numeros que va creciendo hasta el numero introducido por el usuario.
void EjercicioTres() {
	int numero = 0;

	cout << "Introduzca el numero de escalones que tendra la escalera." << endl;
	cin >> numero;
	if (cin.fail()) error("No se introdujo un numero entero.");
	if (numero < 0) error("El numero introducido es negativo.");

	for (int i = 1; i <= numero; i++) {
		for (int x = 1; x <= i; x++) {
			cout << x;
		}
		cout << endl;
	}
}

void error(string s) {
	throw runtime_error(s);
}

//Funcion que forma parte del ejercicio 2, imprime n numeros de la secuencia de fibonacci hasta donde el usuario indique.
void fib(int max) {
	//Pre-condicion: max es un numero entero positivo.
	//Post-condicion: regresa el numero maximo de la secuencia de Fibonacci hasta el ciclo indicado.

	//Se asegura que el numero maximo sea positivo, de lo contrario regresa un error.
	if (max >= 0) {
		int anterior = 0, actual = 1, sumaAmbos;
		if (max == 0) {
			cout << anterior << endl;
		}
		
		for (int i = 1; i <= max; i++) {
			sumaAmbos = anterior + actual;
			anterior = actual;
			actual = sumaAmbos;
			cout << actual << endl;
		}
	}
	else {
		error("No se puede calcular la secuencia de Fibonacci para un numero negativo!");
	}
}

//Funcion que forma parte del ejercicio 1, devuelve true si se trata de un palíndromo, o de lo contrario devuelve false.
bool IsPalindrome(string s) {
	char comparacion = ' ';

	for (int i = 0; i < s.length() / 2; i++) {
		comparacion = s[i];
		if (comparacion != s[s.length() - i - 1]) return false;
	}

	return true;
}