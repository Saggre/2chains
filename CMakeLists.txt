cmake_minimum_required(VERSION 3.17)
project(2chains)

set(CMAKE_CXX_STANDARD 14)

add_executable(2chains src/main.cpp src/block.h src/chainmanager.h)

# Cryptopp
find_library(LIBCRYPTOPP cryptopp)
message(STATUS "CRYPTO LIBRARY => " ${LIBCRYPTOPP})
target_link_libraries(2chains ${LIBCRYPTOPP})

