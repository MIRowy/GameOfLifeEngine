#include <algorithm>

#include "BaseNeighbourhood.h"
#include "../engine/cells/BaseCell.h"

class DefaultGameOfLifeCell final : public BaseCell {
public:
    explicit DefaultGameOfLifeCell(const Point &position) : BaseCell(position) {}
    
    void kill() override {
        _lifeState = CellLifeState::Dead;
    }

    void keepAlive(std::shared_ptr<BaseNeighbourhood> neighbourhood) override {
        _lifeState = CellLifeState::Alive;
    }

    void resurrect() override {
        _lifeState = CellLifeState::Alive;
    }

    CellLifeState getNextLifeState(const std::vector<std::shared_ptr<BaseCell>> neighbourhood) override {
        const auto liveNeighbours = std::ranges::count_if(
            neighbourhood,
            [](const std::shared_ptr<BaseCell>& cell) { return cell->getLifeState() == CellLifeState::Alive; });

        printf("liveNeighbours: %lld\n", liveNeighbours);

        if (getLifeState() == CellLifeState::Alive) {
            if (liveNeighbours < 2 || liveNeighbours > 3) {
                return CellLifeState::Dead;
            }

            return CellLifeState::Alive;
        }

        if (liveNeighbours == 3) {
            return CellLifeState::Alive;
        }

        return CellLifeState::Dead;
    }

    std::string getType() override {
        return "default";
    }
};