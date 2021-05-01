#ifndef PROFILE_H
#define PROFILE_H
#include "Clothing.h"
#include<iostream>
#include<string>

using namespace std;
class CustNode{
	public:
	 string address;
    string CustName;
    int CustId;
    long phoneno;

	Node *link;
}
class  CustLinkedList{
	private:
		CustNode *head;
		CustNode *temp;
	public:
		CustLinkedList(){
			head = NULL;
			temp = head;
		}
		void addCust();//function to add details of predefined customers' profile
		void display_profile();
};
#endif
