cmake_minimum_required (VERSION 3.8)

project ("QuantumSimulator")

set(SOURCE QuantumSimulator.cpp)
set(EXECUTABLE QuantumSimulator)
set(LIBRARY lib)

include_directories(${LIBRARY})

add_executable(${EXECUTABLE} ${SOURCE})

add_subdirectory(${LIBRARY})

target_link_libraries(${EXECUTABLE} ${LIBRARY})
