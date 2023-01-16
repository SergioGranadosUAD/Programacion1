#include <iostream>
#include <string>
#include <cmath>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::sqrt;

inline void keep_window_open() { char ch; cin >> ch; }

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
void EjercicioQuince();
void EjercicioDieciseis();
void EjercicioDiecisiete();
void EjercicioDieciocho();
void EjercicioDiecinueve();
void EjercicioVeinte();
void EjercicioVeintiuno();

int Cuadrado(int);
bool EsPrimo(int);


int main() {

	int opcion;
	cout << "Introduzca el numero del ejercicio al que desea acceder (del 1 al 22)." << endl;
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
	case 15:
		EjercicioQuince();
		break;
	case 16:
		EjercicioDieciseis();
		break;
	case 17:
		EjercicioDiecisiete();
		break;
	case 18:
		EjercicioDieciocho();
		break;
	case 19:
		EjercicioDiecinueve();
		break;
	case 20:
		EjercicioVeinte();
		break;
	case 21:
		EjercicioVeintiuno();
		break;
	default:
		cout << "No se introdujo un numero correcto" << endl;
	}
	return 0;
}

//Recopilación de todos los "Try this" del capítulo 4 del libro.
void EjercicioUno() {
	//Primer "Try this"
	constexpr double YenDolar = 0.0078;
	constexpr double KronerDolar = 0.1;
	constexpr double LibraDolar = 1.22;

	double cantidad;
	char moneda = 0;
	cout << "Introduzca la cantidad que desea convertir seguido del tipo de moneda (Yen = 'y', Corona danesa = 'k', Libra = 'p')" << endl;
	cin >> cantidad >> moneda;

	if (moneda == 'y') {
		cout << cantidad << " Yenes equivalen a " << cantidad * YenDolar << " Dolares." << endl;
	}
	else if (moneda == 'k') {
		cout << cantidad << " Coronas danesas equivalen a " << cantidad * YenDolar << " Dolares." << endl;
	}
	else if (moneda == 'p') {
		cout << cantidad << " Libras equivalen a " << cantidad * YenDolar << " Dolares." << endl;
	}
	else {
		cout << "No se reconoce ese tipo de moneda." << endl;
	}

	//Segundo "Try this"
	constexpr double YuanDolar = 0.15;

	cout << "Introduzca la cantidad que desea convertir seguido del tipo de moneda (Yen = 'y', Yuan = 'z', Corona danesa = 'k', Libra = 'p')" << endl;
	cin >> cantidad >> moneda;

	switch (moneda) {
	case 'y':
		cout << cantidad << " Yenes equivalen a " << cantidad * YenDolar << " Dolares." << endl;
		break;
	case 'k':
		cout << cantidad << " Coronas danesas equivalen a " << cantidad * YenDolar << " Dolares." << endl;
		break;
	case 'p':
		cout << cantidad << " Libras equivalen a " << cantidad * YenDolar << " Dolares." << endl;
		break;
	case 'z':
		cout << cantidad << " Yuanes equivalen a " << cantidad * YuanDolar << " Dolares." << endl;
		break;
	default:
		cout << "No se reconoce ese tipo de moneda." << endl;
	}

	//Tercer "Try this"
	int i = 0;
	while (i < 26) {
		cout << char('a' + i) << '\t' << int('a' + i) << endl;
		++i;
	}
	
	//Cuarto "Try this"
	for (int i = 0; i < 26; ++i) {
		cout << char('a' + i) << '\t' << int('a' + i) << endl;
	}
	cout << endl;
	for (int i = 0; i < 26; ++i) {
		cout << char('A' + i) << '\t' << int('A' + i) << endl;
	}
	cout << endl;
	for (int i = 0; i < 10; ++i) {
		cout << char('0' + i) << '\t' << int('0' + i) << endl;
	}

	//Quinto "Try this" (La función se encuentra hasta el fondo del programa).
	for (int i = 0; i <= 50; ++i) {
		cout << i << '\t' << Cuadrado(i) << endl;
	}

	//Sexto "Try this"
	vector<string> palabras;
	vector<string> palabrasProhibidas = { "Prueba", "Prohibido", "Hambre", "Tarea" };

	cout << "Introduzca las palabras que desea comprarar (Introduzca Ctrl+Z para terminar)." << endl;
	for (string temp; cin >> temp;) {
		palabras.push_back(temp);
	}

	cout << "Numero de palabras introducidas: " << palabras.size() << endl;

	for (int i = 0; i < palabras.size(); ++i) {
		string censura = "";
		for (string x : palabrasProhibidas) {
			if (palabras[i] == x) {
				censura = x;
			}
		}
		if (palabras[i] == censura) {
			cout << "BLEEP" << endl;
		}
		else {
			cout << palabras[i] << endl;
		}
	}
}

