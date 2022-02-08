project(study-machine-r)

add_library(study-machine-r SHARED StudyMachineR.cpp)

target_link_libraries(study-machine-r operations)

add_dependencies(study-machine-r operations)