#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct MaxHeap {
    int arr[MAX_SIZE];
    int size;
};
void set(MaxHeap &heap, int root);


void find(int item, MaxHeap &heap, int &parent, int &location) {
    location = -1;
    for (int i = 0; i < heap.size; ++i) {
        if (item == heap.arr[i]) {
            location = i;
            break;
        }
    }

    if (location == -1) {
        parent = -1;
        return;
    }

    
    parent = (location - 1) / 2;
}

void insert(int item, MaxHeap &heap) {
    int parent, location;

    find(item, heap, parent, location);

    if (location != -1) {
        cout << "Waiter ID already inserted in the heap." << endl;
        return;
    } else {
        if (heap.size == MAX_SIZE) {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }

        int index = heap.size;
        heap.size++;

        heap.arr[index] = item;

       
        while (index != 0 && heap.arr[index] > heap.arr[parent]) {
            swap(heap.arr[index], heap.arr[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
}

void deleteWaiters(MaxHeap &heap, int *deleteWaiterIds, int numToDelete) {
    for (int i = 0; i < numToDelete; ++i) {
        int waiterId = deleteWaiterIds[i];
        int parent, location;

        find(waiterId, heap, parent, location);

        if (location != -1) {
            
            heap.arr[location] = heap.arr[heap.size - 1];
            heap.size--;

          
            for (int i = heap.size / 2 - 1; i >= 0; i--) {
                set(heap, i);
            }
        } else {
            cout << "Waiter ID " << waiterId << " not found in the heap." << endl;
        }
    }
}

void set(MaxHeap &heap, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < heap.size && heap.arr[left] > heap.arr[largest]) {
        largest = left;
    }

    if (right < heap.size && heap.arr[right] > heap.arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(heap.arr[root], heap.arr[largest]);
        set(heap, largest);
    }
}

void displayHeap(const MaxHeap &heap) {
    cout << "Current Max Heap: ";
    for (int i = 0; i < heap.size; ++i) {
        cout << heap.arr[i] << " ";
    }
    cout << endl;
}

int main() {
    MaxHeap heap;
    heap.size = 0;

    int choice, waiterID;
    int newWaiterIds[] = {7, 19};
    int deleteWaiterIds[] = {64, 31};

   
    for (int i = 0; i < 9; ++i) {
        insert(newWaiterIds[i], heap);
    }

    do {
        cout << "\n1. Insert New Waiter ID\n2. Fire Waiters\n3. Display Heap\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the New Waiter ID: ";
                cin >> waiterID;
                insert(waiterID, heap);
                break;
            case 2:
                deleteWaiters(heap, deleteWaiterIds, 2);
                break;
            case 3:
                displayHeap(heap);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

