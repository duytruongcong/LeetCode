add_library(DatabaseLib STATIC StudentRepository.cpp)
find_package(SQLite3 REQUIRED)
target_include_directories(DatabaseLib
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Interface
)
target_link_libraries(DatabaseLib PRIVATE ModelsLib)
target_link_libraries(DatabaseLib PRIVATE SQLite::SQLite3)