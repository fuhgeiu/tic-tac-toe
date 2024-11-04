cmake_minimum_required(VERSION 3.28)
project(cmake)

set(CMAKE_CXX_STANDARD 17)

add_executable(TTT src/ main_current.cpp

        "core data/user interface.hpp"
        "core data/player.hpp"
        "core data/game_data.hpp"
        "includes/stream.hpp"
        "core data/board.hpp"
)

target_include_directories(TTT PUBLIC

        ${PROJECT_SOURCE_DIR}/includes
        ${PROJECT_SOURCE_DIR}/core data
)

