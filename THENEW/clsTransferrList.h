#pragma once
#include <iostream>
#include "clsScreen1.h"
#include "clsBankClient1.h"
#include <iomanip>
class clsTransferrList:protected clsScreen1
{
private:

    static void PrintTransferLogRecordLine(clsBankClient1::stTrnsferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.Date + "-"+TransferLogRecord.Hour;
        cout << "| " << setw(8) << left << TransferLogRecord.AccountNumber1;
        cout << "| " << setw(8) << left << TransferLogRecord.AccountNumber2;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.AccountBalance1;
        cout << "| " << setw(10) << left << TransferLogRecord.AccountBalance2;
        cout << "| " << setw(8) << left << TransferLogRecord.UserName;


    }

public:

    static void ShowTransferLogScreen()
    {


        vector <clsBankClient1::stTrnsferLogRecord> vTransferLogRecord = clsBankClient1::GetTransfersLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient1::stTrnsferLogRecord Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};
