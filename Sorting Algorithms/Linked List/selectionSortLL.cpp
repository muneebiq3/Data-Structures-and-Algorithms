#include <iostream>
using namespace std;

struct node {
	
    int info;
    
    struct node *link;
};
struct node *start = NULL;

void insert(int data) {

	struct node *q = new node;
	struct node *temp = new struct node;
    
    temp->info = data;
    temp->link = NULL;

    if (start == NULL)
        start = temp;
    
    else {
        q = start;
        while (q->link != NULL)
            q = q->link;
        
        q->link = temp;
    }
    
}

void display() {
	
	struct node *q = new struct node;
	q = start;
    while (q != NULL)
    {
        cout << q->info << "   ";
        q = q->link;
    }
    cout << endl;
}

void selectionSort(node *head) {
	
	struct node *current = head;;
	
	while (current != NULL) {
		
		struct node *nextNode = current->link;
		struct node *min = current;
		
		while (nextNode != NULL) {
			
			if(nextNode->info < min->info)
				min = nextNode;
				
			nextNode = nextNode->link;
		}
		
		int temp = min->info;
		min->info = current->info;
		current->info = temp;
			
		current = current->link;
	}
}

int main() {
	
	for(int i = 5; i > 0; i--)
		insert(i);
	
	display();
	selectionSort(start);
	display();
}
