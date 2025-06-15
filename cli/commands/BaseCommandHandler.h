#ifndef BASECOMMANDHANDLER_H
#define BASECOMMANDHANDLER_H

#include "../GameOfLifeManager.h"

class BaseCommandHandler {
public:
    virtual ~BaseCommandHandler() = default;

    virtual void handle(GameOfLifeManager& gameOfLifeManager, std::vector<std::string> args) = 0;

    virtual std::string getDescription() = 0;
};

#endif
