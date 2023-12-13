//INSERTION SORT LL
#include <iostream>

using namespace std;
  
struct node { 
    int data; 
    struct node *next; 
}; 
  
struct node *head = NULL; 
struct node *sorted = NULL; 
  
void push(int val) { 

    struct node *newnode = new node; 
    newnode->data = val; 
    newnode->next = head; 
    head = newnode; 
} 
  
void sortedInsert(struct node *newnode) { 

    if (sorted == NULL || sorted->data >= newnode->data) { 
    
        newnode->next = sorted; 
        sorted = newnode; 
    } 
    else {
	 
        struct node *current = sorted; 

        while (current->next != NULL && current->next->data < newnode->data)
            current = current->next; 
        
        newnode->next = current->next; 
        current->next = newnode; 
    } 
    
} 
  
void insertionsort() { 
  
    struct node *current = head; 
  
    while (current != NULL) { 
  
        struct node *next = current->next; 
  
        sortedInsert(current); 
   
        current = next; 
    } 
    head = sorted; 
} 

void printlist(struct node *head) { 

    while (head != NULL) { 
        cout << head->data << "	"; 
        head = head->next; 
    } 
    cout << "NULL"; 
} 

int main() { 
	int n;
    for(int i = 0; i < 5; i++) {
    	cin >> n;
    	push(n);
	}
  
    cout << "Linked List before sorting:\n"; 
    printlist(head); 
    cout << "\n"; 
  
    insertionsort(); 
  
    cout << "Linked List after sorting:\n"; 
    printlist(head); 
}