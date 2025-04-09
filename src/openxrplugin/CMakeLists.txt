project(openxrplugin)


message(STATUS "^-^ ============================== " ${PROJECT_NAME})


set(OpenXR_DIR "${OPENXR_SDK_ROOT}/cmake")

# 查找 OpenXR
find_package(OpenXR REQUIRED)

include_directories(
    ${JSONLIB_ROOT}
    ${SPDLOG_ROOT}
    OpenXR::headers
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

target_link_libraries(${PROJECT_NAME} PRIVATE OpenXR::openxr_loader)

target_compile_definitions(${PROJECT_NAME} PRIVATE OPENXRPLUGIN_LIBRARY)
