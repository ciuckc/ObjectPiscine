add_executable(${PROJECT_NAME}
  main.cpp
  ${PROJECT_SOURCE_DIR}/inc/Circle.hpp
  ${PROJECT_SOURCE_DIR}/inc/Triangle.hpp
  ${PROJECT_SOURCE_DIR}/inc/Rectangle.hpp
  ${PROJECT_SOURCE_DIR}/inc/Shape.hpp
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)
