//Robert Schenck
//Lab 6
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	
	// Variable Declaration/Initialization
	const double INTERSTATE = 5.2252;
	const double HIGHWAY = 9.4412;
	const double RESIDENTIAL = 17.1525;
	const double OTHER = 12.152;
	const string MONTHS[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	string inputFile, outputFile, outputLine;
	int startDay, startMonth, startYear, startDateCombined;
	int endDay, endMonth, endYear, endDateCombined;
	int day, month, year, dateCombined;
	int clockedSpeed, speedLimit;
	char typeOfRoad;
	double fine;
	string citationNumber;
	ostringstream output;
	ofstream ofs;
	ifstream ifs;

	// Takes the name of the file and opens it
	cout << "Enter a ticket file: ";
	cin >> inputFile;
	ifs.open(inputFile);
	if(!ifs.is_open()){
		cerr << "Unable to open " << inputFile << ".\n";
		return 1;
	}
	// Enter the name of the file to output to, start date, and end date
	cout << "Enter a report file: ";
	cin >> outputFile;
	ofs.open(outputFile);
	cout << "Enter report start date (mm dd yyyy): ";
	cin >> startMonth >> startDay >> startYear;
	cout << "Enter report end date	(mm dd yyyy): ";
	cin >> endMonth >> endDay >> endYear;
	// Loops through each line of the file
	while(ifs >> citationNumber >> month >> day >> year >> clockedSpeed >> speedLimit >> typeOfRoad){
		// Adds the dates together to determine whether or not they are in range
		startDateCombined = (startYear * 10000) + (startMonth * 100) + startDay;
		endDateCombined = (endYear * 10000) + (endMonth * 100) + endDay;
		if(year < 100){
			dateCombined = ((year + 2000) * 10000) + (month * 100) + day;
		}else{
			dateCombined = (year * 10000) + (month * 100) + day;
		}
		// If date is in range, does calculations for fine, else continues and starts at the top of the loop
		if(startDateCombined <= dateCombined && dateCombined <= endDateCombined){
			// Determines which type of fine
			switch(typeOfRoad){
				case 'i':
					fine = (clockedSpeed - speedLimit) * INTERSTATE;
					break;
				case 'h':
					fine = (clockedSpeed - speedLimit) * HIGHWAY;
					break;
				case 'r':
					fine = (clockedSpeed - speedLimit) * RESIDENTIAL;
					break;
				case 'p':
					fine = (clockedSpeed - speedLimit) * OTHER;
					break;
				default:
					fine = (clockedSpeed - speedLimit) * OTHER;
			}
			// Determines if Year is 2 digits in case 21st century needs to be assumed.
			if(year < 100){
				output << setw(2) << setfill('0') << day << '-' << MONTHS[month - 1] << '-' << "20" << year << " " << citationNumber << right << setfill(' ') << setw(6) << '$' << right << setw(9) << 
					fixed << setprecision(2) << fine << '\n';	
			}else{
				output << setw(2) << setfill('0') << day << '-' << MONTHS[month - 1] << '-' << year << " " << citationNumber << right << setfill(' ') <<  setw(6) << '$' << right << setw(9) <<
					fixed << setprecision(2) << fine << '\n';
			}
			// Converts output to a string and outputs it to a file, empties the output stream
			outputLine = output.str();
			if(!ofs.is_open()){
				cerr << "Unable to open " << outputFile << ".\n";
				return 1;
			}
			ofs << outputLine;
			output.str("");
			output.clear();
			outputLine = output.str();

		}else{
			continue;
		}
	}
	// Closes files and returns 0
	ifs.close();
	ofs.close();
	return 0;
}
