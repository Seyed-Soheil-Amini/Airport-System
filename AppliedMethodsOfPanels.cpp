//Author : Seyed Mohammad Soheil Amini
//Up To Date : 2021/12/26
#include "Definitions.hpp"
//---------------------------------------------------------------
bool check_firstname(char first_n[])
{
    if (strlen(first_n) >= 26)
    {
        cout << "\t\t\t!!WARNING!!Your First Name Is Invalid(Max Len = 25)!!WARNING!!\n";
        return false;
    }
    return true;
}
//---------------------------------------------------------------
bool check_lastname(char last_n[])
{
    if (strlen(last_n) >= 26)
    {
        cout << "\t\t\t!!WARNING!!Your Last Name Is Invalid(Max Len = 25)!!WARNING!!\n";
        return false;
    }
    return true;
}
//---------------------------------------------------------------
bool check_phonenumber(char phone_n[])
{
    if (phone_n[0] != '0' || strlen(phone_n) != 11)
    {
        cout << "\t\t\t!!WARNING!!Your Phone Number Is Invalid(Example:09123456789)!!WARNING!!\n";
        return false;
    }
    for (int i = 0; phone_n[i] != 0; i++)
    {
        if (48 > phone_n[i] || phone_n[i] > 57)
        {
            cout << "\t\t\t!!WARNING!!Your Phone Number Is Invalid(Example:09123456789)!!WARNING!!\n";
            return false;
        }
    }
    return true;
}
//---------------------------------------------------------------
bool check_username(char user_n[])
{
    int len = strlen(user_n);
    if (2 <= len && len <= 10)
        return true;
    cout << "\t\t\t!!WARNING!!Your Username Is Invalid(2<=Len<=10)!!WARNING!!\n";
    return false;
}
//---------------------------------------------------------------
bool check_uniqueness_username(int command, char user[])
{
    if (command == 1)
    {
        for (int i = 0; i < step_of_admin; i++)
        {
            if (strcmp(all_admin[i].username, user) == 0)
            {
                cout << "\t\t\t!!WARNING!!Your Username Already Was Entered!!WARNING!!\n";
                return false;
            }
        }
        return true;
    }
    else
    {
        for (int i = 0; i < step_of_user; i++)
        {
            if (strcmp(all_user[i].username, user) == 0)
            {
                cout << "\t\t\t!!WARNING!!Your Username Already Was Entered!!WARNING!!\n";
                return false;
            }
        }
        return true;
    }
}
//---------------------------------------------------------------
bool check_password(char pass_w[])
{
    int len = strlen(pass_w);
    if (count_capital(pass_w) != 0 && count_small(pass_w) != 0 && count_number(pass_w) != 0 && 5 <= len && len <= 25)
        return true;
    cout << "\t\t\t!!WARNING!!Your Password Is Invalid"
         << "(5<=PasswordLen<=25 And It Must Be Have A Capital And A Small And A Number At least)"
         << "!!WARNING!!\n";
    return false;
}
//---------------------------------------------------------------
bool check_t_password(char Tpass_w[], char pass_w[])
{
    if (strlen(Tpass_w) != strlen(pass_w))
    {
        cout << "\t\t\t!!WARNING!!Your Confirmation Of Password Is Invalid!!WARNING!!\n";
        return false;
    }
    for (int i = 0; pass_w[i] != 0; i++)
    {
        if (Tpass_w[i] != pass_w[i])
        {
            cout << "\t\t\t!!WARNING!!Your Confirmation Of Password Is Invalid!!WARNING!!\n";
            return false;
        }
    }
    return true;
}
//---------------------------------------------------------------
int valid_check_username(char in_username[], int command, int st)
{
    if (command == 1)
    {
        for (int i = 0; i < st; i++)
        {
            if (strcmp(all_admin[i].username, in_username) == 0)
                return i;
        }
        cout << "\t\t\t!!WARNING!!Your Username Is Invalid!!WARNING!!\n";
        return -1;
    }
    else
    {
        for (int i = 0; i < st; i++)
        {
            if (strcmp(all_user[i].username, in_username) == 0)
                return i;
        }
        cout << "\t\t\t!!WARNING!!Your Username Is Invalid!!WARNING!!\n";
        return -1;
    }
}
//---------------------------------------------------------------
bool valid_check_password(char in_password[], int command, int st)
{
    if (command == 1)
    {
        if (strcmp(all_admin[st].password, in_password) == 0)
            return true;
        cout << "\t\t\t!!WARNING!!Your Password Is Invalid!!WARNING!!\n";
        return false;
    }
    else
    {
        if (strcmp(all_user[st].password, in_password) == 0)
            return true;
        cout << "\t\t\t!!WARNING!!Your Password Is Invalid!!WARNING!!\n";
        return false;
    }
}
//---------------------------------------------------------------
void incorrect_command()
{
    cout << "\t!--!Your Command Is Incorrect!--!\n";
}
//---------------------------------------------------------------
int choice_way(int panel)
{
    int sub_command;
    while (1)
    {
        cout << "\t\t\t1-Enter Again\n";
        (panel == 1) ? cout << "\t\t\t2-Go Back To Admin Panel\n"
                     : cout << "\t\t\t2-Go Back To User Panel\n";
        cout << "\t\t\t==>";
        cin >> sub_command;
        switch (sub_command)
        {
        case 1:
            return sub_command;
            break;
        case 2:
            return sub_command;
            break;
        default:
            incorrect_command();
            break;
        }
    }
}
//---------------------------------------------------------------
int count_capital(char str[])
{
    int sum = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if (65 <= str[i] && str[i] <= 90)
            sum++;
    }
    return sum;
}
//---------------------------------------------------------------
int count_small(char str[])
{
    int sum = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if (97 <= str[i] && str[i] <= 122)
            sum++;
    }
    return sum;
}
//---------------------------------------------------------------
int count_number(char str[])
{
    int sum = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if (48 <= str[i] && str[i] <= 57)
            sum++;
    }
    return sum;
}
//---------------------------------------------------------------
ADMIN_DASHBOARD_MENU ad_dash_menu()
{
    int da_command;
    cout << "\tEnter Your Command:\n"
         << "\t1-Add Flight\n"
         << "\t2-Flight Statistics\n"
         << "\t3-Ticket Confirmation\n"
         << "\t4-View Flights\n"
         << "\t5-Log Out\n"
         << "\t==>";
    cin >> da_command;
    switch (da_command)
    {
    case 1:
        return ADMIN_DASHBOARD_MENU::ADD_FLIGHT;
    case 2:
        return ADMIN_DASHBOARD_MENU::FLIGHT_STATISTICS;
    case 3:
        return ADMIN_DASHBOARD_MENU::TICKET_CONFIRMATION;
    case 4:
        return ADMIN_DASHBOARD_MENU::VIEW_FLIGHTS_A;
    case 5:
        return ADMIN_DASHBOARD_MENU::LOG_OUT_A;
    default:
        return ADMIN_DASHBOARD_MENU::INVALID_COMMAND_A;
    }
}
//---------------------------------------------------------------
USER_DASHBOARD_MENU us_dash_menu()
{
    int du_command;
    cout << "\tEnter Your Command:\n"
         << "\t1-Buy Ticket\n"
         << "\t2-View Flights\n"
         << "\t3-View Ticket\n"
         << "\t4-Log out\n"
         << "\t==>";
    cin >> du_command;
    switch (du_command)
    {
    case 1:
        return USER_DASHBOARD_MENU::BUY_TICKET;
    case 2:
        return USER_DASHBOARD_MENU::VIEW_FLIGHTS_U;
    case 3:
        return USER_DASHBOARD_MENU::VIEW_TICKETS;
    case 4:
        return USER_DASHBOARD_MENU::LOG_OUT_U;
    default:
        return USER_DASHBOARD_MENU::INVALID_COMMAND_U;
    }
}