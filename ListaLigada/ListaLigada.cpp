#include "ListaLigada.h"

namespace ListaLigada {
	//Método que añade un elemento al final de la lista.
	void SimpleList::Add(int value) {
		//Si se añade un elemento por primera vez, se establece que es el primero y último en la lista.
		if (mSize == 0) {
			Node* newNode = new Node(value);
			mFirst = newNode;
			mLast = newNode;
		}
		//En caso de haber más, se obtiene el último nodo, se crea el nuevo nodo y se asigna al último nodo la dirección del nuevo nodo.
		//Posteriormente el nuevo nodo pasa a ser el último nodo de la lista.
		else {
			Node* lastNode = mLast;
			Node* newNode = new Node(value);
			lastNode->SetmNext(newNode);
			mLast = newNode;
			
		}
		mSize++;
	}

	//Método que itera sobre la lista y devuelve el valor que se encuentra en el índice.
	int SimpleList::At(size_t index) {
		CheckRange(index);
		Node* iterNode = mFirst;
		//Se itera sobre el tamaño de la lista.
		for (int i = 0; i < mSize; i++) {
			//Si la iteración actual equivale al índice, devuelve el valor de esta.
			if (i == index) {
				return iterNode->GetmValue();
			}
			//En caso contrario pasa al siguiente puntero.
			else {
				iterNode = iterNode->GetmNext();
			}
		}
	}

	//Método que inserta un elemento en el indice indicado de la lista.
	void SimpleList::Insert(int value, size_t index) {
		CheckRange(index);
		Node* iterNode = mFirst;
		Node* previousNode = mFirst;

		//Si se inserta en el primer espacio, se le asigna a este nuevo nodo la dirección del que antes era el primer elemento, y se vuelve
		//el primer elemento de la lista.
		if (index == 0) {
			Node* newNode = new Node(value);
			newNode->SetmNext(mFirst);
			mFirst = newNode;
			mSize++;
		}
		//En caso contrario, itera sobre la lista hasta encontrar el índice.
		else {
			for (int i = 0; i < mSize; i++) {
				if (i == index) {
					//se le asigna la dirección del nuevo nodo al nodo anterior, y al nuevo nodo se le asigna la dirección del nodo que sigue.
					Node* newNode = new Node(value);
					previousNode->SetmNext(newNode);
					newNode->SetmNext(iterNode);
					mSize++;
					return;
				}
				//Se guarda el nodo anterior y se sigue iterando.
				else {
					previousNode = iterNode;
					iterNode = iterNode->GetmNext();
				}
			}
		}
	}

	//Método que elimina un elemento de la lista en el índice indicado.
	void SimpleList::Delete(size_t index) {
		CheckRange(index);
		Node* iterNode = mFirst;
		Node* previousNode = mFirst;

		//Si se elimina en el primer espacio, se le asigna la dirección del primer nodo al segundo espacio, y se elimina el primer nodo
		//de la memoria. Posteriormente se reduce el tamaño de la lista.
		if (index == 0) {
			mFirst = iterNode->GetmNext();
			delete iterNode;
			mSize--;
		}
		//En caso contrario, se itera a través de la lista hasta que se encuentra el índice.
		else {
			for (int i = 0; i < mSize; i++) {
				if (i == index) {
					//Se le asigna la dirección del nodo que sigue al nodo anterior, y se elimina el nodo actual de la memoria. Posteriormente
					//se reduce el tamaño de la lista.
					previousNode->SetmNext(iterNode->GetmNext());
					delete iterNode;

					mSize--;
					return;
				}
				//Se guarda el nodo anterior y se sigue iterando.
				else {
					previousNode = iterNode;
					iterNode = iterNode->GetmNext();
				}
			}
		}
	}

	//Método auxiliar que verifica que el indice introducido no sea mayor al tamaño de la lista.
	void SimpleList::CheckRange(size_t index) {
		if (index > mSize) {
			throw out_of_range("El indice esta fuera del rango de la lista");
		}
	}

	//Método que establece el valor de un nodo.
	void Node::SetmValue(int i) {
		mValue = i;
	}

	//Método que establece el puntero al siguiente elemento de un nodo.
	void Node::SetmNext(Node* n) {
		mNext = n;
	}

	//Sobrecarga de operador que llama a la función At() para devolver el valor de un elemento de la lista en la posición indicada.
	int SimpleList::operator[](int i) {
		return At(i);
	}
}