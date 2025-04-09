project(openxrplugin)


message(STATUS "^-^ ============================== " ${PROJECT_NAME})

include_directories(
    ${JSONLIB_ROOT}
)

set(PROJECT_SOURCES
    openxrplugin_global.h
    openxrplugin_define.h
    
    src/vrcapture.h
    src/vrcapture.cpp
    src/eyetracker.h
    src/eyetracker.cpp
)

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE OPENXRPLUGIN_LIBRARY)
