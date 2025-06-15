#include <iostream>
#include "./BaseCommandHandler.h"

class ChangeNeighbourhoodCommandHandler final : public BaseCommandHandler {
public:
    void handle(GameOfLifeManager& gameOfLifeManager, const std::vector<std::string> args) override {
        if (args.size() != 1) {
            std::cout << "Error: Change neighbourhood command requires an argument: <neighbourhood_type>\n";

            return;
        }

        const std::string& neighbourhoodType = args[0];

        gameOfLifeManager.selectNeighbourhood(neighbourhoodType);

        std::cout << "Neighbourhood type changed to: " << neighbourhoodType << "\n";
    }

    std::string getDescription() override {
        return "Changes the neighbourhood type. Usage: neighbourhood <type>";
    }
};