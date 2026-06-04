add_library(CsvLib STATIC CSV.cpp)
target_include_directories(CsvLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(CsvLib PRIVATE ModelsLib)