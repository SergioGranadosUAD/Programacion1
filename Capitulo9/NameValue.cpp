//NameValue.cpp
#include "NameValue.h"

namespace Namevalue {
	//Esta función es ocupada por el ejercicio 2. Le pide al usuario introducir edades al vector age hasta que el usuario decida terminar.
	void Name_pairs::read_ages() {
		int entradaEdad = 0;
		cout << "Hay " << name.size() << " nombres registrados." << endl;
		cout << "Ahora introduzca la edad de las personas que agrego anteriormente en el mismo orden. Introduzca Ctrl+Z para terminar." << endl;
		cin.clear();
		while (cin >> entradaEdad) {
			if (cin.fail()) error("El valor introducido no es numerico.");
			age.push_back(entradaEdad);
		}
		cout << "Se han introducido " << age.size() << " edades." << endl << endl;
	}

	//Esta función es ocupada por el ejercicio 2. Le pide al usuario introducir nombres al vector name hasta que el usuario decida terminar.
	void Name_pairs::read_names() {
		string entradaNombre = "";
		cout << "Hay " << age.size() << " edades registradas." << endl;
		cout << "Introduzca los nombres de las personas que desea agregar a la lista. Introduzca Ctrl+Z para terminar." << endl;
		cin.clear();
		while (cin >> entradaNombre) {
			if (cin.fail()) error("Hubo un error al introducir el valor");
			name.push_back(entradaNombre);
		}
		cout << "Se han introducido " << name.size() << " nombres." << endl << endl;
	}

	/*
	* Esta función es ocupada por el ejecicio 2. La función de esta es de imprimir ambos vectores de la clase Name_pairs.
	* Esta función se ve reemplazada por la sobrecarga del operador << en el ejercicio 3.
	void Name_pairs::print() {
		if (name.size() != age.size()) error("No hay un numero igual de elementos en ambas listas!");
		for (int i = 0; i < name.size() - 1; i++) {
			cout << "(" << name[i] << "," << age[i] << ")" << endl;
		}
	}
	*/

	//Esta función es ocupada por el ejercicio 2. Ordena los nombres del vector y posteriormente ordena sus edades para que coincidan.
	void Name_pairs::sort() {
		if (name.size() != age.size()) error("No hay un numero igual de elementos en ambas listas!");
		vector<string> nameCopy = name;
		vector<int> ageSorted;

		std::sort(name.begin(), name.end());
		for (string val : name) {
			for (int i = 0; i < nameCopy.size(); i++) {
				if (nameCopy[i] == val) {
					ageSorted.push_back(age[i]);
				}
			}
		}

		age = ageSorted;
	}

	//Esta función es ocupada por el ejercicio 3. Sobrecarga el operador << e imprime todos los elementos dentro de los vectores de la clase Name_pairs
	//de forma ordenada.
	ostream& operator<<(ostream& os, const Name_pairs& np) {
		if (np.name.size() != np.age.size()) error("No hay un numero igual de elementos en ambas listas!");
		for (int i = 0; i < np.name.size(); i++) {
			cout << "(" << np.name[i] << "," << np.age[i] << ")" << endl;
		}
		return os;
	}

	//Esta función es ocupada por el ejercicio 3. Sobrecarga el operador == para que compare si dos instancias de la clase Name_pairs tienen los mismos
	//miembros age y name.
	bool operator==(const Name_pairs& np1, const Name_pairs& np2) {
		if (np1.age == np2.age && np1.name == np2.name) {
			return true;
		}
		else {
			return false;
		}
	}

	//Esta función es ocupada por el ejercicio 3. Sobrecarga el operador != para que compare si dos instancias de la clase Name_pairs tienen diferentes
	//miembros age y name.
	bool operator!=(const Name_pairs& np1, const Name_pairs& np2) {
		if (np1.age != np2.age && np1.name != np2.name) {
			return true;
		}
		else {
			return false;
		}
	}

	//Función para arrojar errores.
	void error(string s) {
		throw runtime_error(s);
	}
}