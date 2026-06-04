add_library(ModelsLib STATIC Student.cpp)
target_include_directories(ModelsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ModelsLib PRIVATE ManagerLib)