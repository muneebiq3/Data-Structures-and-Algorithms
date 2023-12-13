#ifndef header_H
#define header_H

#include<iostream>

using namespace std;

struct node
{
	int num;
	struct node *link;
};

struct control
{
	public:
		struct node *front=NULL;
		struct node *rear=NULL;
		int size = 10;
		int rear_count = 0;
		
		void insert();
        void del();
        void display();
};

#endif
