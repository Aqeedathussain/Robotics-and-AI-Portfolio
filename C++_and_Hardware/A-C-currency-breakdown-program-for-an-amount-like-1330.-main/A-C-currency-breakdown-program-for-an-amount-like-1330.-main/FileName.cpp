#include<iostream>
using namespace std;
int main()
{
	int total = 1330;
	int remaining=total;
	switch (100)
	{
	case 100:cout << "The notes of 100 are" << remaining / 100 << endl;
		remaining %= 100;
	case 50:cout << "The notes of 50 are" << remaining / 50 << endl;
		remaining %= 50;
	case 3:cout << "The notes of 20 are" << remaining / 20 << endl;
		remaining %= 20;
	case 1:cout << "The notes of 1 are" << remaining / 1 << endl;
	default:cout << "You have got your payment" << endl;
	}
}