project(liblog)

message(STATUS "^-^ ============================== " ${PROJECT_NAME})
include(LibLogConfig.cmake)

set(PROJECT_SOURCES
    liblog.h
    liblog.cpp
)


add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE LIBLOG_LIBRARY)
