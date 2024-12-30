#include "Course.hpp"

#include <string>
#include <vector>

#include "Professor.hpp"
#include "Student.hpp"

Course::Course(std::string name, Professor* professor)
    : _name(name), _professor(professor), _students(), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0)
{
}

void Course::assign(Professor* professor)
{
    _professor = professor;
}

void Course::subscribe(Student* student)
{
    if (student == nullptr)
    {
        return;
    }
    _students.push_back(student);
}
