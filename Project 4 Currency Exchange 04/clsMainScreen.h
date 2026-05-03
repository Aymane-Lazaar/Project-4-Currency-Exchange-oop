#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindBankClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsers.h"
#include "Global.h"
#include "clsRejisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"

#include <iomanip>

using namespace std;

class clsMainScreen : protected clsScreen
{

private:
    enum enMainMenueOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenue = 6,
        eManageUsers = 7,
        eLoginRegister = 8,
        eCurrencyExchange = 9,
        eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsClientListSceen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        // cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShoweleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        // cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        // cout << "\nFind Client Screen Will be here...\n";
        clsFindBankClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        // cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        // cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    // static void _ShowEndScreen()
    // {
    //     cout << "\nEnd Screen Will be here...\n";
    // }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeMainScreen()
    {
        // cout << "\nCurrency Exchange Screen Will be here...\n";
        clsTransactionsCurrencyExchangeScreen::ShowCurrenciesMenue();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");

        /*
                1. كيف يعمل الـ Stack؟ (قاعدة "الانتظار")
                في لغة ++C، عندما تستدعي دالة (Function A) دالةً أخرى (Function B)، فإن الدالة (A) لا تنتهي، بل تتوقف مؤقتاً وتظل محجوزة في الذاكرة (بكل متغيراتها) وتنتظر حتى تنتهي الدالة (B) وتعود إليها (return).

                2. تتبع الكود في ذاكرة الـ Stack:
                المرحلة الأولى (البداية): الـ main تستدعي ShowLoginScreen.

                الـ Stack يحتوي على: [main] ثم فوقها [ShowLoginScreen 1].

                الحالة: الـ main تنتظر ShowLoginScreen 1 أن تنتهي.

                المرحلة الثانية (الدخول): المستخدم سجل دخوله، فاستدعت دالة اللوجن ShowMainMenue.

                الـ Stack يحتوي على: [main] -> [ShowLoginScreen 1] -> [ShowMainMenue 1].

                الحالة: الآن هناك دالتان في حالة "انتظار".

                المرحلة الثالثة (الخروج - Logout): هنا تقع المشكلة. بدلاً من أن تنتهي دالة المنيو، قمت أنت باستدعاء ShowLoginScreen مرة أخرى.

                الـ Stack يحتوي على: [main] -> [ShowLoginScreen 1] -> [ShowMainMenue 1] -> [ShowLoginScreen 2].

                الحالة: ثلاث دوال تنتظر!

                3. لماذا يعتبر هذا خطأ (Error)؟
                هذا لا يسبب خطأ في الكود (Syntax Error)، لكنه يسبب كارثة في الذاكرة أثناء التشغيل (Runtime Error):

                استهلاك الذاكرة: الـ Stack له مساحة محدودة جداً. في كل مرة "يسجل المستخدم خروجه ثم يدخل"، أنت تضيف طبقتين جديدتين (Login و MainMenu) فوق الطبقات القديمة دون أن تحذف القديم.

                تراكم الانتظار: ShowLoginScreen 2 تنتظر أن تنتهي، وإذا دخل المستخدم للمنيو مرة أخرى ستنشأ ShowMainMenue 2 وهكذا.

                الانهيار (Stack Overflow): بعد عدد معين من المرات (مثلاً 1000 مرة دخول وخروج)، ستمتلئ مساحة الـ Stack تماماً، وسينهار البرنامج ويغلق فجأة، وهذا هو الـ Stack Overflow.
            */

        /* summary
            لما بتنادي دالة من قلب دالة تانية،
            القديمة مش بتموت،
            هي بتفضل "محجوزة" في الذاكرة ومستنية اللي بعدها تخلص. فإنت لما بتعمل Logout وتنادي شاشة الدخول تاني، إنت مش بترجع للشاشة القديمة، إنت بتفتح نسخة جديدة فوق القديمة والقديمة لسه صاحية ومستنية. لو فضلت تعمل كده، الذاكرة هتتملي "نسخ" كلها مستنية بعض،
            والبرنامج هيهنج ويقفل فجأة لأن الـ Stack ليه آخر ومش هيستحمل طوابير الانتظار دي كلها. الحل إنك تقفل الدالة (Return) عشان تمسحها من الذاكرة وترجع للي قبلها "نظيف".
        */

        // clsLoginScreen::ShowLoginScreen(); Circular Reference will get error

        /*لماذا لم تعترض دالة _GoBackToMainMenue على استدعاء ShowMainMenue بينما اعترضت الشاشات الأخرى؟
            لماذا لم تعترض دالة _GoBackToMainMenue على استدعاء ShowMainMenue بينما اعترضت الشاشات الأخرى؟

                الإجابة باختصار: لأن الاستدعاء هنا داخل نفس الكلاس وليس بين كلاسات مختلفة.

                إليك التفصيل باللغتين:

                1. لماذا لا يوجد خطأ في المترجم (No Compiler Error)؟
                دالة _GoBackToMainMenue ودالة ShowMainMenue كلاهما أعضاء في نفس الكلاس (clsMainScreen). المترجم عندما يقرأ الكلاس، فإنه يرى جميع أعضائه (Members). لذلك، عندما تستدعي دالة دالةً أخرى داخل نفس الملف ونفس الكلاس، لا يحتاج المترجم للبحث في ملفات خارجية، وبالتالي لا تحدث مشكلة الـ Circular Reference.

                2. هل يوجد خطر في الذاكرة (Memory Danger)؟
                نعم! وهنا المفاجأة: بالرغم من أن الكود يعمل ولا يعطيك خطأ عند التشغيل، إلا أنك تكرر نفس خطأ الـ Stack Overflow الذي شرحناه سابقاً، ولكن بشكل "داخلي".

                عندما تختار خياراً (مثل عرض العملاء)، تفتح دالة _ShowAllClientsScreen.

                الدالة تطلب _GoBackToMainMenue.

                الدالة تطلب ShowMainMenue.

                النتيجة: الدالة الأولى لم تنتهِ، والثانية لم تنتهِ، وأنت فتحت الثالثة فوقهم.

                إذا ظل المستخدم يتنقل بين القوائم لفترة طويلة جداً (مثلاً دخل وخرج من القوائم 5000 مرة)، البرنامج سيقوم بعمل Crash فجأة لنفس السبب: الـ Stack امتلأ بدوال "تنتظر" بعضها البعض.
        */

        /* Short summary
            السبب في أن ShowLoginScreen تظهر لك خطأ (Compiler Error) بينما _GoBackToMainMenue لا تظهر خطأ، يعود إلى مكان وجود الدوال بالنسبة للمترجم.

            إليك التوضيح ببساطة:

            1. في حالة ShowMainMenue (داخل الكلاس)
            عندما ينظر المترجم داخل ملف clsMainScreen.h:

            هو يرى كلاس واحدًا.

            يقرأ جميع الدوال الموجودة بداخله (حتى لو كانت تنادي بعضها).

            المترجم يقول: "أنا أعرف هذه الدالة، فهي موجودة معي في نفس الغرفة (نفس الكلاس)".

            النتيجة: لا يوجد خطأ في الترجمة، لكن الخطر يظل موجوداً في الذاكرة (Stack) وقت التشغيل كما شرحنا.

            2. في حالة ShowLoginScreen (خارج الكلاس)
            المشكلة هنا هي "من يعرف من؟":

            ملف clsMainScreen.h يخبر المترجم: "أنا أحتاج ملف clsLoginScreen.h".

            يذهب المترجم لفتح ملف clsLoginScreen.h ليقرأه.

            فيجد في أول سطر بداخل clsLoginScreen.h: "أنا أحتاج ملف clsMainScreen.h".

            هنا تحدث اللخبطة: المترجم لم يكمل قراءة clsMainScreen أصلاً لأنه توقف في السطر الأول ليفتح الملف الثاني، والملف الثاني يطلب منه العودة للملف الأول!

            لماذا يظهر الخطأ تحديداً؟
            المترجم يحتاج أن يعرف حجم الكلاس ومواصفاته بالكامل قبل أن يسمح لك باستخدامه.

            عندما تحاول استدعاء clsLoginScreen::ShowLoginScreen() داخل MainScreen (والعكس)، المترجم يشعر أن هناك "حلقة مفقودة".

            هو لم ينتهِ من بناء الكلاس الأول، فيجد طلباً لاستخدام الكلاس الثاني، الذي بدوره يطلب الكلاس الأول الذي لم يُبنى بعد!

            الخلاصة (The Summary)
            داخل الكلاس الواحد (GoBack): المترجم يرى الصورة كاملة لأنها في ملف واحد وكلاس واحد، فيسمح لك بكتابتها (حتى لو كانت ستسبب كارثة في الذاكرة لاحقاً).

            بين كلاسين مختلفين (Login و Main): المترجم يضيع في "الدائرة المفرغة" لمحاولة تضمين الملفات (#include) قبل أن ينتهي من تعريف الكلاسات، وهذا هو الـ Circular Reference الحقيقي الذي يمنع البرنامج من العمل من الأساس.
        */
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeMainScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }
    }

public:
    static void ShowMainMenue()
    {

        system("cls");
        clsScreen::_DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};
