#include <iostream>
#include <graphics.h>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Function to append a node at the end of the linked list
void append(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to initialize graphics window
void initGraphics() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
}

// Function to close graphics window
void closeGraphics() {
    closegraph();
}

// Function to draw the linked list in the graphics window
void drawList(Node* unsortedHead, Node* sortedHead) {
    cleardevice();
    int x = 100, y = 100;

    // Draw unsorted list
    setcolor(WHITE);
    outtextxy(50, 50, "Unsorted List:");

    Node* temp = unsortedHead;
    while (temp) {
        char str[10];
        sprintf(str, "%d", temp->data);

        rectangle(x, y, x + 30, y + 30);
        outtextxy(x + 10, y + 10, str);

        x += 40;
        temp = temp->next;
    }

    // Draw sorted list
    x = 100;
    y = 200;
    setcolor(YELLOW);
    outtextxy(50, 180, "Sorted List:");

    temp = sortedHead;
    while (temp) {
        char str[10];
        sprintf(str, "%d", temp->data);

        rectangle(x, y, x + 30, y + 30);
        outtextxy(x + 10, y + 10, str);

        x += 40;
        temp = temp->next;
    }

    delay(1000); // Add a delay to see the visualization
}

// Function to perform counting sort on a specific digit
void countingSort(Node* head, int exp) {
    const int base = 10;
    Node* output[base] = {NULL};
    Node* temp = head;
    Node* sortedList = NULL;

    // Count occurrences of each digit
    while (temp) {
        int index = (temp->data / exp) % base;
        append(output[index], temp->data);
        temp = temp->next;
    }

    // Concatenate the output lists
    for (int i = 0; i < base; i++) {
        while (output[i]) {
            append(sortedList, output[i]->data);
            Node* tempNode = output[i];
            output[i] = output[i]->next;
            delete tempNode;
        }
    }

    temp = head;
    Node* sortedTemp = sortedList;
    while (temp && sortedTemp) {
        temp->data = sortedTemp->data;
        temp = temp->next;
        sortedTemp = sortedTemp->next;
    }

    // Free memory allocated for the sorted list
    temp = sortedList;
    while (temp) {
        Node* tempNode = temp;
        temp = temp->next;
        delete tempNode;
    }

    // Display the state of the linked list after each pass
    cout << "After pass (exp = " << exp << "): ";
//    printList(head);
    
    drawList(head, sortedList);
}

// Radix Sort function
Node* radixSort(Node* head) {
    // Find the maximum number to know the number of digits
    int max = head->data;

    Node* temp = head;
    while (temp) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    // Copy the unsorted list to keep it unchanged
    Node* sortedHead = NULL;
    temp = head;
    while (temp) {
        append(sortedHead, temp->data);
        temp = temp->next;
    }

    // Perform counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(sortedHead, exp);
    }

    return sortedHead;
}

int main() {
    Node* unsortedHead = NULL;
    Node* sortedHead = NULL;
    int choice;

    initGraphics();

    do {
        cout << "Menu:" << endl;
        cout << "1. Add element to the linked list" << endl;
        cout << "2. Perform Radix Sort" << endl;
        cout << "3. Print the linked list" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "Enter the element to add: ";
                cin >> element;
                append(unsortedHead, element);
                drawList(unsortedHead, sortedHead);
                break;
            }

            case 2:
                cout << "Performing Radix Sort..." << endl;
                sortedHead = radixSort(unsortedHead);
                break;
            
            case 3:
                drawList(unsortedHead, sortedHead);
                break;
            
            case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    closeGraphics();

    return 0;
}
