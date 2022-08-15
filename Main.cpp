//Author : Seyed Mohammad Soheil Amini
//Up To Date : 2022/01/04
#include "Method1.cpp"
#include "Method2.cpp"
#include "Method3.cpp"
#include "Method4.cpp"
int main()
{
    int command;
    while (1)
    {
        cout << "-------------------------------------------START MENU-------------------------------------------\n";
        cout << "Enter Your Command:\n";
        cout << "\t1-Admin Panel\n";
        cout << "\t2-User Panel\n";
        cout << "\t3-Exit\n";
        cout << "==>";
        cin >> command;
        switch (command)
        {
        case 1:
            admin_panel();
            break;
        case 2:
            user_panel();
            break;
        case 3:
            system("cls");
            return 0;
        default:
            incorrect_command();
            break;
        }
    }
    return 0;
    system("cls");
}