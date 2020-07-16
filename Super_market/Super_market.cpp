// Super_market.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Created by: RamaKrishna


#include <string>
#include <iostream>
#include <time.h>
#include <chrono>
#include "SellInventory.h"
#include "Warehouse.h"
#include "BuyInventory.h"

using namespace std;

//prototypes
void DisplayItems();
void SellingItem();
void BuyingItem();
void UserDisplay();
void TimeDisplay();

//Warehouse class 
Warehouse* myWarehouse[50];

//Declaring global variables
int idSearch, quantity;
int numOfQuantity, numberOfItemsSold, productId, numberOfItemsBought;
string productName;
float unitPrice, sales, sellPrice, costPrice, spending;

int main()
{
	int choice;
	myWarehouse[0] = new SellInventory(1, "Apples", 10, 1.02, 0, 0.0);
	myWarehouse[1] = new SellInventory(2, "Banana", 15, 1.50, 0, 0.0);
	myWarehouse[2] = new SellInventory(3, "Grapes", 20, 2.00, 0, 0.0);
	myWarehouse[3] = new SellInventory(4, "Mango", 15, 1.70, 0, 0.0);
	
	//DisplayItems();
	do
	{
		cout << endl << "-----------MAIN MENU.---------" << endl;

		cout << " 1. Buying Items \n 2. Selling Items \n 3. User Menu \n 4. Quit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: BuyingItem();
			break;
		case 2: SellingItem();
			break;
		case 3: UserDisplay();
			break;
		case 4: exit(0);
			break;
		}
	} while (choice != 4);
	
}

//Displaying function
void DisplayItems() {
	for (int i = 0; i < 4; i++)
	{
		myWarehouse[i]->Display();
	}
}


//Selling function 
void SellingItem()
{
	string value;
	DisplayItems();
	do
	{
	cout << "Enter the Product Id or the Product Name to search." << endl;
	cin >> idSearch;
	cout << "PRODUCT ID" << "\t\t" << "PRODUCT NAME" << "\t\t" << "QUANTITY" << "\t\t" << "UNIT PRICE"<< endl;

		for (int i = 0; i < 4; i++)
		{
			if (idSearch == myWarehouse[i]->productId)
			{
				myWarehouse[i]->Display();
				cout << myWarehouse[i]->productName << " Select number of items you want : " << endl;
				cin >> numOfQuantity;
				quantity = myWarehouse[i]->quantity - numOfQuantity;
				numberOfItemsSold = numOfQuantity;
				sellPrice = myWarehouse[i]->unitPrice * numOfQuantity;
				unitPrice = myWarehouse[i]->unitPrice;
				productName = myWarehouse[i]->productName;
				productId = myWarehouse[i]->productId;
				sales += sellPrice;
				myWarehouse[i] = new SellInventory(productId, productName, quantity, unitPrice, numberOfItemsSold, sales);
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				myWarehouse[i]->Display();
				cout << "The Total Price is: " << sellPrice << endl;
			}
		}
		cout << "-------------------------------------------------------------------------------" << endl << endl;
		DisplayItems();
		cout << "Do you want select more items? (Yes/No)" << endl;
		cin >> value;
		DisplayItems();

	} while (value == "yes" ||value == "YES");

	cout << "Choose Yes to display Total count of all sold Items. " << endl;
	cin >> value;
	if (value == "yes" || value == "YES")
	{
		for (int i = 0; i < 4; i++)
		{
			quantity = myWarehouse[i]->quantity;
			numberOfItemsSold++;
			
		}
		cout << numberOfItemsSold << endl;
	}
	system("pause");
}
void BuyingItem()
{
	string value;
	DisplayItems();
	do
	{
		cout << "Enter the Product Id or the Product Name to buy." << endl;
		cin >> idSearch;
		cout << "PRODUCT ID" << "\t\t" << "PRODUCT NAME" << "\t\t" << "QUANTITY" << "\t\t" << "UNIT PRICE" << endl;

		for (int i = 0; i < 4; i++)
		{
			if (idSearch == myWarehouse[i]->productId)
			{
				myWarehouse[i]->Display();
				cout << "You selected " << myWarehouse[i]->productName << endl << "Select number of items you want : " << endl;
				cin >> numOfQuantity;
				quantity = myWarehouse[i]->quantity + numOfQuantity;
				numberOfItemsBought = numOfQuantity;
				costPrice = myWarehouse[i]->unitPrice * numOfQuantity;
				unitPrice = myWarehouse[i]->unitPrice;
				productName = myWarehouse[i]->productName;
				productId = myWarehouse[i]->productId;
				spending += costPrice;
				myWarehouse[i] = new BuyInventory(productId, productName, quantity, unitPrice, numberOfItemsBought, spending);
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				myWarehouse[i]->Display();
				cout << "The Total Price is: " << costPrice << endl;
			}
		}
		cout << "-------------------------------------------------------------------------------" << endl << endl;
		DisplayItems();
		cout << "Do you want select more items? (Yes/No)" << endl;
		cin >> value;
		DisplayItems();
	} while (value == "yes" || value == "YES");
	
	system("pause");
}
void UserDisplay()
{
	TimeDisplay();
	cout << "Number of Items Bought are : " << numberOfItemsBought << endl;
	cout << "Number of Items sold are : " << numberOfItemsSold << endl;
}
void TimeDisplay()
{
	// myTime = time(NULL);
	//cout << ctime_s(myTime);
	auto timenow =
		chrono::system_clock::to_time_t(chrono::system_clock::now());

	cout << ctime(&timenow) << endl;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
