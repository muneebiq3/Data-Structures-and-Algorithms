#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;

int main() {
	
	int choice;
	control list;
	
	while(1) {
		
		cout << "\nDFS for Undirected Graph\n";
		cout << "\n1. Insert Vertex";
		cout << "\n2. Insert Edge";
		cout << "\n3. Delete Vertex";
		cout << "\n4. Delete Edge";
		cout << "\n5. Depth First Search";
		cout << "\n6. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			
			case 1: {
				
				int data;
				cout << "Enter the vertex to be added: "; cin >> data;
				list.insertVertex(data);
				
				getch();
				system("cls");
				break;
				
			} case 2: {
				
				if(list.start == NULL) {
					cout << "Graph is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				int vertex1, vertex2;
				cout << "Enter the first vertex: "; cin >> vertex1;
				cout << "Enter the second vertex: "; cin >> vertex2;
				
				vertex *v1 = NULL, *v2 = NULL;
				vertex *temp = list.start;
				
				while(temp != NULL) {
					
					if(temp->info == vertex1)
						v1 = temp;
					if(temp->info == vertex2)
						v2 = temp;
						
					temp = temp->next;
					
				}
				
				if(v1 == NULL && v2 == NULL)
					cout << "Both Vertices " << vertex1 << " and " << vertex2 << " not found in the Graph!";
				else if(v1 == NULL)
					cout << "First Vertex " << vertex1 << " not found in the Graph!";
				else if(v2 == NULL)
					cout << "Second Vertex " << vertex2 << " not found in the Graph!";
				else 
					list.insertEdge(v1, v2);
				
				getch();
				system("cls");
				break;
				
			} case 3: {
				
				if(list.start == NULL) {
					cout << "Graph is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				int data;
				cout << "Enter the vertex to be deleted: "; cin >> data;
				list.deleteVertex(data);
				
				getch();
				system("cls");
				break;
				
				
			} case 4: {
				
				if(list.start == NULL) {
					cout << "Graph is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				int vertex1, vertex2;
				cout << "Enter the first vertex: "; cin >> vertex1;
				cout << "Enter the second vertex: "; cin >> vertex2;
				
				vertex *v1 = NULL, *v2 = NULL;
				vertex *temp = list.start;
				
				while(temp != NULL) {
					
					if(temp->info == vertex1)
						v1 = temp;
					if(temp->info == vertex2)
						v2 = temp;
						
					temp = temp->next;
					
				}
				
				if(v1 == NULL && v2 == NULL)
					cout << "Both Vertices " << vertex1 << " and " << vertex2 << " not found in the Graph!";
				else if(v1 == NULL)
					cout << "First Vertex " << vertex1 << " not found in the Graph!";
				else if(v2 == NULL)
					cout << "Second Vertex " << vertex2 << " not found in the Graph!";
				else 
					list.deleteEdge(v1, v2);
				
				getch();
				system("cls");
				break;
				
			} case 5: {
				
				if(list.start == NULL) {
					cout << "Graph is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				else
					list.display();
				
				getch();
				system("cls");
				break;
				
			} case 6:
				exit(0);
				
			default: {
				cout << "Wrong Choice!";
				getch();
				system("cls");
			}
		}
	}
}
