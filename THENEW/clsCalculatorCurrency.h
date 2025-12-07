#pragma once
#include<iostream>
#include"clsScreen1.h"
#include "clsCurrency.h"
#include "C:\Users\ZORO\Downloads\مكتبات\clsInputValiDate.h"
using namespace std;
class clsCalculatorCurrency:protected clsScreen1
{
	static void	_Print(clsCurrency C1, clsCurrency C2 ,float N)
	{ 
		cout << "\nConverted from " << C1.Country() << " currency to " << C2.Country() << " currency." << endl;
		cout <<" :" << N << ".";
	}

	static float _ConvertRate(clsCurrency C1, clsCurrency C2, float Number)
	{
		float N1 = Number / C1.Rate();
		float N2 = N1 * C2.Rate();
		return N2;
	}
public:
	static void ShowCalculatorCurrency()
	{
		string S = "Calculator Currency Screen";
		_DrawScreenHeader(S);
		cout << "Enter the Currency CODE" << endl;
		string C1 = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExistCode(C1))
		{
			cout << "The currency of this country does not exist,Enter the Currency Country" << endl;
			 C1 = clsInputValidate::ReadString();

		}
		clsCurrency CO1 = clsCurrency::FindByCode(C1);
		cout << "To which currency do you want to convert ?" << endl;
			string C2 = clsInputValidate::ReadString();
			while (!clsCurrency::IsCurrencyExistCode(C2))
			{
				cout << "The currency of this country does not exist,Enter the Currency Country" << endl;
				 C2 = clsInputValidate::ReadString();

			}
			clsCurrency CO2 = clsCurrency::FindByCode(C2);
		cout << "How much do you want to convert?" << endl;
		float Number = clsInputValidate::ReadFloatNumber();
		float N = _ConvertRate(CO1, CO2, Number);
		_Print(CO1, CO2, N);
	

	}
};

