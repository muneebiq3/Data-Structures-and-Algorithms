//INSERTION SORT ARRAY
#include <iostream>
#define MAX 30
int array[MAX]

using namespace std;
void insertionSort() {
	
	int temp,j, n;
	bool exchange;
	
	cout << "Enter the number of elements: "; cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "[" << i << "]: ";
		cin >> array[i];
	}
	
	cout << "\nUnsorted List:\n";
	for(int i = 0; i < n; i++)
		cout << "[" << i << "]: " <<array[i] << "	";
		
	cout << endl;
	
	for(int i = 1; i < n; i++) {
		
		temp = array[i];
		for(j = i - 1; ( j >= 0 && temp < array[j] ); j--) 
			array[j + 1] = array[j];
			
		array[j + 1] = temp;
		
		cout << "\nPass " << i << " Element inserted in proper place: " << temp << endl;
		
		for(int k = 0; k < n; k++)
			cout << "[" << k << "]: " << array[k] << "	";
			
		cout << endl;
		
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