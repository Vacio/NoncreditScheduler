#include "noncredit.h"
#include <string>
#include <fstream>
#include <iostream>
#include "constants.h"
#include <sstream>

using namespace std;

noncredit::noncredit()
{
	//variables
	subject_ = "\0";
	course_ = "\0";
	section_number_ = "\0";
	days_ = "\0";
	name_last_ = "\0";
	name_first_ = "\0";
	building_ = "\0";
	room_ = "\0";
	startTimeString_ = "\0";
	endTimeString_ = "\0";
	startTime_[6] = { '\0' };
	endTime_[6] = { '\0' };
	startDate = "\0";
	endDate = "\0";
	space_count_ = 0;
	name_bool_ = true;
	evening_ = false;
	next_ = '\0';
	status_ = OPEN;
}

void open_ifstream_isd(ifstream& name)
{
	//name.open("classes.rtf");
	name.open("classes.txt");
	if (name.fail())
	{
		cout << "Failed to connect to file [0.0100]\n";
		//Perhaps the file is not in the same folder as the program";
		system("PAUSE");
		exit(1);
	}
	return;
}
void open_ofstream_isd(ofstream& name, string fileName)
{
	name.open(fileName);
	if (name.fail())
	{
		cout << "Failed to connect to file: " << fileName;
		cout << endl << endl;
		system("PAUSE");
		exit(1);
	}
	return;
}

