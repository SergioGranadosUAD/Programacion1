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

//Estructura que contiene el nombre, la calificacion y el grupo al que pertenece un alumno.
struct Alumno {
	string nombre;
	double calificacion;
	string grupo;
};

//Estructura que contiene todos los alumnos que pertenecen a un mismo grupo, así como el nombre de este.
struct Grupo {
	string nombreGrupo;
	vector<Alumno> alumnos;
};

void OrdenarAlfanumerico(ifstream& inputFile);
void OrdenarPromedio(ifstream& inputFile);
void AgregarAlumno();
vector<Grupo> LeerLista(ifstream& inputFile);

void error(string s);

enum opciones {
	ORDENAR_ALFA = 1,
	ORDENAR_PROMEDIO,
	AGREGAR_ALUMNO,
};

int main() {

	int eleccion = 0;
	bool salida = true;

	try {
		string inputFileName = "alumnos.txt";
		ifstream inputFile{ inputFileName };
		if (!inputFile) {
			error("No se pudo abrir el archivo de entrada.");
		}

		while (salida) {
			cout << "Introduzca la accion que desea realizar. Introduzca cualquier otro valor para terminar el programa." << endl;
			cout << "'1' para ordenar los alumnos por grupo alfabeticamente." << endl;
			cout << "'2' para ordenar los alumnos por grupo en base a su promedio." << endl;
			cout << "'3' para agregar un nuevo alumno a la lista." << endl;

			cin.clear();
			cin >> eleccion;
			if (cin.fail()) {
				error("No se introdujo un numero entero.");
			}

			cout << endl;

			switch (eleccion) {
			case opciones::ORDENAR_ALFA:
				OrdenarAlfanumerico(inputFile);
				cout << endl << "Se han impreso los grupos de alumnos ordenados por nombre!." << endl << endl;
				break;
			case opciones::ORDENAR_PROMEDIO:
				OrdenarPromedio(inputFile);
				cout << endl << "Se han impreso los grupos de alumnos ordenados por calificacion!." << endl << endl;
				break;
			case opciones::AGREGAR_ALUMNO:
				AgregarAlumno();
				cout << endl << "Se ha agregado un alumno satisfactoriamente." << endl << endl;
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

//Esta función ordena los grupos de alumnos de forma alfanumérica e imprime los grupos ordenados en archivos diferentes.
void OrdenarAlfanumerico(ifstream& inputFile) {
	//Se obtiene la lista de grupos existentes.
	vector<Grupo> listaGrupos = LeerLista(inputFile);

	//Se itera a través de estos grupos.
	for (Grupo grupo : listaGrupos) {
		//Se crea un archivo con el nombre del grupo actual.
		string nombreSalida = grupo.nombreGrupo + ".txt";
		ofstream outputFile{ nombreSalida };

		//Se ordena la lista de alumnos dentro de ese grupo, ocupando una función lambda como comparador para evaluar los nombres de los alumnos.
		sort(grupo.alumnos.begin(), grupo.alumnos.end(), [](const Alumno& primer, const Alumno& segundo) {
			return primer.nombre < segundo.nombre;
			});

		//Se imprimen los datos de cada uno de los alumnos que forman parte de este grupo en el archivo.
		for (Alumno alumno : grupo.alumnos) {
			outputFile << alumno.nombre << " " << alumno.calificacion << " " << alumno.grupo << endl;
		}
	}
}

//Esta función ordena los grupos de alumnos por calificación e imprime los grupos ordenados en archivos diferentes.
void OrdenarPromedio(ifstream& inputFile) {
	//Se obtiene la lista de grupos existentes.
	vector<Grupo> listaGrupos = LeerLista(inputFile);

	//Se itera a través de estos grupos.
	for (Grupo grupo : listaGrupos) {
		//Se crea un archivo con el nombre del grupo actual.
		string nombreSalida = grupo.nombreGrupo + ".txt";
		ofstream outputFile{ nombreSalida };

		//Se ordena la lista de alumnos dentro de ese grupo, ocupando una función lambda como comparador para evaluar los nombres de los alumnos.
		sort(grupo.alumnos.begin(), grupo.alumnos.end(), [](const Alumno& primer, const Alumno& segundo) {
			return primer.calificacion > segundo.calificacion;
			});

		//Se imprimen los datos de cada uno de los alumnos que forman parte de este grupo en el archivo.
		for (Alumno alumno : grupo.alumnos) {
			outputFile << alumno.nombre << " " << alumno.calificacion << " " << alumno.grupo << endl;
		}
	}
}

//Esta función agrega un alumno nuevo al archivo que contiene los alumnos.
void AgregarAlumno() {
	//Se crea un stream de salida ocupando las banderas de append y nocreate, para asegurarse que no se sobreescriba la información ya existente en el archivo.
	string nombreSalida = "alumnos.txt";
	ofstream outputFile{ nombreSalida, ios_base::app | ios_base::_Nocreate };

	if (!outputFile) {
		error("No se pudo abrir el archivo de salida.");
	}

	string nombre = "";
	double calificacion = 0;
	string grupo = "";
	
	//Se le pide al usuario introducir los datos del alumno.
	cout << "Introduzca el nombre del alumno: " << endl;
	cin >> nombre;

	cout << "Introduzca la calificacion del alumno: " << endl;
	cin >> calificacion;

	//Se verifica que la calificacion introducida sea valida y esté en el rango apropiado entre 0 y 10.
	if (cin.fail()) {
		error("No se introdujo un valor numerico.");
	}
	else if (calificacion < 0 || calificacion > 10) {
		error("La calificacion introducida no esta dentro del rango apropiado.");
	}

	cout << "Introduzca el grupo al que pertenece el alumno: " << endl;
	cin >> grupo;

	//Se imprimen los datos del alumno en el archivo.
	outputFile << nombre << " " << calificacion << " " << grupo << endl;
}

//Funcion que lee el archivo de alumnos y categoriza los alumnos por grupo, devolviendo un vector de los grupos existentes.
vector<Grupo> LeerLista(ifstream& inputFile){
	//Se declaran las variables que se ocuparán.
	vector<Alumno> listaAlumnos;
	vector<Grupo> listaGrupos;
	vector<string> grupos;
	string line = "";
	string nombre = "";
	double calif = 0;
	string grupo = "";

	//Se recuperan líneas individuales del archivo, y se ocupa un stringstream para guardar la información del alumno en las variables.
	while (getline(inputFile, line)) {
		istringstream stringStream(line);
		stringStream >> nombre >> calif >> grupo;

		//Se guarda la información de todos los alumnos en un vector.
		listaAlumnos.push_back(Alumno{ nombre, calif, grupo });

		//Se guardan los grupos en un vector independiente.
		grupos.push_back(grupo);
	}

	//Se ordena la lista independiente de grupos, y se eliminan los duplicados para obtener una lista de grupos unicos.
	sort(grupos.begin(), grupos.end());
	grupos.erase(std::unique(grupos.begin(), grupos.end()), grupos.end());

	//Se itera sobre la lista de grupos.
	for (string nombreGrupo : grupos) {
		vector<Alumno> alumnosGrupo;
		//Por cada iteración de la lista de grupos, se itera por toda la lista de alumnos.
		for (Alumno alumnoActual : listaAlumnos) {
			//Si el alumno actual pertenece al grupo actual, se agrega a la lista de alumnos de ese grupo.
			if (alumnoActual.grupo == nombreGrupo) {
				alumnosGrupo.push_back(alumnoActual);
			}
		}

		//Se agrega el grupo actual con su lista de alumnos a la lista de grupos.
		listaGrupos.push_back(Grupo{ nombreGrupo, alumnosGrupo });
	}

	//Se regresa la lista de grupos.
	return listaGrupos;
}

void error(string s) {
	throw runtime_error(s);
}

