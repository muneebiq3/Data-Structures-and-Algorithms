#include "header.H"
#include <iostream>

using namespace std;

void control::displayMenuItemDetails(tree* item) {
	
    if (item != NULL) {
        cout << "ID: " << item->id << endl;
        cout << "Name: " << item->name << endl;
        cout << "Dietary Info: " << item->dietaryInfo << endl;
        cout << "Availability: " << (item->availability ? "Available" : "Not Available") << endl;
    } else {
        cout << "Item not found." << endl;
    }
    
}
tree* control::searchByID(tree* ptr, int id) {
	
    if (ptr != NULL) {
        if (id < ptr->id)
            return searchByID(ptr->lchild, id);
        else if (id > ptr->id)
            return searchByID(ptr->rchild, id);
        else {
            displayMenuItemDetails(ptr);
            return ptr;
        }
    } displayMenuItemDetails(NULL);
    
    return NULL;
}

tree* control::searchByName(tree* ptr, const string& name) {
	
    if (ptr != NULL) {
        if (name < ptr->name)
            return searchByName(ptr->lchild, name);
        else if (name > ptr->name)
            return searchByName(ptr->rchild, name);
        else {
            displayMenuItemDetails(ptr);
            return ptr;
        }
    } displayMenuItemDetails(NULL);
    return NULL;
    
}
tree* control::insert(int id, const string& name, const string& dietaryInfo, bool availability, tree* pivotNode, bool* h_inc)
{
	tree *Aptr,*Bptr;
	if(pivotNode==NULL)
	{
	pivotNode=new (struct tree);
	pivotNode->id=id;
	pivotNode->name=name;
	pivotNode->dietaryInfo=dietaryInfo;
	pivotNode->availability=availability;
	pivotNode->lchild=pivotNode->rchild=NULL;
	pivotNode->balance=0;
	*h_inc=true;
	return (pivotNode);
    }
	else if(item<pivotNode->info)
	{
		pivotNode->lchild=insert(item,pivotNode->lchild,h_inc);
		if(*h_inc==true)
		{
		switch(pivotNode->balance)
		{
			case -1:
				pivotNode->balance=0;
				*h_inc=true;
				break;
			case 0:
			pivotNode->balance=1;
			break;
			case 1:
			Aptr=pivotNode->lchild;
			if(Aptr->balance==1)
			{
				cout<<"Left to Left Rotation"<<endl;
				pivotNode->lchild=Aptr->rchild;
				Aptr->rchild=pivotNode;
				pivotNode->balance=0;
				Aptr->balance=0;
				pivotNode=Aptr;
				
			}
			else
			{
				cout<<"Left to Right Rotation"<<endl;
				Bptr=Aptr->rchild;
				Aptr->rchild=Bptr->lchild;
				Bptr->lchild=Aptr;
				pivotNode->lchild=Bptr->rchild;
				Bptr->rchild=pivotNode;
				if(Bptr->balance==1)
				pivotNode->balance=-1;
				else
				pivotNode->balance=0;
				if(Bptr->balance==-1)
				Aptr->balance=1;
				else
				Aptr->balance=0;
				Bptr->balance=0;
				pivotNode=Bptr;
			}
			*h_inc = false;	
		}
	}
   }
   else if(item>pivotNode->info)
   {
   	 pivotNode->rchild=insert(item,pivotNode->rchild,h_inc);
   	 if(*h_inc==true)
   	 {
   	 	switch(pivotNode->balance)
   	 	{
   	 		case 1:
   	 		pivotNode->balance=0;
			*h_inc=true;
			break;
			case 0:
			pivotNode->balance=1;
			break;
			case -1:
			Aptr=pivotNode->rchild;
			if(Aptr->balance==1)
			{
			   cout<<"Right to Right Rotation"<<endl;
			   pivotNode->rchild=Aptr->lchild;
			   Aptr->lchild=pivotNode;
			   pivotNode->balance=0;
			   Aptr->balance=0;
			   Aptr=pivotNode;
			  	
		    }
			else
			{
			    cout<<"Right to Left Rotation"<<endl;
				Bptr=Aptr->lchild;
				Aptr->lchild=Bptr->rchild;
				Bptr->rchild=Aptr;
				pivotNode->rchild=Bptr->lchild;
				Bptr->lchild=pivotNode;
				if(Bptr->balance==-1)
				pivotNode->balance=1;
				else
				pivotNode->balance=0;
				if(Bptr->balance==1)
				Aptr->balance=-1;
				else
				Aptr->balance=0;
				Bptr->balance=0;
				pivotNode=Bptr;
				
		}
			*h_inc=false;		
		}
	 }
   }
   else {
        
        cout << "Duplicate value not allowed: " << item << endl;
        *h_inc = false; 
    }
   return pivotNode; 
}
void control::display(tree *root)
{
	if(root!=NULL)
	{
		display(root->lchild);
		cout<<"ID:"<<root->id<<" "<<"NAME"<<root->name<<" "<<"Dietary-INFO"<<root->dietaryInfo<<endl;
		display(root->rchild);
	}
}
