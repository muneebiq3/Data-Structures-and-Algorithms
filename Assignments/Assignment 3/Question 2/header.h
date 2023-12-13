#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct tree {
	
	int id, balance;
	string name, dietaryInfo;
	bool availability;
	
};

struct control {
	
	public:
		struct tree *lchild = NULL;
		struct tree *rchild = NULL;
		
		void displayMenuItemDietaryInfo(tree *item);
		tree *searchByID(tree *root, int);
		tree *searchByName(tree *root, string &name);
		tree *insert(int, string &name, string &dietaryInfo, bool, tree* pivotNode, bool* h_inc);
	
};
#endif
