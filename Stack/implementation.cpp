#include <iostream>
#include "header.h"
#include <conio.h>
using namespace std;

void control::push()
{
	struct node *tmp;
	int pushed_item;
	tmp=new(struct node);
	cout<<"Enter value to be pushed: ";
	cin>>pushed_item;
	tmp->data=pushed_item;
	tmp->link=top;
	top=tmp;
	getch();
	system("cls");
}
void control::pop()
{
	struct node *tmp;
	if(top == NULL)
	{
		cout<<"Stack is empty!"<<endl;
	}
	else
	{
		tmp=top;
		cout<<"popped item is: "<<tmp->data<<endl;
		top=top->link;
		delete(tmp);
		
	}
	getch();
	system("cls");
}
void control::display()
{
	struct node *ptr;
	ptr=top;
	if(top == NULL)
	{
		cout<<"Stack is empty"<<endl;
	}
	else
	{
		cout<<"Stack elements:"<<endl;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->link;
		}
	}
	getch();
	system("cls");
}
