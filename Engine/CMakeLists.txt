project(Engine)

file(GLOB_RECURSE ENGINE_SOURCES
        "src/*.cpp"
        "src/*.c"
)

file(GLOB_RECURSE ENGINE_HEADERS
        "include/*.h"
        "include/*.hpp"
        "private/*.h"
        "private/*.hpp"
)

add_library(Engine SHARED
        ${ENGINE_SOURCES}
        ${ENGINE_HEADERS}
)

target_include_directories(Engine
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/private
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(Engine
        PRIVATE
        ENGINE_EXPORTS
        PUBLIC
        $<$<PLATFORM_ID:Windows>:WIN32_LEAN_AND_MEAN>
)

if(WIN32)
    set_target_properties(Engine PROPERTIES
            WINDOWS_EXPORT_ALL_SYMBOLS ON
    )
endif()

install(TARGETS Engine
        EXPORT EngineTargets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include)
