#pragma once
#include <iostream>
#include "clsScreen1.h"
#include "clsBankClient1.h"
#include "C:\Users\ZORO\Downloads\مكتبات\clsInputValiDate.h"
#include <string>
class  clsTransfer : protected clsScreen1
{

	static void _print(clsBankClient1 C)
	{
		cout << "________________________" << endl;
		cout << "Client Name: " << C.FullName() << endl;
		cout << "Account Number: " << C.AccountNumber() << endl;
		cout << "Account Balance: " << C.GetAccountBalance() << endl;
		cout << "________________________" << endl;

	}



public:

	static void ShowclsTransfer()
	{
		string T = "Transfer Screen";
		_DrawScreenHeader(T);
		cout << "\nEnter Number Account: " << endl;
		string A = clsInputValidate::ReadString();
		while (!clsBankClient1::IsClientExist(A))
		{
			cout << "\nAccount number is not found, choose another one: " << endl;
			A = clsInputValidate::ReadString();
		}
		clsBankClient1 C1 = clsBankClient1::Find(A);
		_print(C1);

		cout << "\nTranslate: The account you want to deposit into?" << endl;
		string A1 = clsInputValidate::ReadString();
		while (!clsBankClient1::IsClientExist(A1))
		{
			cout << "\nAccount number is not found, choose another one: " << endl;
			A1 = clsInputValidate::ReadString();
		}
		clsBankClient1 C2 = clsBankClient1::Find(A1);
		_print(C2);

		cout << "\nHow much do you want to deposit?" << endl;
		int M = clsInputValidate::ReadIntNumber();
		cout << "Are you sure? y/n" << endl;
		char An ;
		cin >> An;
		if (An == 'y' || An == 'Y')
		{
			if (C1.Transfer(M, C2))
			{
				cout << endl << "The operation completed" << endl;
				_print(C1);
				_print(C2);
				C1.TransferToFile(C2, M, UserName());

			}
			else
			{
				cout << endl << "The operation failed" << endl;
			}
		}
	}
};

