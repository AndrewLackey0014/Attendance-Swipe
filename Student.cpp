#include <iostream>
#include <string>
#include "Student.h"

using std::cout, std::endl;

std::ostream& operator<<(std::ostream& os, const Student& s){
    os << s.get_id() << "," << s.get_name() << "\n";
    return os;
}

Student::Student(std::string student_id, std::string name){
    this->id = student_id;
    this->name = name;
}
std::string Student::get_id() const{
    return id;
}
std::string Student::get_name() const{
    return name;
}
void Student::addCourse(std::string course_id){
    bool fail = false;
    for (int i = 0; i < course_ids.size(); ++i){
        if (course_ids.at(i) == course_id){
            fail = true;
            throw std::invalid_argument("Course exists\n");
        }
    }
    if (fail == false){
        course_ids.push_back(course_id);
    }
}
void Student::listCourses(std::ostream& os) const{
    os << "Courses for " << id << "\n";
    if (course_ids.size() == 0){
        os << "No courses\n";
    }else{
        for (int i = 0; i < course_ids.size(); ++i){
            os << course_ids.at(i) << "\n";
        }
    }
}
