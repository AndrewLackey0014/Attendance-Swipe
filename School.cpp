#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "School.h"
#include "AttendanceRecord.h"

using std::stoi, std::string, std::ostream, std::ifstream, std::istringstream, std::endl, std::cout;

// one method is provided to students; students implement all other methods
void School::addStudents(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::invalid_argument("addStudents: can't open file");
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
    if (!ss.fail()) {
        Student student(uin, name);
        bool exists = false;
        for (Student s : students) {
            if (s == student) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            students.push_back(student);
        }
    }
  }
}

void School::addCourses(std::string filename){
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::invalid_argument("addCourses: can't open file");
  }
  while (!ifs.eof()){
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string id;
    getline(ss, id, ',');
    string startHr;
    getline(ss, startHr, ':');
    string startMin;
    getline(ss, startMin, ',');
    string endHr;
    getline(ss, endHr, ':');
    string endMin;
    getline(ss, endMin, ',');
    string title;
    getline(ss, title);
    if (!ss.fail()) {
      Date startTime(stoi(startHr), stoi(startMin), 0);
      Date endTime(stoi(endHr), stoi(endMin), 0);
      Course course(id, title, startTime, endTime);
      courses.push_back(course);
    }
  }
}
bool School::isEnrolled(std::string student_id) const{
  return true;
}
unsigned int School::addAttendanceData(std::string filename){
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::invalid_argument("addAttendanceData: can't open file");
  }
  while (!ifs.eof()){
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string year;
    getline(ss, year, "-");
    string month;
    getline(ss, month, "-");
    string day;
    getline(ss, day, " ");
    string hour;
    getline(ss, hour, ":");
    string min;
    getline(ss, min, ":");
    string sec;
    getline(ss, sec, ",");
    string course_id;
    getline(ss, course_id, ",");
    string student_id;
    getline(ss, student_id);
  }
}
void School::listCourses(std::ostream& os) const{
  if (courses.size() == 0){
    os << "No Courses\n";
  }else{
    for (int i = 0; i < courses.size(); ++i){
      os << courses.at(i);
    }
  }
}
void School::listStudents(std::ostream& os) const{
  if(students.size() == 0){
    os << "No students\n";
  }else {
    for (int i = 0; i < students.size(); ++i){
      os << students.at(i);
    }
  }
}
void School::outputCourseAttendance(std::ostream& os, std::string course_id) const{

}
void School::outputStudentAttendance(std::ostream& os, std::string student_id, 
  							   std::string course_id) const{

}