#ifndef Clothing_H
#define Clothing_H
#include<iostream>
#include<string>

using namespace std;
class Node {
	public:
	//data
	 int ID;
	 string name;
	 string type;
	 string brand;
	 int price;
	 int mode;
	//next pointer
	Node *next;
};
class  LinkedList{
	private:
		Node *head;
		Node *temp;
	public:
		LinkedList(){
			head = NULL;
			temp = head;
		}

	//Seller functions
	void add(int ID, string name, string type, string brand, int price);
	void add(int ID, string name, string type, string brand, int price,int mode);
	void edit();
	void del();

	void display();

	//Customer Functions
	 void sort1(int,int);
	 int filter(); 	//search the products by price range and display in sorted form
     int search();
	 void buysearch(LinkedList*,int &);
     //void Buy();
	

};

#endif
