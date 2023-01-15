add_library(${CMAKE_PROJECT_NAME}_STATIC STATIC
    vcnl3020.c
)

add_library(${CMAKE_PROJECT_NAME}_SHARED SHARED
    vcnl3020.c
)

target_include_directories(${CMAKE_PROJECT_NAME}_SHARED
    PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
    PRIVATE
    "${PROJECT_SOURCE_DIR}/src/include"
)

target_include_directories(${CMAKE_PROJECT_NAME}_STATIC
    PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
    PRIVATE
    "${PROJECT_SOURCE_DIR}/src/include"
)