cmake_minimum_required (VERSION 2.8)
project (ClassQuiz_65423)
set(PROG quiz)

#---------------------------------

set(SOURCES src/main.c src/interface_main.c src/interface_properties.c src/interface_functions.c src/callbacks_main_menu.c src/callbacks_warnings.c src/destroy_signals.c src/callbacks_edit_scrn.c src/callbacks_edit_file.c server/server.c shm/shared_memory.c src/callbacks_play_scrn.c src/callbacks_results_scrn.c)

add_library(shm SHARED shm/shared_memory.c)
include_directories ("${PROJECT_SOURCE_DIR}/shm")
link_directories ("${PROJECT_SOURCE_DIR}/lib")  #must occur before the target that needs it (next)

add_library(server SHARED server/server.c)
include_directories ("${PROJECT_SOURCE_DIR}/server")
link_directories ("${PROJECT_SOURCE_DIR}/lib")  #must occur before the target that needs it (next)


add_executable(${PROG} ${SOURCES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_INCLUDE_DIRS})

target_link_libraries(${PROG} ${GTK_LIBRARIES}) 
target_link_libraries(${PROG} shm)
target_link_libraries(${PROG} server)

set (CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}")
install(TARGETS ${PROG} shm
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
	)

install(TARGETS ${PROG} server
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
	)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/src/interface/glade/" DESTINATION bin FILES_MATCHING PATTERN "*.glade")
install(DIRECTORY "${PROJECT_SOURCE_DIR}/src/interface/icons/" DESTINATION bin FILES_MATCHING PATTERN "*.svg")
install(DIRECTORY "${PROJECT_SOURCE_DIR}/src/interface/images/" DESTINATION bin FILES_MATCHING PATTERN "*.png")



add_custom_target( cpfiles
		COMMAND cp "${PROJECT_SOURCE_DIR}/src/interface/glade/*.glade" "${PROJECT_SOURCE_DIR}/src/interface/images/*.png" "${PROJECT_SOURCE_DIR}/src/interface/icons/*.svg" "${PROJECT_BINARY_DIR}"
		)

add_custom_target( libpath
		COMMAND sudo ldconfig "${PROJECT_SOURCE_DIR}/lib"
		)


add_dependencies(${PROG} cpfiles)


# The project version number. Used in documentation generation and similar
set(VERSION_MAJOR   1   CACHE STRING "Project major version number.")
set(VERSION_MINOR   0   CACHE STRING "Project minor version number.")
set(VERSION_PATCH   0   CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)
#-- add a target to generate API documentation with Doxygen
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install doc (requires Doxygen)" ${DOXYGEN_FOUND})
if(BUILD_DOCUMENTATION)
	if(NOT DOXYGEN_FOUND)
		message(FATAL_ERROR "Doxygen is needed to build the documentation.")
	endif()
	set(doxyfile_in "${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile")
	set(doxyfile "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
	set(doxy_main_page "${CMAKE_CURRENT_SOURCE_DIR}/doc/mainpage.dox")
	configure_file(${doxyfile_in} ${doxyfile} @ONLY)
	add_custom_target(doc
        	COMMAND ${DOXYGEN_EXECUTABLE}
        	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        	COMMENT "Generating API documentation with Doxygen"
        	VERBATIM)
endif()
