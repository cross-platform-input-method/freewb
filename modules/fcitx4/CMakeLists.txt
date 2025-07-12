message(STATUS "will add fcitx4 module")

find_package(Fcitx 4.2.7 REQUIRED)
if (NOT Fcitx_FOUND)
    message(FATAL_ERROR "fcitx4 not found!,will not build fcitx4 module")
    return()
endif()

include_directories(${FCITX4_FCITX_INCLUDE_DIRS})
include_directories(${FCITX4_FCITX_CONFIG_INCLUDE_DIRS})
include_directories(${FCITX4_FCITX_UTILS_INCLUDE_DIRS})

fcitx_add_addon(fcitx-${PROJECT_NAME}-im-addon SHARED im_module.cpp)

target_link_libraries(fcitx-${PROJECT_NAME}-im-addon
    ${FCITX4_FCITX_LIBRARIES}
    ${FCITX4_FCITX_CONFIG_LIBRARIES}
    ${FCITX4_FCITX_UTILS_LIBRARIES}
)

configure_file(fcitx-freewb-addon.conf.in ${CMAKE_CURRENT_BINARY_DIR}/fcitx-freewb-addon.conf IMMEDIATE @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/fcitx-freewb-addon.conf DESTINATION ${CMAKE_INSTALL_PREFIX}/share/fcitx/addon/)

configure_file(freewb.conf.in ${CMAKE_CURRENT_BINARY_DIR}/freewb.conf IMMEDIATE @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/freewb.conf DESTINATION ${CMAKE_INSTALL_PREFIX}/share/fcitx/inputmethod/)