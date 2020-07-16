//This is the class header file for the Warehouse
//Created by Sharath Reddy
//Creation Date: 09-07-2019

#pragma once
#include <string>
#include <iostream>

using namespace std;
class Warehouse
{
public:
	int productId;
	string productName;
	int quantity;
	float unitPrice;
	
	
	//Constructor for the Warehouse
	Warehouse(int _productId, string _productName, int _quantity, float _unitPrice );
	virtual void Display();

};

