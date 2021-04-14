#include <iostream>
#include <string>
#include<iomanip>
#include "linkedList.h"

using namespace std;

void LinkedList::add(int id, string Name, string Type, string Brand, int Price){
	Node *newNode =  new Node();
	newNode->ID = id;
	newNode->name = Name;
	newNode->type = Type;
	newNode->brand = Brand;
	newNode->price = Price;
	
	newNode->next = NULL;
	if(head == NULL){
		head = newNode;
		temp = newNode;
	}
	else{
		temp->next = newNode;
		temp = newNode;
	}
	
}
// display version of add function (Polymorphism)
void LinkedList::add(int id, string Name, string Type, string Brand, int Price,int mode){
	Node *newNode =  new Node();
	newNode->ID = id;
	newNode->name = Name;
	newNode->type = Type;
	newNode->brand = Brand;
	newNode->price = Price;
	
	newNode->next = NULL;
	if(head == NULL){
		head = newNode;
		temp = newNode;
	}
	else{
		temp->next = newNode;
		temp = newNode;
	}
	cout<<"Product added!!"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<setw(10)<<"Product Id"<< setw(35) <<"Name"<<setw(20)<<"Type" <<setw(20)<<"Brand"<<setw(10)<< "Price"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout <<setw(10)<< newNode->ID <<setw(35)<< newNode->name<<setw(20)<<newNode->type<<setw(20)<<newNode->brand<<setw(10)<<newNode->price<<endl;
}

void edit();
void LinkedList:: del()
{
	int id;
	cout<<"Enter the ID of the product you want to delete."<<endl;
	cin>>id;
	Node* delptr=NULL;
	temp=head;
	Node* curr=head;
	while(curr!=NULL && curr->ID!=id)
	{
		temp=curr;
		curr=curr->next;
	}
	if(curr==NULL)
	{
		cout<<"Product "<<id<<" was not in the list."<<endl;
		delete delptr;
	}
	else if(curr==head)
	{  
        delptr=head;
		head=head->next;
		delete delptr;
		cout<<"Product "<<id<<" was deleted successfully."<<endl;
	}
	else
	{
		delptr=curr;
		curr=curr->next;
		temp->next=curr;
		delete delptr;
		cout<<"Product "<<id<<" was deleted successfully."<<endl;
	}
	

}
void LinkedList::display(){
	if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        Node* t = head;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<setw(10)<<"Product Id"<< setw(35) <<"Name"<<setw(20)<<"Type" <<setw(20)<<"Brand"<<setw(10)<< "Price"<<endl;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        while (t != NULL) {
            cout <<setw(10)<< t->ID <<setw(35)<< t->name<<setw(20)<<t->type<<setw(20)<<t->brand<<setw(10)<<t->price<<endl;
            t = t->next;
        }
        cout << endl;
    }
}