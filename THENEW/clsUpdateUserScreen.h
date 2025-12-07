#pragma once
#include <iostream>
#include "C:\Users\ZORO\Downloads\مكتبات\clsString.h"
#include "clsUser.h"
#include "C:\Users\ZORO\Downloads\مكتبات\clsInputValiDate.h"

class clsUpdateUserScreen :protected clsScreen1
{
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

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

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
        cout << "\n Show Log In Register? y/n ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y');
        {
            Permissions += clsUser::enPermissions::pLogRegister;
        }
        return Permissions;
    }
    public:
        static void SHowUpdateUser()
        {
            _DrawScreenHeader("\tUpdate User Screen");

            string UserName = "";
            cout << "Enter User Name ";
            UserName = clsInputValidate::ReadString();
            while (!clsUser::IsUserExist(UserName))
            {
                cout << endl << "Not found,Enter User Name";
                UserName = clsInputValidate::ReadString();

            }
            clsUser User1 = clsUser::Find(UserName);
            _PrintUser(User1);

            cout << endl << "Are you sure you want to update this user? Y/N" << endl;
            char Answer = 'n';
            if (Answer == 'y' || Answer == 'Y')
            {

                _ReadUserInfo(User1);
                clsUser::enSaveResults SaveResult;
                SaveResult = User1.Save();
                switch (SaveResult)
                {
                case clsUser::enSaveResults::svSucceeded:
                {
                    cout << "\nUser Updated Successfully :-)\n";
                    _PrintUser(User1);
                    break;
                }
                case clsUser::enSaveResults::svFaildEmptyObject:
                {
                    cout << "\nError User was not saved because it's Empty";
                    break;
                }
                }
            }
        }
};