//Kevin Serrano
//Convert_subject_view_to_schedule
//June 11, 2014  --  July 07, 2014
//This program will allow the user to convert text from a file that uses the "course listing - daily updated" text to format a text file that will be much more useful for creating the schedules.
//*July 07, 2014 Update: this program will only accept text form a "normal highlight".
//*Dec 30, 2014 Rapo: Trouble with the time algoithm
//*Mar 10, 2015 Update: Needs a way to store the noncredit class's data for convenient retreival.
//*Aug 06, 2015 Upadte: Back in action

#include <iostream>
#include <fstream>
#include <string>
//#include <cctype>
//#include <cstdlib>
#include "constants.h"
#include "noncredit.h"
#include <vector>
#include <unordered_set>

using namespace std;

vector<ofstream> coursesOutputFiles(vector<noncredit> an87)
{
	vector<ofstream> fout;
	unordered_set<string> courses;

	for (int i = 0; i < an87.size(); i++)
	{
		courses.emplace(an87[i].course_);
	}
	cout << endl << endl << courses.size() << endl << endl;



	return fout;
}

////This is where I start outputing all the data.
void outputingData(vector<noncredit> an87, vector<ofstream> fout)
{
	// 00 acad Canceled
	// 01 esl  Canceled
	// 02 acad 1st
	// 03 acad 1st  Evening
	// 04 acad 2nd
	// 05 acad 2nd  Evening
	// 06 acad Full
	// 07 acad Full Evening
	// 08 esl  1st 
	// 09 esl  1st  Evening
	// 10 esl  2nd 
	// 11 esl  2nd  Evening
	// 12 esl  Full
	// 13 esl  Full Evening 

	//go to the open.fout[] stuff and hard code each course header 
	//so that if will be ready for this function.

	for (int i = 0; i < an87.size(); i++)
	{
		//++++++++ Canceled Courses ++++++++
		if (an87[i].status_ == CANCELED
			&& an87[i].subject_ == "ACAD")
		{
			an87[i].outputToFile(fout[0]);
		}
		else if (an87[i].status_ == CANCELED
			&& an87[i].subject_ == "ESL")
		{
			an87[i].outputToFile(fout[1]);
		}
		//++++++++ ACAD ++++++++
		else if (an87[i].status_ != ERROR_STATUS
			&& an87[i].subject_ == "ACAD"
			&& an87[i].session_ == FIRST
			&& an87[i].evening_ == false)
		{
			an87[i].outputToFile(fout[2]);
		}
		else if (an87[i].status_ != ERROR_STATUS
			&& an87[i].subject_ == "ACAD"
			&& an87[i].session_ == FIRST
			&& an87[i].evening_ == true)
		{
			an87[i].outputToFile(fout[3]);
		}
		else if (an87[i].status_ != ERROR_STATUS
			&& an87[i].subject_ == "ACAD"
			&& an87[i].session_ == SECOND
			&& an87[i].evening_ == false)
		{
			an87[i].outputToFile(fout[4]);
		}
		else if (an87[i].status_ != ERROR_STATUS
			&& an87[i].subject_ == "ACAD"
			&& an87[i].session_ == SECOND
			&& an87[i].evening_ == true)
		{
			an87[i].outputToFile(fout[5]);
		}
		else if (an87[i].status_ != ERROR_STATUS
			&& an87[i].subject_ == "ACAD"
			&& an87[i].session_ == FULL
			&& an87[i].evening_ == false)
		{
			an87[i].outputToFile(fout[6]);
		}
		else if (an87[i].status_ != ERROR_STATUS
			&& an87[i].subject_ == "ACAD"
			&& an87[i].session_ == FULL
			&& an87[i].evening_ == true)
		{
			an87[i].outputToFile(fout[7]);
		}
		//++++++++ ESL ++++++++
		else if (an87[i].status_ != ERROR_STATUS//1st
			&& an87[i].subject_ == "ESL"
			&& an87[i].session_ == FIRST
			&& an87[i].evening_ == false)
		{
			an87[i].outputToFile(fout[8]);
		}
		else if (an87[i].status_ != ERROR_STATUS//1stE
			&& an87[i].subject_ == "ESL"
			&& an87[i].session_ == FIRST
			&& an87[i].evening_ == true)
		{
			an87[i].outputToFile(fout[9]);
		}
		else if (an87[i].status_ != ERROR_STATUS//2nd
			&& an87[i].subject_ == "ESL"
			&& an87[i].session_ == SECOND
			&& an87[i].evening_ == false)
		{
			an87[i].outputToFile(fout[10] );
		}
		else if (an87[i].status_ != ERROR_STATUS//2ndE
			&& an87[i].subject_ == "ESL"
			&& an87[i].session_ == SECOND
			&& an87[i].evening_ == true)
		{
			an87[i].outputToFile(fout[11]);
		}
		else if (an87[i].status_ != ERROR_STATUS//Full
			&& an87[i].subject_ == "ESL"
			&& an87[i].session_ == FULL
			&& an87[i].evening_ == false)
		{
			an87[i].outputToFile(fout[12]);
		}
		else if (an87[i].status_ != ERROR_STATUS//FullE
			&& an87[i].subject_ == "ESL"
			&& an87[i].session_ == FULL
			&& an87[i].evening_ == true)
		{
			an87[i].outputToFile(fout[13]);
		}
		//++++++++ ERROR checking ++++++++
		else
		{
			cout << "There has been an ERROR with file output\n\n";
		}
	} 
}


int main()
{
	vector<noncredit>an87;
	vector<ofstream> fout;
	int index = 0;
	int session2 = 0;
	ifstream fin;
	//ofstream fout[NUM_OF_OUTPUT_FILES];
				// 00 acad Canceled
				// 01 esl  Canceled
				// 02 acad 1st
				// 03 acad 1st  Evening
				// 04 acad 2nd
				// 05 acad 2nd  Evening
				// 06 acad Full
				// 07 acad Full Evening
				// 08 esl  1st 
				// 09 esl  1st  Evening
				// 10 esl  2nd 
				// 11 esl  2nd  Evening
				// 12 esl  Full
				// 13 esl  Full Evening 

	open_ifstream_isd(fin);
	
	//for (int i = 0; i < 10; i++)
	//{
	//	string fileName = "fout-0";
	//	fileName += (i + '0');
	//	fileName += ".txt";
	//	open_ofstream_isd(fout[i], fileName);
	//}
	//open_ofstream_isd(fout[10], "fout-10.txt");
	//open_ofstream_isd(fout[11], "fout-11.txt");
	//open_ofstream_isd(fout[12], "fout-12.txt");
	//open_ofstream_isd(fout[13], "fout-13.txt");
	
	//extracting all data from the text files
	while (!fin.eof())
	{
		an87.push_back(noncredit());
		an87[index++].bring_it(fin, session2);
		cout << endl;
		////---vs.---
		//an87.push_back(noncredit());
		//an87[index].bring_it(fin, session2);
		//cout << endl;
		//index++;
	}

	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	cout << endl;

	fout = coursesOutputFiles(an87);

//	outputingData(an87, fout);

	fin.close();

	//for (int i = 0; i < 12; i++)
	//{
	//	fout[i].close();
	//}

	system("PAUSE");
	return 0;
}//end of main









