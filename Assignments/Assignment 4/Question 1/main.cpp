#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;

int main() {
	
	int choice;
	control list;
	char node;
	
	list.insert_node('0');
	list.insert_node('1');
	list.insert_node('2');
	list.insert_node('3');
	list.insert_node('4');

	list.insert_edge('0', '1');
	list.insert_edge('0', '2');
	list.insert_edge('0', '3');
	list.insert_edge('1', '2');
	list.insert_edge('2', '4');
	
	while(1) {
		
		cout << "\Depth First Search\n";
		cout << "\n1. Display Adjacency List";
		cout << "\n2. Depth First Search";
		cout << "\n3. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			
			case 1: {
		
				list.display();
				getch();
				system("cls");
				break;
				
			} case 2: {
				
				cout << "Enter the starting node: "; cin >> node;
				list.depth_first_search(node);
				getch();
				system("cls");
				break;
			
			} case 3:
				exit(0);
				
			default: {
				cout << "Wrong Choice!";
				getch();
				system("cls");
			}
		}
	}
}