void noncredit::course_converter(const string& course)
{
	if (course == "040")
	{
		cout << "Level 1 ";
		course_ = "Level 1 ";
	}
	else if (course == "041")
	{
		cout << "Level 2 ";
		course_ = "Level 2 ";
	}
	else if (course == "042")
	{
		cout << "Level 3 ";
		course_ = "Level 3 ";
	}
	else if (course == "043")
	{
		cout << "Level 4 ";
		course_ = "Level 4 ";
	}
	else if (course == "044")
	{
		cout << "Conversation ";
		course_ = "Conversation ";
	}
	else if (course == "045")
	{
		cout << "Workplace ";
		course_ = "Workplace ";
	}
	else if (course == "003")
	{
		cout << "Writing Essays ";
		course_ = "Writing Essays ";
	}
	else if (course == "003")
	{
		cout << "Writing Essays ";
		course_ = "Writing Essays ";
	}
	else if (course == "003")
	{
		cout << "Writing Essays ";
		course_ = "Writing Essays ";
	}
	else if (course == "012")
	{
		cout << "Fractions ";
		course_ = "Fractions ";
	}
	else if (course == "014")
	{
		cout << "Ratio, Proportions, & Percentages ";
		course_ = "Ratio, Proportions, & Percentages ";
	}
	else
	{
		cout << "The course is not recongnized\n";
		course_ = "The course is not recongnized\n";
	}
	return;
}
bool noncredit::startTimeConverter(const char time[])
{
	int hours = 0, minutes = 0;
	bool evening = false;
	//This loop extracts the characters values an stores the numeric values 
	//in the apporopiate variables
	for (int i = 0; i < TIME_CHARACTERS; i++)
	{
		switch (i)
		{
		case 0:
			//startTimeString_ = time[i];
			hours += (time[i] - ASCII_INTEGER_CONVERTER) * 10;
			break;
		case 1:
			//startTimeString_ += time[i];
			hours += (time[i] - ASCII_INTEGER_CONVERTER);
			break;
		case 2:
			//startTimeString_ += ":";
			break;
		case 3:
			//startTimeString_ += time[i];
			minutes += (time[i] - ASCII_INTEGER_CONVERTER) * 10;
			break;
		case 4:
			//startTimeString_ += time[i];
			minutes += (time[i] - ASCII_INTEGER_CONVERTER);
			break;
		default:
			cout << "ERROR";
			break;
		}//switch
	}//for

	if (hours>11)//works since we don't have any 12am classes
	{//sets the pm status
		pm_ = true;
	}
	if (hours >= EVENING_HOURS)
	{//sets to evening after EVENING_HOURS
		evening = true;
	}
	if (hours>12)
	{//minus 12 for the 12 hour notation
		hours -= 12;
	}

	////store data to object
	//startTimeString_ = static_cast<ostringstream*>(&(ostringstream() << hours))->str();
	//startTimeString_ += ":";
	//startTimeString_ += static_cast<ostringstream*>(&(ostringstream() << minutes))->str();
	ostringstream temp;
	//temp.flags(right);
		//std::ios::right | std::ios::hex | std::ios::showbase
	temp << hours;

	startTimeString_ = temp.str();


	//display of content
	if (pm_)
	{
		cout << hours << ":" << minutes << "pm";
		startTimeString_ += "PM";
	}
	else
	{
		cout << hours << ":" << minutes << "am";
		startTimeString_ += "AM";
	}

	return evening;
}
bool noncredit::endTimeConverter(const char time[])
{
	int hours = 0, minutes = 0;
	bool pm = false, evening = false;
	for (int i = 0; i < TIME_CHARACTERS; i++)
	{//This loop extracts the characters values an stores the numeric values in the apporopiate variables
		switch (i)
		{
		case 0:
			hours += (time[i] - ASCII_INTEGER_CONVERTER) * 10;
			break;
		case 1:
			hours += (time[i] - ASCII_INTEGER_CONVERTER);
			break;
		case 2:
			break;
		case 3:
			minutes += (time[i] - ASCII_INTEGER_CONVERTER) * 10;
			break;
		case 4:
			minutes += (time[i] - ASCII_INTEGER_CONVERTER);
			break;
		default:
			cout << "ERROR";
			break;
		}//switch
	}//for

	if (hours>11)//works since we don't have any 12am classes
	{//sets the pm status
		pm = true;
	}
	if (hours >= EVENING_HOURS)
	{//sets to evening after EVENING_HOURS
		evening = true;
	}
	if (hours>12)
	{//minus 12 for the 12 hour notation
		hours -= 12;
	}
	
	//store data to object
	endTimeString_ = static_cast<ostringstream*>(&(ostringstream() << hours))->str();
	endTimeString_ += ":";
	endTimeString_ += static_cast<ostringstream*>(&(ostringstream() << minutes))->str();

	//display of content
	if (pm)
	{
		cout << hours << ":" << minutes << "pm";
		endTimeString_ += "PM";
	}
	else
	{
		cout << hours << ":" << minutes << "am";
		endTimeString_ += "AM";
	}

	return evening;
}
void noncredit::displaySession(int month_start, int month_end, int session2)
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
	else if (month_end - month_start < 2 && month_start != session2)//look over
	{
		cout << "1st Session ";
	}
	else
	{
		cout << "ERROR: Pe-Pen... Ahh";
	}

	return;
}
void noncredit::daysFinder(string& days, ifstream& fin)
{
	char ch1, ch2, ch3;

	fin.get(ch1);

	if (ch1 == 'F')
	{
		days = "F";
		days_ = days;
		return;
	}

	fin.get(ch2);
	fin.get(ch3);

	if (ch1 == 'M' && ch2 == 'T' && ch3 == 'W')
	{
		days = "MTWTh";
	}
	else if (ch1 == 'M' && ch2 == ' ' && ch3 == 'W')
	{
		days = "M W";
	}
	else if (ch1 == 'T' && ch2 == ' ' && ch3 == 'R')
	{
		days = "T Th";
	}
	else
	{
		days = "ERROR:(days)";
	}
	days_ = days;
	return;
}
void noncredit::bring_it(ifstream& fin, const int &session2)
{
	//variables
	string subject = "\0", course = "\0", section_number = "\0", days = "\0";
	string name_last = "\0", name_first = "\0", building = "\0", room = "\0", status = "\0";
	string startTimeString = "\0", endTimeString = "\0";
	char startTime[6] = { '\0' }, endTime[6] = { '\0' };
	int space_count = 0;
	bool name_bool = true;
	char next = '\0';
	int month_start, month_end;

	while (next != '\n' && !fin.eof())
	{
		fin.get(next);

		if (next == ' ')//count the number of spaces in the line
		{
			space_count++;
		}

		switch (space_count)
		{
		case 0:  //ACAD PR  or  ESL NC
			while (next != ' ')
			{
				subject += next;
				fin.get(next);
			}
			subject_ = subject;
			space_count++;
			break;
		case 2:  //course number  and  1st digit of section number
			for (int i = 0; i < 3; i++)
			{
				fin.get(next);
				course += next;
			}
			fin.get(next);
			while (next < CHAR0 || next > CHAR9)
			{
				fin.get(next);
			}
			section_number += next;// This stores the 1st digit of the section number to section_number.
			//here I will call the function that converts this into the stuff that I want
			course_converter(course);
			space_count = 9;
			break;
		case 9:  //last 3 digits of section number
			for (int i = 0; i < 2; i++)
			{
				section_number += next;
				fin.get(next);
			}
			section_number += next;
			cout << section_number << " ";
			section_number_ = section_number;
			break;
		case 10: //startTime
			while (next < CHAR0 || next > CHAR9)
			{
				fin.get(next);
			}
			startTime[0] += next;
			for (int j = 1; j < 5; j++)
			{
				fin.get(next);
				startTime[j] = next;
			}
			evening_ = startTimeConverter(startTime);
			cout << "--";
			break;
		case 11: //endTime
			for (int j = 0; j < 5; j++)
			{
				fin.get(next);
				endTime[j] = next;
			}
			endTimeConverter(endTime);
			//NOTE: I am adding a space here, so get rid of this crap later, brofavor
			//#######################################################################
			cout << " ";
			break;
		case 12: //days that the class meets
			daysFinder(days, fin);
			cout << days << " ";
			//fin.putback(next);//figure out why this does not work
			space_count = 13;
			break;
		case 14: //professor name_last
			while (next != ' ')
			{
				name_last += next;
				fin.get(next);
				if (next == ' ')
				{
					space_count++;
				}
			}
			cout << name_last << " ";
			name_last_ = name_last;
			break;
		case 15: //professor name_first
			if (name_bool)
			{
				name_first += next;
				name_bool = false;
				cout << name_first << " ";
				name_first_ = name_first;
				break;
			}
			else
			{
				name_first_ = name_first;
				break;
			}
		case 16: //building
			fin.get(next);
			while (next != ' ')
			{
				building += next;
				fin.get(next);
				if (next == ' ' && days != "")
				{
					space_count++;
				}
			}
			building_ = building;
			if (building == "SGEC")
			{
				cout << "SG-";
				building_ = "SG-";
			}
			else
			{
				building_ += "-";
				cout << building << "-";//I think this is the same reason why there is an extra space somewhere in the previous cases.
			}
			break;
		case 17: //room
			while (next != ' ')
			{
				room += next;
				fin.get(next);
				if (next == ' ')
				{
					space_count++;
				}
			}
			cout << room << " ";
			room_ = room;
			break;
		case 20: //status
			fin.get(next);
			while (next != ' ')
			{
				status += next;
				fin.get(next);
				if (next == ' ')
				{
					space_count++;
				}
			}
			cout << status << " ";
			if (status == "OPEN")
			{
				status_ = OPEN;
			}
			else if (status == "CLOSE")
			{
				status_ = CLOSE;
			}
			else if (status == "CANCELED")
			{
				status_ = CANCELED;
			}
			else
			{
				status_ = ERROR_STATUS;
				cout << "ERROR, status_ has been set to ERROR\n";
			}
			break;
		case 25: //start date  and  semester
			fin.get(next);
			startDate_ = next;
			month_start = (next - ASCII_INTEGER_CONVERTER) * 10;
			fin.get(next);
			startDate_ += next;
			month_start += next - ASCII_INTEGER_CONVERTER;
			cout << month_start;

			switch (month_start)
			{
			case 1:
				semester_ = WINTER;
				break;
			case 2:
			case 3:
			case 4:
				semester_ = SPRING;
				break;
			case 6:
				semester_ = SUMMER;
				break;
			case 8:
			case 9:
			case 10:
				semester_ = FALL;
				break;
			default:
				semester_ = ERROR_SEMESTER;
				break;
			}

			for (int i = 0; i < 6; i++)
			{
				fin.get(next);
				cout << next;
				startDate_ += next;
			}
			startDate_ += '-';
			cout << "--";
			break;
		case 26: //end date  and  session
			fin.get(next);
			endDate_ = next;
			month_end = (next - ASCII_INTEGER_CONVERTER) * 10;
			fin.get(next);
			endDate_ += next;
			month_end += next - ASCII_INTEGER_CONVERTER;
			cout << month_end;

			if (semester_ == WINTER || semester_ == SUMMER) //only have full sessions in winter and summer
			{
				session_ = FULL;
			}
			else if (month_end == 4 || month_end == 3 //spring 1st session
				|| month_end == 10 || month_end == 9) //fall 1st session
			{
				session_ = FIRST;
			}
			else if (month_start == 4 || month_start == 3 //spring 2nd session 
				|| month_start == 10 || month_start == 11) //fall 2nd session
			{
				session_ = SECOND;
			}
			else
			{
				session_ = FULL;
			}

			for (int i = 0; i < 6; i++)
			{
				fin.get(next);
				cout << next;
				endDate_ += next;
			}
			displaySession(month_start, month_end, session2);
			break;
		case 1:		case 3:		case 4:		case 5:		case 6:
		case 7:		case 8:		case 13:	case 18:	case 19:
		case 21:	case 22:	case 23:	case 24:	case 27:
			break;
		default:
			cout << "There has been some ERROR in the switch (space_count)\n";
			break;
		}//switch (space_count)
	}//while (next != '\n')

	if (evening_)
	{
		cout << "\tEvening class";
	}

	cout << endl;

	return;
}

void noncredit::outputToFile(std::ofstream& fout)
{
	fout << "\n";
	fout << section_number_;
	fout << "\t";
	fout << startTimeString_;
	fout << " - ";
	fout << endTimeString_;
	fout << "\t";
	fout << days_;
	fout << "\t";
	fout << name_last_;
	fout << " ";
	fout << name_first_;
	fout << "\t";
	fout << building_;
	//fout << "-";
	fout << room_;
}



