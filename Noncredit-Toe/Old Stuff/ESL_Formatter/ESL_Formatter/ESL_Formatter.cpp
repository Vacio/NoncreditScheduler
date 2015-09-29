//Kevin Serrano
//Convert_subject_view_to_schedule
//June 11, 2014  --  July 07, 2014
//This program will allow the user to convert text from a file that uses the "course listing - daily updated" text to format a text file that will be much more useful for creating the schedules.
//*Update July 07, 2014: this program will only accept text form a "normal highlight".


#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

void open_ofstream_isd(ofstream& name);
void open_ifstream_isd(ifstream& name);
void course_converter(string& course);
void bring_it(ifstream& fin, int session2);
bool get_time (char time[]);
void dates(int month_start, int month_end, int session2);


int main()
{
	int session2 = 0;
	ifstream fin;
	ofstream fout;

	open_ifstream_isd(fin);
	open_ofstream_isd(fout);

	cout << "The second session begins in which month? \nPlease enter 1-12 or 0 if there is no second session: ";
	cin >> session2; cout << endl;
	bring_it(fin, session2);

	cout << endl;//do not forget to close the files.
	system("PAUSE");
	return 0;
}//end of main

//connects to the file in the same directory
void open_ifstream_isd(ifstream& name)
{
	name.open("paste_text_here.txt");
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

//converts the course number to a string
void course_converter (string& course)
{
	if (course == "040")
	{
		cout << "Level 1 ";
	}
	else if (course == "041")
	{
		cout << "Level 2 ";
	}
	else if (course == "042")
	{
		cout << "Level 3 ";
	}
	else if (course == "043")
	{
		cout << "Level 4 ";
	}
	else if (course == "044")
	{
		cout << "Conversation ";
	} 
	else if (course == "045")
	{
		cout << "Workplace ";
	}
	else if (course == "046")
	{
		cout << "Writing ";
	}
	else
	{
		cout << "The course is not recongnized\n";
	}
	return ;
}

//collects the information from the text file
void bring_it(ifstream& fin, int session2)
{
	string course = "\0", section_number = "\0", days = "\0", name_last = "\0", name_first = "\0", building = "\0", room = "\0", status = "\0";
	char time_start[6] = {'\0'}, time_end[6] = {'\0'};
	//string subject, course_number, section_number, professor, start_date, end_date, start_time, end_time, days, lecture, building, room, course_type, status, weeks;
	int space_count = 0;
	bool name_bool = true, evening;
	char next = '\0';
	int month_start, month_end;

	while (next != '\n')
	{
		fin.get(next);
		
		//count the number of spaces in the line
		if (next == ' ')
		{
			space_count++;
			//cout << space_count << endl;//for debugging
			//fin.get(next);//rewrite the code with this line so that I do not have to program the rest of the code with so many
			//condiditon for the gettting somthing to store in the variables.  This will make it so that I will start each case with 
			//some text rather than a space.
		}

		switch (space_count)
		{
		case 2://if (space_count == 2)//@2spaces: saves the course number to course
			for (int i = 0; i < 3; i++)
			{
				fin.get(next);
				course+=next;
			}
			//here I will call the function that converts this into the stuff that I want
			course_converter(course);
			break;
		case 9://saves the section number to section_number
			for (int i = 0; i < 4; i++)
			{
				fin.get(next);
				section_number+=next;
			}
			cout << section_number << " ";
			break;
		case 11://time_start
			for (int j = 0; j < 5; j++)
			{
				fin.get(next);
				time_start[j]=next;
			}
			evening = get_time(time_start);
			cout << "--";
			break;
		case 12://time_end
			for (int j = 0; j < 5; j++)
			{
				fin.get(next);
				time_end[j]=next;
			}
			get_time(time_end);
			//cout << endl << endl << endl << time_end;//NOTE: I do not need to fout a space here since days will is couting a space.
			break;
		case 13://days that the class meets
			while (next != ' ')
			{
				if (next == 'R')
				{
					next = '\0';
					days+="Th";
				}
				days+=next;
				fin.get(next);
			}
			cout << days << " ";
			//fin.putback(next);//figure out why this does not work
			if (next == ' ' && days != "")//this is probably the most efficient way to program this part. compare to the if in case 14.
			{
				space_count++;
			}
			break;
		case 14://professor name_last//left off here
			while (next != ' ')
			{
				name_last+=next;
				fin.get(next);
				if (next == ' ')
				{
					space_count++;
				}
			}
			cout << name_last << " ";
			break;
		case 15://professor name_first
			if (name_bool)
			{
				name_first+=next;
				name_bool = false;
				cout << name_first << " ";
				break;
			}
			else
			{
				break;
			}
		case 16://building
			fin.get(next);
			while (next != ' ')
			{
				building+=next;
				fin.get(next);
				if (next == ' ' && days != "")
				{
					space_count++;
				}
			}
			if (building == "SGEC")
			{
				cout << "SG-";
			}
			else
			{
			cout << building << "-";//I think this is the same reason why there is an extra space somewhere in the previous cases.
			}
			break;
		case 17://room
			while (next != ' ')
			{
				room+=next;
				fin.get(next);
				if (next == ' ')
				{
					space_count++;
				}
			}
			cout << room << " ";
			break;
		case 20://status
			fin.get(next);
			while (next != ' ')
			{
				status+=next;
				fin.get(next);
				if (next == ' ')
				{
					space_count++;
				}
			}
			cout << status << " ";
			break;
		case 25:
			fin.get(next);
			month_start = (next - 48) * 10;
			fin.get(next);
			month_start += next - 48;
			cout << month_start;
			for (int i = 0; i < 6; i++)
			{
				fin.get(next);
				cout << next;
			}
			cout << "--";
			break;
		case 26:
			fin.get(next);
			month_end = (next - 48) * 10;
			fin.get(next);
			month_end += next - 48;
			cout << month_end;
			for (int i = 0; i < 6; i++)
			{
				fin.get(next);
				cout << next;
			}
			dates(month_start, month_end, session2);
			break;
		case 0:		case 1:		case 3:		case 4:		case 5:		case 6:		case 7:		case 8:		case 10:		case 18:		case 19:		case 21:		case 22:		case 23:		case 24:		case 27:
			break;
		default:
			cout << "There has been some ERROR in the switch (space_count)\n";
			break;
		}//switch (space_count)
	}//while (next != '\n')

	if (evening)
	{
		cout << "\tEvening class";
	}

	cout << endl; 
	return ;
}

//converts char time to int time  &  converts 24hr notation to 12hr notation
bool get_time (char time[])
{
	int hours=0, minutes=0, num;
	bool pm = false, evening = false;
	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
			case 0:
				num = time[i];
				hours +=  (num-48) * 10;
				break;
			case 1:
				num = time[i];
				hours +=  (num-48);
				break;
			case 2:
				break;				
			case 3:
				num = time[i];
				minutes +=  (num-48) * 10;
				break;
			case 4:
				num = time[i];
				minutes +=  (num-48);
				break;
			default:
				cout << "ERROR";
				break;
		}//switch
	}//for
	
	//sets the pm status
	if (hours>11)
	{
		pm = true;
	}
	//sets if evening
	if (hours>15)
	{
		evening = true;
	}
	//minus 12 for the 12 hour notation
	if (hours>12)
	{
		hours-=12;
	}
	//display of content
	if (pm)
	{
		cout << hours << ":" << minutes << "pm";
	}
	else
	{
		cout << hours << ":" << minutes << "am";
	}

//	return hours;
	return evening;
}

//will tell us what session the class is in
void dates(int month_start, int month_end, int session2)
{
	cout << endl << "\t";
	if (month_start == session2)
	{
		cout << "2nd Session ";
	}
	else if (month_end - month_start > 2)
	{
		cout << "16 week Session ";
	}
	else if (month_end - month_start < 2  &&  month_start != session2)//look over
	{
		cout << "1st Session ";
	}
	else
	{
		cout << "ERROR: Pe-Pen... Ahh";
	}

	return ;
}
