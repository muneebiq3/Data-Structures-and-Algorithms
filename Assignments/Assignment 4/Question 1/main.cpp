#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;

int main() {
	
	int choice;
	control list;
	
	list.insertVertex(0);
	list.insertVertex(1);
	list.insertVertex(2);
	list.insertVertex(3);
	list.insertVertex(4);
	
	vertex *v1 = NULL, *v2 = NULL;
	vertex *temp = list.start;
				
		while(temp != NULL) {
					
			if(temp->info == 0)
				v1 = temp;
			if(temp->info == 1)
				v2 = temp;
						
			temp = temp->next;
					
		}
				
	list.insertEdge(v1, v2);
	
	temp = list.start;
				
		while(temp != NULL) {
					
			if(temp->info == 0)
				v1 = temp;
			if(temp->info == 2)
				v2 = temp;
						
			temp = temp->next;
					
		}
				
	list.insertEdge(v1, v2);
	
	temp = list.start;
				
		while(temp != NULL) {
					
			if(temp->info == 1)
				v1 = temp;
			if(temp->info == 2)
				v2 = temp;
						
			temp = temp->next;
					
		}
				
	list.insertEdge(v1, v2);
	
	temp = list.start;
				
		while(temp != NULL) {
					
			if(temp->info == 0)
				v1 = temp;
			if(temp->info == 3)
				v2 = temp;
						
			temp = temp->next;
					
		}
				
	list.insertEdge(v1, v2);
	
	temp = list.start;
				
		while(temp != NULL) {
					
			if(temp->info == 2)
				v1 = temp;
			if(temp->info == 4)
				v2 = temp;
						
			temp = temp->next;
					
		}
				
	list.insertEdge(v1, v2);
	
	
	while(1) {
		
		cout << "\Depth First Search for Undirected Graph\n";
		cout << "\n1. Display";
		cout << "\n2. Depth First Search";
		cout << "\n3. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			
			case 1: {
				
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
				
			} case 2: {
				
				if(list.start == NULL) {
					cout << "Graph is empty!" << endl;
					
					getch();
					system("cls");
					break;
				}
				
				else
					list.depthFirstSearch(list.start);
				
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
