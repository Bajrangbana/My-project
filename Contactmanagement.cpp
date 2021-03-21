#include<iostream>
#include<conio.h>
#include<fstream>
#include <cstring>
#include <string>
#include<stdlib.h>
using namespace std;
string fname,lname,phone_num;
void addContact();
void searchContact();
void checkContactList();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);
int main()
{
    short int choice;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\n\t\t\tContact Management.";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3.Check Contact List\n\t4. Help\n\t0. Exit\n\t> ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            checkContactList();
            break;
        case 4:
            help();
            break;
        case 0:
            self_exit();
            break;
        default:
            cout << "\n\n\tInvalid Input !";
            cout << "\n\tPress Any Key To Continue..";
            getch();
            main();
    }
    return 0;
}

void self_exit()
{
    system("cls");
    char yorn;
    cout << "\n\n\n\t\tAre you sure you want to exit  Y/N\n";
    cin>>yorn;
    if(yorn=='y'||yorn=='Y')
    exit(1);
    else if(yorn=='n'||yorn=='N'){
        main();
    }
    else {
        cout<<"\n\n\n\t\tinvalid input";
        getchar();
        self_exit();
        }
}
void checkContactList()
{
    cout<<"\nContact List....";
    ifstream read;
    read.open("number.txt");
    if(read){
        int recordfound=0;
        string line;
        while(getline(read,line)){
            char name[100];
            strcpy(name,line.c_str());
            char onlyname[100];
            strncpy(onlyname,name,(strlen(name)+1));
            cout<<"\n"<<onlyname;


        }
        read.close();

    }
    else {
        cout<<"\n\n\nNo record found";
    }
    cout<<"\npress any key to continue...";
    getch();


}


void help()
{
    cout << "please contact management for help";
    cout << "\n email id- bhichar1@gmail.com\n\n\n\n\n";
}

void addContact()
{
    ofstream phone("number.txt", ios::app);
    system("cls");
    cout << "\n\n\tEnter First Name : ";
    cin >> fname;
    cout << "\n\tEnter Last Name : ";
    cin >> lname;
    cout << "\n\tEnter 10-Digit Phone Number : ";
    cin >> phone_num;

    if(check_digits(phone_num) == true)
    {
        if(check_numbers(phone_num) == true)
        {
            if(phone.is_open())
            {
                phone << fname << " " << lname << " " << phone_num << endl;
                cout << "\n\tContact Saved Successfully !";
            }
            else
            {
                cout << "\n\tError Opening File !";
            }
        }
        else
        {
            cout << "\n\tA Phone Number Must Contain Numbers Only !";
        }
    }
    else
    {
        cout << "\n\tA Phone Number Must COntain 10 Digits.";
    }
    phone.close();




    while(1){
        system("cls");
        int choice;
        cout<<"\n\t\t1. Go back";
        cout<<"\n\t\t2. exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            main();
            break;
            case 2:
                self_exit();
                break;
            default:
            cout<<"invalid input please try again";
            getchar();


        }

    }
}

void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout << "\n\tEnter Name To Search : ";
    cin >> keyword;
    while(myfile >> fname >> lname >> phone_num)
    {
        if(keyword == fname || keyword == lname)
        {
            system("cls");
            cout << "\n\n\n\t\tContact details..";
            cout << "\n\n\tName : " << fname<<" " << lname;
            cout << "\n\tPhone Number : " << phone_num;
            found = true;
            break;
        }
    }
    if(found == false)
    cout << "\n\tNo Contact Found";
}

bool check_digits(string x)
{
    if(x.length() == 10)
    return true;
    else
    return false;
}

bool check_numbers(string x)
{
    bool check = true;

    for(int i=0; i < x.length(); i++)
    {
        if(!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }

    if(check == true)
    return true;
    if(check == false)
    return false;
}
