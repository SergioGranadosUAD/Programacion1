#include "Sorting.h"

namespace Sorting {
	//Este algoritmo de ordenamiento ocupa un elemento pivote para dividir una lista en dos sublistas, las cuales a su vez se vuelven
	//a dividir en dos partes hasta que se organizan todos los elementos.
	void QuickSort(vector<int>& vector, int low, int high) {
		if (low < high) {
			int pivot = vector[high];
			int index = Partition(vector, low, high, pivot);

			QuickSort(vector, low, index - 1);
			QuickSort(vector, index + 1, high);
		}
	}

	//Este algoritmo de ordenamiento itera a través de una lista comparando elementos adyacentes, y los intercambia para ordenar
	//la lista de manera lineal hasta que todos los elementos están en el orden correcto.
	void BubbleSort(vector<int>& vector, int size) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - j; j++) {
				if (vector[j] > vector[j + 1]) {
					swap(vector[j], vector[j + 1]);
				}
			}
		}
	}

	//Este algoritmo de ordenamiento itera a través de una lista obteniendo el elemento no ordenado más pequeño, y lo manda al
	//inicio de la lista hasta que se organiza toda la lista.
	void SelectionSort(vector<int>& vector, int size) {
		for (int i = 0; i < size - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < size; j++) {
				if (vector[j] < vector[minIndex]) {
					minIndex = j;
				}

				swap(vector[i], vector[minIndex]);
			}
		}
	}

	//Esta función ocupada por el algoritmo de QuickSort intercambia en la lista de tal manera que los elementos más pequeños se mandan
	//a un lado del pivote y los más grandes al otro lado del pivote.
	int Partition(vector<int> vector, int low, int high, int pivot) {
		int index = low;
		for (int i = low; i <= high; i++) {
			if (vector[i] <= pivot) {
				swap(vector[index], vector[i]);
				index++;
			}
		}
		index--;
		return index;
	}
}