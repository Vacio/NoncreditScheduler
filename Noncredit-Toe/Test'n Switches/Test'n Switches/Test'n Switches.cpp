// Test'n Switches.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

int main()
{
	int count = 0;

	while (count < 4)
	{
		switch (count)
		{
		case 0:
			cout << count << endl;
			count++;
			break;
		case 1:
			cout << count << endl;
			count++;
		default:
			count++;
			break;
		}
	}

	cout << endl;
	system("PAUSE");
	return 0;
}