//Este ejercicio modifica el programa del ejemplo 4.6.3 para que siempre obtenga el valor de la media.
void EjercicioDos() {
	vector<double> temps;
	for (double temp; cin >> temp;) {
		temps.push_back(temp);
	}

	double sum = 0;
	for (double x : temps) {
		sum += x;
	}
	cout << "Temperatura promedio: " << sum / temps.size() << endl;

	sort(temps.begin(), temps.end());
	if (temps.size() % 2 == 0) {
		cout << "Temperatura media: " << temps[((temps.size()/2)-1+(temps.size()/2))/2] << endl;
	}
	else {
		cout << "Temperatura media: " << temps[temps.size()/2] << endl;
	}
}

//Este ejercicio realiza diversos cálculos de distancias entre ciudades en base a los datos de un vector.
void EjercicioTres() {
	vector<double> distancias;
	double sumaDistancias = 0;
	double menorDistancia = 0;
	double mayorDistancia = 0;
	double promedioDistancia = 0;
	cout << "Introduzca varias distancias entre ciudades (Para terminar de introducir presione Ctrl+z)." << endl;
	for (double distancia; cin >> distancia;) {
		distancias.push_back(distancia);
	}
	menorDistancia = distancias[0];
	for (double x : distancias) {
		sumaDistancias += x;
		if (x > mayorDistancia) {
			mayorDistancia = x;
		}
		if (x < menorDistancia) {
			menorDistancia = x;
		}
	}

	cout << "La suma de las distancias es de " << sumaDistancias << " metros." << endl;
	cout << "La mayor distancia entre ciudades es de " << mayorDistancia << " metros." << endl;
	cout << "La menor distancia entre ciudades es de " << menorDistancia << " metros." << endl;
	cout << "El promedio de distancias entre ciudades es de " << sumaDistancias / 2 << " metros." << endl;
}

//Ejercicio que adivina un numero en el que piensa un usuario del 1 al 100.
//UNFINISHED
void EjercicioCuatro() {

}

//Este ejercicio emula una calculadora simple, haciendo las cuatro operaciones aritmeticas principales sobre dos numeros.
void EjercicioCinco() {
	double num1, num2;
	char operacion;

	cout << "Introduzca dos numeros y la operacion que desea realizar separados por espacios. (+ para suma, - para resta, * para multiplicacion, / para division)" << endl;
	cin >> num1 >> num2 >> operacion;
	switch (operacion) {
	case '+':
		cout << "La suma de " << num1 << " y " << num2 << " es " << num1+num2 << endl;
		break;
	case '-':
		cout << "La resta de " << num1 << " y " << num2 << " es " << num1 - num2 << endl;
		break;
	case '*':
		cout << "La multiplicacion de " << num1 << " y " << num2 << " es " << num1 * num2 << endl;
		break;
	case '/':
		if (num2 != 0) cout << "La division de " << num1 << " y " << num2 << " es " << num1 / num2 << endl;
		else cout << "No se puede dividir entre cero!" << endl;
		break;
	default:
		cout << "No se introdujo una operacion valida." << endl;
		break;
	}
}


//Este ejercicio ocupa un vector para deletrear digitos y convertir un digito deletreado en su numero correspondiente.
void EjercicioSeis() {
	vector<string> numeros = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
	string entrada;

	cout << "Introduzca un numero del 1 al 9 de forma deletreada o en digito para saber su contraparte." << endl;
	cin >> entrada;
	for (int i = 0; i < numeros.size(); i++) {
		if (entrada[0]-'0' == i) {
			cout << "La forma deletreada de " << entrada[0] << " es " << numeros[i] << endl;
		} else if (entrada == numeros[i]) {
			cout << "El digito correspondiente a " << entrada << " es " << i << endl;
		}
	}
}

