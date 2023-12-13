#include <iostream>
#include <queue>
using namespace std;

struct PatientHuffmanNode {
    string name;
    int severity;
    struct PatientHuffmanNode *left;
    struct PatientHuffmanNode *right;
};

PatientHuffmanNode *root = NULL;

struct CompareNodes {
    bool operator()(PatientHuffmanNode *a, PatientHuffmanNode *b) {
        return a->severity > b->severity;
    }
};

priority_queue<PatientHuffmanNode *, vector<PatientHuffmanNode *>, CompareNodes> minHeap;

PatientHuffmanNode *createPatientHuffmanNode(string name, int severity) {
    PatientHuffmanNode *node = new PatientHuffmanNode;
    node->name = name;
    node->severity = severity;
    node->left = node->right = NULL;
    return node;
}

void buildHuffmanTree() {
    while (minHeap.size() > 1) {
        PatientHuffmanNode *left = minHeap.top();
        minHeap.pop();
        PatientHuffmanNode *right = minHeap.top();
        minHeap.pop();

        PatientHuffmanNode *internalNode = createPatientHuffmanNode("Internal", left->severity + right->severity);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    root = minHeap.top();
}

void displayHuffmanTree(PatientHuffmanNode *node, string prefix = "") {
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            cout << "Patient: " << node->name << " - Severity: " << node->severity << " (" << prefix << ")" << endl;
        }
        displayHuffmanTree(node->left, prefix + "0");
        displayHuffmanTree(node->right, prefix + "1");
    }
}

void insertPatient(string name, int severity) {
    PatientHuffmanNode *node = createPatientHuffmanNode(name, severity);
    minHeap.push(node);
}

int main() {
    int choice, severity;
    string name;

    do {
        cout << "\n1. Add Patient\n2. Build Huffman Tree\n3. Display Huffman Tree\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the patient's name: ";
                cin >> name;
                cout << "Enter the severity: ";
                cin >> severity;
                insertPatient(name, severity);
                break;
            case 2:
                buildHuffmanTree();
                cout << "Huffman Tree built successfully.\n";
                break;
            case 3:
                displayHuffmanTree(root);
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


