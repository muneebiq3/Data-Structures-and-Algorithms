#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;

int main() {
	
	int choice;
	control list;
	char source;
		
	list.insert_node('A');
	list.insert_node('B');
	list.insert_node('C');
	list.insert_node('D');
	list.insert_node('E');
	list.insert_node('F');

	list.insert_edge('A', 'A', 0);
	list.enqueue('A', 'A', 0, &list.front, &list.rear);
	
	list.insert_edge('A', 'B', 7);
	list.enqueue('A', 'B', 7, &list.front, &list.rear);
	
	list.insert_edge('A', 'C', 8);
	list.enqueue('A', 'C', 8, &list.front, &list.rear);
	
	list.insert_edge('B', 'C', NULL);
	list.enqueue('B', 'C', NULL, &list.front, &list.rear);
	
	list.insert_edge('B', 'D', 6);
	list.enqueue('B', 'D', 6, &list.front, &list.rear);
	
	list.insert_edge('B', 'F', NULL);
	list.enqueue('B', 'F', NULL, &list.front, &list.rear);
	
	list.insert_edge('C', 'D', 4);
	list.enqueue('C', 'D', 4, &list.front, &list.rear);
	
	list.insert_edge('C', 'F', 3);
	list.enqueue('C', 'F', 3, &list.front, &list.rear);
	
	list.insert_edge('D', 'E', 5);
	list.enqueue('D', 'E', 5, &list.front, &list.rear);
	
	list.insert_edge('D', 'F', 2);
	list.enqueue('D', 'F', 2, &list.front, &list.rear);
	
	list.insert_edge('E', 'E', 1);
	list.enqueue('E', 'E', 1, &list.front, &list.rear);
	
	list.insert_edge('E', 'F', 2);
	list.enqueue('E', 'F', 2, &list.front, &list.rear);
	
	while(1) {
		
		cout << "\nKruskal Algorithm\n";
		cout << "\n1. Display Adjacency List";
		cout << "\n2. Kruskal Algorithm";
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
				
				
				list.sort();
				list.make_tree();
				cout << "MST:\n";
				list.displayQ();
				cout << "Total weight:\n";
				cout << list.wt_tree;
				
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


