#include "BaseCell.h"
#include "BaseGameCycleBehaviour.h"
#include "BaseNeighbourhood.h"
#include "../typedefs.h"

class DefaultGameCycleBehaviour final : public BaseGameCycleBehaviour {
    void performCycle(const Board &board, const std::shared_ptr<BaseNeighbourhood> neighbourhood) override {
        const int rows = board.size();
        const int cols = board[0].size();

        std::vector nextStates(rows, std::vector<CellLifeState>(cols));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                const auto neighbours = neighbourhood->getNeighbours(board, {i, j});

                nextStates[i][j] = board[i][j]->getNextLifeState(neighbours);
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                const CellLifeState current = board[i][j]->getLifeState();
                const CellLifeState next = nextStates[i][j];

                if (current == CellLifeState::Alive && next == CellLifeState::Dead) {
                    board[i][j]->kill();
                } else if (current == CellLifeState::Dead && next == CellLifeState::Alive) {
                    board[i][j]->resurrect();
                }
                else if (current == CellLifeState::Alive && next == CellLifeState::Alive) {
                    board[i][j]->keepAlive(neighbourhood);
                }
            }
        }
    }
};