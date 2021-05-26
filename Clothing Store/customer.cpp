#include <iostream>
#include <set>
#include <string>
#include<iomanip>
#include <algorithm>
#include <sstream>
#include <vector>
#include "Clothing.h"


using namespace std;

void LinkedList :: sort1(int lower, int upper)
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
int LinkedList :: filter(){
    
    int choice, flag=1;
    cout<<"\t \t \t \t \t Select a price ranges from the options given below : "<<endl;
    cout<<"\t \t \t \t \t 1.Rs.500 to Rs.1000"<<endl<<"\t \t \t \t \t 2.Rs.1000 to Rs.1500"<<endl<<"\t \t \t \t \t 3.Rs.1500 to Rs.2000"<<endl;
    cout<<"\t \t \t \t \t ";
	cin>>choice;
	cout<<"\n";
    switch(choice)
	{
        case 1:sort1(500,1000);
		break;
		case 2:sort1(1001,1500);
		break;
		case 3:sort1(1501,2000);
		break;
		default: cout<<"\t \t \t \t \t Invalid entry! \n"<<endl;
				flag = 0;
      }
	return flag;
    
}
int LinkedList :: search(){
  string Input, brand2, name2, type2, tmp;
  set <int> visited;

  int flag=0;
  cout<< "\t \t \t \t \t Search for something... \n"<<endl;
  cout<<"\t \t \t \t \t ";
  cin.ignore();
  getline(cin, Input);
  cout<<"\n";
  transform(Input.begin(), Input.end(), Input.begin(), ::tolower );
  temp = head;
  
  stringstream s(Input);
  vector<string> words;  //vector to store words of string Input
  while( s >> tmp ){     //splits string into tmp words
	  words.push_back(tmp);  //pushes the tmp words into vector words
  }
	  
  if(head == NULL){
      cout<< "\t \t \t \t \t List is empty! \n"<<endl;
  }
  else{
      int counter =1;
      while(temp!= NULL){
          name2 = temp -> name;
          brand2 = temp -> brand;
          type2 = temp -> type;
          transform(name2.begin(), name2.end(), name2.begin(), ::tolower );
          transform(brand2.begin(), brand2.end(), brand2.begin(), ::tolower );
          transform(type2.begin(), type2.end(), type2.begin(), ::tolower );
		  
			for( int i=0; i<words.size(); ++i){   //iterating through each word in vector words
				if(name2.find(words[i]) != string::npos || brand2.find(words[i]) != string::npos || type2.find(words[i]) != string::npos){ 
				  if(visited.count(temp->ID)){
                      continue;
                  }
                   if (counter==1){
					 cout<<"\t -------------------------------------------------------------------------------------------------"<<endl;
					 cout<<"\t "<<setw(10)<<"Product Id"<< setw(35) <<"Name"<<setw(20)<<"Type" <<setw(20)<<"Brand"<<setw(10)<< "Price"<<endl;
					 cout<<"\t -------------------------------------------------------------------------------------------------"<<endl;
					 counter++;
					   }
					 cout <<"\t "<<setw(10)<< temp->ID <<setw(35)<< temp->name<<setw(20)<<temp->type<<setw(20)<<temp->brand<<setw(10)<<temp->price<<endl;
					 flag = 1;
                     visited.insert(temp->ID);
				  }
			}
			 
         
          temp = temp -> next;
     }
      if(flag == 0){
          cout <<"\t \t \t \t \t Product not available! \n "<<endl;
      }
  }
  return flag;

}
void LinkedList::buysearch(LinkedList* cart,int &total)
{
	  int pid;
	  cout<<"\t \t \t \t \t Enter product Id of product to be added to cart."<<endl;
	  cout<<"\t \t \t \t \t ";
	  cin>>pid;
	  cout<<endl;
	  temp = head;
	  if(head == NULL){
		  cout<< "\t \t \t \t \t List is empty"<<endl;
	  }
	  else
	  {
		  while(temp!= NULL)
		  {
			   if(pid==temp->ID)
			   {
					 cart->add(temp->ID,temp->name,temp->brand,temp->type,temp->price);
					 total=total+temp->price;
					 return;
				}
			  temp = temp -> next;
		  }
		  cout <<"\n \t \t \t \t \t Product not available\n"<<endl;
	  }

}



