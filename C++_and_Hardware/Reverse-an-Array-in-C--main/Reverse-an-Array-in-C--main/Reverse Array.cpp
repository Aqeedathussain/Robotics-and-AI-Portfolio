#include<iostream>
using namespace std;
int main()
{
	int arr[5];
	cout << "please enter the values of the array";
	for (int i = 0;i < 5;i++)
	{
		cin >> arr[i];
	}
	int secondarray = arr[0];
	for (int i = 4;i >= 0;i--)
	{
		cout << "the updated array is" << arr[i] << endl;
	}
	return 0;
}