#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <map>
#include <sstream>
using namespace std;

float principle = 1000;
float rate = 0.05;

char ans;
string ID;
double initialamount;

// My extra application on bank system
void accounts_in_the_bank(map<string, int> &mpp)
{
    char c;
    do
    {
        cout << "Please enter a new account ID : (positive numbers , letters only ) " << '\n';
        cin >> ID;
        for (int i = 0; i < ID.length(); i++)
        {
            if (ID[i] == '-')
            {
                cout << "Invalid ID ! please enter Positive numbers or letters only " << '\n';
                cin >> ID;
            }
        }

        cout << "Enter the initial amount to deposit " << '\n';
        cin >> initialamount;
        do
        {

            if (initialamount < 0)
            {
                cout << "Invalid value ! , please enter positive number " << '\n';
                cin >> initialamount;
            }
        } while (initialamount < 0);

        auto result = mpp.insert({ID, initialamount});
        if (result.second == false)
        {
            cout << "This ID was taken by another customer ! Please new ID " << '\n';
        }
        else
        {
            cout << "Account " << ID << " has been created successfuly " << '\n';
        }
        cout << "====================================================" << '\n';
        cout << "====================================================" << '\n';
        cout << "Do you want to create a new account ? (Y/N)" << '\n';
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            continue;
        }
        else if (c == 'N' || c == 'n')
        {
            break;
        }
        do
        {
            if (c != 'Y' && c != 'y' && c != 'N' && c != 'n')
            {
                cout << "Please enter (Y , y for YES) or (N , n for NO)" << '\n';
                cin >> c;
                continue;
            }
        } while (c != 'Y' && c != 'y' && c != 'N' && c != 'n');

    } while (c == 'y' || c == 'Y');
}
bool withdrawall = false;



void withdrawal(string ID, double value_withdrawal, map<string, int> &mpp)
{                            // Passing by reference (&) to avoid copying data for better performance
    auto itr = mpp.find(ID); // Here we are searching for distinct ID so it will be not good to loop on the whole map , so this is an efficient way and a fast way to find that distinct ID
    if (itr != mpp.end())
    {
        if (itr->second >= value_withdrawal)
        {
            double x = itr->second - value_withdrawal;
            cout << "=============================" << '\n';
            cout << "Your current balance is " << x << '\n';
            cout << "Success withdrawal process " << '\n';
            cout << "=============================" << '\n';
            itr->second = x;
            withdrawall = true;
        }
        else
        {
            cout << "Insufficient funds ! current balance is " << itr->second << '\n';
        }
    }
    else
    {
        cout << "The account is not found , or not created ." << '\n';

        cout << "(You can create a new account by pressing  4) " << '\n';
    }
}



bool Deposited = false;
void Deposit(string ID, double deposit, map<string, int> &mpp)
{
    auto itr = mpp.find(ID);
    if (itr != mpp.end())
    {
        if (deposit >= 0)
        {
            double y = itr->second + deposit;
            cout << "=============================" << '\n';
            cout << "Your current balance is " << y << '\n';
            cout << "Success withdrawal process " << '\n';
            cout << "=============================" << '\n';
            itr->second = y;
            Deposited = true;
        }
        else
        {
            cout << "Insufficient funds ! please enter a positive number" << '\n';
        }
    }
    else
    {
        cout << "The account is not found , or not created ." << '\n';

        cout << "(You can create a new account by pressing  4) " << '\n';
    }
}




void display_accounts(map<string, int> &mpp)
{

    for (const auto &[ID, initialamount] : mpp)
    { // modern way to loop on a map
        cout << "ID account number" << '\t' << "       Balance" << '\n';
        cout << ID << '\t' << '\t' << '\t' << '\t' << initialamount << '\n';
    }
}




void History(string currentID, double amount, string type, vector<string> &M)
{

    if (Deposited)
    {

        stringstream ss;
        ss << "ID : " << currentID << " | " << type << " : " << amount << '\n';
        M.push_back(ss.str());
        Deposited = false;
    }
    if (withdrawall)
    {
        stringstream sp;
        sp << "ID : " << currentID << "| " << type << " : " << amount << '\n';
        M.push_back(sp.str());
        withdrawall = false;
    }
}



void History_display(const vector<string> &M)
{ // Passing by reference (&) to avoid copying data for better performance
    for (const auto &selected_value : M)
    { // Modern way to loop and display
        cout << selected_value << '\n';
    }
}



void search_by_ID(string ID_customer, map<string, int> &mpp)
{
    auto itr = mpp.find(ID_customer); // One shot method
    if (itr != mpp.end())
    {
        cout << "Customer's current balance is " << itr->second << '\n';
    }
    else
    {
        cout << "The account is not found , or not created ." << '\n';

        cout << "(You can create a new account by pressing  4) " << '\n';
    }
}



