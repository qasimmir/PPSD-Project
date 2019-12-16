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

	void load_file()
	{
		fstream file;
		file.open("C:\\Users\\Qasim Mir\\Desktop\\data.txt");
		if (file.is_open())
		{
			file >> input;
			while (!file.eof())
			{
				for (int i = 0; i < 2; i++)
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
//This functions saves the file in .txt file
    	void save_to_file()
	{
		fstream file;
		file.open("C:\\Users\\Qasim Mir\\Desktop\\data.txt", ios::out | ios::trunc);

		if (file.is_open())
		{
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					file << arr[i][j] << endl;
				}
				file << endl;
			}
			cout << "Data sent to file.." << endl << endl;

		}
		else
			cout << "File is not able to open";

		file.close();
	}

	void cash_withdrawal();
	void cash_deposit();
	void check_balance();
	void change_pin();

};

int main()
{
	ATM obj;
	char option, repeat;


	do {
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

