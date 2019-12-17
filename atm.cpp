#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class ATM
{
private:
	int value, index;
	int amount, convert;
	string  pin, input, transfer;
	int T_amount = 0;
	string arr[10][3];

public:

	void load_file()
	{
		fstream file;
		file.open("C:\\Users\\Qasim Mir\\Desktop\\data.txt");
		if (file.is_open())
		{
			file >> input;
			while (!file.eof())
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						arr[i][j] = input;
						file >> input;
					}
				}
			}
		}
		else
			cout << "File is unable to open" << endl << endl;
		file.close();

	}

	void save_to_file()
	{
		fstream file;
		file.open("C:\\Users\\Qasim Mir\\Desktop\\data.txt", ios::out | ios::trunc);

		if (file.is_open())
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					file << arr[i][j] << endl;
				}
				file << endl;
			}
	

		}
		else
			cout << "File is not able to open";

		file.close();
	}

	void display()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << arr[i][j] << endl;
			}
			cout << endl;
		}
	}


	void cash_withdrawal(string account_no)
	{
		for (int i = 0; i < 10; i++)
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
	
			else if (i == 9)
			{
				cout << "Invalid Account No." << endl;
			}
		}
	}

	void cash_deposit(string account_no)
	{
		for (int i = 0; i < 10; i++)
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
				cout << "Enter the amount you want to deposit:";
				cin >> amount;

				convert = stoi(arr[i][j]);
				amount = convert + amount;
				arr[i][j] = to_string(amount);

			}
	
			else if (i == 9)
			{
				cout << "Invalid Account No." << endl;
			}
		}
	}

	void check_balance(string account_no)
	{
		for (int i = 0; i < 10; i++)
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

				cout << "Your available balance is Rs." << arr[i][j] << endl;

			}
	
			else if (i == 9)
			{
				cout << "Invalid Account No." << endl;
			}
		}
	}

	void change_pin(string account_no)
	{
		for (int i = 0; i < 10; i++)
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
				cout << "Enter new PIN:";
				cin >> arr[i][j];
				return;

			}
			else if (i == 9)
			{
				cout << "Invalid Account No." << endl;
			}
		}
	}

	void Transfer_amount(string account_no)
	{
		for (int i = 0; i < 10; i++)
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

				cout << "Enter account number in which you want to transfer:";
				cin >> transfer;

				j++;
				cout << "Enter the amount you want to transfer:";
				cin >> amount;

				convert = stoi(arr[i][j]);

				if (convert >= amount)
				{
					T_amount = amount;
					amount = convert - amount;
					arr[i][j] = to_string(amount);
				}
				else
				{
					cout << "You have insufficient balance for this Transfer.";
					return;
				}

				for (int i = 0; i < 10; i++)
				{
					if (arr[i][0] == transfer)
					{
						convert = stoi(arr[i][2]);
						T_amount = convert + T_amount;
						arr[i][2] = to_string(T_amount);
						return;
					}
				}

			}
			else if (i == 9)
			{
				cout << "Invalid Account No." << endl;
			}
		}
	}
};


int main()
{
	ATM obj;
	char option, repeat;
	string account_no;

	obj.load_file();

	do {
		cout << "Enter W to Withdraw Cash" << endl;
		cout << "Enter D to deposit Cash" << endl;
		cout << "Enter B to check balance" << endl;
		cout << "Enter P to change your PIN" << endl;
		cout << "Enter T to transfer amount to another account" << endl;
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
		if (option == 'T' || option == 't')
		{
			cout << "Enter your Account NO.:";
			cin >> account_no;
			obj.Transfer_amount(account_no);
		}

		obj.save_to_file();

		cout << endl << "If you want to continue with another activity than press C:";
		cin >> repeat;

	} while (repeat == 'C' || repeat == 'c');
}