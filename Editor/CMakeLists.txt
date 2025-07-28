project(Editor)
file(GLOB_RECURSE EDITOR_SOURCES
        "src/*.cpp"
        "src/*.c"
)
file(GLOB_RECURSE EDITOR_HEADERS
        "src/*.h"
        "src/*.hpp"
)
add_executable(Editor
        ${EDITOR_SOURCES}
        ${EDITOR_HEADERS}
)
target_link_libraries(Editor
        PRIVATE
        Engine
)
target_include_directories(Editor
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(WIN32)
    add_custom_command(TARGET Editor POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Engine>
            $<TARGET_FILE_DIR:Editor>
            COMMENT "Copying Engine DLL to Editor output directory"
    )
endif()

#add_custom_command(TARGET Editor POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_CURRENT_SOURCE_DIR}/resources
#        $<TARGET_FILE_DIR:Editor>/resources
#        COMMENT "Copying Editor resources"
#)
