#pragma once 
#include <iostream>
#include "clsScreen1.h"
#include "clsCurrency.h"
#include "C:\Users\ZORO\Downloads\مكتبات\clsInputValiDate.h"
class clsFindCurrencyScreen :protected clsScreen1
{
	static void	_Print(clsCurrency C)
	{
		cout << "---------------------------------------------" << endl;
		cout << "Country     : " << C.Country() << endl;
		cout << "Code        : " << C.CurrencyCode() << endl;
		cout << "Name        : " << C.CurrencyName() << endl;
		cout << "Rate(1$) =  : " << C.Rate() << endl;
		cout << "---------------------------------------------" << endl;

	}

public:
static void ShowFindCurrency()
	{
	string T = "Find Currency Screen";
	_DrawScreenHeader(T);
	cout << "\n\n---------------------------------------------" << endl;


	    cout << "Search by country [1] or code [2]: " << endl;
		int A = clsInputValidate::ReadIntNumberBetween(1, 2);

	if (A == 1)
	{
		cout << "\nWhich country do you want to search for" << endl;
		string A = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExistCountry(A))
		{
			cout << "The country you searched for is not found. Try again" << endl;
			A = clsInputValidate::ReadString();
		}
		clsCurrency C = clsCurrency::FindByCountry(A);
		_Print(C);
	}
	else
	{	
		cout << "\nWhich Code do you want to search for" << endl;
		string S = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExistCode(S))
		{
			cout << "The Code you searched for is not found. Try again" << endl;
			S = clsInputValidate::ReadString();
		}
		clsCurrency C = clsCurrency::FindByCode(S);
		_Print(C);


	}





	}
};

