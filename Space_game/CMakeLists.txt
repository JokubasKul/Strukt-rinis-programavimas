cmake_minimum_required(VERSION 3.30)
project(Space_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(Space_game main.cpp
        Global_variables.h
        Global_variables.cpp
        Enemies_data.h
        Enemies_data.cpp
        loading_map.h
        loading_map.cpp
        movement.h
        movement.cpp
        loot_package.h
        "loot package.cpp"
        computer.h
        computer.cpp
        name_opening_endings_stats_level_up.h
        name_opening_endings_stats_level_up.cpp
        recharge_stations.h
        recharge_stations.cpp
        points_of_interest.h
        points_of_interest.cpp
        door.h
        door.cpp
        combat_encounters.h
        combat_encounters.cpp
        store_inventory_map.h
        store_inventory_map.cpp)
