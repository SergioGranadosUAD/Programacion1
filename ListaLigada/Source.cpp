#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "ListaLigada.h"
#include "Sorting.h"

using namespace std::chrono;
using namespace ListaLigada;
using namespace Sorting;
using std::vector;
using std::cout;
using std::endl;
using std::cerr;
using std::generate;
using std::out_of_range;

int main() {
	cout << "Ejercicios con la lista ligada:" << endl;
	try {
		SimpleList lista;
		lista.Add(1);
		lista.Add(2);
		lista.Add(3);
		lista.Add(4);
		lista.Add(6);

		lista.Insert(0, 0);
		lista.Insert(5, 5);

		lista.Delete(3);
		for (int i = 0; i < lista.Size(); ++i) {
			cout << "elemento: " << lista[i] << endl;
		}
	}
	catch (out_of_range& e) {
		cerr << e.what() << endl;
	}
	cout << endl << endl;

	cout << "Ejercicios de sorting:" << endl;
	vector<int> vector1(1000);
	vector<int> vector2(10000);
	vector<int> vector3(50000);

	auto fill1 = []() -> int { return rand() % 1000; };
	auto fill2 = []() -> int { return rand() % 10000; };
	auto fill3 = []() -> int { return rand() % 50000; };

	auto start = high_resolution_clock::now();
	auto stop = high_resolution_clock::now();

	
	generate(vector1.begin(), vector1.end(), fill1);
	generate(vector2.begin(), vector2.end(), fill2);
	generate(vector3.begin(), vector3.end(), fill2);

	//Conteo de tiempo de QuickSort.
	start = high_resolution_clock::now();
	QuickSort(vector1, 0, (vector1.size() - 1));
	stop = high_resolution_clock::now();
	cout << "La duracion del QuickSort sobre vector1 es: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;

	start = high_resolution_clock::now();
	QuickSort(vector2, 0, (vector2.size() - 1));
	stop = high_resolution_clock::now();
	cout << "La duracion del QuickSort sobre vector2 es: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;

	start = high_resolution_clock::now();
	QuickSort(vector3, 0, (vector3.size() - 1));
	stop = high_resolution_clock::now();
	cout << "La duracion del QuickSort sobre vector3 es: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;

	//Conteo de tiempo de BubbleSort.
	start = high_resolution_clock::now();
	BubbleSort(vector1, vector1.size());
	stop = high_resolution_clock::now();
	cout << "La duracion del BubbleSort sobre vector1 es: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;

	start = high_resolution_clock::now();
	BubbleSort(vector2, vector2.size());
	stop = high_resolution_clock::now();
	cout << "La duracion del BubbleSort sobre vector2 es: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;

	start = high_resolution_clock::now();
	BubbleSort(vector3, vector3.size());
	stop = high_resolution_clock::now();
	cout << "La duracion del BubbleSort sobre vector3 es: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;

	//Conteo de tiempo de SelectionSort.
	start = high_resolution_clock::now();
	SelectionSort(vector1, vector1.size());
	stop = high_resolution_clock::now();
	cout << "La duracion del SelectionSort sobre vector1 es: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;

	start = high_resolution_clock::now();
	SelectionSort(vector1, vector1.size());
	stop = high_resolution_clock::now();
	cout << "La duracion del SelectionSort sobre vector2 es: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;

	start = high_resolution_clock::now();
	SelectionSort(vector1, vector1.size());
	stop = high_resolution_clock::now();
	cout << "La duracion del SelectionSort sobre vector3 es: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;
	

	return 0;
}