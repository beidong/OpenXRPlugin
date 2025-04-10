get_filename_component(PACKAGE_LIBLOG_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)

set(SPD_LOG_INCLUDE ${PACKAGE_LIBLOG_DIR}/spdlog-1.13.0/include)

include_directories(
    ${SPD_LOG_INCLUDE}
    ${PACKAGE_LIBLOG_DIR}
)