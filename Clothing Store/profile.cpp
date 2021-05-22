#include <iostream>
#include <string>
#include<iomanip>
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
void CustLinkedList::display_profile(){
	if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        temp = head;
		cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<setw(10)<<"Customer Id"<< setw(25) <<"Name"<<setw(50)<<"Address" <<setw(15)<<"Phone no."<<endl;
		cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
        while (temp != NULL) {
            cout <<setw(10)<< temp->CustId <<setw(25)<< temp->CustName<<setw(50)<<temp->address<<setw(15)<<temp->phoneno<<endl;
            temp = temp->link;
        }
        cout << endl;
    }
}
