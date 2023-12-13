#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct tree {
	
	int info;
	string name;
	
	struct tree *lchild;
	struct tree *rchild;
};

struct control {
	public:
		
		struct tree *root = NULL;
		
		void find(int, tree **parent, tree **location);
		void insert(int, string);
		void del(int);
		void caseA(tree *parent, tree *location);
		void caseB(tree *parent, tree *location);
		void caseC(tree *parent, tree *location);
		tree *search(tree *ptr, int);
		void display(tree *ptr);
};
#endif
