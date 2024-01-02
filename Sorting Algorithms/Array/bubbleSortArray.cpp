//BUBBLE SORT ARRAY
#include <iostream>
#define MAX 30
int array[MAX];

using namespace std;
void insertionSort() {
	
	int j, n;
	
	cout << "Enter the number of elements: "; cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "[" << i << "]: ";
		cin >> array[i];
	}
	
	cout << "\nUnsorted List:\n";
	for(int i = 0; i < n; i++)
		cout << "[" << i << "]: " <<array[i] << "	";
		
	cout << endl;
	
	for(int i = 0; i < n - 1; i++) {
		
		for(j = 0; j < n - i - 1; j++) {
			
			if(array[j] > array[j + 1]) {
				
				int temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				
			}
			
		}
		
	}
	
	cout << "\nFinal Sorted List: " << endl;
	for(int i = 0; i < n; i++)
		cout << "[" << i << "]: " << array[i] << "	";
		
	cout << endl;
	
}

int main () {
	
	insertionSort();
	
	return 0;
}
