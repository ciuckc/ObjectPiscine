#pragma once

#include <string>
#include <vector>

#include "IPerson.hpp"

class ISchoolSpace;
class Course;
class Classroom;

class Student : public IPerson
{
public:
    explicit Student(std::string name, ISchoolSpace* currentSpace);

    ~Student() override = default;

    void attendClass(Classroom* classroom);
    void exitClass();
    void graduate(Course* course);
    std::string getName() const override;
    ISchoolSpace* getSchoolSpace() const override;

private:
    std::string _name;
    std::vector<Course*> _subscribedCourse;
    ISchoolSpace* _currentSpace;
};
