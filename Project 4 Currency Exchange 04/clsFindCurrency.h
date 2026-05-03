#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsFindCurrencyListScreen : protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
            cout << "\nCurrency Was not Found :-(\n";
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer = 1;

        Answer = clsInputValidate::ReadShortNumberBetween(1, 2);

        if (Answer == 1)
        {
            string CurrencyCode;

            cout << "\nPlease Enter CurrencyCode: ";

            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

            _ShowResults(Currency);
        }
        else
        {
            string Country;

            cout << "\nPlease Enter Country Name: ";

            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);

            _ShowResults(Currency);
        }
    }
};
