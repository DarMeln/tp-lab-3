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
        case 0: {month = "december"; break;}
		case 1: {month = "january"; break;}
		case 2: {month = "february"; break;}
		case 3: {month = "march"; break;}
		case 4: {month = "april"; break;}
		case 5: {month = "may"; break;}
		case 6: {month = "june"; break;}
		case 7: {month = "july"; break;}
		case 8: {month = "august"; break;}
		case 9: {month = "september"; break;}
		case 10: {month = "october"; break;}
		case 11: {month = "november"; break;}
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
    time(&this->now);
    this->date = localtime(&this->now);
    this->date->tm_year = year - 1900;
    this->date->tm_mon = month - 1;
    this->date->tm_mday = day;
    this->now = mktime(this->date);
    this->date = localtime(&this->now);
}

DateTime::DateTime(){
	time_t t;
	time(&t);
	this->date = localtime(&t);
	this->now = t;
	this->date->tm_year;
}

DateTime::DateTime(tm &date, time_t &now){
	*(this->date) = date;
	this->now = now;
}

string DateTime::getToday(){
	string month = getMonth(this->date->tm_mon);
	string w = getDay(this->date->tm_wday);
	string date = to_string(this->date->tm_mday) + ' ' + month + ' ' + to_string(this->date->tm_year+=1900) + ", " + w;
	return date;
}

string DateTime::getYesterday(){
    time_t tmp = this->now - 24 * 3600;
    tm* curr = localtime(&tmp);
    string month = getMonth(curr->tm_mon);
	string w = getDay(curr->tm_wday);
	string date = to_string(curr->tm_mday) + ' ' + month + ' ' + to_string(curr->tm_year+=1900) + ", " + w;
	return date;
}

string DateTime::getTomorrow(){
    time_t tmp = this->now + 24 * 3600;
    tm* curr = localtime(&tmp);
    string month = getMonth(curr->tm_mon);
	string w = getDay(curr->tm_wday);
	string date = to_string(curr->tm_mday) + ' ' + month + ' ' + to_string(curr->tm_year+=1900) + ", " + w;
	return date;
}

string DateTime::getFuture(unsigned int N){
    time_t tmp = this->now + N * 24 * 3600;
    tm* curr = localtime(&tmp);
    string month = getMonth(curr->tm_mon);
	string w = getDay(curr->tm_wday);
	string date = to_string(curr->tm_mday) + ' ' + month + ' ' + to_string(curr->tm_year+=1900) + ", " + w;
	return date;
}

string DateTime::getPast(unsigned int N){
    time_t tmp = this->now - N * 24 * 3600;
    tm* curr = localtime(&tmp);
    string month = getMonth(curr->tm_mon);
	string w = getDay(curr->tm_wday);
	string date = to_string(curr->tm_mday) + ' ' + month + ' ' + to_string(curr->tm_year+=1900) + ", " + w;
	return date;
}

int DateTime::getDifference(DateTime& d){
    time_t t1 = mktime(this->date), t2 = mktime(d.date);
    return abs((int)round(difftime(t2, t1) / (3600 * 24)));
}
