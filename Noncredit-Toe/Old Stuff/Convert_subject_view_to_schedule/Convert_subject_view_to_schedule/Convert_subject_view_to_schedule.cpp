//Kevin Serrano
//Convert_subject_view_to_schedule
//June 11, 2014
//This program will allow the user to convert text from a file that uses the subject view text to format a text file that will be 
//much more useful for creating the schedules.

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

void open_ifstream(ifstream& name);
void open_ofstream(ofstream& name);



void openingIn() //will create a static fstream for reading text
{
	fstream file;

	file.open("ELAC-Power.rtf", ios_base::in);

	if (file.is_open())
	{
		file.close();
		cout << "file: ELAC-Power.rtf has been opened\n";
		static fstream fin;
		fin.open("ELAC-Power.rtf", ios_base::in);
	}
	else
	{
		cout << "File not found" << endl;
		system("Pause");
		exit(-1);
	}
}

void course (string& course)
{
	if (course == "- Noncredit040CE")
	{
		cout << "Level 1 ";
	}
	else if (course == "- Noncredit041CE")
	{
		cout << "Level 2 ";
	}
	else if (course == "- Noncredit042CE")
	{
		cout << "Level 3 ";
	}
	else if (course == "- Noncredit043CE")
	{
		cout << "Level 4 ";
	}
	else if (course == "- Noncredit044CE")
	{
		cout << "Conversation ";
	} 
	else if (course == "- Noncredit045CE")
	{
		cout << "Workplace ";
	}
	else if (course == "- Noncredit046CE")
	{
		cout << "Writing ";
	}
	else
	{
		cout << "The course is not recongnized\n";
	}
	return ;
}

void fx (ifstream& fin, ofstream& fout, string& course)
{
	string info = "\0";
	char next = 'a';
	int line_count=0, dash_count=0, tab_count=0;
	while (fin)
	{
		if (next == '\n')
		{
			cout << endl;//this is for the console astetics
			dash_count=0, tab_count=0;//does this work???
		}
		if (next == '-')
		{
			dash_count++;
		}
		if (next == '\t')
		{
			tab_count++;
		}
		if (dash_count == 1)
		{
			course = course + next;
		}
		if (dash_count == 2)
		{
			cout << course << endl;
			course = "\0";
		}
		if (dash_count == 0 && tab_count > 0)
		{
		//	cout << next;
		}
	

		fin.get(next);	
	}
	
	

	return ;
}

int main ()
{
	string course = "Kraq", info = "# T-T D P B-R";
	char next = 'a';

	ifstream fin;
	ofstream fout;

	open_ifstream (fin);
	open_ofstream (fout);

	fx (fin, fout, course);
	
	//getline(fin, course);

	//cout << course;

	system ("PAUSE");
	return 0;
}


//connects to the file 
//####### May want to change the cout statement.
void open_ifstream (ifstream& name)
{
	//name.open("C:\\Users\\Mufasa\\Desktop\\ENGLISH_AS_A_SECOND_LANGUAGE.rtf");
	
	name.open("classes.rtf");
	
	if (name.fail())
	{
		cout << "Failed to connect to file [middle finger]\n";//Perhaps the file is not in the same folder as the program";
		system ("PAUSE");
		exit(1);
	}
	return ;
}

//creates the file that will have the changes
void open_ofstream (ofstream& name)
{
	//name.open("C:\\Users\\Mufasa\\Desktop\\ENGLISH_AS_A_SECOND_LANGUAGE_aww_yeah_baby.rtf");
	
	name.open("I_Remmember_When_You_Came_Love_is_So_Far_Away.rtf");
	if (name.fail())
	{
		cout << "Failed to connect to file & this program probaly did not create the file for you\n";
		system ("PAUSE");
		exit(1);
	}
	return;
}
