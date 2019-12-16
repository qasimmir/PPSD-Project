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

		cout << endl << "If you want to continue with another activity than press C:";
		cin >> repeat;

	} while (repeat == 'C' || repeat == 'c');

	return 0;
}

