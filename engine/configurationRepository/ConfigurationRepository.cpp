#include "ConfigurationRepository.h"

#include <utility>

void ConfigurationRepository::addNeighbourhood(
    const std::string &key, std::shared_ptr<BaseNeighbourhood> neighbourhood) {
    _neighbourhoodMap[key] = std::move(neighbourhood);
}

std::shared_ptr<BaseNeighbourhood> ConfigurationRepository::getNeighbourhood(const std::string &key) {
    return _neighbourhoodMap.at(key);
}

void ConfigurationRepository::addCellFactoryMethod(
    const std::string &key, std::shared_ptr<BaseCellFactoryMethod> cellFactoryMethod) {
    _cellFactoryMethodMap[key] = std::move(cellFactoryMethod);
}

std::shared_ptr<BaseCellFactoryMethod> ConfigurationRepository::getCellFactoryMethod(const std::string &key) {
    return _cellFactoryMethodMap.at(key);
}

void ConfigurationRepository::addGameCycleBehaviour(
    const std::string &key, std::shared_ptr<BaseGameCycleBehaviour> gameCycleBehavior) {
    _gameCycleBehaviourMap[key] = std::move(gameCycleBehavior);
}

std::shared_ptr<BaseGameCycleBehaviour> ConfigurationRepository::getGameCycleBehaviour(const std::string &key) {
    return _gameCycleBehaviourMap.at(key);
}