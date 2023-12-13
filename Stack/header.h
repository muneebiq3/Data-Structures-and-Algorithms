#include<iostream>
#include<stdlib.h>
#ifndef header_H
#define header_H
using namespace std;

void push();
void pop();
void display();

struct node
{
	int data;
	struct node *link;
};
struct control
{
	public:
		struct node *top=NULL;
		void push();
        void pop();
        void display();  
};
#endif
