#include <iostream>
#include <conio.h>
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
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                list.insert();
                getch();
                system("cls");
                break;
            case 2:
                list.del();
                getch();
                system("cls");
                break;
            case 3:
				list.display();
				getch();
                system("cls");
				break;    
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
