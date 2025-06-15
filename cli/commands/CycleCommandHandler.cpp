#include <iostream>
#include "../cli/commands/BaseCommandHandler.h"

class CycleCommandHandler final : public BaseCommandHandler {
public:
    void handle(GameOfLifeManager& gameOfLifeManager, const std::vector<std::string> args) override {
        int cycles = 1;

        if (args.size() > 1) {
            std::cout << "Error: Cycle command accepts at most 1 argument (number of cycles)\n";

            return;
        }

        if (args.size() == 1) {
            cycles = std::stoi(args[0]);
        }

        if (cycles <= 0) {
            std::cout << "Error: Number of cycles must be positive\n";

            return;
        }

        for (int i = 0; i < cycles; ++i) {
            gameOfLifeManager.performCycle();
        }

        std::cout << "Advanced " << cycles << " cycle(s)\n";
    }

    std::string getDescription() override {
        return "Advances the game by specified number of cycles. Usage: cycle [number_of_cycles]. Default is 1 cycle.";
    }
};