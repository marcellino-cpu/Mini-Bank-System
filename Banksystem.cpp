#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>

float principle = 1000;
float rate = 0.05;

char ans;
std::string ID;
double initialamount;


// My extra application on bank system
void accounts_in_the_bank(std::unordered_map<std::string, int> &mpp)
{
    char c;
    do
    {
        std::cout << "Please enter a new account ID : (positive numbers , letters only ) " << '\n';
        std::cin >> ID;
        for (int i = 0; i < ID.length(); i++)
        {
            if (ID[i] == '-')
            {
                std::cout << "Invalid ID ! please enter Positive numbers or letters only " << '\n';
                std::cin >> ID;
            }
        }

        std::cout << "Enter the initial amount to deposit " << '\n';
        std::cin >> initialamount;
        do
        {

            if (initialamount < 0)
            {
                std::cout << "Invalid value ! , please enter positive number " << '\n';
                std::cin >> initialamount;
            }
        } while (initialamount < 0);

        auto result = mpp.insert({ID, initialamount});
        if (result.second == false)
        {
            std::cout << "This ID was taken by another customer ! Please new ID " << '\n';
        }
        else
        {
            std::cout << "Account " << ID << " has been created successfuly " << '\n';
        }
        std::cout << "====================================================" << '\n';
        std::cout << "====================================================" << '\n';
        std::cout << "Do you want to create a new account ? (Y/N)" << '\n';
        std::cin >> c;
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
                std::cout << "Please enter (Y , y for YES) or (N , n for NO)" << '\n';
                std::cin >> c;
                continue;
            }
        } while (c != 'Y' && c != 'y' && c != 'N' && c != 'n');

    } while (c == 'y' || c == 'Y');
}



bool withdrawall = false;
void withdrawal(std::string ID, double value_withdrawal, std::unordered_map<std::string, int> &mpp)
{                            // Passing by reference (&) to avoid copying data for better performance
    auto itr = mpp.find(ID); // Here we are searching for distinct ID so it will be not good to loop on the whole map , so this is an efficient way and a fast way to find that distinct ID
    if (itr != mpp.end())
    {
        if (itr->second >= value_withdrawal)
        {
            double x = itr->second - value_withdrawal;
            std::cout << "=============================" << '\n';
            std::cout << "Your current balance is " << x << '\n';
            std::cout << "Success withdrawal process " << '\n';
            std::cout << "=============================" << '\n';
            itr->second = x;
            withdrawall = true;
        }
        else
        {
            std::cout << "Insufficient funds ! current balance is " << itr->second << '\n';
        }
    }
    else
    {
        std::cout << "The account is not found , or not created ." << '\n';

        std::cout << "(You can create a new account by pressing  4) " << '\n';
    }
}




bool Deposited = false;
void Deposit(std::string ID, double deposit, std::unordered_map<std::string, int> &mpp)
{
    auto itr = mpp.find(ID);
    if (itr != mpp.end())
    {
        if (deposit >= 0)
        {
            double y = itr->second + deposit;
            std::cout << "=============================" << '\n';
            std::cout << "Your current balance is " << y << '\n';
            std::cout << "Success withdrawal process " << '\n';
            std::cout << "=============================" << '\n';
            itr->second = y;
            Deposited = true;
        }
        else
        {
            std::cout << "Insufficient funds ! please enter a positive number" << '\n';
        }
    }
    else
    {
        std::cout << "The account is not found , or not created ." << '\n';

        std::cout << "(You can create a new account by pressing  4) " << '\n';
    }
}





void display_accounts(std::unordered_map<std::string, int> &mpp)
{

    for (const auto &[ID, initialamount] : mpp)
    { // modern way to loop on a map
        std::cout << "ID account number" << '\t' << "       Balance" << '\n';
        std::cout << ID << '\t' << '\t' << '\t' << '\t' << initialamount << '\n';
    }
}




void History(std::string currentID, double amount, std::string type, std::vector<std::string> &M)
{

    if (Deposited)
    {

        std::stringstream ss;
        ss << "ID : " << currentID << " | " << type << " : " << amount << '\n';
        M.push_back(ss.str());
        Deposited = false;
    }
    if (withdrawall)
    {
        std::stringstream sp;
        sp << "ID : " << currentID << "| " << type << " : " << amount << '\n';
        M.push_back(sp.str());
        withdrawall = false;
    }
}



void History_display(const std::vector<std::string> &M)
{ // Passing by reference (&) to avoid copying data for better performance
    for (const auto &selected_value : M)
    { // Modern way to loop and display
        std::cout << selected_value << '\n';
    }
}




void search_by_ID(std::string ID_customer, std::unordered_map<std::string, int> &mpp)
{
    auto itr = mpp.find(ID_customer); // One shot method
    if (itr != mpp.end())
    {
        std::cout << "Customer's current balance is " << itr->second << '\n';
    }
    else
    {
        std::cout << "The account is not found , or not created ." << '\n';

        std::cout << "(You can create a new account by pressing  4) " << '\n';
    }
}





