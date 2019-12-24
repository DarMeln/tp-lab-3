#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include <string>
#include <math.h>
#include "DateTime.h"

using namespace std;

string getMonth(int m){
	string month;
	switch(m){
        case 0: {month = "january"; break;}
		case 1: {month = "february"; break;}
		case 2: {month = "march"; break;}
		case 3: {month = "april"; break;}
		case 4: {month = "may"; break;}
		case 5: {month = "june"; break;}
		case 6: {month = "july"; break;}
		case 7: {month = "august"; break;}
		case 8: {month = "september"; break;}
		case 9: {month = "october"; break;}
		case 10: {month = "november"; break;}
		case 11: {month = "december"; break;}
	}
	return month;
}

string getDay(int d){
	string w;
	switch (d){
	case 0: {w = "sunday"; break;}
	case 1: {w = "monday"; break;}
	case 2: {w = "tusday"; break;}
	case 3: {w = "wedensday"; break;}
	case 4: {w = "thursday"; break;}
	case 5: {w = "friday"; break;}
	case 6: {w = "saturday"; break;}
	}
	return w;
}

DateTime::DateTime(unsigned int day, unsigned int month, unsigned int year){
    this->date = new tm[sizeof(tm)];
	this->date->tm_mday = day;
	this->date->tm_mon = month;
	this->date->tm_year = year;
}

DateTime::DateTime(){
	time_t t;
	time(&t);
	this->date = localtime(&t);
	this->date->tm_year += 1900;
}

DateTime::DateTime(tm &date){
	*(this->date) = date;
}

string DateTime::getToday(){
	string month = getMonth(this->date->tm_mon);
	string w = getDay(this->date->tm_wday);
	string date = to_string(this->date->tm_mday) + ' ' + month + ' ' + to_string(this->date->tm_year) + ", " + w;
	return date;
}

string DateTime::getYesterday(){
    this->date->tm_mday--;
    mktime(this->date);
    string month = getMonth(this->date->tm_mon);
	string w = getDay(this->date->tm_wday);
	string date = to_string(this->date->tm_mday) + ' ' + month + ' ' + to_string(this->date->tm_year) + ", " + w;
	this->date->tm_mday++;
	return date;
}

string DateTime::getTomorrow(){
    this->date->tm_mday++;
    mktime(this->date);
    string month = getMonth(this->date->tm_mon);
	string w = getDay(this->date->tm_wday);
	string date = to_string(this->date->tm_mday) + ' ' + month + ' ' + to_string(this->date->tm_year) + ", " + w;
	this->date->tm_mday--;
	return date;
}

string DateTime::getFuture(unsigned int N){
    this->date->tm_mday += N;
    mktime(this->date);
    string month = getMonth(this->date->tm_mon);
	string w = getDay(this->date->tm_wday);
	string date = to_string(this->date->tm_mday) + ' ' + month + ' ' + to_string(this->date->tm_year) + ", " + w;
	this->date->tm_mday -= N;
    mktime(this->date);
	return date;
}

string DateTime::getPast(unsigned int N){
    this->date->tm_mday -= N;
    mktime(this->date);
    string month = getMonth(this->date->tm_mon);
	string w = getDay(this->date->tm_wday);
	string date = to_string(this->date->tm_mday) + ' ' + month + ' ' + to_string(this->date->tm_year) + ", " + w;
	this->date->tm_mday += N;
    mktime(this->date);
	return date;
}

int DateTime::getDifference(DateTime& d){
    time_t t1 = mktime(this->date), t2 = mktime(d.date);
    return abs((int)round(difftime(t2, t1) / (3600 * 24)));
}
