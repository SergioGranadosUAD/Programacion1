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
using std::swap;
using std::sort;

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
void EjercicioDoce();
void EjercicioTrece();
void EjercicioCatorce();

void error(string);
void print(string, const vector<int>&);
void fibonacci(int, int, vector<int>&, int);
void reverseCopy(const vector<int>&);
void reverseModify(vector<int>&);
void reverseCopyString(const vector<string>&);
void reverseModifyString(vector<string>&);
vector<int> letterCountString(const vector<string>&);
string longestString(const vector<string>&);
string shortestString(const vector<string>&);
string lexFirstString(vector<string>);
string lexLastString(vector<string>);


vector<double> calculateIndex(const vector<double>&, const vector<double>&);
double maxv(const vector<double>&);
void print_until_s(const vector<string>&, string);
void print_until_ss(const vector<string>&, string);
double areaCircle(double, const double);

//Struct ocupada por el ejercicio 11, almacena los resultados de las operaciones en una sola variable.
struct Calculos
{
	double max;
	double min;
	double mean;
	double median;
};

Calculos calcularValores(vector<double>&);

enum ejercicios {
	EJERCICIO_UNO = 1,
	EJERCICIO_DOS,
	EJERCICIO_TRES,
	EJERCICIO_CUATRO,
	EJERCICIO_CINCO,
	EJERCICIO_SEIS,
	EJERCICIO_SIETE,
	EJERCICIO_OCHO,
	EJERCICIO_NUEVE,
	EJERCICIO_DIEZ,
	EJERCICIO_ONCE,
	EJERCICIO_DOCE,
	EJERCICIO_TRECE,
	EJERCICIO_CATORCE
};

