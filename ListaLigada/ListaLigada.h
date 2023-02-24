#include <iostream>
using std::out_of_range;

namespace ListaLigada {

	//Clase que contiene el valor del elemento de la lista y un puntero que lleva al siguiente elemento.
	class Node {
	public:
		//Constructor del nodo.
		Node(int val) :
			mValue(val), mNext(nullptr) {}

		//Getters and Setters para acceder a los atributos del nodo.
		int GetmValue() const { return mValue; }
		Node* GetmNext() const { return mNext; }
		void SetmValue(int i);
		void SetmNext(Node* n);

	private:
		//Declaraci�n de las propiedades.
		int mValue;
		Node* mNext;
	};

	//Clase que sirve como una lista ligada que almacena enteros, contando con m�todos para su manipulaci�n.
	class SimpleList {
	public:
		//Constructor de la lista.
		SimpleList() :
			mSize(0), mFirst(nullptr), mLast(nullptr) {}

		//M�todo que regresa el tama�o de la lista.
		size_t Size() const {
			return mSize;
		}

		//M�todos auxiliares para la manipulaci�n de la lista.
		void Add(int value);
		int At(size_t index);
		void Insert(int value, size_t index);
		void Delete(size_t index);

		//M�todo auxiliar que revisa si el �ndice introducido est� dentro del rango de la lista.
		void CheckRange(size_t index);

		//Sobrecarga del operador [].
		int operator[](int i);
	private:
		//Declaraci�n de los atributos.
		size_t mSize;
		Node* mFirst;
		Node* mLast;
	};
}
