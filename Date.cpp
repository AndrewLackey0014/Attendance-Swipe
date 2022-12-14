#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include "Date.h"

using std::string, std::stringstream, std::setw,  std::setfill;

// TODO: implement the two constructors
Date::Date(int year, int month, int day, int hour, int min, int sec){
  this-> year = year;
  this-> month = month;
  this-> day = day;
  this-> hour = hour;
  this-> min = min;
  this-> sec = sec;

}
Date::Date(int hour, int min, int sec){
  this-> year = -1;
  this-> month = -1;
  this-> day = -1;
  this-> hour = hour;
  this-> min = min;
  this-> sec = sec;
}
// TODO: implement the < comparison operator
bool Date::operator<(const Date& rhs) const {
  if (rhs.year < year){
    return false;
  }
  else if (rhs.month < month && rhs.year == year){
    return false;
  }
  else if (rhs.day < day && rhs.year == year && rhs.month == month){
    return false;
  }
  else if (rhs.year == year && rhs.month == month && rhs.day == day && rhs.hour < hour){
    return false;
  }
  else if (rhs.year == year && rhs.month == month && rhs.day == day && rhs.hour == hour && rhs.min < min){
    return false;
  }
  else if (rhs.year == year && rhs.month == month && rhs.day == day && rhs.hour == hour && rhs.min == min && rhs.sec < sec){
    return false;
  }else{
    return true;
  }
}

// methods below are provided to students

string Date::getDateTime() const {
  stringstream ss;
  ss << month << "/" << day << "/" << year << " ";
  ss << setw(2) << setfill('0') << hour << ":"; 
  ss << setw(2) << setfill('0') << min << ":";
  ss << setw(2) << setfill('0') << sec;
  return ss.str();
}

string Date::getDate() const {
  stringstream ss;
  ss << month << "/" << day << "/" << year;
  return ss.str();
}

string Date::getTime(bool withSeconds) const {
  stringstream ss;
  ss << setw(2) << setfill('0') << hour << ":"; 
  ss << setw(2) << setfill('0') << min;
  if (withSeconds)
    ss << ":" << setw(2) << setfill('0') << sec;
  return ss.str();
}



bool Date::operator>(const Date& rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date& rhs) const {
    return !(*this > rhs);
}

bool Date::operator>=(const Date& rhs) const {
    return !(*this < rhs);
}

bool leap_year(unsigned int year) {
  /* From wikipedia: year which is a multiple of 4 (except for years evenly divisible by 100, 
   * which are not leap years unless evenly divisible by 400).
   */
  if (year % 400 == 0 
      || (year % 4 == 0 && year % 100 != 0)) {
    return true;
  }
  return false;
}

bool Date::isValid() const {
  if (day == 0 || month == 0) {
    return false;
  }
  if (month > 12) {
    return false;
  }
  unsigned int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31,
                                    31, 30, 31, 30, 31};
  if (leap_year(year)) {
    days_in_month[2] = 29;
  } 

  if (day > days_in_month[month]) {
    return false;
  }
  return true;
}