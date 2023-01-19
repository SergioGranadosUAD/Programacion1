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
using std::sort;
using std::sqrt;
using std::runtime_error;
using std::cerr;
using std::srand;
using std::rand;
using std::shuffle;
using std::default_random_engine;
using std::begin;
using std::end;

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

int area(int, int);
int framed_area(int, int);
void f(int, int, int);
void error(string);
double ctok(double);
double ktoc(double);
double ctof(double);
double ftoc(double);
void formulaGeneral(double, double, double, double&, double&);
int fib(int);

int main() {
	f(8, 5, 10);
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
	case 11:
		EjercicioOnce();
		break;
	case 12:
		EjercicioDoce();
		break;
	case 13:
		EjercicioTrece();
		break;
	case 14:
		EjercicioCatorce();
		break;
	default:
		cout << "No se introdujo un numero correcto" << endl;
	}
	return 0;
}

//Ejercicio que contiene todos los "Try this" del capítulo 5.
void EjercicioUno() {
	//Primer "Try this"
	/*int s1 = area(7;
	int s2 = area(7)
		Int s3 = area(7);
	int s4 = area('7);*/

	//Segundo "Try this"
	/*int x0 = arena(7); // error: undeclared function
	int x1 = area(7); // error: wrong number of arguments
	int x2 = area("seven", 2);
	int x3 = area("cinco", "pez");*/

	//Tercer "Try this"
	//f(8, 5, 10);
	//f(1, 3, 7);
	//f(-4, 7, 2);
	//f(8, 6, -3);

	//Cuarto "Try this"
	//error();

	//Quinto "Try this"
	vector<double> temps; // temperatures
	for (double temp; cin >> temp; ) // read and put into temps
		temps.push_back(temp);
	double sum = 0;
	double high_temp = 0;
	double low_temp = 0;
	for (double x : temps)
	{
		if (x > high_temp) high_temp = x; // find high
		if (x < low_temp) low_temp = x; // find low
		sum += x; // compute sum
	}
	cout << "High temperature: " << high_temp << '\n';
	cout << "Low temperature: " << low_temp << '\n';
	cout << "Average temperature: " << sum / temps.size() << '\n';

	//Sexto "Try this"
	sum = 0;
	high_temp = 134; // initialize to impossibly low
	low_temp = -128.56; // initialize to “impossibly high”
	int no_of_temps = 0;
	for (double temp; cin >> temp; ) { // read temp
		++no_of_temps; // count temperatures
		sum += temp; // compute sum
		if (temp > high_temp) high_temp = temp; // find high
		if (temp < low_temp) low_temp = temp; // find low
	}
	cout << "High temperature: " << high_temp << '\n';
	cout << "Low temperature: " << low_temp << '\n';
	cout << "Average temperature: " << sum / no_of_temps << '\n';

	//Los siguientes dos "Try this" se hacen en papel, puesto que son pruebas de estimación.

	//Noveno "Try this"
	area(0, 0);
}

//Ejercicio que corrige un programa de conversión de kelvin a celsius.
void EjercicioDos() {
	double c = 0; // declare input variable
	cout << "Introduzca un el valor en grados para convertirlo a Kelvin." << endl;
	cin >> c; // retrieve temperature to input variable
	double k = ctok(c); // convert temperature
	cout << c << " grados Celsius se convierten en " << k << " Kelvin." << endl; // print out temperature
}

//Ejercicio que modifica la función de conversión para que verifique que la temperatura no sea menor al cero absoluto.
void EjercicioTres(){
	double c = 0; // declare input variable
	cout << "Introduzca un el valor en grados para convertirlo a Kelvin." << endl;
	cin >> c; // retrieve temperature to input variable
	double k = ctok(c); // convert temperature
	cout << c << " grados Celsius se convierten en " << k << " Kelvin." << endl; // print out temperature
}

//Ejercicio que sigue modificando el programa de conversión para que maneje el mensaje de error.
void EjercicioCuatro() {
	try {
		double c = 0; // declare input variable
		cout << "Introduzca un el valor en grados para convertirlo a Kelvin." << endl;
		cin >> c; // retrieve temperature to input variable
		double k = ctok(c); // convert temperature
		cout << c << " grados Celsius se convierten en " << k << " Kelvin." << endl; // print out temperature
	}
	catch (runtime_error& e) {
		cerr << "Error durante la ejecucion del programa: " << e.what() << endl;
	}
}

