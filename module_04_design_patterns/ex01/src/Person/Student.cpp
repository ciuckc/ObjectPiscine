#include "Student.hpp"

#include "Classroom.hpp"
#include "Course.hpp"
#include "ISchoolSpace.hpp"

Student::Student(std::string name, ISchoolSpace* currentSpace)
    : _name(name), _subscribedCourse(), _currentSpace(currentSpace)
{
}

void Student::attendClass(Classroom* classroom)
{
    classroom->enter(this);
}

void Student::exitClass()
{
    _currentSpace->exit(this);
}

void Student::graduate(Course* course)
{
    (void)course;
}

std::string Student::getName() const
{
    return _name;
}

ISchoolSpace* Student::getSchoolSpace() const
{
    return _currentSpace;
}
