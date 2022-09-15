#include <iostream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using std::string, std::ostream, std::endl, std::cout;

std::ostream& operator<<(std::ostream& os, const Course& c){
    os << c.getID() << "," << c.getStartTime().getTime() << "," << c.getEndTime().getTime() << "," << c.getTitle() << "\n";
    return os;
}

Date::Date(){
  year = 0;
  month = 0;
  day = 0;
  hour = 0;
  min = 0;
  sec = 0;
}

Course::Course(std::string id, std::string title, Date startTime, Date endTime){
    this->id = id;
    this->title = title;
    this->startTime = startTime;
    this->endTime = endTime;
}
std::string Course::getID() const{
    return id;
}
std::string Course::getTitle() const{
    return title;
}
Date Course::getStartTime() const{
    return startTime;
}
Date Course::getEndTime() const{
    return endTime;
}
void Course::addAttendanceRecord(AttendanceRecord ar){

}
void Course::outputAttendance(std::ostream& os) const{

}
void Course::outputAttendance(std::ostream& os, std::string student_id) const{

}