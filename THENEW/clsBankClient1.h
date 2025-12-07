#pragma once
#include <iostream>
#include <string>
#include "C:\Users\ZORO\source\repos\THENEW\THENEW\clsPerson1.h"
#include "C:\Users\ZORO\Downloads\مكتبات\clsString.h"
#include <vector>
#include <fstream>
#include "C:\Users\ZORO\Downloads\مكتبات\clsDate.h"
class clsBankClient1 : public clsPerson1
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient1 _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient1(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient1 Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient1> _LoadClientsDataFromFile()
    {

        vector <clsBankClient1> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient1 Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient1> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient1 C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient1> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient1& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient1 _GetEmptyClientObject()
    {
        return clsBankClient1(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    string _ConverTransferObjectToLine( clsBankClient1 Client2,int M,string UserName,string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += clsDate::DateToString(clsDate::GetSystemDate()) + Seperator;
        stClientRecord += clsDate::GetCurrentHourString() + Seperator;
        stClientRecord += AccountNumber() + Seperator;
        stClientRecord += Client2.AccountNumber() + Seperator;
        stClientRecord += to_string(M) + Seperator;
        stClientRecord += to_string(Client2.AccountBalance) + Seperator;
        stClientRecord += to_string(AccountBalance) + Seperator;
        stClientRecord += UserName;

        return stClientRecord;

    }
    struct stTrnsferLogRecord;
      static stTrnsferLogRecord _getstaticvector(string Line, string Seperator = "#//#")
    {
          vector <string> vString = clsString::Split(Line, Seperator);
          stTrnsferLogRecord V;
          V.Date = vString[0];
          V.Hour = vString[1];
          V.AccountNumber1 = vString[2];
          V.AccountNumber2 = vString[3];
          V.Amount = stoi(vString[4]);
          V.AccountBalance2 = stoi(vString[5]);
          V.AccountBalance1 = stoi(vString[6]);
          V.UserName = vString[7];
          return V;

    }
public:
   
    static struct stTrnsferLogRecord
    {
        string Date;
        string Hour;
        string AccountNumber1;
        string AccountNumber2;
        int Amount;
        int AccountBalance1;
        int AccountBalance2;
        string UserName;

    };




    clsBankClient1(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson1(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    static clsBankClient1 Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient1 Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient1 Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient1 Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient1::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }



    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient1 Client1 = clsBankClient1::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    bool Delete()
    {
        vector <clsBankClient1> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient1& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }

    static clsBankClient1 GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient1(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsBankClient1> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }


    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient1> vClients = clsBankClient1::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient1 Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;
    }
    bool Transfer(int M, clsBankClient1& C2)
    {
        if (M > AccountBalance)
        {
            return false;
        }
        Withdraw(M);
        C2.Deposit(M);
        return true;
    }
     void TransferToFile(clsBankClient1& C2, int M,string UserName)
    {
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            string Lien = _ConverTransferObjectToLine(C2, M,UserName);
            MyFile << Lien << endl;
        }
    }
     static vector <stTrnsferLogRecord> GetTransfersLogList()
     {
         vector <stTrnsferLogRecord> vTransfer;
         fstream MyFile;
         MyFile.open("TransferLog.txt", ios::in);
         if (MyFile.is_open())
         {
             string Lien;
             while (getline(MyFile, Lien))
             {

                 stTrnsferLogRecord CLient = _getstaticvector(Lien);
                 vTransfer.push_back(CLient);

             }
             MyFile.close();
         }

         return vTransfer;

     }
};

