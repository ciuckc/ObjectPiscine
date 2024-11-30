set(INCLUDE_DIR
        ${PROJECT_SOURCE_DIR}/inc
)

# Course
set(COURSE_HEADER_DIR
        ${INCLUDE_DIR}/Course
)

set(COURSE_HEADER
        ${COURSE_HEADER_DIR}/Course.hpp
)

# Event
set(EVENT_HEADER_DIR
        ${INCLUDE_DIR}/Event
)

set(EVENT_HEADER
        ${EVENT_HEADER_DIR}/Event.hpp
)

# Form
set(FORM_HEADER_DIR
        ${INCLUDE_DIR}/Form
)

set(FORM_HEADER
        ${FORM_HEADER_DIR}/Contract/IForm.hpp
        ${FORM_HEADER_DIR}/CourseFinishedForm.hpp
        ${FORM_HEADER_DIR}/NeedCourseCreationForm.hpp
        ${FORM_HEADER_DIR}/NeedMoreClassRoomForm.hpp
        ${FORM_HEADER_DIR}/SubscriptionToCourseForm.hpp
        ${FORM_HEADER_DIR}/FormType.hpp
)

# Person
set(PERSON_HEADER_DIR
        ${INCLUDE_DIR}/Person
)

set(PERSON_HEADER
        ${PERSON_HEADER_DIR}/Contract/IPerson.hpp
        ${PERSON_HEADER_DIR}/Contract/IStaff.hpp
        ${PERSON_HEADER_DIR}/Headmaster.hpp
        ${PERSON_HEADER_DIR}/Student.hpp
        ${PERSON_HEADER_DIR}/Person.hpp
        ${PERSON_HEADER_DIR}/Professor.hpp
        ${PERSON_HEADER_DIR}/Secretary.hpp
        ${PERSON_HEADER_DIR}/Staff.hpp
)

# SchoolSpace
set(SCHOOL_SPACE_HEADER_DIR
        ${INCLUDE_DIR}/SchoolSpace
)

set(SCHOOL_SPACE_HEADER
        ${SCHOOL_SPACE_HEADER_DIR}/Contract/ISchoolSpace.hpp
        ${SCHOOL_SPACE_HEADER_DIR}/Classroom.hpp
        ${SCHOOL_SPACE_HEADER_DIR}/Courtyard.hpp
        ${SCHOOL_SPACE_HEADER_DIR}/HeadmasterOffice.hpp
        ${SCHOOL_SPACE_HEADER_DIR}/SecretarialOffice.hpp
        ${SCHOOL_SPACE_HEADER_DIR}/StaffRestRoom.hpp
)

add_executable(${PROJECT_NAME}
        main.cpp
        Person.cpp
        Room.cpp
        ${COURSE_HEADER}
        ${EVENT_HEADER}
        ${PERSON_HEADER}
        ${FORM_HEADER}
        ${SCHOOL_SPACE_HEADER}
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${INCLUDE_DIR}
        ${COURSE_HEADER_DIR}
        ${EVENT_HEADER_DIR}
        ${SCHOOL_SPACE_HEADER_DIR}
        ${SCHOOL_SPACE_HEADER_DIR}/Contract
        ${FORM_HEADER_DIR}
        ${FORM_HEADER_DIR}/Contract
        ${PERSON_HEADER_DIR}
        ${PERSON_HEADER_DIR}/Contract
)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)
