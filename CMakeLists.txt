cmake_minimum_required(VERSION 3.15)
project(BlockchainCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)

# Collect sources but exclude CMake build dirs
file(GLOB_RECURSE ALL_SRC CONFIGURE_DEPENDS
     "${CMAKE_SOURCE_DIR}/*.cpp"
     "${CMAKE_SOURCE_DIR}/*.cxx"
)

# Remove files in CMakeFiles or out or other build dirs
list(FILTER ALL_SRC EXCLUDE REGEX ".*/CMakeFiles/.*")
list(FILTER ALL_SRC EXCLUDE REGEX ".*/out/.*")
list(FILTER ALL_SRC EXCLUDE REGEX ".*/build/.*")

add_executable(${PROJECT_NAME} ${ALL_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/blockhain"
    ${OPENSSL_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::SSL OpenSSL::Crypto)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "--- Starting Execution ---"
    COMMAND $<TARGET_FILE:${PROJECT_NAME}>
)