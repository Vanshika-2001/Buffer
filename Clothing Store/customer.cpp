#include <iostream>
#include <string>
#include<iomanip>
#include <algorithm>
#include "Clothing.h"


using namespace std;
void LinkedList :: filter(){
    LinkedList *Filter = new LinkedList;

    int choice;
    cout<<"Select a price ranges from the options given below"<<endl;
    cout<<"1.Rs.500 to Rs.1000"<<endl<<"2.Rs.1000 to Rs.1500"<<endl<<"3.Rs.1500 to Rs.2000"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
        {
            while(temp!=NULL){
                if((temp->price>=500)&&(temp->price<=1000)){
                    Filter->add(temp->ID,temp->name,temp->type,temp->brand,temp->price);
                    
                }
            }
        }

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
