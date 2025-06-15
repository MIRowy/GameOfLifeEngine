#include <iostream>
#include "../cli/commands/BaseCommandHandler.h"
#include "../engine/utils/Point.h"

class SetCommandHandler final : public BaseCommandHandler {
public:
    void handle(GameOfLifeManager& gameOfLifeManager, const std::vector<std::string> args) override {
        if (args.size() != 3) {
            std::cout << "Error: Set command requires 3 arguments: <x> <y> <cell_type>\n";

            return;
        }

        int x = std::stoi(args[0]);
        int y = std::stoi(args[1]);
        const std::string& cellType = args[2];

        gameOfLifeManager.setCellOnBoard({x, y}, cellType);

        std::cout << "Cell set successfully!\n";
    }

    std::string getDescription() override {
        return "Sets a cell of specified type at given coordinates. Usage: set <x> <y> <cell_type>";
    }
};