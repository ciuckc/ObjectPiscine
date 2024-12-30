#pragma once

#include <string>
#include <vector>

class Professor;
class Student;

class Course
{
public:
    explicit Course(std::string name, Professor* professor);

    void assign(Professor* professor);
    void subscribe(Student* student);

private:
    std::string _name;
    Professor* _professor;
    std::vector<Student*> _students;
    int _numberOfClassToGraduate;
    int _maximumNumberOfStudent;
};
