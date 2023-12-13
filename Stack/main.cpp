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
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display"<<endl;
        cout << "\nEnter choice: "; cin >> choice;
        switch (choice) {
            case 1:
                list.push();
                break;
            case 2:
                list.pop();
                break;
            case 3:
				list.display();
				break;    
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
