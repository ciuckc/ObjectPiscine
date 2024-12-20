#pragma once

#include "Course.hpp"
#include "ISchoolSpace.hpp"

class Course;
class IPerson;

class Classroom : public ISchoolSpace
{
public:
    ~Classroom() override = default;

    void assignCourse(Course* course);
    bool canEnter(IPerson* person) override;
    void enter(IPerson* person) override;
    void exit(IPerson* person) override;
    std::vector<IPerson*> getOccupants() const override;
    long long getId() const override;

private:
    Course* _currentRoom{};
};