//Este ejercicio modifica la calculadora del ejercicio 5 para que solo acepte digitos en forma numerica o deletreados.
//UNFINISHED
void EjercicioSiete() {
	string num1, num2;
	double digito1 = 0, digito2 = 0;
	char operacion;
	vector<string> numeros = { "cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };

	cout << "Introduzca dos digitos de forma numerica o deletreada y la operacion que desea realizar separados por espacios. (+ para suma, - para resta, * para multiplicacion, / para division)" << endl;
	cin >> num1 >> num2 >> operacion;

	for (int i = 0; i < numeros.size(); i++) {
		if (num1[0] - '0' == i) {
			digito1 = num1[0] - '0';
		}
		else if (num1 == numeros[i]) {
			digito1 = i;
		}
		else {
			digito1 = 0;
		}

		if (num2[0] - '0' == i) {
			digito2 = num2[0] - '0';
		}
		else if (num2 == numeros[i]) {
			digito2 = i;
		}
		else {
			digito2 = 0;
		}
	}

	switch (operacion) {
	case '+':
		cout << "La suma de " << digito1 << " y " << digito2 << " es " << digito1 + digito2 << endl;
		break;
	case '-':
		cout << "La resta de " << digito1 << " y " << digito2 << " es " << digito1 - digito2 << endl;
		break;
	case '*':
		cout << "La multiplicacion de " << digito1 << " y " << digito2 << " es " << digito1 * digito2 << endl;
		break;
	case '/':
		if (digito2 != 0) cout << "La division de " << digito1 << " y " << digito2 << " es " << digito1 / digito2 << endl;
		else cout << "No se puede dividir entre cero!" << endl;
		break;
	default:
		cout << "No se introdujo una operacion valida." << endl;
		break;
	}
}

//Este ejercicio calcula la cantidad de cuadrados necesarios para alcanzar un numero determinado.
void EjercicioOcho() {
	int cicloActual = 3;
	int granosActuales = 0;
	int granosTotal = 3;

	while (granosTotal < 1000) {
		granosActuales = pow(2, cicloActual);
		granosTotal += granosActuales;
		++cicloActual;
	}
	cout << "Se requiere un total de " << cicloActual << " ciclos para alcanzar 1,000 granos de arroz." << endl;

	cicloActual = 3;
	granosActuales = 0;
	granosTotal = 3;

	while (granosTotal < 1000000) {
		granosActuales = pow(2, cicloActual);
		granosTotal += granosActuales;
		++cicloActual;
	}
	cout << "Se requiere un total de " << cicloActual << " ciclos para alcanzar 1,000,000 granos de arroz." << endl;

	cicloActual = 3;
	granosActuales = 0;
	granosTotal = 3;

	while (granosTotal < 1000000000) {
		granosActuales = pow(2, cicloActual);
		granosTotal += granosActuales;
		++cicloActual;
	}
	cout << "Se requiere un total de " << cicloActual << " ciclos para alcanzar 1,000,000,000 granos de arroz." << endl;
}

//Ejercicio que ocupa el ejercicio 8 como base para saber cual es el numero maximo de potencia que puede caber dentro de un int y de un double.
void EjercicioNueve() {
	int cicloActual = 3;
	int granosActuales = 0;
	int granosTotal = 3;

	while (cicloActual < 64) {
		granosActuales = pow(2, cicloActual);
		granosTotal += granosActuales;
		++cicloActual;
		cout << granosTotal << endl;
	}

	cicloActual = 3;
	double granosActuales2 = 0;
	double granosTotal2 = 3;

	while (cicloActual < 64) {
		granosActuales2 = pow(2, cicloActual);
		granosTotal2 += granosActuales2;
		++cicloActual;
		cout << granosTotal2 << endl;
	}
}

void EjercicioDiez() {

}

//Ejercicio que revisa si un numero es primo ocupando una funcion que ya contiene los numeros primos del 1 al 100.
void EjercicioOnce() {
	vector<int> numerosPrimos;

	for (int i = 0;i <= 100;++i) {
		if (EsPrimo(i)) {
			numerosPrimos.push_back(i);
		}
	}

	cout << "Numeros primos encontrados: " << endl;
	for (int x : numerosPrimos) {
		cout << x << " ";
	}
}

//Ejercicio que modifica el ejercicio once para que encuentre todos los numeros primos hasta n.
void EjercicioDoce() {
	vector<int> numerosPrimos;
	int max;

	cout << "Introduzca el numero hasta el que desea encontrar numeros primos: " << endl;
	cin >> max;

	for (int i = 0; i <= max; i++) {
		if (EsPrimo(i)) {
			numerosPrimos.push_back(i);
		}
	}

	cout << "Numeros primos encontrados: " << endl;
	for (int x : numerosPrimos) {
		cout << x << " ";
	}
}

//Ejercicio que encuentra numeros primos ocupando el algoritmo de la Criba de Eratóstenes.
//UNFINISHED
void EjercicioTrece() {
	vector<int> intLista;
	int primoSiguiente = 0, primosEncontrados = 0;

	for (int i = 2; i <= 100; ++i) {
		intLista.push_back(i);
	}

	primoSiguiente = intLista[0];
	++primosEncontrados;
	while (primosEncontrados != 0) {
		for (int x : intLista) {

		}
	}
	
}

void EjercicioCatorce() {

}

//Ejercicio que calcula la cantidad de numeros primos que le indique el usuario.
void EjercicioQuince() {
	vector<int> numerosPrimos;
	int conteoPrimos, i = 0;

	cout << "Introduzca el numero de numeros primos que desea obtener: " << endl;
	cin >> conteoPrimos;

	while (numerosPrimos.size() < conteoPrimos) {
		if (EsPrimo(i)) {
			numerosPrimos.push_back(i);
		}
		++i;
	}

	cout << "Numeros primos encontrados: " << endl;
	for (int x : numerosPrimos) {
		cout << x << " ";
	}
}

//Ejercicio que encuentra la moda de una serie de enteros positivos.
void EjercicioDieciseis() {
	vector<int> intLista;
	int conteoActual = 0, mayorConteo = 0, entrada = 0, numeroActual = 0, numeroModa = 0;
	cout << "Introduzca los numeros que desee. Para salir escriba '-1'." << endl;
	while (entrada != -1) {
		cin >> entrada;
		intLista.push_back(entrada);
	}

	sort(intLista.begin(), intLista.end());

	numeroActual = intLista[0];
	for (int x : intLista) {
		if (x == numeroActual) {
			++conteoActual;
		}
		else {
			numeroActual = x;
			conteoActual = 1;
		}
		if (conteoActual > mayorConteo) {
			mayorConteo = conteoActual;
			numeroModa = numeroActual;
		}
	}

	cout << "El numero que mas se repite es: " << numeroModa << ", repitiendose " << mayorConteo << " veces." << endl;
}

//Ejercicio que encuentra el maximo, minimo y la moda de una serie de strings.
void EjercicioDiecisiete() {
	vector<string> stringLista;
	string entrada, max = "", min = "", palabraActual = "", palabraModa = "";
	int conteoActual = 0, mayorConteo = 0;
	cout << "Introduzca las palabras que desee. Para salir escriba 'salir'." << endl;
	while (entrada != "salir") {
		cin >> entrada;
		stringLista.push_back(entrada);
	}
	
	min = stringLista[0];
	for (string x : stringLista) {
		if (x < min) {
			min = x;
		}
		else if (x > max) {
			max = x;
		}
	}

	sort(stringLista.begin(), stringLista.end());

	palabraActual = stringLista[0];
	for (string x : stringLista) {
		if (x == palabraActual) {
			++conteoActual;
		}
		else {
			palabraActual = x;
			conteoActual = 1;
		}
		if (conteoActual > mayorConteo) {
			mayorConteo = conteoActual;
			palabraModa = palabraActual;
		}
	}

	cout << "La palabra minima es: " << min << "." << endl;
	cout << "La palabra maxima es: " << max << "." << endl;
	cout << "La palabra que mas se repite es es: " << palabraModa << ", repitiendose " << mayorConteo << " veces." << endl;
}

//Ejercicio que resuelve una ecuación cuadrática aplicando la fórmula general.
void EjercicioDieciocho() {
	double a, b, c, x1, x2;
	cout << "Introduzca el valor de a, b y c, separados por espacios." << endl;
	cin >> a >> b >> c;

	x1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
	x2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);

	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
}

