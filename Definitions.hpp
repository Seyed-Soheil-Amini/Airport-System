//Author : Seyed Mohammad Soheil Amini
//Up To Date : 2022/01/06
#pragma once
#include <iostream>
#include <string.h>
#define MAX_LEN 50
#define MAX_ADMIN 10
#define MAX_USER 10
#define MAX_FLIGHT 50
#define PAYLOAD 250
//------------------------------------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------------------------------------
enum ADMIN_DASHBOARD_MENU
{
    ADD_FLIGHT,
    FLIGHT_STATISTICS,
    TICKET_CONFIRMATION,
    VIEW_FLIGHTS_A,
    LOG_OUT_A,
    INVALID_COMMAND_A
};
//------------------------------------------------------------------------------------------------------------
enum USER_DASHBOARD_MENU
{
    BUY_TICKET,
    VIEW_FLIGHTS_U,
    VIEW_TICKETS,
    LOG_OUT_U,
    INVALID_COMMAND_U
};
//------------------------------------------------------------------------------------------------------------
struct DATE
{
    int year;
    int month;
    int day;
};
//------------------------------------------------------------------------------------------------------------
struct TIME
{
    int hour;
    int minute;
};
//------------------------------------------------------------------------------------------------------------
struct FLIGHT
{
    unsigned long int fly_id;
    char origin[MAX_LEN];
    char destination[MAX_LEN];
    DATE date;
    TIME time;
    char airline_name[MAX_LEN];
    int num_passenger = 0;
    int payload;
};
//------------------------------------------------------------------------------------------------------------
struct TICKET
{
    char user_id[MAX_LEN];
    int flight_id;
};
//------------------------------------------------------------------------------------------------------------
struct INFO_OF_USER
{
    char first_name[MAX_LEN];
    char last_name[MAX_LEN];
    char No_user[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
};
//------------------------------------------------------------------------------------------------------------
INFO_OF_USER all_admin[MAX_ADMIN];
INFO_OF_USER all_user[MAX_USER];
FLIGHT all_flight[MAX_FLIGHT];
TICKET all_ticket[MAX_FLIGHT * MAX_USER];
int step_of_admin = 0;
int step_of_user = 0;
int number_of_flight = 0;
int number_of_ticket = 0;
//------------------------------------------------------------------------------------------------------------
/**
* user by choosing the user panel command in main menu ,is entered this function 
* and enters his or her command such as login or signup 
*/
void user_panel();
/**
* admin by choosing the admin panel command in mian menu ,is entered this function 
* and enters his or her command such as login or signup 
*/
void admin_panel();
/**
* this function get information of per user include user and admin for signing up he or she 
* @param command:becuase this function is common for admin and user,this parameter that is sent from  
* user panel or admin panel ,distinguishs to get information from which one user or admin 
*/
void signup_panel(int command);
/**
* this function get username and password of per user include user and admin for loging  
* in her or his dashboard . 
* ofcourse,before loging in it checks the entered information   
* @param command becuase this function is common for admin and user,this parameter that is sent from  
* user panel or admin panel ,distinguishs to get information from which one user or admin 
* @return when user or admin enters the incorrect information ,he or she can choice two command 
* 1-again enter 2-come back relevant panel 
* if choice 2 ,this function retrun 0 for come back to relevant panel 
*/
int login_panel(int command);
/**
* this function for admin dashboard  
* admin by using this function can employe other abilities that develop soon! 
* @param index: it is sent from log in panel for distinguishing which admin enters her or his dashboard   
*/
void admin_dashboard(int index);
/**
* this function for user dashboard 
* user by using this function can employ other abilities that develop soon! 
* @param index: it is sent from log in panel for distinguishing which user enters her or his dashboard
*/
void user_dashboard(int index);
/**
* this function warns to user or admin for incorrect command 
*/
void incorrect_command();
/**
* this function when user or admin enters the incorrect information  warns to he or she   
* and show to item for choosing  
* @param panel: this parameter to distinguish the coming back to which one panel
* @return: i use this return wherefor previous function can distinguish what it must do 
*/
int choice_way(int panel);
/**
* this function checks syntaxly first name 
* @param fisrt_n[]:first name of user or admin
* @return:true or false that shows fisrt name is correct or incorrect
*/
bool check_firstname(char first_n[]);
/**
* this function checks syntaxly last name 
* @param last_n[]:last name of user or admin
* @return:true or false that shows last name is correct or incorrect
*/
bool check_lastname(char last_n[]);
/**
* this function checks syntaxly phone number 
* @param phone number[]:phone number of user or admin
* @return:true or false that shows phone number is correct or incorrect
*/
bool check_phonenumber(char phone_n[]);
/**
* this function checks syntaxly username 
* @param username[]username of user or admin
* @return:true or false that shows username is correct or incorrect
*/
bool check_username(char user_n[]);
/**
* this function checks uniqely username of user or admin  
* @param command:this parameter for distinguising user or admin 
* @param user[]:entered user 
* @return:shows username is unique or no
*/
bool check_uniqueness_username(int command, char user[]);
/**
* this function checks syntaxly password 
* @param password[]password of user or admin
* @return:true or false that shows password is correct or incorrect
*/
bool check_password(char pass_w[]);
/**
* this function checks syntaxly confirmation of password 
* @param Tpass_w confirmation of user or admin
* @return true or false that shows confirmation is correct or incorrect
*/
bool check_t_password(char Tpass_w[], char pass_w[]);
/**
* this function check validly username 
* @param in_username:this parameter is entered username as user or admin
* @param command:to distingiush which one user or admin
* @param st:the number of user or admin that entered
* @return:result of checking that sends as integer 
*/
int valid_check_username(char in_username[], int command, int st);
/**
* this function check validly password 
* @param in_password:this parameter is entered password as user or admin
* @param command:to distingiush which one user or admin
* @param st:the number of user or admin that entered
* @return:result of checking that sends as boolean 
*/
bool valid_check_password(char in_password[], int command, int st);
/**
* this function whenfor the signingup of user or admin is incomplete that the incompelete  
* information entered  have saved in memory  
* @param index:number of user or admin who is loging in
* @param command:to distinguish which one user or admin is loging in
* @return:result of checking that sends as boolean
*/
int count_capital(char str[]);
/**
* this function for counting the number of small words  
* this function is used for syntaxly check of many information of user or admin 
* @param str:the string that is counted its small words
* @return:result of counting 
*/
int count_small(char str[]);
/**
* this function for counting the number of number characters  
* this function is used for syntaxly check of many information of user or admin 
* @param str:the string that is counted its number characters
* @return:result of counting 
*/
int count_number(char str[]);
/**
 * this function shows the menu of admin dashboard  
 * @return return the command that has been chosen by admin as enum
 */
ADMIN_DASHBOARD_MENU ad_dash_menu();
/**
 * this function shows the menu of user dashboard  
 * @return return the command that has been chosen by user as enum
 */
USER_DASHBOARD_MENU us_dash_menu();
/**
 * this function is for admin dashboard that admin can add a flight to list of flight   
 */
void add_flight();
/**
 * this function is for admin dashboard that admin can get statistics from list of flight  
 */
void fly_statistics();
/**
 * this function is for th admin dashboad that admin can see list of flight 
 */
void view_flights_for_ad();
/**
 * this function is for the admin dashboard that admin can confiram a ticket  
 * by means of user_id and fly_id of per ticket 
 */
void ticket_confirmation();
/**
 * this function is for the user dashboard that user can buy a ticket  
 * for finding out the buying tickets proccess,you can refer to definition of  
 * function with name : check_valid_org_des and  with name : check_uniqueness_ticket
 * after the ticket was bought,username of user is saved in user id of ticket  
 * and fly id is saved in fly id of ticket 
 * @param index the index of user which saved in list of all user
 */
void buy_ticket(int index);
/**
 * this function shows the list of flight by empty payload for user  
 */
void view_flights_for_us();
/**
 * this function shows the tickets of user   
 * at fisrt,it searchs in list of tickets and find username of user that has bought some tickets 
 * then,it saved his or her id_fly of tickets in relevant array,then by searching in list of all flight 
 * and comparing ids of flights with elements of metioned array and print information  
 * of per flight that bought by user 
 * @param username_of_user username of user that want to see his or her tickets
 */
void view_tickets(char username_of_user[]);
/**
 * this function syntaxly checks the per flight id 
 * @param fly_id the id of flight which entered by user
 * @return it returns the result of checking proccess as boolean  
 */
bool check_fly_id(int fly_id);
/**
 * this function checks the fly_id that is uniqueness 
 * @param fly_id the id of flight which entered by admin
 * @return it returns the result of checking proccess as boolean
 */
bool check_uniqueness_fly_id(int fly_id);
/**
 * this function syntaxly checks the origin which entered by admin for adding a flight 
 * @param fly_origin the string of origin which entered by admin
 * @return it returns the result of checking proccess as boolean
 */
bool check_origin(char fly_origin[]);
/**
 * this function syntaxly checks the destination which entered by admin for adding a flight  
 * @param fly_origin the string of destination which entered by admin
 * @return it returns the result of checking proccess as boolean
 */
bool check_destination(char fly_destination[]);
/**
 * this function checkes the date which entered by admin for adding a flight  
 * (year must be between 2000 and 3000) 
 * (month must be between 1 and 12) 
 * (day must be between 1 and 30) 
 * @param date_of_fly the date of flight which entered by admin as a record
 * @return it returns the result of checking proccess as boolean
 */
bool check_date_of_fly(DATE date_of_fly);
/**
 * this function checks the time which entered by admin for adding a flight  
 * (hour must be between 1 and 23) 
 * (minute must be between 0 and 59) 
 * @param time_of_fly the time of flight which entered by admin as a record
 * @return it returns the result of checking proccess as boolean
 */
bool check_time_of_fly(TIME time_of_fly);
/**
 * this function for user dashboard that checks origin and destination that were entered by user 
 * for buying a ticket  
 * at fisrt, this function searchs in list of all flights for finding the mentioned origin and destination  
 * when it found the origin and destination ,it saves its indexes of all flights that has mentioned  
 * origin and destination in a array and in next part checks these flights that have null payload  
 * and next part,it refrences the array of indexes and its length  
 * @param index the array for saving the index of flights that have mentioned origin and destination 
 * @param len the length of array
 * @param origin the string of origin that has been entered by user
 * @param destination the string of destination that has been entered by user
 * @return it returns the result of checking proccess as boolean
 */
bool check_valid_org_des(int index[MAX_FLIGHT], int *len, char origin[], char destination[]);
/**
 * this function checks the ticket that it is uniqueness or not 
 * its application for prevening while a user buys a ticket twice
 * @param index the index of user in all user list that want buys a ticket
 * @param fly_id the id of flight that has been entered by user
 * @return it returns the result of checking proccess as boolean
 */
bool check_uniqueness_ticket(int index, int fly_id);
/**
 * this function checks validly the ticket that a user want to buy it
 * its application in the ticket confirmtion panel in admin dashboard
 * @param user_id the username of user that was bought the thicket
 * @param fly_id the id of flight that was bought by mentioned user
 * @return it returns the result of checking proccess as boolean
 */
bool check_valid_ticket(char user_id[], int fly_id);
/**
 * this function checks validly the id of flight 
 * its application in statistics flight panel 
 * it sreachs in list of all flight, when finds the flight with fly_id that has been entered by user 
 * ,returns the index of this flight in list of all flight 
 * @param id_fly the  id of flight that has been entered by admin
 * @return it retruns the result of checking proccess as integer(index) 
 * if the flight does not exist ths function return -1  
 */
int check_valid_id_of_fly(int id_fly);
/**
 * this function for field of admin dashboard
 * while admin enters a incorrect enter ,this function shows a warning then want to admin 
 * to enter a command to distinct continue way 
 * @return it returns mentioned command
 */
int choice_way_ad_dash();
/**
 * this function for field of user dashboard
 * while user enters a incorrect enter ,this function shows a warning then want to user 
 * to enter a command to distinct continue way 
 * @return it returns mentioned command
 */
int choice_way_us_dash();
/**
 * this function shows the information of a flight 
 * @param fly it shows information of this flight
 */
void show_info_of_fly(FLIGHT fly);
/**
 * this function for while user enter a incorrect origin or destination 
 * it shows a warning then want to user to enter a command that tis command distincts continue way
 * @return it returns chosen command as a integer
 */
int choice_way_for_buy_ticket();
/**
 * this function shows the information of all flights
 */
void view_info_of_all_flights();
/**
 * this function get a date from user
 * @return after get a date ,it returns this date as a record
 */
DATE read_date();
/**
 * this function get a time from user
 * @return after get a time ,it returns this time as a record 
 */
TIME read_time();
/**
 * this function counts the number of times that digit zero reapet in a number
 * for id of flight untill it have not zero digit
 */
int count_digit_zero(int num);
/**
 * this function shows the information of flight that has been bought by user
 * @param fly it prints the information of this flight 
 */
void show_info_of_ticket_us(FLIGHT fly);
/**
 * this function shows the information of flight for user 
 * @param fly it prints the information of this flight
 */
void show_info_of_fly_for_us(FLIGHT fly);
/**
 * this function shows the information of flight that has been stastisticesed by admin  
 * @param fly it prints the information of this flight
 */
void show_info_of_fly_for_sta(FLIGHT fly);