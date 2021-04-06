#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Clothing.h"
#include<iostream>
using namespace std;
class Customer : public Clothing{
    string address;
    string CustName;
    int CustId;
    long phoneno;

    public:
        //clothing class add display functn
        void filter(); //search the products by price range and display in sorted form
        void search(int ID);
        void buy(int ID);
        void profile();
};
#endif