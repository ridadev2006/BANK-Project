#pragma once
#include <iostream>
#include "clsScreen1.h"
#include "clsPerson1.h"
#include "clsUser.h"
#include "C:\Users\ZORO\Downloads\مكتبات\clsInputValiDate.h"
class clsFindUserScreen :protected clsScreen1
{

private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }


public:

    static void ShowFindClientScreen()
    {

        _DrawScreenHeader("\tFind User Screen");

        string UserName;
        cout << "\nPlease Enter Account Number: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\User number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        if (!User.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintUser(User);

    }

};



