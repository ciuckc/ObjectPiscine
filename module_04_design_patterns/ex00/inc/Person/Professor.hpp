#pragma once

#include "IStaff.hpp"

class Course;
class IForm;

class Professor : public IStaff
{
public:
 explicit Professor(std::string name);
 ~Professor() override = default;

 void assignCourse(Course* course);
 void doClass();
 void closeCourse();
 void sign(IForm* form) override;
 std::string getName() const override;
 ISchoolSpace* getSchoolSpace() const override;

private:
 Course* _currentCourse;
};
