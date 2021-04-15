#include <iostream>
#include <string>
#include<iomanip>
#include "Clothing.h"

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
	cout<<"Product added!"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout<<setw(10)<<"Product Id"<< setw(35) <<"Name"<<setw(20)<<"Type" <<setw(20)<<"Brand"<<setw(10)<< "Price"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout <<setw(10)<< newNode->ID <<setw(35)<< newNode->name<<setw(20)<<newNode->type<<setw(20)<<newNode->brand<<setw(10)<<newNode->price<<endl;
}


void LinkedList::edit(){
	int id, price2, flag=0, visit=0;
	char ch;
	string name2, brand2, type2;
	cout<<"Enter the Product ID"<<endl;
	cin>>id;
	temp =head;
	if(head == NULL)
		cout<<"List is empty!"<<endl;
	else{
		while(temp!=NULL)
		{
			if(temp->ID == id){
				do{
					flag = 0;
				cout<<"What would you like to edit"<<endl<<"1. Name"<<endl<<"2. Type"<<endl<<"3. Brand"<<endl<<"4. Price"<<endl;
				cin>>ch;
				
					switch(ch){
					case '1': cout<<"Enter new Product name"<<endl;
								cin>>name2;
								temp->name = name2;
								break;
					case '2': cout<<"Enter new Product type"<<endl;
								cin>>type2;
								temp->type = type2;
								break;
					case '3': cout<<"Enter new Brand name"<<endl;
								cin>>brand2;
								temp->brand = brand2;
								break;
					case '4': cout<<"Enter new price of the product"<<endl;
								cin>>price2;
								temp->price = price2;
								break;
					default : cout<<" Invalid Entry! Try again!"<<endl;
									flag =1;
					}	//switch ends
				}while(flag == 1);
				
				visit =1;
				cout<<"The product have been updated!"<<endl;
				break;
			}
			
			temp=temp->next;
		}	// while ends
		
		if(visit == 0){
			cout<<"Invalid Product ID "<<endl;
		}
	}
}


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
        temp = head;
		cout<<"-------------------------------------------------------------------------------------------------"<<endl;
		cout<<setw(10)<<"Product Id"<< setw(35) <<"Name"<<setw(20)<<"Type" <<setw(20)<<"Brand"<<setw(10)<< "Price"<<endl;
		cout<<"-------------------------------------------------------------------------------------------------"<<endl;
        while (temp != NULL) {
            cout <<setw(10)<< temp->ID <<setw(35)<< temp->name<<setw(20)<<temp->type<<setw(20)<<temp->brand<<setw(10)<<temp->price<<endl;
            temp = temp->next;
        }
        cout << endl;
    }
}