//Ejercicio que expande el ejercicio anterior para que se pueda elegir la conversión que se desea.
void EjercicioCinco() {
	try {
		double c = 0; // declare input variable
		double k = 0;
		char seleccion = ' ';
		cout << "Introduzca el tipo de conversion que quiere hacer. ('c' para Celsius a Kelvin, 'k' para Kelvin a Celsius)" << endl;
		cin >> seleccion;

		switch (seleccion) {
		case 'c':
			cout << "Introduzca un el valor en grados para convertirlo a Kelvin." << endl;
			cin >> c; // retrieve temperature to input variable
			k = ctok(c); // convert temperature
			cout << c << " grados Celsius se convierten en " << k << " Kelvin." << endl; // print out temperature
			break;
		case 'k':
			cout << "Introduzca un el valor en Kelvin para convertirlo a Celsius." << endl;
			cin >> c; // retrieve temperature to input variable
			k = ktoc(c); // convert temperature
			cout << c << " Kelvin se convierten en " << k << " grados Celsius." << endl; // print out temperature
			break;
		default:
			cout << "No se introdujo un tipo de conversion valido." << endl;;
			break;
		}
	}
	catch (runtime_error& e) {
		cerr << "Error durante la ejecucion del programa: " << e.what() << endl;
	}
}

//Ejercicio que convierte entre grados Celsius y Fahrenheit y viceversa.
void EjercicioSeis() {
	double temperatura = 0;
	double conversion = 0;
	char seleccion = ' ';
	cout << "Introduzca el tipo de conversion que quiere hacer. ('c' para Celsius a Fahrenheit, 'f' para Fahrenheit a Celsius)" << endl;
	cin >> seleccion;

	switch (seleccion) {
	case 'c':
		cout << "Introduzca un el valor en grados Celsius para convertirlo a Fahrenheit." << endl;
		cin >> temperatura;
		conversion = ctof(temperatura);
		cout << temperatura << " grados Celsius se convierten en " << conversion << " grados Fahrenheit." << endl;
		break;
	case 'f':
		cout << "Introduzca un el valor en grados Fahrenheit para convertirlo a Celsius." << endl;
		cin >> temperatura;
		conversion = ftoc(temperatura);
		cout << temperatura << " grados Fahrenheit se convierten en " << conversion << " grados Celsius." << endl;
		break;
	default:
		cout << "No se introdujo un tipo de conversion valido." << endl;;
		break;
	}
}

//Ejercicio que resuelve una ecuacion cuadratica usando la formula general y le avisa al usuario si la ecuación no tiene raices.
void EjercicioSiete() {
	try {
		double a, b, c, x1, x2;
		cout << "Introduzca el valor de a, b y c, separados por espacios." << endl;
		cin >> a >> b >> c;
		formulaGeneral(a, b, c, x1, x2);
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	catch (runtime_error& e) {
		cerr << "Error durante la ejecucion del programa: " << e.what() << endl;
	}
}

//Ejercicio que recibe una serie de enteros y suma n cantidad de enteros que se le indique.
void EjercicioOcho() {
	try {
		vector<int> listaNumeros;
		int cantidadNumeros = 0;
		int suma = 0;
		int entrada = 0;
		cout << "Introduzca la cantidad de numeros que quiere sumar." << endl;
		cin >> cantidadNumeros;

		cout << "Introduzca los numeros que quiere agregar a la lista. (Introduzca Ctrl+z para salir)" << endl;
		while (cin >> entrada) {
			listaNumeros.push_back(entrada);
		}
		cout << "Ha terminado de recolectar numeros." << endl;

		if (cantidadNumeros > listaNumeros.size()) {
			error("Esta intentando sumar mas numeros de los que introdujo en la lista!");
		}
		else {
			for (int i = 0; i < cantidadNumeros; ++i) {
				suma += listaNumeros[i];
			}
		}

		cout << "La suma de los primeros " << cantidadNumeros << " numeros ( ";
		for (int i = 0; i < cantidadNumeros; ++i) {
			cout << listaNumeros[i] << " ";
		}
		cout << ") es: " << suma << endl;
	}
	catch (runtime_error& e) {
		cerr << "Error durante la ejecucion del programa: " << e.what() << endl;
	}
}

//Ejercicio que modifica el ejercicio 8 para que maneje un error en caso de que no se pueda representar el resultado como entero.
void EjercicioNueve() {
	try {
		vector<int> listaNumeros;
		int cantidadNumeros = 0;
		int suma = 0;
		int entrada = 0;
		cout << "Introduzca la cantidad de numeros que quiere sumar." << endl;
		cin >> cantidadNumeros;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			error("El valor introducido no es entero.");
		}

		cout << "Introduzca los numeros que quiere agregar a la lista. (Introduzca '-1' para salir)" << endl;
		while (entrada != -1) {
			cin >> entrada;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				error("El valor introducido no es entero.");
			}
			listaNumeros.push_back(entrada);
			if (entrada == -1) {
				cout << "Ha terminado de recolectar numeros." << endl;
			}
		}

		if (cantidadNumeros > listaNumeros.size()) {
			error("Esta intentando sumar mas numeros de los que introdujo en la lista!");
		}
		else {
			for (int i = 0; i < cantidadNumeros; ++i) {
				suma += listaNumeros[i];
			}
		}

		cout << "La suma de los primeros " << cantidadNumeros << " numeros ( ";
		for (int i = 0; i < cantidadNumeros; ++i) {
			cout << listaNumeros[i] << " ";
		}
		cout << ") es: " << suma << endl;
	}
	catch (runtime_error& e) {
		cerr << "Error durante la ejecucion del programa: " << e.what() << endl;
	}
}

