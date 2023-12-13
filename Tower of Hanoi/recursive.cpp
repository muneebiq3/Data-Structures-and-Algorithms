#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char temp, char destination);

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
	cout << endl;
	
    towerOfHanoi(n, 'S', 'T', 'D');

    return 0;
}
void towerOfHanoi(int n, char source, char temp, char destination) {
    if (n == 1) {
    	cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, temp);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, temp, source, destination);
}
