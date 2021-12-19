// Robert Schenck
// Lab 9
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Fine multipliers and months of the year as global constants
const double INTERSTATE = 5.2252;
const double HIGHWAY = 9.4412;
const double RESIDENTIAL = 17.1525;
const double OTHER = 12.152;
const string MONTHS[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

// Date structure that contains variables for the year, month, and day
struct Date{
	int month;
	int day;
	int year;
};

// Ticket structure that contains variables for the citation number, date, clocked speed, speed limit of the road, and the type of road
// driving on.
struct Ticket{
	string citationNumber;
	Date citationDate;
	int clockedSpeed;
	int speedLimit;
	char typeOfRoad;
};

// Database class that contains an add_ticket mutator that adds a given ticket to the private ticket vector.
// A public accessor gen_report that returns a vector of ticket object that are within the given dates.
class Database{
	public:
		void add_ticket(const Ticket &ticket);
		vector<Ticket> gen_report(Date start, Date end);
	private:		
		vector<Ticket> tickets;
};

// Function prototypes
bool Read(Database &d, istream &in);
bool Write(const vector<Ticket> &tickets, ostream &out);
int Encode(const Date &d);



int main(int argc, char * argv[]){
	// Variable declaration
	ofstream ofs;
	ifstream ifs;
	Date start;
	Date end;
	Database d;
	stringstream ss;
	char dash;

	// If argc count is less than or greater than 5 returns 1 and tells user proper way to run the program
	if(argc < 5 || argc > 5){
		cout << "Usage: ./lab9 <input file> <start: year-month-day> <end: year-month-day> <output or '-'>" << '\n';
		return 1;
	}

	// assigns the argv's given to variables
	string startDate = argv[2];
	string endDate = argv[3];
	string inputFile = argv[1];
	string outputFile = argv[4];

	// Attempts to open the file, if it fails the program is exited and an error message is displayed
	// If the attempt is successful the program call the Read function which reads the tickets from the input file into a ticket vector
	ifs.open(inputFile);
	if(!ifs.is_open()){
		cerr << "The file '" << argv[1] << "' cannot be read.\n";
		return 1;
	}else{
		Read(d, ifs);
		ifs.close();
	}

	// Fills the start and end date objects with the given arguments from main
	ss << startDate;
	ss >> start.year >> dash >> start.month >> dash >> start.day;
	ss.clear();
	ss << endDate;
	ss >> end.year >> dash >> end.month >> dash >> end.day;
	ss.clear();

	// Determines if the user wants to output to a file or console, if they decide a file then attempts to open file, if it fails to open file then the program is exited
	// If it succeeds then the Write function is called and writes the output to the given file
	if(outputFile[0] == '-'){
		Write(d.gen_report(start, end), cout);
	}else{
		ofs.open(outputFile);
		if(ofs.is_open()){
			Write(d.gen_report(start, end), ofs);
			ofs.close();
		}
	}
	return 0;
}

// Generates the report given to the Write function that excludes tickets that are not in the given time period
vector<Ticket> Database::gen_report(Date start, Date end){
	vector<Ticket> returnTicket;
	int startEncoded = Encode(start);
	int endEncoded = Encode(end);
	int currentTicketEncoded;
	// For the amount of tickets from the input file
	for(unsigned int i = 0; i < tickets.size(); i++){
		currentTicketEncoded = Encode(tickets.at(i).citationDate);
		// If in range then add to vector of tickets
		if(currentTicketEncoded >= startEncoded && currentTicketEncoded <= endEncoded){
			returnTicket.push_back(tickets.at(i));
		}
	}
	// Returns the vector to be used by the Write function
	return returnTicket;
}

// Adds a ticket from the input file to the private vector of tickets from the Database class
void Database::add_ticket(const Ticket &ticket){
	tickets.push_back(ticket);
}

// Reads the input file and calls the add_ticket mutator to add the tickets from the file to the private vector tickets from the Database class
bool Read(Database &d, istream &in){


	Ticket t;
	// While they're still tickets to be input
	while(in >> t.citationNumber >> t.citationDate.month >> t.citationDate.day >> t.citationDate.year >> t.clockedSpeed >> t.speedLimit >> t.typeOfRoad){
		if(t.citationDate.year < 100){
			t.citationDate.year += 2000;
		}
		d.add_ticket(t);
	}
	return true;
}

// Writes to the output file or console
bool Write(const vector<Ticket> &tickets, ostream &out){
	double fine;
	// For the amount of tickets in the ticket vector
	for(unsigned int i = 0; i < tickets.size(); i++){
		// Determines the multiplier that needs to be used based on the information on the ticket
		switch(tickets.at(i).typeOfRoad){
			case 'I':
			case 'i':
				fine = (tickets.at(i).clockedSpeed - tickets.at(i).speedLimit) * INTERSTATE;
				break;
			case 'H':
			case 'h':
				fine = (tickets.at(i).clockedSpeed - tickets.at(i).speedLimit) * HIGHWAY;
				break;
			case 'R':
			case 'r':
				fine = (tickets.at(i).clockedSpeed - tickets.at(i).speedLimit) * RESIDENTIAL;
				break;
			case 'P':
			case 'p':
				fine = (tickets.at(i).clockedSpeed - tickets.at(i).speedLimit) * OTHER;
				break;
			default:
				fine = (tickets.at(i).clockedSpeed - tickets.at(i).speedLimit) * OTHER;
		}
		// If the fine is calculated to be less than 0, then set the fine to 0
		if(fine < 0){
			fine = 0;
		}
		// Outputs the date of the ticket, the citation number, and the fine amount to the output file or console
		out << setw(2) << setfill('0') << tickets.at(i).citationDate.day << '-' << MONTHS[tickets.at(i).citationDate.month - 1] << '-' << tickets.at(i).citationDate.year << " " << 
			tickets.at(i).citationNumber << right << setfill(' ') << setw(4) << '$' << right << setw(9) << fixed << setprecision(2) << fine << '\n';	
	}
	return 1;
}

// Encodes and returns the date given so that it can be compared easier
int Encode(const Date &d){
	int dateEncoded;
	dateEncoded = (d.year * 10000) + (d.month * 100) + d.day;

	return dateEncoded;
}
