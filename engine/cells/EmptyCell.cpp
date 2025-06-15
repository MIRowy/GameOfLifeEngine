#include "BaseCell.h"

class EmptyCell final : public BaseCell {
public:
    explicit EmptyCell(const Point position) : BaseCell(position) {
        _lifeState = CellLifeState::Dead;
    }

    void kill() override {
        // Empty cell is always dead, so no action needed.
    }
    
    void keepAlive(std::shared_ptr<BaseNeighbourhood> neighbourhood) override {
        // Empty cell can't be kept alive as it's always dead.
    }
    
    void resurrect() override {
        // Empty cell can't be resurrected as it must always remain dead.
    }
    
    [[nodiscard]] 
    CellLifeState getNextLifeState(std::vector<std::shared_ptr<BaseCell>> neighbourhood) override {
        // Empty cell will always return Dead state regardless of its neighborhood.
        return CellLifeState::Dead;
    }

    std::string getType() override {
        return "empty";
    }
};