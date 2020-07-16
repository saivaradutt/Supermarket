#include "SellInventory.h"


SellInventory::SellInventory(int _productId, string _productName, int _quantity, float _unitPrice,  int _numberOfItemsSold,  float _sales) : Warehouse(_productId, _productName, _quantity, _unitPrice)
{
	sales = _sales;
	numberOfItemsSold = _numberOfItemsSold;
}

void SellInventory::Display()
{
	Warehouse::Display();
	cout << "Sales :" << sales <<"\t\t"<< "Number of Items Sold :" << numberOfItemsSold << endl;
}
