#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "C:\Users\ZORO\Downloads\مكتبات\clsDate.h"
using namespace std;
class clsScreen1
{
protected: 
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\tUSER NAME: " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDATE: " << clsDate::DateToString(clsDate::GetSystemDate()) << endl;
        
    }
 
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;

        }
        

    }
    static string UserName()
    {
        return CurrentUser.UserName;
    }
    };


