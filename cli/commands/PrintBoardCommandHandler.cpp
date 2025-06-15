#include <iostream>
#include <map>
#include "BaseCommandHandler.h"

class PrintBoardCommandHandler final : public BaseCommandHandler {
    const std::map<std::string, char> cellTypeToChar = {
        {"empty", ' '},
        {"default", '*'}
    };

public:
    void handle(GameOfLifeManager &gameOfLifeManager, std::vector<std::string> args) override {
        const auto board = gameOfLifeManager.getBoard();

        std::cout << "+";

        for (auto i = 0; i < board[0].size() * 2 + 1; ++i) {
            std::cout << "-";
        }

        std::cout << "+\n";

        for (const auto &row: board) {
            std::cout << "| ";
            for (const auto &[state, type]: row) {
                char displayChar;

                if (state == CellLifeState::Alive || type == "empty") {
                    auto it = cellTypeToChar.find(type);

                    displayChar = it != cellTypeToChar.end() ? it->second : '?';
                }
                else {
                    displayChar = '#';
                }

                std::cout << displayChar << " ";
            }
            std::cout << "|\n";
        }

        std::cout << "+";

        for (auto i = 0; i < board[0].size() * 2 + 1; ++i) {
            std::cout << "-";
        }

        std::cout << "+\n";
    }

    std::string getDescription() override {
        return "Prints the current state of the board";
    }
};
