#include <iostream>
#include <string>
#include "Clothing.h"
#include "profile.h"
using namespace std;
void CustLinkedList::addCust(int id, string Name, string Address,long Phoneno){
	CustNode *newCust =  new CustNode();
	newCust->CustId = id;
	newCust->CustName = Name;
	newCust->address = Address;
	newCust->phoneno = Phoneno;


	newCust->link = NULL;
	if(head == NULL){
		head = newCust;
		temp = newCust;
	}
	else{
		temp->link = newCust;
		temp = newCust;
	}

}
