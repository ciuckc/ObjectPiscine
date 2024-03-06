set(HEADER_LIST "${PROJECT_SOURCE_DIR}/inc/Vector2.h"
                "${PROJECT_SOURCE_DIR}/inc/Graph.h")

add_executable(${PROJECT_NAME} main.cpp Vector2.cpp Graph.cpp ${HEADER_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)

set_target_properties(${PROJECT_NAME}
PROPERTIES CXX_STANDARD 23
CXX_STANDARD_REQUIRED ON
RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
