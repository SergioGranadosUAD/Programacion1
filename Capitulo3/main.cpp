#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void EjercicioUno();
void EjercicioDos();
void EjercicioTres();
void EjercicioCuatro();
void EjercicioCinco();
void EjercicioSeis();
void EjercicioSiete();
void EjercicioOcho();
void EjercicioNueve();
void Ejercicio10();
void Ejercicio11();

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

void EjercicioUno() {
	//ToDo
}

//Este ejercicio convierte millas a kilometros en base al numero introducido por el usuario.
void EjercicioDos() {
	double millas, kilometros;
	cout << "Introduzca la cantidad de millas que desea convertir a kilometros." << endl;
	cin >> millas;
	kilometros = millas * 1.609;
	cout << millas << " millas equivalen a " << kilometros << " kilometros.";
}

void EjercicioTres() {
	//ToDo
}

//Este ejercicio recibe dos enteros y determina cual es mayor de estos, su suma, su diferencia, su producto y el ratio de estos.
void EjercicioCuatro() {
	int val1, val2;
	cout << "Introduzca el valor de dos enteros separados por un espacio." << endl;
	cin >> val1 >> val2;

	if (val1 > val2) {
		cout << val1 << " es mayor que " << val2 << endl;
	}
	else {
		cout << val2 << " es mayor que " << val1 << endl;
	}
	cout << "La suma de ambos numeros es " << val1 + val2 << endl;
	cout << "La diferencia de ambos numeros es " << val1 - val2 << endl;
	cout << "El producto de ambos numeros es " << val1 * val2 << endl;
	if (val2 != 0) {
		cout << "El ratio de ambos numeros es " << val1 / val2 << endl;
	}
	else {
		cout << "No se puede dividir entre cero!" << endl;
	}
}

//Este ejercicio recibe dos double y determina cual es mayor de estos, su suma, su diferencia, su producto y el ratio de estos.
void EjercicioCinco() {
	double val1, val2;
	cout << "Introduzca el valor de dos numeros decimales separados por un espacio." << endl;
	cin >> val1 >> val2;

	if (val1 > val2) {
		cout << val1 << " es mayor que " << val2 << endl;
	}
	else {
		cout << val2 << " es mayor que " << val1 << endl;
	}
	cout << "La suma de ambos numeros es " << val1 + val2 << endl;
	cout << "La diferencia de ambos numeros es " << val1 - val2 << endl;
	cout << "El producto de ambos numeros es " << val1 * val2 << endl;
	if (val2 != 0) {
		cout << "El ratio de ambos numeros es " << val1 / val2 << endl;
	}
	else {
		cout << "No se puede dividir entre cero!" << endl;
	}
}

//Este ejercicio recibe tres enteros y los organiza del menor al mayor.
void EjercicioSeis() {
	int entero1, entero2, entero3, max, med, min;
	cout << "Introduzca el valor de tres numeros decimales separados por un espacio." << endl;
	cin >> entero1 >> entero2 >> entero3;
	cout << "El orden actual de los valores es: " << entero1 << ", " << entero2 << ", " << entero3 << endl;

	if (entero1 > entero2) {
		if (entero1 > entero3) {
			max = entero1;
			if (entero2 > entero3) {
				med = entero2;
				min = entero3;
			}
			else {
				med = entero3;
				min = entero2;
			}
		}
		else {
			max = entero3;
			med = entero1;
			min = entero2;
		}
	}
	else {
		if (entero2 > entero3) {
			max = entero2;
			if (entero1 > entero3) {
				med = entero1;
				min = entero3;
			}
			else {
				med = entero3;
				min = entero1;
			}
		}
		else {
			max = entero3;
			med = entero2;
			min = entero1;
		}
	}

	cout << "El orden de los numeros ordenados es: " << min << ", " << med << ", " << max;
}

//Este ejercicio recibe tres strings y los organiza alfabeticamente.
void EjercicioSiete() {
	//ToDo
}

//Ejercicio que recibe un numero y determina si es par o non.
void EjercicioOcho() {
	int numero;
	cout << "Introduzca un numero para determinar si es par o non." << endl;
	cin >> numero;
	if (numero % 2 == 0) {
		cout << "El numero " << numero << " es par." << endl;
	}
	else {
		cout << "El numero " << numero << " es non." << endl;
	}
}

