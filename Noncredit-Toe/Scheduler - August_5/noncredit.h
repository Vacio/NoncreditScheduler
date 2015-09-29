#pragma once

#include <string>
#include <fstream>
#include "constants.h"

void open_ifstream_isd(std::ifstream& name);
void open_ofstream_isd(std::ofstream& name, std::string fileName);

class noncredit
{
public:
	noncredit();
	void daysFinder(std::string& days, std::ifstream& fin);
	void displaySession(int month_start, int month_end, int session2);
	bool startTimeConverter(const char time[]);
	bool endTimeConverter(const char time[]);
	void course_converter(const std::string& course);
	void bring_it(std::ifstream& fin, const int &session2);

	void outputToFile(std::ofstream& fout);

	//variables
	std::string subject_ = "\0", course_ = "\0", section_number_ = "\0", days_ = "\0",
		name_last_ = "\0", name_first_ = "\0", building_ = "\0", room_ = "\0",
		startTimeString_ = "\0", endTimeString_ = "\0", startDate_ = "\0", endDate_ = "\0",
		startDate = "\0", endDate = "\0";
	char next_ = '\0', startTime_[6], endTime_[6];
	int space_count_ = 0;// , month_start_, month_end_;
	bool name_bool_ = true, evening_ = false, pm_ = false;
	Status status_ = OPEN;
	Semester semester_;
	Session session_;
};




