#pragma once
#include <iostream>
#include "clsScreen1.h"
#include "clsCurrency.h"
#include "C:\Users\ZORO\Downloads\مكتبات\clsInputValiDate.h"
#include <string>
using namespace std;
class clsUdateRateCurrency :protected clsScreen1
{
	static void	_Print(clsCurrency C)
	{
		cout << "\n\nCurrency Card:";
		cout << "\n---------------------------------------------" << endl;
		cout << "Country     : " << C.Country() << endl;
		cout << "Code        : " << C.CurrencyCode() << endl;
		cout << "Name        : " << C.CurrencyName() << endl;
		cout << "Rate(1$) =  : " << C.Rate() << endl;
		cout << "---------------------------------------------" << endl;

	}
public:
	static void ShowUpdateCurrency()
	{
		string t = "Update Rate Currency";
		_DrawScreenHeader(t);
		cout << "\n\n\n Please Enter Currency Code: ";
		string S = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExistCode(S))
		{
			cout << "The Code you searched for is not found. Try again" << endl;
			S = clsInputValidate::ReadString();
		}
		clsCurrency C = clsCurrency::FindByCode(S);
		_Print(C);


		cout << "Are you sure you want to update the rate of this Currency y/n";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\nUpdate Currency Rate:" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Enter New Rate: ";
			float NewRate = clsInputValidate::ReadFloatNumber();
			C.UpdateRate(NewRate);
			_Print(C);
		}
		else
		{

		}
	}
};

