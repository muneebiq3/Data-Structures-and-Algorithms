//QUICK SORT ARRAY
#include <iostream>
#define MAX 30
int array[MAX];

using namespace std;

void display(int arr[], int low, int up) {
	
	int i;
	for(i = low; i <= up; i++)
		cout << array[i] << "	";
	
}

void quick(int arr[], int low, int up) {
	
	int pivot, temp, left, right;
	bool pivotPlaced = false;
	
	left = low;
	right = up;
	
	pivot = low;
	
	if(low >= up)
		return;
		
	cout << "\nSublist:\n";
	display(arr, low, up);
	
	while(pivotPlaced = false) {
		
		while(arr[pivot] <= arr[right] && pivot != right)
			right = right - 1;
			
		if(pivot == right)
			pivotPlaced = true;
			
		if(arr[pivot] > arr[right]) {
			
			temp = arr[pivot];
			arr[pivot] = arr[right];
			arr[right] = temp;
			pivot = right;
			
		}
		
		while(arr[pivot] >= arr[left] && left != pivot)
			left = left + 1;
			
		if(pivot == left)
			pivotPlaced = true;
			
		if(arr[pivot] < arr[left]) {
			
			temp = arr[pivot];
			arr[pivot] = arr[left];
			arr[left] = temp;
			pivot = left;
			
		}
		
	}
	
	cout << "Pivot Placed : " << arr[pivot];
	display(arr, low, up);
	cout << "\n";
	
	quick(arr, low, pivot - 1);
	quick(arr, pivot + 1, up);
	
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
	display(array, 0, n - 1);
	
	cout << "\n";
	quick(array, 0, n - 1);
	
	cout << "\nSorted List:\n";
	display(array, 0, n - 1);
		
	cout << "\n";
}