#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;

int main() {
	
	int choice;
	control list;
	char source, dest;
		
	list.insert_node('a');
	list.insert_node('b');
	list.insert_node('c');
	list.insert_node('d');
	list.insert_node('e');
	list.insert_node('f');

	list.insert_edge('a', 'b', 4);
	list.insert_edge('a', 'c', 4);
	list.insert_edge('b', 'c', 2);
	list.insert_edge('c', 'd', 3);
	list.insert_edge('c', 'e', 6);
	list.insert_edge('c', 'f', 1);
	list.insert_edge('d', 'f', 2);
	list.insert_edge('e', 'f', 3);
	
	while(1) {
		
		cout << "\nDijkstras Algorithm\n";
		cout << "\n1. Display Adjacency List";
		cout << "\n2. Dijkstras Algorithm";
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
				
				cout << "Enter the source node: "; cin >> source;
				list.find_path(source);
				
				cout << "Enter the destination node: "; cin >> dest;
				list.traverse_path(source, dest);
				
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
