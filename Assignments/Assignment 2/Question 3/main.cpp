#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;

int main() {
	
	control list;
	node *start  = NULL;
	
	while(1) {
		
		int choice;
		cout << "\n1. Fibonacci\n2. Sum\n3. Reverse\n4. Quit\n\nEnter your choice: "; cin >> choice;
		switch(choice) {
			case 1: {
				int num;
				cout << "Enter the number to find its fibonacci: "; cin >> num;
				
				if(num < 0)
					cout << "Fibonacci sequence is not defined for negative numbers!\n";
				else {
					int result = list.fibonacci(num);
					cout << "The " << num << "th Fibonacci number is: " << result << endl;
				}
				getch();
				system("cls");
				break;
			}
			case 2: {
				int sum = list.recursiveSum(start);
				cout << "Sum of elements in the linked list: " << sum << endl;
				getch();
				system("cls");
				break;
			}
			case 3: {
				start = list.reverseList(start);
				list.printList(start);
				getch();
				system("cls");
				break;
			}
			case 4: {
				exit(0);
				break;
			}
			default :
				cout << "Invalid Choice!";
		}
	
	}
	return 0;
}