// University Assignment

void inputdetails()
{

    std::cout << "Please enter the principle amount you want to deposit : " << '\n';
    std::cin >> principle;
    std::cout << "What's the bank rate for the account type you chose? " << '\n';
    std::cin >> rate;
}




void yearly_amount(std::map<int, float> &mp)
{

    std::cout << "Year " << " " << " Amount on deposit " << '\n';
    for (int years = 1; years <= 10; years++)
    {
        float amount = principle * pow(1.0 + rate, years);
        mp.insert({years, amount});

        std::cout << years << "              " << amount << '\n';
    }
}





float search_by_year(int year, const std::map<int, float> &mp)
{ // pass by value (Create a new copy of data (slower but  safe for modification))

    std::map<int, float>::const_iterator itr; // classic way to loop on a map , compiler gives erorr when writing (::itreator only) as itreators has the access to edit on map and this is not acceptable when writing const in function's parameter
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
    std::vector<std::string> storing_History;
    std::map<int, float> Storing_years;
    std::unordered_map<std::string, int> Storing_accounts;

    do
    {
        std::cout << "Welcome to mini bank project " << '\n';
        std::cout << "*****************************" << '\n';

        std::cout << "(University Assignment requirements) " << '\n';
        std::cout << "press" << '\n';
        std::cout << "1 to input account details " << '\n';
        std::cout << "2 to display yearly amount for 10 years " << '\n';
        std::cout << "3 to display the amount at a certain speecified year " << '\n';
        std::cout << "------------------------------------------------" << '\n';
        std::cout << "(My extra application on bank system)" << '\n';
        std::cout << "4 add new account to the bank " << '\n';
        std::cout << "5 make a Withdraw process" << '\n';
        std::cout << "6 make a deposit process " << '\n';
        std::cout << "7 Display accounts found in the bank" << '\n';
        std::cout << "8 Display successful Transactions History " << '\n';
        std::cout << "9 Search for an account by customer's ID " << '\n';
        std::cout << "=====================================================" << '\n';
        std::cout << " Enter your choice : " << '\n';
        char no;
        std::cin >> no;
        switch (no)
        {
        case '1':

            inputdetails();
            break;

        case '2':

            yearly_amount(Storing_years);
            break;

        case '3':

            int year;
            std::cout << "Enter the year you want to display the amount reached at : ";
            std::cin >> year;
            std::cout << " Amount :" << search_by_year(year, Storing_years) << '\n';
            break;

        case '4':

            accounts_in_the_bank(Storing_accounts);
            break;

        case '5':
        {
            double value_withdrawal;
            std::cout << "Enter the ID account you want to withdrawal from " << '\n';
            std::cin >> ID;
            std::cout << "Enter the value you want to withdraw : " << '\n';
            std::cin >> value_withdrawal;
            do
            {

                if (value_withdrawal < 0)
                {
                    std::cout << "Invalid value ! Please enter a positive value " << '\n';
                    std::cin >> value_withdrawal;
                    continue;
                }
            } while (value_withdrawal < 0);

            withdrawal(ID, value_withdrawal, Storing_accounts);
            History(ID, value_withdrawal, "Withdrawal", storing_History); // Capture ID and sent it to History() function and capture the withdrawal transaction details into the history vector
            break;
        }

        case '6':
        {
            double deposit;
            std::cout << "Enter ID " << '\n';
            std::cin >> ID;
            std::cout << "Enter the amount you want to deposit " << '\n';
            std::cin >> deposit;
            Deposit(ID, deposit, Storing_accounts);
            History(ID, deposit, "Deposit", storing_History); // Capture ID and sent it to History function and capture the deposit transaction details into the history vector
            break;
        }

        case '7':
            display_accounts(Storing_accounts);
            break;

        case '8':

            History_display(storing_History);
            break;

        case '9':
        {
            std::cout << "Enter customer's ID to search  " << '\n';
            std::string id;
            std::cin >> id;
            search_by_ID(id, Storing_accounts);
            break;
        }
        default:
            std::cout << "Invalid choice ! please re-enter the correct one " << '\n';
            continue;
        }
        std::cout << "******************************" << '\n';
        std::cout << "Another opertion ? (Y/N) : " << '\n';

        std::cin >> ans;

        do
        {
            if (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
            {
                std::cout << "Please enter (Y , y for YES) or (N , n for NO)" << '\n';
                std::cin >> ans;
                continue;
            }
        } while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');

        if (ans == 'y' || ans == 'Y')
        {
            continue;
        }

        if (ans == 'N' || ans == 'n')
        {
            std::cout << "Thank you for using our application" << '\n';
            break;
        }

    } while (ans == 'Y' || ans == 'y');

    return 0;
}
