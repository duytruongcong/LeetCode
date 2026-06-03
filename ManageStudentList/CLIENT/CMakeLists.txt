cmake_minimum_required(VERSION 3.10)

project(StudentManagementClient VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    Main.cpp
    Database/Database.cpp
    Manager/Manager.cpp
    Models/Student.cpp
    CSV/CSV.cpp
    Utils/JsonHelper.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/Database
        ${CMAKE_SOURCE_DIR}/Manager
        ${CMAKE_SOURCE_DIR}/Models
        ${CMAKE_SOURCE_DIR}/CSV
        ${CMAKE_SOURCE_DIR}/Utils
)

target_include_directories(${PROJECT_NAME} PRIVATE ../LIBRARY/json/include)

target_compile_definitions(${PROJECT_NAME} PRIVATE DATABASE_FILE_PATH=\"${CMAKE_SOURCE_DIR}/Database/student.db\")
target_compile_definitions(${PROJECT_NAME} PRIVATE CSV_FILE_PATH=\"${CMAKE_SOURCE_DIR}/CSV/student.csv\")

find_package(SQLite3 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3)
