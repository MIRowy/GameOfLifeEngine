#include "GameOfLifeManager.h"

#include <format>

#include "BaseCell.h"
#include "BaseCellFactoryMethod.h"
#include "BaseGameCycleBehaviour.h"

GameOfLifeManager::GameOfLifeManager(const ConfigurationRepository& configurationRepository)
    : _boardSize(10, 10), _configurationRepository(configurationRepository) {
    const auto emptyCellFactory = _configurationRepository.getCellFactoryMethod("empty");

    _board.resize(10);

    for (auto i = 0; i < 10; i++) {
        _board[i].resize(10);

        for (auto j = 0; j < 10; j++) {
            _board[i][j] = emptyCellFactory->create({i, j});
        }
    }
}

void GameOfLifeManager::selectGameCycleBehaviour(const std::string &name) {
    _selectedGameCycleBehaviour = _configurationRepository.getGameCycleBehaviour(name);
}

void GameOfLifeManager::selectNeighbourhood(const std::string &name) {
    _selectedNeighbourhood = _configurationRepository.getNeighbourhood(name);
}

std::vector<std::vector<CellState>> GameOfLifeManager::getBoard() const {
    std::vector board(_boardSize.x, std::vector<CellState>(_boardSize.y));

    for (auto i = 0; i < _boardSize.x; i++) {
        for (auto j = 0; j < _boardSize.y; j++) {
            const auto cell = _board[i][j];

            board[i][j] = { cell->getLifeState(), cell->getType() };
        }
    }

    return board;
}

void GameOfLifeManager::setCellOnBoard(const Point position, std::string type) {
    const auto factoryMethod = _configurationRepository.getCellFactoryMethod(type);

    if (factoryMethod == nullptr) {
        throw std::runtime_error(std::format("Cell type {} not found", type));
    }

    _board[position.x][position.y] = factoryMethod->create(position);
}

void GameOfLifeManager::performCycle() const {
    _selectedGameCycleBehaviour->performCycle(_board, _selectedNeighbourhood);
}
