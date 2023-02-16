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
		M�todos:
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
		M�todos:
			HacerLlamada()
			PrenderLinterna()
			AbrirAplicacion()
			Desbloquear()
			CambiarConfiguracion()

	*/
}

//Este ejercicio utiliza la librer�a NameValue.h para declarar una clase Name_pairs que contiene vectores de int y string que corresponden a edad y nombres.
//Adem�s, contiene varios m�todos que realizan operaciones sobre estas.
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

//Este ejercicio modifica la librer�a del ejercicio anterior para que ocupe una sobrecarga del operador << en vez de ocupar el m�todo print(), adem�s
//de agregar la sobrecarga de operadores == y !=.
void EjercicioTres() {

}

//Este ejercicio indenta y organiza apropiadamente el c�digo del ejemplo 8.4 del cap�tulo, y trata de comentar lo que hace cada parte de este.
void EjercicioCuatro() {
	//dangerously ugly code

	//Contiene el m�todo f(), g(),x(), m3() y main(), as� como la propiedad int m. 
	struct X {
		//Recibe un entero, lo guarda en la variable m, y crea un objeto de tipo Y, del cual regresa el resultado del m�todo f() de Y, el cual pasa
		//por la misma funci�n f() principal, llam�ndose a s� mismo.
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

		//Compara si m devuelve verdadero? En caso verdadero llama el m�todo f() con valor de m+2, en caso contrario se llama a si mismo +2.
		void g(int m) {
		if (m) f(m + 2);
		else {
			g(m + 2);
		}
		}

		//Estos dos m�todos no hacen absolutamente nada.
		X() { } 
		void m3() { }

		//Instancia un objeto 'a' de la clase X, y llama la funci�n (f) de este m�todo con un valor de 2.
		//Este m�todo no deber�a de ir dentro de la clase.
		void main() {
			X a; 
			a.f(2);
		}
	};
}

//Este ejercicio implementa una clase Book que contiene la informaci�n de un libro, as� como funciones para la administraci�n de este.
//La implementaci�n de esta se encuentra en los archivos Books.h y Books.cpp.
void EjercicioCinco() {

}

//Este ejercicio le agrega sobrecargas de operadores a la clase Book, para que puedan ser comparados e impresos de una forma apropiada.
//La implementaci�n de esta se encuentra en los archivos Books.h y Books.cpp.
void EjercicioSeis() {

}

//Este ejercicio le agrega un enum a la clase Libros que contiene g�neros literarios, modific�ndola para que funcione adecuadamente.
//La implementaci�n de esta se encuentra en los archivos Books.h y Books.cpp.
void EjercicioSiete() {

}

//Este ejercicio implementa la clase Patron, que contiene los datos de un cliente de una biblioteca, adem�s de implementar varios m�todos para
// obtener y cambiar la informaci�n de este.
//La implementaci�n de esta se encuentra en los archivos Books.h y Books.cpp.
void EjercicioOcho() {

}

//Este ejercicio agrega la clase Library que implementa las dos clases anteriores, adem�s de crear un struct llamado Transaction para guardar
// las transacciones que se realicen en la biblioteca. Esta clase amacena a los clientes y libros que se encuentren en la biblioteca, y permite
// a�adirlos, as� como registrar las transacciones que se realicen.
//La implementaci�n de esta se encuentra en los archivos Books.h y Books.cpp.
void EjercicioNueve() {

}

//Este ejercicio implementa el m�todo auxiliar leapyear() en la clase Date que form� parte de este cap�tulo del libro.
//La implementaci�n de este se encuentra en los archivos Chrono.h y Chrono.cpp.
void EjercicioDiez() {

}

//Este ejercicio a�ade funciones auxiliares tales como next_workday() y week_of_year() a la clase Date.
void EjercicioOnce() {

}

//Este ejercicio cambia la representaci�n de la clase Date para que ahora sea el n�mero de d�as desde el primero de enero de 1970.
void EjercicioDoce() {

}

//Este ejercicio implementa la clase Rational, que representa n�meros fraccionarios. Adem�s, se implementa la sobrecarga de operadores para
//esta clase, para que se puedan realizar operaciones aritm�ticas directamente sobre estos objetos.
//La implementaci�n de esta clase se encuentra en los archivos Numbers.h y Numbers.cpp.
void EjercicioTrece() {

}

//Este ejercicio implementa la clase Money que se ocupa para c�lculos que involucren dinero en d�lares y centavos, solamente almacenando
//la cantidad en centavos pero convirti�ndolos en d�lares para su impresi�n.
//La implementaci�n de esta clase se encuentra en los archivos Numbers.h y Numbers.cpp.
void EjercicioCatorce() {

}

//Este ejercicio modifica la clase Money para a�adir divisas, adem�s de a�adir la sobrecarga de operadores correspondiente para que se puedan realizar
//operaciones aritm�ticas b�sicas entre divisas.
//La implementaci�n de esta clase se encuentra en los archivos Numbers.h y Numbers.cpp.
void EjercicioQuince() {

}

//Este ejercicio modifica una vez m�s las clase Money para a�adir la sobrecarga de los operadores >> y <<, para que se puedan inicializar objetos
//de manera personalizada, y de igual manera que se puedan imprimir de manera organizada.
//La implementaci�n de esta clase se encuentra en los archivos Numbers.h y Numbers.cpp.
void EjercicioDieciseis() {

}

//La clase Rational puede ser mejor para expresar una cantidad que la clase Money cuando se quiere evitar la p�rdida de datos que se da durante el
//redondeo de los valores introducidos en la clase Money.
void EjercicioDiecisiete() {

}

//Es mejor ocupar la clase Rational en vez de un double cuando se quiere evitar la p�rdida de datos que se puede dar durante la conversi�n de estos,
//como es el caso de n�meros con decimal infinito como (1/3).
void EjercicioDieciocho() {

}

/*
FUNCIONES OCUPADAS POR LOS EJERCICIOS
*/

