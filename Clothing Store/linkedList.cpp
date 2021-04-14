#include <iostream>
#include <string>
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
	cout<<"Product added!!"<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	cout<<"Product Id\t Name\t Type\t Brand\t Price"<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
    cout << newNode->ID <<"\t\t"<< newNode->name<<"\t "<<newNode->type<<"\t "<<newNode->brand<<"\t "<<newNode->price<<endl;

}

void edit();
void del();
void LinkedList::display(){
	if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        Node* t = head;
		cout<<"----------------------------------------------------------------------------"<<endl;
		cout<<"Product Id\t Name\t Type\t Brand\t Price"<<endl;
		cout<<"----------------------------------------------------------------------------"<<endl;
        while (t != NULL) {
            cout << t->ID <<"\t\t"<< t->name<<"\t "<<t->type<<"\t "<<t->brand<<"\t "<<t->price<<endl;
            t = t->next;
        }
        cout << endl;
    }
}