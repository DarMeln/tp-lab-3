#include <iostream>
#include <string>
#include "DateTime.h"

using namespace std;

int main(){
	DateTime date1(15, 10, 2004);
	cout << "making a date: " << date1.getToday() << '\n';
	DateTime date2;
	cout << "today's date: " << date2.getToday() << '\n';
	cout << "yesterday's date: " << date2.getYesterday() << '\n';
	cout << "8 days in the future: " << date2.getFuture(8) << '\n';
    cout << "difference from now and made date: " << date2.getDifference(date1);
	DateTime test1(31,10,2018);
	cout << '\n' << test1.getTomorrow();
	DateTime test2(1,11,2018);
	cout << '\n' << test2.getTomorrow();
}
