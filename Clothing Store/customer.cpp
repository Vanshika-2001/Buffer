#include <iostream>
#include <string>
#include<iomanip>
#include <algorithm>
#include "Clothing.h"

using namespace std;

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
      while(temp!= NULL){
          name2 = temp -> name;
          brand2 = temp -> brand;
          type2 = temp -> type;
          if(name2.find(Input) != string::npos || brand2.find(Input) != string::npos || type2.find(Input) != string::npos){
             cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	         cout<<setw(10)<<"Product Id"<< setw(35) <<"Name"<<setw(20)<<"Type" <<setw(20)<<"Brand"<<setw(10)<< "Price"<<endl;
	         cout<<"-------------------------------------------------------------------------------------------------"<<endl;
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
 