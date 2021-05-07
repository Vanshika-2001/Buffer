#include <iostream>
#include <string>
#include<iomanip>
#include <algorithm>
#include "Clothing.h"


using namespace std;

void LinkedList :: sort(int lower, int upper)
{
    LinkedList *Filter = new LinkedList();//creates new object of linked list class for sorted list
	Node *FilterH = NULL; //head to the new LL
	Node *current = NULL;// current pointer for neew LL
    Node *newnode = NULL;// pointer to store address of newly created node
    temp = head;// pointers of original linkedlist
	//while block iterates through original linked list
	 while(temp != NULL )
	{
		// if block checks if node is in given price range
        if( (temp -> price >= lower) && (temp -> price <= upper))
		{
			// creation of new node and copying the data from node in original linked list
            newnode = new Node();
            newnode->ID = temp -> ID;
	        newnode->name = temp ->name;
	        newnode->type = temp->type;
	        newnode->brand = temp ->brand;
	        newnode->price = temp ->price;
			// Conditions to insert the new node in appropriate position
            if (FilterH == NULL || (FilterH)->price >= newnode->price)
            {
                newnode->next = FilterH;
                FilterH = newnode;
            }
            else
            {
                /* Locate the node before the point of insertion */
                current = FilterH;
                while (current->next!=NULL &&
                    current->next->price < newnode->price)
                {
                    current = current->next;
                }
                newnode->next = current->next;
                current->next = newnode;
				
            }

            }
        temp = temp -> next; 
    }
	//Assigning the head of  our new linked list to the head in the new linked lists object
	Filter->head=FilterH;
	/*if(FilterH==NULL)
	{
		cout<<"Products not available in the given price range"<<endl;
	}*/
    Filter -> display(); //calling display function to display items in given range
    
    
}
void LinkedList :: filter(){
    
    int choice;
    cout<<"Select a price ranges from the options given below"<<endl;
    cout<<"1.Rs.500 to Rs.1000"<<endl<<"2.Rs.1000 to Rs.1500"<<endl<<"3.Rs.1500 to Rs.2000"<<endl;
    cin>>choice;

    switch(choice)
	{
        case 1:sort(500,1000);
		break;
		case 2:sort(1001,1500);
		break;
		case 3:sort(1501,2000);
		break;
		default: cout<<"Invalid entry"<<endl;
        
      }

    
}
void LinkedList :: search(){
  string Input, brand2, name2, type2;
  cout<< "Search for something"<<endl;
  cin>> Input;
  transform(Input.begin(), Input.end(), Input.begin(), ::tolower );
  temp = head;
  if(head == NULL){
      cout<< "List is empty"<<endl;
  }
  else{
      int flag = 0;
      int counter =1;
      while(temp!= NULL){
          name2 = temp -> name;
          brand2 = temp -> brand;
          type2 = temp -> type;
          transform(name2.begin(), name2.end(), name2.begin(), ::tolower );
          transform(brand2.begin(), brand2.end(), brand2.begin(), ::tolower );
          transform(type2.begin(), type2.end(), type2.begin(), ::tolower );

          if(name2.find(Input) != string::npos || brand2.find(Input) != string::npos || type2.find(Input) != string::npos){
               if (counter==1){
                cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	         cout<<setw(10)<<"Product Id"<< setw(35) <<"Name"<<setw(20)<<"Type" <<setw(20)<<"Brand"<<setw(10)<< "Price"<<endl;
	         cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	         counter++;
               }
             cout <<setw(10)<< temp->ID <<setw(35)<< temp->name<<setw(20)<<temp->type<<setw(20)<<temp->brand<<setw(10)<<temp->price<<endl;
             flag = 1;

          }
          temp = temp -> next;
     }
      if(flag == 0){
          cout <<"Product not available"<<endl;
      }
  }


}
