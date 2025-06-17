#include "./engine/neighbourhood/BaseNeighbourhood.h"

class VonNeumannNeighbourhood final : public BaseNeighbourhood {
public:
    std::vector<std::shared_ptr<BaseCell>> getNeighbours(const Board &board, const Point position) override {
        std::vector<std::shared_ptr<BaseCell>> neighbours;
        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());

        const std::vector<std::pair<int, int>> directions = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };

        for (const auto& [dx, dy] : directions) {
            const int newX = position.x + dx;
            const int newY = position.y + dy;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                neighbours.push_back(board[newX][newY]);
            }
        }

        return neighbours;

    }
};