//Ejercicio que captura pares de nombres y puntajes y los imprime al terminar de capturar.
void EjercicioDiecinueve() {
	vector<string> nombresLista = {};
	vector<int> puntajesLista;
	string nombre = "";
	string repetido = "";
	int puntaje = 0;

	cout << "Inserte un nombre seguido de su puntaje para su almacenamiento, escriba 'NoName 0' para dejar de capturar elementos." << endl;
	cin >> nombre >> puntaje;
	nombresLista.push_back(nombre);
	puntajesLista.push_back(puntaje);

	while (nombre != "NoName" || puntaje != 0) {
		cin >> nombre >> puntaje;
		for (int i = 0; i < nombresLista.size(); ++i) {
			if (nombresLista[i] == nombre) {
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
			nombresLista.push_back(nombre);
			puntajesLista.push_back(puntaje);
		}
	}

	for (int i = 0; i < nombresLista.size(); ++i) {
		cout << "(" << nombresLista[i] << "," << puntajesLista[i] << ")" << endl;
	}
}

//Ejercicio que modifica el ejercicio 19 y en vez imprimir los pares al terminar la captura permite buscar un nombre e imprimir su puntaje.
void EjercicioVeinte() {
	vector<string> nombresLista = {};
	vector<int> puntajesLista;
	string nombre = "";
	string repetido = "";
	string busqueda = "";
	int puntaje = 0;

	cout << "Inserte un nombre seguido de su puntaje para su almacenamiento, escriba 'NoName 0' para dejar de capturar elementos." << endl;
	cin >> nombre >> puntaje;
	nombresLista.push_back(nombre);
	puntajesLista.push_back(puntaje);

	while (nombre != "NoName" || puntaje != 0) {
		cin >> nombre >> puntaje;
		for (int i = 0; i < nombresLista.size(); ++i) {
			if (nombresLista[i] == nombre) {
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
			nombresLista.push_back(nombre);
			puntajesLista.push_back(puntaje);
		}
	}

	cout << "Introduzca el nombre para el que desea buscar su puntaje." << endl;
	cin >> busqueda;
	for (int i = 0; i < nombresLista.size(); ++i) {
		if (busqueda == nombresLista[i]) {
			cout << "El puntaje de " << nombresLista[i] << " es de " << puntajesLista[i] << " puntos." << endl;
		}
	}
}

//Ejercicio que modifica el ejercicio 19 y en vez de imprimir los pares al terminar la captura imprime todos los nombres con el puntaje que se introduzca.
void EjercicioVeintiuno() {
	vector<string> nombresLista = {};
	vector<int> puntajesLista;
	string nombre = "";
	string repetido = "";
	int puntaje = 0;
	int busqueda = 0;

	cout << "Inserte un nombre seguido de su puntaje para su almacenamiento, escriba 'NoName 0' para dejar de capturar elementos." << endl;
	cin >> nombre >> puntaje;
	nombresLista.push_back(nombre);
	puntajesLista.push_back(puntaje);

	while (nombre != "NoName" || puntaje != 0) {
		cin >> nombre >> puntaje;
		for (int i = 0; i < nombresLista.size(); ++i) {
			if (nombresLista[i] == nombre) {
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
			nombresLista.push_back(nombre);
			puntajesLista.push_back(puntaje);
		}
	}

	cout << "Introduzca el puntaje para el que desea encontrar personas." << endl;
	cin >> busqueda;

	cout << "Las personas con " << busqueda << " puntos son las siguientes: " << endl;
	for (int i = 0; i < nombresLista.size(); ++i) {
		if (busqueda == puntajesLista[i]) {
			cout << nombresLista[i] << endl;
		}
	}
}

//Funciones ocupadas por los ejercicios

//Función utilizada en el Ejercicio Uno, quinto "Try this". Esta calcula el cuardado de un numero de forma manual.
int Cuadrado(int numero) {
	int resultado = 0;
	for (int i = 0; i < numero; ++i) {
		resultado += numero;
	}
	return resultado;
}

bool EsPrimo(int numero) {
	if (numero == 0) {
		return false;
	}
	else if (numero == 1) {
		return false;
	}
	else {
		for (int i = 2; i < numero; ++i) {
			if (numero % i == 0) {
				return false;
			}
		}
		return true;
	}
}