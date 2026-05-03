#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsCalculatorCurrencyListScreen : protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nConvert From:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";
    }

    static void _ConvertToUsd(clsCurrency Currency, float Amount)
    {
        _PrintCurrency(Currency);

        cout << Amount << Currency.CurrencyCode() << " = " << (Amount / Currency.Rate()) << " USD ";
    }

public:
    static void ShowCalculatorCurrencyScreen()
    {
        _DrawScreenHeader("\t  Calculator Currency Screen");

        string CurrencyCodeFrom = "";

        cout << "\nPlease Enter Currency Code: ";
        CurrencyCodeFrom = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCodeFrom))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCodeFrom = clsInputValidate::ReadString();
        }

        string CurrencyCodeTo = "";

        cout << "\nPlease Enter Currency Code: ";
        CurrencyCodeTo = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCodeTo))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCodeTo = clsInputValidate::ReadString();
        }

        float Amount;
        cout << "Enter Amount to Exchange: ";
        Amount = clsInputValidate::ReadFloatNumber();

        clsCurrency CurrencyFrom = clsCurrency::FindByCode(CurrencyCodeFrom);
        clsCurrency CurrencyTo = clsCurrency::FindByCode(CurrencyCodeTo);

        if (clsString::UpperAllString(CurrencyTo.CurrencyCode()) == "USD")
            _ConvertToUsd(CurrencyFrom, Amount);

        char Answer;

        cout << "Do you want to perform another calculation? y/n ?";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
            ShowCalculatorCurrencyScreen();
    }
};