//Ejercicio que sigue modificando el ejercicio 8 para que acepte double, así como agrega las diferencias entre valores en otro vector.
void EjercicioDiez() {
	try {
		vector<double> listaNumeros;
		vector<double> diferenciasNumeros;
		int cantidadNumeros = 0;
		double suma = 0;
		double entrada = 0;
		cout << "Introduzca la cantidad de numeros que quiere sumar." << endl;
		cin >> cantidadNumeros;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			error("El valor introducido no es entero.");
		}

		cout << "Introduzca los numeros que quiere agregar a la lista. (Introduzca '-1' para salir)" << endl;
		while (entrada != -1) {
			cin >> entrada;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				error("El valor introducido no es numerico.");
			}
			listaNumeros.push_back(entrada);
			if (entrada == -1) {
				cout << "Ha terminado de recolectar numeros." << endl;
			}
		}
		

		if (cantidadNumeros > listaNumeros.size()) {
			error("Esta intentando sumar mas numeros de los que introdujo en la lista!");
		}
		else {
			for (int i = 0; i < cantidadNumeros; ++i) {
				suma += listaNumeros[i];
			}
		}

		for (int i = 1; i < listaNumeros.size() - 1; ++i) {
			diferenciasNumeros.push_back(listaNumeros[i] - listaNumeros[i - 1]);
		}

		cout << "La suma de los primeros " << cantidadNumeros << " numeros ( ";
		for (int i = 0; i < cantidadNumeros; ++i) {
			cout << listaNumeros[i] << " ";
		}
		cout << ") es: " << suma << endl;

		for (int i = 0; i < diferenciasNumeros.size(); ++i) {
			cout << "La diferencia entre " << listaNumeros[i + 1] << " y " << listaNumeros[i] << " es de " << diferenciasNumeros[i] << endl;
		}

		
	}
	catch (runtime_error& e) {
		cerr << "Error durante la ejecucion del programa: " << e.what() << endl;
	}
}

//Ejercicio que encuentra el mayor numero de fibonacci que puede caber en un int.
void EjercicioOnce() {
	try {
		int max, f;
		cout << "Inserte el numero de ciclos para la funcion de fibonacci: " << endl;;
		cin >> max;
		f = fib(max);
		cout << "El numero maximo de fibonacci hasta ese ciclo es " << f << endl;
		//El numero maximo de fibonacci que acepta un int antes de romperse es '1836311903', que se obtiene al 46vo ciclo de la funcion.

	}
	catch (runtime_error& e) {
		cerr << "Error durante la ejecucion del programa: " << e.what() << endl;
	}
}

