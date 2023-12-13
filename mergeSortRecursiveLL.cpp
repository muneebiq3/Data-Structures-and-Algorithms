//MERGE SORT RECURSIVE LL
#include <iostream>

using namespace std;

struct node {
    int data;
    node *link;
};

node *push(node *head, int value) {
    node *newNode = new node;
    newNode->data = value;
    newNode->link = head;
    return newNode;
}

node *merge(node *left, node *right) {
    node *result = NULL;

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    if (left->data <= right->data) {
        result = left;
        result->link = merge(left->link, right);
    } else {
        result = right;
        result->link = merge(left, right->link);
    }

    return result;
}

node *mergeSort(node *head) {
    if (head == NULL || head->link == NULL)
        return head;

    node *slow = head;
    node *fast = head->link;

    while (fast != NULL && fast->link != NULL) {
        slow = slow->link;
        fast = fast->link->link;
    }

    node *left = head;
    node *right = slow->link;
    slow->link = NULL; 

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

void printList(node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->link;
    }
    cout << "\n";
}

int main() {
	
    int n, value;
    cout << "Enter the number of elements: ";
    cin >> n;

    node *head = NULL;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        head = push(head, value);
    }

    cout << "Unsorted List:\n";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}
