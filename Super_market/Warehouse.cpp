//This is the class header file for the Warehouse
//Created by Sharath Reddy
//Creation Date: 09-07-2019

#include "Warehouse.h"

//Constructor calling from the warehouse header file
Warehouse::Warehouse(int _productId, string _productName, int _quantity, float _unitPrice)
{
	productId = _productId;
	productName = _productName;
	quantity = _quantity;
	unitPrice = _unitPrice;
}

void Warehouse::Display() 
{
		cout << productId << "\t\t\t" << productName << "\t\t\t" << quantity << "\t\t\t" << unitPrice << "\t\t";
}
