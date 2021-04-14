#ifndef linkedList_H
#define linkedList_H
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
	void add(int ID, string name, string type, string brand, int price);
	void add(int ID, string name, string type, string brand, int price,int mode);
	void edit();
	void del();
	void display();
};

#endif