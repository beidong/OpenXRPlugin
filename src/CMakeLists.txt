add_subdirectory(xviewclient/rfkitcommon)
set(RFKITCOMMON_DIR "${RFKITCOMMON_DIR}" PARENT_SCOPE)

add_subdirectory(xviewclient/rfexetool)
set(RFEXETOOL_DIR "${RFEXETOOL_DIR}" PARENT_SCOPE)

#add_subdirectory(xviewclient/rfhttpserver)
#set(RFHTTPSERVER_DIR "{RFHTTPSERVER_DIR}" PARENT_SCOPE)

add_subdirectory(xviewclient/capturetool)
set(CAPTURETOOL_DIR "${CAPTURETOOL_DIR}" PARENT_SCOPE)

add_subdirectory(xviewclient/cefwidget)
set(CEFWIDGET_DIR "${CEFWIDGET_DIR}" PARENT_SCOPE)

add_subdirectory(xviewclient/cefqueryprocessimp)
set(CEFQUREYPROCESS_DIR "${CEFQUREYPROCESS_DIR}" PARENT_SCOPE)

add_subdirectory(xviewclient/xviewclient)

