cmake_minimum_required(VERSION 3.10)

project(StudentManagement VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    Main.cpp
    Src/Database.cpp
    Src/Manager.cpp
    Src/Student.cpp
    Src/CSV.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/Include
)

target_compile_definitions(${PROJECT_NAME} PRIVATE DATABASE_FILE_PATH="${CMAKE_SOURCE_DIR}/Database/student.db")
target_compile_definitions(${PROJECT_NAME} PRIVATE CSV_FILE_PATH="${CMAKE_SOURCE_DIR}/CSV/student.csv")

find_package(SQLite3 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3)