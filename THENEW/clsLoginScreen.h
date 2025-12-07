#pragma once
#include <iostream>
#include "clsScreen1.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen1.h"
#include "C:\Users\ZORO\Downloads\مكتبات\clsInputValiDate.h"
#include "Global.h"
class clsLoginScreen :protected clsScreen1
{
private:
    static  bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FaildLoginCount++;

                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have " << (3 - FaildLoginCount)
                    << " Trial(s) to login.\n\n";
            }

            if (FaildLoginCount == 3)
            {
                cout << "\nYour are Locked after 3 faild trails \n\n";
                return false;
            }

            cout << "Enter Username: ";
            cin >> Username;

            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegistorLogIn();
        clsMainScreen1::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t    Login Screen");
        return _Login();

    }


};

