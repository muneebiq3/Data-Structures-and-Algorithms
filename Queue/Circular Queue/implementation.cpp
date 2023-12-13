#include<iostream>
#include "header.h"

using namespace std;

void control::insert()
    {
    	if(rear_count == size)
    	{
    		cout<<"Overflow"<<endl;
    		return;
		}
        struct node *tmp = new struct node;
        int pushed_item;

        cout << "Enter value to be inserted: ";
        cin >> pushed_item;

        tmp->num = pushed_item;
        tmp->link = NULL;

        if (rear == NULL)
        {
            front = tmp;
            rear = tmp;
            rear->link=front;
        }
        else
        {
           rear->link=tmp;
           rear=tmp;
           rear->link=front;
        }
    
        rear_count++;
    }

  void control::del()
{
    if (front == NULL)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        cout << "Deleted item is: " << front->num << endl;
        struct node* temp = front;

        if (front == rear)
        {
            
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->link; 
            rear->link = front; 
        }
        delete temp;
        rear_count--;
    }
}

void control::display()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue elements:" << endl;
        struct node *ptr = front;

        do
        {
            cout << ptr->num << " ";
            ptr = ptr->link;
        } while (ptr != front);

        cout << endl;
    }
}
