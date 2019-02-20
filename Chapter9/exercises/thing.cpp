#include "../stdlibfacilities.h"

int main()
{	
	string year = "1987";
	int lastTwoDigitsYear = stoi(to_string(year[year.size() - 2] + year[year.size() - 1]));
	cout << lastTwoDigitsYear << endl;

	int lastTwoDigitsYearTwo = year[year.size() - 2] + year[year.size() - 1];
	cout << lastTwoDigitsYearTwo << endl;

	int lastTwoDigitsYearThree = stoi(to_string(year[year.size() - 2]) + to_string(year[year.size() - 1]));
	cout << lastTwoDigitsYearThree << endl;

	string lastTwoDigitsYearFour;
	lastTwoDigitsYearFour.push_back(year[year.size() - 2]);
	lastTwoDigitsYearFour.push_back(year[year.size() - 1]);
	cout << stoi(lastTwoDigitsYearFour) << endl;
}
 