//MERGE SORT RECURSIVE ARRAY
#include <iostream>
#define MAX 30
int array[MAX];

using namespace std;

void merge(int low, int mid, int high) {
	
	int temp[MAX];
	int i = low;
	int j = mid + 1;
	int k = low;
	
	while((i <= mid) && (j <= high)) {
		
		if(array[i] <= array[j])
			temp[k++] = array[i++];
		
		else
			temp[k++] = array[j++];
		
	}
	
	while(i <= mid)
		temp[k++] = array[i++];
		
	while(j <= high)
		temp[k++] = array[j++];
		
	for(i = low; i <= high; i++)
		array[i] = temp[i];
	
}

void mergeSort (int low, int high) {
	
	int mid;
	if(low != high) {
		
		mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		merge(low, mid, high);
		
	}
	
}

int main() { 
	
	int i, n;
	cout << "Enter the number of elements: ";
	cin >> n;
	
	for(i = 0; i < n; i++) {
		
		cout << "Enter element " << i + 1 << ": ";
		cin >> array[i];
		
	}
	
	cout << "Unsorted List:\n";
	for(i = 0; i < n; i++)
		cout << array[i] << "	";
		
	mergeSort(0, n - 1);
	
	cout << "\nSorted List:\n";
	for(i = 0; i < n; i++)
		cout << array[i] << "	";
		
	cout << "\n";
}