//Ejercicio que convierte un numero deletreado en un digito.
void EjercicioNueve() {
	string escrito;
	int resultado;
	cout << "Deletree un numero de un solo digito." << endl;
	cin >> escrito;

	if (escrito == "cero") {
		resultado = 0;
	}
	else if (escrito == "uno") {
		resultado = 1;
	}
	else if (escrito == "dos") {
		resultado = 2;
	}
	else if (escrito == "tres") {
		resultado = 3;
	}
	else if (escrito == "cuatro") {
		resultado = 4;
	}
	else {
		resultado = -1;
	}

	if (resultado != -1) {
		cout << "El digito correspondiente a la palabra " << escrito << " es " << resultado;
	}
	else {
		cout << "escribiste mas de lo que puedo calcular!";
	}
}

//Ejercicio que recibe la operacion y dos numeros que se desean calular y realiza la operacion correspondiente
void EjercicioDiez() {
	string operacion;
	double val1, val2, resultado;
	cout << "Introduzca la operacion que desea realizar (+, -, *, /, suma, resta, multiplicacion, division) y los dos numeros que desea calular, todo separado por espacios." << endl;
	cin >> operacion >> val1 >> val2;

	if (operacion == "+" || operacion == "suma") {
		resultado = val1 + val2;
		cout << "El resultado de sumar " << val1 << " y " << val2 << " es " << resultado << endl;
	}
	else if (operacion == "-" || operacion == "resta") {
		resultado = val1 - val2;
		cout << "El resultado de restar " << val1 << " y " << val2 << " es " << resultado << endl;
	}
	else if (operacion == "*" || operacion == "multiplicacion") {
		resultado = val1 * val2;
		cout << "El resultado de multiplicar " << val1 << " y " << val2 << " es " << resultado << endl;
	}
	else if (operacion == "/" || operacion == "division") {
		if (val2 != 0) {
			resultado = val1 / val2;
			cout << "El resultado de dividir " << val1 << " entre " << val2 << " es " << resultado << endl;
		}
		else {
			cout << "No se puede dividir entre cero!" << endl;
		}
	}
}

//Ejercicio que le pide al usuario introducir el numero de monedas de diferentes tipos que tiene y mostrarlas, así como el balance final de estas.
void EjercicioOnce() {
	double pennies, nickels, dimes, quarters, halfDollars, sumatoria;
	cout << "Introduzca el numero de monedas de 1 centavo: ";
	cin >> pennies;
	cout << "Introduzca el numero de monedas de 5 centavos: ";
	cin >> nickels;
	cout << "Introduzca el numero de monedas de 10 centavos: ";
	cin >> dimes;
	cout << "Introduzca el numero de monedas de 25 centavos: ";
	cin >> quarters;
	cout << "Introduzca el numero de monedas de 50 centavos: ";
	cin >> halfDollars;

	cout << endl;

	if (pennies == 0) {
		cout << "No tienes monedas de 1 centavo." << endl;
	}
	else if (pennies == 1) {
		cout << "Tienes una moneda de 1 centavo." << endl;
	}
	else {
		cout << "Tienes " << pennies << " monedas de 1 centavo." << endl;
	}

	if (nickels == 0) {
		cout << "No tienes monedas de 5 centavos." << endl;
	}
	else if (nickels == 1) {
		cout << "Tienes una moneda de 5 centavos." << endl;
	}
	else {
		cout << "Tienes " << nickels << " monedas de 5 centavos." << endl;
	}

	if (dimes == 0) {
		cout << "No tienes monedas de 10 centavos." << endl;
	}
	else if (dimes == 1) {
		cout << "Tienes una moneda de 10 centavos." << endl;
	}
	else {
		cout << "Tienes " << dimes << " monedas de 10 centavos." << endl;
	}

	if (quarters == 0) {
		cout << "No tienes monedas de 25 centavos." << endl;
	}
	else if (quarters == 1) {
		cout << "Tienes una moneda de 25 centavos." << endl;
	}
	else {
		cout << "Tienes " << quarters << " monedas de 25 centavos." << endl;
	}

	if (halfDollars == 0) {
		cout << "No tienes monedas de 50 centavos." << endl;
	}
	else if (halfDollars == 1) {
		cout << "Tienes una moneda de 50 centavos." << endl;
	}
	else {
		cout << "Tienes " << halfDollars << " monedas de 50 centavos." << endl;
	}

	sumatoria = (pennies + (nickels * 5) + (dimes * 10) + (quarters * 25) + (halfDollars * 50)) / 100;
	cout << "Tienes $" << sumatoria << " dolares." << endl;
}
