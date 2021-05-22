#include <iostream>
#include <string>
#include<stdlib.h>
#include "Clothing.h"
#include "profile.h"
using namespace std;
LinkedList* cart= new LinkedList();
LinkedList* list = new LinkedList();
int totalamount=0;
void addtocart()
{
	int opt;
	char a;
	cout<<"\n \t \t \t \t \t Do you want to add to cart?"<<endl;
	cout<<"\t \t \t \t \t 1.Yes\n\t \t \t \t \t 2.No \n"<<endl;
	cout<<"\t \t \t \t \t ";
	cin>>opt;
	cout<<endl;
	do
	{
		
		if(opt==1)
		{
			list->buysearch(cart,totalamount);
		}
		else
		{
			break;
		}
		cout<<"\t \t \t \t \t Do you want to add more products to the cart?(y/n)"<<endl;
		cout<<"\t \t \t \t \t ";
		cin>>a;
		cout<<endl;
	}while(a=='y');
}

int main(){
	
	
	CustLinkedList* profiles = new CustLinkedList();
	profiles ->addCust(1,"Vanshika","Gaur City,Noida,Delhi 201390",802197474);
	/*profiles ->addCust(2,"Vijitha","Gaur City,Pune 411080",802197494);
	profiles ->addCust(3,"Shreya","Pink City,Pune 456178",802187474);
	profiles ->addCust(4,"Fatma","Rock City,Pune 401390",803197474);*/

	list->add(1,"Grey printed round neck t-shirt","Western wear","Levi's",800);
	list->add(2,"Bandhani printed kurta","Ethnic wear","Biba",1200);
	list->add(3,"Sneakers","Footwear","Roadster",1300);
	list->add(4,"Captain America t-shirt","Kidswear","Pantaloons",700);
	list->add(5,"Slimfit jeans","Menswear","H&M",1500);
	list->add(6,"Boyfriend jeans","Womenswear","Pantaloons",1800);
	//int opt;
    char ch;   	//choice
	int visit = 0;
    char ans;   //yes or no for continuing in the do while loop
    cout<<"\n \n \t \t \t \t \t Welcome to Clothing Store!\n "<<endl;
	cout<<"\t ----------------------------------------------------------------------------------------------------\n"<<endl;
    do{
		visit = 0;
        cout<<"\t \t \t \t \t Are you a Customer or Seller? \n"<<endl;
        cout<<"\t \t \t \t \t 1.Customer"<<endl<<"\t \t \t \t \t 2.Seller \n"<<endl;
		cout<<"\t \t \t \t \t ";
        cin>>ch;
		cout<<"\n";
        switch (ch)
        {
            case '1':
                //login part
                char ch1;    //choice for the customer menu
                do
                {
					visit = 0;
                    cout<<"\t \t \t \t \t What would you like to do today?\n"<<endl;
                    cout<<"\t \t \t \t \t 1.Display All Products"<<endl<<"\t \t \t \t \t 2.Filter the Products by price"<<endl<<"\t \t \t \t \t 3.Search for a product"<<endl<<"\t \t \t \t \t 4.Buy Now"<<endl<<"\t \t \t \t \t 5.Display Profile \n"<<endl;
                    cout<<"\t \t \t \t \t ";
					cin>>ch1;
					cout<<"\n";
                    switch (ch1)
                    {
                        case '1':
                        {   //display function call
						    list ->display();
							addtocart();
						   
						}
                        break;

                        case '2':
                         //filter function call
						 {  
						    list->filter();
					        addtocart();
						 }
                        break;

                        case '3':
                        //search function call
						{
							list ->search();
							addtocart();
						}
					   			   
                        break;

                        case '4':
                        //buy function call
						{
							char confirm;
							cout<<"\t \t \t \t \t The following products have been added to your cart \n"<<endl;
							cart->display();
							cout<<" \t \t \t \t \t \t \t \t \t\t\t----------------------"<<endl;
							cout<<"\t \t \t \t \t \t \t \t\t		Total amount: Rs. "<<totalamount<<endl;
							cout<<" \t \t \t \t \t \t \t \t \t\t\t----------------------\n"<<endl;
							cout<<"\t \t \t \t \t Would you like to place your order?(y/n)"<<endl;
							cout<<"\t \t \t \t \t ";
							cin>>confirm;
							cout<<"\n";
							if(confirm=='y')
							{
								cout<<"\t \t \t \t \t Your order has been placed!\n\t \t \t \t \t Your order will be delivered to you between 5 to 10 business days."<<endl;
								cout<<"\t \t \t \t \t Thanks for shopping with us! Enjoy your day :)"<<endl;
								exit(0);
							}
						}
                        break;

                        case '5':
                        //display profile function call
						profiles->display_profile();
                        break;

                        default:cout<<"Invalid Entry"<<endl<<"Enter number from the given menu"<<endl;
										visit =1;
                    }       //switch ends ch ,the customer choice

                    if(visit == 0)
                    {
                        cout<<"\t \t \t \t \t Go to Main Menu? (y/n)"<<endl;
						cout<<"\t \t \t \t \t ";
                        cin>>ans;
						cout<<"\n";
                    }

                } while((visit == 1) ||(ans=='y'));       // do while ends for customer menu

                break;

            case '2':
                char ch2;//for seller as choice

                do
                {
					visit = 0;
                    cout<<"\t \t \t \t \t What would you like to do today?"<<endl;
                    cout<<"\t \t \t \t \t 1.Add a product"<<endl<<"\t \t \t \t \t 2.Delete a Product"<<endl<<"\t \t \t \t \t 3.Edit details of a product"<<endl<<"\t \t \t \t \t 4.Display all the products"<<endl<<"\t \t \t \t \t 5.Exit \n"<<endl;
                    cout<<"\t \t \t \t \t ";
					cin>>ch2;
					cout<<"\n";
                    switch (ch2)
                    {
                        case '1':
                        //add function call
						{
						    int ID,price;
							string name,type,brand;
							cout<<"\n \t \t \t \t \t Enter the product ID:"<<endl;
							cout<<"\t \t \t \t \t ";
							cin>>ID;
							cout<<"\n";
							cout<<"\n \t \t \t \t \t Enter the product name:"<<endl;
							cout<<"\t \t \t \t \t ";
							cin>>name;
							cout<<"\n";
							cout<<"\n \t \t \t \t \t Enter the product type:"<<endl;
							cout<<"\t \t \t \t \t ";
							cin>>type;
							cout<<"\n";
							cout<<"\n \t \t \t \t \t Enter the product brand:"<<endl;
							cout<<"\t \t \t \t \t ";
							cin>>brand;
							cout<<"\n";
							cout<<"\n \t \t \t \t \t Enter the price of product:"<<endl;
							cout<<"\t \t \t \t \t ";
							cin>>price;
							cout<<"\n";
							list->add(ID,name,type,brand,price,1);
						}
						break;

                        case '2':
							//delete function call
						    list->del();
                        break;

                        case '3':
							//edit function call
							list->edit();
                        break;

                        case '4':
							//display function call
							list->display();
						break;
						
						case '5': exit(0);
						break;
						
                        default :	cout<<"\t \t \t \t \t Invalid Entry! \n"<<endl<<"\t \t \t \t \t Enter number from the given menu"<<endl;
										visit=1;
                    }   //switch ends

                    if(visit == 0)
                    {
                        cout<<"\n \t \t \t \t \t Go to Main Menu ?(y/n)"<<endl;
						cout<<"\t \t \t \t \t ";
                        cin>>ans;
						cout<<"\n";
                    }
                } while((visit == 1) || (ans=='y'));        //do while ends for ch2 seller

                break;

            default:    cout<<"\t \t \t \t \t Invalid Entry! \n"<<endl<<"\t \t \t \t \t Enter number from given options"<<endl;
							visit =1;

        }       //switch ends for the main menu where user choses between customer and seller

    } while (visit == 1);         //do while ends for ch,the initial choice

	delete list;
}	//main ends
