#pragma once
#include <string>
#include <iostream>
#include "Warehouse.h"

using namespace std;
class SellInventory : public Warehouse
{
public:
	 float sales;
	 int  numberOfItemsSold;

	//Constructor for the class
	SellInventory(int _productId, string _productName, int _quantity, float _unitPrice, int _numberOfItemsSold, float _sales);

	void Display()override;

};

