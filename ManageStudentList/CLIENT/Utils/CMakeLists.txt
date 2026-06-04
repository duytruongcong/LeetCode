add_library(UtilsLib STATIC 
JsonHelper.cpp)

find_package(nlohmann_json REQUIRED)

target_include_directories(UtilsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(UtilsLib PUBLIC nlohmann_json::nlohmann_json)