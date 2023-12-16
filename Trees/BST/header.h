#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct node {
	
	int info;
	
	struct node *lchild;
	struct node *rchild;
};

struct control {
	public:
		
		struct node *root = NULL;
		
		void find(int, node **parent, node **location);
		void insert();
		void del();
		void caseA(node *parent, node *location);
		void caseB(node *parent, node *location);
		void caseC(node *parent, node *location);
		void preorder(node *ptr);
		void inorder(node *ptr);
		void postorder(node *ptr);
};
#endif
