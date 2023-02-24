#include <vector>
using std::vector;
using std::swap;

namespace Sorting {
	void QuickSort(vector<int>& vector, int low, int high);
	void BubbleSort(vector<int>& vector, int size);
	void SelectionSort(vector<int>& vector, int size);

	int Partition(vector<int> vector, int low, int high, int pivot);
}