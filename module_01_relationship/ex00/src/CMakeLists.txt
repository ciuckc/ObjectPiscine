add_executable(${PROJECT_NAME}
main.cpp
Worker.cpp
Tool.cpp
Shovel.cpp
Hammer.cpp
${PROJECT_SOURCE_DIR}/inc/Position.hpp
${PROJECT_SOURCE_DIR}/inc/Statistic.hpp
${PROJECT_SOURCE_DIR}/inc/Worker.hpp
${PROJECT_SOURCE_DIR}/inc/Tool.hpp
${PROJECT_SOURCE_DIR}/inc/Hammer.hpp
${PROJECT_SOURCE_DIR}/inc/Shovel.hpp
${PROJECT_SOURCE_DIR}/inc/Workshop.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)

set_target_properties(${PROJECT_NAME}
PROPERTIES CXX_STANDARD 23
CXX_STANDARD_REQUIRED ON
RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
