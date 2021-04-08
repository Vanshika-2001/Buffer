#include <iostream>
#include <string>
//#include "Clothing.h"
//#include "seller.h"
using namespace std;
int main(){
    int ch;     //choice
    char ans;   //yes or no for continuing in the do while loop
    cout<<"Welcome to Clothing Store"<<endl;
    do{
        cout<<"Are you a Customer or Seller"<<endl;
        cout<<"1.Customer"<<endl<<"2.Seller"<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1: 
                //login part
                int ch1;    //choice for the customer menu
                do
                {
                    cout<<"What would you like to do today?"<<endl;
                    cout<<"1.Display All Products"<<endl<<"2.Filter the Products by price"<<endl<<"3.Search for a product"<<endl<<"4.Buy A Product"<<endl<<"5.Display Profile"<<endl;
                    cin>>ch1;

                    switch (ch1)
                    {
                        case 1:
                        //display function call
                        break;
                        case 2:
                        //filter function call
                        break;
                        case 3:
                        //search function call
                        break;
                        case 4:
                        //buy function call
                        break;
                        case 5:
                        //display profile function call
                        break;
                        default:cout<<"Invalid Entry"<<endl<<"Enter number from the given menu"<<endl;
                    }       //switch ends ch ,the customer choice

                    if((ch1>=1)&&(ch1<=5))
                    {
                        cout<<"Do you want to continue(y/n)"<<endl;
                        cin>>ans;
                    }
                }  while(((ch1<1) || (ch1>5))||(ans=='y'));       // do while ends for customer menu

                break;

            case 2:
                int ch2;//for seller as choice
                do
                {
                    cout<<"What would you like to do today?"<<endl;
                    cout<<"1.Add a product"<<endl<<"2.Delete a Product"<<endl<<"3.Edit details of a product"<<endl<<"4.Display all the products"<<endl;
                    cin>>ch2;

                    switch (ch2)
                    {
                        case 1:
                        //add function call
                        break;
                        case 2:
                        //delete function call
                        break;
                        case 3:
                        //edit function call
                        break;
                        case 4:
                        //display function call
                        break;
                        default:cout<<"Invalid Entry"<<endl<<"Enter number from the given menu"<<endl;
                    }   //switch ends

                    if((ch2>=1)&&(ch2<=4))
                    {
                        cout<<"Do you want to continue?(y/n)"<<endl;
                        cin>>ans;
                    }
                } while(((ch2<1) || (ch2>4)) || (ans=='y'));        //do while ends for ch2 seller

                break;

            default:    cout<<"Invalid Entry"<<endl<<"Enter number from given options"<<endl;

        }       //switch ends for the main menu where user choses between customer and seller

    } while ((ch<1) || (ch>2));         //do while ends for ch,the initial choice

}//main ends