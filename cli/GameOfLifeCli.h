#ifndef GAMEOFLIFECLI_H
#define GAMEOFLIFECLI_H

#include "../engine/GameOfLifeManager.h"
#include "./commands/BaseCommandHandler.h"

class GameOfLifeCli {
    std::map<std::string, std::shared_ptr<BaseCommandHandler>> _commandHandlers;
    GameOfLifeManager _gameOfLifeManager;

public:
    explicit GameOfLifeCli(GameOfLifeManager gameOfLifeManager);

    void registerCommandHandler(const std::string &command, const std::shared_ptr<BaseCommandHandler> &commandHandler);

    void run();
};

#endif
