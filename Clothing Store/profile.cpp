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
        cout << "\t \t \t \t \t List is empty! \n" << endl;
    }
    else {
        temp = head;
		cout<<"\t ----------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\t "<<setw(10)<<"Customer Id"<< setw(25) <<"Name"<<setw(50)<<"Address" <<setw(15)<<"Phone no."<<endl;
		cout<<"\t ----------------------------------------------------------------------------------------------------"<<endl;
        while (temp != NULL) {
            cout <<"\t "<<setw(10)<< temp->CustId <<setw(25)<< temp->CustName<<setw(50)<<temp->address<<setw(15)<<temp->phoneno<<endl;
            temp = temp->link;
        }
        cout << endl;
    }
}
