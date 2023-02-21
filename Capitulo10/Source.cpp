#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include "CapituloDiez.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;
using std::cerr;
using std::sort;
using std::fstream;
using std::ifstream;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ios_base;
using std::ios;
using std::srand;
using std::rand;
using CapituloDiez::Roman_int;
using CapituloDiez::calculate;

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
const int not_a_month = -1;
const int not_a_reading = -1;
constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

struct Day {
	vector<double> hour{ vector<double>(24,not_a_reading) };
};

struct Month { //a month of temperature readings
		int month{ not_a_month }; //[0:11] January is 0
		vector<Day> day{ 32 }; //[1:31] one vector of readings per day
};

struct Year { //a year of temperature readings, organized by month
	int year; //positive == A.D.
	vector<Month> month{ 12 }; //[0:11] January is 0
};

struct Reading {
	int day;
	int hour;
	double temperature;
	char scale;
};

void skip_to_int(bool&, ifstream&);
void end_of_loop(istream& ist, char term, const string& message);
int month_to_int(string s);
string int_to_month(int i);
bool is_valid(const Reading& r);
void print_year(ostream& ost, const Year& y);
void print_month(ostream& ost, const Month& m);
void print_day(ostream& ost, const Day& d);
void ConcatenateFiles(ifstream& file1, ifstream& file2, ofstream& result);
void SortFileContents(ifstream& file1, ifstream& file2, ofstream& result);

void error(string);



istream& operator>>(istream& is, Reading& r);
istream& operator>>(istream& is, Month& m);
istream& operator>>(istream& is, Year& y);


vector<string> month_input_tbl = {
	"jan", "feb", "mar", "apr", "may", "jun", "jul",
	"aug", "sep", "oct", "nov", "dec"
};

vector<string> month_print_tbl = {
"January", "February", "March", "April", "May", "June", "July",
"August", "September", "October", "November", "December"
};

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
	EJERCICIO_ONCE
};

