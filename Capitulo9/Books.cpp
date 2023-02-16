//Books.cpp
#include "Books.h"

namespace Books {
	/*
	-------------------------------------------
	Funciones correspondientes a la clase Books.
	-------------------------------------------
	*/

	//Conjunto de funciones que permiten establecer los valores de un objeto de tipo Book.
	void Book::setISBN(ISBN i) {
		isbn = to_string(i.n1) + "-" + to_string(i.n2) + "-" + to_string(i.n3) + "-" + to_string(i.x1);
	}

	void Book::setTitle(string s) {
		title = s;
	}

	void Book::setAuthor(string s) {
		author = s;
	}

	void Book::setCopyrightDate(string s) {
		copyrightDate = s;
	}

	void Book::setGenre(Genre g) {
		bookGenre = g;
	}

	//Función auxiliar que cambia el estado de disponibilidad de un libro.
	void Book::CheckBook() {
		if (isChecked) {
			isChecked = false;
		}
		else {
			isChecked = true;
		}
	}

	//Sobrecarga de operador que imprime apropiadamente las propiedades de un objeto de tipo Book.
	ostream& operator<<(ostream& os, const Book& b) {
		cout << "Titulo: " << b.getTitle() << endl;
		cout << "Autor: " << b.getAuthor() << endl;
		cout << "ISBN: " << b.getISBN() << endl;
		return os;
	}

	//Sobrecarga de operador que verifica si el ISBN de dos objeto de tipo Book coinciden.
	bool operator==(const Book& b1, const Book& b2) {
		if (b1.getISBN() == b2.getISBN()) {
			return true;
		}
		else {
			return false;
		}
	}

	//Sobrecarga de operador que verifica si el ISBN de dos objeto de tipo Book coinciden.
	bool operator!=(const Book& b1, const Book& b2) {
		if (b1.getISBN() != b2.getISBN()) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	-------------------------------------------
	Funciones correspondientes a la clase Patron
	-------------------------------------------
	*/

	//Conjunto de métodos que establecen los valores de un objeto de tipo Patron.
	void Patron::setName(string s) {
		name = s;
	}

	void Patron::setCardNumber(int i) {
		cardNumber = i;
	}

	void Patron::setLibraryFees(double d) {
		libraryFees = d;

		if (libraryFees > 0) {
			owesFees = true;
		}
		else {
			owesFees = false;
		}
	}

	//Método auxiliar que devuelve un booleando dependiendo si el cliente tiene deudas o no.
	bool Patron::CheckFees() {
		if (owesFees) {
			return true;
		}
		else {
			return false;
		}
	}

	

	/*
	-------------------------------------------
	Funciones correspondientes a la clase Library
	-------------------------------------------
	*/

	//Método que añade un libro al vector de libros de la biblioteca.
	void Library::AddBook(Book b) {
		for (Book b2 : bookList) {
			if (b == b2) {
				error("El libro indicado ya existe en la biblioteca.");
			}
		}
		bookList.push_back(b);
	}

	//Método que añade un cliente al vector de clientes de la biblioteca.
	void Library::AddPatron(Patron p) {
		for (Patron p2 : customers) {
			if (p.getCardNumber() == p2.getCardNumber()) {
				error("El cliente indicado ya existe en la biblioteca.");
			}
		}
		customers.push_back(p);
	}

	//Método que añade una transacción a la lista de transacciones, validando que toda la información sea correcta.
	void Library::CheckOutBook(Book b, Patron p, Date d) {
		bool bookFound = false;
		bool customerFound = false;
		int bookIndex = 0;

		//Verifica que el libro exista en la biblioteca.
		for (int i = 0; i < bookList.size(); i++) {
			if (b == bookList[i]) {
				bookFound = true;
				bookIndex = i;
			}
		}

		//Verifica que el cliente esté registrado en la biblioteca.
		for (Patron p2 : customers) {
			if (p.getCardNumber() == p2.getCardNumber()) {
				customerFound = true;
			}
		}

		if (bookFound && customerFound) {
			//Si el cliente no tiene deudas, se cambia la disponibilidad del libro y se agrega la transacción.
			if (!p.CheckFees()) {
				bookList[bookIndex].CheckBook();
				transactions.push_back(Transaction{ b, p, d });
			}
			else {
				error("El cliente seleccionado tiene deudas pendientes.");
			}
		}
		else {
			error("No se encontro el isbn del libro solicitado o el numero de cliente.");
		}
	}

	//Método auxiliar que devuelve en un vector todos los clientes que tienen deudas con la biblioteca.
	vector<Patron> Library::CheckPatronFees() {
		vector<Patron> feeDebtors;
		for (Patron p : customers) {
			if (p.CheckFees()) {
				feeDebtors.push_back(p);
			}
		}

		return feeDebtors;
	}

	//Función para arrojar errores.
	void error(string s) {
		throw runtime_error(s);
	}
}