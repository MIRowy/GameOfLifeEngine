#include <algorithm>

#include "GameOfLifeCli.h"
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

#include "./commands/PrintBoardCommandHandler.cpp"
#include "./commands/SetCommandHandler.cpp"
#include "./commands/ChangeNeighbourhoodCommandHandler.cpp"
#include "./commands/ChangeGameCycleBehaviourCommandHandler.cpp"
#include "./commands/CycleCommandHandler.cpp"

GameOfLifeCli::GameOfLifeCli(GameOfLifeManager gameOfLifeManager): _gameOfLifeManager(std::move(gameOfLifeManager)) {
    _commandHandlers["printBoard"] = std::make_shared<PrintBoardCommandHandler>();
    _commandHandlers["set"] = std::make_shared<SetCommandHandler>();
    _commandHandlers["changeNeighbourhood"] = std::make_shared<ChangeNeighbourhoodCommandHandler>();
    _commandHandlers["changeGameCycleBehaviour"] = std::make_shared<ChangeGameCycleBehaviourCommandHandler>();
    _commandHandlers["cycle"] = std::make_shared<CycleCommandHandler>();
}

void GameOfLifeCli::registerCommandHandler(
    const std::string& command, const std::shared_ptr<BaseCommandHandler> &commandHandler) {
    _commandHandlers[command] = commandHandler;
}

void GameOfLifeCli::run() {
    std::cout << "Welcome to Game of Life CLI!\n";
    std::cout << "Type 'help' for available commands.\n";

    std::string input;
    std::string command;
    std::vector<std::string> args;
    while (true) {
        args.clear();

        std::cout << ">  ";

        // Get input, then trim it.
        std::getline(std::cin, input);
        input = std::string(input.begin(), std::find_if_not(input.rbegin(), input.rend(), isspace).base());
        input = std::string(std::ranges::find_if_not(input, isspace), input.end());

        if (input.empty()) {
            continue;
        }

        // Check if besides command there are any arguments. Split into separate vector.
        if (const size_t spacePos = input.find(' '); spacePos != std::string::npos) {
            command = input.substr(0, spacePos);
            std::string argsStr = input.substr(spacePos + 1);

            std::istringstream iss(argsStr);
            std::string token;

            while (iss >> token) {
                args.push_back(token);
            }
        } else {
            command = input;
            args.clear();
        }

        if (command == "exit") {
            break;
        }

        if (command == "help") {
            std::cout << "Available commands:\n";
            std::cout << "- exit - Exit the program\n";
            std::cout << "- help - List all commands\n";

            for (const auto &[command, handler]: _commandHandlers) {
                std::cout << "- " << command << " - " << handler->getDescription() << "\n";
            }

            std::cout << std::endl;

            continue;
        }

        auto handlerIt = _commandHandlers.find(command);

        if (handlerIt == _commandHandlers.end()) {
            std::cout << "Unknown command: " << command << "\n";
            std::cout << "Type 'help' for available commands.\n";

            continue;
        }

        try {
            handlerIt->second->handle(_gameOfLifeManager, args);
        } catch (const std::exception &e) {
            std::cout << "Error executing command: " << e.what() << "\n";
        }
    }
}
