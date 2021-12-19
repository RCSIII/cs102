#include <iostream>

using namespace std;

int main(){

	int startDateYear, startDateMonth, startDateDay, startDateCombined;
	int endDateYear, endDateMonth, endDateDay, endDateCombined;
	int dateYear, dateMonth, dateDay, dateCombined;

	cout << "Enter start date: ";
	cin >> startDateYear >> startDateMonth >> startDateDay;
	cout << "Enter end date  : ";
	cin >> endDateYear >> endDateMonth >> startDateDay;
	cout << "Enter date      : ";
	cin >> dateYear >> dateMonth >> dateDay;

	startDateCombined = (startDateYear * 10000) + (startDateMonth * 100) + startDateDay;
	endDateCombined = (endDateYear * 10000) + (endDateMonth * 100) + startDateDay;
	dateCombined = (dateYear * 10000) + (dateMonth * 100) + dateDay;

	if(startDateCombined <= dateCombined <= endDateCombined){
		cout << "IN RANGE\n";
	}else{
		cout << "OUT OF RANGE\n";
	}
}
