#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include <limits>
using namespace std;

class clsInputValidate
{
public:
    static bool IsNumberBetween(short Number, short From, short To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsNumberBetween(int Number, int From, int To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsNumberBetween(float Number, float From, float To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        // Date>=From && Date<=To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        // Date>=To && Date<=From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }

        return false;
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
    {
        int Number;

        // Method 1
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }

        // Method 2
        //  while (cin.fail())
        //  {
        //      cin.clear();
        //      cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //      cout << ErrorMessage;
        //     cin >> Number;
        // }

        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage)
    {
        int number = ReadIntNumber();

        while (!(IsNumberBetween(number, From, To)))
        {
            cout << ErrorMessage;
            number = ReadIntNumber();
        }

        return number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
    {
        double Number;

        // Method 1
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }

        // Method 2
        //  while (cin.fail())
        //  {
        //      cin.clear();
        //      cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //      cout << ErrorMessage;
        //     cin >> Number;
        // }

        return Number;
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage)
    {
        double number = ReadDblNumber();

        while (!(IsNumberBetween(number, From, To)))
        {
            cout << ErrorMessage;
            number = ReadDblNumber();
        }

        return number;
    }

    static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    static string ReadString()
    {
        string S1 = "";
        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, S1);
        return S1;
    }

    static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        short Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number = ReadShortNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadShortNumber();
        }
        return Number;
    }

    static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
    {
        float Number;

        // Method 1
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }

        // Method 2
        //  while (cin.fail())
        //  {
        //      cin.clear();
        //      cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //      cout << ErrorMessage;
        //     cin >> Number;
        // }

        return Number;
    }

};
