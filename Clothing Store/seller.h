#include "Clothing.h"
#include<iostream>
class Seller: public Clothing 
{ 
     public:
	 void add(Clothing);
	 void edit();
	 void del();
     
};
// This class includes the declarations of the functions for seller class .