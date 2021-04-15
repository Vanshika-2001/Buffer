#ifndef CUSTOMER_H
#define CUSTOMER_H
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
		void display_profile();
};
#endif