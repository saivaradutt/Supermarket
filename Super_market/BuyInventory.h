#pragma once

#include<iostream>
#include <string>
#include "Warehouse.h"

using namespace std;

class BuyInventory : public Warehouse
{
public:
	float spending;
	int numberOfItemsBought;

	//Constructor for the class
	BuyInventory(int _productId, string _productName, int _quantity, float _unitPrice, int _numberOfItemsBought, float _spending);

	void Display() override;
};

