#pragma once
#include <iostream>
#include "clsScreen1.h"
#include "clsPerson1.h"
#include "clsUser.h"
#include "C:\Users\ZORO\Downloads\مكتبات\clsInputValiDate.h"

class clsDeleteUserScreen :protected clsScreen1
{
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
    static void ShowDeletedUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");
        string UserName = "";
        cout << "Please Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "USer Is Not Found,choose ANoter one:  ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);
        cout << "Are You sure you want to delete This User Y/N? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (User1.Delete())
            {
                cout << "\n User deleted Successfully :-(\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was Not Deleted";
            }
        }
    }
};