//----------------------------------------------------------------------------------
// University Assignment

void inputdetails()
{

    cout << "Please enter the principle amount you want to deposit : " << '\n';
    cin >> principle;
    cout << "What's the bank rate for the account type you chose? " << '\n';
    cin >> rate;
}


void yearly_amount(map<int, float> &mp)
{

    cout << "Year " << " " << " Amount on deposit " << '\n';
    for (int years = 1; years <= 10; years++)
    {
        float amount = principle * pow(1.0 + rate, years);
        mp.insert({years, amount});

        cout << years << "              " << amount << '\n';
    }
}

float search_by_year(int year, const map<int, float> &mp)
{ // pass by value (Create a new copy of data (slower but  safe for modification))

    map<int, float>::const_iterator itr; // classic way to loop on a map , compiler gives erorr when writing (::itreator only) as itreators has the access to edit on map and this is not acceptable when writing const in function's parameter
    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        if (itr->first == year)
        {
            return itr->second;
        }
    }
    return 0;
}

int main()
{
    vector<string> M;
    map<int, float> mp;
    map<string, int> mpp;

    do
    {
        cout << "Welcome to mini bank project " << '\n';
        cout << "*****************************" << '\n';

        cout << "(University Assignment requirements) " << '\n';
        cout << "press" << '\n';
        cout << "1 to input account details " << '\n';
        cout << "2 to display yearly amount for 10 years " << '\n';
        cout << "3 to display the amount at a certain speecified year " << '\n';
        cout << "------------------------------------------------" << '\n';
        cout << "(My extra application on bank system)" << '\n';
        cout << "4 add new account to the bank " << '\n';
        cout << "5 make a Withdraw process" << '\n';
        cout << "6 make a deposit process " << '\n';
        cout << "7 Display accounts found in the bank" << '\n';
        cout << "8 Display successful Transactions History " << '\n';
        cout << "9 Search for an account by customer's ID " << '\n';
        cout << "=====================================================" << '\n';
        cout << " Enter your choice : " << '\n';
        char no;
        cin >> no;
        switch (no)
        {
        case '1':

            inputdetails();
            break;

        case '2':

            yearly_amount(mp);
            break;

        case '3':

            int year;
            cout << "Enter the year you want to display the amount reached at : ";
            cin >> year;
            cout << " Amount :" << search_by_year(year, mp) << '\n';
            break;

        case '4':

            accounts_in_the_bank(mpp);
            break;

        case '5':
        {
            double value_withdrawal;
            cout << "Enter the ID account you want to withdrawal from " << '\n';
            cin >> ID;
            cout << "Enter the value you want to withdraw : " << '\n';
            cin >> value_withdrawal;
            do
            {

                if (value_withdrawal < 0)
                {
                    cout << "Invalid value ! Please enter a positive value " << '\n';
                    cin >> value_withdrawal;
                    continue;
                }
            } while (value_withdrawal < 0);

            withdrawal(ID, value_withdrawal, mpp);
            History(ID, value_withdrawal, "Withdrawal", M); // Capture ID and sent it to History() function and capture the withdrawal transaction details into the history vector
            break;
        }

        case '6':
        {
            double deposit;
            cout << "Enter ID " << '\n';
            cin >> ID;
            cout << "Enter the amount you want to deposit " << '\n';
            cin >> deposit;
            Deposit(ID, deposit, mpp);
            History(ID, deposit, "Deposit", M); // Capture ID and sent it to History function and capture the deposit transaction details into the history vector
            break;
        }

        case '7':
            display_accounts(mpp);
            break;

        case '8':

            History_display(M);
            break;

        case '9':
        {
            cout << "Enter customer's ID to search  " << '\n';
            string id;
            cin >> id;
            search_by_ID(id, mpp);
            break;
        }
        default:
            cout << "Invalid choice ! please re-enter the correct one " << '\n';
            continue;
        }
        cout << "******************************" << '\n';
        cout << "Another opertion ? (Y/N) : " << '\n';

        cin >> ans;

        do
        {
            if (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
            {
                cout << "Please enter (Y , y for YES) or (N , n for NO)" << '\n';
                cin >> ans;
                continue;
            }
        } while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');

        if (ans == 'y' || ans == 'Y')
        {
            continue;
        }

        if (ans == 'N' || ans == 'n')
        {
            cout << "Thank you for using our application" << '\n';
            break;
        }

    } while (ans == 'Y' || ans == 'y');

    return 0;
}
