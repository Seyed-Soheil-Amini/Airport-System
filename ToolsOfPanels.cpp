// Author : Seyed Mohammad Soheil Amini
// Up To Date : 2022/01/04
#include "Definitions.hpp"
//-------------------------------------------------------------------------------------------------
void add_flight()
{
    FLIGHT read_flight;
    cout << "-------------------------------------------ADD FLIGHT PANEL-------------------------------------------\n";
    while (1)
    {
        cout << "\tEnter the id of flight : ";
        cin >> read_flight.fly_id;
        if (check_fly_id(read_flight.fly_id) == false || check_uniqueness_fly_id(read_flight.fly_id) == false)
        {
            if (choice_way_ad_dash() == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter the origin of flight : ";
        cin >> read_flight.origin;
        if (check_origin(read_flight.origin) == false)
        {
            if (choice_way_ad_dash() == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter the destination of flight : ";
        cin >> read_flight.destination;
        if (check_destination(read_flight.destination) == false)
        {
            if (choice_way_ad_dash() == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter the date of flight : \n";
        read_flight.date = read_date();
        if (check_date_of_fly(read_flight.date) == false)
        {
            if (choice_way_ad_dash() == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter the time of flight : \n";
        read_flight.time = read_time();
        if (check_time_of_fly(read_flight.time) == false)
        {
            if (choice_way_ad_dash() == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter the name of airline : ";
        cin >> read_flight.airline_name;
        if (strlen(read_flight.airline_name) > 25)
        {
            cout << "\t!!WARNING!!The name of airline is incorrect!!WARNING!!\n";
            if (choice_way_ad_dash() == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        cout << "\tEnter the payload : ";
        cin >> read_flight.payload;
        if (0 > read_flight.payload || read_flight.payload > PAYLOAD)
        {
            cout << "\t!!WARNING!!The number of payload is incorrect!!WARNING!!\n";
            if (choice_way_ad_dash() == 2)
                return;
        }
        else
            break;
    }
    cout << "\tThe flight was successfully registered\n";
    all_flight[number_of_flight] = read_flight;
    number_of_flight++;
    return;
}
//-------------------------------------------------------------------------------------------------
void fly_statistics()
{
    unsigned long int id_fly, n, ary_index_passenger[PAYLOAD], step = 0, number_of_passenger = 1;
    cout << "-------------------------------------FLIGHT STATISTICS PANEL--------------------------------------\n";
    while (1)
    {
        cout << "\tEnter the id of flight : ";
        cin >> id_fly;
        n = check_valid_id_of_fly(id_fly);
        if (n == -1)
        {
            if (choice_way_ad_dash() == 2)
                return;
        }
        else
        {
            show_info_of_fly_for_sta(all_flight[n]);
            cout << "\tInformation of passenger\n";
            for (int i = 0; i < number_of_ticket; i++)
            {
                if (all_ticket[i].flight_id == id_fly)
                {
                    ary_index_passenger[step] = i;
                    step++;
                }
            }
            for (int i = 0; i < step; i++)
            {
                for (int j = 0; j < step_of_user; j++)
                {
                    if (strcmp(all_ticket[ary_index_passenger[i]].user_id, all_user[j].username) == 0)
                    {
                        cout << "\t\t\tpassenger" << number_of_passenger << endl;
                        cout << "\t\t\t\tFisrt Name : " << all_user[j].first_name << endl;
                        cout << "\t\t\t\tLast Name : " << all_user[j].last_name << endl;
                        number_of_passenger++;
                    }
                }
            }
            break;
        }
    }
    system("pause");
    return;
}
//-------------------------------------------------------------------------------------------------
void ticket_confirmation()
{
    char user_id[MAX_LEN];
    unsigned long int fly_id;
    cout << "--------------------------------TICKET CONFIRMATION PANEL--------------------------------\n";
    cout << "\tEnter username of user : ";
    cin >> user_id;
    cout << "\tEnter id of flight : ";
    cin >> fly_id;
    if (check_valid_ticket(user_id, fly_id) == false)
        cout << "\t!!WARNING!!This ticket is invalid!!WARNING!!\n";
    else
        cout << "\tThis ticket is valid\n";
    return;
}
//-------------------------------------------------------------------------------------------------
void view_flights_for_ad()
{
    cout << "--------------------------------VIEW INFORMATION OF ALL FLIGHT----------------------------------\n";
    view_info_of_all_flights();
    system("pause");
    return;
}
//-------------------------------------------------------------------------------------------------
void buy_ticket(int index)
{
    char origin[MAX_LEN], destination[MAX_LEN];
    int ary[MAX_FLIGHT], len_of_ary, choice;
    while (1)
    {
        len_of_ary = 0;
        cout << "--------------------------------BUYING TICKET PANEL--------------------------------\n";
        cout << "\tEnter your origin : ";
        cin >> origin;
        cout << "\tEnter your destination : ";
        cin >> destination;
        if (check_valid_org_des(ary, &len_of_ary, origin, destination) == false)
        {
            if (choice_way_us_dash() == 2)
                return;
        }
        else
            break;
    }
    while (1)
    {
        for (int i = 0; i < len_of_ary; i++)
        {
            cout << "\t\tInformation of flight " << ary[i] + 1 << endl;
            show_info_of_fly_for_us(all_flight[ary[i]]);
            cout << endl;
        }
        choice = choice_way_for_buy_ticket();
        if (choice == 0)
            return;
        else
        {
            for (int i = 0; i < len_of_ary; i++)
            {
                if (choice == all_flight[ary[i]].fly_id && check_uniqueness_ticket(index, choice) == true)
                {
                    strcpy(all_ticket[number_of_ticket].user_id, all_user[index].username);
                    all_ticket[number_of_ticket].flight_id = choice;
                    cout << "\tTicket successfully bought\n";
                    number_of_ticket++;
                    all_flight[ary[i]].payload--;
                    all_flight[ary[i]].num_passenger++;
                    return;
                }
            }
            if (choice_way_us_dash() == 2)
                return;
        }
    }
    system("pause");
    return;
}
//-------------------------------------------------------------------------------------------------
void view_flights_for_us()
{
    int counter = 0;
    cout << "--------------------------------VIEW FLIGHTS FOR USER--------------------------------\n";
    if (number_of_flight == 0)
    {
        cout << "!!WARNING!!There is not exist any flight!!WARNING!!";
        system("pause");
        return;
    }
    for (int i = 0; i < number_of_flight; i++)
    {
        if (all_flight[i].payload != 0)
        {
            cout << "\t\tInformation of flight " << i + 1 << endl;
            show_info_of_fly_for_us(all_flight[i]);
            counter++;
        }
    }
    if (counter == 0)
        cout << "\t!!WARNING!!There is not any flight by null payload!!WARNING!!\n";
    system("pause");
    return;
}
//--------------------------------------------------------------------------------------------------
void view_tickets(char username_of_user[])
{
    int ary_flight_id[MAX_FLIGHT], ary_fly_index[MAX_FLIGHT];
    int step = 0, steps = 0;
    for (int i = 0; i < number_of_ticket; i++)
    {
        if (strcmp(all_ticket[i].user_id, username_of_user) == 0)
        {
            ary_flight_id[step] = all_ticket[i].flight_id;
            step++;
        }
    }
    for (int i = 0; i < step; i++)
    {
        for (int j = 0; j < number_of_flight; j++)
        {
            if (all_flight[j].fly_id == ary_flight_id[steps])
            {
                ary_fly_index[steps] = j;
                steps++;
                break;
            }
        }
    }
    cout << "--------------------------------VIEW TICKETS OF USER--------------------------------\n";
    if (step == 0)
    {
        cout << "\t!!WARNING!!Your have not any ticket!!WARNING!!\n";
        system("pause");
        return;
    }
    for (int i = 0; i < step; i++)
    {
        cout << "\t\tInformation of ticket " << i + 1 << endl;
        show_info_of_ticket_us(all_flight[ary_fly_index[i]]);
        cout << endl;
    }
}