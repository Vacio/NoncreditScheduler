//Kevin Serrano
//Co Sci 243
//05-13-2014
//HW13_M  p.366 #09
//This program will

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

int main ()
{
	ifstream fin;
	string jack;
	
	fin.open("test.txt");
	
	getline(fin, jack);
	cout << jack << endl;
	getline(fin, jack);
	cout << jack << endl;
	getline(fin, jack);
	
	cout << jack;
	
	
	
	
	system ("PAUSE");
	return 0;
}


