#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include "NameValue.h"

using namespace Namevalue;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;
using std::cerr;
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
void EjercicioQuince();
void EjercicioDieciseis();
void EjercicioDiecisiete();
void EjercicioDieciocho();

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
	EJERCICIO_DIECISEIS,
	EJERCICIO_DIECISIETE,
	EJERCICIO_DIECIOCHO
};

int main() {
	int eleccion = 0;
	bool salida = true;

	try {
		while (salida) {
			cout << "Introduzca el numero del ejercicio al que desea acceder (1-18). Introduzca cualquier otro numero para salir." << endl;

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
			case ejercicios::EJERCICIO_QUINCE:
				EjercicioQuince();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_DIECISEIS:
				EjercicioDieciseis();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_DIECISIETE:
				EjercicioDiecisiete();
				cout << endl << "Fin del ejercicio." << endl << endl;
				break;
			case ejercicios::EJERCICIO_DIECIOCHO:
				EjercicioDieciocho();
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

//Este ejercicio enlista objetos de la vida real como si fueran clases.
void EjercicioUno() {
	/*
	Clase Automovil:
		Propiedades:
			string marca
			string modelo
			double velocidadMaxima
			double capacidadCombustible
		Métodos:
			EncenderMotor()
			ApagarMotor()
			Acelerar()
			Frenar()
			PrenderFaros()
	
	Clase Celular:
		Propiedades:
			string marca
			string modelo
			int memoriaRAM
			int capacidadMemoria
			int numeroTelefono
		Métodos:
			HacerLlamada()
			PrenderLinterna()
			AbrirAplicacion()
			Desbloquear()
			CambiarConfiguracion()

	*/
}

//Este ejercicio utiliza la librería NameValue.h para declarar una clase Name_pairs que contiene vectores de int y string que corresponden a edad y nombres.
//Además, contiene varios métodos que realizan operaciones sobre estas.
void EjercicioDos() {
	Name_pairs np1;
	Name_pairs np2;

	cout << "Introduzca los valores del primer Name_pairs." << endl;
	np1.read_names();
	np1.read_ages();
	cout << np1 << endl;

	cout << "Introduzca los valores del segundo Name_pairs." << endl;
	np2.read_names();
	np2.read_ages();
	cout << np2 << endl;

	if (np1 == np2) {
		cout << "Ambos elementos son identicos." << endl;
	}
	else if (np1 != np2) {
		cout << "Los elementos son diferentes." << endl;
	}

	np1.sort();
	cout << "Primer elemento ordenado alfabeticamente:" << endl;
	cout << np1 << endl;
}

//Este ejercicio modifica la librería del ejercicio anterior para que ocupe una sobrecarga del operador << en vez de ocupar el método print(), además
//de agregar la sobrecarga de operadores == y !=.
void EjercicioTres() {

}

//Este ejercicio indenta y organiza apropiadamente el código del ejemplo 8.4 del capítulo, y trata de comentar lo que hace cada parte de este.
void EjercicioCuatro() {
	//dangerously ugly code

	//Contiene el método f(), g(),x(), m3() y main(), así como la propiedad int m. 
	struct X {
		//Recibe un entero, lo guarda en la variable m, y crea un objeto de tipo Y, del cual regresa el resultado del método f() de Y, el cual pasa
		//por la misma función f() principal, llamándose a sí mismo.
		void f(int x) {
			struct Y {
				int f() { return 1; } 
				int m;
			};
		int m;
		m = x; 
		Y m2;
		return f(m2.f());
		}

		int m;

		//Compara si m devuelve verdadero? En caso verdadero llama el método f() con valor de m+2, en caso contrario se llama a si mismo +2.
		void g(int m) {
		if (m) f(m + 2);
		else {
			g(m + 2);
		}
		}

		//Estos dos métodos no hacen absolutamente nada.
		X() { } 
		void m3() { }

		//Instancia un objeto 'a' de la clase X, y llama la función (f) de este método con un valor de 2.
		//Este método no debería de ir dentro de la clase.
		void main() {
			X a; 
			a.f(2);
		}
	};
}

//Este ejercicio implementa una clase Book que contiene la información de un libro, así como funciones para la administración de este.
//La implementación de esta se encuentra en los archivos Books.h y Books.cpp.
void EjercicioCinco() {

}

//Este ejercicio le agrega sobrecargas de operadores a la clase Book, para que puedan ser comparados e impresos de una forma apropiada.
//La implementación de esta se encuentra en los archivos Books.h y Books.cpp.
void EjercicioSeis() {

}

//Este ejercicio le agrega un enum a la clase Libros que contiene géneros literarios, modificándola para que funcione adecuadamente.
//La implementación de esta se encuentra en los archivos Books.h y Books.cpp.
void EjercicioSiete() {

}

//Este ejercicio implementa la clase Patron, que contiene los datos de un cliente de una biblioteca, además de implementar varios métodos para
// obtener y cambiar la información de este.
//La implementación de esta se encuentra en los archivos Books.h y Books.cpp.
void EjercicioOcho() {

}

//Este ejercicio agrega la clase Library que implementa las dos clases anteriores, además de crear un struct llamado Transaction para guardar
// las transacciones que se realicen en la biblioteca. Esta clase amacena a los clientes y libros que se encuentren en la biblioteca, y permite
// añadirlos, así como registrar las transacciones que se realicen.
//La implementación de esta se encuentra en los archivos Books.h y Books.cpp.
void EjercicioNueve() {

}

//Este ejercicio implementa el método auxiliar leapyear() en la clase Date que formó parte de este capítulo del libro.
//La implementación de este se encuentra en los archivos Chrono.h y Chrono.cpp.
void EjercicioDiez() {

}

//Este ejercicio añade funciones auxiliares tales como next_workday() y week_of_year() a la clase Date.
void EjercicioOnce() {

}

//Este ejercicio cambia la representación de la clase Date para que ahora sea el número de días desde el primero de enero de 1970.
void EjercicioDoce() {

}

//Este ejercicio implementa la clase Rational, que representa números fraccionarios. Además, se implementa la sobrecarga de operadores para
//esta clase, para que se puedan realizar operaciones aritméticas directamente sobre estos objetos.
//La implementación de esta clase se encuentra en los archivos Numbers.h y Numbers.cpp.
void EjercicioTrece() {

}

//Este ejercicio implementa la clase Money que se ocupa para cálculos que involucren dinero en dólares y centavos, solamente almacenando
//la cantidad en centavos pero convirtiéndolos en dólares para su impresión.
//La implementación de esta clase se encuentra en los archivos Numbers.h y Numbers.cpp.
void EjercicioCatorce() {

}

//Este ejercicio modifica la clase Money para añadir divisas, además de añadir la sobrecarga de operadores correspondiente para que se puedan realizar
//operaciones aritméticas básicas entre divisas.
//La implementación de esta clase se encuentra en los archivos Numbers.h y Numbers.cpp.
void EjercicioQuince() {

}

//Este ejercicio modifica una vez más las clase Money para añadir la sobrecarga de los operadores >> y <<, para que se puedan inicializar objetos
//de manera personalizada, y de igual manera que se puedan imprimir de manera organizada.
//La implementación de esta clase se encuentra en los archivos Numbers.h y Numbers.cpp.
void EjercicioDieciseis() {

}

//La clase Rational puede ser mejor para expresar una cantidad que la clase Money cuando se quiere evitar la pérdida de datos que se da durante el
//redondeo de los valores introducidos en la clase Money.
void EjercicioDiecisiete() {

}

//Es mejor ocupar la clase Rational en vez de un double cuando se quiere evitar la pérdida de datos que se puede dar durante la conversión de estos,
//como es el caso de números con decimal infinito como (1/3).
void EjercicioDieciocho() {

}

/*
FUNCIONES OCUPADAS POR LOS EJERCICIOS
*/

