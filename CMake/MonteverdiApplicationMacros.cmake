macro(create_monteverdi_application)
  cmake_parse_arguments(APPLICATION  "" "NAME;OUTPUT_NAME;COMPONENT_NAME" "SOURCES;LINK_LIBRARIES" ${ARGN} )

  if(WIN32)
    add_executable(${APPLICATION_NAME}
      WIN32
      ${APPLICATION_SOURCES})
  else() #Unix
    add_executable(${APPLICATION_NAME}
      ${APPLICATION_SOURCES})
  endif()

  if (APPLICATION_OUTPUT_NAME)
    set_target_properties(${APPLICATION_NAME} PROPERTIES OUTPUT_NAME ${APPLICATION_OUTPUT_NAME})
  endif()

  target_link_libraries(${APPLICATION_NAME} ${APPLICATION_LINK_LIBRARIES})

install(TARGETS ${APPLICATION_NAME}
  RUNTIME DESTINATION ${Monteverdi_INSTALL_BIN_DIR} COMPONENT ${APPLICATION_COMPONENT_NAME}
  LIBRARY DESTINATION ${Monteverdi_INSTALL_LIB_DIR} COMPONENT ${APPLICATION_COMPONENT_NAME}
  ARCHIVE DESTINATION ${Monteverdi_INSTALL_LIB_DIR} COMPONENT ${APPLICATION_COMPONENT_NAME}
  )

endmacro(create_monteverdi_application)