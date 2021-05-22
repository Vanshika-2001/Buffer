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
	cout<<"\t \t \t \t \t Product added!"<<endl;
	cout<<"\t ----------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t "<<setw(10)<<"Product Id"<< setw(35) <<"Name"<<setw(20)<<"Type" <<setw(20)<<"Brand"<<setw(13)<< "Price (Rs)"<<endl;
	cout<<"\t ----------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t " <<setw(10)<< newNode->ID <<setw(35)<< newNode->name<<setw(20)<<newNode->type<<setw(20)<<newNode->brand<<setw(13)<<newNode->price<<endl;
}


void LinkedList::edit(){
	int id, price2, flag=0, visit=0;
	char ch;
	string name2, brand2, type2;
	cout<<"\t \t \t \t \t Enter the Product ID"<<endl;
	cout<<"\t \t \t \t \t ";
	cin>>id;
	cout<<"\n";
	temp =head;
	if(head == NULL)
		cout<<"\t \t \t \t \t List is empty!"<<endl;
	else{
		while(temp!=NULL)
		{
			if(temp->ID == id){
				do{
					flag = 0;
				cout<<"\t \t \t \t \t What would you like to edit"<<endl<<"\t \t \t \t \t 1. Name"<<endl<<"\t \t \t \t \t 2. Type"<<endl<<"\t \t \t \t \t 3. Brand"<<endl<<"\t \t \t \t \t 4. Price (Rs) \n"<<endl;
				cout<<"\t \t \t \t \t ";
				cin>>ch;
				cout<<"\n";
				
					switch(ch){
					case '1': cout<<"\n \t \t \t \t \t Enter new Product name"<<endl;
								cout<<"\t \t \t \t \t ";
								cin>>name2;
								cout<<"\n";
								temp->name = name2;
								break;
					case '2': cout<<"\n \t \t \t \t \t Enter new Product type"<<endl;
								cout<<"\t \t \t \t \t ";
								cin>>type2;
								cout<<"\n";
								temp->type = type2;
								break;
					case '3': cout<<"\n \t \t \t \t \t Enter new Brand name"<<endl;
								cout<<"\t \t \t \t \t ";
								cin>>brand2;
								cout<<"\n";
								temp->brand = brand2;
								break;
					case '4': cout<<"\n \t \t \t \t \t Enter new price of the product"<<endl;
								cout<<"\t \t \t \t \t ";
								cin>>price2;
								cout<<"\n";
								temp->price = price2;
								break;
					default : cout<<"\n \t \t \t \t \t  Invalid Entry! Try again!"<<endl;
									flag =1;
					}	//switch ends
				}while(flag == 1);
				
				visit =1;
				cout<<"\t \t \t \t \t The product have been updated! \n"<<endl;
				break;
			}
			
			temp=temp->next;
		}	// while ends
		
		if(visit == 0){
			cout<<"\t \t \t \t \t Invalid Product ID \n"<<endl;
		}
	}
}


void LinkedList:: del()
{
	int id;
	cout<<"\t \t \t \t \t Enter the ID of the product you want to delete."<<endl;
	cout<<"\t \t \t \t \t ";
	cin>>id;
	cout<<"\n";
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
		cout<<"\t \t \t \t \t Product "<<id<<" was not in the list."<<endl;
		delete delptr;
	}
	else if(curr==head)
	{  
        delptr=head;
		head=head->next;
		delete delptr;
		cout<<"\t \t \t \t \t Product "<<id<<" was deleted successfully."<<endl;
	}
	else
	{
		delptr=curr;
		curr=curr->next;
		temp->next=curr;
		delete delptr;
		cout<<"\t \t \t \t \t Product "<<id<<" was deleted successfully."<<endl;
	}
	
}


void LinkedList::display(){
	if (head == NULL) {
        cout << "\t \t \t \t \t List is empty!" << endl;
    }
    else {
        temp = head;
		cout<<"\t ----------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\t "<<setw(10)<<"Product Id"<< setw(35) <<"Name"<<setw(20)<<"Type" <<setw(20)<<"Brand"<<setw(13)<< "Price (Rs)"<<endl;
		cout<<"\t ----------------------------------------------------------------------------------------------------"<<endl;
        while (temp != NULL) {
            cout <<"\t "<<setw(10)<< temp->ID <<setw(35)<< temp->name<<setw(20)<<temp->type<<setw(20)<<temp->brand<<setw(13)<<temp->price<<endl;
            temp = temp->next;
        }
        cout << endl;
    }
}