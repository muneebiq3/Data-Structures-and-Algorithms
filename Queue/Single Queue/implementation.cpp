#include<iostream>
#include<stdlib.h>
#include "header.h"
using namespace std;


void control::insert()
    {
    	if(rear_count==size)
    	{
    		cout<<"OverFlow"<<endl;
    		return;
		}
        struct node *tmp = new struct node;
        int pushed_item;

        cout << "Enter value to be pushed: ";
        cin >> pushed_item;

        tmp->data = pushed_item;
        tmp->link = NULL;

        if (rear == NULL)
        {
            front = tmp;
            rear = tmp;
        }
        else
        {
            rear->link = tmp;
            rear = tmp;
        }
        rear_count++;
    }

    void control::del()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            struct node *tmp = front;
            cout << "Popped item is: " << tmp->data << endl;
            front = front->link;

            if (front == NULL)
            {
                rear = NULL;
            }

            delete tmp;
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

            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->link;
            }
            cout << endl;
        }
    }