//Programa que emula el juego de adivinanza 'Toros y Vacas', ocupando un valor fijo como referencia.
void EjercicioDoce() {
	vector<int> adivinanza = { 5,8,3,9 };
	vector<int> intento;
	int entrada = 0, i = 0, bulls = 0, cows = 0, intentos = 0;
	bool repetido = false;

	

	while (bulls < 4) {
		intento.clear();
		bulls = 0;
		cows = 0;
		i = 0;

		cout << "Introduzca cuatro digitos. (No pueden estar repetidos)" << endl;
		while (i < 4) {
			cin >> entrada;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "El valor introducido no es un digito, intentelo nuevamente." << endl;
			}
			else if (entrada < 0 || entrada > 9) {
				cout << "El valor introducido no es un digito, intentelo nuevamente." << endl;
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
						cout << "El numero introducido esta repetido, introduzca otro." << endl;
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
	
	cout << "Has ganado! El numero secreto era " << adivinanza[0] << adivinanza[1] << adivinanza[2] << adivinanza[3] << endl;
	cout << "Te ha tomado " << intentos << " intentos adivinar el numero." << endl;
}

//Ejercicio que modifica el ejercicio 12, cambiando el numero estático por uno aleatorio ocupando la libreria de random.
void EjercicioTrece() {
	vector<int> adivinanza;
	vector<int> intento;
	vector <int> numeros = { 0,1,2,3,4,5,6,7,8,9 };
	int entrada = 0, i = 0, bulls = 0, cows = 0, intentos = 0, seed = 0;
	bool repetido = false;

	cout << "Introduzca un valor para generar el numero aleatorio." << endl;
	cin >> seed;
	srand(seed);

	shuffle(numeros.begin(), numeros.end(), default_random_engine(seed));

	for (int i = 0; i < 4; ++i) {
		adivinanza.push_back(numeros[i]);
	}

	cout << "intento: " << adivinanza[0] << " " << adivinanza[1] << " " << adivinanza[2] << " " << adivinanza[3] << endl;

	while (bulls < 4) {
		intento.clear();
		bulls = 0;
		cows = 0;
		i = 0;
		repetido = false;

		cout << "Introduzca cuatro digitos. (No pueden estar repetidos)" << endl;
		while (i < 4) {
			cin >> entrada;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "El valor introducido no es un digito, intentelo nuevamente." << endl;
			}
			else if (entrada < 0 || entrada > 9) {
				cout << "El valor introducido no es un digito, intentelo nuevamente." << endl;
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
						cout << "El numero introducido esta repetido, introduzca otro." << endl;
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

	cout << "Has ganado! El numero secreto era " << adivinanza[0] << adivinanza[1] << adivinanza[2] << adivinanza[3] << endl;
	cout << "Te ha tomado " << intentos << " intentos adivinar el numero." << endl;
}

//Ejercicio que recolecta pares de dias de la semana-numeros, suma los valores de cada dia de la semana y los imprime, así como las veces que un valor fue rechazado.
void EjercicioCatorce() {
	vector<int> valoresSemana = { 0,0,0,0,0,0,0 };
	string dia = "";
	int valor = 0, valoresRechazados = 0;
	cout << "Introduzca un dia de la semana y un valor numerico separados por espacios. (Introduzca Ctrl+z para terminar)" << endl;
	while (cin >> dia >> valor) {
		if (dia == "Lunes" || dia == "lunes" || dia == "lun") {
			valoresSemana[0] += valor;
		}
		else if (dia == "Martes" || dia == "martes" || dia == "mar") {
			valoresSemana[1] += valor;
		}
		else if (dia == "Miercoles" || dia == "miercoles" || dia == "mie") {
			valoresSemana[2] += valor;
		}
		else if (dia == "Jueves" || dia == "jueves" || dia == "jue") {
			valoresSemana[3] += valor;
		}
		else if (dia == "Viernes" || dia == "viernes" || dia == "vie") {
			valoresSemana[4] += valor;
		}
		else if (dia == "Sabado" || dia == "sabado" || dia == "sab") {
			valoresSemana[5] += valor;
		}
		else if (dia == "Domingo" || dia == "domingo" || dia == "dom") {
			valoresSemana[6] += valor;
		}
		else {
			cout << "El dia de la semana introducido no es valido." << endl;
			valoresRechazados++;
		}
	}

	cout << "La suma de los valores de cada dia de la semana son los siguientes: " << endl;
	cout << "Lunes: " << valoresSemana[0] << endl;
	cout << "Martes: " << valoresSemana[1] << endl;
	cout << "Miercoles: " << valoresSemana[2] << endl;
	cout << "Jueves: " << valoresSemana[3] << endl;
	cout << "Viernes: " << valoresSemana[4] << endl;
	cout << "Sabado: " << valoresSemana[5] << endl;
	cout << "Domingo: " << valoresSemana[6] << endl;
	cout << "Veces que un valor fue rechazado: " << valoresRechazados << endl;
}




//Funciones ocupadas por los ejercicios.


//Funcion que forma parte del tercer "Try this".
int area(int length, int width)
// calculate area of a rectangle;
// pre-conditions: length and width are positive
// post-condition: returns a positive value that is the area
{
	if (length <= 0 || width <= 0) error("area() pre-condition");
	int a = length * width;
	if (a <= 0) error("area() post-condition");
	return a;
}

//Funcion que forma parte del tercer "Try this".
int framed_area(int x, int y) // calculate area within frame
{
	cout << "framed_area x: " << x << endl;
	cout << "framed_area y: " << y << endl;
	constexpr int frame_width = 2;
	if (x - frame_width <= 0 || y - frame_width <= 0) {
		error("non-positive area() argument called by framed_area()");
	}
		
	return area(x - frame_width, y - frame_width);
}

//Funcion que forma parte del tercer "Try this".
void f(int x, int y, int z)
{
	try {
		int area1 = area(x, y);
		{
			if (area1 <= 0) error("non-positive area");
		}
		int area2 = framed_area(x, z);
		int area3 = framed_area(y, z);
		double ratio = double(area1) / area3;

		cout << "area1: " << area1 << endl;
		cout << "area2: " << area2 << endl;
		cout << "area3: " << area3 << endl;
		cout << "ratio: " << ratio << endl;
		// . . .
	}
	catch (runtime_error& e) {
		cerr << "runtime error:" << e.what() << endl;
	}
}

void error(string s) {
	throw runtime_error(s);
}

//Funcion que forma parte del ejercicio 2, convierte de grados celsius a Kelvin. Como parte del ejercicio 3 y 4 fue actualizada para que el valor no fuera menor al cero absoluto y se manejara el error.
double ctok(double c)
{
	//Pre-condicion: c es un valor que puede llevar punto decimal, no menor al cero absoluto (-273.15°C).
	//Post-condicion: Regresa la conversion de grados celsius a Kelvin.
	constexpr double ceroAbsoluto = -273.15;
	if (c > ceroAbsoluto) {
		return c + 273.15;
	}
	else {
		error("La temperatura indicada es menor al cero absoluto.");
	}
}

//Funcion que forma parte del ejercicio 5, convierte de Kelvin a grados Celsius.
double ktoc(double k) {
	//Pre-condicion: k es un valor positivo que puede llevar punto decimal.
	//Post-condicion: Regresa la conversion de Kelvin a grados Celsius.
	if (k > 0) {
		return k - 273.15;
	}
	else {
		error("La temperatura Kelvin no puede ser negativa.");
	}
}

//Funcion que forma parte del ejercicio 6, convierte de grados Celsius a Fahrenheit.
double ctof(double c) {
	//Pre-condicion: c es un valor numerico que puede llevar punto decimal.
	//Post-condicion: Regresa la conversion de grados celsius a Fahrenheit.
	return (c * (9.0 / 5.0)) + 32;
}

//Funcion que forma parte del ejercicio 6, convierte de grados Fahrenheit a Celsius.
double ftoc(double f) {
	//Pre-condicion: f es un valor numerico que puede llevar punto decimal.
	//Post-condicion: regresa la conversion de grados Fahrenheit a Celsius.
	return (f - 32) * (5.0 / 9.0);
}

//Funcion que forma parte del ejercicio 7, calcula las raices de una formula cuadrática.
void formulaGeneral(double a, double b, double c, double& x1, double& x2) {
	//Pre-condicion: a, b, y c, que son numeros que pueden llevar punto decimal.
	//Post-condicion: regresa el resultado de ambas raices de la ecuacion cuadratica a x1 y x2 por medio de la modificacion de sus referencias.
	double discriminante = (b * b) - (4 * a * c);
	if (discriminante < 0) {
		error("Los valores introducidos para la formula no tienen raices.");
	}
	else {
		x1 = (-b + sqrt(discriminante)) / (2 * a);
		x2 = (-b - sqrt(discriminante)) / (2 * a);
	}
}

//Funcion que forma parte del ejercicio 11, calcula el numero de ciclos indicados par la secuencia de Fibonacci.
int fib(int max) {
	//Pre-condicion: max es un numero entero positivo.
	//Post-condicion: regresa el numero maximo de la secuencia de Fibonacci hasta el ciclo indicado.
	if (max >= 0) {
		int a = 0, b = 1, c;
		if (max == 0) {
			cout << a << endl;
		}
		for (int i = 2; i <= max; i++) {
			c = a + b;
			a = b;
			b = c;
			cout << b << endl;
		}
		return b;
	}
	else {
		error("No se puede calcular la secuencia de Fibonacci para un numero negativo!");
	}
}