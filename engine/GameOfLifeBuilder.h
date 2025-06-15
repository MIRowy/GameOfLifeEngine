#ifndef GAMEOFLIFEBUILDER_H
#define GAMEOFLIFEBUILDER_H

#include "./GameOfLifeManager.h"
#include "./neighbourhood/MooreNeighbourhood.cpp"
#include "./gameCycleBehaviour/DefaultGameCycleBehaviour.cpp"
#include "./cells/EmptyCellFactoryMethod.cpp"

class GameOfLifeBuilder {
    ConfigurationRepository _configurationRepository;

public:
    GameOfLifeBuilder() {
        MooreNeighbourhood neighbourhood;
        _configurationRepository.addNeighbourhood("moore", std::make_shared<MooreNeighbourhood>(neighbourhood));

        DefaultGameCycleBehaviour gameCycleBehaviour;
        _configurationRepository.addGameCycleBehaviour(
            "default", std::make_shared<DefaultGameCycleBehaviour>(gameCycleBehaviour));

        EmptyCellFactoryMethod cellFactoryMethod;
        _configurationRepository.addCellFactoryMethod(
            "empty", std::make_shared<EmptyCellFactoryMethod>(cellFactoryMethod));
    }

    void addNeighbourhood(const std::string& name, const std::shared_ptr<BaseNeighbourhood> &neighbourhood) {
        _configurationRepository.addNeighbourhood(name, neighbourhood);
    }

    void addGameCycleBehaviour(const std::string& name, const std::shared_ptr<BaseGameCycleBehaviour> &behaviour) {
        _configurationRepository.addGameCycleBehaviour(name, behaviour);
    }

    void addCellFactoryMethod(const std::string& name, const std::shared_ptr<BaseCellFactoryMethod> &factoryMethod) {
        _configurationRepository.addCellFactoryMethod(name, factoryMethod);
    }

    [[nodiscard]]
    GameOfLifeManager build() const {
        GameOfLifeManager game(_configurationRepository);

        game.selectGameCycleBehaviour("default");
        game.selectNeighbourhood("moore");

        return game;
    }
};

#endif
