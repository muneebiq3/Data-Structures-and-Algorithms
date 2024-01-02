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

void bubbleSort(node *head) {
	
	struct node *ptr = head;
	
	while (ptr != NULL) {
		
		struct node *nextNode = ptr->link;
		int xchanges = 0;
		
		while (nextNode != NULL) {
			
			if(ptr->info > nextNode->info) {	
			
				int temp = nextNode->info;
				nextNode->info = ptr->info;
				ptr->info = temp;
				xchanges++;
					
			}	
			nextNode = nextNode->link;
		}
		
		if (xchanges == 0)
			break;
			
		ptr = ptr->link;
	}
}

int main() {
	
	for(int i = 5; i > 0; i--)
		insert(i);
	
	display();
	bubbleSort(start);
	display();
}
