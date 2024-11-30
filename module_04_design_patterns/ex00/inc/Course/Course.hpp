#pragma once

#include <string>
#include <vector>

#include "Professor.hpp"
#include "Student.hpp"

class Course
{
public:
    explicit Course(std::string name, Professor* professor);

    void Assign(Professor* professor);
    void Subscribe(Student* student);

private:
    std::string _name;
    Professor* _professor;
    std::vector<Student*> _students;
    int _numberOfClassToGraduate;
    int _maximumNumberOfStudent;
};
