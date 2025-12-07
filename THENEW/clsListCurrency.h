#pragma once
#include <iostream>	
#include <iomanip>
#include "clsScreen1.h"
#include "clsCurrency.h"
class clsListCurrency: protected clsScreen1
{ 

	static void _Print(clsCurrency C)
	{
		cout << setw(8)<< " " << left << "| " << left << setw(30) << C.Country();
		cout << "| " << left << setw(8) << C.CurrencyCode();;
		cout << "| " << left << setw(45) << C.CurrencyName();
		cout << "| " << left << setw(10) << C.Rate();
		cout << endl;

	}



public:
	static void ShowListCurrency()
	{
		vector <clsCurrency> Currency = clsCurrency::GetCurrenciesList();
		string T = "\t List Currency Screen";
		string S = "\t    (" + to_string(Currency.size()) + ") Currency";
		_DrawScreenHeader(T, S);

		cout << setw(8) << left << " " << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		cout << setw(8)<<"" << left << "| " << left << setw(30) << "Currency";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (Currency.size() == 0)
		{
			cout << "\t\t\t\tNo Currencies Available In the System!";
		}
		else
		{
			for (clsCurrency& C : Currency)
			{
				_Print(C);
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		}


};

