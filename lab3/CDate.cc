// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
	setDate(year, month, day);
}

bool CDate::isValidDate(int year, int month, int day){
	// TODO you need to fill in the code here        ********
	// comment out the "return false" below 
	// then check the validity of a year, month, and day
	if (isValidDay(year, month, day) && (month >= 1) && (month <= 12 ) && year>=0) {
		return true;
	}

	return false; //When date is not valid, return false
}

bool CDate::isValidDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// comment out "return false" below
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
	int numMonth = monthStr2Num(month);
	return isValidDate(year, numMonth, day);
}

int CDate::monthStr2Num(std::string month){
	// TODO you need to fill in the code here        ********
	int num = 0;
	if (month.compare("January")==0) {
		num = 1;
	}
	else if (month.compare("February")==0) {
		num = 2;
	}
	else if (month.compare("March")==0) {
		num = 3;
	}
	else if (month.compare("April")==0) {
		num = 4;
	}
	else if (month.compare("May")==0) {
		num = 5;
	}
	else if (month.compare("June")==0) {
		num = 6;
	}
	else if (month.compare("July")==0) {
		num = 7;
	}
	else if (month.compare("August")==0) {
		num = 8;
	}
	else if (month.compare("September")==0) {
		num = 9;
	}
	else if (month.compare("October")==0) {
		num = 10;
	}
	else if (month.compare("November")==0) {
		num = 11;
	}
	else if (month.compare("December")==0) {
		num = 12;
	}
	return num;
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;

	bool valid = false;
	switch (month) {
		case 1: 
			if ((day >= 1) && (day <= 31)) {
				valid = true;
			}
			break;
		case 3: 
			if ((day >= 1) && (day <= 31)) {
				valid = true;
			}
			break;
		case 5: 
			if ((day >= 1) && (day <= 31)) {
				valid = true;
			}
			break;
		case 7: 
			if ((day >= 1) && (day <= 31)) {
				valid = true;
			}
			break;
		case 8: 
			if ((day >= 1) && (day <= 31)) {
				valid = true;
			}
			break;
		case 10: 
			if ((day >= 1) && (day <= 31)) {
				valid = true;
			}
			break;
		case 12: 
			if ((day >= 1) && (day <= 31)) {
				valid = true;
			}
			break;
			// TODO you need to fill in the code here        ********
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4: 
			if ((day >= 1) && (day <= 30)) {
				valid = true;
			}
			break;
		case 6: 
			if ((day >= 1) && (day <= 30)) {
				valid = true;
			}
			break;
		case 9: 
			if ((day >= 1) && (day <= 30)) {
				valid = true;
			}
			break;
		case 11: 
			if ((day >= 1) && (day <= 30)) {
				valid = true;
			}
			break;
			// TODO you need to fill in the code here        ********
		default: valid=false;
			// TODO you need to fill in the code here        ********
			break; 
	}
	return valid;
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
	int numMonth = monthStr2Num(month);
	setDate(year, numMonth, day);
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}

