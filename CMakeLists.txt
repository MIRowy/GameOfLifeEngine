cmake_minimum_required(VERSION 3.31)
project(GameOfLifeEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameOfLifeEngine main.cpp
        engine/configurationRepository/ConfigurationRepository.cpp engine/configurationRepository/ConfigurationRepository.h
        engine/neighbourhood/MooreNeighbourhood.cpp
        engine/gameCycleBehaviour/DefaultGameCycleBehaviour.cpp

        cli/GameOfLifeCli.cpp
        cli/commands/BaseCommandHandler.h

        engine/GameOfLifeBuilder.h
        engine/GameOfLifeManager.cpp
        myCustomImplementations/DefaultGameOfLifeCell.cpp
        myCustomImplementations/DefaultGameOfLifeCellFactoryMethod.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/engine
        ${CMAKE_SOURCE_DIR}/engine/cells
        ${CMAKE_SOURCE_DIR}/engine/neighbourhood
        ${CMAKE_SOURCE_DIR}/engine/utils
        ${CMAKE_SOURCE_DIR}/engine/cellFactoryMethod
        ${CMAKE_SOURCE_DIR}/engine/gameCycleBehaviour
)