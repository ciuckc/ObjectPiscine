#pragma once

#include <vector>

#include "Classroom.hpp"
#include "Course.hpp"
#include "IPerson.hpp"

class Student : public IPerson
{
public:
    Student(std::string name, ISchoolSpace* currentSpace);

    ~Student() override;

    void attendClass(Classroom* p_classroom);
    void exitClass();
    void graduate(Course* p_course);
    std::string getName() const override;
    ISchoolSpace* getSchoolSpace() const override;

private:
    ISchoolSpace* _currentSpace;
    std::vector<Course*> _subscribedCourse;
};
