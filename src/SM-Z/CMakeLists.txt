project(study-machine-z)

add_library(study-machine-z SHARED StudyMachineZ.cpp)

target_link_libraries(study-machine-z operations)

add_dependencies(study-machine-z operations)