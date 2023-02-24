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
		//Declaración de las propiedades.
		int mValue;
		Node* mNext;
	};

	//Clase que sirve como una lista ligada que almacena enteros, contando con métodos para su manipulación.
	class SimpleList {
	public:
		//Constructor de la lista.
		SimpleList() :
			mSize(0), mFirst(nullptr), mLast(nullptr) {}

		//Método que regresa el tamaño de la lista.
		size_t Size() const {
			return mSize;
		}

		//Métodos auxiliares para la manipulación de la lista.
		void Add(int value);
		int At(size_t index);
		void Insert(int value, size_t index);
		void Delete(size_t index);

		//Método auxiliar que revisa si el índice introducido está dentro del rango de la lista.
		void CheckRange(size_t index);

		//Sobrecarga del operador [].
		int operator[](int i);
	private:
		//Declaración de los atributos.
		size_t mSize;
		Node* mFirst;
		Node* mLast;
	};
}
