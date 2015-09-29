//Kevin Serrano
//Convert_subject_view_to_schedule
//June 11, 2014  --  June 25, 2014
//This program will allow the user to convert text from a file that uses the "course listing - daily updated" text to format a text file that will be much more useful for creating the schedules.

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

void open_ifstream(ifstream& name);
void open_ofstream(ofstream& name);
/*void course (string& course)
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
*/
/*void fx (ifstream& fin, ofstream& fout, string& course)
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
*/


void get_info (ifstream& fin)
{
	string row = "\0";
	string subject, course_number, section_number, professor, start_date, end_date, start_time, end_time, days, lecture, building, room, course_type, status, weeks;
	char next = '\0';
	int line_count = 0;
	
	getline(fin, row);
	if (row == "BASIC SKILLS" || row  == "ESL")//what ever the esl crap is
	{
		line_count = 1;
	}
	else if ()
	{
		
	}
	else if ()//maybe its own condition for tutors
	{
		
	}
	else//everything else that is correct //maybe/maybe not since I actually many want to leave this for the ERROR checking
	{
		line_coutn = 2;
	}
	
	while (line_count < 22)
	{
		switch (line_count):
		{
			case 2:
			case 4:
			case 5:
			case 6:
			case 19:
			case 20:
			case 21:
				break;
			case 0://maynot want to getline on this case since it might be taken care of in the previous if-else conditions.
				//getline(fin, subject);
				break;
			case 1://maynot want to getline on this case since it might be taken care of in the previous if-else conditions.
				//getline(fin, course_number);
				break;
			case 3:
				getline(fin, section_number);
				break;
			case 7:
				getline(fin, professor);		
				break;
			case 8:
				getline(fin, start_date);			
				break;
			case 9:
				getline(fin, end_date);
				break;
			case 10:
				getline(fin, start_time);
				break;
			case 11:
				getline(fin, end_time);
				break;
			case 12:
				getline(fin, days);
				break;
			case 13:
				getline(fin, lecture);
				break;
			case 14:
				getline(fin, building);
				break;
			case 15:
				getline(fin, room);
				break;
			case 16:
				getline(fin, course_type);
				break;
			case 17:
				getline(fin, status);
				break;
			case 18:
				getline(fin, weeks);
				break;
			default:
				cout << "There is some kind of a ERROR. {check the 0-21 switch}\n";
				break;
		}
		line_count++;
	}
	
	
	
	while (fin.get(next))
	{
		if (next != '\n')
		{
			row = row + next;
		}
		else if (next == '\n')
		{
			line_count++;//need a conditition to reset to 01 after I reach 21. //Need a condidtion to reset to 00 after I reach a subject line.
		}
		else if ()
		{
			
		}
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
	name.open("C:\\Users\\Mufasa\\Desktop\\ENGLISH_AS_A_SECOND_LANGUAGE.rtf");
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
	name.open("C:\\Users\\Mufasa\\Desktop\\ENGLISH_AS_A_SECOND_LANGUAGE_aww_yeah_baby.rtf");
	if (name.fail())
	{
		cout << "Failed to connect to file & this program probaly did not create the file for you\n";
		system ("PAUSE");
		exit(1);
	}
	return;
}