int main() {
	int eleccion = 0;
	bool salida = true;

	try {
		while (salida) {
			cout << "Introduzca el numero del ejercicio al que desea acceder (1-14). Introduzca cualquier otro numero para salir." << endl;

			cin.clear();
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
			case ejercicios::EJERCICIO_CUATRO:
				EjercicioCuatro();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_CINCO:
				EjercicioCinco();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_SEIS:
				EjercicioSeis();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_SIETE:
				EjercicioSiete();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_OCHO:
				EjercicioOcho();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_NUEVE:
				EjercicioNueve();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_DIEZ:
				EjercicioDiez();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_ONCE:
				EjercicioOnce();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_DOCE:
				EjercicioDoce();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_TRECE:
				EjercicioTrece();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_CATORCE:
				EjercicioCatorce();
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

//En este caso para evitar hacer más completo e ilegible este archivo decidí modificar el programa de la calculadora en el capítulo 7,
//por lo que los cambios se encuentran en ese archivo.
void EjercicioUno() {

}

//Ejercicio que ocupa la funcion print() para imprimir vectores.
void EjercicioDos() {
	string etiqueta = "";
	int num = 0;
	vector<int> numeros;

	cout << "Introduzca la etiqueta para la impresion del vector: " << endl;
	cin >> etiqueta;

	cout << "Introduzca los numeros que desea agregar al vector. Introduzca Ctrl+z para terminar." << endl;
	while (cin >> num) {
		if (cin.fail()) error("No se introdujo un numero entero.");
		numeros.push_back(num);
	}

	print(etiqueta, numeros);
}

//Ejercicio que ocupa la funcion fibonacci() para calcular la secuencia de fibonacci con los valores introducidos y la imprime.
void EjercicioTres() {
	int numeroUno = 0;
	int numeroDos = 0;
	int cantidadCiclos = 0;
	vector<int> vectorNumeros;

	cout << "Introduzca los dos numeros en los que iniciara la secuencia de fibonacci: " << endl;
	cin >> numeroUno >> numeroDos;
	if (cin.fail()) error("No se introdujo un numero entero.");

	cout << "Introduzca la cantidad de ciclos que de fibonacci que quiere imprimir: " << endl;
	cin >> cantidadCiclos;
	if (cin.fail()) error("No se introdujo un numero entero.");

	fibonacci(numeroUno, numeroDos, vectorNumeros, cantidadCiclos);

}

//Ejercicio que ocupa la funcion pasada para encontrar el numero maximo de ciclos antes de que el int se rompa.
void EjercicioCuatro() {
	vector<int> vectorNumeros;
	fibonacci(0, 1, vectorNumeros, 46);
	//El numero maximo de fibonacci que acepta un int antes de romperse es '1836311903', que se obtiene al 46vo ciclo de la funcion.
}

//Ejercicio que ocupa las funciones reverseCopy() y reverseModify() para voltear un vector de enteros de diferentes maneras.
void EjercicioCinco() {
	vector<int> vector = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	reverseCopy(vector);

	reverseModify(vector);
}

//Este ejercicio hace lo mismo que el anterior pero con strings, ocupando las funciones reverseCopyString() y reverseModifyString();
void EjercicioSeis() {
	vector<string> vector = { "Hola", "esto", "es", "una", "tarea", "de", "programacion."};

	reverseCopyString(vector);

	reverseModifyString(vector);
}

//Este ejercicio captura pares de nombres y edad en vectores, para posteriormente organizar estos de forma alfabética y los imprime.
void EjercicioSiete() {
	vector<string> name;
	vector<string> nameCopy;
	vector<double> age;
	vector<double> ageSorted;
	string entradaNombre = "";
	double entradaEdad = 0;

	cout << "Introduzca los nombres de las personas que desea agregar a la lista." << endl;
	while (cin >> entradaNombre) {
		if (cin.fail()) error("Hubo un error al introducir el valor");
		name.push_back(entradaNombre);
	}

	cin.clear();
	cout << "Ahora introduzca la edad de las personas que agrego anteriormente en el mismo orden." << endl;
	while (cin >> entradaEdad) {
		if (cin.fail()) error("El valor introducido no es numerico.");
		age.push_back(entradaEdad);
	}

	if (name.size() != age.size()) error("No se introdujeron todos los elementos en una de las listas!");

	nameCopy = name;
	sort(name.begin(), name.end());
	for (string val : name) {
		for (int i = 0; i < nameCopy.size(); i++) {
			if (nameCopy[i] == val) {
				ageSorted.push_back(age[i]);
			}
		}
	}

	cout << "Pares de nombres y edad ordenados: " << endl;
	for (int i = 0; i < name.size(); i++) {
		cout << "Nombre: " << name[i] << ", Edad: " << ageSorted[i] << endl;
	}
}

//Este ejercicio hace lo mismo que el anterior pero con n numero de elementos introducidos por el usuario.
void EjercicioOcho() {
	vector<string> name;
	vector<string> nameCopy;
	vector<double> age;
	vector<double> ageSorted;
	string entradaNombre = "";
	double entradaEdad = 0;

	cout << "Introduzca los nombres de las personas que desea agregar a la lista. Introduzca Ctrl+Z para terminar." << endl;
	while (cin >> entradaNombre) {
		if (cin.fail()) error("Hubo un error al introducir el valor");
		name.push_back(entradaNombre);
	}

	cin.clear();
	cout << "Ahora introduzca la edad de las personas que agrego anteriormente en el mismo orden. Introduzca Ctrl+Z para terminar." << endl;
	while (cin >> entradaEdad) {
		if (cin.fail()) error("El valor introducido no es numerico.");
		age.push_back(entradaEdad);
	}

	if (name.size() != age.size()) error("No se introdujeron todos los elementos en una de las listas!");

	nameCopy = name;
	sort(name.begin(), name.end());
	for (string val : name) {
		for (int i = 0; i < nameCopy.size(); i++) {
			if (nameCopy[i] == val) {
				ageSorted.push_back(age[i]);
			}
		}
	}

	cout << "Pares de nombres y edad ordenados: " << endl;
	for (int i = 0; i < name.size(); i++) {
		cout << "Nombre: " << name[i] << ", Edad: " << ageSorted[i] << endl;
	}
}

//Este ejercicio ocupa la función calculateIndex() para crear un tercer vector calculando el 'indice' de dos vectores anteriores introducidos por el usuario.
void EjercicioNueve() {
	vector<double> price;
	vector<double> weight;
	vector<double> index;
	double val1 = 0;
	double val2 = 0;

	cout << "Introduzca los pares de precio y peso. Cuando termine presione Ctrl+Z para salir." << endl;
	while (cin >> val1 >> val2) {
		if (cin.fail()) error("No se introdujo un numero.");
		price.push_back(val1);
		weight.push_back(val2);
	}

	index = calculateIndex(price, weight);

	cout << "Los indices calculados son: " << endl;
	for (double i : index) {
		cout << i << ", ";
	}
}

//Este ejercicio ocupa la función maxv() para encontrar el número más grande de un vector.
void EjercicioDiez() {
	vector<double> vector;
	double numero = 0;
	double mayor = 0;

	cout << "Introduzca numeros de los cuales se encontrara el mayor. Introduzca Ctrl+Z para salir. " << endl;
	while (cin >> numero) {
		if (cin.fail()) error("No se introdujo un numero.");
		vector.push_back(numero);
	}

	mayor = maxv(vector);

	cout << "El valor mayor del vector es de: " << mayor << endl;
}

//Este ejercicio ocupa la función calcularValores() para hacer varios cálculos sobre un vector de doubles, siendo devueltos en forma de struct, para
//su posterior impresión.
void EjercicioOnce() {
	vector<double> vector;
	double numero = 0;
	Calculos resultado;

	cout << "Introduzca numeros sobre los cuales se realizaran las operaciones. Introduzca Ctrl+Z para salir. " << endl;
	while (cin >> numero) {
		if (cin.fail()) error("No se introdujo un numero.");
		vector.push_back(numero);
	}

	resultado = calcularValores(vector);

	cout << "El valor maximo del vector es: " << resultado.max << endl;
	cout << "El valor minimo del vector es: " << resultado.min << endl;
	cout << "El promedio del vector es: " << resultado.mean << endl;
	cout << "La media del vector es: " << resultado.median << endl;
}

//Este ejercicio mejora la función print_until_s() del libro. Posteriormente crea la función print_until_ss(), que funciona como la anterior
//con la diferencia de que esta termina al introducirse la palabra de salida por segunda ocasión.
void EjercicioDoce() {
	string word = "";
	string quit = "";
	vector<string> palabras;

	cout << "Introduzca la palabra que detendra la impresion de la lista." << endl;
	cin >> quit;

	cout << "Introduzca las palabras que quiera enlistar. Introduzca Ctrl+Z para salir. " << endl;
	while (cin >> word) {
		if (cin.fail()) error("Error al introducir la palabra.");
		palabras.push_back(word);
	}

	cout << "Funcion print_until_s:" << endl;
	print_until_s(palabras, quit);
	cout << endl;

	cout << "Funcion print_until_ss:" << endl;
	print_until_ss(palabras, quit);
}

//Este ejercicio recibe un vector de strings y ocupa funciones para encontrar el numero de letras dentro de cada uno de los elementos de este,
//así como encontrar el elemento más largo, el más corto, el primero y el último en orden lexicográfico.
void EjercicioTrece() {
	vector<string> palabras;
	vector<int> conteoPalabras;
	string word = "";

	cout << "Introduzca las palabras que quiera enlistar. Introduzca Ctrl+Z para salir. " << endl;
	while (cin >> word) {
		if (cin.fail()) error("Error al introducir la palabra.");
		palabras.push_back(word);
	}

	conteoPalabras = letterCountString(palabras);
	cout << "El conteo de letras de cada elementro introducido es: (";
	for (int i : conteoPalabras) cout << i << ", ";
	cout << ")" << endl;
	cout << "La palabra mas corta encontrada en la lista es: " << shortestString(palabras) << endl;
	cout << "la palabra mas larga encontrada en la lista es: " << longestString(palabras) << endl;
	cout << "la primera palabra en orden lexicografico de la lista es: " << lexFirstString(palabras) << endl;
	cout << "la ultima palabra en orden lexicografico de la lista es: " << lexLastString(palabras) << endl;

	//Ocupé cinco funciones, esto se debe a que es mejor separar cada tarea a una función para que sean más legibles, y se puedan reutilizar mejor
	//según el uso que se requiera para esta.
}

//Este ejercicio explica explica qué pasa cuando se declara un argumento de función constante no referencial. Así como una pequeña prueba de su uso.
void EjercicioCatorce() {
	//Sí se puede declarar, y significa que el argumento de la función siempre tendrá el mismo valor, y puede tener la utilidad de declarar una
	//variable constante que solo ocupa espacio al momento de mandar a llamar la función, ahorrando ese espacio en la memoria, pero aún así es muy raro
	//este caso y no hay mucha razón para que se ocupe.

	cout << "El area de un circulo con radio de 5 es " << areaCircle(5, 3.1416) << endl;
}

/*
FUNCIONES OCUPADAS POR LOS EJERCICIOS
*/


void error(string s) {
	throw runtime_error(s);
}

//Función ocupada por el ejercicio 2, recibe una etiqueta y un vector e imprime todos los elementos de este vector.
void print(string label, const vector<int>& vector) {
	for (int i : vector) {
		cout << label << ": " << i << endl;
	}
}

//Función ocupada por el ejercicio 3 y 4, recibe varios argumentos para calcular la secuencia de fibonacci e imprime la secuencia usando la funcion print().
void fibonacci(int x, int y, vector<int>& v, int n) {
	//Se asegura que el numero maximo sea positivo, de lo contrario regresa un error.
	if (n >= 0) {
		int sumaAmbos;
		if (n <= 0) {
			error("No hay elementos que agregar en la secuencia.");
		}

		for (int i = 1; i <= n; i++) {
			sumaAmbos = x + y;
			x = y;
			y = sumaAmbos;
			v.push_back(y);
		}

		print("fibonacci", v);
	}
	else {
		error("No se puede calcular la secuencia de Fibonacci para un numero negativo!");
	}
}

//Función ocupada por el ejercicio 5, crea una copia de un vector para invertur los elementos.
void reverseCopy(const vector<int>& v) {
	vector<int> reverse;
	for (int i = v.size()-1; i > 0; i--) {
		reverse.push_back(v[i]);
	}

	cout << "Nuevo vector en reversa: ";
	for (int i = 0; i < reverse.size(); i++) {
		cout << reverse[i] << ", ";
	}
	cout << endl;
}

//Función ocupada por el ejercicio 5, ocupa una referencia para modificar directamente el vector sin crear uno nuevo.
void reverseModify(vector<int>& v) {
	for (auto start = v.begin(), end = std::prev(v.end()); start < end; ++start, --end) {
		swap(*start, *end);
	}

	cout << "Vector original en reversa: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

//Función ocupada por el ejercicio 6, es la misma función del ejercicio 5 pero ocupando un string.
void reverseCopyString(const vector<string>& v) {
	vector<string> reverse;
	for (int i = v.size()-1; i > 0; i--) {
		reverse.push_back(v[i]);
	}

	cout << "Nuevo vector en reversa: ";
	for (int i = 0; i < reverse.size(); i++) {
		cout << reverse[i] << ", ";
	}
	cout << endl;
}

//Función ocupada por el ejercicio 6, es la misma función del ejercicio 5 pero ocupando un string.
void reverseModifyString(vector<string>& v) {
	for (auto start = v.begin(), end = std::prev(v.end()); start < end; ++start, --end) {
		swap(*start, *end);
	}

	cout << "Vector original en reversa: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

//Función ocupada por el ejercicio 9, calcula un vector con los indices de dos vectores de precio y peso y lo devuelve.
vector<double> calculateIndex(const vector<double>& price, const vector<double>& weight) {
	vector<double> index;
	if (weight.size() == price.size()) {
		for (int i = 0; i < weight.size(); i++) {
			index.push_back(weight[i] * price[i]);
		}
	}
	else {
		error("Los vectores no contienen el mismo numero de elementos.");
	}

	return index;
}

//Función ocupada por el ejercicio 10, esta recibe un vector de tipo double y devuelve el valor mayor de este.
double maxv(const vector<double>& v) {
	double max = 0;
	for (double i : v) {
		if (i > max) max = i;
	}

	return max;
}

//Función ocupada por el ejercicio 11, hace varios calculos sobre los elementos de un vector y devuelve el resultado de estos en un struct.
Calculos calcularValores(vector<double>& v) {
	Calculos resultados;
	double max = 0;
	double min = v[0];
	double mean = 0;
	double median = 0;
	double sum = 0;

	for (double i : v) {
		if (i > max) max = i;
		if (i < min) min = i;
		sum += i;
	}

	mean = sum / v.size();

	sort(v.begin(), v.end());

	if (v.size() % 2 == 1) median = v[v.size() / 2];
	else median = v[(v.size() / 2)-1] + v[v.size() / 2];
	
	resultados.max = max;
	resultados.min = min;
	resultados.mean = mean;
	resultados.median = median;

	return resultados;
}

//Función ocupada por el ejercicio 12, imprime un vector hasta que se encuentra una palabra de salida.
void print_until_s(const vector<string>& v, string quit) {
	for (string s : v) {
		if (s == quit) return;
		cout << s << endl;
	}
}

//Función ocupada por el ejercicio 12, imprime un vector hasta que se encuentra una palabra de salida por segunda ocasión.
void print_until_ss(const vector<string>& v, string quit) {
	int contador = 0;
	for (string s : v) {
		if (s == quit) contador++;
		if (contador == 2) return;
		cout << s << endl;
	}
}

//Función ocupada por el ejercicio 13, recibe un vector de Strings y devuelve un vector de Ints con el conteo de letras de cada uno de los elementos del
//vector.
vector<int> letterCountString(const vector<string>& v) {
	if (v.size() < 1) {
		error("El vector introducido no contiene elementos!");
	}

	vector<int> conteoLetras;
	for (string val : v) {
		int contador = 0;
		for (int i = 0; i < val.size(); i++) {
			contador++;
		}
		conteoLetras.push_back(contador);
	}

	return conteoLetras;
}

//Función ocupada por el ejercicio 13, recibe un vector de Strings y devuelve el string más corto.
string longestString(const vector<string>& v) {
	if (v.size() < 1) {
		error("El vector introducido no contiene elementos!");
	}

	string longest = "";
	for (string val : v) {
		if (val.size() > longest.size()) longest = val;
	}

	return longest;
}

//Función ocupada por el ejercicio 13, recibe un vector de Strings y devuelve el string más largo.
string shortestString(const vector<string>& v) {
	if (v.size() < 1) {
		error("El vector introducido no contiene elementos!");
	}

	string shortest = v[0];
	for (string val : v) {
		if (val.size() < shortest.size()) shortest = val;
	}

	return shortest;
}

//Función ocupada por el ejercicio 13, recibe un vector de Strings y devuelve el primer string en orden lexicográfico.
string lexFirstString(vector<string> v) {
	if (v.size() < 1) {
		error("El vector introducido no contiene elementos!");
	}

	sort(v.begin(), v.end());
	return v[0];
}

//Función ocupada por el ejercicio 13, recibe un vector de Strings y devuelve el último string en orden lexicográfico.
string lexLastString(vector<string> v) {
	if (v.size() < 1) {
		error("El vector introducido no contiene elementos!");
	}

	sort(v.begin(), v.end());
	return v[v.size() - 1];
}

//Funcion ocupada por el ejercicio 14, calcula el area de un circulo ocupando la constante de pi.
double areaCircle(double radius, const double pi = 3.1416) {
	return (pi * radius) / 2;
}