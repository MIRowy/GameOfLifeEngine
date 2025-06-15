#ifndef GAMEOFLIFEMANAGER_H
#define GAMEOFLIFEMANAGER_H

#include <memory>

#include "BaseCell.h"
#include "typedefs.h"
#include "configurationRepository/ConfigurationRepository.h"

struct CellState {
    CellLifeState state;
    std::string type;
};

class GameOfLifeManager {
    Board _board;
    Point _boardSize;

    ConfigurationRepository _configurationRepository;

    std::shared_ptr<BaseNeighbourhood> _selectedNeighbourhood;
    std::shared_ptr<BaseGameCycleBehaviour> _selectedGameCycleBehaviour;

public:
    explicit GameOfLifeManager(const ConfigurationRepository &configurationRepository);

    void selectGameCycleBehaviour(const std::string &name);

    void selectNeighbourhood(const std::string &name);

    std::vector<std::vector<CellState>> getBoard() const;

    void setCellOnBoard(Point position, std::string type);

    void performCycle() const;
};

#endif
