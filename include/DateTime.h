#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

class DateTime{
public:
	DateTime(unsigned int day, unsigned int month, unsigned int year);
	DateTime();
	DateTime(tm &date, time_t &now);
	string getToday();
	string getYesterday();
	string getTomorrow();
	string getFuture(unsigned int N);
	string getPast(unsigned int N);
	int getDifference(DateTime& d);
private:
    time_t now;
	tm * date;
};
