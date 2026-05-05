#include <iostream>
using namespace std;
int main()
{
	int arr[10];
	for (int i = 0;i < 10;i++)
	{
		arr[i] = 5;
	}
	for (int i = 0;i < 10;i++)
	{
		cout << "the updated array is" << arr[i] << endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	int num = 2;
	char ch = 'a';
	cout << endl;
	switch (num)
	{
	case 1:
		cout << "First" << endl;
		break;
	case 'a':switch (num)
	{
	case 1:cout << "Second" <<num<< endl;
		break;
	}
			break;
	default:
		cout << "Out of the Switch Statement" << endl;
		
	}
	return 0;
}