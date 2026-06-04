add_library(ManagerLib STATIC Manager.cpp)
target_include_directories(ManagerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ManagerLib PUBLIC ModelsLib DatabaseLib CsvLib)