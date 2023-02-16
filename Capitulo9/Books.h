//Books.h
#include <iostream>
#include <string>
#include <vector>
#include "chrono.h"

using namespace Chrono;
using std::string;
using std::vector;
using std::runtime_error;
using std::to_string;
using std::ostream;
using std::cout;
using std::endl;

namespace Books {
	struct ISBN {
		int n1;
		int n2;
		int n3;
		char x1;
	};

	enum class Genre {
		fiction, nonfiction, periodical, biography, children
	};

	//Clase ocupada por los ejercicios 5 a 9. Crea un objeto de tipo Libro y cuenta con los métodos correspondientes para obtener y establecer
	//los valores de este objeto. Además, sobrecarga los operadores <<, == y != para que impriman y comparen las instancias de esta clase de
	//manera adecuada.
	class Book {
	public:
		//Funciones para devolver los valores del objeto.
		string getISBN() const {
			return isbn; 
		}
		string getTitle() const {
			return title; 
		}
		string getAuthor() const {
			return author; 
		}
		string getCopyrightDate() const {
			return copyrightDate; 
		}
		bool getIsChecked() const {
			return isChecked;
		}

		Genre getGenre() const {
			return bookGenre;
		}

		//Funciones para establecer los valores del objeto.
		void setISBN(ISBN i);
		void setTitle(string s);
		void setAuthor(string s);
		void setCopyrightDate(string s);
		void setGenre(Genre g);

		//Función auxiliar para marcar si el libro se encuentra disponible o no.
		void CheckBook();

		//Sobrecargas de operadores para que acepten objetos de tipo Book.
		friend ostream& operator<<(ostream& os, const Book& b);
		friend bool operator==(const Book& b1, const Book& b2);
		friend bool operator!=(const Book& b1, const Book& b2);

	private:
		//Declaración de las propiedades.
		string isbn;
		string title;
		string author;
		string copyrightDate;
		Genre bookGenre;
		bool isChecked = false;
	};

	//Clase que forma parte de los ejercicios 5-9. Crea un objeto de tipo Patron, el cual tiene de igual manera funciones para obtener y
	//establecer los valores de este objeto, además de tener funciones para revisar si el cliente tiene deudas sin pagar.
	class Patron {
	public:
		//Funciones para devolver los valores del objeto.
		string getName() const {
			return name;
		}

		int getCardNumber() const {
			return cardNumber;
		}

		double getLibraryFees() const {
			return libraryFees;
		}

		//Funciones para establecer los valores del objeto.
		void setName(string s);
		void setCardNumber(int i);
		void setLibraryFees(double d);
		
		//Función auxiliar para revisar si el cliente seleccionado tiene deudas o no.
		bool CheckFees();

	private:
		//Declaración de las propiedades.
		string name;
		int cardNumber;
		double libraryFees;
		bool owesFees;
	};

	//Estrcutura que registra transacciones realizadas, guardando el libro, el cliente y la fecha de la transacción.
	struct Transaction {
		Book borrowedBook;
		Patron relevantPatron;
		Date transactionDate;
	};

	//Clase ocupada por los ejercicios 5-9. Crea un objeto de clase Library que implementa las otras dos clases anteriores y almacena conjuntos de
	//estas en vectores. Además, añade las transacciones que se han hecho, permitiendo agregarlas a un tercer vector. Por último, permite
	//devolver un vector con los clientes que tengan deudas con la biblioteca.
	class Library {
	public:
		//Funciones que agregan libros y clientes a los vectores.
		void AddBook(Book b);
		void AddPatron(Patron p);

		//Función auxiliar que valida la información y guarda una transacción.
		void CheckOutBook(Book b, Patron p, Date d);

		//Función auxiliar que devuelve un vector con todos los clientes que tienen deudas con la biblioteca.
		vector<Patron> CheckPatronFees();

	private:
		//Declaración de las propiedades.
		vector<Book> bookList;
		vector<Patron> customers;
		vector<Transaction> transactions;
	};

	void error(string);
}
