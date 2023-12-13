#include <iostream>
#include<cstdlib>
#include<string>
#include "header.h"
using namespace std;
int main()
{
	int choice;
	control list;
    while(1) {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display"<<endl;
        cout << "\nEnter choice: " << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                list.insert();
                break;
            case 2:
                list.del();
                break;
            case 3:
				list.display();
				break;    
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
