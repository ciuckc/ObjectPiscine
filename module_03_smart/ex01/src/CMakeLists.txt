add_executable(${PROJECT_NAME}
  PUBLIC
    main.cpp
    ${PROJECT_SOURCE_DIR}/inc/Command.hpp
    ${PROJECT_SOURCE_DIR}/inc/IDiscountedPrice.hpp
    ${PROJECT_SOURCE_DIR}/inc/PackageReductionDiscountCommand.hpp
    ${PROJECT_SOURCE_DIR}/inc/TuesdayDiscountCommand.hpp
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
