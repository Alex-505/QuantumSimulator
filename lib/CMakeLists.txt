file(GLOB SOURCES impl/*.cpp)
file(GLOB HEADERS *.h)

add_library(${LIBRARY} STATIC ${SOURCES} ${HEADERS})