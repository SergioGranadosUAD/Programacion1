#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;
using std::invalid_argument;
using std::cerr;
using std::sort;
using std::fstream;
using std::ifstream;
using std::istream;
using std::ostream;
using std::istringstream;
using std::ostringstream;
using std::ofstream;
using std::ios_base;
using std::ios;

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

void EvaluateChar(char c);
void EvaluateCharCount(char c, vector<int>& contador);
void ToWhitespace(string& input, string whitespace);
void ToLower(string& input);
void ReplaceApostrophe(string& input);
void TextToBinary(string inputFileName, string outputFileName);
void BinaryToText(string inputFileName, string outputFileName);
vector<string> split(const string& s);
vector<string> split(const string& s, const string& w);

//Template implementada de std_lib_facilites, no intenté replicarla puesto que todavía no entiendo cómo funcionan los templates,
//pero era necesario para aprender la forma de dar entrada y salida en binario.
template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
	// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}

void error(string);

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
	EJERCICIO_CATORCE,
	EJERCICIO_QUINCE,
	EJERCICIO_DIECISEIS
};

int main() {
	int eleccion = 0;
	bool salida = true;

	try {
		while (salida) {
			cout << "Introduzca el numero del ejercicio al que desea acceder (1-16). Introduzca cualquier otro numero para salir." << endl;

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
			case ejercicios::EJERCICIO_QUINCE:
				EjercicioQuince();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_DIECISEIS:
				EjercicioDieciseis();
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
	catch (invalid_argument& e) {
		cerr << e.what() << endl;
	}
}

//Ejercicio que lee un archivo y convierte su texto en minúsculas, imprimiéndolo en otro archivo.
void EjercicioUno() {
	string inputFileName = "EjercicioUnoInput.txt";
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	string outputFileName = "EjercicioUnoOutput.txt";
	ofstream outputFile{ outputFileName };
	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	string line = "";
	while (getline(inputFile, line)) {
		for (char c : line) {
			outputFile << char(tolower(c));
		}
		outputFile << endl;
	}
	cout << "Se han impreso los cambios a 'EjercicioUnoOutput.txt' satisfactoriamente!" << endl;
}

//Ejercicio que lee un archivo y e imprime las líneas en las que se encuentre una palabra determinada por el usuario.
void EjercicioDos() {
	string inputFileName = "EjercicioUnoInput.txt";
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	int index = 1;
	string findWord = "";
	string streamWord = "";
	bool found = false;
	cout << "Introduzca la palabra que desea buscar en el archivo EjercicioUnoInput.txt." << endl;
	cin >> findWord;

	string line = "";
	while (getline(inputFile, line)) {
		found = false;
		istringstream stringStream(line);
		while (stringStream) {
			stringStream >> streamWord;
			if (findWord == streamWord) {
				found = true;
			}
		}

		if (found) {
			cout << "line " << index << ":\t" << line << endl;
		}
		index++;
	}
}

//Ejercicio que lee un archivo, le quita las vocales que se encuentren en el texto e imprime el resultado en otro archivo.
void EjercicioTres() {
	string inputFileName = "EjercicioUnoInput.txt";
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	string outputFileName = "EjercicioTresOutput.txt";
	ofstream outputFile{ outputFileName };
	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	string line = "";
	string vowels = "aAeEiIoOuU";
	while (getline(inputFile, line)) {
		for (char c : vowels) {
			line.erase(remove(line.begin(), line.end(), c), line.end());
			
		}
		outputFile << line << endl;
	}
	cout << "Se han impreso los cambios a 'EjercicioTresOutput.txt' satisfactoriamente!" << endl;
}

//Ejercicio que le pide al usuario numeros en hexadecimal, octal y decimal, e imprime su conversión a decimal.
void EjercicioCuatro() {
	string numero = "";

	cout << "Introduzca los numeros que desee en octal, decimal o hexadecimal separados por espacios. Introduzca Ctrl+Z para terminar." << endl;
	while (cin >> numero) {
		if (cin.fail()) {
			error("Hubo un error al introducir datos.");
		}
		if (numero[0] == '0' && numero[1] == 'x') {
			cout << numero << "\thexadecimal\t converts to\t" << stoi(numero, 0, 16) << "\tdecimal" << endl;
		}
		else if (numero[0] == '0') {
			cout << numero << "\toctal\t converts to\t" << stoi(numero, 0, 8) << "\tdecimal" << endl;
		}
		else {
			cout << numero << "\tdecimal\t converts to\t" << stoi(numero, 0, 10) << "\tdecimal" << endl;
		}
	}
}

//Ejercicio que lee un string y devuelve todas las clasificaciones a las que pertenecen los caracteres de este.
void EjercicioCinco() {
	string str = "";
	
	cout << "Introduzca un string que desea evaluar. Introduzca Ctrl+Z para terminar." << endl;
	while (cin >> str) {
		if (cin.fail()) {
			error("Hubo un error al introducir datos.");
		}
		cout << "Clasificacion de los caracteres de " << str << "." << endl;
		for (char c : str) {
			cout << "caracter '" << c << "': ";
			EvaluateChar(c);
			cout << endl;
		}
	}
}

//Este ejercicio lee un archivo y filtra los simbolos de este, e imprime el resultado en otro archivo.
//También se agregaron las funciones de el ejercicio siguiente.
void EjercicioSeis() {
	string inputFileName = "EjercicioUnoInput.txt";
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	string outputFileName = "EjercicioSeisOutput.txt";
	ofstream outputFile{ outputFileName };
	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	string line = "";
	while (getline(inputFile, line)) {
		ReplaceApostrophe(line);
		ToLower(line);
		ToWhitespace(line, ".;,?-'");
		outputFile << line << endl;
	}
}

//Este ejercicio le añadio al anterior la capacidad de filtrar apostrofes y convertir el texto en minusculas, ocupando las funciones
//ReplaceApostrophe() y ToLower(), respectivamente.
void EjercicioSiete() {

}

//Este ejercicio ocupa el ejercicio seis para crear un diccionario de palabras ordenadas que no se repitan y lo imprime en otro archivo.
void EjercicioOcho() {
	string inputFileName = "EjercicioUnoInput.txt";
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	string outputFileName = "EjercicioOchoOutput.txt";
	ofstream outputFile{ outputFileName };
	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	vector<string> fileWords;
	string lineWord;
	string line = "";
	while (getline(inputFile, line)) {
		ReplaceApostrophe(line);
		ToLower(line);
		ToWhitespace(line, ".;,?-'");
		
		istringstream stringStream(line);
		while (stringStream >> lineWord) {
			fileWords.push_back(lineWord);
		}
	}

	sort(fileWords.begin(), fileWords.end());
	fileWords.erase(std::unique(fileWords.begin(), fileWords.end()), fileWords.end());

	for (string s : fileWords) {
		outputFile << s << endl;
	}
	cout << "Se ha impreso satisfactoriamente el diccionario en EjercicioOchoOutput.txt." << endl;
}

//Ejercicio que lee un archivo y lo convierte en binario y viceversa ocupando dos funciones separadas.
void EjercicioNueve(){
	int seleccion;
	string inputFileTTB = "EjercicioUnoInput.txt";
	string outputFileTTB = "EjercicioNueveTextToBinary.txt";
	string inputFileBTT = "EjercicioNueveInputBinary.txt";
	string outputFileBTT = "EjercicioNueveBinaryToText.txt";
	cout << "Introduzca 1 para convertir un archivo de texto a binario." << endl;
	cout << "Introduzca 2 para convertir un archivo binario a texto." << endl;
	cin >> seleccion;
	if (cin.fail()) {
		error("No se introdujo un numero entero.");
	}
	switch (seleccion) {
	case 1:
		TextToBinary(inputFileTTB, outputFileTTB);
		break;
	case 2:
		BinaryToText(inputFileBTT, outputFileBTT);
		break;
	default:
		error("No se introdujo un numero valido.");
	}
}

//Este ejercicio crea la función split() que regresa un vector de substrings separados por un espacio.
void EjercicioDiez() {
	vector<string> test = split("Esta es una prueba y por lo tanto todas estas palabras deben estar separadas.");
	for (string s : test) {
		cout << s << endl;
	}
}

//Este ejercicio sobrecarga la función split(), convirtiendo caracteres delimitados en espacios, y regresando un vector de substrings que se
//encuentran separados por espacios.
void EjercicioOnce() {
	vector<string> test = split("Es'ta es una prue,ba y por lo tanto tod.as estas palabras de'ben estar sep,arad.as.", ",'.");
	for (string s : test) {
		cout << s << endl;
	}
}

//Este ejercicio lee un archivo e imprime el orden de todos los caracteres al revés por línea en otro archivo.
void EjercicioDoce() {
	string inputFileName = "EjercicioUnoInput.txt";
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	string outputFileName = "EjercicioDoceOutput.txt";
	ofstream outputFile{ outputFileName };
	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	string line = "";
	while (getline(inputFile, line)) {
		for (int i = line.size()-1; i > 0; i--) {
			outputFile << line[i];
		}
		outputFile << endl;
	}
	cout << "Se han impreso los cambios a 'EjercicioDoceOutput.txt' satisfactoriamente!" << endl;
}

//Este ejercicio lee un archivo e imprime el orden de las palabras por línea al revés en otro archivo.
void EjercicioTrece() {
	string inputFileName = "EjercicioUnoInput.txt";
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	string outputFileName = "EjercicioTreceOutput.txt";
	ofstream outputFile{ outputFileName };
	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	string streamWord = "";

	string line = "";
	while (getline(inputFile, line)) {
		vector<string> lineWords;
		istringstream stringStream(line);
		while (stringStream >> streamWord) {
			lineWords.push_back(streamWord);
		}

		for (int i = lineWords.size() - 1; i >= 0; i--) {
			outputFile << lineWords[i] << " ";
		}
		outputFile << endl;
	}
	cout << "Se han impreso los cambios a 'EjercicioTreceOutput.txt' satisfactoriamente!" << endl;
}

//Este ejercicio lee un archivo y regresa la clasificación de todos los caracteres dentro de este.
void EjercicioCatorce() {
	string inputFileName = "EjercicioUnoInput.txt";
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	string line = "";
	vector<int> contadores(11, 0);
	while (getline(inputFile, line)) {
		for (char c : line) {
			EvaluateCharCount(c, contadores);
		}
	}

	cout << "Conteo de clasificaciones de caracteres en el archivo: " << endl;
	cout << "isspace: " << contadores[0] << endl;
	cout << "isalpha: " << contadores[1] << endl;
	cout << "isdigit: " << contadores[2] << endl;
	cout << "isxdigit: " << contadores[3] << endl;
	cout << "isupper: " << contadores[4] << endl;
	cout << "islower: " << contadores[5] << endl;
	cout << "isalnum: " << contadores[6] << endl;
	cout << "iscntrl: " << contadores[7] << endl;
	cout << "ispunct: " << contadores[8] << endl;
	cout << "isprint: " << contadores[9] << endl;
	cout << "isgraph: " << contadores[10] << endl;
}

//Este ejercicio lee un archivo e imprime los numeros en notación científica aplicando un formato establecido, y lo imprime en otro archivo.
void EjercicioQuince(){
	string inputFileName = "EjercicioQuinceInput.txt";
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	string outputFileName = "EjercicioQuinceOutput.txt";
	ofstream outputFile{ outputFileName };
	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	int index = 0;
	double number = 0;
	vector<double> numberList;
	while (inputFile >> number) {
		if (inputFile.fail()) {
			error("Uno de los elementos en el archivo no es numerico.");
		}
		numberList.push_back(number);
	}

	outputFile << std::scientific << std::setprecision(8);
	for (double d : numberList) {
		outputFile << d << "\t";
		index++;
		if (index == 4) {
			outputFile << endl;
			index = 0;
		}
	}
	cout << "Se han impreso los cambios a 'EjercicioQuinceOutput.txt' satisfactoriamente!" << endl;
}

//Este ejercicio lee un archivo e imprime los numeros de forma ordenada, junto con las veces que se repitieron.
void EjercicioDieciseis() {
	string inputFileName = "EjercicioQuinceInput.txt";
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	string outputFileName = "EjercicioDieciseisOutput.txt";
	ofstream outputFile{ outputFileName };
	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	double number = 0;
	vector<double> numberList;
	
	while (inputFile >> number) {
		if (inputFile.fail()) {
			error("Uno de los elementos en el archivo no es numerico.");
		}
		numberList.push_back(number);
	}
	sort(numberList.begin(), numberList.end());

	vector<int> counter(numberList.size(), 1);

	for (int i = 0; i < numberList.size() - 1; i++) {
		if (numberList[i] == numberList[i + 1]) {
			numberList.erase(numberList.begin() + i);
			counter.erase(counter.begin() + i);
			counter[i]++;
			i--;
		}
	}

	for (int i = 0; i < numberList.size(); i++) {
		outputFile << numberList[i];
		if (counter[i] > 1) {
			outputFile << "\t\t" << counter[i];
		}
		outputFile << endl;
	}
}

/*
FUNCIONES OCUPADAS POR LOS EJERCICIOS
*/

//Funcion que imprime todas las clasificaciones que tiene un caracter.
void EvaluateChar(char c) {
	if (isspace(c)) {
		cout << "isspace ";
	}
	if (isalpha(c)) {
		cout << "isalpha ";
	}
	if (isdigit(c)) {
		cout << "isdigit ";
	}
	if (isxdigit(c)) {
		cout << "isxdigit ";
	}
	if (isupper(c)) {
		cout << "isupper ";
	}
	if (islower(c)) {
		cout << "islower ";
	}
	if (isalnum(c)) {
		cout << "isalnum ";
	}
	if (iscntrl(c)) {
		cout << "iscntrl ";
	}
	if (ispunct(c)) {
		cout << "ispunct ";
	}
	if (isprint(c)) {
		cout << "isprint ";
	}
	if (isgraph(c)) {
		cout << "isgraph ";
	}
}

//Función que toma la referencia de contadores de un vector y suma las veces que se detecten las clasificaciones de estos.
void EvaluateCharCount(char c, vector<int>& contador) {
	if (isspace(c)) {
		contador[0]++;
	}
	if (isalpha(c)) {
		contador[1]++;
	}
	if (isdigit(c)) {
		contador[2]++;
	}
	if (isxdigit(c)) {
		contador[3]++;
	}
	if (isupper(c)) {
		contador[4]++;
	}
	if (islower(c)) {
		contador[5]++;
	}
	if (isalnum(c)) {
		contador[6]++;
	}
	if (iscntrl(c)) {
		contador[7]++;
	}
	if (ispunct(c)) {
		contador[8]++;
	}
	if (isprint(c)) {
		contador[9]++;
	}
	if (isgraph(c)) {
		contador[10]++;
	}
}

//Función que recibe un string y convierte todos los caracteres marcados en espacios vacios.
void ToWhitespace(string& input, string whitespace) {
	for (char c : whitespace) {
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == c) {
				input[i] = ' ';
			}
		}
	}
}

