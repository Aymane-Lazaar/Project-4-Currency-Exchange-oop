#include <iostream>
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include "clsUser.h"

int main()
{

    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
            break;
    }

    return 0;
}
