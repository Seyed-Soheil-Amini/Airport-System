//Author : Seyed Mohammad Soheil Amini
//Up To Date : 2022/01/04
#include "Definitions.hpp"
//---------------------------------------------------------------------
void admin_panel()
{
    int admin_command;
    while (1)
    {
        cout << "-------------------------------------------ADMIN PANEL------------------------------------------\n";
        cout << "\t1-Log In(As Admin)\n";
        cout << "\t2-Sign Up(As Admin)\n";
        cout << "\t3-Go Back\n";
        cout << "\t==>";
        cin >> admin_command;
        switch (admin_command)
        {
        case 1:
            if (login_panel(1) != 0)
                return;
            break;
        case 2:
            if (step_of_admin >= MAX_ADMIN)
            {
                cout << "\t!!The Number Of Admins Out Of Memory!!\n";
                break;
            }
            signup_panel(1);
            break;
        case 3:
            return;
        default:
            incorrect_command();
            break;
        }
    }
    return;
}
//---------------------------------------------------------------------------------------------
void user_panel()
{
    int user_command;
    while (1)
    {
        cout << "-------------------------------------------USER PANEL-------------------------------------------\n";
        cout << "\t1-Log In(As User)\n";
        cout << "\t2-Sign Up(As User)\n";
        cout << "\t3-Go Back\n";
        cout << "\t==>";
        cin >> user_command;
        switch (user_command)
        {
        case 1:
            if (login_panel(2) != 0)
                return;
            break;
        case 2:
            if (step_of_user >= MAX_USER)
            {
                cout << "\t!!The Number Of Users Out Of Memory!!\n";
                break;
            }
            signup_panel(2);
            break;
        case 3:
            return;
        default:
            incorrect_command();
            break;
        }
    }
    return;
}
//---------------------------------------------------------------------------------------------------
int login_panel(int command)
{
    char username_a[MAX_LEN];
    char password_a[MAX_LEN];
    int n;
    cout << "-------------------------------------------LOG IN PANEL-----------------------------------------\n";
    if (command == 1)
    {
        while (1)
        {
            cout << "\tEnter Your Username:";
            cin >> username_a;
            n = valid_check_username(username_a, command, step_of_admin);
            if (n == -1)
            {
                if (choice_way(command) == 2)
                    return 0;
            }
            else
                break;
        }
        while (1)
        {
            cout << "\tEnter Your Password:";
            cin >> password_a;
            if (valid_check_password(password_a, command, n) == false)
            {
                if (choice_way(command) == 2)
                    return 0;
            }
            else
                break;
        }
    }
    else
    {
        while (1)
        {
            cout << "\tEnter Your Username:";
            cin >> username_a;
            n = valid_check_username(username_a, command, step_of_user);
            if (n == -1)
            {
                if (choice_way(command) == 2)
                    return 0;
            }
            else
                break;
        }
        while (1)
        {
            cout << "\tEnter Your Password:";
            cin >> password_a;
            if (valid_check_password(password_a, command, n) == false)
            {
                if (choice_way(command) == 2)
                    return 0;
            }
            else
                break;
        }
    }
    if (command == 1)
    {
        cout << "\t!!Successful Enter!!\n";
        admin_dashboard(n);
    }
    else
    {
        cout << "\t!!Successful Enter!!\n";
        user_dashboard(n);
    }
    return 1;
}
//--------------------------------------------------------------------------------------------------------
void signup_panel(int command)
{
    INFO_OF_USER sign_up;
    char confirmation_password[MAX_LEN];
    cout << "-------------------------------------------SIGN UP PANEL----------------------------------------\n";
    while (1)
    {
        cout << "\tEnter Your First Name:";
        cin >> sign_up.first_name;
        if (check_firstname(sign_up.first_name) == false)
        {
            if (choice_way(command) == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter Your Last Name:";
        cin >> sign_up.last_name;
        if (check_lastname(sign_up.last_name) == false)
        {
            if (choice_way(command) == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter Your Phone Number:";
        cin >> sign_up.No_user;
        if (check_phonenumber(sign_up.No_user) == false)
        {
            if (choice_way(command) == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter Your Username:";
        cin >> sign_up.username;
        if (check_username(sign_up.username) == false || check_uniqueness_username(command, sign_up.username) == false)
        {
            if (choice_way(command) == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter Your Password:";
        cin >> sign_up.password;
        if (check_password(sign_up.password) == false)
        {
            if (choice_way(command) == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter Confirmation Of Password:";
        cin >> confirmation_password;
        if (check_t_password(confirmation_password, sign_up.password) == false)
        {
            if (choice_way(command) == 2)
                return;
        }
        else
            break;
    }
    cout << "\tRegistration Completed Successfully\n";
    if (command == 1)
    {
        all_admin[step_of_admin] = sign_up;
        step_of_admin++;
    }
    else
    {
        all_user[step_of_user] = sign_up;
        step_of_user++;
    }
    return;
}
//--------------------------------------------------------------------------------------------
void admin_dashboard(int index)
{
    int command;
    while (1)
    {
        cout << "-----------------------------------------ADMIN DASHBOARD----------------------------------------\n"
             << "\tHello " << all_admin[index].first_name << endl;
        command = ad_dash_menu();
        switch (command)
        {
        case ADMIN_DASHBOARD_MENU::ADD_FLIGHT:
            if (number_of_flight >= MAX_FLIGHT)
            {
                cout << "\t!!The Number Of Flight Out Of Memory!!\n";
                break;
            }
            add_flight();
            break;
        case ADMIN_DASHBOARD_MENU::FLIGHT_STATISTICS:
            fly_statistics();
            break;
        case ADMIN_DASHBOARD_MENU::TICKET_CONFIRMATION:
            ticket_confirmation();
            break;
        case ADMIN_DASHBOARD_MENU::VIEW_FLIGHTS_A:
            view_flights_for_ad();
            break;
        case ADMIN_DASHBOARD_MENU::LOG_OUT_A:
            return;
        default:
            incorrect_command();
            break;
        }
    }
}
//------------------------------------------------------------------------------------------
void user_dashboard(int index)
{
    int command;
    while (1)
    {
        cout << "-----------------------------------------USER DASHBOARD-----------------------------------------\n";
        cout << "\tHello " << all_user[index].first_name << endl;
        command = us_dash_menu();
        switch (command)
        {
        case USER_DASHBOARD_MENU::BUY_TICKET:
            buy_ticket(index);
            break;
        case USER_DASHBOARD_MENU::VIEW_FLIGHTS_U:
            view_flights_for_us();
            break;
        case USER_DASHBOARD_MENU::VIEW_TICKETS:
            view_tickets(all_user[index].username);
            break;
        case USER_DASHBOARD_MENU::LOG_OUT_U:
            return;
        default:
            incorrect_command();
            break;
        }
    }
}