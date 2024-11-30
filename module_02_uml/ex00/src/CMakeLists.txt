add_executable(${PROJECT_NAME}
        main.cpp
        ${PROJECT_SOURCE_DIR}/inc/LinkablePart.hpp
        ${PROJECT_SOURCE_DIR}/inc/Gear.hpp
        ${PROJECT_SOURCE_DIR}/inc/GearLever.hpp
        ${PROJECT_SOURCE_DIR}/inc/Wheel.hpp
        ${PROJECT_SOURCE_DIR}/inc/Singleton.hpp
        ${PROJECT_SOURCE_DIR}/inc/Transmission.hpp
        ${PROJECT_SOURCE_DIR}/inc/Crankshaft.hpp
        ${PROJECT_SOURCE_DIR}/inc/ExplosionChamber.hpp
        ${PROJECT_SOURCE_DIR}/inc/Injector.hpp
        ${PROJECT_SOURCE_DIR}/inc/Motor.hpp
        ${PROJECT_SOURCE_DIR}/inc/Pedal.hpp
        ${PROJECT_SOURCE_DIR}/inc/Direction.hpp
        ${PROJECT_SOURCE_DIR}/inc/DAE.hpp
        ${PROJECT_SOURCE_DIR}/inc/SteerWheel.hpp
        ${PROJECT_SOURCE_DIR}/inc/Brake.hpp
        ${PROJECT_SOURCE_DIR}/inc/BrakeController.hpp
        ${PROJECT_SOURCE_DIR}/inc/Cockpit.hpp
        ${PROJECT_SOURCE_DIR}/inc/Electronics.hpp
        ${PROJECT_SOURCE_DIR}/inc/Car.hpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/inc
)

set_target_properties(${PROJECT_NAME}
        PROPERTIES CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CMAKE_EXPORT_COMPILE_COMMANDS ON
)

set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
  ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
