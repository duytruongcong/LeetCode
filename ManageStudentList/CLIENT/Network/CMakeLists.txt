add_library(NetworkLib STATIC 
SyncService.cpp
ApiClient.cpp)

target_include_directories(NetworkLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})