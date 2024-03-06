add_executable(${PROJECT_NAME}
        main.cpp
        ${PROJECT_SOURCE_DIR}/inc/LinkablePart.hpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/inc
)

set_target_properties(${PROJECT_NAME}
        PROPERTIES CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)