int main() {
	int eleccion = 0;
	bool salida = true;

	try {
		while (salida) {
			cout << "Introduzca el numero del ejercicio al que desea acceder (1-18). Introduzca cualquier otro numero para salir." << endl;

			cin.clear();
			cin >> eleccion;
			if (cin.fail()) {
				error("No se introdujo un numero entero.");
			}

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

//Ejercicio que hace la sumatoria de todos los numeros dentro de un archivo de texto.
void EjercicioUno() {
	string filename = "EjercicioUnoSuma.txt";
	ifstream ifs{ filename };
	if (!ifs) {
		error("No se pudo abrir el archivo de entrada.");
	}

	int sumatoria = 0;
	int n = 0;
	bool salida = true;
	while (salida) {
		if (ifs >> n) {
			sumatoria += n;
		}
		skip_to_int(salida, ifs);
	}

	cout << "La sumatoria de los enteros en el archivo es: " << sumatoria << endl;
}

//Ejercicio que agrega sets de temperaturas al archivo raw_temps.txt ocupando la estructura Reading.
void EjercicioDos() {
	srand(time(NULL));

	string filename = "raw_temps.txt";
	ofstream ofs{ filename };
	if (!ofs) {
		error("No se pudo abrir el archivo de salida.");
	}

	vector<Reading> readingList;
	Reading r;
	for (int i = 0; i < 50; i++) {
		double random = (float)rand() / RAND_MAX;
		r.day = 1 + rand() / (RAND_MAX / (31 - 1 + 1) + 1);
		r.hour = 1 + rand() / (RAND_MAX / (24 - 1 + 1) + 1);
		r.temperature = -30 + rand() / (RAND_MAX / (50 - -30 + 1) + 1);
		if (random < .5) {
			r.scale = 'c';
		}
		else {
			r.scale = 'f';
		}

		readingList.push_back(r);
	}

	for (Reading r1 : readingList) {
		ofs << '(' << r1.day << ' ' << r1.hour << ' ' << r1.temperature << ' ' << r1.scale << ' ' << ')' << endl;
	}
	cout << "Se han impreso las temperaturas satisfactoriamente. Revisar el archivo raw_temps.txt" << endl;
}

//Ejercicio que lee las temperaturas del archivo raw_temps.txt, y calcula el promedio y la media de estas temperaturas.
void EjercicioTres() {
	string filename = "raw_temps.txt";
	ifstream ifs{ filename };
	if (!ifs) {
		error("No se pudo abrir el archivo de salida.");
	}

	vector<double> readingList;
	double sumatoria = 0;
	double promedio = 0;
	double media = 0;

	for (Reading r; ifs >> r;) {
		readingList.push_back(r.temperature);
		sumatoria += r.temperature;
	}

	sort(readingList.begin(), readingList.end());
	promedio = sumatoria / readingList.size();
	if (readingList.size() % 2 == 1) {
		media = readingList[readingList.size() / 2];
	}
	else {
		media = readingList[(readingList.size() / 2) - 1] + readingList[readingList.size() / 2];
	}

	cout << "El promedio de las temperaturas de raw_temps.txt es: " << promedio << endl;
	cout << "La media de las temperaturas de raw_temps.txt es: " << media << endl;
}

//Modificación del ejercicio anterior, pero modificando el struct Reading para especificar si se trata de temperaturas en grados celsius o fahrenheit,
//convirtiendo las temperaturas celsius en fahrenheit para el cálculo del promedio y la media.
void EjercicioCuatro() {
	string filename = "raw_temps.txt";
	ifstream ifs{ filename };
	if (!ifs) {
		error("No se pudo abrir el archivo de salida.");
	}

	vector<double> readingList;
	double sumatoria = 0;
	double promedio = 0;
	double media = 0;
	double tempf = 0;

	for (Reading r; ifs >> r;) {
		if (r.scale = 'f') {
			readingList.push_back(r.temperature);
		}
		else if (r.scale = 'c') {
			tempf = (r.temperature * (9 / 5)) + 32;
			readingList.push_back(tempf);
		}
		
		sumatoria += r.temperature;
	}

	sort(readingList.begin(), readingList.end());
	promedio = sumatoria / readingList.size();
	if (readingList.size() % 2 == 1) {
		media = readingList[readingList.size() / 2];
	}
	else {
		media = readingList[(readingList.size() / 2) - 1] + readingList[readingList.size() / 2];
	}

	cout << "El promedio de las temperaturas de raw_temps.txt es: " << promedio << endl;
	cout << "La media de las temperaturas de raw_temps.txt es: " << media << endl;
}

//Ejercicio que lee un con un set de datos de lecturas de temperaturas, y lo imprime en el archivo EjercicioCincoOutput.txt, asignándole un formato
//para hacerlo más legible.
void EjercicioCinco() {
	bool salida = true;
	//open an input file:
	string iname = "EjercicioCincoInput.txt";
	ifstream ifs{ iname };
	if (!ifs) {
		error("can’t open input file");
	}
	ifs.exceptions(ifs.exceptions() | ios_base::badbit); //throw for bad()

	//open an output file :

	string oname = "EjercicioCincoOutput.txt";
	ofstream ofs{ oname };
	if (!ofs) {
		error("can’t open output file");
	}
	//read an arbitrary number of years :
	vector<Year> ys;
	while (salida) {
		Year y; //get a freshly initialized Year each time around
		if (!(ifs >> y)) break;
		ys.push_back(y);
	}
	cout << "read " << ys.size() << " years of readings\n";
	for (Year& y : ys) {
		print_year(ofs, y);
	}
}

//Ejercicio que crea una clase llamada Roman_int, que representa numeros romanos. Además añade funciones para la conversión numeros
//arabigos y romanos.
//La implementación se encuentra en CapituloDiez.h y CapituloDiez.cpp.
void EjercicioSeis() {
	Roman_int test;
	test.SetNumber("MDCCCXL");
	cout << "Roman" << test.GetNumber() << " as int: " << test.as_int() << endl;
}

//Ejercicio que añade el uso de la clase Roman_int a la calculadora del capítulo 7, recibiendo una entrada y salida de numeros romanos.
//La implementación se encuentra en CapituloDiez.h y CapituloDiez.cpp.
void EjercicioSiete() {
	calculate();
}

//Este ejercicio obtiene la información de dos archivos diferentes y los concatena en un tercer archivo.
//Al ejecutar este ejercicio, el resultado de este se puede apreciar en el archivo "EjercicioOchoOutput.txt".
void EjercicioOcho() {
	ifstream file1{ "EjercicioOchoFile1.txt" };
	ifstream file2{ "EjercicioOchoFile2.txt" };
	ofstream result{ "EjercicioOchoOutput.txt" };

	if (!file1 || !file2 || !result) {
		error("No se pudo abrir uno de los archivos.");
	}

	ConcatenateFiles(file1, file2, result);
	cout << "Se han concatenado ambos archivos satisfactoriamente!" << endl;
}

//Este ejercicio obtiene la información de dos archivos diferentes y mantiene la organización de las palabras, juntándolas en un mismo archivo.
//Al ejecutar este ejercicio, el resultado de este se puede apreciar en el archivo "EjercicioNueveInput.txt".
void EjercicioNueve() {
	ifstream file1{ "EjercicioNueveFile1.txt" };
	ifstream file2{ "EjercicioNueveFile2.txt" };
	ofstream result{ "EjercicioNueveOutput.txt" };

	if (!file1 || !file2 || !result) {
		error("No se pudo abrir uno de los archivos.");
	}

	SortFileContents(file1, file2, result);
	cout << "Se han concatenado ambos archivos satisfactoriamente!" << endl;
}

//Este ejercicio por más que traté, se volvió imposible implementarlo sin modificar completamente la calculadora.
void EjercicioDiez() {

}

//Ejercicio que da la suma de todos los enteros separados por un espacio en un archivo de texto. Es el mismo que el de la actividad 1
//debido a que funcionan igual.
void EjercicioOnce() {
	string filename = "EjercicioUnoSuma.txt";
	ifstream ifs{ filename };
	if (!ifs) {
		error("No se pudo abrir el archivo de entrada.");
	}

	int sumatoria = 0;
	int n = 0;
	bool salida = true;
	while (salida) {
		if (ifs >> n) {
			sumatoria += n;
		}
		skip_to_int(salida, ifs);
	}

	cout << "La sumatoria de los enteros en el archivo es: " << sumatoria << endl;
}

/*
----------------------------------------
FUNCIONES OCUPADAS POR LOS EJERCICIOS
----------------------------------------
*/

//Función utilizada por los ejercicios 1 y 11. Modificación de una función del libro para seguir buscando enteros en caso de haber algún elemento
//desconocido en el archivo.
void skip_to_int(bool& salida, ifstream& ifs) {
	if (ifs.fail()) { //we found something that wasn’t an integer
			ifs.clear(); //we’d like to look at the characters
			for (char ch; ifs >> ch; ) { //throw away non - digits
					if (isdigit(ch) || ch == '-') {
						ifs.unget(); //put the digit back,
							//so that we can read the number
							return;
					}
			}
	}
	if (ifs.eof()) {
		salida = false;
	}
	if (ifs.bad()) {
		error("Hubo un error durante la lectura del archivo.");
	}
}

//Función ocupada por el ejercicio 5. Limpia el estado del stream y termina la lectura.
void end_of_loop(istream& ist, char term, const string& message)
{
	if (ist.fail()) { //use term as terminatorand /or separator
		ist.clear();
		char ch;
		if (ist >> ch && ch == term) return; //all is fine
			//error(message);
	}
}

//Función ocupada por el ejercicio 5. Verifica que las lecturas registradas por un objeto de clase Reading tengan valores válidos.
bool is_valid(const Reading& r)
//a rough test
{
	if (r.day < 1 || 31 < r.day) return false;
	if (r.hour < 0 || 23 < r.hour) return false;
	if (r.temperature < implausible_min || implausible_max < r.temperature)
		return false;
	return true;
}

//Función ocupada por el ejercicio 5. Convierte el nombre de un mes en su valor numérico.
int month_to_int(string s)
//is s the name of a month ? If so return its index[0:11] otherwise -1
{
	for (int i = 0; i < 12; ++i) if (month_input_tbl[i] == s) return i;
	return -1;
}

//Función ocupada por la actividad 5. Convierte la representación en entero de un número en su palabra correspondiente.
string int_to_month(int i)
//months[0:11]
{
if (i < 0 || 12 <= i) error("bad month index");
return month_print_tbl[i];
}

//Función ocupada por la actividad 5. Procesa todos los años registrados en el archivo EjercicioCincoInput.txt y los imprime en el archivo
//EjercicioCincoOutput.txt.
void print_year(ostream& ost, const Year& y) {
	ost << "Year " << y.year << ':' << endl;
	for (int i = 0; i < 12; i++) {
		print_month(ost, y.month[i]);
	}
}

//Función ocupada por la actividad 5. Procesa todos los meses registrados en el archivo EjercicioCincoInput.txt y los imprime en el archivo
//EjercicioCincoOutput.txt.
void print_month(ostream& ost, const Month& m) {
	if (m.month != not_a_month) {
		ost << "\tMonth " << int_to_month(m.month) << ':' << endl;
		for (int i = 0; i < 31; i++) {
			print_day(ost, m.day[i]);
		}
	}
}

//Función ocupada por la actividad 5. Procesa todos los días con lecturas registrados en el archivo EjercicioCincoInput.txt y los imprime en el archivo
//EjercicioCincoOutput.txt.
void print_day(ostream& ost, const Day& d) {
	for (int i = 0; i < 24; i++) {
		if (d.hour[i] != not_a_reading) {
			ost << "\t\tReading " << i << ":00 = " << d.hour[i] << endl;
		}
	}
}

//Función utilizada por el ejercicio 8. Recibe dos archivos y los junta en un tercer archivo.
void ConcatenateFiles(ifstream& file1, ifstream& file2, ofstream& result) {
	vector<string> concat;
	string line;
	while (getline(file1, line)) {
		concat.push_back(line);
	}

	while (getline(file2, line)) {
		concat.push_back(line);
	}
	
	for (string s : concat) {
		result << s << endl;
	}
}

//Función utilizada por el ejercicio 9. Recibe dos archivos que contengan palabras ordenadas y los junta en un tercer archivo, manteniendo
//el orden.
void SortFileContents(ifstream& file1, ifstream& file2, ofstream& result) {
	bool salida = true;
	int contador = 0;
	vector<string> file1Words;
	vector<string> file2Words;
	string word = "";

	while (file1 >> word) {
		file1Words.push_back(word);
	}

	while (file2 >> word) {
		file2Words.push_back(word);
	}

	if (file1Words.size() < file2Words.size()) {
		for (int i = 0; i < file1Words.size(); i++) {
			if (file1Words[i] <= file2Words[i]) {
				result << file1Words[i] << ' ';
				result << file2Words[i] << ' ';
				contador++;
			}
			else {
				result << file2Words[i] << ' ';
				result << file1Words[i] << ' ';
				contador++;
			}
		}
		while (contador < file2Words.size()) {
			cout << contador << endl;
			result << file2Words[contador] << ' ';
			contador++;
		}
	}
	else {
		for (int i = 0; i < file2Words.size(); i++) {
			if (file1Words[i] <= file2Words[i]) {
				result << file1Words[i] << ' ';
				result << file2Words[i] << ' ';
				contador++;
			}
			else {
				result << file2Words[i] << ' ';
				result << file1Words[i] << ' ';
				contador++;
			}
		}
		while (contador < file1Words.size()) {
			cout << contador << endl;
			result << file2Words[contador] << ' ';
			contador++;
		}
	}
}

//Función para arrojar errores.
void error(string s) {
	throw runtime_error(s);
}

/*
----------------------------------------
SOBRECARGAS DE OPERADORES
----------------------------------------
*/

//Función utilizada por los ejercicios 2 a 5. Verifica y asigna la información de un archivo de texto a un objeto de tipo Reading si tiene el
//formato correcto.
istream& operator>>(istream& is, Reading& r)
//read a temperature reading from is into r
//format : (3 4 9.7)
//check format, but don’t bother with data validity
{ 
	char ch1;
	if (is >> ch1 && ch1 != '(') { //could it be a Reading ?
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	char ch2;
	int d;
	int h;
	double t;
	char s;
	is >> d >> h >> t >> s >> ch2;

	if (!is || ch2 != ')') {
		//error("bad reading"); //messed - up reading
	}
	r.day = d;
	r.hour = h;
	r.temperature = t;
	r.scale == s;
	return is;
	}

//Función utilizada por el ejercicio 5. Verifica y asigna la información de un archivo de texto a un objeto de tipo Month si tiene el
//formato correcto.
istream& operator>>(istream& is, Month& m)
//read a month from is into m
//format : { month feb . . . }
{
	char ch = 0;
	if (is >> ch && ch != '{') {
		is.unget();
		is.clear(ios_base::failbit); //we failed to read a Month
		return is;
	}
	string month_marker;
	string mm;
	is >> month_marker >> mm;
	if (!is || month_marker != "month") error("bad start of month");
	m.month = month_to_int(mm);
	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is >> r; ) {
		if (is_valid(r)) {
			if (m.day[r.day].hour[r.hour] != not_a_reading)
				++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else {
			++invalids;
		}
	}

	if (invalids) {
		error("invalid readings in month");
	}
	if (duplicates) {
		error("duplicate readings in month");
	}
	end_of_loop(is, '}', "bad end of month");
	return is;
}

//Función utilizada por el ejercicio 5. Verifica y asigna la información de un archivo de texto a un objeto de tipo Year si tiene el
//formato correcto.
istream& operator>>(istream& is, Year& y)
//read a year from is into y
//format : { year 1972 . . . }
{
	bool salida = true;
	char ch;
	is >> ch;
	if (ch != '{') {
		is.unget();
		is.clear(ios::failbit);
		return is;
	}
	string year_marker;
	int yy;
	is >> year_marker >> yy;
	if (!is || year_marker != "year") error("bad start of year");
	y.year = yy;
	while (salida) {
		Month m; //get a clean m each time around
		if (!(is >> m)) break;
		y.month[m.month] = m;
	}
	end_of_loop(is,'}', "bad end of year");
	return is;
	}