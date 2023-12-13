#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct tree {
	
	int info;
	
	struct tree *lchild = NULL;
	struct tree *rchild = NULL;
};

struct queue {
	
	struct tree *root= NULL;
	
	struct queue *link = NULL;
	
};

struct control {
	public:
		
		struct queue *front = NULL;
		struct queue *rear = NULL;
		
		void populateQueue(tree *tree);
		void swap();
		tree *pop();
		void inorder(tree *root, int);
		void buildTree();
		void display();

};
#endif
