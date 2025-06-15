#include <iostream>
#include "./BaseCommandHandler.h"

class ChangeGameCycleBehaviourCommandHandler final : public BaseCommandHandler {
public:
    void handle(GameOfLifeManager& gameOfLifeManager, const std::vector<std::string> args) override {
        if (args.size() != 1) {
            std::cout << "Error: Change game cycle behaviour command requires an argument: <behaviour_type>\n";

            return;
        }

        const std::string& behaviourType = args[0];

        gameOfLifeManager.selectGameCycleBehaviour(behaviourType);

        std::cout << "Game cycle behaviour changed to: " << behaviourType << "\n";
    }

    std::string getDescription() override {
        return "Changes the game cycle behaviour type. Usage: behaviour <type>";
    }
};