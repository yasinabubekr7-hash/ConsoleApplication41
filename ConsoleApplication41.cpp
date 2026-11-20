#include <iostream>
using namespace std;

struct account {
	int number;
	char name[20];
	int pin;
	double balance;
};

account acc[3] = {
	{ 1001, "Abebe", 1234, 5000 },
	{ 1002, "Hana", 2222, 3000 },
	{ 1003, "Dawit", 3333, 4000 }
};

int accIndex = -1;

int number();
void pin();
void deposit();
void wthdraw();

int main()
{
	cout << "welcome to our bank\n";
	if (number() == 0) {
		return 0;
	}
	pin();

	int c = 0;
	do {
		cout << "1,  deposit\n";
		cout << "2, withdraw\n";
		cout << "3,exit\n";
		cout << " enter your choice \n";
		cin >> c;

		switch (c)
		{
		case 1:
			deposit();
			break;
		case 2:
			wthdraw();
			break;
		case 3:
			return 0;
		default:
			cout << " you  entered inavlid choice \n";
		}
	} while (c != 3);

	return 0;
}

int number()
{
	int enteredNum;
	accIndex = -1;

	cout << "enter your account number\n";
	cin >> enteredNum;

	for (int i = 0; i < 3; i++)
	{
		if (acc[i].number == enteredNum)
		{
			accIndex = i;
			return 1;
		}
	}

	cout << "not found\n";
	return 0;
}

void pin()
{
	int temp2;
	int tries = 0;

	while (tries < 3)
	{
		cout << "enter your pin\n";
		cin >> temp2;

		if (temp2 == acc[accIndex].pin)
		{
			cout << "login successfully\n";
			return;
		}

		tries++;
		cout << "wrong pin\n";
	}

	cout << "too many wrong attempts\n";
	exit(0);
}

void deposit()
{
	double x;
	cout << "enter you balance to deposit\n";
	cin >> x;

	if (x <= 0)
	{
		cout << "invalid amount\n";
		return;
	}

	acc[accIndex].balance += x;
	cout << "your balance is " << acc[accIndex].balance << endl;
}

void wthdraw()
{
	double w;
	cout << "enter you balance to withdraw\n";
	cin >> w;

	if (w <= 0 || w > acc[accIndex].balance)
	{
		cout << "invalid amount or not enough balance\n";
		return;
	}

	acc[accIndex].balance -= w;
	cout << "your balance is " << acc[accIndex].balance << endl;
}

