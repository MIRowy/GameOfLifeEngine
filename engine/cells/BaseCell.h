#ifndef BASECELL_H
#define BASECELL_H

#include <memory>

#include "../typedefs.h"

enum class CellLifeState { Alive, Dead };

class BaseCell {
protected:
    const Point position;
    CellLifeState _lifeState { CellLifeState::Alive };

public:
    explicit BaseCell(const Point position): position(position) {}
    virtual ~BaseCell() = default;

    [[nodiscard]]
    Point getPosition() const { return position; }

    [[nodiscard]]
    CellLifeState getLifeState() const { return _lifeState; }

    virtual void kill() = 0;

    virtual void keepAlive(std::shared_ptr<BaseNeighbourhood> neighbourhood) = 0;

    virtual void resurrect() = 0;

    virtual CellLifeState getNextLifeState(std::vector<std::shared_ptr<BaseCell>> neighbourhood) = 0;

    virtual std::string getType() = 0;
};

#endif
