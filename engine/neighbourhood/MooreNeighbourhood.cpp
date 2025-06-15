#include "BaseNeighbourhood.h"

class MooreNeighbourhood final : public BaseNeighbourhood {
public:
    std::vector<std::shared_ptr<BaseCell>> getNeighbours(const Board &board, const Point position) override {
        std::vector<std::shared_ptr<BaseCell>> neighbours;
        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) {
                    continue;
                }

                const int newX = position.x + dx;
                const int newY = position.y + dy;

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    neighbours.push_back(board[newX][newY]);
                }
            }
        }

        return neighbours;
    }
};