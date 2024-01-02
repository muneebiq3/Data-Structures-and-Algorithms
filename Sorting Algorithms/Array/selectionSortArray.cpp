//SELECTION SORT ARRAY
#include <iostream>
#define MAX 30
using namespace std;

int array[MAX];

void selectionSort() {
	
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
		
		int least = i;
		
		for(j = i + 1; j < n; j ++) {
			
			if(array[j] < array[least])
				least = j;
			
			int temp = array[i];
			array[i] = array[least];
			array[least] = temp;
		}
		
	}
	
	cout << "\nFinal Sorted List: " << endl;
	for(int i = 0; i < n; i++)
		cout << "[" << i << "]: " << array[i] << "	";
		
	cout << endl;
	
}

int main () {
	
	selectionSort();
	
	return 0;
}
