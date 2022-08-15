//Author : Seyed Mohammad Soheil Amini
//Up To Date : 2022/01/04
#include "Definitions.hpp"
//-------------------------------------------------------------------------------------------------
bool check_fly_id(int fly_id)
{
    if (count_digit_zero(fly_id) == 0)
        return true;
    cout << "\t!!WARNING!!This id is incorrect(id must has just numbers)!!WARNING!!\n";
    return false;
}
//-------------------------------------------------------------------------------------------------
bool check_uniqueness_fly_id(int fly_id)
{
    for (int i = 0; i < number_of_flight; i++)
    {
        if (fly_id == all_flight[i].fly_id)
        {
            cout << "\t!!WARNING!!This id has already been entered!!WARNING!!\n";
            return false;
        }
    }
    return true;
}
//-------------------------------------------------------------------------------------------------
bool check_origin(char fly_origin[])
{
    if (strlen(fly_origin) <= 50 && count_number(fly_origin) == 0)
        return true;
    cout << "\t!!WARNING!!This origin is incorrect!!WARNING!!\n";
    return false;
}
//-------------------------------------------------------------------------------------------------
bool check_destination(char fly_destination[])
{
    if (strlen(fly_destination) <= 50 && count_number(fly_destination) == 0)
        return true;
    cout << "\t!!WARNING!!This destination is incorrect!!WARNING!!\n";
    return false;
}
//-------------------------------------------------------------------------------------------------
bool check_date_of_fly(DATE date_of_fly)
{
    if (2000 > date_of_fly.year || date_of_fly.year > 3000)
    {
        cout << "\t!!WARNING!!This date is incorrect(2000 <= year <= 3000)!!WARNING!!\n";
        return false;
    }
    else if (1 > date_of_fly.month || date_of_fly.month > 12)
    {
        cout << "\t!!WARNING!!This date is incorrect(1 <= month <= 12)!!WARNING!!\n";
        return false;
    }
    else if (1 > date_of_fly.day || date_of_fly.day > 30)
    {
        cout << "\t!!WARNING!!This date is incorrect(1 <= day <= 30)!!WARNING!!\n";
        return false;
    }
    else
        return true;
}
//-------------------------------------------------------------------------------------------------
bool check_time_of_fly(TIME time_of_fly)
{
    if (0 > time_of_fly.hour || time_of_fly.hour > 23)
    {
        cout << "\t!!WARNING!!This time is incorrect(0 <= hour <= 23!!WARNING!!\n";
        return false;
    }
    else if (0 > time_of_fly.minute || time_of_fly.minute > 59)
    {
        cout << "\t!!WARNING!!This time is incorrect(0 <= minute <= 59!!WARNING!!\n";
        return false;
    }
    else
        return true;
}
//-------------------------------------------------------------------------------------------------
bool check_valid_org_des(int index[MAX_FLIGHT], int *len, char origin[], char destination[])
{
    int alen = 0;
    for (int i = 0; i < number_of_flight; i++)
    {
        if (strcmp(origin, all_flight[i].origin) == 0 && strcmp(destination, all_flight[i].destination) == 0 && all_flight[i].payload != 0)
        {
            index[alen] = i;
            alen++;
            *len = *len + 1;
        }
    }
    if (alen == 0)
    {
        cout << "\t!!WARNING!!This flight does not exist or has not empty payload!!WARNING!!\n";
        return false;
    }
    else
        return true;
}
//-------------------------------------------------------------------------------------------------
bool check_uniqueness_ticket(int index, int fly_id)
{
    int j = 0, ary[MAX_USER];
    for (int i = 0; i < number_of_ticket; i++)
    {
        if (strcmp(all_ticket[i].user_id, all_user[index].username) == 0)
        {
            ary[j] = i;
            j++;
        }
    }
    if (j != 0)
    {
        for (int i = 0; i < j; i++)
        {
            if (all_ticket[ary[i]].flight_id == fly_id)
            {
                cout << "\t!!WARNING!!You have already been bought this ticket!!WARNING!!\n";
                return false;
            }
        }
        return true;
    }
    else
        return true;
}
//-------------------------------------------------------------------------------------------------
bool check_valid_ticket(char user_id[], int fly_id)
{
    int ary_index[MAX_FLIGHT], step = 0;
    for (int i = 0; i < number_of_ticket; i++)
    {
        if (strcmp(all_ticket[i].user_id, user_id) == 0)
        {
            ary_index[step] = i;
            step++;
        }
    }
    if (step == 0)
        return false;
    for (int i = 0; i < step; i++)
    {
        if (all_ticket[ary_index[i]].flight_id == fly_id)
            return true;
    }
    return false;
}
//-------------------------------------------------------------------------------------------------
int check_valid_id_of_fly(int id_fly)
{
    for (int i = 0; i < number_of_flight; i++)
    {
        if (id_fly == all_flight[i].fly_id)
            return i;
    }
    cout << "\t!!WARNING!!This id of flight is invalid!!WARNING!!\n";
    return -1;
}
//-------------------------------------------------------------------------------------------------
int choice_way_ad_dash()
{
    int sub_command;
    while (1)
    {
        cout << "\t\t\t1-Enter Again\n"
             << "\t\t\t2-Go back to admin dashboard\n"
             << "\t\t\t==>";
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
//-------------------------------------------------------------------------------------------------
int choice_way_us_dash()
{
    int sub_command;
    while (1)
    {
        cout << "\t\t\t1-Enter Again\n"
             << "\t\t\t2-Go back to user dashboard\n"
             << "\t\t\t==>";
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
//-------------------------------------------------------------------------------------------------
int choice_way_for_buy_ticket()
{
    int sub_command;
    cout << "\t\tEnter the command ('0' for come back to user dashboard,id of your flight for buying this flight)\n";
    cout << "==>";
    cin >> sub_command;
    switch (sub_command)
    {
    case 0:
        return 0;
        break;
    default:
        return sub_command;
    }
}
//-------------------------------------------------------------------------------------------------
int count_digit_zero(int num)
{
    int rev, sum = 0;
    while (num > 0)
    {
        rev = num % 10;
        if (rev == 0)
            sum++;
        num /= 10;
    }
    return sum;
}
//-------------------------------------------------------------------------------------------------
void view_info_of_all_flights()
{
    if (number_of_flight == 0)
    {
        cout << "\t!!WARNING!!There is nothing flight!!WARNING!!\n";
        return;
    }
    for (int i = 0; i < number_of_flight; i++)
    {
        cout << "\t\t\tThe information of flight" << i + 1 << endl;
        show_info_of_fly(all_flight[i]);
    }
}
//-------------------------------------------------------------------------------------------------
DATE read_date()
{
    DATE date;
    cout << "\t\tYear : ";
    cin >> date.year;
    cout << "\t\tMonth : ";
    cin >> date.month;
    cout << "\t\tDay : ";
    cin >> date.day;
    return date;
}
//-------------------------------------------------------------------------------------------------
TIME read_time()
{
    TIME time;
    cout << "\t\thour : ";
    cin >> time.hour;
    cout << "\t\tminute : ";
    cin >> time.minute;
    return time;
}
//-------------------------------------------------------------------------------------------------
void show_info_of_fly(FLIGHT fly)
{
    cout << "\tThe id : " << fly.fly_id << endl;
    cout << "\tThe origin : " << fly.origin << endl;
    cout << "\tThe destination : " << fly.destination << endl;
    cout << "\tThe date : " << fly.date.year << "/" << fly.date.month << "/" << fly.date.day << endl;
    cout << "\tThe time : " << fly.time.hour << ":";
    (fly.time.minute != 0) ? cout << fly.time.minute << endl : cout << "00" << endl;
    cout << "\tThe airline name : " << fly.airline_name << endl;
    cout << "\tThe number of passengers : " << fly.num_passenger << endl;
    cout << "\tThe payload : " << fly.payload << endl;
}
//-------------------------------------------------------------------------------------------------
void print_ticket()
{
    for (int i = 0; i < number_of_ticket; i++)
    {
        cout << "\n\tINFO OF TICKET " << i + 1 << endl;
        cout << "user_id : ";
        cout << all_ticket[i].user_id << endl;
        cout << "fly_id : ";
        cout << all_ticket[i].flight_id << endl;
    }
}
//-------------------------------------------------------------------------------------------------
void show_info_of_ticket_us(FLIGHT fly)
{
    cout << "\tThe id : " << fly.fly_id << endl;
    cout << "\tThe origin : " << fly.origin << endl;
    cout << "\tThe destination : " << fly.destination << endl;
    cout << "\tThe date : " << fly.date.year << "/" << fly.date.month << "/" << fly.date.day << endl;
    cout << "\tThe time : " << fly.time.hour << ":";
    (fly.time.minute != 0) ? cout << fly.time.minute << endl : cout << "00" << endl;
    cout << "\tThe airline name : " << fly.airline_name << endl;
}
//-------------------------------------------------------------------------------------------------
void show_info_of_fly_for_us(FLIGHT fly)
{
    cout << "\tThe id : " << fly.fly_id << endl;
    cout << "\tThe origin : " << fly.origin << endl;
    cout << "\tThe destination : " << fly.destination << endl;
    cout << "\tThe date : " << fly.date.year << "/" << fly.date.month << "/" << fly.date.day << endl;
    cout << "\tThe time : " << fly.time.hour << ":";
    (fly.time.minute != 0) ? cout << fly.time.minute << endl : cout << "00" << endl;
    cout << "\tThe airline name : " << fly.airline_name << endl;
    cout << "\tThe payload : " << fly.payload << endl;
}

void show_info_of_fly_for_sta(FLIGHT fly)
{
    cout << "\tThe origin : " << fly.origin << endl;
    cout << "\tThe destination : " << fly.destination << endl;
    cout << "\tThe date : " << fly.date.year << "/" << fly.date.month << "/" << fly.date.day << endl;
    cout << "\tThe time : " << fly.time.hour << ":";
    (fly.time.minute != 0) ? cout << fly.time.minute << endl : cout << "00" << endl;
    cout << "\tThe airline name : " << fly.airline_name << endl;
    cout << "\tThe number of passengers : " << fly.num_passenger << endl;
    cout << "\tThe payload : " << fly.payload << endl;
}