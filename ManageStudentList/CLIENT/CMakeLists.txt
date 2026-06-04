cmake_minimum_required(VERSION 3.10)

project(StudentManagementClient VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} Main.cpp)

add_subdirectory(CSV)
add_subdirectory(Database)
add_subdirectory(Manager)
add_subdirectory(Models)
add_subdirectory(Network)
add_subdirectory(Utils)
    

target_link_libraries(${PROJECT_NAME} PRIVATE    
    CsvLib 
    DatabaseLib 
    ManagerLib 
    ModelsLib 
    NetworkLib
    UtilsLib)

target_compile_definitions(${PROJECT_NAME} PUBLIC DATABASE_FILE_PATH=\"${CMAKE_SOURCE_DIR}/Database/student.db\")
target_compile_definitions(${PROJECT_NAME} PUBLIC CSV_FILE_PATH=\"${CMAKE_SOURCE_DIR}/CSV/student.csv\")