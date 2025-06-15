#ifndef CONFIGURATIONREPOSITORY_H
#define CONFIGURATIONREPOSITORY_H

#include <map>
#include <memory>
#include <string>

#include "../typedefs.h"

class ConfigurationRepository {
    std::map<std::string, std::shared_ptr<BaseNeighbourhood>> _neighbourhoodMap;
    std::map<std::string, std::shared_ptr<BaseCellFactoryMethod>> _cellFactoryMethodMap;
    std::map<std::string, std::shared_ptr<BaseGameCycleBehaviour>> _gameCycleBehaviourMap;

public:
    void addNeighbourhood(const std::string &key, std::shared_ptr<BaseNeighbourhood> neighbourhood);
    std::shared_ptr<BaseNeighbourhood> getNeighbourhood(const std::string &key);

    void addCellFactoryMethod(const std::string &key, std::shared_ptr<BaseCellFactoryMethod> cellFactoryMethod);
    std::shared_ptr<BaseCellFactoryMethod> getCellFactoryMethod(const std::string &key);

    void addGameCycleBehaviour(const std::string &key, std::shared_ptr<BaseGameCycleBehaviour> gameCycleBehavior);
    std::shared_ptr<BaseGameCycleBehaviour> getGameCycleBehaviour(const std::string &key);
};

#endif
