set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/inc)

add_executable(${PROJECT_NAME}
  main.cpp
  ${INCLUDE_DIR}/IEmployee.hpp
  ${INCLUDE_DIR}/EmployeeManager.hpp
  ${INCLUDE_DIR}/ContractEmployee.hpp
  ${INCLUDE_DIR}/Apprentice.hpp
  ${INCLUDE_DIR}/TempWorker.hpp
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)
