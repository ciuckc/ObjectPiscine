#pragma once

#include "Course.hpp"
#include "ISchoolSpace.hpp"

class Classroom : public ISchoolSpace
{
public:
    ~Classroom() override = default;

    void assignCourse(Course* _course);
    bool canEnter(IPerson*) override;
    void enter(IPerson*) override;
    void exit(IPerson*) override;
    std::vector<IPerson*> getOccupants() const override;
    long long getId() const override;

private:
    Course* _currentRoom{};
};
