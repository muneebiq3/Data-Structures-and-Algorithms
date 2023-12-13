#include<iostream>
#include<stdlib.h>
#ifndef header_H
#define header_H
using namespace std;



struct node
{
	int data;
	struct node *link;
};
struct control
{
	public:
		struct node *front=NULL;
		struct node *rear=NULL;
		int size;
		int rear_count;
		void insert();
        void del();
        void display();
		   control() : size(3), rear_count(0)
    {
    }
};
#endif
