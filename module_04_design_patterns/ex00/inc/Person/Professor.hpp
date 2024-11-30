#pragma once

#include "Course.hpp"
#include "IForm.hpp"
#include "IStaff.hpp"

class Professor : public IStaff
{
public:
    explicit Professor(std::string name);
    ~Professor() override = default;

    void assignCourse(Course* p_course);
    void doClass();
    void closeCourse();
    void sign(IForm* p_form) override;
    std::string getName() const override;
    ISchoolSpace* getSchoolSpace() const override;

private:
    Course* _currentCourse;
};
