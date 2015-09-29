//Kevin Serrano
//Convert_subject_view_to_schedule
//June 11, 2014  --  July 01, 2014
//This program will allow the user to convert text from a file that uses the "course listing - daily updated" text to format a text file that will be much more useful for creating the schedules.

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

void open_ofstream_isd(ofstream& name);
void open_ifstream_isd(ifstream& name);
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


void get_info(ifstream& fin)
{
	string row = "\0";
	string subject, course_number, section_number, professor, start_date, end_date, start_time, end_time, days, lecture, building, room, course_type, status, weeks;
	char next = '\0';
	int line_count = 0;
	
	getline(fin, subject);	
	while (line_count < 22)
	{
		switch (line_count)
		{
			case 2:
			case 4:
			case 5:
			case 6:
			case 19:
			case 20:
			case 21:
				getline(fin, row);
				break;
			case 0:
				if (subject != "BASIC SKILLS")// || subject != "ESL")
				{
					course_number = subject;
					line_count++;
					cout << course_number;
				}
				else if (subject != "ESL")
				{
					course_number = subject;
					line_count++;
					cout << course_number;
				}
				else
				{
					cout << subject; 
				}
				break;
			case 1:
				getline(fin, course_number);
				cout << course_number;
				break;
			case 3:
				getline(fin, section_number);
				cout << section_number;
				break;
			case 7:
				getline(fin, professor);		
				cout << professor;
				break;
			case 8:
				getline(fin, start_date);
				cout << start_date;
				break;
			case 9:
				getline(fin, end_date);
				cout << end_date;
				break;
			case 10:
				getline(fin, start_time);
				cout << start_time;
				break;
			case 11:
				getline(fin, end_time);
				cout << end_time;
				break;
			case 12:
				getline(fin, days);
				cout << days;
				break;
			case 13:
				getline(fin, lecture);
				cout << lecture;
				break;
			case 14:
				getline(fin, building);
				cout << building;
				break;
			case 15:
				getline(fin, room);
				cout << room;
				break;
			case 16:
				getline(fin, course_type);
				cout << course_type;
				break;
			case 17:
				getline(fin, status);
				cout << status;
				break;
			case 18:
				getline(fin, weeks);
				cout << weeks;
				break;
			default:
				cout << "There is some kind of a ERROR. {check the 0-21 switch}\n";
				break;
		}
		line_count++;
		cout << endl;
	}//while (line_count < 22)
	
	return ;
}



int main ()
{
	string course = "Kraq", info = "# T-T D P B-R";
	char next = 'a';

	ifstream fin;
	ofstream fout;

	open_ifstream_isd (fin);
	open_ofstream_isd (fout);

	while (fin)
	{
		get_info(fin);
	}


	system ("PAUSE");
	return 0;
}


//connects to the file //####### May want to change the cout statement.
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

//connects to the file in the same directory
void open_ifstream_isd (ifstream& name)
{
	name.open("classes.rtf");
	if (name.fail())
	{
		cout << "Failed to connect to file [middle finger]\n";//Perhaps the file is not in the same folder as the program";
		system ("PAUSE");
		exit(1);
	}
	return ;
}

//Connects to the file in the same directory
void open_ofstream_isd(ofstream& name)
{
	name.open("Nicely_formatted_text.txt");
	if (name.fail())
	{
		cout << "Failed to connect to file [middle finger]\n Perhaps the file is not in the same folder as the program";
		system ("PAUSE");
		exit(1);
	}
	return ;
}