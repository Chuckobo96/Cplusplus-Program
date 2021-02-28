//============================================================================
// Name        : Clock.cpp
// Author      : Charlie Obonaga
// Date        : 1/23/2021
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Clock24; //declares class Clock24
enum AMPM //declares enum, tracks AM or PM in 12 hour clock
{
	AM , PM
}ampm;

class Time //declares class Time
{
public:
	int hour; //declares hour as integer
	int minute; //declares minute as integer
	int second; //declares second as integer
	virtual void addOneHour() = 0; //overrides addOneHour
	virtual void addOneMinute() = 0; //overrides addOneMinute
	virtual void addOneSecond() = 0; //overrides addOneSecond
};

class Clock12 : public Time //Clock12 class inherits Time class
{
public:
	Clock12(int h , int m , int s) { //declares method Clock12, uses integer
		hour = h;
		minute = m;
		second = s;
		ampm = AM;
}
void addOneHour() //does not return addOneHour
{
	if(hour == 11){ //if hour is not 11
		hour = 0;
		ampm = ampm == AM ? PM : AM; //checks whether to put AM or PM
		}
	else {
		hour += 1; //increases hour by 1
		}
}
void addOneMinute() //does not return addOneMinute
{
	if(minute == 59){ //if minute is not 59
		minute = 0;
		addOneHour();
		}
	else {
		minute += 1; //increases minute by 1
		}
}
void addOneSecond() //does not return addOneSecond
{
	if(second == 59){ //if second is not 59
		second = 0;
		addOneMinute();
		}
	else{
		second += 1; //increases second by 1
		}
}
friend void displayTime(const Clock12& ,const Clock24&); //declares friend void displayTime, sets both classes as constant
};

class Clock24 : public Time //Clock24 class inherits Time class
{
public:
	Clock24(int h , int m , int s) { //declares method Clock24, uses integer
		hour = h;
		minute = m;
		second = s;
}
void addOneHour() //does not return addOneHour
{
	if(hour == 23){ //if hour is not 23
		hour = 0;
		}
	else{
		hour += 1; //hour increases by 1
		}
}
void addOneMinute() //does not return addOneMinute
{
	if(minute == 59){ //if minute is not 59
		minute = 0;
		addOneHour();
		}
	else {
		minute += 1; //minute increases by 1
		}
}
void addOneSecond() //does not return addOneSecond
{
	if(second == 59){ //if second is not 59
		second = 0;
		addOneMinute();
		}
	else{
		second += 1; //second increases by 1
		}
}
friend void displayTime(const Clock12& ,const Clock24&); //declares friend void displayTime, sets both classes as constant
};
void displayTime(const Clock12& time12 ,const Clock24& time24)
{
cout << "*************************** ***************************\n";
cout << "* 12-Hour Clock * * 24-Hour Clock *\n";
cout << "* ";
	if(time12.hour < 10) {
		cout << "0"; cout << time12.hour << ":";
	}
	if(time12.minute < 10 ) {
		cout << "0" ; cout << time12.minute << ":";
	}
	if(time12.second < 10) {
		cout << "0"; cout << time12.second;
	}
	if(ampm == AM ) {
		cout << " AM";
	}
	else {
		cout << " PM";
	}
		cout << " * * ";
	if(time24.hour < 10) {
		cout << "0"; cout << time24.hour << ":";
	}
	if(time24.minute < 10 ) {
		cout << "0" ;
		cout << time24.minute << ":";
	}
	if(time24.second < 10) {
		cout << "0" ;
		cout << time24.second;
	}
		cout << " *\n";
		cout << "*************************** ***************************\n";
}

int main() {
	Clock12 time_12_Clock(11, 59, 59);
	Clock24 time_24_Clock(23, 59, 59);
	displayTime(time_12_Clock, time_24_Clock);
	while(true) {
		cout << "***************************\n";
		cout << "* 1 - Add One Hour *\n";
		cout << "* 2 - Add One Minute *\n";
		cout << "* 3 - Add One Second *\n";
		cout << "* 4 - Exit Program *\n";
		cout << "***************************\n";
	int choice;
		cin >> choice;
	switch (choice) {
	case 1:
		time_12_Clock.addOneHour();
		time_24_Clock.addOneHour();
		displayTime(time_12_Clock , time_24_Clock);
		break;
	case 2:
		time_12_Clock.addOneMinute();
		time_24_Clock.addOneMinute();
		displayTime(time_12_Clock , time_24_Clock);
		break;
	case 3:
		time_12_Clock.addOneSecond();
		time_24_Clock.addOneSecond();
		displayTime(time_12_Clock , time_24_Clock);
		break;
	case 4:
		cout << "Thank You!";
		exit(1);
		break;
	default:
		cout << "Error! Invalid choice! Please try again.\n";
		break;
	return 0;
	}
}
}
