project(pg_hamming)

find_package(PostgreSQL REQUIRED)

include_directories(${PostgreSQL_TYPE_INCLUDE_DIR} SYSTEM)

add_library(pg_hamming SHARED pg_hamming.c)
target_link_libraries(pg_hamming ${PostgreSQL_LIBRARY})
