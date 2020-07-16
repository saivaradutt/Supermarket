#include "BuyInventory.h"

BuyInventory::BuyInventory(int _productId, string _productName, int _quantity, float _unitPrice, int _numberOfItemsBought, float _spending) : Warehouse(_productId, _productName, _quantity, _unitPrice)
{
	spending = _spending;
	numberOfItemsBought = _numberOfItemsBought;
}

void BuyInventory::Display()
{
	Warehouse::Display();
	cout << "Spending: " << spending <<"\t\t"<< "Number of items bought: " << numberOfItemsBought << endl;
	
}
