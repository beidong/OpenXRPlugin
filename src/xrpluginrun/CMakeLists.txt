project(xrpluginrun)


message(STATUS "^-^ ============================== " ${PROJECT_NAME})

include_directories(
    ${OPENXRPLUGIN_DIR}
)

include(${LIBLOG_DIR}/LibLogConfig.cmake)

set(PROJECT_SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCES})


target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::WinExtras)
target_link_libraries(${PROJECT_NAME} PRIVATE openxrplugin liblog)