//Funcion que recibe un string y lo convierte a minusculas.
void ToLower(string& input) {
	for (char& c : input) {
		c = tolower(c);
	}
}

//Funcion que recibe un string y reemplaza palabras que lleven apostrofes por su version completa.
void ReplaceApostrophe(string& input) {
	string result;
	string stringWord;
	istringstream stringStream(input);
	while (stringStream >> stringWord) {
		if (stringWord == "don't") {
			stringWord = "do not";
		}
		else if (stringWord == "can't") {
			stringWord = "cannot";
		}
		else if (stringWord == "it's") {
			stringWord = "it is";
		}
		else if (stringWord == "i'm") {
			stringWord = "i am";
		}
		else if (stringWord == "you're") {
			stringWord = "you are";
		}
		result += stringWord + " ";
	}
	input = result;
}

//Funcion que lee un archivo de texto, lo convierte a binario y lo imprime en otro archivo.
void TextToBinary(string inputFileName, string outputFileName) {
	ifstream inputFile{ inputFileName };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	ofstream outputFile{ outputFileName, ios_base::binary };
	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	char c;
	while (inputFile.get(c)) {
		outputFile.write(as_bytes(c), sizeof(char));
	}
}

//Funcion que lee un archivo de texto binario, lo convierte a texto y lo imprime en otro archivo.
void BinaryToText(string inputFileName, string outputFileName) {
	ifstream inputFile{ inputFileName, ios_base:: binary };
	if (!inputFile) {
		error("No se pudo abrir el archivo de entrada.");
	}

	ofstream outputFile{ outputFileName };
	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	char c;
	while (inputFile.read(as_bytes(c), sizeof(char))) {
		outputFile << c;
	}
}

//Funcion que devuelve vector de strings a partir de un string de multiples palabras.
vector<string> split(const string& s) {
	vector<string> result;
	string stringWord;
	istringstream stringStream(s);
	while (stringStream >> stringWord) {
		result.push_back(stringWord);
	}

	return result;
}

//Sobrecarga de split() que acepta un string extra que delimita caracteres que se convertiran en espacios.
vector<string> split(const string& s, const string& w) {
	string input = s;
	ToWhitespace(input, w);
	vector<string> result;
	string stringWord;
	istringstream stringStream(input);
	while (stringStream >> stringWord) {
		result.push_back(stringWord);
	}

	return result;
}

void error(string s) {
	throw runtime_error(s);
}