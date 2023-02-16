//NameValue.h
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

namespace Namevalue {
	void error(string);

	//Clase ocupada por los ejercicios 2 y 3. Contiene dos vectores que forman pares de nombres y edades. Además, contiene varias funciones para su manejo.
	class Name_pairs {
	public:
		//Métodos que sirven para ingresar nombres y edades en los vectores.
		void read_names();
		void read_ages();

		//Método que imprime la lista de nombres y edades.
		//void print();

		//Método que organiza ambas listas.
		void sort();

		//Sobrecargas de operadores para que se puedan realizar operaciones correctamente con esta clase.
		friend ostream& operator<<(ostream& os, const Name_pairs& np);
		friend bool operator==(const Name_pairs& np1, const Name_pairs& np2);
		friend bool operator!=(const Name_pairs& np1, const Name_pairs& np2);
	private:
		//Declaración de las propiedades.
		vector<string> name;
		vector<int> age;
	};
}