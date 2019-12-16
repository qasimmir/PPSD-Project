#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class ATM
{
private:
    int value, index;
	int amount, convert;
	string  pin,input;
	string arr[2][3];


public:

	void load_file();
	void save_to_file();
	void cash_withdrawal();
	void cash_deposit();
	void check_balance();
	void change_pin();

};
void ATM::load_file()
{

}
void ATM::save_to_file()
{

}
void ATM::cash_withdrawal(string account_no)
{

		for (int i = 0; i < 2; i++)
		{
			int j = 0;
			if (arr[i][j] == account_no)
			{
				j++;
				cout << "Enter your PIN:";
				cin >> pin;

				while (pin != arr[i][j])
				{
					cout << "The Pin you Entered was Wrong." << endl;
					cout << "Press Q to Quit.";
					cout << "Enter Pin again:";
					cin >> pin;
				}
				j++;
				cout << "Enter the amount you want to Withdraw:";
				cin >> amount;

				convert = stoi(arr[i][j]);

				if (convert >= amount)
				{
					amount = convert - amount;
					arr[i][j] = to_string(amount);
				}
				else
				{
					cout << "You have insufficient balance for this withdrawl.";
				}

			}
			else
			{
				cout << "Invalid Account No." << endl;
			}
		}

}
void ATM::cash_deposit(string account_no)
{
    		for (int i = 0; i < 2; i++)
		{
			int j = 0;
			if (arr[i][j] == account_no)
			{
				j++;
				cout << "Enter your PIN:";
				cin >> pin;

				while (pin != arr[i][j])
				{
					cout << "The Pin you Entered was Wrong." << endl;
					cout << "Press Q to Quit.";
					cout << "Enter Pin again:";
					cin >> pin;
				}
				j++;


			}
			else
			{
				cout << "Invalid Account No." << endl;
			}
		}

}
void ATM::check_balance()
{

}

void ATM::change_pin()
{

}
int main()
{
	ATM obj;
	char option, repeat;
    string account_no;

	do{
		cout << "Enter W to Withdraw Cash" << endl;
		cout << "Enter D to deposit Cash" << endl;
		cout << "Enter B to check balance" << endl;
		cout << "Enter P to change your PIN" << endl;
		cout << endl << "Enter Here:";
		cin >> option;
		cout << endl;


		if (option == 'W' || option == 'w')
		{
			cout << "Enter your Account NO.:";
			cin >> account_no;
			obj.cash_withdrawal(account_no);
		}
		if (option == 'D' || option == 'd')
		{
			cout << "Enter your Account NO.:";
			cin >> account_no;
			obj.cash_deposit(account_no);
		}

		if (option == 'B' || option == 'b')
		{
			cout << "Enter your Account NO.:";
			cin >> account_no;
			obj.check_balance(account_no);
		}

		if (option == 'P' || option == 'p')
		{
			cout << "Enter your Account NO.:";
			cin >> account_no;
			obj.change_pin(account_no);
		}

		cout << endl << "If you want to continue with another activity than press C:";

		cin >> repeat;

	} while (repeat == 'C' || repeat == 'c');




	return 0;
}

