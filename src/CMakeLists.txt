add_library(VCNL3020_STATIC STATIC
    vcnl3020.c
)

add_library(VCNL3020_SHARED SHARED
    vcnl3020.c
)

target_include_directories(VCNL3020_SHARED
    PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_include_directories(VCNL3020_STATIC
    PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_compile_definitions(VCNL3020_SHARED
    PUBLIC
    PUBLIC_VCNL3020
    PRIVATE
    PRIVATE_VCNL3020
)

target_compile_definitions(VCNL3020_STATIC
    PUBLIC
    PUBLIC_VCNL3020
    PRIVATE
    PRIVATE_VCNL3020
)